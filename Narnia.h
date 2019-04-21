#ifndef TP_Narnia_H
#define TP_Narnia_H

#include "State.h"

class Narnia : public State {
public:
    void writeToFile(ostream &file) override;
    void readFromFile(istream &file) override;

    string getFilename() override;

    void toConsole() override;

    friend ostream &operator<<(ostream &os, const Narnia &gp);
    friend istream &operator>>(istream &in, Narnia &gp);
};

#endif //TP_Narnia_H