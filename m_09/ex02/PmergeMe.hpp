#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <climits>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void sort(int argc, char **argv);

private:
	std::vector<int> _vec;
	std::deque<int> _deq;

	void parseInput(int argc, char **argv);
	void displaySequence(const std::string &prefix, const std::vector<int> &seq) const;

	// Ford-Johnson for vector
	void fordJohnsonVector(std::vector<int> &arr);
	void binaryInsertVector(std::vector<int> &sorted, int value);

	// Ford-Johnson for deque
	void fordJohnsonDeque(std::deque<int> &arr);
	void binaryInsertDeque(std::deque<int> &sorted, int value);

	// Jacobsthal number
	std::vector<int> getJacobsthalOrder(int n) const;
};

#endif
