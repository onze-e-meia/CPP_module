




#ifndef PRINT_ARRAY_HPP
# define PRINT_ARRAY_HPP
# include "CtrlVar.hpp"
# include "color.hpp"

// Helper Functions
#define BEFORE 1
#define AFTER 0
#define MERGE 1
#define INSERT 0
#define PRINT 1
#define DONT_PRINT 0

// void		printMerge(Ctrl *c, int *vec, bool before, bool merge);
// void printArray(Ctrl &c, int *vec, bool before, bool merge);

template<typename Container>
void	printArray(Ctrl &var, Container main) {
	std::size_t	start = var._pairStart;
	std::size_t	pos = 0;
	bool		keepBackGround = true;
	std::string	backGroundColor = "";
	// if (before) {
	// 	if (merge)
	// 		std::cout << DENDL BOLD COP " >>> Merge iteration level: " << var._level << ENDL
	// 			<< ENDL "BEFORE: " RST;
	// 	else
	// 		std::cout << DENDL BOLD COP " >>> Insertion Sort iteration level: " << var._level << ENDL
	// 			<< ENDL "BEFORE: " RST;
	// } else
	// 	std::cout << ENDL COP << C_VERT(1) << "AFTER:  " RST;

	for (std::size_t i = 0, groupNb = 0; i <  var._cntSize; ++i) {
		if (i < var._nbElements_noLeftOver) {
			if (groupNb == var._nb_pairs) {
				backGroundColor = U_LINE O_LINE;
				std::cout << backGroundColor;
			}

			if (keepBackGround) {
				backGroundColor += BG_GS_0;
				std::cout << backGroundColor;
			} else {
				backGroundColor += BG_GS_3;
				std::cout << backGroundColor;
			}

			if (i <= start) {
				std::cout << M_ORG;
				if (i == start) {
					std::cout << RST BOLD ORG ITALIC
						<< backGroundColor;
				}
			} else if (i >= start + 1) {
				std::cout << S_BLU;
				if (i == start + var._order){
					std::cout << RST BOLD V_BLU ITALIC
						<< backGroundColor;
						start += var._pairSize;
				}
			}
		} else
			std::cout << REVERSE BOLD;

		std::cout << " " << main[i] << " ";
		if (++pos == var._pairSize) {
			keepBackGround = !keepBackGround;
			pos = 0;
			++groupNb;
		}
		backGroundColor = "";
		std::cout << RST;
	}
	std::cout << RENDL;
}

#endif
