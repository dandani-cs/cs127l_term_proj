#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

// declaration
int opt; // for int related choices
char choice; // for char related choices

void init();
void loginMenu(); // menu for login of different users 
void loginUser();
//void loginAdmin();
void loginAccounting();

void menuUser();
//void menuAdmin();
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

///////////////////////////////////////////////////////////

// structs
struct room_type {
	string name;
	double rate;
	double additional;
	string info;
} single_room, double_room, family_room, deluxe_room;

single_room.name = "Single";
single_room.rate = 1000;
single_room.additional = 500;
single_room.info = "1 single bed";

double_room.name = "Double";
double_room.rate = 2000;
double_room.additional = 700;
double_room.info = "2 double beds";

family_room.name = "Family";
family_room.rate = 3500;
family_room.additional = 700;
family_room.info = "1 queen bed and 2 single beds";

deluxe_room.name = "Deluxe";
deluxe_room.rate = 5000;
deluxe_room.additional = 1000;
deluxe_room.info = "1 king bed and 2 double beds";

/////////////////////////////////////////////////////////////////
// counters
int res_count = 0;

////////////////////////////////////////////////////////////////
int main() 
{
	init();
	loginMenu();
}
//////////////////////////////////////////////////////////////
void init() {
	// check counters
}
/////////////////////////////////////////////////////////////
void loginMenu() {
	
	system("cls");
	
	cout << "[1] User " << endl
//		<< "[2] Admin " << endl
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
//		case 2:
//			loginAdmin();
//			break;
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
//void loginAdmin() {
//	string password;
//	
//	while (password != "TEUWAISEU") {
//		cout << "Enter password: ";
//		try {
//			
//			cin >> password;
//			
//			if (password != "TEUWAISEU") {
//				throw password;
//			} // end if
//		} // end try
//		
//		catch (string x) {
//			cout << "Incorrect password!" << endl;
//			do {
//				cout << "Try again? [Y/N]:";
//				cin >> choice;
//				
//				choice = toupper(choice);
//				
//				if (choice != 'Y' && choice != 'N') {
//					cout << "Invalid input! " << endl;
//				}
//			} while (choice != 'Y' && choice != 'N');
//			
//			if (choice == 'N') {
//				loginMenu();
//				break;
//			}
//			continue;
//		} // end catch
//	} // end while
//	
//	
//}
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
				
				if (res_no == 0) {
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
				
				if (res_no == 0) {
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
	string last_name, first_name, middle_name;
	int arr_month, arr_day, arr_year;
	int dep_month, dep_day, dep_year;
	
	// guest name	
	cout << "Last name: ";
	cin.ignore();
	getline(cin, last_name);
	cout << "First name: ";
	getline(cin, first_name);
	cout << "Middle name: ";
	getline(cin, middle_name);
	
	// check in date
	// possible to parse this instead
	cout << "Month of arrival [mm]: ";
	cin >> arr_month;
	cout << "Day of arrival [dd]: ";
	cin >> arr_day;
	cout << "Year of arrival [yy]:";
	cin >> arr_year;
	
	// check out date
	cout << "Month of departure [mm]: ";
	cin >> dep_month;
	cout << "Day of departure [dd]: ";
	cin >> dep_day;
	cout << "Year of departure [yy]:";
	cin >> dep_year;
	
	
}
//////////////////////////////////////////////////////////////////
void checkOut() {
	
}

