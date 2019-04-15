#include <iostream>
#include "Westeros.h"

void Westeros::writeToFile(ostream &file) {
	file << "Westeros" << endl;
	State::writeToFile(file);
}

void Westeros::readFromFile(istream &file) {
	State::readFromFile(file);
}
istream &operator >> (istream &in, Westeros &sc) {
	in >> static_cast<State &>(sc);
	return in;
}
ostream &operator<<(ostream &os, const Westeros &sc) {
	os << "Вестерос - " << static_cast<const State &>(sc);
	return os;
}

void Westeros::toConsole() {
	cout << *this;
}
string Westeros::getFilename() {
	return "Westeros.txt";
}