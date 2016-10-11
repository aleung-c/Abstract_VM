/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VMController.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:53:18 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 16:53:20 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

/*
**	Main controller for the Virtual Machine.
*/
class VMController
{
	public:
							// Default Copplien methods
								VMController( void );
								VMController( VMController const &src );
								~VMController( void );
		VMController			&operator=( VMController const &rhs );




		// My Public methods
		void					InitDictionnaries();
		int						Run(int argc, char **argv);

		int						PrintException(std::runtime_error &e);
		// Getters/Setters
		void					SetVMSettings(t_avm &Settings);

	protected:
		t_avm					*VMSettings;

		// My Controllers
		InputController			InputController;
		VirtualProcessor		VirtualProcessor;
		//IOperandController		IOpController; // present in the virtual processor;
};
