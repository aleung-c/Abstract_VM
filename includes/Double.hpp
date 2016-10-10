/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:47:52 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 17:47:54 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

class Double : public IOperand
{
	public:

	// Default Copplien methods
								Double( void );
								Double( Double const &src );
								~Double( void );
	class Double						&operator=( Double const &rhs );

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
