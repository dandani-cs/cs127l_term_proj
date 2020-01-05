#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;


///////////////////////////////////////////////////////////

//structs
struct room_type {
	string name;
	double rate;
	double additional;
	string info;
} single_room, double_room, family_room, deluxe_room;




int main () {
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
}
	
