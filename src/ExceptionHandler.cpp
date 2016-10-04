/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionHandler.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:18:18 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 17:18:20 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

const char *FileOpeningError::what() const throw()
{
	return ("File opening error");
}

const char *FileReadingError::what() const throw()
{
	return ("File Reading error: no end of input found");
}

const char *NullvarDetected::what() const throw()
{
	return ("Nullvar detected");
}

const char *LexicalError::what() const throw()
{
	return ("Lexical Error detected");
}

const char *UnknownInstruction::what() const throw()
{
	return ("Unknown Instruction in program");
}

const char *ValueOverflow::what() const throw()
{
	return ("Value Overflow detected");
}

const char *ValueUnderflow::what() const throw()
{
	return ("Value Underflow detected");
}

const char *EmptyStack::what() const throw()
{
	return ("Stack is Empty");
}

const char *ZeroDiv::what() const throw()
{
	return ("Division by zero is impossible");
}

const char *NoExit::what() const throw()
{
	return ("Program doesnt have a exit instruction");
}

const char *TrueAssertion::what() const throw()
{
	return ("Assert is always true");
}


const char *StackLessThanTwo::what() const throw()
{
	return ("Operation on a stack that has less than two values is impossible");
}