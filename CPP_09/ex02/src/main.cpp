/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:16:48 by tforster          #+#    #+#             */
/*   Updated: 2025/02/25 19:00:52 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <cmath>
#include "lib/color.hpp"

void	merge(std::vector<int> &vec);
void	printMerge(std::size_t level, std::vector<int> &vec, bool before = true);

int	main(int argc, char ** argv) {
	std::system("clear");
	(void)argc;
	(void)argv;
	std::cout << "Number of arg: " << argc - 1 << ENDL;

	// int	input[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// // int	input[] = {17, 2, 11, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// // int	input[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	// std::size_t			size = 22;
	// std::vector<int>	vector(22);

	int input[] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	std::size_t			size = 26;
	std::vector<int>	vector(26);

	std::cout << "CAPACITY " << vector.capacity() << ENDL;
	std::cout << "SIZE " << vector.size() << ENDL;
	std::cout << "MAX_SIZE " << vector.max_size() << ENDL;
	for (std::size_t i = 0; i < size; ++i) {std::cout << vector[i] << " | ";}
	std::cout << ENDL;

	for (std::size_t i = 0; i < size; ++i) {vector[i] = input[i];}

	std::cout << "ORIGINAL: " ENDL;
	for (std::size_t i = 0; i < size; ++i) {std::cout << vector[i] << " | ";}
	std::cout << ENDL << ENDL;

	std::cout << "FIRST MERGE: " ENDL;
	merge(vector);
	std::cout << ENDL;



	// std::vector<int>::iterator it = vector.begin();
	// std::advance(it, 2);
	// std::swap(*vector.begin(), *vector.rbegin());

	return (EXIT_SUCCESS);
}

void	merge(std::vector<int> &vec) {
	std::size_t level = 0;
	std::size_t vecSize = vec.size();
	std::size_t step = std::pow(2, level);
	std::size_t	groupSize = 2*step;
	std::size_t	groupStart = step - 1;
	std::size_t	numberOfGroups = vecSize / groupSize;

	while (numberOfGroups > 0) {
		std::cout
			<< " MERGE LEVEL: " << level << ENDL
			<< " NB_OF_GROUPS: " << numberOfGroups << " TOTAL_VALID: " << (vecSize - numberOfGroups * groupSize) % step<< ENDL
			<< " STEP: " << step << ENDL
			<< " GROUP_START " << groupStart << ENDL
			<< " GROUP_SIZE: " << groupSize << ENDL;
		printMerge(level, vec);

		for (std::size_t i = groupStart, g = 0 ; g < numberOfGroups ; i += groupSize, ++g) {
			if (vec[i] > vec[i + step]) {
				// std::cout << "TRUE: " << vec[i] << " | " << vec[i + step] << ENDL;
				for (std::size_t j = i - (groupStart), c = 0; c < step; j++, c++) {
					// std::cout << "IN FOR\n";
					int	temp = vec[j];
					vec[j] = vec[j + step];
					vec[j + step] = temp;
				}
			}
		}
		printMerge(level, vec, false);
		step = std::pow(2, ++level);
		groupSize = 2*step;
		groupStart = step - 1;
		numberOfGroups = vecSize / groupSize;
	}

	std::vector<int>	temp(26);

	// groupSize /= 2;
	// step /= 2;
	// level /= 2;

	step = std::pow(2, --level);
	groupSize = 2*step;
	groupStart = step - 1;
	numberOfGroups = vecSize / groupSize;

	std::cout
		<< " > STEP: " << step << ENDL
		<< " > GROUP_SIZE: " << groupSize << ENDL
		<< " > FIRST_LEFT_OVER: " << vec[groupSize + 0] << ENDL;
	for (std::size_t i = 0, left = 0; i < vecSize; ++i) {
		if (i < groupSize && left < step && (vec[i] > vec[groupSize + left])) {
			// std::cout << i << " TRUE\n";
			temp[i] = vec[groupSize + left];
			++left;
		}
		else if(i < groupSize + left)
			temp[i] = vec[i - left];
		else
			temp[i] = vec[i];;
	}
	printMerge(level, temp);

	step = std::pow(2, --level);
	groupSize = 2*step;
	groupStart = step - 1;
	numberOfGroups = vecSize / groupSize;
	printMerge(level, temp);





};

void	printMerge(std::size_t level, std::vector<int> &vec, bool before) {
	std::size_t	step = std::pow(2, level);
	std::size_t	groupSize = 2*step;
	std::size_t	groupStart = step - 1;
	std::size_t	nbOfGroups = vec.size() / groupSize;

	std::size_t vecSize = vec.size();
	// std::size_t	numberOfGroups = vecSize / groupSize;

	std::size_t	newNB = nbOfGroups * groupSize;
	std::size_t	XXX = vecSize - (vecSize - newNB) % step;

	std::size_t	pos = 0;
	bool		backGround = true;
	if (before)
		std::cout << BOLD COP "Merge iteration level: " << level << " | " << newNB << ENDL
			<< vecSize - newNB << " | " << XXX << ENDL
			<< "BEFORE: " RST;
	else
		std::cout << BOLD COP "AFTER:  " RST;

	// std::size_t left = 0;
	for (std::size_t i = 0, groupNb = 0; i <  vec.size(); ++i) {
			if (i < XXX && groupNb >= nbOfGroups)
				std::cout << U_LINE O_LINE;

		// if (groupNb < newNB) {
			// std::cout << RST;
			if (i < XXX && backGround)
				std::cout << BG_GS_0;
			else if (i < XXX)
				std::cout << BG_GS_15;
			// else
			// 	std::cout << RST;

			// if (i <= groupStart) {
			if (i < XXX && i <= groupStart) {
				std::cout << YLW;
				if (i == groupStart)
					std::cout << H_YLW BOLD ITALIC;
			}
			// else if (i >= groupStart + 1) {
			else if (i < XXX && i >= groupStart + 1) {
				std::cout << D_BLU;
				if (i == groupStart + step){
					std::cout << V_BLU BOLD ITALIC;
					groupStart += groupSize;
				}
			}
		// }
		// else {
		// 	++left;
		// 	if (left > step){
		// 		std::cout << REVERSE BOLD;
		// 	}
		// }

		std::cout << " " << vec[i] << " ";
		if (++pos == groupSize) {
			backGround = !backGround;
			pos = 0;
			++groupNb;
		}
		std::cout << RST;
	}
	std::cout << RENDL;
}
