

#ifndef TYPEDEF_HPP
# define TYPEDEF_HPP

# include <vector>

typedef unsigned long sz_t;

template <typename Cnt>
struct type {
	typedef typename Cnt::iterator it;
};

#endif

/*
EXAMPLE
	std::memcpy(&pend[0], &main[bi], var._order * sizeof(int));
	std::copy(&main[bi], &main[bi] + var._order, &pend[0]);

	std::memcpy(FIRST, SECOND, LEN * sizeof(int));
	std::copy(SECOND, SECOND + LEN, FIRST);

	std::memmove(&main[(iBnry + 1) * order], &main[iBnry * order], toMove * sizeof(int));
	std::copy(&main[iBnry * order], &main[iBnry * order] + toMove,	&main[(iBnry + 1) * order]);

Since std::deque isn't contiguous, shifting elements manually is error-prone. Instead, try:

Method 1: Use std::deque::insert
Instead of shifting manually, insert takes care of memory for you:

cpp
Copy
Edit
main.insert(main.begin() + (iBnry + 1) * order, main.begin() + iBnry * order, main.begin() + copied);
Automatically moves elements without risk of overwriting.

Works for std::deque safely, unlike copy_backward.


Method 3: Use std::rotate (Safer than copy_backward)
If you still want to avoid insert, std::rotate can shift elements safely:

cpp
Copy
Edit
std::rotate(main.begin() + iBnry * order, main.begin() + copied, main.begin() + (iBnry + 1) * order);
Shifts elements safely without overlap issues.

Avoids manual copying.




*/
