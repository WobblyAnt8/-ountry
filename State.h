#ifndef TP_State_H
#define TP_State_H

#include <string>
#include <ostream>

using namespace std;

class State {
private:
    
	bool magic;

	string name;
	string flag;
    string capital;
	string king;
	string origin;
	string climate;
	string races;
	string beasts;

public:

    virtual void writeToFile(ostream &file);
    virtual void readFromFile(istream &file);
    virtual string getFilename() = 0;

    State(const string &name, const string &flag, const string &capital, const string &king, const string &origin,
		const string &climate, bool magic, const string &races, const string &beasts);

	virtual ~State();

	const string &getname() const;
	void setname(const string &name);

    const string &getflag() const;
	void setflag(const string &flag);

	const string &getcapital() const;
	void setcapital(const string &capital);

	const string &getking() const;
	void setking(const string &king);

	const string &getorigin() const;
	void setorigin(const string &origin);

	const string &getclimate() const;
	void setclimate(const string &climate);

	bool getmagic() const;
	void setmagic(bool magic);

	const string &getraces() const;
	void setraces(const string &races);

	const string &getbeasts() const;
	void setbeasts(const string &beasts);

    virtual void toConsole();

    friend ostream &operator<<(ostream &os, const State &state);
    friend istream &operator>>(istream &in, State &state);

    State();
};

#endif //TP_State_H