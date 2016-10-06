/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:47:16 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:47:20 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

class Int8 : public IOperand
{
	public:
	
	// Default Copplien methods
								Int8( void );
								Int8( Int8 const &src );
								~Int8( void );
	Int8						&operator=( Int8 const &rhs );

	// Interface methods
	int							getPrecision( void ) const = 0;						// Precision of the type of the instance
	eOperandType				getType( void ) const = 0;							// Type of the instance
	
	IOperand const				*operator+( IOperand const & rhs ) const = 0;		// Sum
	IOperand const				*operator-( IOperand const & rhs ) const = 0;		// Difference
	IOperand const				*operator*( IOperand const & rhs ) const = 0;		// Product
	IOperand const				*operator/( IOperand const & rhs ) const = 0;		// Quotient
	IOperand const				*operator%( IOperand const & rhs ) const = 0;		// Modulo
	
	 std::string const			&toString( void ) const = 0;						// String representation of the instance

	
};