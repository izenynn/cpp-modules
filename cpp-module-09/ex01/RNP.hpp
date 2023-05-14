#ifndef RNP_HPP_
#define RNP_HPP_

#include <string> // std::string
#include <stack> // stack<>
#include <stdexcept> // std::runtime_error()

class RNP {
public:
	typedef int result_type;

	static result_type ResolveExpression(const std::string &line);
private:
	typedef result_type token_type;
	typedef unsigned char op_type;

	RNP();
	~RNP();
	RNP(const RNP &rhs);
	RNP& operator=(const RNP &rhs);

	static std::stack<token_type> stack_;

	static const int op_size = 4;
	static const struct operations {
		op_type symbol;
		token_type (*calc)(const token_type &lhs, const token_type &rhs);
	} operations_[op_size];

	static void GetOperandsTokens(token_type &lhs, token_type &rhs);
	static void PushToken(token_type token);

	static void operate(op_type symbol);

	static token_type OpSum(const token_type &lhs, const token_type &rhs);
	static token_type OpSub(const token_type &lhs, const token_type &rhs);
	static token_type OpMul(const token_type &lhs, const token_type &rhs);
	static token_type OpDiv(const token_type &lhs, const token_type &rhs);
};

#endif // RNP_HPP_
