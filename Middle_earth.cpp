#include <iostream>
#include "Middle_earth.h"

void Middle_earth::writeToFile(ostream &file) {
	file << "Middle_earth" << endl;
	State::writeToFile(file);
}

void Middle_earth::readFromFile(istream &file) {
	State::readFromFile(file);
}

istream &operator >> (istream &in, Middle_earth &p) {
	in >> static_cast<State &>(p);
	return in;
}

ostream &operator<<(ostream &os, const Middle_earth &p) {
	os << "ׁנוהטחולüו - " << static_cast<const State &>(p);
	return os;
}

void Middle_earth::toConsole() {
	cout << *this;
}

string Middle_earth::getFilename() {
	return "Middle_earth.txt";
}