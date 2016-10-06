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
	for (std::list<t_MachineInstruction>::iterator it = VMSettings->MachineInstructionsSet.begin();
		it != VMSettings->MachineInstructionsSet.end(); it++)
	{

		/*std::cout << "- Machine Instruction: " << (*it).Instruction;
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
		}*/
	}
}

// getters / setters

void				VirtualProcessor::LinkVMSettings(t_avm *VMSettings)
{
	this->VMSettings = VMSettings;
	if (!this->VMSettings)
	{
		throw NullvarDetected();
	}
}