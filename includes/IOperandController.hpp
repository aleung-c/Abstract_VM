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

#include "AbstractVM.hpp"

/*
**	Factory for the IOperands.
*/

class IOperandController
{
	public:
		
		static IOperandController& Instance(); // Singleton Pattern;
		
		typedef IOperand const *(IOperandController::*OperandFunctions)(std::string const & value) const;
		OperandFunctions OperandFt[5];

		// Default Copplien methods
								IOperandController( void );
								IOperandController( IOperandController const &src );
								~IOperandController( void );
		IOperandController		&operator=( IOperandController const &rhs );


		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	private:
		static IOperandController m_instance; // singleton pattern

		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
};
