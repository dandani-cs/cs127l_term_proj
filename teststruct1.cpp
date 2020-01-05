#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
using namespace std;

int res_count = 0;

struct guest {
	string last_name;
	string first_name;
	string middle_name;
};

int main() {
//	ofstream files;
//	files.open("reservation.csv");
	
	guest checkin_guest;
	
	res_count++;
	
	struct tm checkin = {0};
	struct tm checkout = {0};
	
	string last_name, first_name, middle_name;
	
	// guest name
	// struct this	
	cout << "Last name: ";
	getline(cin, checkin_guest.last_name);
	cout << "First name: ";
	getline(cin, checkin_guest.first_name);
	cout << "Middle name: ";
	getline(cin, checkin_guest.middle_name);
	
	// does not catch error date
	cout << "Month of arrival [mm]: ";
	cin >> checkin.tm_mon;
	checkin.tm_mon--;
	cout << "Day of arrival [dd]: ";
	cin >> checkin.tm_mday;
	cout << "Year of arrival [yy]:";
	cin >> checkin.tm_year;
	
	cout << "Check in details: " << endl;
	
	cout << checkin_guest.last_name << " " << checkin_guest.first_name << " " << checkin_guest.middle_name << endl;
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
