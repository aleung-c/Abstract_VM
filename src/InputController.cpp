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
	std::cout << "InputController Ready" << std::endl;
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

void				InputController::GetInput(int argc, char **argv)
{
	if (argc == 1)
	{
		// only the program. go to standard input recording;
		std::cout << "Reading from standard input" << std::endl;
		ProgramString = ReadFromStdIn();
		std::cout << "\nprogram after getting input:" << std::endl << ProgramString << std::endl;
		ProgramString = CleanInputFromStdIn();
		std::cout << "\nprogram after cleaning input:" << std::endl << ProgramString << std::endl;
	}
	else if (argc == 2)
	{
		// the program and possibly a file. lets try it;
		ProgramString = ReadFromFile(argv[1]);
	}

}

void				InputController::LexInput()
{
	std::string				line;
	std::stringstream		ProgStream(ProgramString);
	char 					*splittedString;
	// the input has been taken from either stdin or a file.
	// now, lex then parse it;
	std::cout << std::endl;
	std::cout << " --------- Program Tokenizing ------- " << std::endl;
	while (getline(ProgStream, line))
	{
		
		splittedString = std::strtok((char *)line.c_str(), " \t");
		while (splittedString != NULL)
		{
			std::cout << splittedString << std::endl;
			splittedString = strtok (NULL, " \t");
		}
		// split the string;
	}
		

}

std::string			InputController::ReadFromFile(std::string path)
{
	std::string		line;
	char 			*charLine;
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
				charLine = (char *)line.c_str();
				charLine[commentPosition] = '\0';
				ret += std::string(charLine);
			}
			else
			{
				ret += line;
				ret += "\n";
			}
		}
		CurrentFile.close();
		return (ret);
	}
	else
	{
		throw FileOpeningError();
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
	while (line.find(";;") == std::string::npos)
	{
		getline(std::cin, line);
		ret += line;
		ret += "\n";
	}
	return (ret);
}

std::string			InputController::CleanInputFromStdIn() // TODO : pb here.
{
	std::string				line;
	std::string				ret;
	size_t					commentPosition;
	char					*charLine;
	std::stringstream		ProgStream(ProgramString);

	line = "";
	ret = line;
	while (getline(ProgStream, line))
	{
		if ((commentPosition = line.find(";")) != std::string::npos)
		{
			charLine = (char *)line.c_str();
			charLine[commentPosition] = '\0';
			ret += std::string(charLine);
			ret += "\n";
			
		}
		ret += line;
	}
	return (ret);
}

