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
**	Special exceptions handling.
*/

// TODO : change it into heriting std::runtime for maximum points.

class FileOpeningError: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class MachineInitialisationError: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class FileReadingError: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class NullvarDetected: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class LexicalError: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class ParsingError: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class ValueOverflow: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class ValueUnderflow: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class EmptyStack: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class ZeroDiv: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class NoExit: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class TrueAssertion: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class StackLessThanTwo: public std::exception
{
	public:
		virtual const char	*what() const throw();
};