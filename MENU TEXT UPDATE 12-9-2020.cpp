#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <cctype>
#include<conio.h>
#include<windows.h>
#include<algorithm>
#include<cstdlib>
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
int ctr;

void init();
void loginMenu(); // menu for login of different users 
void loginUser();
void loginAdmin();
void loginAccounting();
string EnterPassword();

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
void showRooms();
void checkPrices();
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
  single_room.name = "SINGLE";
  single_room.adult_rate = 1000;
  single_room.child_rate = single_room.adult_rate * .5;
  single_room.additional = 500;
  single_room.max = 1;
  single_room.info = "1 SINGLE BED";
  
  double_room.name = "DOUBLE";
  double_room.adult_rate = 2000;
  double_room.child_rate = double_room.adult_rate * .5;
  double_room.additional = 700;
  double_room.max = 2;
  double_room.info = "2 DOUBLE BEDS";
  
  family_room.name = "FAMILY";
  family_room.adult_rate = 3500;
  family_room.child_rate = family_room.adult_rate * .5;
  family_room.additional = 850;
  family_room.max = 4;
  family_room.info = "1 QUEEN BED AND 2 SINGLE BEDS";
  
  deluxe_room.name = "DELUXE";
  deluxe_room.adult_rate = 5000;
  deluxe_room.child_rate = deluxe_room.adult_rate * .5;
  deluxe_room.additional = 1000;
  deluxe_room.max = 5;
  deluxe_room.info = "1 KING BED AND 2 DOUBLE BEDS";
  
  // check counters
}
/////////////////////////////////////////////////////////////
void loginMenu() {
  
  
  ctr=0;
  cout << "== == == == == == == == == == == == == ==" << endl
  	   << "       H O T E L   D E L   L U N A       " << endl
  	   << "== == == == == == == == == == == == == ==" << endl
       << "[1] U S E R " << endl
       << "[2] A D M I N " << endl
       << "[3] A C C O U N T I N G " << endl
       << "[4] E X I T " << endl
       << "== == == == == == == == == == == == == ==" << endl;
  do {
    cout << "LOG INTO: ";
  
    cin >> opt;
    
    if (opt < 1 || opt > 4) {
      cout << "INVALID CHOICE!" << endl;
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
    cout << "ENTER PASSWORD: ";
    try {
      
      password=EnterPassword();
      
      if (password != "RVpsycho") {
        throw password;
      } // end if
    } // end try
    
    catch (string x) {
      cout << "\nINCORRECT PASSWORD!" << endl;
      ctr++;
    
    if (ctr >= 3)
    {
      system("cls");  
      cout<<"MAXIMUM ATTEMPTS REACHED!"<<endl;
      loginMenu();
    } 
    
      do {
        cout << "TRY AGAIN? [Y/N]:";
        cin >> choice;
        
        choice = toupper(choice);
        
        if (choice != 'Y' && choice != 'N') {
          cout << "INVALID INPUT! " << endl;
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
    cout << "ENTER PASSWORD: ";
    try {
      
      password = EnterPassword();
      
      if (password != "TEUWAISEU") {
        throw password;
      } // end if
    } // end try
    
    catch (string x) {
     cout << "\nINCORRECT PASSWORD!" << endl;
      ctr++;
    
    if (ctr >= 3)
    {
      system("cls");
      cout<<"MAXIMUM ATTEMPTS REACHED!"<<endl;
      loginMenu();
    } 
      do {
        cout << "TRY AGAIN? [Y/N]:";
        cin >> choice;
        
        choice = toupper(choice);
        
        if (choice != 'Y' && choice != 'N') {
          cout << "INVALID INPUT! " << endl;
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
  
  system("cls");
  
  string password;
  
  while (password != "stanG-IDLE") {
    cout << "ENTER PASSWORD: ";
    try {
      
      password = EnterPassword();
      
      if (password != "stanG-IDLE") {
        throw password;
      } // end if
    } // end try
    
    catch (string x) {
      cout << "\nINCORRECT PASSWORD!" << endl;
      ctr++;
    
    if (ctr >= 3)
    {
      system("cls");
      cout<<"MAXIMUM ATTEMPTS REACHED!"<<endl;
      loginMenu();
    } 
      do {
        cout << "TRY AGAIN? [Y/N]:";
        cin >> choice;
        
        choice = toupper(choice);
        
        if (choice != 'Y' && choice != 'N') {
          cout << "INVALID INPUT! " << endl;
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
//  cout << "[1] View account details " << endl
//    << 
//    << "[2] View reservations " << endl
//}
//////////////////////////////////////////////////////////////////
void menuUser() {
  do {
    int res_id;
    
    system("cls");
    cout << "== == == == == == == == == == == == == ==" << endl
  	     << "       H O T E L   D E L   L U N A       " << endl << endl
  	     << "    L O G G E D   I N   A S   U S E R    " << endl
  	     << "== == == == == == == == == == == == == ==" << endl
         << "[1] R E S E R V A T I O N S" << endl
         << "[2] C H E C K   I N" << endl
         << "[3] C H E C K   O U T" << endl
         << "[4] R O O M S" << endl
         << "[5] R O O M   S E R V I C E" << endl
         << "[6] L O G   O U T" << endl
         << "== == == == == == == == == == == == == ==" << endl;
    do {
      cout << "GO TO: ";
    
      cin >> opt;
      
      if (opt < 1 || opt > 7) {
        cout << "INVALID CHOICE!" << endl;
      }
    } while (opt < 1 || opt > 7);
    
    switch (opt) {
      case 1:
        submenuReservations();
        break;
      case 2:
        cout << "RESERVATION NUMBER [0 FOR WALK-IN]: ";
        cin >> res_id;
        
        if (res_id == 0) {
          checkInWithoutReservation();
        } else {
          checkInWithReservation(res_id);
        }
        break;
      case 3:
        checkOut();
        break;
      case 4:
        submenuRooms();
        break;
      case 5:
        submenuRoomService();
        break;
      case 6:
        system("cls");
        loginMenu();
        break;
    } // end switch 
  } while (opt < 1 || opt > 7);  
}
//////////////////////////////////////////////////////////////////
//void menuAdmin() {
//  cout << "[1] Admins" << endl
//       << "[2] Reservations " << endl
//       << "[3] Check-in " << endl
//       << "[4] Check-out " << endl
//       << "[5] Room Service " << endl
//       << "[6] Log out " << endl;
//}
//////////////////////////////////////////////////////////////////
void menuAccounting() {
  do {
    int res_id;
  
    system("cls");
    cout << "== == == == == == == == == == == == == == == == == ==" << endl
  	  	 << "             H O T E L   D E L   L U N A             " << endl << endl
  	  	 << "    L O G G E D   I N   A S   A C C O U N T A N T    " << endl
  	  	 << "== == == == == == == == == == == == == == == == == ==" << endl
      	 << "[1] R E C O R D S" << endl
      	 << "[2] G U E S T S" << endl
      	 << "[3] R E S E R V A T I O N S" << endl
      	 << "[4] C H E C K   I N" << endl
      	 << "[5] C H E C K   O U T" << endl
      	 << "[6] R O O M S" << endl
      	 << "[7] R O O M   S E R V I C E" << endl
      	 << "[8] L O G   O U T" << endl
      	 << "== == == == == == == == == == == == == == == == == ==" << endl;
    do {
      cout << "ENTER YOUR CHOICE: ";
    
      cin >> opt;
      
      if (opt < 1 || opt > 7) {
        cout << "INVALID CHOICE!" << endl;
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
        cout << "RESERVATION NUMBER [0 FOR WALK-IN]: ";
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
        system("cls");
        loginMenu();
        break;
    } // end switch 
  } while (opt != 8);
}
//////////////////////////////////////////////////////////////////
void submenuGuests() {
  cout << "[1] V I E W   G U E S T S" << endl
       << "[2] A D D   G U E S T" << endl
       << "[3] E D I T   G U E S T   I N F O" << endl
       << "[4] L O O K   U P   G U E S T" << endl
       << "[5] B A C K   T O   M A I N   M E N U" << endl;
    
}
///////////////////////////////////////////////////////////////////
void submenuReservations() {
  cout << "[1] V I E W   R E S E R V A T I O N S" << endl
       << "[2] A D D   R E S E R V A T I O N" << endl
       << "[3] E D I T   R E S E R V A T I O N" << endl
       << "[4] L O O K   U P   R E S E R V A T I O N" << endl
       << "[5] B A C K   T O   M A I N   M E N U" << endl;
}
//////////////////////////////////////////////////////////////////
void submenuRooms() {
   do {
     system("cls");
  cout << "[1] V I E W   O C C U P I E D   R O O M S" << endl
       << "[2] V I E W   A L L   R O O M S" << endl
       << "[3] L O O K   U P   B Y   N U M B E R" << endl
       << "[4] C H E C K   P R I C E S" << endl
       << "[5] B A C K   T O   M A I N   M E N U" << endl;
    do {
      cout << "ENTER YOUR CHOICE: ";
    
      cin >> opt;
      
      if (opt < 1 || opt > 5) {
        cout << "INVALID CHOICE!" << endl;
      }
    } while (opt < 1 || opt > 5);
    
    switch (opt) 
  {
      case 1:{
    break;
    }
      case 2:{
        showRooms();
        system("pause");
        submenuRooms();
    break;
    }
      case 3:{
    break;
    }
      case 4:{
        checkPrices();
        system("pause");
        submenuRooms();
    break;
    }
      case 5:{
        system("cls");
        menuUser();
    break;
    }
    } // end switch 
  } while (opt < 1 || opt > 5);
}
/////////////////////////////////////////////////////////////////
void submenuRoomService() {
  cout << "[1] V I E W   M E N U" << endl
       << "[2] O R D E R" << endl
       << "[3] B A C K   T O   M A I N   M E N U" << endl;
}
/////////////////////////////////////////////////////////////////
//void submenuUsers();
//void submenuAdmins();
//////////////////////////////////////////////////////////////////
void submenuRecords() {
  cout << "[1] D A I L Y   R E C O R D" << endl
       << "[2] W E E K L Y   R E C O R D" << endl
       << "[3] M O N T H L Y   R E C O R D" << endl
       << "[4] B A C K   T O   M A I N   M E N U" << endl;
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
//  struct tm checkout = {0};
    
  getInfo(checkin_guest, roomtype_ptr, numbers, checkin, no_nights_ptr, base_bill_ptr);
  

  system("cls");
  
  cout << "GUEST: " << checkin_guest.last_name << " " << checkin_guest.first_name << " " << checkin_guest.middle_name << endl;
  cout << "CONTACT NUMBER: " << checkin_guest.contact_no << endl;
  
  cout << "NUMBER OF ADULTS: " << numbers[0] << endl;
  cout << "NUMBER OF CHILDREN: " << numbers[1] << endl;
  cout << "NUMBER OF INFANTS: " << numbers[2] << endl;
  
  cout << "DATE OF ARRIVAL: " << checkin.tm_mon + 1 << "/" << checkin.tm_mday << "/" << checkin.tm_year << endl;
  cout << "NUMBER OF NIGHTS: " << no_nights << endl;
  
  cout << "BASE BILL: " << base_bill << endl;

  
}
//////////////////////////////////////////////////////////////////
void checkOut() {
  
}
/////////////////////////////////////////////////////////////////
double calculateBaseBill (string roomtype, int no_nights, int numbers[]) {
  int xrate[5];
  double total;
  
  
//  getRates(roomtype, xrate);
  
  if (roomtype == "SINGLE") {
    xrate[0] = single_room.adult_rate;
    xrate[1] = single_room.child_rate;
    xrate[2] = single_room.additional;
    xrate[3] = single_room.max;
  } else if (roomtype == "DOUBLE") {
    xrate[0] = double_room.adult_rate;
    xrate[1] = double_room.child_rate;
    xrate[2] = double_room.additional;
    xrate[3] = double_room.max;
  } else if (roomtype == "FAMILY") {
    xrate[0] = family_room.adult_rate;
    xrate[1] = family_room.child_rate;
    xrate[2] = family_room.additional;
    xrate[3] = family_room.max;
  } else if (roomtype == "DELUXE") {
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
  
  cout << "TOTAL: " << total << endl;
  
   
}
void getRates(string roomtype, int xrate[]) {
  if (roomtype == "SINGLE") {
    xrate[0] = single_room.adult_rate;
    xrate[1] = single_room.child_rate;
    xrate[2] = single_room.additional;
    xrate[3] = single_room.max;
  } else if (roomtype == "DOUBLE") {
    xrate[0] = double_room.adult_rate;
    xrate[1] = double_room.child_rate;
    xrate[2] = double_room.additional;
    xrate[3] = double_room.max;
  } else if (roomtype == "FAMILY") {
    xrate[0] = family_room.adult_rate;
    xrate[1] = family_room.child_rate;
    xrate[2] = family_room.additional;
    xrate[3] = family_room.max;
  } else if (roomtype == "DELUXE") {
    xrate[0] = deluxe_room.adult_rate;
    xrate[1] = deluxe_room.child_rate;
    xrate[2] = deluxe_room.additional;
    xrate[3] = deluxe_room.max;
  }
}
//////////////////////////////////////////////////
void getToUpper(guest xguest) {
//  xguest.last_name = toupper(xguest.last_name);
//  xguest.first_name = toupper(xguest.first_name);
//  xguest.middle_name = toupper(xguest.middle_name);
}
////////////////////////////////////////////////////////////////////
void getInfo(guest xguest, string *room_type, int numbers[], struct tm time, int *nights_no, double *base_bill) {
  // guest name
  cin.ignore();
  cout << "LAST NAME: ";
  getline(cin, xguest.last_name);
  cout << "FIRST NAME: ";
  getline(cin, xguest.first_name);
  cout << "MIDDLE NAME: ";
  getline(cin, xguest.middle_name);
  cout << "CONTACT NUMBER: ";
  cin >> xguest.contact_no;
  
//  getToUpper(xguest);
  
  cout << "ROOM TYPE: ";
  cin >> *room_type;

  cout << "NUMBER OF ADULTS: ";
  cin >> numbers[0];
  cout << "NUMBER OF CHILDREN: ";
  cin >> numbers[1];
  cout << "NUMBER OF INFANTS: ";
  cin >> numbers[2];
  
  
  // check in date
  // possible to parse this instead
  cout << "DATE OF ARRIVAL: " << endl;
  cout << "[MM]: ";
  cin >> time.tm_mon;
  time.tm_mon--;
  cout << "[DD]: ";
  cin >> time.tm_mday;
  cout << "[YYYY]:";
  cin >> time.tm_year;
  
  cout << "NUMBER OF NIGHTS: "; 
  cin >> *nights_no;
  
  *base_bill = calculateBaseBill(*room_type, *nights_no, numbers);
  
  cout << "LAST NAME TEST: " << xguest.last_name << endl;
}
////////////////////////////////////////////////////////
string EnterPassword(){
  //add code here
  string password="";
  char ch;
  
  while (true)
  {
    ch=getch();
    
    if(ch == '\b') 
      {        
      if(password.size() > 0)
        {
            password.erase(password.begin() + password.size() - 1); 
            cout<<"\b \b";
      }
    }
    
    else if(ch != '\n' && ch != '\r') 
    {
      cout<<'*';
      password = password + ch;
    }
    
    else 
          break;
  }
  //return password;
  return password;
}
///////////////////////////////////////////////////////////

void showRooms(){
  
  

void checkPrices();
  const char full = 'X', empty = 'O';
  const int floor = 8;
  const int room = 10;
  char map [room][floor];
  
  system("cls");

  for (int i = 0; i < floor + 1; i++)
  {
    for (int j = 0; j < room; j++)
      map [i][j] = empty;
  }//THIS IS USED TO CLEAR ROOMS (INITIALIZER)
  
  cout << endl << "  O = VACANT   X = TAKEN" << endl << endl;
  cout << "    A   B   C   D   E   F   G   H   I   J";
  for (int i = 1; i < floor + 1; i++)
  {
    cout << endl << endl << i;
    for (int j = 0; j < room; j++)
      cout << setw(3) << " " << map [i][j];
  }
  cout<<endl;
}

void checkPrices(){
  int i,j;
  system("cls");
  cout<<"===========================HOTEL DEL LUNA ROOM RATES==========================="<<endl<<endl;
  for(i=0;i<7;i++)
    {
      for(j=0;j<5;j++)
      {
        cout<<left<<setw(16);
        if(i==0&&j==0) cout<<"";
        if(i==0&&j==1) cout<<"SINGLE";
        if(i==0&&j==2) cout<<"DOUBLE";
        if(i==0&&j==3) cout<<"FAMILY";
        if(i==0&&j==4) cout<<"DELUXE";
        if(i==1&&j==0) cout<<"PAX";
        if(i==1&&j==1) cout<<"1";
        if(i==1&&j==2) cout<<"2";
        if(i==1&&j==3) cout<<"4";
        if(i==1&&j==4) cout<<"4";
        if(i==2&&j==0) cout<<"BED";
        if(i==2&&j==1) cout<<"1 SINGLE BED";
        if(i==2&&j==2) cout<<"2 DOUBLE BEDS";
        if(i==2&&j==3) cout<<"1 QUEEN-SIZE";
        if(i==2&&j==4) cout<<"1 KING-SIZE";
        if(i==3&&j==0) cout<<"";
        if(i==3&&j==1) cout<<"";
        if(i==3&&j==2) cout<<"";
        if(i==3&&j==3) cout<<"+2 SINGLE BED";
        if(i==3&&j==4) cout<<"+2 DOUBLE BEDS";
        if(i==4&&j==0) cout<<"ADULT/NIGHT";
        if(i==4&&j==1) cout<<"P1,000.00";
        if(i==4&&j==2) cout<<"P2,000.00";
        if(i==4&&j==3) cout<<"P3,500.00";
        if(i==4&&j==4) cout<<"P5,000.00";        
        if(i==5&&j==0) cout<<"CHILDREN/NIGHT";
        if(i==5&&j==1) cout<<"P500.00";
        if(i==5&&j==2) cout<<"P1,000.00";
        if(i==5&&j==3) cout<<"P1,750.00";
        if(i==5&&j==4) cout<<"P2,500.00";
        if(i==6&&j==0) cout<<"ADD'L PERSON";
        if(i==6&&j==1) cout<<"P500.00";
        if(i==6&&j==2) cout<<"P700.00";
        if(i==6&&j==3) cout<<"P850.00";
        if(i==6&&j==4) cout<<"P1,000.00";
      }cout<<endl;
    }
}
