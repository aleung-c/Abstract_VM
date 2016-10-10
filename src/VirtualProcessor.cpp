/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualProcessor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:53:05 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 16:53:09 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

VirtualProcessor::VirtualProcessor( void )
{
	// init set of valable instructions
	InstructionsMap["push"] = 0;
	InstructionsMap["pop"] = 1;
	InstructionsMap["dump"] = 2;
	InstructionsMap["assert"] = 3;
	InstructionsMap["add"] = 4;
	InstructionsMap["sub"] = 5;
	InstructionsMap["mul"] = 6;
	InstructionsMap["div"] = 7;
	InstructionsMap["mod"] = 8;
	InstructionsMap["print"] = 9;
	InstructionsMap["exit"] = 10;

	// set pointers function array
	Process[0] = &VirtualProcessor::ProcessPush;
	Process[1] = &VirtualProcessor::ProcessPop;
	Process[2] = &VirtualProcessor::ProcessDump;
	Process[3] = &VirtualProcessor::ProcessAssert;
	Process[4] = &VirtualProcessor::ProcessAdd;
	Process[5] = &VirtualProcessor::ProcessSub;
	Process[6] = &VirtualProcessor::ProcessMul;
	Process[7] = &VirtualProcessor::ProcessDiv;
	Process[8] = &VirtualProcessor::ProcessMod;
	Process[9] = &VirtualProcessor::ProcessPrint;
	Process[10] = &VirtualProcessor::ProcessExit;


	std::cout << KGRN "Virtual processor Ready" KRESET << std::endl;
}

VirtualProcessor::VirtualProcessor( VirtualProcessor const &src )
{

}

VirtualProcessor::~VirtualProcessor( void )
{
	// free stack and stuffs
}

VirtualProcessor		&VirtualProcessor::operator=( VirtualProcessor const &rhs )
{
	(void)rhs;
	return (*this);
}

void					VirtualProcessor::InstructionsReception()
{
	std::cout << std::endl << KGRN "AbstractVM Output:" KRESET << std::endl;
	ExitInstructionReceived = false;
	// For each machine instruction;
	for (std::list<t_MachineInstruction>::iterator CurInstr = VMSettings->MachineInstructionsSet.begin();
		CurInstr != VMSettings->MachineInstructionsSet.end();
		CurInstr++)
	{
		std::map<std::string, int>::iterator it = InstructionsMap.find((*CurInstr).Instruction);
		if (it != InstructionsMap.end())
		{
			//std::cout << "found " << it->first << "\n";
			(*this.*Process[it->second])(*CurInstr);
		}
		if (ExitInstructionReceived)
		{
			//sleep(30);
			return ;
		}
	}
	if (ExitInstructionReceived == false)
	{
		throw NoExit("Error: No \"exit\" instruction received in program");
	}
}

void				VirtualProcessor::ProcessPush(t_MachineInstruction &CurInstr)
{
	//std::cout << "Processing push on the machine" << std::endl;
	VMSettings->MachineStack.push_front(
		IOperandController::Instance().createOperand(CurInstr.ValueOperandType, CurInstr.StrValue));
}

void				VirtualProcessor::ProcessPop(t_MachineInstruction &CurInstr)
{
	const IOperand			*val1;
	
	//std::cout << "Processing pop on the machine" << std::endl;
	if (VMSettings->MachineStack.size() >= 1)
	{
		val1 = VMSettings->MachineStack.front();
		delete val1;
		VMSettings->MachineStack.pop_front();
	}
	else
	{
		throw EmptyStack("Error: Pop operation on empty stack");
	}
}

void				VirtualProcessor::ProcessDump(t_MachineInstruction &CurInstr) // leger pb de fuite here.
{
	//std::cout << "Processing dump on the machine" << std::endl;
	std::list<IOperand const*> listclone = VMSettings->MachineStack;
	
	for (std::list<IOperand const*>::const_iterator it = listclone.begin();
			it != listclone.end(); it++)
	{
		std::cout << (*it)->toString() << std::endl;
	}
}

void				VirtualProcessor::ProcessAssert(t_MachineInstruction &CurInstr)
{
	const IOperand			*val1;
	const IOperand			*retVal;
	double					lhsVal;
	double					rhsVal;

	//std::cout << "Processing assert on the machine" << std::endl;
	if (VMSettings->MachineStack.size() >= 1) // must have at least one val on the stack
	{
		val1 = VMSettings->MachineStack.front();
		//VMSettings->MachineStack.pop_front();

		lhsVal = std::strtod(CurInstr.StrValue.c_str(), 0);
		rhsVal = std::strtod((*val1).StringValue.c_str(), 0);
		//delete val1;
		if (CurInstr.ValueOperandType != (*val1).getType()
			|| lhsVal != rhsVal)
		{
			throw FalseAssertion("Error: Assertion is not true");
		}
		else
		{
			//std::cout << "Assertion true" << std::endl;
		}
	}
	else
	{
		throw EmptyStack("Error: Assert operation on empty stack");
	}
}

