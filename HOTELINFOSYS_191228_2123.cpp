#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

// declaration
int opt; // for int related choices
char choice; // for char related choices

void loginMenu(); // menu for login of different users 
void loginUser();
void loginAdmin();
void loginAccounting();

void menuUser();
void menuAdmin();
void menuAccounting();

int main() 
{
	loginMenu();
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
}
//////////////////////////////////////////////////////////////////
void menuUser() {
	cout << "[1] Guests" << endl
		<< "[2] Reservations " << endl
		<< "[3] Check-in " << endl
		<< "[4] Check-out " << endl
		<< "[5] Room Service " << endl
		<< "[6] Log out " << endl;
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
