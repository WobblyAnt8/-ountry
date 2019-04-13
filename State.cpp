#include <iostream>
#include "State.h"

using namespace std;

const string &State::getname() const {
	return name;
}

const string &State::getflag() const {
    return flag;
}

void State::setflag(const string &flag) {
    State::flag = flag;
}

const string &State::getcapital() const {
    return capital;
}

void State::setcapital(const string &capital) {
    State::capital = capital;
}

const string &State::getking() const {
	return king;
}

void State::setking(const string &king) {
	State::king = king;
}

const string &State::getorigin() const {
	return origin;
}

void State::setorigin(const string &origin) {
	State::origin = origin;
}

const string &State::getclimate() const {
	return climate;
}

void State::setclimate(const string &climate) {
	State::climate = climate;
}

bool State::getmagic() const {
	return magic;
}

void State::setmagic(bool magic) {
	State::magic = magic;
}

const string &State::getraces() const {
	return races;
}

void State::setraces(const string &races) {
	State::races = races;
}

const string &State::getbeasts() const {
	return beasts;
}

void State::setbeasts(const string &beasts) {
	State::beasts = beasts;
}

State::~State() {
	name = "";
    flag = "";
    capital = "";
	king = "";
	origin = "";
	climate = "";
	magic = 0;
	races = "";
	beasts = "";
}

State::State(const string &name, const string &flag, const string &capital, const string &king, const string &origin,
	const string &climate, bool magic, const string &races, const string &beasts)
        : flag(flag), capital(capital), king(king), origin(origin), 
	climate(climate), magic(magic), races(races), beasts(beasts) {}

ostream &operator<<(ostream &os, const State &state) {
	os << "Назавание: " << state.name << ", Описание флага: " << state.flag << ", Столица: " << state.capital 
		<< ", Глава государства: " << state.king << ", Первоисточник: " << state.origin << ", Климат: " << state.climate 
		<< ", Наличие волшебства: " << state.magic << ", Проживающие расы: " << state.races << ", Мифические существа: " << state.beasts 
		<< endl << "---------------";
    return os;
}

void State::writeToFile(ostream &file) {
	file << name << endl << flag << endl << capital << endl << king << endl << origin << endl
		<< climate << endl << magic << endl << races << endl << beasts << endl;
}

void State::readFromFile(istream &file) {
	string name;
	file >> name;
    string flag;
    file >> flag;
    string capital;
    file >> capital;
	string king;
	file >> king;
	string origin;
	file >> origin;
	string climate;
	file >> climate;
	bool magic;
	file >> magic;
	string races;
	file >> races;
	string beasts;
	file >> beasts;

	this->name = name;
    this->flag = flag;
    this->capital = capital;
	this->king = king;
	this->origin = origin;
    this->climate = climate;
	this->magic = magic;
	this->races = races;
	this->beasts = beasts;
}

istream &operator>>(istream &in, State &state) {
	cout << "Название:" << endl;
	string name;
	in >> name;
    cout << "Описание флага:" << endl;
    string flag;
    in >> flag;
    cout << "Столица:" << endl;
    string capital;
    in >> capital;
    cout << "Глава государства:" << endl;
    string king;
    in >> king;
	cout << "Первоисточник:" << endl;
	string origin;
	in >> origin;
	cout << "Климат:" << endl;
	string climate;
	in >> climate;
	cout << "Наличие волшебства (1/0):" << endl;
	bool magic;
	in >> magic;
	cout << "Проживающие расы:" << endl;
	string races;
	in >> races;
	cout << "Мифические существа:" << endl;
	string beasts;
	in >> beasts;

	state.name = name;
    state.flag = flag;
	state.capital = capital;
	state.king = king;
	state.origin = origin;
	state.climate = climate;
	state.magic = magic;
	state.races = races;
	state.beasts = beasts;
    return in;
}

State::State() {}

void State::toConsole() {
    cout << *this;
}
