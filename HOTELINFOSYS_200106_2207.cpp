#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <cctype>
using namespace std;

// structs
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
////////////////////////////////////////////////////////////////

// declaration
int opt; // for int related choices
char choice; // for char related choices

void init();
void loginMenu(); // menu for login of different users 
void loginUser();
void loginAdmin();
void loginAccounting();

void menuUser();
void menuAdmin();
void menuAccounting();

void submenuGuests();
void submenuReservations();
void submenuRooms();
void submenuRoomService();

//void submenuUsers();
//void submenuAdmins();
void submenuRecords();

void checkInWithReservation(int xres_no);
void checkInWithoutReservation();
void checkOut();

// misc
double calculateBaseBill (int no_nights, int no_adults, int no_children);
void getToUpper(guest xguest);
void getRates(string roomtype, int rate_arr);
void getInfo(guest xguest, string *room_type, int numbers[], struct tm time, int *nights_no, double *base_bill);
///////////////////////////////////////////////////////////

// counters
int res_count = 0;
int i;

////////////////////////////////////////////////////////////////
int main() 
{
	init();
	loginMenu();
}
//////////////////////////////////////////////////////////////
void init() {
	// struct assignment
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
	
	// check counters
}
/////////////////////////////////////////////////////////////
void loginMenu() {
	
	system("cls");
	
	cout << "[1] User " << endl
		<< "[2] Admin " << endl
		<< "[3] Accounting " << endl
		<< "[4] Exit " << endl;
		
	do {
		cout << "Log into: ";
	
		cin >> opt;
		
		if (opt < 1 || opt > 4) {
			cout << "Invalid input!" << endl;
		}
	} while (opt < 1 || opt > 4);
	
	switch (opt) {
	
		case 1:
			loginUser();
			break;
		case 2:
			loginAdmin();
			break;
		case 3:
			loginAccounting();
			break;
		case 4:
			exit(0);
	} // end switch
}

///////////////////////////////////////////////////////////////////////////////

