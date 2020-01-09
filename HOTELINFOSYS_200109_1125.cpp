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
	string contact_no;
};

struct info_struct {
	int res_id;
	guest guest_info;
	room_type roomtype;
	int adult_num;
	int child_num;
	int infant_num;
	int nights_num;
	struct tm checkin;
	struct tm checkout;
	double base_bill;
};
////////////////////////////////////////////////////////////////

// declaration
int opt; // for int related choices
char choice; // for char related choices
const char full = 'X', empty = 'O';
const int floor = 8;
const int room_per_floor = 10;
char map [room_per_floor][floor];

roomtype room_type_array = {single_room, double_room, family_room, deluxe_room};

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

// reservation
void addReservation();

// checkin checkout
void checkInWithReservation(int xres_no);
void checkInWithoutReservation();
void checkOut();

// rooms

// room service
void viewMenu();
void viewOrder();

// misc
void showMap();
double calculateBaseBill (int no_nights, int no_adults, int no_children);
void getCheckoutDate(struct tm &checkin, int nights_no);
void getToUpper(guest xguest);
void getRates(string roomtype, int rate_arr);
void getInfo(info_struct &info);
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
void addReservation() {
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
	
	info_struct res_info;
	
	getInfo(res_info);
	
	header = ((checkin.tm_year - 2000) * 10000) + ((checkin.tm_mon + 1) * 100) + checkin.tm_mday;
	res_num = (header * 10000) + (rand() % (randMax - randMin) + randMin);
	
	system("cls");
	
	cout << "Reservation ID: " << res_info.res_id << endl;
	cout << "Guest: " << res_info.guest_info.last_name << " " << res_info.guest_info.first_name << " " << res_info.guest_info.middle_name << endl;
	cout << "Contact number: " << res_info.guest_info.contact_no << endl;
	
	cout << "Number of adults: " << res_info.adult_num << endl;
	cout << "Number of children: " << res_info.child_num << endl;
	cout << "Number of infants: " << res_info.infant_num << endl;
	
	cout << "Date of arrival: " << res_info.checkin.tm_mon + 1 << "/" << res_info.checkin.tm_mday << "/" << res_info.checkin.tm_year << endl;
	cout << "Date of departure: " << res_info.checkout.tm_mon + 1 << "/" << res_info.checkout.tm_mday << "/" << res_info.checkout.tm_year << endl;
	cout << "Number of nights: " << res_info.nights_num << endl;
	
	cout << "Base bill: " << res_info.base_bill << endl;
	
	
}

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
	
	info_struct checkin_info;
	
	checkin_info.res_id = 0;
		
	getInfo(checkin_info);
	

	system("cls");
	
	cout << "Reservation ID: " << checkin_info.res_id << endl;
	cout << "Guest: " << checkin_info.guest_info.last_name << " " << checkin_info.guest_info.first_name << " " << checkin_info.guest_info.middle_name << endl;
	cout << "Contact number: " << checkin_info.guest_info.contact_no << endl;
	
	cout << "Number of adults: " << checkin_info.adult_num << endl;
	cout << "Number of children: " << checkin_info.child_num << endl;
	cout << "Number of infants: " << checkin_info.infant_num << endl;
	
	cout << "Date of arrival: " << checkin_info.checkin.tm_mon + 1 << "/" << checkin_info.checkin.tm_mday << "/" << checkin_info.checkin.tm_year << endl;
	cout << "Date of departure: " << checkin_info.checkout.tm_mon + 1 << "/" << checkin_info.checkout.tm_mday << "/" << checkin_info.checkout.tm_year << endl;
	cout << "Number of nights: " << checkin_info.nights_num << endl;
	
	cout << "Base bill: " << checkin_info.base_bill << endl;

	
}
//////////////////////////////////////////////////////////////////
void checkOut() {
	
}
/////////////////////////////////////////////////////////////////
double calculateBaseBill (info_struct &info) {
	int xrate[5];
	double total;
	
	// adults
	total += info.adult_num * info.roomtype.adult_rate * info.nights_num;
	// children
	total += info.child_num * info.roomtype.child_rate * info.nights_num;
	
	// if there is any additional people
	if (info.roomtype.max < info.adult_num + info.child_num) {
		total += info.roomtype.additional;
	}
	
	
	return total;
	 
}
void getCheckoutDate(info_struct &info) {
	switch (info.checkin.tm_mon) {
		//jan, mar, may, july, aug, oct
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9: {
			if ((info.checkin.tm_mday + info.nights_num) > 31) {
				info.checkout.tm_mon = info.checkin.tm_mon + 1;
				info.checkout.tm_mday = (info.checkin.tm_mday + info.nights_num) % 31;
				info.checkout.tm_year = info.checkin.tm_year;
			} else {
				info.checkout.tm_mon = info.checkin.tm_mon;
				info.checkout.tm_mday = info.checkin.tm_mday + info.nights_num;
				info.checkout.tm_year = info.checkin.tm_year;
			}
			break;
		}
			
		//feb, apr, jun, sep, nov
		case 3:
		case 5:
		case 8:
		case 10: {
			if ((info.checkin.tm_mday + info.nights_num) > 30) {
				info.checkout.tm_mon = info.checkin.tm_mon + 1;
				info.checkout.tm_mday = (info.checkin.tm_mday + info.nights_num) % 30;
				info.checkout.tm_year = info.checkin.tm_year;
			} else {
				info.checkout.tm_mon = info.checkin.tm_mon;
				info.checkout.tm_mday = info.checkin.tm_mday + info.nights_num;
				info.checkout.tm_year = info.checkin.tm_year;
			}
			break;
		}
		
		case 1: {
			if ((info.checkin.tm_mday + info.nights_num) > 28) {
				info.checkout.tm_mon = info.checkin.tm_mon + 1;
				info.checkout.tm_mday = (info.checkin.tm_mday + info.nights_num) % 28;
				info.checkout.tm_year = info.checkin.tm_year;
			} else {
				info.checkout.tm_mon = info.checkin.tm_mon;
				info.checkout.tm_mday = info.checkin.tm_mday + info.nights_num;
				info.checkout.tm_year = info.checkin.tm_year;
			}
			break;
		}
		
		case 11: {
			if ((info.checkin.tm_mday + info.nights_num) > 31) {
				info.checkout.tm_mon = 0;
				info.checkout.tm_mday = (info.checkin.tm_mday + info.nights_num) % 31;
				info.checkout.tm_year = info.checkin.tm_year++;
			} else {
				info.checkout.tm_mon = info.checkin.tm_mon;
				info.checkout.tm_mday = info.checkin.tm_mday + info.nights_num;
				info.checkout.tm_year = info.checkin.tm_year;
			}
			break;
		}	
		
	} // end switch
}
////////////////////////////////////////////////////////////////////

