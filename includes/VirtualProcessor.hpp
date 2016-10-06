/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualProcessor.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:52:52 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/06 16:52:55 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

class VirtualProcessor
{
	public:
						// Default Copplien methods
							VirtualProcessor( void );
							VirtualProcessor( VirtualProcessor const &src );
							~VirtualProcessor( void );
	VirtualProcessor		&operator=( VirtualProcessor const &rhs );


	void					InstructionsReception();
	//getters / setters
	void					LinkVMSettings(t_avm *VMSettings);

	private:
		IOperandController		IOperandController;
		t_avm					*VMSettings;
};