void loginUser() {
	// putting in one user for now
	
	system("cls");
	
	string password;
	
	while (password != "RVpsycho") {
		cout << "Enter password: ";
		try {
			
			cin >> password;
			
			if (password != "RVpsycho") {
				throw password;
			} // end if
		} // end try
		
		catch (string x) {
			cout << "Incorrect password!" << endl;
			do {
				cout << "Try again? [Y/N]:";
				cin >> choice;
				
				choice = toupper(choice);
				
				if (choice != 'Y' && choice != 'N') {
					cout << "Invalid input! " << endl;
				}
			} while (choice != 'Y' && choice != 'N');
			
			if (choice == 'N') {
				loginMenu();
				break;
			}
			continue;
		} // end catch
	} // end while
	
	menuUser(); // if password is correct 
} 
////////////////////////////////////////////////////////////////
void loginAdmin() {
	string password;
	
	while (password != "TEUWAISEU") {
		cout << "Enter password: ";
		try {
			
			cin >> password;
			
			if (password != "TEUWAISEU") {
				throw password;
			} // end if
		} // end try
		
		catch (string x) {
			cout << "Incorrect password!" << endl;
			do {
				cout << "Try again? [Y/N]:";
				cin >> choice;
				
				choice = toupper(choice);
				
				if (choice != 'Y' && choice != 'N') {
					cout << "Invalid input! " << endl;
				}
			} while (choice != 'Y' && choice != 'N');
			
			if (choice == 'N') {
				loginMenu();
				break;
			}
			continue;
		} // end catch
	} // end while
	
	
}
///////////////////////////////////////////////////////////////
void loginAccounting() {
	string password;
	
	while (password != "stanG-IDLE") {
		cout << "Enter password: ";
		try {
			
			cin >> password;
			
			if (password != "stanG-IDLE") {
				throw password;
			} // end if
		} // end try
		
		catch (string x) {
			cout << "Incorrect password!" << endl;
			do {
				cout << "Try again? [Y/N]:";
				cin >> choice;
				
				choice = toupper(choice);
				
				if (choice != 'Y' && choice != 'N') {
					cout << "Invalid input! " << endl;
				}
			} while (choice != 'Y' && choice != 'N');
			
			if (choice == 'N') {
				loginMenu();
				break;
			}
			continue;
		} // end catch
	} // end while
	
	menuAccounting();
}
//////////////////////////////////////////////////////////////////
//void menuUser() {
//	cout << "[1] View account details " << endl
//		<< 
//		<< "[2] View reservations " << endl
//}
//////////////////////////////////////////////////////////////////
void menuUser() {
	do {
		int res_id;
		
	
		cout << "[1] Guests" << endl
			<< "[2] Reservations " << endl
			<< "[3] Check-in " << endl
			<< "[4] Check-out " << endl
			<< "[5] Rooms " << endl
			<< "[6] Room Service " << endl
			<< "[7] Log out " << endl;
			
		do {
			cout << "Go to: ";
		
			cin >> opt;
			
			if (opt < 1 || opt > 7) {
				cout << "Invalid input!" << endl;
			}
		} while (opt < 1 || opt > 7);
		
		switch (opt) {
			case 1:
				submenuGuests();
				break;
			case 2:
				submenuReservations();
				break;
			case 3:
				cout << "Reservation number [0 for walk-in]: ";
				cin >> res_id;
				
				if (res_id == 0) {
					checkInWithoutReservation();
				} else {
					checkInWithReservation(res_id);
				}
				break;
			case 4:
				checkOut();
				break;
			case 5:
				submenuRooms();
				break;
			case 6:
				submenuRoomService();
				break;
			case 7:
				loginMenu();
				break;
		} // end switch 
	} while (opt != 7);	
}
//////////////////////////////////////////////////////////////////
//void menuAdmin() {
//	cout << "[1] Users" << endl
//		<< "[2] Admins " << endl
//		<< "[3] Guests" << endl
//		<< "[4] Reservations " << endl
//		<< "[5] Check-in " << endl
//		<< "[6] Check-out " << endl
//		<< "[7] Room Service " << endl
//		<< "[8] Log out " << endl;
//}
//////////////////////////////////////////////////////////////////
void menuAccounting() {
	do {
		int res_id;
	
		cout << "[1] Records " << endl
			<< "[2] Guests" << endl
			<< "[3] Reservations " << endl
			<< "[4] Check-in " << endl
			<< "[5] Check-out " << endl
			<< "[6] Rooms " << endl
			<< "[7] Room Service " << endl
			<< "[8] Log out " << endl;
			
		do {
			cout << "Enter your choice: ";
		
			cin >> opt;
			
			if (opt < 1 || opt > 7) {
				cout << "Invalid input!" << endl;
			}
		} while (opt < 1 || opt > 7);
		
		switch (opt) {
			case 1:
				submenuRecords();
				break;
			case 2:
				submenuGuests();
				break;
			case 3:
				submenuReservations();
				break;
			case 4:
				cout << "Reservation number [0 for walk-in]: ";
				cin >> res_id;
				
				if (res_id == 0) {
					checkInWithoutReservation();
				} else {
					checkInWithReservation(res_id);
				}
				break;
			case 5:
				checkOut();
				break;
			case 6:
				submenuRooms();
				break;
			case 7:
				submenuRoomService();
				break;
			case 8:
				loginMenu();
				break;
		} // end switch 
	} while (opt != 8);
}
//////////////////////////////////////////////////////////////////
void submenuGuests() {
	cout << "[1] View guests" << endl
		<< "[2] Add guest" << endl
		<< "[3] Edit guest info" << endl
		<< "[4] Look up guest " << endl
		<< "[5] Back to main menu " << endl;
		
}
///////////////////////////////////////////////////////////////////
void submenuReservations() {
	cout << "[1] View reservations " << endl
		<< "[2] Add reservation " << endl
		<< "[3] Edit reservation " << endl
		<< "[4] Look up reservation " << endl
		<< "[5] Back to main menu " << endl;
}
//////////////////////////////////////////////////////////////////
void submenuRooms() {
	cout << "[1] View occupied rooms " << endl
		<< "[2] View all rooms" << endl
		<< "[3] Look up by number" << endl
		<< "[4] Check prices" << endl
		<< "[5] Back to main menu" << endl;
}
/////////////////////////////////////////////////////////////////
void submenuRoomService() {
	cout << "[1] View menu " << endl
		<< "[2] Order " << endl
		<< "[3] Back to main menu " << endl;
}
/////////////////////////////////////////////////////////////////

