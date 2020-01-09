//room service
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;
//global
int opt;
const int menuSize=5;
double price[50];
string menuB[menuSize]={"Pancakes","Sausage and Eggs","French Toast","Waffles","Continental Breakfast" };
string menuApp[menuSize]={"Garlic Bread", "Calamari","Cheese and Crackers","Onion rings","Mini Tacos"};
string menuSal[menuSize]={"Caesar Salad", "Greek Salad","Potato salad","Crab Louis","Chef's Salad"};
string menuSoup[menuSize]={"Mushroom Soup","Pumpkin Soup","Carrot Soup", "Chicken Soup","Porridge"};
string menuPasta[menuSize]={"Carbonara","Puttanesca","Aglio e olio","Lasagna","Pesto"};
string menuPizza[menuSize]={"Hawaiian","Pepperoni","Vegetarian","Four Cheese","All Meat"};
string menuSnacks[menuSize]={"Nachos","French Fries","Club Sandwich","Mini burger","Fish and Chips"};
string menuMeals[menuSize]={"Grilled Porkchop","Roasted Chicken","Turkey","Grilled lamb","Grilled Salmon"};
string menuDess[menuSize]={"Ice Cream (Vanilla, Chocolate, Strawberry)","Sliced Cake","Whole Cake","Banana Split","Halo-halo"};
string menuDrinks[menuSize]={"Juice","Wine","Beer","Coffee","Shakes"};
double priceB[menuSize]={160, 200, 180, 180, 230};
double priceApp[menuSize]={90, 150, 200, 120, 150};
double priceSal[menuSize]={180, 180, 180, 200, 180};
double priceSoup[menuSize]={120, 120, 120, 120, 100};
double pricePasta[menuSize]={180, 180, 180, 190, 190};
double pricePizza[menuSize]={250, 250, 260, 280, 270};
double priceSnacks[menuSize]={200, 120, 160, 140, 180};
double priceMeals[menuSize]={200, 200, 250, 300, 300};
double priceDess[menuSize]={120, 150, 600, 180, 160};
double priceDrinks[menuSize]={60, 180, 70, 60, 100};
int menuCtr[menuSize];
int i;
int menuOpt;

//function prototype
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
			main();
			break;
	}//end switch
}while(opt!=11);
}//end function
///////////////////////////////////////////////
void order(){
	
char let;
	
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
			do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuB[i]<<"-"<<priceB[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
		
		case 2:{
				do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuApp[i]<<"-"<<priceApp[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
		
		}
			
		case 3:{
				do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuSal[i]<<"-"<<priceSal[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
		}
		
		case 4:{
			do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuSoup[i]<<"-"<<priceSoup[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
		}
			
		case 5:{
			
			do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuPasta[i]<<"-"<<pricePasta[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
		}
		
		case 6:{
				do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuPizza[i]<<"-"<<pricePizza[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
			}
		
		case 7:{
		do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuSnacks[i]<<"-"<<priceSnacks[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
		}
		
		case 8:{
			do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuMeals[i]<<"-"<<priceMeals[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
		}
			
		case 9:{
			do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuDess[i]<<"-"<<priceDess[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
		}
		
		case 10:{
			
		
			do{			
				system("cls");
				
				
					cout<<"======Breakfast======\n";
					for(i=0;i<5;i++){
			        	cout<<"["<<i+1<<"]"<<menuDrinks[i]<<"-"<<priceDrinks[i]<<endl;			 	
			          }
				   cout<<"["<<i+1<<"]"<<"Back"<<endl
			           <<"Enter your option: ";
		           cin>>menuOpt;
		        	if(menuOpt==i+1){
		        		break;
					}
					else{
						cout<<"Enter amount of order: ";
			  		cin>>menuCtr[menuOpt-1];
		       			
					}
					
					do{					
		        	cout<<"Order Again? [y/n]";
			 		cin>>let;
			 	}while(let!='y'&&let!='n');	
			        
			
				
			}while(let=='y');	
			break;
		}
		case 11:
			break;
	}//end switch
}while(opt!=11);
}

