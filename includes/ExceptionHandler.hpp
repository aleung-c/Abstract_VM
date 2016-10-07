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

class FileOpeningError: public std::runtime_error
{
	public:
		FileOpeningError(const std::string& what_arg);
};

class MachineInitialisationError: public std::runtime_error
{
	public:
		MachineInitialisationError(const std::string& what_arg);
};

class FileReadingError: public std::runtime_error
{
	public:
		FileReadingError(const std::string& what_arg);
};

class NullvarDetected: public std::runtime_error
{
	public:
		NullvarDetected(const std::string& what_arg);
};

class LexicalError: public std::runtime_error
{
	public:
		LexicalError(const std::string& what_arg);
};

class ParsingError: public std::runtime_error
{
	public:
		ParsingError(const std::string& what_arg);
};

class ValueOverflow: public std::runtime_error
{
	public:
		ValueOverflow(const std::string& what_arg);
};

class ValueUnderflow: public std::runtime_error
{
	public:
		ValueUnderflow(const std::string& what_arg);
};

class EmptyStack: public std::runtime_error
{
	public:
		EmptyStack(const std::string& what_arg);
};

class ZeroDiv: public std::runtime_error
{
	public:
		ZeroDiv(const std::string& what_arg);
};

class NoExit: public std::runtime_error
{
	public:
		NoExit(const std::string& what_arg);
};

class TrueAssertion: public std::runtime_error
{
	public:
		TrueAssertion(const std::string& what_arg);
};

class StackLessThanTwo: public std::runtime_error
{
	public:
		StackLessThanTwo(const std::string& what_arg);
};