#ifndef TP_Middle_earth_H
#define TP_Middle_earth_H

#include "State.h"

class Middle_earth : public State {
public:
	void writeToFile(ostream &file) override;
	void readFromFile(istream &file) override;

	string getFilename() override;

	void toConsole() override;

	friend ostream &operator<<(ostream &os, const Middle_earth &p);
	friend istream &operator >> (istream &in, Middle_earth &p);
};

#endif //TP_Middle_earth_H