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
	class Int8						&operator=( Int8 const &rhs );

	// Interface methods
	int							getPrecision( void ) const;						// Precision of the type of the instance
	eOperandType				getType( void ) const;							// Type of the instance
	
	IOperand const				*operator+( IOperand const & rhs ) const;			// Sum
	IOperand const				*operator-( IOperand const & rhs ) const;			// Difference
	IOperand const				*operator*( IOperand const & rhs ) const;			// Product
	IOperand const				*operator/( IOperand const & rhs ) const;			// Quotient
	IOperand const				*operator%( IOperand const & rhs ) const;			// Modulo

	std::string const			&toString( void ) const;				// String representation of the instance
};
