#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
using namespace std;

int res_count = 0;

int main() {
//	ofstream files;
//	files.open("reservation.csv");
	
	res_count++;
	
	struct tm checkin = {0};
	struct tm checkout = {0};
	
	string last_name, first_name, middle_name;
	
	// guest name
	// struct this	
	cout << "Last name: ";
	cin.ignore();
	getline(cin, last_name);
	cout << "First name: ";
	getline(cin, first_name);
	cout << "Middle name: ";
	getline(cin, middle_name);
	
	
	cout << "Month of arrival [mm]: ";
	cin >> checkin.tm_mon;
	checkin.tm_mon--;
	cout << "Day of arrival [dd]: ";
	cin >> checkin.tm_mday;
	cout << "Year of arrival [yy]:";
	cin >> checkin.tm_year;
	
	cout << checkin.tm_mon << "/" << checkin.tm_mday << "/" << checkin.tm_year << endl;
	
//	// check in date
//	// possible to parse this instead
//	cout << "Month of arrival [mm]: ";
//	cin >> arr_month;
//	cout << "Day of arrival [dd]: ";
//	cin >> arr_day;
//	cout << "Year of arrival [yy]:";
//	cin >> arr_year;
//	
//	// check out date
//	cout << "Month of departure [mm]: ";
//	cin >> dep_month;
//	cout << "Day of departure [dd]: ";
//	cin >> dep_day;
//	cout << "Year of departure [yy]:";
//	cin >> dep_year;
	
//	files << res_count << last_name << first_name << middle_name 
}
