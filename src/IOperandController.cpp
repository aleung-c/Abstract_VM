/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperandController.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:58:30 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:58:32 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

// singleton pattern
IOperandController IOperandController::m_instance=IOperandController();

IOperandController::IOperandController( void )
{
	OperandFt[0] = &IOperandController::createInt8;
	OperandFt[1] = &IOperandController::createInt16;
	OperandFt[2] = &IOperandController::createInt32;
	OperandFt[3] = &IOperandController::createFloat;
	OperandFt[4] = &IOperandController::createDouble;
	std::cout << KGRN "IOperandController factory initialized" KRESET << std::endl;
}

IOperandController::IOperandController( IOperandController const &src )
{

}

IOperandController::~IOperandController( void )
{
	// free stack and stuffs
}

IOperandController		&IOperandController::operator=( IOperandController const &rhs )
{
	(void)rhs;
	return (*this);
}

// singleton pattern
IOperandController& IOperandController::Instance()
{
    return m_instance;
}


IOperand const * IOperandController::createOperand( eOperandType type, std::string const & value ) const
{
	IOperand const *RetOperand = (*this.*OperandFt[type])(value);
	return (RetOperand);
}

IOperand const * IOperandController::createInt8( std::string const & value ) const
{
	class Int8			*retOperand = new class Int8();
	double				retVal;

	retOperand->StringValue = value;
	retVal = std::strtod(value.c_str(), 0);
	std::cout << "creating int8: " << retVal << std::endl;
	if (retVal > 127)
	{
		throw ValueOverflow("Value overflow");
	}
	else if (retVal < -128)
	{
		throw ValueUnderflow("Value underflow");
	}
	return (retOperand);
}

IOperand const * IOperandController::createInt16( std::string const & value ) const
{
	std::cout << "creating int16" << std::endl;
	return (NULL);
}

IOperand const * IOperandController::createInt32( std::string const & value ) const
{
	std::cout << "creating int32" << std::endl;
	return (NULL);
}

IOperand const * IOperandController::createFloat( std::string const & value ) const
{
	std::cout << "creating Float" << std::endl;
	return (NULL);
}

IOperand const * IOperandController::createDouble( std::string const & value ) const
{
	std::cout << "creating Double" << std::endl;
	return (NULL);
}