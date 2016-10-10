/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:48:06 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:48:08 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

Int8::Int8( void )
{

}

Int8::Int8( Int8 const &src )
{

}

Int8::~Int8( void )
{

}

class Int8		&Int8::operator=( Int8 const &rhs )
{
	this->StringValue = rhs.StringValue;
	return (*this);
}

// interface methods
int							Int8::getPrecision( void ) const
{
	return (1);
}

eOperandType				Int8::getType( void ) const
{
	return ::Int8;
}

IOperand const				*Int8::operator+( IOperand const & rhs ) const
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

IOperand const				*Int8::operator-( IOperand const & rhs ) const
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
	
IOperand const				*Int8::operator*( IOperand const & rhs ) const
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

IOperand const				*Int8::operator/( IOperand const & rhs ) const
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

IOperand const				*Int8::operator%( IOperand const & rhs ) const
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
	
std::string const			&Int8::toString( void ) const
{
	std::string const &retval = *(new std::string(this->StringValue));
	return ((retval));
}

