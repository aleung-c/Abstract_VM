/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:29:37 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 15:29:41 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractVM.hpp"

int main(int argc, char **argv)
{
	std::cout << KMAG "- AbstractVM Starting -" KRESET << std::endl;
	if (argc != 0 && argv)
	{
		t_avm			VMSettings;
		VMController	MainVMContoller;

		MainVMContoller.SetVMSettings(VMSettings);
		MainVMContoller.InitDictionnaries();
		return (MainVMContoller.Run(argc, argv));
	}
	return (0);
}
