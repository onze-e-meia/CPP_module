/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:03:06 by tforster          #+#    #+#             */
/*   Updated: 2024/10/30 13:43:24 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "../include/color.hpp"

static void	replace(std::ifstream &input_file, std::ofstream &output_file,
					std::string &str1, std::string &str2);

int main(int argc, char **argv) {
	system("clear");
	if (argc != 4) {
		std::cerr << RED "Arguments sholud be: <filename> <string1> <string2>" RST << std::endl;
		return EXIT_FAILURE;
	}
	std::string		filename(argv[1]), str1(argv[2]), str2(argv[3]);

	if (str1.empty()) {
		std::cerr << RED "ERROR: The string to replace <string1> can't be empty" RST << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream	input_file(filename.c_str());
	if (!input_file) {
		std::cerr << RED "ERROR: Could not open input_file" RST << std::endl;
		return EXIT_FAILURE;
	}

	filename += ".replace";
	std::ofstream output_file(filename.c_str());
	if (!output_file) {
		input_file.close();
		std::cerr << RED "ERROR: Could not open output_file" RST << std::endl;
		return EXIT_FAILURE;
	}

	replace(input_file, output_file, str1, str2);
	input_file.close();
	output_file.close();
	return EXIT_SUCCESS;
}

static void	replace(std::ifstream &input_file, std::ofstream &output_file,
					std::string &str1, std::string &str2) {
	std::string	line;
	while (std::getline(input_file, line)) {
		std::string::size_type	pos = 0, found;

		while ((found = line.find(str1, pos)) != std::string::npos) {
			output_file << line.substr(pos, found - pos) << str2;
			pos = found + str1.length();
		}
		output_file << line.substr(pos) << std::endl;
	}

}
