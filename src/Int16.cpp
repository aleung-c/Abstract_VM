/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:48:13 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:48:14 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

Int16::Int16( void )
{

}

Int16::Int16( Int16 const &src )
{

}

Int16::~Int16( void )
{

}

class Int16		&Int16::operator=( Int16 const &rhs )
{
	this->StringValue = rhs.StringValue;
	return (*this);
}

// interface methods
int							Int16::getPrecision( void ) const
{
	return (2);
}

eOperandType				Int16::getType( void ) const
{
	return ::Int16;
}

IOperand const				*Int16::operator+( IOperand const & rhs ) const
{
	double					lhsVal;
	double					rhsVal;
	double					result;
	std::stringstream		ss;
	IOperand				*ret;

	lhsVal = std::strtod(this->StringValue.c_str(), 0);
	rhsVal = std::strtod(rhs.StringValue.c_str(), 0);
	result = lhsVal + rhsVal;
	ss << result;
	if (getType() < rhs.getType())
	{
		return (IOperandController::Instance().createOperand(rhs.getType(),  ss.str()));
	}
	else
	{
		return (IOperandController::Instance().createOperand(this->getType(),  ss.str()));
	}
	return (ret);
}

IOperand const				*Int16::operator-( IOperand const & rhs ) const
{
	double					lhsVal;
	double					rhsVal;
	double					result;
	std::stringstream		ss;
	IOperand				*ret;

	lhsVal = std::strtod(this->StringValue.c_str(), 0);
	rhsVal = std::strtod(rhs.StringValue.c_str(), 0);
	result = lhsVal - rhsVal;
	ss << result;
	if (getType() < rhs.getType())
	{
		return (IOperandController::Instance().createOperand(rhs.getType(),  ss.str()));
	}
	else
	{
		return (IOperandController::Instance().createOperand(this->getType(),  ss.str()));
	}
	return (ret);
}
	
IOperand const				*Int16::operator*( IOperand const & rhs ) const
{
	double					lhsVal;
	double					rhsVal;
	double					result;
	std::stringstream		ss;
	IOperand				*ret;

	lhsVal = std::strtod(this->StringValue.c_str(), 0);
	rhsVal = std::strtod(rhs.StringValue.c_str(), 0);
	result = lhsVal * rhsVal;
	ss << result;
	if (getType() < rhs.getType())
	{
		return (IOperandController::Instance().createOperand(rhs.getType(),  ss.str()));
	}
	else
	{
		return (IOperandController::Instance().createOperand(this->getType(),  ss.str()));
	}
	return (ret);
}

IOperand const				*Int16::operator/( IOperand const & rhs ) const
{
	double					lhsVal;
	double					rhsVal;
	double					result;
	std::stringstream		ss;
	IOperand				*ret;

	lhsVal = std::strtod(this->StringValue.c_str(), 0);
	rhsVal = std::strtod(rhs.StringValue.c_str(), 0);
	result = lhsVal / rhsVal;
	ss << result;
	if (getType() < rhs.getType())
	{
		return (IOperandController::Instance().createOperand(rhs.getType(),  ss.str()));
	}
	else
	{
		return (IOperandController::Instance().createOperand(this->getType(),  ss.str()));
	}
	return (ret);
}

IOperand const				*Int16::operator%( IOperand const & rhs ) const
{
	double					lhsVal;
	double					rhsVal;
	double					result;
	std::stringstream		ss;
	IOperand				*ret;

	lhsVal = std::strtod(this->StringValue.c_str(), 0);
	rhsVal = std::strtod(rhs.StringValue.c_str(), 0);
	result = fmod(lhsVal,rhsVal);
	
	ss << result;
	if (getType() < rhs.getType())
	{
		return (IOperandController::Instance().createOperand(rhs.getType(),  ss.str()));
	}
	else
	{
		return (IOperandController::Instance().createOperand(this->getType(),  ss.str()));
	}
	return (ret);
}
	
std::string const			&Int16::toString( void ) const
{
	std::string const &retval = *(new std::string(this->StringValue));
	return ((retval));
}
