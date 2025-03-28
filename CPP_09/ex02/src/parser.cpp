

#include <iostream>
#include <sstream>
#include <vector>
// #include "typedef/typedef.hpp"
#include "lib/parser.hpp"
#include "lib/color.hpp"

static bool		isValidNumber(char *arg, std::size_t i);
static inline	std::string errorMsg(const char *msg, const char *arg, int i);

typedef std::vector<int>::iterator	Vec_Int_It;

void	parse(int argc, char **argv, std::vector<int> &parsedInput) {
	std::istringstream	iss;
	std::ostringstream	oss;
	long				value;
	Vec_Int_It 			it = parsedInput.begin();

	for (std::size_t i = 1; i < static_cast<std::size_t>(argc); ++i, ++it) {
		if (!isValidNumber(argv[i], i)) {
			oss << errorMsg("invalid input", argv[i], i);
			throw (std::runtime_error(oss.str()));
		} else {
			iss.str(argv[i]);
			iss.clear();
			iss >> value;
			if (iss.fail()) {
				oss << errorMsg("invalid input", argv[i], i);
				throw (std::runtime_error(oss.str()));
			} else
				*it = value;
		}
	}
}

inline std::string errorMsg(const char *msg, const char *arg, int i) {
	std::ostringstream oss;
	oss << BOLD RED "Error: " RST << msg << " {" << arg << "} at position " << i << RENDL;
	return oss.str();
}

bool	isValidNumber(char *arg, std::size_t i) {
	if (!arg || !*arg)
		return (false);

	while (std::isspace(*arg))
		++arg;

	if (*arg == '+')
		++arg;
	else if (*arg == '-') {
		std::ostringstream	oss;
		oss << errorMsg("negative input", arg, i);
		throw (std::runtime_error(oss.str()));
	}

	while (*arg) {
		if (!std::isdigit(*arg)) {
			while (*arg) {
				if (!std::isspace(*arg))
					return (false);
				++arg;
			}
			return (true);
		}
		++arg;
	}
	return (true);
}
