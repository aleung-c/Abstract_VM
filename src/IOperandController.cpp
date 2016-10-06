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

IOperandController::IOperandController( void )
{
	std::cout << KGRN "IOperandController initialized" KRESET << std::endl;
	/*OperandFunctions =
	{
		&IOperandController::createInt8,
		&IOperandController::createInt16,
		&IOperandController::createInt32,
		&IOperandController::createFloat,
		&IOperandController::createInt8,
	};*/

	OperandFt = &IOperandController::createInt8;

	/*ArrayOfOpFunc[0] = OperandFunctions[0];
	ArrayOfOpFunc[1] = OperandFunctions[1];
	ArrayOfOpFunc[2] = OperandFunctions[2];
	ArrayOfOpFunc[3] = OperandFunctions[3];
	ArrayOfOpFunc[4] = OperandFunctions[4];*/
	//(*OperandFt)("hey");
	//(*OperandFunctions[0])("value");
	//(*OperandFunctions[0])("value");
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

IOperand const * IOperandController::createInt8( std::string const & value ) const
{
	std::cout << "creating int8" << std::endl;
	return (NULL);
}

IOperand const * IOperandController::createInt16( std::string const & value ) const
{
	return (NULL);
}

IOperand const * IOperandController::createInt32( std::string const & value ) const
{
	return (NULL);
}

IOperand const * IOperandController::createFloat( std::string const & value ) const
{
	return (NULL);
}

IOperand const * IOperandController::createDouble( std::string const & value ) const
{
	return (NULL);
}