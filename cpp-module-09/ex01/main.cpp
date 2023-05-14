#include <iostream>

#include "RNP.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " \"OPERATION\"\n";
		return 1;
	}
	
	try {
		int res = RNP::ResolveExpression(argv[1]);
		std::cout << "Result: " << res << '\n';
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	
	return 0;
}
