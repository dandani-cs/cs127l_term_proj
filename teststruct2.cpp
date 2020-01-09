#include <iostream>
#include <ctime>
using namespace std;

int main () {
	struct tm time = {0};
	struct tm checkout = {0};
	
	int nights_no;
	
	cout << "Date of Arrival: " << endl;
	cout << "[mm]: ";
	cin >> time.tm_mon;
	time.tm_mon--;
	cout << "[dd]: ";
	cin >> time.tm_mday;
	cout << "[yyyy]:";
	cin >> time.tm_year;
	
	cout << "Number of nights: "; 
	cin >> nights_no;
	
	switch (time.tm_mon) {
		//jan, mar, may, july, aug, oct
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9: {
			if ((time.tm_mday + nights_no) > 31) {
				checkout.tm_mon = time.tm_mon++;
				checkout.tm_mday = (time.tm_mday + nights_no) % 31;
				checkout.tm_year = time.tm_year;
			} else {
				checkout.tm_mon = time.tm_mon;
				checkout.tm_mday = time.tm_mday + nights_no;
				checkout.tm_year = time.tm_year;
			}
			break;
		}
			
		//feb, apr, jun, sep, nov
		case 3:
		case 5:
		case 8:
		case 10: {
			if ((time.tm_mday + nights_no) > 30) {
				checkout.tm_mon = time.tm_mon++;
				checkout.tm_mday = (time.tm_mday + nights_no) % 30;
				checkout.tm_year = time.tm_year;
			} else {
				checkout.tm_mon = time.tm_mon;
				checkout.tm_mday = time.tm_mday + nights_no;
				checkout.tm_year = time.tm_year;
			}
			break;
		}
		case 1: {
			if ((time.tm_mday + nights_no) > 28) {
				checkout.tm_mon = time.tm_mon++;
				checkout.tm_mday = (time.tm_mday + nights_no) % 28;
				checkout.tm_year = time.tm_year;
			} else {
				checkout.tm_mon = time.tm_mon;
				checkout.tm_mday = time.tm_mday + nights_no;
				checkout.tm_year = time.tm_year;
			}
			break;
		}
		
		case 11: {
			if ((time.tm_mday + nights_no) > 31) {
				checkout.tm_mon = 0;
				checkout.tm_mday = (time.tm_mday + nights_no) % 31;
				checkout.tm_year = time.tm_year++;
			} else {
				checkout.tm_mon = time.tm_mon;
				checkout.tm_mday = time.tm_mday + nights_no;
				checkout.tm_year = time.tm_year;
			}
			break;
		}	
		
	} // end switch
	
	cout << "Expected checkout: " << checkout.tm_mon + 1 << "/" << checkout.tm_mday << "/" << checkout.tm_year << endl; 
}
