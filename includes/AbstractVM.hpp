/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:29:17 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 15:29:21 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include "../libft/libft.h"
# include <iostream>
# include <string>
# include <exception>


enum					eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

// Struct definition;
typedef struct			s_avm
{



}						t_avm;

// Class Declarations.
class IOperand;
class IOperandController;
class InputController;
class ExceptionHandler;


class VMController;



#include "IOperand.hpp"
#include "IOperandController.hpp"
#include "InputController.hpp"
#include "ExceptionHandler.hpp"


#include "VMController.hpp"


#endif
