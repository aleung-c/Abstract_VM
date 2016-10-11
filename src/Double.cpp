/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:48:32 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:48:34 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

Double::Double( void )
{

}

Double::Double( Double const &src )
{

}

Double::~Double( void )
{

}

class Double		&Double::operator=( Double const &rhs )
{
	this->StringValue = rhs.StringValue;
	return (*this);
}

// interface methods
int							Double::getPrecision( void ) const
{
	return (15);
}

eOperandType				Double::getType( void ) const
{
	return ::Double;
}

IOperand const				*Double::operator+( IOperand const & rhs ) const
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

IOperand const				*Double::operator-( IOperand const & rhs ) const
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
	
IOperand const				*Double::operator*( IOperand const & rhs ) const
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

IOperand const				*Double::operator/( IOperand const & rhs ) const
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

IOperand const				*Double::operator%( IOperand const & rhs ) const
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
	
std::string const			&Double::toString( void ) const
{
	return (this->StringValue);
}
