/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputController.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 18:28:40 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 18:28:42 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"


/*
**	Lexer - parser for the virtual machine. Will look at every input 
**	going through the vm.
*/

class InputController
{
	public:
										// Default Copplien methods
										InputController( void );
										InputController( InputController const &src );
										~InputController( void );
		InputController					&operator=( InputController const &rhs );
	
	// Public variables

// TODO: to be continued.
//		void Lexer();
//		void Parser();


};