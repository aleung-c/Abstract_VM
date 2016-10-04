/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VMController.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:04:13 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 17:04:15 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

VMController::VMController( void )
{
	std::cout << "Initializing Virtual Machine ..." << std::endl;
}

VMController::VMController( VMController const &src )
{

}

VMController::~VMController( void )
{
	// free stack and stuffs
}

VMController		&VMController::operator=( VMController const &rhs )
{
	(void)rhs;
	return (*this);
}

// Main Control methods

int					VMController::Run(int argc, char **argv)
{
	if (argc != -1 && argv)
	{
		std::cout << "*Virtual Machine starts running*" << std::endl;
		try
		{
			InputController.GetInput(argc, argv);
			InputController.LexInput();
			return (0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			// TODO: free stuff.
			return (-1);
		}
	}
	return (0);
}

// Getters/Setters
void				VMController::SetVMSettings(t_avm &Settings)
{
	try
	{
		this->VMSettings = &Settings;
		if (this->VMSettings)
		{
			std::cout << "VM setting structure linked" << std::endl;
		}
		else
		{
			throw NullvarDetected();
		}

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}