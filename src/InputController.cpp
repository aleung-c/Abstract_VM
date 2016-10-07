/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputController.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 18:33:33 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 18:33:35 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

InputController::InputController( void )
{
	std::cout << KGRN "InputController Ready" KRESET << std::endl;
}

InputController::InputController( InputController const &src )
{

}

InputController::~InputController( void )
{

}

InputController		&InputController::operator=( InputController const &rhs )
{
	(void)rhs;
	return (*this);
}

// the selection between file reading and standard input reading.
void				InputController::GetInput(int argc, char **argv)
{
	if (argc == 1)
	{
		// only the program. go to standard input recording;
		//std::cout << "Reading from standard input" << std::endl;
		ProgramString = ReadFromStdIn();
		//std::cout << "\nprogram after getting input:" << std::endl << ProgramString << std::endl;
		ProgramString = CleanInputFromStdIn();
		//std::cout << "\nprogram after cleaning input:" << std::endl << ProgramString << std::endl;
	}
	else if (argc == 2)
	{
		// the program and possibly a file. lets try it;
		ProgramString = ReadFromFile(argv[1]);
	}
}

std::string			InputController::ReadFromFile(std::string path)
{
	std::string		line;
	std::string		ret;
	size_t			commentPosition;
	bool			IsEndPresent;
	
	ret = "";
	CurrentFile.open(path);
	if (CurrentFile.is_open())
	{
		std::cout << "Program file opened" << std::endl;
		while (getline(CurrentFile,line))
		{
			// Comment cleaning at reading.
			if ((commentPosition = line.find(";")) != std::string::npos)
			{
				line.erase(commentPosition, line.size());
			}
			ret += line;
			ret += "\n";
		}
		CurrentFile.close();
		return (ret);
	}
	else
	{
		throw FileOpeningError("File opening error");
	}
}

std::string			InputController::ReadFromStdIn()
{
	std::string line;
	std::string	ret;

	line = "";
	ret = line;
	std::cout << "Reading program from user input :" << std::endl
	<< "$>" << std::endl;
	while (getline(std::cin, line) && line.find(";;") == std::string::npos)
	{
		ret += line;
		ret += "\n";
	}
	ret += line;
	ret += "\n";
	return (ret);
}

std::string			InputController::CleanInputFromStdIn()
{
	std::string				line;
	std::string				ret;
	size_t					commentPosition;
	std::stringstream		ProgStream(ProgramString);

	line = "";
	ret = line;
	while (getline(ProgStream, line))
	{
		if ((commentPosition = line.find(";")) != std::string::npos)
		{
			line.erase(commentPosition, line.size());
		}
		ret += line;
		ret += "\n";
	}
	return (ret);
}

// Lex the input -> cut it into token and look if they correspond to the type of entries we expect (ie instructions and values)
void				InputController::LexInput()
{
	std::string				line;
	std::stringstream		ProgStream(ProgramString);
	char 					*splittedString;
	int						lineNumber;
	int						numberInLine;
	t_token					CurToken;

	// the input has been taken from either stdin or a file.
	// now, lex then parse it;
	lineNumber = 0;
	numberInLine = 0;
	while (getline(ProgStream, line))
	{
		for (splittedString = std::strtok((char *)line.c_str(), " \t");
			splittedString != NULL; splittedString = strtok (NULL, " \t"))
		{
			CurToken.Value = splittedString;
			CurToken.LineNumber = lineNumber;
			CurToken.NumberInLine = numberInLine;
			if (std::regex_match (splittedString, std::regex("^[A-Za-z0-9]+\\([-+]?[0-9]*\\.?[0-9]*\\)$")))
			{
				CurToken.TokenType = Value;
			}
			else if (std::regex_match (splittedString, std::regex("^[A-Za-z]+")))
			{
				CurToken.TokenType = Instruction;
			}
			else
			{
				CurToken.TokenType = Error;
			}
			TokenList.push_back(CurToken);
			numberInLine += 1;
		}
		lineNumber += 1;
		numberInLine = 0;
	}

	// Display token and their stats.
	/*for(std::list<t_token>::iterator it = TokenList.begin(); it != TokenList.end() ; it++)
	{
		printf("token : line %d - pos %d -", (*it).LineNumber,(*it).NumberInLine);
		if ((*it).TokenType == Instruction)
			printf(" type = instruction");
		else if ((*it).TokenType == Value)
			printf(" type = value");
		else if ((*it).TokenType == Error)
			printf(" type = Error");
		printf(" - value = %s\n", (*it).Value.c_str());
	}*/
	// check and display lexical errors.
	if (LexerCheck() != 0)
		throw LexicalError("Lexical error");
}

