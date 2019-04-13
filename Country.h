#ifndef TP_Country_H
#define TP_Country_H

#include <ostream>
#include "State.h"

class Country {
private:
    static Country *country;

    int size;
    State **states;

    Country();
public:

    Country(const Country&) = delete;
    Country& operator=(Country&) = delete;

    Country& add(State &state);
    Country& remove(int index);

    static Country* getInstance() {
        if(!country)
            country = new Country();
        return country;
    }

    int getSize() const;
    State **getStates() const;

    void writeToFile();
    void readFromFile();

    friend std::ostream &operator<<(std::ostream &os, const Country &country);

    ~Country();
};

#endif //TP_Country_H