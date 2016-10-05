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
	std::cout << "Initializing Virtual Machine ..." << std::endl;
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

// Main Control methods

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
			throw MachineInitialisationError();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		exit(-1);
	}
}

int					VMController::Run(int argc, char **argv)
{
	if (argc != -1 && argv)
	{
		std::cout << "*Virtual Machine starts running*" << std::endl;
		try
		{
			// ******************************************** //
			//	Input Handling								//
			//												//
			// ******************************************** //

			// throw calls will be made in these methods.
			InputController.LinkVMSettings(VMSettings);
			InputController.GetInput(argc, argv);
			InputController.LexInput();
			InputController.ParseInput();
			InputController.TranslateInputToMachineInstruction();

			// ******************************************** //
			//	Input Processing							//
			//												//
			// ******************************************** //

			// soon.

			// ******************************************** //
			//	Output										//
			//												//
			// ******************************************** //

			// soon.

			return (0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			// TODO: free stuff.
			return (-1);
		}
	}
	return (0);
}

// Getters/Setters
void				VMController::SetVMSettings(t_avm &Settings)
{
	try
	{
		this->VMSettings = &Settings;
		if (this->VMSettings)
		{
			std::cout << "VM setting structure linked" << std::endl;
		}
		else
		{
			throw NullvarDetected();
		}

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}