/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionHandler.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:16:57 by aleung-c          #+#    #+#             */
/*   Updated: 2016/10/03 17:16:59 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

/*
**	Special exception handling.
*/

class MyExceptions: public std::exception
{
	public:
		class NullvarDetected
		{
			public:
				virtual const char	*what() const throw();
		};
};