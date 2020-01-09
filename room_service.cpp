//room service
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

int opt;
int size=50;
double price[50];
string menu[50];

void viewMenu();
void order();

int main(){
	
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
			order();
			break;
		case 3:
			break;
	}
	
	
	
}//end main
//////////////////////////////////////////////////////////////////
void viewMenu(){

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
///////////////////////////////////////////////
void order(){
	
}

