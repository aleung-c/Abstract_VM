/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualProcessor.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:52:52 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 16:52:55 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

class VirtualProcessor
{
	typedef void					(VirtualProcessor::*VPFunctions)
										(t_MachineInstruction &CurInst);
	VPFunctions						Process[11];
	std::map<std::string, int>		InstructionsMap;
	bool							ExitInstructionReceived;

	public:
						// Default Copplien methods
							VirtualProcessor( void );
							VirtualProcessor( VirtualProcessor const &src );
							~VirtualProcessor( void );
	VirtualProcessor		&operator=( VirtualProcessor const &rhs );


	void					InstructionsReception();

	// Instructions functions;
	void					ProcessPush(t_MachineInstruction &CurInstr);
	void					ProcessPop(t_MachineInstruction &CurInstr);
	void					ProcessDump(t_MachineInstruction &CurInstr);
	void					ProcessAssert(t_MachineInstruction &CurInstr);
	void					ProcessAdd(t_MachineInstruction &CurInstr);
	void					ProcessSub(t_MachineInstruction &CurInstr);
	void					ProcessMul(t_MachineInstruction &CurInstr);
	void					ProcessDiv(t_MachineInstruction &CurInstr);
	void					ProcessMod(t_MachineInstruction &CurInstr);
	void					ProcessPrint(t_MachineInstruction &CurInstr);
	void					ProcessExit(t_MachineInstruction &CurInstr);
	
	//getters / setters
	void					LinkVMSettings(t_avm *VMSettings);



	private:
		//IOperandController		IOperandController; // now singleton.
		t_avm					*VMSettings;
};
