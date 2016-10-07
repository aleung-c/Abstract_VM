/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:46:06 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 15:46:08 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parent class for each value type.
**
**	List of values:
**	Int8
**	Int16
**	Int32
**	Float
**	Double
*/

#include "AbstractVM.hpp"

class IOperand {
	
	public:
	std::string							StringValue;
	
	virtual int							getPrecision( void ) const = 0;						// Precision of the type of the instance
	virtual eOperandType				getType( void ) const = 0;							// Type of the instance
	
	virtual IOperand const				*operator+( IOperand const & rhs ) const = 0;		// Sum
	virtual IOperand const				*operator-( IOperand const & rhs ) const = 0;		// Difference
	virtual IOperand const				*operator*( IOperand const & rhs ) const = 0;		// Product
	virtual IOperand const				*operator/( IOperand const & rhs ) const = 0;		// Quotient
	virtual IOperand const				*operator%( IOperand const & rhs ) const = 0;		// Modulo
	
	virtual std::string const			&toString( void ) const = 0;						// String representation of the instance

	virtual								~IOperand( void ) {}
};
