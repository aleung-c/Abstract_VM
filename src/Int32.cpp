/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:48:18 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:48:20 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

Int32::Int32( void )
{

}

Int32::Int32( Int32 const &src )
{

}

Int32::~Int32( void )
{

}

class Int32		&Int32::operator=( Int32 const &rhs )
{
	this->StringValue = rhs.StringValue;
	return (*this);
}

// interface methods
int							Int32::getPrecision( void ) const
{
	return (4);
}

eOperandType				Int32::getType( void ) const
{
	return ::Int32;
}

IOperand const				*Int32::operator+( IOperand const & rhs ) const
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

IOperand const				*Int32::operator-( IOperand const & rhs ) const
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
	
IOperand const				*Int32::operator*( IOperand const & rhs ) const
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

IOperand const				*Int32::operator/( IOperand const & rhs ) const
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

IOperand const				*Int32::operator%( IOperand const & rhs ) const
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
	
std::string const			&Int32::toString( void ) const
{
	std::string const &retval = *(new std::string(this->StringValue));
	return ((retval));
}
