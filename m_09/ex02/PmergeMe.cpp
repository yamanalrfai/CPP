#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		std::string arg(argv[i]);
		if (arg.empty()) {
			std::cerr << "Error" << std::endl;
			std::exit(1);
		}
		for (size_t j = 0; j < arg.length(); j++) {
			if (!std::isdigit(arg[j])) {
				std::cerr << "Error" << std::endl;
				std::exit(1);
			}
		}
		long val = std::atol(arg.c_str());
		if (val <= 0 || val > INT_MAX) {
			std::cerr << "Error" << std::endl;
			std::exit(1);
		}
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
}

void PmergeMe::displaySequence(const std::string &prefix, const std::vector<int> &seq) const {
	std::cout << prefix;
	for (size_t i = 0; i < seq.size(); i++) {
		std::cout << seq[i] << ((i + 1 < seq.size()) ? " " : "");
	}
	std::cout << std::endl;
}

std::vector<int> PmergeMe::getJacobsthalOrder(int n) const {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (jacobsthal.back() < n) {
		size_t sz = jacobsthal.size();
		jacobsthal.push_back(jacobsthal[sz - 1] + 2 * jacobsthal[sz - 2]);
	}
	std::vector<int> order;
	std::vector<bool> used(n, false);

	for (size_t i = 2; i < jacobsthal.size(); i++) {
		int jn = jacobsthal[i];
		if (jn > n)
			jn = n;
		for (int k = jn; k > jacobsthal[i - 1]; k--) {
			if (k - 1 >= 0 && k - 1 < n && !used[k - 1]) {
				order.push_back(k - 1);
				used[k - 1] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!used[i])
			order.push_back(i);
	}

	return order;
}

void PmergeMe::binaryInsertVector(std::vector<int> &sorted, int value) {
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}

void PmergeMe::fordJohnsonVector(std::vector<int> &arr) {
	if (arr.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	bool hasStraggler = false;
	int straggler = 0;
	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	if (arr.size() % 2 != 0) {
		hasStraggler = true;
		straggler = arr.back();
	}
	std::vector<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);
	std::vector<int> origLargers = largers;
	fordJohnsonVector(largers);
	std::vector<int> smallers(largers.size());
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < largers.size(); i++) {
		for (size_t j = 0; j < origLargers.size(); j++) {
			if (!used[j] && origLargers[j] == largers[i]) {
				smallers[i] = pairs[j].second;
				used[j] = true;
				break;
			}
		}
	}
	std::vector<int> sorted = largers;
	if (!smallers.empty())
		sorted.insert(sorted.begin(), smallers[0]);
	if (smallers.size() > 1) {
		std::vector<int> order = getJacobsthalOrder(static_cast<int>(smallers.size()) - 1);
		for (size_t i = 0; i < order.size(); i++) {
			int idx = order[i] + 1;
			if (idx < static_cast<int>(smallers.size()))
				binaryInsertVector(sorted, smallers[idx]);
		}
	}
	if (hasStraggler)
		binaryInsertVector(sorted, straggler);
	arr = sorted;
}

void PmergeMe::binaryInsertDeque(std::deque<int> &sorted, int value) {
	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &arr) {
	if (arr.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	bool hasStraggler = false;
	int straggler = 0;

	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	if (arr.size() % 2 != 0) {
		hasStraggler = true;
		straggler = arr.back();
	}

	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	std::deque<int> origLargers = largers;
	fordJohnsonDeque(largers);
	std::deque<int> smallers(largers.size());
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < largers.size(); i++) {
		for (size_t j = 0; j < origLargers.size(); j++) {
			if (!used[j] && origLargers[j] == largers[i]) {
				smallers[i] = pairs[j].second;
				used[j] = true;
				break;
			}
		}
	}
	std::deque<int> sorted = largers;
	if (!smallers.empty())
		sorted.push_front(smallers[0]);
	if (smallers.size() > 1) {
		std::vector<int> order = getJacobsthalOrder(static_cast<int>(smallers.size()) - 1);
		for (size_t i = 0; i < order.size(); i++) {
			int idx = order[i] + 1;
			if (idx < static_cast<int>(smallers.size()))
				binaryInsertDeque(sorted, smallers[idx]);
		}
	}
	if (hasStraggler)
		binaryInsertDeque(sorted, straggler);

	arr = sorted;
}

void PmergeMe::sort(int argc, char **argv) {
	parseInput(argc, argv);

	std::vector<int> unsorted = _vec;

	clock_t startVec = clock();
	fordJohnsonVector(_vec);
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	// Sort with deque
	clock_t startDeq = clock();
	fordJohnsonDeque(_deq);
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	// Display
	std::cout << "Before:\t";
	for (size_t i = 0; i < unsorted.size(); i++) {
		std::cout << unsorted[i];
		if (i + 1 < unsorted.size())
			std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "After:\t";
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i];
		if (i + 1 < _vec.size())
			std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
