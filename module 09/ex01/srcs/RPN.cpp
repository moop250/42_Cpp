/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:15:07 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/26 17:29:42 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RPN.hpp"

size_t RPN::calculate(const std::string in) {
	std::stack<int>	stack;
	std::string		tmp;
	size_t			i = 0, j = 0;
	int				num1, num2;

	while (in[i]) {
		bool			numbers = true;
	
		i = in.find_first_not_of(' ', j);
		if (i == std::string::npos)
			break;
		j = in.find(' ', i);
		if (j == std::string::npos)
			j = in.length();
		tmp = in.substr(i, j - i);
		for (size_t len = tmp.length(), pos = 0; pos < len; pos++) {
			if (!strchr(NUMBERS, tmp[pos])) {
				numbers = false;
				continue ;
			}
		}
		if (!numbers) {
			size_t count = 0;
			for (size_t len = tmp.length(), pos = 0; pos < len; pos++) {
				if (!strchr(OPERATIONS, tmp[pos]))
					throw std::runtime_error("Invalid characters");
				if (!strchr(WHITESPACE, tmp[pos])) {
					++count;
					if (count >= 2)
		 				throw std::runtime_error("Invalid operator sequence");
				}
			}
		}
		
		if (numbers) {
			try {
				stack.push(atoi(tmp.c_str()));
			}
			catch (const std::out_of_range& e) {
				throw std::invalid_argument("Number out of range");
			}
		}
		else {
			if (stack.size() < 2)
				throw std::invalid_argument("Invalid sequence");

			num2 = stack.top();
			stack.pop();
			num1 = stack.top();
			stack.pop();
			
			switch (tmp[0]) {
				case '+':
					stack.push(num1 + num2);
					break;
				case '-':
					stack.push(num1 - num2);
					break;
				case '/':
					if (num2 == 0)
						throw std::runtime_error("Division by 0");
					stack.push(num1 / num2);
					break;
				case '*':
					stack.push(num1 * num2);
					break;
				default:
					throw std::runtime_error("Invalid operation");
			}
		}
	}

	if (stack.size() == 1)
		return stack.top();
	else
		throw std::invalid_argument("Invalid sequence");
}
