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

FileOpeningError::FileOpeningError(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

MachineInitialisationError::MachineInitialisationError(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

FileReadingError::FileReadingError(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

NullvarDetected::NullvarDetected(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

LexicalError::LexicalError(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

ParsingError::ParsingError(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

ValueOverflow::ValueOverflow(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

ValueUnderflow::ValueUnderflow(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

EmptyStack::EmptyStack(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

ZeroDiv::ZeroDiv(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

NoExit::NoExit(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

FalseAssertion::FalseAssertion(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

StackLessThanTwo::StackLessThanTwo(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

NotAnInteger8::NotAnInteger8(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}

NotADouble::NotADouble(const std::string& what_arg) : std::runtime_error(what_arg)
{
	
}
