/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:47:41 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:47:47 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

class Float : public IOperand
{
	public:

	// Default Copplien methods
								Float( void );
								Float( Float const &src );
								~Float( void );
	class Float						&operator=( Float const &rhs );

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
