#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Country.h"
#include "Westeros.h"
#include "Middle_earth.h"
#include "Narnia.h"
#include "Oz.h"
#include "Atlanta.h"

using namespace std;

const string FILENAME = "text.txt";

void printMenu() {
    cout << "0 - Выход" << endl;
    cout << "1 - Добавить страну" << endl;
    cout << "2 - Удалить страну" << endl;
    cout << "3 - Записать в файл" << endl;
    cout << "4 - Прочитать из файла" << endl;
    cout << "5 - Вывод стран на экран" << endl;
}

int main() {

    setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Country *perephery = Country::getInstance();

    bool isRunning = true;
    int mode;
    while (isRunning) {
        printMenu();
        cin >> mode;
        switch(mode) {
            case 0:
                isRunning = false;
                break;
            case 1:
                cout << "Выберите страну добавления:" << endl;
                cout << "1 - Средиземье, 2 - Нарния, 3 - Вестерос, 4 - Страна Оз, 5 - Атлантида" << endl;
                int selected;
                cin >> selected;
                if (selected == 1) {
                    Middle_earth *p = new Middle_earth();
                    cin >> *p;
                    Country::getInstance()->add(*p);
                }
				if (selected == 2) {
                    Narnia *gp = new Narnia();
                    cin >> *gp;
                    Country::getInstance()->add(*gp);
                }
                if (selected == 3) {
                    Westeros *sc = new Westeros();
                    cin >> *sc;
                    Country::getInstance()->add(*sc);
                }
				if (selected == 4) {
					Oz *zx = new Oz();
					cin >> *zx;
					Country::getInstance()->add(*zx);
				}
				if (selected == 5) {
					Atlanta *qa = new Atlanta();
					cin >> *qa;
					Country::getInstance()->add(*qa);
				}
                break;
            case 2:
                cout << "Введите индекс удаляемой страны:" << endl;
                int removed;
                cin >> removed;
                Country::getInstance()->remove(removed-1);
                break;
            case 3:
                try {
                    Country::getInstance()->writeToFile();
                } catch (exception e) {
                    cout << "Не удается записать в файл" << e.what();
                }
                break;
            case 4:
                try {
                    Country::getInstance()->readFromFile();
                } catch (exception e) {
                    cout << "Не удается прочитать файл" << e.what();
                }
                break;
            case 5:
                cout << *Country::getInstance();
                break;
        }
    }
    return 0;
} 