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
	//std::cout << "creating int8: " << retVal << std::endl;
	if (retVal > 127)
	{
		throw ValueOverflow("Error: Int8 Value overflow");
	}
	else if (retVal < -128)
	{
		throw ValueUnderflow("Error: Int8 Value underflow");
	}
	return (retOperand);
}

IOperand const * IOperandController::createInt16( std::string const & value ) const
{
	class Int16			*retOperand = new class Int16();
	double				retVal;

	retOperand->StringValue = value;
	retVal = std::strtod(value.c_str(), 0);
	//std::cout << "creating int16" << std::endl;
	if (retVal > 32767)
	{
		throw ValueOverflow("Error: Int16 Value overflow");
	}
	else if (retVal < -32768)
	{
		throw ValueUnderflow("Error: Int16 Value underflow");
	}
	return (retOperand);
}

IOperand const * IOperandController::createInt32( std::string const & value ) const
{
	class Int32			*retOperand = new class Int32();
	double				retVal;

	retOperand->StringValue = value;
	retVal = std::strtod(value.c_str(), 0);
	//std::cout << "creating int16" << std::endl;
	if (retVal > 2147483647)
	{
		throw ValueOverflow("Error: Int32 Value overflow");
	}
	else if (retVal < -2147483648)
	{
		throw ValueUnderflow("Error: Int32 Value underflow");
	}
	return (retOperand);
}

IOperand const * IOperandController::createFloat( std::string const & value ) const
{
	class Float			*retOperand = new class Float();
	double				retVal;

	retOperand->StringValue = value;
	retVal = std::strtod(value.c_str(), 0);
	//std::cout << "creating int16" << std::endl;
	if (retVal > std::numeric_limits<float>::max())
	{
		throw ValueOverflow("Error: Float Value overflow");
	}
	else if (retVal < std::numeric_limits<float>::lowest())
	{
		throw ValueUnderflow("Error: Float Value underflow");
	}
	return (retOperand);
}

IOperand const * IOperandController::createDouble( std::string const & value ) const
{
	class Double			*retOperand = new class Double();
	double					retVal;

	retOperand->StringValue = value;
	retVal = std::strtod(value.c_str(), 0);
	//std::cout << "creating int16" << std::endl;
	if (retVal > std::numeric_limits<double>::max())
	{
		throw ValueOverflow("Error: Double Value overflow");
	}
	else if (retVal < std::numeric_limits<double>::lowest())
	{
		throw ValueUnderflow("Error: Double Value underflow");
	}
	return (retOperand);
}