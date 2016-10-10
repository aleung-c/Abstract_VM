/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:47:25 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:47:28 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

class Int16 : public IOperand
{
	public:

	// Default Copplien methods
								Int16( void );
								Int16( Int16 const &src );
								~Int16( void );
	class Int16						&operator=( Int16 const &rhs );

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
