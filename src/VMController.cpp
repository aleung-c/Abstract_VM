/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VMController.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:04:13 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 17:04:15 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

VMController::VMController( void )
{
	std::cout << KGRN "Machine main controller Ready" KRESET << std::endl;
}

VMController::VMController( VMController const &src )
{

}

VMController::~VMController( void )
{
	// free stack and stuffs
}

VMController		&VMController::operator=( VMController const &rhs )
{
	(void)rhs;
	return (*this);
}

// List of authorized words.
void				VMController::InitDictionnaries()
{
	try
	{
		if (VMSettings)
		{
			// init set of valable instructions
			VMSettings->InstructionsTable.push_back("push");
			VMSettings->InstructionsTable.push_back("pop");
			VMSettings->InstructionsTable.push_back("dump");
			VMSettings->InstructionsTable.push_back("assert");
			VMSettings->InstructionsTable.push_back("add");
			VMSettings->InstructionsTable.push_back("sub");
			VMSettings->InstructionsTable.push_back("mul");
			VMSettings->InstructionsTable.push_back("div");
			VMSettings->InstructionsTable.push_back("mod");
			// bonus
			VMSettings->InstructionsTable.push_back("sin");
			VMSettings->InstructionsTable.push_back("cos");
			VMSettings->InstructionsTable.push_back("tan");
			// bonus - end;
			VMSettings->InstructionsTable.push_back("print");
			VMSettings->InstructionsTable.push_back("exit");

			// init set of valable values.
			VMSettings->ValuesTable.push_back("int8");
			VMSettings->ValuesTable.push_back("int16");
			VMSettings->ValuesTable.push_back("int32");
			VMSettings->ValuesTable.push_back("float");
			VMSettings->ValuesTable.push_back("double");
		}
		else
		{
			throw MachineInitialisationError("Dictionnaries initialization error");
		}
	}
	catch (MachineInitialisationError &e)
	{
		std::cout << e.what() << std::endl;
		exit(-1);
	}
}

// Main Control methods
int					VMController::Run(int argc, char **argv)
{
	if (argc != -1 && argv)
	{
		std::cout << KBLU "*Virtual Machine starts running*" KRESET << std::endl;
		try
		{
			// ******************************************** //
			//	Input Handling								//
			//												//
			// ******************************************** //
			// throw calls will be made in these classes.
			InputController.LinkVMSettings(VMSettings);
			InputController.GetInput(argc, argv);
			InputController.LexInput();
			InputController.ParseInput();
			InputController.TranslateInputIntoMachineInstruction();

			// ******************************************** //
			//	Input Processing							//
			//												//
			// ******************************************** //
			VirtualProcessor.LinkVMSettings(VMSettings);
			VirtualProcessor.InstructionsReception();

			return (0);
		}
		// Personalized exceptions catching;
		catch (FileOpeningError &e)
		{
			return (PrintException(e));
		}
		catch (FileReadingError &e)
		{
			return (PrintException(e));
		}
		catch (NullvarDetected &e)
		{
			return (PrintException(e));
		}
		catch (LexicalError &e)
		{
			return (PrintException(e));
		}
		catch (ParsingError &e)
		{
			return (PrintException(e));
		}
		catch (ValueOverflow &e)
		{
			return (PrintException(e));
		}
		catch (ValueUnderflow &e)
		{
			return (PrintException(e));
		}
		catch (EmptyStack &e)
		{
			return (PrintException(e));
		}
		catch (ZeroDiv &e)
		{
			return (PrintException(e));
		}
		catch (NoExit &e)
		{
			return (PrintException(e));
		}
		catch (FalseAssertion &e)
		{
			return (PrintException(e));
		}
		catch (StackLessThanTwo &e)
		{
			return (PrintException(e));
		}
		catch (NotAnInteger8 &e)
		{
			return (PrintException(e));
		}
		catch (NotADouble &e)
		{
			return (PrintException(e));
		}
	}
	return (0);
}

int			VMController::PrintException(std::runtime_error &e)
{
	std::cout << KRED << "Error: " << KRESET << e.what() << std::endl;
	return (-1);
}

// Getters/Setters
void				VMController::SetVMSettings(t_avm &Settings)
{
	try
	{
		this->VMSettings = &Settings;
		if (this->VMSettings)
		{
			std::cout << KGRN "VM setting structure linked" KRESET << std::endl;
		}
		else
		{
			throw NullvarDetected("NULL variable detected");
		}

	}
	catch (NullvarDetected &e)
	{
		PrintException(e);
	}
}