// first pass of check : everything has been tokenized. if some of these token are errors. we stop here.
int					InputController::LexerCheck()
{
	int nbOfErrors = 0;

	for(std::list<t_token>::iterator it = TokenList.begin(); it != TokenList.end() ; it++)
	{
		if ((*it).TokenType == Error)
		{
			nbOfErrors += 1;
			std::cout << "Line " << (*it).LineNumber << " col "
			<< (*it).NumberInLine << ": Invalid syntax: \""
			<< (*it).Value << "\"" << std::endl;
		}
	}
	if (nbOfErrors != 0)
	{
		return (-1);
	}
	return (0); // All green;
}

// Input was lexed in tokens, now we parse those token to see if they are in accord with our program rules.
void				InputController::ParseInput()
{
	int								nbOfErrors = 0;	

	for(std::list<t_token>::iterator it = TokenList.begin(); it != TokenList.end() ; it++)
	{
		// STEP 1 : Order of tokens check : are they well placed?
		ParseTokenOrder(it, &nbOfErrors);
		// STEP 2 : Dictionnary comparison : do these input exist for the machine?
		ParseDictionnaryComparison(it, &nbOfErrors);
		// STEP 3 : Specific rules checking : there are some special cases to handle
		ParseSpecificRules(it, &nbOfErrors);
		// STEP 4 : Values entered checking : The values should be checked before processing.
		ParseValuesRules(it, &nbOfErrors);
	}
	if (nbOfErrors != 0)
	{
		throw ParsingError("Parser error");
	}
	std::cout << KGRN "Program parsed -> OK for process" KRESET << std::endl;
	return ; // All green -> Go to translate into machine instruction;
}



void				InputController::ParseTokenOrder(std::list<t_token>::iterator it, int *nbOfErrors)
{
	std::list<t_token>::iterator	next;


	next = it;
	next++;
	// STEP 1 : Order of tokens check  -------------------------------

	// Rule 1 : values cant be alone and first on a line;
	if ((*it).TokenType == Value && (*it).NumberInLine == 0)
	{
		*nbOfErrors += 1;
		std::cout << "Line " << (*it).LineNumber << " col "
		<< (*it).NumberInLine << ": Value cannot be first on a line: \""
		<< (*it).Value << "\"" << std::endl;
	}

	if ((*it).TokenType == Instruction)
	{
		// Rule 2 : two instructions cannot be on the same line
		if (next != TokenList.end())
		{
			if ((*next).LineNumber == (*it).LineNumber
			&& (*next).TokenType == Instruction)
			{
				*nbOfErrors += 1;
				std::cout << "Line " << (*it).LineNumber << " col "
				<< (*it).NumberInLine << ": Two or more instructions cannot be on the same line: \""
				<< (*it).Value << " " << (*next).Value  << "\"" << std::endl;
			}
		}
	}
	else if ((*it).TokenType == Value)
	{
		// Rule 3 : two values cannot be on the same line
		if (next != TokenList.end())
		{
			if ((*next).LineNumber == (*it).LineNumber
			&& (*next).TokenType == Value)
			{
				*nbOfErrors += 1;
				std::cout << "Line " << (*it).LineNumber << " col "
				<< (*it).NumberInLine << ": Two or more values cannot be on the same line: \""
				<< (*it).Value << " " << (*next).Value  << "\"" << std::endl;
			}
		}
	}
}

