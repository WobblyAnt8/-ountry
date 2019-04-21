#include <iostream>
#include "Oz.h"

void Oz::writeToFile(ostream &file) {
	file << "Oz" << endl;
	State::writeToFile(file);
}

void Oz::readFromFile(istream &file) {
	State::readFromFile(file);
}

istream &operator>>(istream &in, Oz &zx) {
	in >> static_cast<State &>(zx);
	return in;
}

ostream &operator<<(ostream &os, const Oz &zx) {
	os << "Страна Оз - " << static_cast<const State &>(zx);
	return os;
}

void Oz::toConsole() {
	cout << *this;
}

string Oz::getFilename() {
	return "Oz.txt";
}