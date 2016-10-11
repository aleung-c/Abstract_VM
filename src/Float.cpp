/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:48:26 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:48:28 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

Float::Float( void )
{

}

Float::Float( Float const &src )
{

}

Float::~Float( void )
{

}

class Float		&Float::operator=( Float const &rhs )
{
	this->StringValue = rhs.StringValue;
	return (*this);
}

// interface methods
int							Float::getPrecision( void ) const
{
	return (6);
}

eOperandType				Float::getType( void ) const
{
	return ::Float;
}

IOperand const				*Float::operator+( IOperand const & rhs ) const
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

IOperand const				*Float::operator-( IOperand const & rhs ) const
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
	
IOperand const				*Float::operator*( IOperand const & rhs ) const
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

IOperand const				*Float::operator/( IOperand const & rhs ) const
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

IOperand const				*Float::operator%( IOperand const & rhs ) const
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
	
std::string const			&Float::toString( void ) const
{
	return (this->StringValue);
}
