/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:16:56 by tforster          #+#    #+#             */
/*   Updated: 2025/02/20 18:29:08 by tforster         ###   ########.fr       */
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
			int	top = this->top();;
			this->pop();
			int	bellow = this->top();
			this->pop();
			this->push(op(bellow, top));
		}

	public:
		RPN(void);
		RPN(const std::string input);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);

		typedef std::stack<int>::container_type::const_iterator	const_it;
		typedef std::stack<int>::container_type::iterator		it;

		const_it	begin() const {return (this->c.begin());}
		const_it	end() const {return (this->c.end());}
		it			begin(){return (this->c.begin());}
		it			end() {return (this->c.end());}

		int	solver(void);
};

std::ostream &operator<<(std::ostream &os, RPN &rpn);
std::ostream &operator<<(std::ostream &os, const RPN &_rpn);

#endif
