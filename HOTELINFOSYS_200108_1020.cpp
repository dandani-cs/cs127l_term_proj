#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cstdlib>
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
const char full = 'X', empty = 'O';
const int floor = 8;
const int room_per_floor = 10;
char map [room_per_floor][floor];

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

// reservation
void addReservation();

// room service
void viewMenu();
void viewOrder();

// misc
void showMap();
double calculateBaseBill (int no_nights, int no_adults, int no_children);
void getCheckoutDate(struct tm &checkin, int nights_no);
void getToUpper(guest xguest);
void getRates(string roomtype, int rate_arr);
void getInfo(guest &xguest, string *room_type, int numbers[], struct tm &time, struct tm &checkout, int *nights_no, double *base_bill);
///////////////////////////////////////////////////////////

// counters
int res_count = 0;
int occupied_rooms = 0;
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
void menuAdmin() {
	cout << "[1] Users" << endl
		<< "[2] Admins " << endl
		<< "[3] Guests" << endl
		<< "[4] Reservations " << endl
		<< "[5] Check-in " << endl
		<< "[6] Check-out " << endl
		<< "[7] Room Service " << endl
		<< "[8] Log out " << endl;
}
//////////////////////////////////////////////////////////////////
void menuAccounting() {
	do {
		int res_id;
		bool valid;
	
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
	system("cls");
	cout << "[1] View reservations " << endl
		<< "[2] Add reservation " << endl
		<< "[3] Edit reservation " << endl
		<< "[4] Look up reservation " << endl
		<< "[5] Back to main menu " << endl;
		
	cin >> opt;
	
	switch (opt) {
		case 2:
			addReservation();
	}
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
	system("cls");
	cout<< "[1] View menu " << endl
		<< "[2] Order " << endl
		<< "[3] Back to main menu "<<endl
		<< "Enter your option: ";
	cin>>opt; 
	
	switch(opt){
		case 1:
			viewMenu();
			break;
		case 2:
			viewOrder();
			break;
		case 3:
			break;
	}
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
	int no_nights, res_id;
	int numbers[3];
	double base_bill;
	
	string *roomtype_ptr = &roomtype;
	double *base_bill_ptr = &base_bill;
	int *no_nights_ptr = &no_nights;
	
	struct tm checkin = {0};
	struct tm checkout = {0};
		
	getInfo(checkin_guest, roomtype_ptr, numbers, checkin, checkout, no_nights_ptr, base_bill_ptr);
	

	system("cls");
	
	res_id = 0;
	cout << "Reservation ID: " << res_id << endl;
	cout << "Guest: " << checkin_guest.last_name << " " << checkin_guest.first_name << " " << checkin_guest.middle_name << endl;
	cout << "Contact number: " << checkin_guest.contact_no << endl;
	
	cout << "Number of adults: " << numbers[0] << endl;
	cout << "Number of children: " << numbers[1] << endl;
	cout << "Number of infants: " << numbers[2] << endl;
	
	cout << "Date of arrival: " << checkin.tm_mon + 1 << "/" << checkin.tm_mday << "/" << checkin.tm_year << endl;
	cout << "Date of departure: " << checkout.tm_mon + 1 << "/" << checkout.tm_mday << "/" << checkout.tm_year << endl;
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
void getCheckoutDate(struct tm &checkin, struct tm &checkout, int nights_no) {
	switch (checkin.tm_mon) {
		//jan, mar, may, july, aug, oct
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9: {
			if ((checkin.tm_mday + nights_no) > 31) {
				checkout.tm_mon = checkin.tm_mon + 1;
				checkout.tm_mday = (checkin.tm_mday + nights_no) % 31;
				checkout.tm_year = checkin.tm_year;
			} else {
				checkout.tm_mon = checkin.tm_mon;
				checkout.tm_mday = checkin.tm_mday + nights_no;
				checkout.tm_year = checkin.tm_year;
			}
			break;
		}
			
		//feb, apr, jun, sep, nov
		case 3:
		case 5:
		case 8:
		case 10: {
			if ((checkin.tm_mday + nights_no) > 30) {
				checkout.tm_mon = checkin.tm_mon + 1;
				checkout.tm_mday = (checkin.tm_mday + nights_no) % 30;
				checkout.tm_year = checkin.tm_year;
			} else {
				checkout.tm_mon = checkin.tm_mon;
				checkout.tm_mday = checkin.tm_mday + nights_no;
				checkout.tm_year = checkin.tm_year;
			}
			break;
		}
		
		case 1: {
			if ((checkin.tm_mday + nights_no) > 28) {
				checkout.tm_mon = checkin.tm_mon + 1;
				checkout.tm_mday = (checkin.tm_mday + nights_no) % 28;
				checkout.tm_year = checkin.tm_year;
			} else {
				checkout.tm_mon = checkin.tm_mon;
				checkout.tm_mday = checkin.tm_mday + nights_no;
				checkout.tm_year = checkin.tm_year;
			}
			break;
		}
		
		case 11: {
			if ((checkin.tm_mday + nights_no) > 31) {
				checkout.tm_mon = 0;
				checkout.tm_mday = (checkin.tm_mday + nights_no) % 31;
				checkout.tm_year = checkin.tm_year++;
			} else {
				checkout.tm_mon = checkin.tm_mon;
				checkout.tm_mday = checkin.tm_mday + nights_no;
				checkout.tm_year = checkin.tm_year;
			}
			break;
		}	
		
	} // end switch
}
////////////////////////////////////////////////////////////////////
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
void getInfo(guest &xguest, string *room_type, int numbers[], struct tm &time, struct tm &checkout, int *nights_no, double *base_bill) {
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
	
	getCheckoutDate(time, checkout, *nights_no);
	
	*base_bill = calculateBaseBill(*room_type, *nights_no, numbers);
}

void addReservation () {
	guest res_guest;
	string roomtype;
	int no_nights, res_id, header, res_num;
	int randMax = 300000, randMin = 200000;
	int numbers[3];
	double base_bill;
	
	
	string *roomtype_ptr = &roomtype;
	double *base_bill_ptr = &base_bill;
	int *no_nights_ptr = &no_nights;
	
	struct tm checkin = {0};
	struct tm checkout = {0};
	
	getInfo(res_guest, roomtype_ptr, numbers, checkin, checkout, no_nights_ptr, base_bill_ptr);
	
	header = ((checkin.tm_year - 2000) * 10000) + ((checkin.tm_mon + 1) * 100) + checkin.tm_mday;
	res_num = (header * 10000) + (rand() % (randMax - randMin) + randMin);
	
	system("cls");
	
	cout << "Reservation number: " << res_num << endl;
	cout << "Guest: " << res_guest.last_name << " " << res_guest.first_name << " " << res_guest.middle_name << endl;
	cout << "Room type: " << roomtype << endl;
	cout << "Number of adults: " << numbers[0] << endl;
	cout << "Number of children: " << numbers[1] << endl;
	cout << "Number of infants: " << numbers[2] << endl;
	cout << "Date of arrival: " << checkin.tm_mon + 1 << "/" << checkin.tm_mday << "/" << checkin.tm_year << endl;
	cout << "Date of departure: " << checkout.tm_mon + 1 << "/" << checkout.tm_mday << "/" << checkout.tm_year << endl;
	cout << "Number of nights: " << no_nights << endl;
	cout << "Base bill: " << base_bill << endl;
	
	
}
void viewMenu() {
	do{
		system("cls");
		do{	
		
		cout<<"======ROOM SERVICE MENU======\n"
			<<"[1]Breakfast\n"
			<<"[2]Appetizer\n"
			<<"[3]Pasta\n"
			<<"[4]Salad\n"
			<<"[5]Soup\n"
			<<"[6]Pizza\n"
			<<"[7]Snacks\n"
			<<"[8]Meals\n"
			<<"[9]Desserts\n"
			<<"[10]Drinks\n"
			<<"[11]Back\n"
			<<"Enter your option: ";		
		cin>>opt;
		
		if (opt<1||opt>11){
			system("cls");
			cout<<"Invalid Choice!\n";
			}//end if
		
		}while(opt<1||opt>11);
		
		switch(opt){
			
			case 1:
				system("cls");
				cout<<"======Breakfast======\n"
					<<"[1]Pancakes\n"
					<<"[2]Sausage and Eggs\n"
					<<"[3]French Toast\n"
					<<"[4]Waffles\n"
					<<"[5]Continental Breakfast\n"
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();	
				break;
			case 2:
				system("cls");
				cout<<"======Appetizer=======\n"
					<<"[1]Fish and Chips\n"
					<<"[2]Dynamite\n"
					<<"[3]Cheese Platter\n"
					<<"[4]Caesar Salad\n"
					<<"[5]Greek Salad\n"
					<<"[6]Garlic Bread\n"
					<<"[7]Cheese and Crackers\n"
					<<"[8]Calamari\n"
					<<"[9]Onion rings\n"
					<<"[10]Mini tacos\n"
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();
				break;
			case 3:{
				system("cls");
				cout<<"=======Salad======\n"
					<<"[1]Caesar Salad\n"
					<<"[2]Greek Salad\n"
					<<"[3]Potato Salad\n"
					<<"[4]Crab Louis\n"
					<<"[5]Chef's Salad\n"
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();
				break;
			}
			
			case 4:{
				system("cls");
				cout<<"======Soup======\n"
					<<"[1]Mushroom Soup\n"
					<<"[2]Pumpkin Soup\n"
					<<"[3]Carrot Soup\n"
					<<"[4]Chikcen Soup\n"
					<<"[5]Porridge\n"
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();
				break;
			}
				
			case 5:
				system("cls");
				cout<<"======Pasta=======\n"
					<<"[1]Carbonara\n"
					<<"[2]Puttanesca\n"
					<<"[3]Aglio e olio\n"
					<<"[4]Lasagna\n"
					<<"[5]Chicken Pesto\n"				
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();
				break;
			case 6:
				system("cls");
				cout<<"=====Pizza=====\n"
					<<"[1]Hawaiian\n"
					<<"[2]Pepperoni\n"
					<<"[3]Vegetarion\n"
					<<"[4]Four Cheese\n"
					<<"[5]All Meat\n"
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();
				break;
			
			case 7:{
				system("cls");
				cout<<"======Snacks======\n"
					<<"[1]Nachos\n"
					<<"[2]French Fries\n"
					<<"[3]Clubhouse Sandwich\n"
					<<"[4]Mini Burger\n"
					<<"[5]Fish and Chips\n"
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();
				break;
			}
			case 8: 
				system("cls");
				cout<<"======Meals=====\n"
					<<"[1]Grilled Porkchop\n"
					<<"[2]Herb Chicken\n"
					<<"[3]Turkey\n"
					<<"[4]Grilled Lamb\n"
					<<"[5]Grilled Salmon\n"
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();
				break;
			case 9:
				system("cls");
				cout<<"=======Desserts=======\n"
					<<"[1]Ice Cream (Vanilla, Chocolate, Strawbbery)\n"
					<<"[2]Sliced Cake\n"
					<<"[3]Whole Cake\n"
					<<"[4]Banana Split\n"
					<<"[5]Halo-Halo\n"
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();
				break;
			case 10:
				system("cls");
				cout<<"======Drinks=======\n"
					<<"[1]Fruit Juice\n"
					<<"[2]Fruit Shake\n"
					<<"[3]Wine\n"
					<<"[4]Beer\n"
					<<"[5]Coffee\n"
					<<"[6]Shakes\n"
					<<"\npress enter to go back......\n";
				cin.get();
				cin.ignore();
				break;
			case 11:
				break;
		}//end switch
	}while(opt!=11);
}//end function
/////////////////////////////////////////////////////////////////////////
void viewOrder(){
	
}

//////////////////////////////////////////////////////////
void showMap() {
		for (int i = 0; i < floor + 1; i++)
	{
		for (int j = 0; j < room_per_floor; j++)
			map[i][j] = empty;
	}

	cout << endl << "  O = VACANT   X = TAKEN" << endl << endl;
	cout << "    A   B   C   D   E   F   G   H   I   J";
	for (int i = 1; i < floor + 1; i++)
	{
		cout << endl << endl << i;
		for (int j = 0; j < room_per_floor; j++)
			cout << setw(3) << " " << map[i][j];
	}
}
////////////////////////////////////////////////////////////////////////////

