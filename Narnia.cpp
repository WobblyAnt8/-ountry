#include <iostream>
#include "Narnia.h"

void Narnia::writeToFile(ostream &file) {
    file << "Narnia" << endl;
    State::writeToFile(file);
}

void Narnia::readFromFile(istream &file) {
    State::readFromFile(file);
}

istream &operator>>(istream &in, Narnia &gp) {
    in >> static_cast<State &>(gp);
    return in;
}

ostream &operator<<(ostream &os, const Narnia &gp) {
    os << "Нарния - " << static_cast<const State &>(gp);
    return os;
}

void Narnia::toConsole() {
    cout << *this;
}

string Narnia::getFilename() {
    return "Narnia.txt";
}