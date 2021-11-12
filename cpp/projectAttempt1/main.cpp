#include "headers/headers.h"


void cli_interface() {
	string a;
	std::cin >> a;
	rx(a);
}

int main() {
	cli_interface();
	return 0;
}
