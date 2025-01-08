/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:57:16 by tforster          #+#    #+#             */
/*   Updated: 2024/12/04 14:00:32 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include <cstdlib>
#include <iostream>

static void	show_string(std::string name, std::string str, std::string color);

int	main() {
	system("clear");

	std::string	string = "Text for COLOR TEST!!";

	show_string("Black", string, BG_WHT BLK);
	show_string("Red", string, RED);
	show_string("Green", string, GRN);
	show_string("Yelow", string, YLW);
	show_string("Blue", string, BLU);
	show_string("Magenta", string, MGT);
	show_string("Cyan", string, CYN);
	show_string("White", string, WHT);
	std::cout << ENDL;

	show_string("High-intensity Black", string, BG_WHT H_BLK);
	show_string("High-intensity Red", string, H_RED);
	show_string("High-intensity Green", string, H_GRN);
	show_string("High-intensity Yelow", string, H_YLW);
	show_string("High-intensity Blue", string, H_BLU);
	show_string("High-intensity Magenta", string, H_MGT);
	show_string("High-intensity Cyan", string, H_CYN);
	show_string("High-intensity White", string, H_WHT);
	std::cout << ENDL;

	show_string("Gray scale 0", string, GS_5 BG_GS_0);
	show_string("Gray scale 1", string, GS_4 BG_GS_1);
	show_string("Gray scale 2", string, GS_3 BG_GS_2);
	show_string("Gray scale 3", string, GS_2 BG_GS_3);
	show_string("Gray scale 4", string, GS_1 BG_GS_4);
	show_string("Gray scale 5", string, GS_0 BG_GS_5);
	std::cout << ENDL;

	show_string("Deep Sky Blue", string, D_BLU);
	show_string("Vivid Sky Blue", string, V_BLU);
	show_string("Steel Blue", string, S_BLU);
	show_string("Brown", string, BRW);
	show_string("Copperfield", string, COP);
	show_string("Moderate Orange", string, M_ORG);
	show_string("Teal", string, TEAL);
	show_string("Orange", string, ORG);
	show_string("Pure Magenta", string, P_MGT);
	show_string("Purple", string, PURP);
	show_string("Light Red", string, L_RED);

	return (EXIT_SUCCESS);
}

static void	show_string(std::string name, std::string str, std::string color) {
	std::cout << BOLD U_LINE << color << name << RST ENDL;
	std::cout << color << str << "   " BOLD << str << "   " ITALIC << str << RST ENDL;
}
