/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:16:56 by tforster          #+#    #+#             */
/*   Updated: 2025/02/19 18:56:50 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

#include <exception>
#include <stdexcept>

class	RPN {
	private:
		std::stack<int>	_stack;
		std::string		_input;

		// typedef operate() ;

		// struct	plus {
		// 	int operator()(int top, int bellow);
		// };

		// typedef std::string		(Contact::*ContactGetter)(void) const;
		// static ContactGetter	getters[FIELD_COUNT];

		// typedef void 	(*getOperator(const char token))(int, int);
		// getOperator		func[5];

		void	getOperator(const char token);

		template <typename Oprt>
		void	process_operation(Oprt op) {
			int	lvalue = -1, rvalue = -1;
			if (RPN::_stack.size() < 2)
				throw (std::runtime_error("RPN: invalid expression 4"));
			rvalue = RPN::_stack.top();
			RPN::_stack.pop();
			lvalue = RPN::_stack.top();
			RPN::_stack.pop();
			RPN::_stack.push(op(lvalue, rvalue));
		}

	public:
		RPN(void);
		RPN(const std::string input);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);

		int	solver(void);
};



#endif
