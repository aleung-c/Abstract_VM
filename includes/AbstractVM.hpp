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

// color in text;
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KRESET "\x1B[0m"

// VM operands
enum									eOperandType
{
	Int8,	// -128 to 127					- 1 byte
	Int16,	// -32768 to 32767				- 2 bytes
	Int32,	// -2147483648 to 2147483647	- 4 bytes
	Float,	// 1.2E-38 to 3.4E+38			- 4 bytes, 6 decimal places
	Double	// 2.3E-308 to 1.7E+308			- 8 bytes, 15 decimal places
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
	eOperandType						ValueOperandType;
	std::string							StrValue;
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
