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
	// For each machine instruction;
	for (std::list<t_MachineInstruction>::iterator CurInstr = VMSettings->MachineInstructionsSet.begin();
		CurInstr != VMSettings->MachineInstructionsSet.end();
		CurInstr++)
	{
		std::map<std::string, int>::iterator it = InstructionsMap.find((*CurInstr).Instruction);
		if (it != InstructionsMap.end())
		{
			std::cout << "found " << it->first << "\n";
			(*this.*Process[it->second])(*CurInstr);
		}
	}
}

void				VirtualProcessor::ProcessPush(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing push on the machine" << std::endl;
	VMSettings->MachineStack.push_front(
		IOperandController::Instance().createOperand(CurInstr.ValueOperandType, CurInstr.StrValue));
}

void				VirtualProcessor::ProcessPop(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing pop on the machine" << std::endl;
}

void				VirtualProcessor::ProcessDump(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing dump on the machine" << std::endl;
	for (std::list<IOperand const*>::iterator it = VMSettings->MachineStack.begin();
		it != VMSettings->MachineStack.end();
		it++)
	{
		std::cout << (*it)->toString() << std::endl;
	}
}

void				VirtualProcessor::ProcessAssert(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing assert on the machine" << std::endl;
}

void				VirtualProcessor::ProcessAdd(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing add on the machine" << std::endl;
}

void				VirtualProcessor::ProcessSub(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing sub on the machine" << std::endl;
}

void				VirtualProcessor::ProcessMul(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing mul on the machine" << std::endl;
}

void				VirtualProcessor::ProcessDiv(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing div on the machine" << std::endl;
}

void				VirtualProcessor::ProcessMod(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing mod on the machine" << std::endl;
}

void				VirtualProcessor::ProcessPrint(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing print on the machine" << std::endl;
}

void				VirtualProcessor::ProcessExit(t_MachineInstruction &CurInstr)
{
	std::cout << "Processing exit on the machine" << std::endl;
}


// getters / setters

void				VirtualProcessor::LinkVMSettings(t_avm *VMSettings)
{
	this->VMSettings = VMSettings;
	if (!this->VMSettings)
	{
		throw NullvarDetected("Null variable detected");
	}
}