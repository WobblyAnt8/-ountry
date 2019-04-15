#ifndef TP_Oz_H
#define TP_Oz_H

#include "State.h"

class Oz : public State {
public:
	void writeToFile(ostream &file) override;
	void readFromFile(istream &file) override;

	string getFilename() override;

	void toConsole() override;

	friend ostream &operator<<(ostream &os, const Oz &zx);
	friend istream &operator>>(istream &in, Oz &zx);
};

#endif //TP_Oz_H