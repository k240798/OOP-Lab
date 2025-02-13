#include <iostream>
#include <string>

using namespace std;

class Date {
public:
	int month;
	int day; 
	int year;

	void diplayDate(int day, int month, int year) {
		this->month = month;
		this->day = day;
		this->year = year;

		cout << this->day << "/" << this->month << "/" << this->year << endl;
	}
};

int main(int argc, char const *argv[])
{
	Date DateTest;
	int day = stoi(*(argv + 1));
	int month = stoi(*(argv + 2));
	int year = stoi(*(argv + 3));

	DateTest.diplayDate(day, month, year);


	return 0;
}