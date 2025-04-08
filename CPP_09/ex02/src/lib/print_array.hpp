




#ifndef PRINT_ARRAY_HPP
# define PRINT_ARRAY_HPP
# include <string>
# include <iostream>
# include <iomanip>
# include "typedef.hpp"
# include "../include/CtrlVar.hpp"
# include "color.hpp"

extern const sz_t	CNT_SIZE;

#define INDEX 1
#define SPLIT 1
#define NONE 0

std::string strip_ansi(const std::string &str);

// ===============================
// Dereference Helper Templates
// ===============================
template <typename Cnt>
struct	Get {
	typedef	typename Cnt::iterator	it_t;

	inline static int	value(Cnt &container, sz_t i) {
		it_t it = container.begin();
		std::advance(it, i);
		return (*it);
	}
};

template <>
struct	Get<int*> {
	typedef	int* it_t;

	inline static int	value(int *ptr, sz_t i) {
		return (*(ptr + i));
	}
};

// ==========================
// Parcial Print Templates
// ==========================
template <typename Cnt>
void	printBefore(Ctrl &var, Cnt &conatiner, const char *step) {
	if (var._cntSize <= CNT_SIZE) {
		std::cout
			<< COP U_LINE << std::setfill(' ') << std::setw(25) << "" << std::flush
			<< COP << step << " Iteration " << var._level << ": Pair Size = " << var._pairSize << std::flush
			<< std::setfill(' ') << std::setw(25) << "" << std::flush << RENDL;
		printArray(var, conatiner, NONE, INDEX, var._cntSize, H_GRN "Before");
	}
}

template <typename Cnt>
void	printAfter(Ctrl &var, Cnt &conatiner) {
	if (var._cntSize <= CNT_SIZE) {
		printArray(var, conatiner, NONE, NONE, var._cntSize, H_GRN "After");
		std::cout << ENDL;
	}
}

template <typename Cnt>
void	printStartMain(Ctrl &var, Cnt &conatiner, sz_t copied) {
	if (var._cntSize <= CNT_SIZE) {
		printArray(var, conatiner, SPLIT, NONE, copied, "Start Main");
	}
}

template <typename Cnt>
void	printInsertAs(Ctrl &var, Cnt &conatiner, sz_t copied, sz_t partialMove, sz_t jacob_diff, sz_t i) {
	if (var._cntSize <= CNT_SIZE) {
		std::cout
			<< ENDL COP "Inserions lefts = " << partialMove
			<< " (Jacobsthal diff. = " <<  jacob_diff << ")" <<  RENDL;
			if (i)
				printArray(var, conatiner, SPLIT, NONE, copied, "Insert " ITALIC "a's" RST );
	}
}

template <typename Cnt>
void	msgInsertB(Ctrl &var, Cnt &conatiner, sz_t revBi, int value, sz_t iBnry, std::ostringstream &oss) {
	if (var._cntSize <= CNT_SIZE) {
		oss << ITALIC << "b" << revBi + 1 << ORG "(" << value << ")" RST
			<< " at " ITALIC ORG << Get<Cnt>::value(conatiner, (iBnry + 1) * var._order - 1) << RST;
	}
}

template <typename Cnt>
void	printInsertB(Ctrl &var, Cnt &conatiner, sz_t copied, std::ostringstream &oss) {
	if (var._cntSize <= CNT_SIZE) {
		printArray(var, conatiner, SPLIT, NONE, copied, oss.str());
	}
}

// ==================
// Print Template
// ==================
template <typename Cnt>
void	printArray(Ctrl &var, Cnt &container, bool split, bool index, sz_t len, const std::string &text) {
	bool		keepBackGround = true;
	std::string	backGroundColor = "";
	sz_t		start = var._pairStart;
	sz_t		pairSize = var._pairSize;
	sz_t		pos = 0;
	sz_t		textLen = 14 + text.length() - strip_ansi(text).length();

	if (index)
		std::cout << ENDL << std::left << std::setw(textLen) << text << RST;
	else if (!index)
		std::cout << std::left << std::setw(textLen) << text << RST;

	if (split)
		 pairSize /= 2;

	int8_t hDidp = 0;
	for (sz_t i = 0, groupNb = 0; i < len; ++i) {
		hDidp = groupNb < 9 ? 0 : 1;

		if (i < var._nbElements_noLeftOver) {
			if (keepBackGround) {
				backGroundColor += BG_GS_0;
				std::cout << backGroundColor;
			} else {
				backGroundColor += BG_GS_3;
				std::cout << backGroundColor;
			}
			if (i == start) {
				std::cout << RST BOLD ORG ITALIC;
				if (index) {
					std::cout << C_VERT(1) << "b" << (groupNb + 1)
						<< C_VERT(-1) << C_HORZ(-(2 + hDidp));
				}
				std::cout << backGroundColor;
			}
			else if (i == start + var._order) {
				std::cout << RST BOLD ORG ITALIC;
				if (index) {
					std::cout << C_VERT(1) << "a" << (groupNb + 1)
						<< C_VERT(-1) << C_HORZ(-(2 + hDidp));
				}
				std::cout << backGroundColor;
				start += pairSize;
			}
		} else
			std::cout << L_RED;

		if (i == start) {
			std::cout << "[" << Get<Cnt>::value(container, i) << "]";
		} else {
			if (i == start + var._order - pairSize)
				std::cout << "[" << Get<Cnt>::value(container, i) << "]";
			else
				std::cout << " " << Get<Cnt>::value(container, i) << " ";
		}

		if (++pos == pairSize) {
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
