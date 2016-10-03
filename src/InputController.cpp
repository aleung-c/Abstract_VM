/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputController.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 18:33:33 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 18:33:35 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

InputController::InputController( void )
{
	std::cout << "InputController Ready" << std::endl;
}

InputController::InputController( InputController const &src )
{

}

InputController::~InputController( void )
{

}

InputController		&InputController::operator=( InputController const &rhs )
{
	(void)rhs;
	return (*this);
}
