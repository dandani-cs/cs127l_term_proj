#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

int res_count = 0;
int i;
int numbers[3];

double calculateBaseBill (string roomtype, int no_nights, int numbers[]);
void getRates(string roomtype, int xrate[]);

struct room_type {
	string name;
	double adult_rate;
	double child_rate;
	double additional;
	int max;
	string info;
} single_room, double_room, family_room, deluxe_room;

struct guest {
	string last_name;
	string first_name;
	string middle_name;
	double contact_no;
};

int main() {
	
	
//	ofstream files;
//	files.open("reservation.csv");


	
	guest checkin_guest;
	string room_type;
	int adult_no, child_no, infant_no, nights_no;
	double expected_bill;
	
	struct tm checkin = {0};
	struct tm checkout = {0};

	single_room.name = "Single";
	single_room.adult_rate = 1000;
	single_room.child_rate = single_room.adult_rate * .5;
	single_room.additional = 500;
	single_room.max = 1;
	single_room.info = "1 single bed";
	
	double_room.name = "Double";
	double_room.adult_rate = 2000;
	double_room.child_rate = double_room.adult_rate * .5;
	double_room.additional = 700;
	double_room.max = 2;
	double_room.info = "2 double beds";
	
	family_room.name = "Family";
	family_room.adult_rate = 3500;
	family_room.child_rate = family_room.adult_rate * .5;
	family_room.additional = 850;
	family_room.max = 4;
	family_room.info = "1 queen bed and 2 single beds";
	
	deluxe_room.name = "Deluxe";
	deluxe_room.adult_rate = 5000;
	deluxe_room.child_rate = deluxe_room.adult_rate * .5;
	deluxe_room.additional = 1000;
	deluxe_room.max = 5;
	deluxe_room.info = "1 king bed and 2 double beds";


	// guest name
	cout << "Last name: ";
	getline(cin, checkin_guest.last_name);
	cout << "First name: ";
	getline(cin, checkin_guest.first_name);
	cout << "Middle name: ";
	getline(cin, checkin_guest.middle_name);
	cout << "Contact number: ";
	cin >> checkin_guest.contact_no;
	
	cout << "Room type: ";
	cin >> room_type;

	cout << "Number of adults: ";
	cin >> numbers[0];
	cout << "Number of children: ";
	cin >> numbers[1];
	cout << "Number of infants: ";
	cin >> numbers[2];
	
	
	// check in date
	// possible to parse this instead
	cout << "Date of Arrival: " << endl;
	cout << "[mm]: ";
	cin >> checkin.tm_mon;
	checkin.tm_mon--;
	cout << "[dd]: ";
	cin >> checkin.tm_mday;
	cout << "[yyyy]:";
	cin >> checkin.tm_year;
	
	cout << "Number of nights: "; 
	cin >> nights_no;
	
	calculateBaseBill(room_type, nights_no, numbers);
	
	
//	checkin.tm_hour = 0; checkin.tm_min = 0; checkin.tm_sec = 0;
//	checkout.tm_hour = 0; checkout.tm_min = 0; checkout.tm_sec = 0;
//	
//	cout << "Date of Departure: " << endl;
//	cout << "[mm]: ";
//	cin >> checkout.tm_mon;
//	checkout.tm_mon--;
//	cout << "[dd]: ";
//	cin >> checkout.tm_mday;
//	cout << "[yyyy]:";
//	cin >> checkout.tm_year;
	
//	time_t checkin_tm = mktime(&checkin);
//	time_t checkout_tm = mktime(&checkout);
//	
//	cout << "Difference of dates: " << difftime(checkout_tm, checkin_tm) << endl;
}

double calculateBaseBill (string roomtype, int no_nights, int numbers[]) {
	int xrate[] = {0};
	double total;
	
	getRates(roomtype, xrate);
	
	for (i = 0; i < 2; i++) {
		total += xrate[i] * numbers[i] * no_nights;
	}
	
	if (xrate[3] < (numbers[0] + numbers[1])) {
		total += xrate[2];
	}
	
	
	return total;
	
	cout << "Total: " << total << endl;
	
	 
}
void getRates(string roomtype, int xrate[]) {
	if (roomtype == "Single") {
		xrate[0] = single_room.adult_rate;
		xrate[1] = single_room.child_rate;
		xrate[2] = single_room.additional;
		xrate[3] = single_room.max;
	} else if (roomtype == "Double") {
		xrate[0] = double_room.adult_rate;
		xrate[1] = double_room.child_rate;
		xrate[2] = double_room.additional;
		xrate[3] = double_room.max;
	} else if (roomtype == "Family") {
		xrate[0] = family_room.adult_rate;
		xrate[1] = family_room.child_rate;
		xrate[2] = family_room.additional;
		xrate[3] = family_room.max;
	} else if (roomtype == "Deluxe") {
		xrate[0] = deluxe_room.adult_rate;
		xrate[1] = deluxe_room.child_rate;
		xrate[2] = deluxe_room.additional;
		xrate[3] = deluxe_room.max;
	}
}
