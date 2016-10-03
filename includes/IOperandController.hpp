/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperandController.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:58:55 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 15:58:58 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Factory for the IOperands.
*/

class IOperandController
{
	public:
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;

	private:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
};
