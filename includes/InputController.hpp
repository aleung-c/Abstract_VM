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

		// Public variables
		std::ifstream					CurrentFile;
		std::string						ProgramString;
		std::list<t_token>				TokenList;

		// Default Copplien methods
										InputController( void );
										InputController( InputController const &src );
										~InputController( void );
		InputController					&operator=( InputController const &rhs );

		// Public Methods
		// Get the input
		void							GetInput(int argc, char **argv);
		std::string						ReadFromFile(std::string path);
		std::string						ReadFromStdIn();
		std::string						CleanInputFromStdIn();

		// Lex the input
		void							LexInput();
		int								LexerCheck();

		// parse the input - 4 steps
		void							ParseInput();
		void							ParseTokenOrder(std::list<t_token>::iterator it, int *nbOfErrors);
		void							ParseDictionnaryComparison(std::list<t_token>::iterator it, int *nbOfErrors);
		void							ParseSpecificRules(std::list<t_token>::iterator it, int *nbOfErrors);
		void							ParseValuesRules(std::list<t_token>::iterator it, int *nbOfErrors);

		// translate it for machine process;
		void							TranslateInputIntoMachineInstruction();
		eOperandType					GetOperandTypeOfValue(t_token	&ValueToken);
		std::string						GetStringValueOfValue(t_token	&ValueToken);
		// Setters / getters
		void							LinkVMSettings(t_avm *VMSettings);

	private:
		t_avm							*VMSettings;

};