void				InputController::ParseDictionnaryComparison(std::list<t_token>::iterator it, int *nbOfErrors)
{
	char							*valueType;
	std::string						tmpValue;

	// STEP 2 : Dictionnary comparison  -------------------------------
	if ((*it).TokenType == Instruction)
	{
		// does instruction exist in Instruction Table ?
		if (find(VMSettings->InstructionsTable.begin(), VMSettings->InstructionsTable.end(),
			(*it).Value) == VMSettings->InstructionsTable.end())
		{
			// did NOT found Instruction in dictionnary
			*nbOfErrors += 1;
			std::cout << "Line " << (*it).LineNumber << " col "
			<< (*it).NumberInLine << ": Unknown instruction: \""
			<< (*it).Value << "\"" << std::endl;
		}
	}
	else if ((*it).TokenType == Value)
	{
		// we take the string before the parenthesis;
		tmpValue = (*it).Value;
		valueType = std::strtok((char *)tmpValue.c_str(), "(");
		// does this type of value exist in Value Table ?
		if (find(VMSettings->ValuesTable.begin(), VMSettings->ValuesTable.end(), valueType) == VMSettings->ValuesTable.end())
		{
			// did NOT found Value in dictionnary
			*nbOfErrors += 1;
			std::cout << "Line " << (*it).LineNumber << " col "
			<< (*it).NumberInLine << ": Unknown value type: \""
			<< valueType << "\"" << std::endl;
		}
	}
}

void				InputController::ParseSpecificRules(std::list<t_token>::iterator it, int *nbOfErrors)
{
	std::list<t_token>::iterator	next;

	next = it;
	next++;
	// STEP 3 : Specific rules checking  -------------------------------
	// Specific rule 1: only push and assert can have a value following;
	if ((*it).TokenType == Instruction)
	{
		if (((*it).Value != "push" && (*it).Value != "assert")
			&& next != TokenList.end()
			&& (*next).LineNumber == (*it).LineNumber
			&& (*next).TokenType == Value)
		{
			*nbOfErrors += 1;
			std::cout << "Line " << (*it).LineNumber << " col "
			<< (*it).NumberInLine << ": only assert and push require a value following them: \""
			<< (*it).Value << " " << (*next).Value  << "\"" << std::endl;
		}
		if (((*it).Value == "push" || (*it).Value == "assert")
			&& ((next == TokenList.end())
				|| (next != TokenList.end()
				&& (*next).LineNumber != (*it).LineNumber)))
		{
			*nbOfErrors += 1;
			std::cout << "Line " << (*it).LineNumber << " col "
			<< (*it).NumberInLine << ": assert and push require a value after them: \""
			<< (*it).Value << " " << "\"" << std::endl;
		}
	}
}

void				InputController::ParseValuesRules(std::list<t_token>::iterator it, int *nbOfErrors)
{
	char							*valueType;
	std::string						valueString;
	std::smatch						match;
	std::regex 						regex("\\(([-+]?[0-9]*\\.?[0-9]*)\\)$");
	std::string						tmpValue;


	if ((*it).TokenType == Value)
	{
		tmpValue = (*it).Value;
		valueType = std::strtok((char *)tmpValue.c_str(), "(");
		std::regex_search((*it).Value, match, regex);
		if (match.size() >= 2)
			valueString = match[1]; // capture group with only the value;
		//std::cout << "Type = " << valueType << std::endl;
		//std::cout << "captured value = " << valueString << std::endl;

		// Int8 checks
		if ((std::string)valueType == "int8")
		{
			if (valueString.find(".") != std::string::npos)
			{
				*nbOfErrors += 1;
				std::cout << "Line " << (*it).LineNumber << " col "
				<< (*it).NumberInLine << ": int8 declared as floating value: \""
				<< (*it).Value << " " << "\"" << std::endl;
			}
			if ((valueString[0] == '-' && valueString.size() > 4) || (valueString[0] != '-' && valueString.size() > 3))
			{
				*nbOfErrors += 1;
				std::cout << "Line " << (*it).LineNumber << " col "
				<< (*it).NumberInLine << ": int8 declared with incorrect value: \""
				<< (*it).Value << " " << "\"" << std::endl;
			}
		}
		// Int16 checks
		if ((std::string)valueType == "int16")
		{
			if (valueString.find(".") != std::string::npos)
			{
				*nbOfErrors += 1;
				std::cout << "Line " << (*it).LineNumber << " col "
				<< (*it).NumberInLine << ": int16 declared as floating value: \""
				<< (*it).Value << " " << "\"" << std::endl;
			}
			if ((valueString[0] == '-' && valueString.size() > 6) || (valueString[0] != '-' && valueString.size() > 5))
			{
				*nbOfErrors += 1;
				std::cout << "Line " << (*it).LineNumber << " col "
				<< (*it).NumberInLine << ": int16 declared with incorrect value: \""
				<< (*it).Value << " " << "\"" << std::endl;
			}
		}
		// Int32 checks
		if ((std::string)valueType == "int32")
		{
			if (valueString.find(".") != std::string::npos)
			{
				*nbOfErrors += 1;
				std::cout << "Line " << (*it).LineNumber << " col "
				<< (*it).NumberInLine << ": int32 declared as floating value: \""
				<< (*it).Value << " " << "\"" << std::endl;
			}
			if ((valueString[0] == '-' && valueString.size() > 11) || (valueString[0] != '-' && valueString.size() > 10))
			{
				*nbOfErrors += 1;
				std::cout << "Line " << (*it).LineNumber << " col "
				<< (*it).NumberInLine << ": int32 declared with incorrect value: \""
				<< (*it).Value << " " << "\"" << std::endl;
			}
		}
		// for now, float and double will be checked during process;
	}
}

