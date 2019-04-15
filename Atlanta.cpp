#include <iostream>
#include "Atlanta.h"

void Atlanta::writeToFile(ostream &file) {
	file << "Atlanta" << endl;
	State::writeToFile(file);
}

void Atlanta::readFromFile(istream &file) {
	State::readFromFile(file);
}

istream &operator>>(istream &in, Atlanta &qa) {
	in >> static_cast<State &>(qa);
	return in;
}

ostream &operator<<(ostream &os, const Atlanta &qa) {
	os << "Атлантида - " << static_cast<const State &>(qa);
	return os;
}

void Atlanta::toConsole() {
	cout << *this;
}

string Atlanta::getFilename() {
	return "Atlanta.txt";
}