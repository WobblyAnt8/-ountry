#ifndef TP_Atlanta_H
#define TP_Atlanta_H

#include "State.h"

class Atlanta : public State {
public:
	void writeToFile(ostream &file) override;
	void readFromFile(istream &file) override;

	string getFilename() override;

	void toConsole() override;

	friend ostream &operator<<(ostream &os, const Atlanta &qa);
	friend istream &operator>>(istream &in, Atlanta &qa);
};

#endif //TP_Atlanta_H