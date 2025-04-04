


#include <iostream>
// #include "lib/print_array.hpp"
#include "lib/color.hpp"


// template<typename Container>
// void	printArray(ctrl &var, Container main, bool before, bool merge) {
// 	std::size_t	start = var._pairStart;
// 	std::size_t	pos = 0;
// 	bool		keepBackGround = true;
// 	std::string	backGroundColor = "";
// 	if (before) {
// 		if (merge)
// 			std::cout << DENDL BOLD COP " >>> Merge iteration level: " << var._level << ENDL
// 				<< ENDL "BEFORE: " RST;
// 		else
// 			std::cout << DENDL BOLD COP " >>> Insertion Sort iteration level: " << var._level << ENDL
// 				<< ENDL "BEFORE: " RST;
// 	} else
// 		std::cout << ENDL COP << C_VERT(1) << "AFTER:  " RST;

// 	int8_t vd = before ? 1 : -1;
// 	int8_t hd = 0;
// 	for (std::size_t i = 0, groupNb = 0; i <  var._cntSize; ++i) {
// 		hd = groupNb < 10 ? 0 : 1;

// 		if (i < var._nbElements_noLeftOver) {
// 			if (groupNb == var._nb_pairs) {
// 				backGroundColor = U_LINE O_LINE;
// 				std::cout << backGroundColor;
// 			}

// 			if (keepBackGround) {
// 				backGroundColor += BG_GS_0;
// 				std::cout << backGroundColor;
// 			} else {
// 				backGroundColor += BG_GS_3;
// 				std::cout << backGroundColor;
// 			}

// 			if (i <= start) {
// 				std::cout << M_ORG;
// 				if (i == start) {
// 					std::cout << RST BOLD ORG ITALIC
// 						<< C_VERT(vd) << C_HORZ(1)
// 						<< "b" << subscript(groupNb)
// 						<< C_VERT(-vd) << C_HORZ(-(3 + hd))
// 						<< backGroundColor;
// 				}
// 			} else if (i >= start + 1) {
// 				std::cout << S_BLU;
// 				if (i == start + var._order){
// 					std::cout << RST BOLD V_BLU ITALIC
// 						<< C_VERT(vd) << C_HORZ(1)
// 						<< "a" << subscript(groupNb)
// 						<< C_VERT(-vd) << C_HORZ(-(3 + hd))
// 						<< backGroundColor;
// 						start += var._pairSize;
// 				}
// 			}
// 		} else
// 			std::cout << REVERSE BOLD;

// 		std::cout << " " << main[i] << " ";
// 		if (++pos == var._pairSize) {
// 			keepBackGround = !keepBackGround;
// 			pos = 0;
// 			++groupNb;
// 		}
// 		backGroundColor = "";
// 		std::cout << RST;
// 	}
// 	std::cout << RENDL;
// }
