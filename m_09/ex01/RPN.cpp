#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperator(int a, int b, const std::string &op) {
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/") {
		if (b == 0) {
			std::cerr << "Error" << std::endl;
			std::exit(1);
		}
		return a / b;
	}
	return 0;
}

int RPN::evaluate(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (isOperator(token)) {
			if (_stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				std::exit(1);
			}
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			_stack.push(applyOperator(a, b, token));
		}
        else {
			if (token.length() > 1 || !std::isdigit(token[0])) {
				std::cerr << "Error" << std::endl;
				std::exit(1);
			}
			_stack.push(token[0] - '0');
		}
	}

	if (_stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		std::exit(1);
	}

	return _stack.top();
}
