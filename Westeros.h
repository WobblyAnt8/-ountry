#ifndef TP_Westeros_H
#define TP_Westeros_H

#include "State.h"

class Westeros : public State {
public:
	void writeToFile(ostream &file) override;
	void readFromFile(istream &file) override;

	string getFilename() override;

	void toConsole() override;

	friend ostream &operator<<(ostream &os, const Westeros &sc);
	friend istream &operator >> (istream &in, Westeros &sc);
};

#endif //TP_Westeros_H 