void				InputController::TranslateInputIntoMachineInstruction()
{
	t_MachineInstruction				CurMachineInstruction;
	std::list<t_token>::iterator		next;

	for (std::list<t_token>::iterator it = TokenList.begin(); it != TokenList.end() ; it++)
	{
		next = it;
		next++;
		if ((*it).TokenType == Instruction)
		{
			CurMachineInstruction.Instruction = (*it).Value;
			if (next != TokenList.end() && (*next).LineNumber == (*it).LineNumber)
			{
				CurMachineInstruction.HasValue = true;
				CurMachineInstruction.ValueOperandType = GetOperandTypeOfValue(*next);
				CurMachineInstruction.StrValue = GetStringValueOfValue(*next);
			}
			else 
			{
				CurMachineInstruction.HasValue = false;
			}
			VMSettings->MachineInstructionsSet.push_back(CurMachineInstruction);
		}
	}

	// Display each machine instruction for debug.
	std::cout << std::endl << KYEL " // List of machine instructions ----------- //" KRESET << std::endl;
	for (std::list<t_MachineInstruction>::iterator it = VMSettings->MachineInstructionsSet.begin();
		it != VMSettings->MachineInstructionsSet.end(); it++)
	{
		std::cout << "- Machine Instruction: " << (*it).Instruction;
		if ((*it).HasValue == true)
		{
			if ((*it).ValueOperandType == Int8)
			{
				std::cout << " | int8 ";
			}
			else if ((*it).ValueOperandType == Int16)
			{
				std::cout << " | int16 ";
			}
			else if ((*it).ValueOperandType == Int32)
			{
				std::cout << " | int32 ";
			}
			else if ((*it).ValueOperandType == Float)
			{
				std::cout << " | Float ";
			}
			else if ((*it).ValueOperandType == Double)
			{
				std::cout << " | Double ";
			}

			std::cout << "| value = " << (*it).StrValue << std::endl;
		}
		else
		{
			std::cout << std::endl;
		}
	}
	std::cout << KYEL " // END - List of machine instructions ---- //" KRESET << std::endl;

}

eOperandType	InputController::GetOperandTypeOfValue(t_token	&ValueToken)
{
	std::string						valueType;
	std::string						tmpValue;

	if (ValueToken.TokenType == Value)
	{
		tmpValue = ValueToken.Value;
		valueType = std::strtok((char *)tmpValue.c_str(), "(");
		//std::cout << "Value type taken = " << valueType << std::endl;
		if (valueType == "int8")
			return (Int8);
		else if (valueType == "int16")
			return (Int16);
		else if (valueType == "int32")
			return (Int32);
		else if (valueType == "Float")
			return (Float);
		else
			return (Double);
	}
	else
	{
		throw ParsingError("Parser error");
	}
	return (Double);

}

std::string		InputController::GetStringValueOfValue(t_token	&ValueToken)
{
	std::regex 						regex("\\(([-+]?[0-9]*\\.?[0-9]*)\\)$");
	std::smatch						match;
	std::string						tmpValue;
	std::string						valueString;

	if (ValueToken.TokenType == Value)
	{
		tmpValue = ValueToken.Value;
		std::regex_search(tmpValue, match, regex);
		if (match.size() >= 2)
			valueString = match[1];
		//std::cout << "Value string taken = " << valueString << std::endl;
		return (valueString);
	}
	return (NULL);
}

// Setters / Getters

void				InputController::LinkVMSettings(t_avm *VMSettings)
{
	this->VMSettings = VMSettings;
	if (!this->VMSettings)
	{
		throw NullvarDetected("NULL variable detected");
	}
}
