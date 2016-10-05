/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:29:17 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 15:29:21 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include "../libft/libft.h"
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <list>
# include <exception>
# include <regex>

// VM operands
enum									eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

// Lexer Parser
enum									eTokenType
{
	Instruction,
	Value,
	Error
};

typedef struct							s_token
{
	int									LineNumber;
	int									NumberInLine;
	eTokenType							TokenType;
	std::string							Value;
}										t_token;

// Instruction Processing
typedef struct							s_MachineInstruction
{
	std::string							Instruction;
	bool								HasValue;
	std::string							Value;
}										t_MachineInstruction;

// Main Struct definition;
typedef struct							s_avm
{
	// List of Instructions
	std::list<std::string>				InstructionsTable;
	std::list<std::string>				ValuesTable;
	std::list<t_MachineInstruction>		MachineInstructionsSet;
}										t_avm;

// Class Declarations.
class IOperand;
class IOperandController;
class InputController;
class ExceptionHandler;


class VMController;

#include "IOperand.hpp"
#include "IOperandController.hpp"
#include "InputController.hpp"
#include "ExceptionHandler.hpp"


#include "VMController.hpp"


#endif
