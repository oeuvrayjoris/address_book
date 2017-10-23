#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <sstream>

#include "headers/address.hpp"
#include "headers/person.hpp"
#include "headers/menu.hpp"

int main() {
	Book book;
	Menu menu;

	for(;;) {
		book.print();
		menu.print();
		menu.setChoice();
		book.action(menu.getChoice());
	}

	return 0;
}