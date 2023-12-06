#include "RPN.hpp"

#include <cctype> // std::isdigt(), std::isspace()

std::stack<RPN::token_type> RPN::stack_;

const struct RPN::operations RPN::operations_[op_size] = {
	{ '+', &RPN::OpSum },
	{ '-', &RPN::OpSub },
	{ '*', &RPN::OpMul },
	{ '/', &RPN::OpDiv }
};

RPN::result_type RPN::ResolveExpression(const std::string &line)
{
	if (line.empty()) {
		return 0;
	}
	for (std::string::const_iterator it = line.begin(); it != line.end(); ++it) {
		if (std::isspace(*it))
			continue;
		else if (std::isdigit(*it))
			PushToken(static_cast<token_type>(*it - '0'));
		else
			Operate(static_cast<op_type>(*it));
	}
	if (stack_.size() > 1)
		throw::std::runtime_error("Operations ended and stack has more than 1 item");
	result_type ret = stack_.top();
	stack_ = std::stack<token_type>();
	return ret;
}

void RPN::PopOperandsTokens(token_type &lhs, token_type &rhs)
{
	if (stack_.size() < 2)
		throw std::runtime_error("RPN stack must have at less 2 items to do operations");
	rhs = stack_.top();
	stack_.pop();
	lhs = stack_.top();
	stack_.pop();
}

void RPN::PushToken(token_type token)
{
	stack_.push(token);
}

void RPN::Operate(op_type symbol)
{
	for (short i = 0; i < op_size; ++i) {
		if (operations_[i].symbol == symbol) {
			token_type lhs = 0, rhs = 0;
			PopOperandsTokens(lhs, rhs);
			token_type res = (*(operations_[i].calc))(lhs, rhs);
			PushToken(res);
			return;
		}
	}
	throw std::runtime_error("Encoutered an undefined operator");
}

RPN::token_type RPN::OpSum(const token_type &lhs, const token_type &rhs)
{
	return lhs + rhs;
}
RPN::token_type RPN::OpSub(const token_type &lhs, const token_type &rhs)
{
	return lhs - rhs;
}
RPN::token_type RPN::OpMul(const token_type &lhs, const token_type &rhs)
{
	return lhs * rhs;
}
RPN::token_type RPN::OpDiv(const token_type &lhs, const token_type &rhs)
{
	if (rhs == 0)
		throw std::runtime_error("Tried to divide by 0");
	return lhs / rhs;
}