//void submenuUsers();
//void submenuAdmins();
//////////////////////////////////////////////////////////////////
void submenuRecords() {
	cout << "[1] Daily record" << endl
		<< "[2] Weekly record" << endl
		<< "[3] Monthly record " << endl
		<< "[4] Back to main menu" << endl;
}
/////////////////////////////////////////////////////////////////
void checkInWithReservation(int xres_id) {
	
}
/////////////////////////////////////////////////////////////////
void checkInWithoutReservation() {
	guest checkin_guest;
	string roomtype;
	int no_nights;
	int numbers[3];
	double base_bill;
	
	string *roomtype_ptr = &roomtype;
	double *base_bill_ptr = &base_bill;
	int *no_nights_ptr = &no_nights;
	
	struct tm checkin = {0};
//	struct tm checkout = {0};
		
	getInfo(checkin_guest, roomtype_ptr, numbers, checkin, no_nights_ptr, base_bill_ptr);
	

	system("cls");
	
	cout << "Guest: " << checkin_guest.last_name << " " << checkin_guest.first_name << " " << checkin_guest.middle_name << endl;
	cout << "Contact number: " << checkin_guest.contact_no << endl;
	
	cout << "Number of adults: " << numbers[0] << endl;
	cout << "Number of children: " << numbers[1] << endl;
	cout << "Number of infants: " << numbers[2] << endl;
	
	cout << "Date of arrival: " << checkin.tm_mon + 1 << "/" << checkin.tm_mday << "/" << checkin.tm_year << endl;
	cout << "Number of nights: " << no_nights << endl;
	
	cout << "Base bill: " << base_bill << endl;

	
}
//////////////////////////////////////////////////////////////////
void checkOut() {
	
}
/////////////////////////////////////////////////////////////////
double calculateBaseBill (string roomtype, int no_nights, int numbers[]) {
	int xrate[5];
	double total;
	
	
//	getRates(roomtype, xrate);
	
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
//////////////////////////////////////////////////
void getToUpper(guest xguest) {
//	xguest.last_name = toupper(xguest.last_name);
//	xguest.first_name = toupper(xguest.first_name);
//	xguest.middle_name = toupper(xguest.middle_name);
}
////////////////////////////////////////////////////////////////////
void getInfo(guest xguest, string *room_type, int numbers[], struct tm time, int *nights_no, double *base_bill) {
	// guest name
	cin.ignore();
	cout << "Last name: ";
	getline(cin, xguest.last_name);
	cout << "First name: ";
	getline(cin, xguest.first_name);
	cout << "Middle name: ";
	getline(cin, xguest.middle_name);
	cout << "Contact number: ";
	cin >> xguest.contact_no;
	
//	getToUpper(xguest);
	
	cout << "Room type: ";
	cin >> *room_type;

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
	cin >> time.tm_mon;
	time.tm_mon--;
	cout << "[dd]: ";
	cin >> time.tm_mday;
	cout << "[yyyy]:";
	cin >> time.tm_year;
	
	cout << "Number of nights: "; 
	cin >> *nights_no;
	
	*base_bill = calculateBaseBill(*room_type, *nights_no, numbers);
	
	cout << "Last name test: " << xguest.last_name << endl;
}

