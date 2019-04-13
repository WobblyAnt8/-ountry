#include <iostream>
#include <fstream>
#include "Country.h"
#include "Middle_earth.h"
#include "Westeros.h"
#include "Narnia.h"
#include "Oz.h"
#include "Atlanta.h"

using namespace std;

Country* Country::country = nullptr;

Country::Country() {
    size = 0;
    states = new State*[size];
}

Country::~Country() {
    size = 0;
    delete []states;
}

std::ostream &operator<<(std::ostream &os, const Country &country) {
    os << "Всего: " << country.size << endl << endl;
    for (int i = 0; i < country.size; ++i) {
        country.states[i]->toConsole();
        cout << endl;
    }
    return os;
}

int Country::getSize() const {
    return size;
}


State **Country::getStates() const {
    return states;
}

Country &Country::add(State &state) {
    this->size++;
    State **copy = new State*[this->size - 1];
    for (int i = 0; i < this->size - 1; ++i) {
        copy[i] = this->states[i];
    }
    this->states = new State*[this->size];
    for (int j = 0; j < this->size - 1; ++j) {
        this->states[j] = copy[j];
    }
    this->states[size - 1] = &state;
    return *this;
}

Country &Country::remove(int index) {
    if (index < 0 || index >= this->size) {
        cout << "Ошибка!" << endl;
    } else {
        int k = 0;
        State **copy = new State*[this->size-1];
        for (int i = 0; i < this->size; ++i) {
            if (i != index) {
                copy[k] = this->states[i];
                k++;
            }
        }
        this->size--;
        this->states = new State*[this->size];
        for (int j = 0; j < this->size; ++j) {
            this->states[j] = copy[j];
        }
    }
    return *this;
}

void Country::writeToFile() {
    const string files[] = {
            "Westeros.txt", "Middle_earth.txt", "Narnia.txt", "Oz.txt", "Atlanta.txt"
    };
    const int length = 5;
    for (int j = 0; j < 5; ++j) {
        ofstream file;
        int count = 0;
        file.open(files[j], ios_base::out);
        for (int i = 0; i < size; ++i) {
            if (states[i]->getFilename() == files[j]) {
                count++;
            }
        }
        file << count << endl;
        for (int i = 0; i < size; ++i) {
            if (states[i]->getFilename() == files[j]) {
                states[i]->writeToFile(file);
                file << "---------------" << endl;
            }
        }
		//file << "---------------" << endl;
        file.close();
    }
}

void Country::readFromFile() {
    const string files[] = {
             "Middle_earth.txt", "Narnia.txt","Westeros.txt", "Oz.txt", "Atlanta.txt"
    };
    for (int j = 0; j < 5; ++j) {
        ifstream is;
        is.open(files[j], ios_base::in);
        int size;
        is >> size;
        for (int i = 0; i < size; ++i) {
           string currentState;
           is >> currentState;
           
           if (currentState == "Middle_earth") {
               Middle_earth *p = new Middle_earth();
               p->readFromFile(is);
               this->add(*p);
           }
           if (currentState == "Westeros") {
               Westeros *sc = new Westeros();
               sc->readFromFile(is);
               this->add(*sc);
           }
           if (currentState == "Narnia") {
               Narnia *gp = new Narnia();
               gp->readFromFile(is);
               this->add(*gp);
           }
		   if (currentState == "Oz") {
			   Oz *zx = new Oz();
			   zx->readFromFile(is);
			   this->add(*zx);
		   }
		   if (currentState == "Atlanta") {
			   Atlanta *qa = new Atlanta();
			   qa->readFromFile(is);
			   this->add(*qa);
		   }
        }
        is.close();
    }
}