/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:16:56 by tforster          #+#    #+#             */
/*   Updated: 2025/02/21 17:39:42 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <stdexcept>
# include "../lib/color.hpp"

class RPN ;

std::ostream &operator<<(std::ostream &os, RPN &rpn);
std::ostream &operator<<(std::ostream &os, const RPN &_rpn);

class	RPN: public std::stack<int> {
	private:
		std::string		_input;

		struct plus			{ int operator()(int l, int r); };
		struct minus		{ int operator()(int l, int r); };
		struct multiplies	{ int operator()(int l, int r); };
		struct divides		{ int operator()(int l, int r); };

		void	getOperator(const char *token);

		template <typename Oprt>
		void	process_operation(Oprt op, const char *token) {
			if (this->size() < 2) {
				std::ostringstream oss;
				oss << L_RED "Error: " RST << "Stack [" << *this << "] "
					<< "lack number to do operation '"
					<< token << "'";
				throw (std::runtime_error(oss.str()));
			}
			this->push(op(pop(), pop()));
		}

	public:
		RPN(void);
		RPN(const std::string input);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);

		typedef std::stack<int>::container_type::const_iterator	const_it;
		typedef std::stack<int>::container_type::iterator		it;

		int			pop(void);
		const_it	begin() const;
		const_it	end() const;
		it			begin();
		it			end();

		int			solver(void);
};

#endif