void getToUpper(guest xguest) {
//	xguest.last_name = toupper(xguest.last_name);
//	xguest.first_name = toupper(xguest.first_name);
//	xguest.middle_name = toupper(xguest.middle_name);
}
////////////////////////////////////////////////////////////////////
void getInfo(info_struct& info) {
	
	string temp_roomtype;
	
	// guest name
	cin.ignore();
	cout << "Last name: ";
	getline(cin, info.guest_info.last_name);
	cout << "First name: ";
	getline(cin, info.guest_info.first_name);
	cout << "Middle name: ";
	getline(cin, info.guest_info.middle_name);
	cout << "Contact number: ";
	cin >> info.guest_info.contact_no;
	
	cout << info.guest_info.last_name << " " << info.guest_info.first_name << endl;
	
//	getToUpper(xguest);
	
	cout << "Room type: ";
	cin >> temp_roomtype;
	
	if (temp_roomtype == "Single") {
		info.roomtype = single_room;
	} else if (temp_roomtype == "Double") {
		info.roomtype = double_room;
	} else if (temp_roomtype == "Family") {
		info.roomtype = family_room;
	} else if (temp_roomtype == "Deluxe") {
		info.roomtype = deluxe_room;
	}
	
	cout << info.roomtype.name << endl;

	cout << "Number of adults: ";
	cin >> info.adult_num;
	cout << "Number of children: ";
	cin >> info.child_num;
	cout << "Number of infants: ";
	cin >> info.infant_num;
	
	
	// check in date
	// possible to parse this instead
	cout << "Date of Arrival: " << endl;
	cout << "[mm]: ";
	cin >> info.checkin.tm_mon;
	info.checkin.tm_mon--;
	cout << "[dd]: ";
	cin >> info.checkin.tm_mday;
	cout << "[yyyy]:";
	cin >> info.checkin.tm_year;
	
	cout << info.checkin.tm_mon << "/" << info.checkin.tm_mday << "/" << info.checkin.tm_year << endl;
	
	cout << "Number of nights: "; 
	cin >> info.nights_num;
	
	cout << info.nights_num << endl;
	
	getCheckoutDate(info);
	
	cout << info.checkout.tm_mon << "/" << info.checkout.tm_mday << "/" << info.checkout.tm_year << endl;
	
	info.base_bill = calculateBaseBill(info);
	
	cout << info.base_bill;
}
/////////////////////////////////////////////////////////////////////////
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