void				VirtualProcessor::ProcessAdd(t_MachineInstruction &CurInstr)
{
	const IOperand		*val1;
	const IOperand		*val2;
	const IOperand		*retVal;

	//std::cout << "Processing add on the machine" << std::endl;
	if (VMSettings->MachineStack.size() >= 2) // must have at least two val on the stack
	{
		val1 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();
		val2 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();

		retVal = *val2 + *val1;
		delete val1;
		delete val2;
		VMSettings->MachineStack.push_front(retVal);
	}
	else
	{
		throw StackLessThanTwo("Error: Stack must have at least two values to perform \"add\" operation");
	}
}

void				VirtualProcessor::ProcessSub(t_MachineInstruction &CurInstr)
{
	const IOperand		*val1;
	const IOperand		*val2;
	const IOperand		*retVal;

	//std::cout << "Processing sub on the machine" << std::endl;
	if (VMSettings->MachineStack.size() >= 2) // must have at least two val on the stack
	{
		val1 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();
		val2 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();

		retVal = *val2 - *val1;
		delete val1;
		delete val2;
		VMSettings->MachineStack.push_front(retVal);
	}
	else
	{
		throw StackLessThanTwo("Error: Stack must have at least two values to perform \"sub\" operation");
	}
}

void				VirtualProcessor::ProcessMul(t_MachineInstruction &CurInstr)
{
	const IOperand		*val1;
	const IOperand		*val2;
	const IOperand		*retVal;

	//std::cout << "Processing mul on the machine" << std::endl;
	if (VMSettings->MachineStack.size() >= 2) // must have at least two val on the stack
	{
		val1 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();
		val2 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();

		retVal = *val2 * *val1;
		delete val1;
		delete val2;
		VMSettings->MachineStack.push_front(retVal);
	}
	else
	{
		throw StackLessThanTwo("Error: Stack must have at least two values to perform \"mul\" operation");
	}
}

void				VirtualProcessor::ProcessDiv(t_MachineInstruction &CurInstr)
{
	const IOperand		*val1;
	const IOperand		*val2;
	const IOperand		*retVal;
	double				rhsVal;

	//std::cout << "Processing div on the machine" << std::endl;
	if (VMSettings->MachineStack.size() >= 2) // must have at least two val on the stack
	{
		val1 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();
		val2 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();

		rhsVal = std::strtod((*val1).StringValue.c_str(), 0);

		if (rhsVal == 0.0)
		{
			delete val1;
			delete val2;
			throw ZeroDiv("Error: Division by zero is impossible");
		}
		retVal = *val2 / *val1;
		delete val1;
		delete val2;
		VMSettings->MachineStack.push_front(retVal);
	}
	else
	{
		throw StackLessThanTwo("Error: Stack must have at least two values to perform \"div\" operation");
	}
}

void				VirtualProcessor::ProcessMod(t_MachineInstruction &CurInstr)
{
	const IOperand		*val1;
	const IOperand		*val2;
	const IOperand		*retVal;
	double				rhsVal;

	//std::cout << "Processing mod on the machine" << std::endl;
	if (VMSettings->MachineStack.size() >= 2) // must have at least two val on the stack
	{
		val1 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();
		val2 = VMSettings->MachineStack.front();
		VMSettings->MachineStack.pop_front();

		rhsVal = std::strtod((*val1).StringValue.c_str(), 0);
		if (rhsVal == 0.0)
		{
			delete val1;
			delete val2;
			throw ZeroDiv("Error: Division by zero is impossible");
		}
		retVal = *val2 % *val1;
		delete val1;
		delete val2;
		VMSettings->MachineStack.push_front(retVal);
	}
	else
	{
		throw StackLessThanTwo("Error: Stack must have at least two values to perform \"mod\" operation");
	}
}

void				VirtualProcessor::ProcessPrint(t_MachineInstruction &CurInstr)
{
	//std::cout << "Processing print on the machine" << std::endl;
	if (VMSettings->MachineStack.size() >= 1)
	{

		if (CurInstr.ValueOperandType == Int8)
		{
			printf("%c\n", std::stoi(CurInstr.StrValue, NULL));
		}
		else
		{
			throw NotAnInteger8("Error: Value to print is not an int8");
		}
	}
	else
	{
		throw EmptyStack("Error: Print operation on empty stack");
	}
}

void				VirtualProcessor::ProcessExit(t_MachineInstruction &CurInstr)
{
	//std::cout << "Processing exit on the machine" << std::endl;
	ExitInstructionReceived = true;
}


// getters / setters

void				VirtualProcessor::LinkVMSettings(t_avm *VMSettings)
{
	this->VMSettings = VMSettings;
	if (!this->VMSettings)
	{
		throw NullvarDetected("Error: Null variable detected");
	}
}
