/* PROGRAMMERS:
 * GROUP 5
 * Capua, Ezekiel Joshua D.
 * Najarila, Lurd Synell B.
 * Rubiano, Geremie B.
 * Samonte, Danielle C.
 * Subaan, Val Rindel S.
 * COURSE / SECTION: CS126-8L / BM1
 * PROGRAM: Student Information System
 */


#include<iostream> //cin cout
#include<fstream> //file manipulation
#include<iomanip> //input output manipulation
#include<ctime> //for random generating student number
#include<cstdlib> //for random generating student number
using namespace std;


//GLOBAL DECLARATION
//for automatic calculation of age, set to date of presentation
const int CURRENT_YEAR=2019;
const int CURRENT_MONTH=10;
const int CURRENT_DAY=24;

const int maxStudents=150; //no. of students program can accommodate
int totalStudents=0; //ctr for number of students in system

char choice; //used for all menus
int ctr; //used for loops

//arrays to hold student data during runtime
string data_sn[maxStudents]; //student number
string data_ln[maxStudents]; //last name
string data_fn[maxStudents]; //first name
string data_mn[maxStudents]; //middle name
int data_birth_year[maxStudents]; //year of birth
int data_birth_month[maxStudents]; //month of birth
int data_birth_day[maxStudents]; //day of birth
string data_status[maxStudents]; //status
string data_course[maxStudents]; //course
string data_section[maxStudents]; //section


//FUNCTION PROTOTYPE
//login functions
void getLogin(); //login menu; as student or admin
void getStudentLogin(); //student login
void getAdminLogin(); //admin login
void getStudentMenu(int xDataIndex); //display student menu
void getAdminMenu(); //display admin menu

//main functions
void addInfo(); //add students
void EditStudentInfo(int xDataIndex); //edit student info
void ViewStudentInfo(int xDataIndex); //view student info
void ViewStudents(); //view all students, in ascending order
void getSched(string xSection); //view student schedule
void lookUp(); //lookup student by student number

//misc functions
int getDataIndex(string xStudentNum); //look for student number in data, also validate if existing
int StringToInt(string xStrNum); //convert number from string to int; used in getData for birth day, month, year
string ConvertStudentNum(int xStudentNum); //convert student number from int to string; used in addInfo

//fstream functions
void getData(); //get data in text files, put in arrays
void UpdateFile(); //overwrite existing data in text files


int main()
{
	//declaration
	
	//executable
	getData(); //initialize arrays for student data
	
	do{
		getLogin();
		
		switch(choice)
		{
			case '1':
				getAdminLogin();
				break;
				
			case '2':
				getStudentLogin();				
				break;
				
			case '3':
				exit(0);
				break;
		}//end switch
	}while(choice!='5'&&choice!='7');
}//end main
////////////////////////////////////////////////////////////////////////////////
void getLogin()
{
	//declaration
	
	//executable
	do{
		system("cls");
		cout<<"******************************" <<endl
			<<"| STUDENT INFORMATION SYSTEM |" <<endl
			<<"|           login            |" <<endl
			<<"******************************" <<endl
			<<"|                            |" <<endl
			<<"| [1] ADMIN                  |"<<endl
			<<"| [2] STUDENT                |"<<endl
			<<"| [3] EXIT                   |"<<endl
			<<"|                            |"<<endl
			<<"******************************"<<endl << endl
			<<"Enter your choice: ";
		cin>>choice;
	}while(choice<'1'||choice>'3');
}//end getLogin
////////////////////////////////////////////////////////////////////////////////
void getStudentLogin()
{
	//declaration
	string xstud; //input student number
	string xpassw; //input password
	int dataIndex; //index in student data arrays; used for validation
	
	//executable
	
	do{
		system("cls");
		cout<<"******************************" <<endl
			<<"| STUDENT INFORMATION SYSTEM |" <<endl
			<<"|        student login       |" <<endl
			<<"******************************" <<endl << endl;
		cout<<"Student number: ";
		cin>>xstud;
		cout<<"Password: ";
		cin>>xpassw;
		
		dataIndex=getDataIndex(xstud);
		
		if(dataIndex>=0&&xpassw=="Password1")
			getStudentMenu(dataIndex);
		else
		{
			cout<<"Incorrect student number or password!"<<endl;
			
			do{
				cout<<"Try again? [Y/N] ";
				cin>>choice;
				choice=toupper(choice);
			}while(choice!='Y'&&choice!='N');
		}//end else
	}while(choice=='Y');		
}//end getStudentLogin
////////////////////////////////////////////////////////////////////////////////
void getAdminLogin()
{
	//declaration
	string xans; //input password
	
	//executable
	do
	{
		system("cls");

		cout<<"******************************" <<endl
			<<"| STUDENT INFORMATION SYSTEM |" <<endl
			<<"|        admin login         |" <<endl
			<<"******************************" <<endl << endl
			<<"Enter Password: ";
		cin>>xans;
	
		if(xans=="Admin1")
			getAdminMenu();
		else
		{
			cout<<"Incorrect password!"<<endl;
			do{
				cout<<"Try again? [Y/N] ";
				cin>>choice;
				choice=toupper(choice);
			}while(choice!='Y'&&choice!='N');
		}//end else
	
	}while(choice=='Y'); //if choice=='N', return to login menu: getLogin
}//end getAdminLogin
////////////////////////////////////////////////////////////////////////////////
void getStudentMenu(int xDataIndex)
{
	//declaration
	
	//executable
	do{
		do{
			system("cls");
			cout<<"************************************" <<endl
				<<"|    STUDENT INFORMATION SYSTEM    |" <<endl
				<<"|       student system menu        |" <<endl
				<<"************************************" <<endl
				<<" [1]VIEW STUDENT INFOMATION  "<<endl
				<<" [2]VIEW STUDENT SCHEDULE "<<endl
				<<" [3]EDIT YOUR STUDENT INFORMATION"<<endl
				<<" [4]LOG OUT"<<endl
				<<" [5]EXIT"<<endl
				<<"************************************"<<endl
				<<"Enter your choice: ";
			cin>>choice;
		}while(choice<'1'||choice>'5');
			
		switch(choice)
		{
			case '1': //view student information
				ViewStudentInfo(xDataIndex);
				break;
				
			case '2': //view student schedule
				getSched(data_section[xDataIndex]);
				break;
				
			case '3': //edit student information
				EditStudentInfo(xDataIndex);
				break;
				
			case '5': //exit
				exit(0);
		}//end switch
		
		if(choice!='4')
		{
			cout<<endl<<endl<<endl
				<<"--------OPTIONS--------"<<endl
				<<"[1] RETURN TO MAIN MENU"<<endl
				<<"[2] EXIT PROGRAM"<<endl
				<<"-----------------------"<<endl;
					
			do{
				cout<<"Enter your choice: ";
				cin>>choice;
			}while(choice<'1'||choice>'2');
			
			if(choice=='2')
				exit(0);
		}//end if
	}while(choice=='1');
}//end getStudentMenu
////////////////////////////////////////////////////////////////////////////////
void getAdminMenu()
{
	//declaration
	string studentNum; //input student number
	string sec; //input section
	int dataIndex; //index in student data arrays; used for validation
	
	//executable
	do{
		do{
			system("cls");
			cout<<"***********************************" <<endl
				<<"|   STUDENT INFORMATION SYSTEM    |" <<endl
				<<"|        admin system menu        |" <<endl
				<<"***********************************" <<endl
				<<" [1]ADD STUDENT INFOMATION  "<<endl
				<<" [2]EDIT STUDENT INFORMATION "<<endl
				<<" [3]VIEW STUDENTS  "<<endl
				<<" [4]VIEW STUDENT SCHEDULE "<<endl
				<<" [5]LOOK UP BY STUDENT NUMBER  "<<endl
				<<" [6]LOG OUT"<<endl
				<<" [7]EXIT"<<endl
				<<"***********************************"<<endl
				<<"Enter your choice: ";
			cin>>choice;
		}while(choice<'1'||choice>'7');
			
		switch(choice)
		{
			case '1': //add student information
			{
					if(totalStudents==maxStudents)
					{
						cout<<"Database full!"<<endl
							<<"Can only handle "<<maxStudents<<" students!"
							<<endl<<endl;
					}//end if
					else
						addInfo();
					
					break;
			}//end case 1
				
			case '2': //edit student information
			{
				do{
					cout<<"Enter student number: ";
					cin>>studentNum;
					
					dataIndex=getDataIndex(studentNum);
					
					if(dataIndex<0)
						cout<<"Invalid input!"<<endl<<endl;
				}while(dataIndex<0);
				
				EditStudentInfo(dataIndex);
				break;
			}//end case 2
				
			case '3': //view all students
				ViewStudents();	
				break;
				
			case '4': //view student schedule
			{
				do{
					cout<<"Enter section [BM1/BM2/BM3/BM4/BM5]: ";
					cin>>sec;
					
					if (sec != "BM1" && sec != "BM2" && sec != "BM3" &&
						sec != "BM4" && sec != "BM5")
					{
						cout << "Invalid section!" <<endl<<endl;
					}//end if
				}while(sec != "BM1" && sec != "BM2" && sec != "BM3" &&
					   sec != "BM4" && sec != "BM5");
					   
				getSched(sec);
				break;
			}//end case 4
				
			case '5':
				lookUp();
				break;
				
			case '7':
				exit(0);
		}//end switch
		
		if(choice!='6')
		{
			cout<<endl<<endl<<endl
				<<"--------OPTIONS--------"<<endl
				<<"[1] RETURN TO MAIN MENU"<<endl
				<<"[2] EXIT PROGRAM"<<endl
				<<"-----------------------"<<endl;
					
			do{
				cout<<"Enter your choice: ";
				cin>>choice;
			}while(choice<'1'||choice>'2');
			
			if(choice=='2')
				exit(0);
		}//end if
	}while(choice=='1');
}//end getAdminMenu
////////////////////////////////////////////////////////////////////////////////
void addInfo()
{
	//declaration
	int studentNum; //randomly generated student number
	int studentIndex; //used for validation if studentNum is unique
	int randMax = 300000, randMin = 200000, batch = 2019;
	string strStudentNum; //studentNum converted to string
	
	//input student info
	string fn,ln,mn, course, status, section;
	int birth_year, birth_month, birth_day;
	int age; //computed automatically from birthday
	
	//executable
	system("cls");
	cout<<"***********************************" <<endl
		<<"|   STUDENT INFORMATION SYSTEM    |" <<endl
		<<"|       add student info          |" <<endl
		<<"***********************************" <<endl;
	srand(time(NULL));
	
	do{ 
		studentNum = (batch * 1000000) + (rand() % (randMax - randMin) + randMin); //generate random student number
		strStudentNum=ConvertStudentNum(studentNum); //convert student number to string
		studentIndex=getDataIndex(strStudentNum); //check if student number already exists
	}while(studentIndex>=0);
	
	cout << "Student number: " << strStudentNum << endl;
	cout << "Enter first name: ";
	cin.ignore(); //prevents program from skipping getline
	getline(cin, fn);
	cout << "Enter last name: ";
	getline(cin, ln);
	cout << "Enter middle name: ";
	getline(cin, mn);
	
	do{
		cout << "Enter year of birth [1960-2005]: ";
		cin >> birth_year;
		
		if(birth_year<1960||birth_year>2005)
			cout << "Invalid input!"<<endl<<endl;
	}while(birth_year<1960||birth_year>2005);
	
	do{
		cout << "Enter month of birth [1-12]: ";
		cin >> birth_month;
		
		if(birth_month<1||birth_month>12)
			cout << "Invalid input!"<<endl<<endl;
	}while(birth_month<1||birth_month>12);
	
	do{
		cout << "Enter day of birth: ";
		cin >> birth_day;
		
		if(birth_day<1||birth_day>31)
			cout<<"Invalid input!"<<endl<<endl;
		else
		{
			switch(birth_month)
			{
				//months with 31 days
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
				{
					if(birth_day>31)
					{
						cout<<"Invalid input!"<<endl<<endl;
						birth_day=-1;
					}//end if
					
					break;
				}//end case for 31 days
					
					
				//months with 30 days
				case 4:
				case 6:
				case 9:
				case 11:
				{
					if(birth_day>30)
					{
						cout<<"Invalid input!"<<endl<<endl;
						birth_day=-1;
					}//end if
					
					break;
				}//end case for 30 days
					
					
				//for february
				case 2:
				{
					if(birth_year%400==0||(birth_year%4==0&&birth_year%100!=0)) //check if leap year
					{
						if(birth_day>29)
						{
							cout<<"Invalid input!"<<endl<<endl;
							birth_day=-1;
						}//end if
					}//end if
					else
					{
						if(birth_day>28)
						{
							cout<<"Invalid input!"<<endl<<endl;
							birth_day=-1;
						}//end if
					}//end else
				}//end case 2
			}//end switch
		}//end else
	}while(birth_day<1||birth_day>31);
	
	do{
		cout << "Enter status [Full/Part]: ";
		cin >> status;
		
		if(status!="Full"&&status!="Part")
			cout<<"Invalid input!"<<endl<<endl;
	}while(status!="Full"&&status!="Part");
	
	do{
		cout << "Enter course [CS/IT/IS/EMC]: ";
		cin >> course;
		
		if(course!="CS"&&course!="IT"&&course!="IS"&&course!="EMC")
			cout << "Invalid input!"<<endl<<endl;
	}while(course!="CS"&&course!="IT"&&course!="IS"&&course!="EMC");
	
	do{
		cout << "Enter section [BM1/BM2/BM3/BM4/BM5]: ";
		cin >> section;
		
		if(section!="BM1"&&section!="BM2"&&section!="BM3"&&
		   section!="BM4"&&section!="BM5")
		{
			cout<<"Invalid input!"<<endl<<endl;
		}//end if
	}while(section!="BM1"&&section!="BM2"&&section!="BM3"&&
		   section!="BM4"&&section!="BM5");
	
	data_sn[totalStudents]=strStudentNum;
	data_ln[totalStudents]=ln;
	data_fn[totalStudents]=fn;
	data_mn[totalStudents]=mn;
	data_birth_year[totalStudents]=birth_year;
	data_birth_month[totalStudents]=birth_month;
	data_birth_day[totalStudents]=birth_day;
	data_status[totalStudents]=status;
	data_course[totalStudents]=course;
	data_section[totalStudents]=section;
	
	totalStudents++;
	UpdateFile(); //write to text file
}//end addInfo
////////////////////////////////////////////////////////////////////////////////
void EditStudentInfo(int xDataIndex)
{
	//declaration
	int x_year; //birth year of student
	//input student info
	string ln, fn, mn;
	int bm, bd, by;
	string status, course, section;
	
	//executable
	do{
		do{
			system("cls");
			cout<<right;
			ViewStudentInfo(xDataIndex);
			
			cout<<endl<<endl
				<<"-------------EDIT STUDENT INFO-------------"<<endl
				<<" [1] LAST NAME"<<endl
				<<" [2] FIRST NAME"<<endl
				<<" [3] MIDDLE NAME"<<endl
				<<" [4] MONTH OF BIRTH"<<endl
				<<" [5] DAY OF BIRTH"<<endl
				<<" [6] YEAR OF BIRTH"<<endl
				<<" [7] STATUS"<<endl
				<<" [8] COURSE"<<endl
				<<" [9] SECTION"<<endl
				<<" [0] FINISH EDIT"<<endl
				<<"-------------------------------------------"<<endl
				<<"Enter your choice: ";
			cin>>choice;
		}while(choice<'0'||choice>'9');
		
		switch(choice)
		{
			case '1': //last name
			{
				cout<<"Enter LAST NAME: ";
				cin.ignore(); //prevents program from skipping getline
				getline(cin, ln);
				
				data_ln[xDataIndex]=ln;
				UpdateFile();
				break;
			}//end case 1
			
			case '2': //first name
			{
				cout<<"Enter FIRST NAME: ";
				cin.ignore(); //prevents program from skipping getline
				getline(cin, fn);
				
				data_fn[xDataIndex]=fn;
				UpdateFile();
				break;
			}//end case 2
			
			case '3': //middle name
			{
				cout<<"Enter MIDDLE NAME: ";
				cin.ignore(); //prevents program from skipping getline
				getline(cin, mn);
				
				data_mn[xDataIndex]=mn;
				UpdateFile();
				break;
			}//end case 3
			
			case '4': //month of birth
			{
				do{
					cout<<"Enter MONTH OF BIRTH [1-12]: ";
					cin>>bm;
					
					if(bm<1||bm>12)
						cout<<"Invalid input!"<<endl<<endl;
				}while(bm<1||bm>12);
				
				
				data_birth_month[xDataIndex]=bm;
				UpdateFile();
				break;
			}//end case 4
			
			case '5': //day of birth
			{
				do{
					cout<<"Enter DAY OF BIRTH: ";
					cin>>bd;
					
					if(bd<1||bd>31)
						cout<<"Invalid input!"<<endl<<endl;
					else
					{
						switch(data_birth_month[xDataIndex])
						{
							//months with 31 days
							case 1:
							case 3:
							case 5:
							case 7:
							case 8:
							case 10:
							case 12:
							{
								if(bd>31)
								{
									cout<<"Invalid input!"<<endl<<endl;
									bd=-1;
								}//end if
								
								break;
							}//end case for 31 days
								
								
							//months with 30 days
							case 4:
							case 6:
							case 9:
							case 11:
							{
								if(bd>30)
								{
									cout<<"Invalid input!"<<endl<<endl;
									bd=-1;
								}//end if
								
								break;
							}//end case for 30 days
								
								
							//for february
							case 2:
							{
								x_year=data_birth_year[xDataIndex];
								if(x_year%400==0||(x_year%4==0&&x_year&100!=0))
								{
									if(bd>29)
									{
										cout<<"Invalid input!"<<endl<<endl;
										bd=-1;
									}//end if
								}//end if
								else
								{
									if(bd>28)
									{
										cout<<"Invalid input!"<<endl<<endl;
										bd=-1;
									}//end if
								}//end else
							}//end case 2
						}//end switch
					}//end else
				}while(bd<1||bd>31);
				
				data_birth_day[xDataIndex]=bd;
				UpdateFile();
				break;
			}//end case 5
			
			case '6': //year of birth
			{
				do{
					cout<<"Enter YEAR OF BIRTH [1960-2005]: ";
					cin>>by;
					
					if(by<1960||by>2005)
						cout<<"Invalid input!"<<endl<<endl;
				}while(by<1960||by>2005);
				
				data_birth_year[xDataIndex]=by;
				UpdateFile();
				break;
			}//end case 6
			
			case '7': //status
			{
				do{
					cout<<"Enter STATUS [Full/Part]: ";
					cin>>status;
					
					if(status!="Full"&&status!="Part")
						cout<<"Invalid input!"<<endl<<endl;
				}while(status!="Full"&&status!="Part");
				
				data_status[xDataIndex]=status;
				UpdateFile();
				break;
			}//end case 7
			
			case '8': //course
			{
				do{
					cout<<"Enter COURSE [CS/IT/IS/EMC]: ";
					cin>>course;
					
					if(course!="CS"&&course!="IT"&&course!="IS"&&course!="EMC")
						cout<<"Invalid input!"<<endl<<endl;
				}while(course!="CS"&&course!="IT"&&course!="IS"&&course!="EMC");
				
				data_course[xDataIndex]=course;
				UpdateFile();
				break;
			}//end case 8
			
			case '9': //section
			{
				do{
					cout<<"Enter SECTION [BM1/BM2/BM3/BM4/BM5]: ";
					cin>>section;
					
					if(section!="BM1"&&section!="BM2"&&section!="BM3"&&
					   section!="BM4"&&section!="BM5")
					{
						cout<<"Invalid input!"<<endl<<endl;
					}//end if
				}while(section!="BM1"&&section!="BM2"&&section!="BM3"&&
					   section!="BM4"&&section!="BM5");
				
				data_section[xDataIndex]=section;
				UpdateFile();
				break;
			}//end case 9
		}//end switch
	}while(choice!='0');
}//end EditStudentInfo
////////////////////////////////////////////////////////////////////////////////
void ViewStudentInfo(int xDataIndex)
{
	//declaration
	
	//executable
	system("cls"); //clear screen
	cout<<"*******************************************" <<endl
		<<"|        STUDENT INFORMATION SYSTEM       |" <<endl
		<<"|            student information          |" <<endl
		<<"*******************************************" <<endl;
	cout<<right<<setw(20)<<"NAME:  "
		<<data_ln[xDataIndex]<<", " //display last name
		<<data_fn[xDataIndex]<<" " //display first name
		<<data_mn[xDataIndex]<<endl //display middle name
		<<setw(20)<<"STUDENT NUMBER:  "<<data_sn[xDataIndex]<<endl
		<<setw(20)<<"BIRTHDAY:  ";
		
	switch(data_birth_month[xDataIndex])
	{
		case 1:
			cout<<"January ";
			break;
			
		case 2:
			cout<<"February ";
			break;
			
		case 3:
			cout<<"March ";
			break;
			
		case 4:
			cout<<"April ";
			break;
			
		case 5:
			cout<<"May ";
			break;
			
		case 6:
			cout<<"June ";
			break;
			
		case 7:
			cout<<"July ";
			break;
			
		case 8:
			cout<<"August ";
			break;
			
		case 9:
			cout<<"September ";
			break;
			
		case 10:
			cout<<"October ";
			break;
			
		case 11:
			cout<<"November ";
			break;
			
		case 12:
			cout<<"December ";
			break;
	}//end switch -- birthMonth
	
	cout<<data_birth_day[xDataIndex]<<", " //display birth day
		<<data_birth_year[xDataIndex]<<endl //display birth year
		<<setw(20)<<"AGE:  ";
		
	//calculate age
	if(CURRENT_MONTH>data_birth_month[xDataIndex]) //nag birthday na this year
		cout<<(CURRENT_YEAR-data_birth_year[xDataIndex]);
	else if(CURRENT_MONTH<data_birth_month[xDataIndex]) //hindi pa nagbirthday this year
		cout<<(CURRENT_YEAR-data_birth_year[xDataIndex]-1);
	else if(CURRENT_MONTH==data_birth_month[xDataIndex]) //birthday ngayon na month
	{
		if(CURRENT_DAY<data_birth_day[xDataIndex]) //hindi pa nagbirthday
			cout<<(CURRENT_YEAR-data_birth_year[xDataIndex]-1);
		else //nagbirthday na
			cout<<(CURRENT_YEAR-data_birth_year[xDataIndex]);
	}//end else if
		
	cout<<endl;
	cout<<setw(20)<<"STATUS:  ";
	
	if(data_status[xDataIndex]=="Full")
		cout<<"Full-time"<<endl;
	else
		cout<<"Part-time"<<endl;
	
	cout<<setw(20)<<"COURSE:  "<<data_course[xDataIndex]<<endl
		<<setw(20)<<"YEAR:  "<<"1"<<endl
		<<setw(20)<<"SCHOOL YEAR:  "<<"2019-2020"<<endl
		<<setw(20)<<"SECTION:  "<<data_section[xDataIndex]<<endl;
}//end ViewStudentInfo
////////////////////////////////////////////////////////////////////////////////
void ViewStudents()
{
	//declaration
	// for sorting
	int sortedIndex[totalStudents];
	int currentPos, largestPos, temp;
	string largest_LN, largest_FN, largest_MN;
	string current_LN, current_FN, current_MN;
	
	//executable
	system("cls");
	cout<<"************************************************" <<endl
		<<"|          STUDENT INFORMATION SYSTEM          |" <<endl
		<<"|                 view students                |" <<endl
		<<"***********************************************" <<endl;
	for(ctr=0; ctr<totalStudents; ctr++) //initialize sortedIndex[]
	{
		sortedIndex[ctr]=ctr;
	}//end for
	
	for(ctr=totalStudents-1; ctr>=0; ctr--) //arrange in ascending order
	{
		//select largest name in unsorted section of the list
		largestPos=0;
		for(currentPos=1; currentPos<=ctr; currentPos++)
		{
			largest_LN=data_ln[sortedIndex[largestPos]];
			largest_FN=data_fn[sortedIndex[largestPos]];
			largest_MN=data_mn[sortedIndex[largestPos]];
			
			current_LN=data_ln[sortedIndex[currentPos]];
			current_FN=data_fn[sortedIndex[currentPos]];
			current_MN=data_mn[sortedIndex[currentPos]];
			
			if(current_LN>largest_LN) //compare using last name
				largestPos=currentPos;
			else if(current_LN==largest_LN) //if last names are equal
			{
				if(current_FN>largest_FN) //compare using first name 
					largestPos=currentPos;
				else if(current_FN==largest_FN) //if first names are equal
				{
					if(current_MN>largest_MN) //compare using middle name
						largestPos=currentPos;
				} //end else if -- first names are equal
			} //end else if -- last names are equals
		} //end for -- select largest name
		
		//exchange name in unsorted section with largest name
		temp=sortedIndex[ctr]; //store in temp the last in unsorted section
		sortedIndex[ctr]=sortedIndex[largestPos]; //replace the last with largest
		sortedIndex[largestPos]=temp; //put value of temp in old position of largest
	}//end for
	
	
	//display list of students
	cout<<left
		<<setw(20)<<"STUDENT NUMBER"<<"NAME"<<endl;
		
	for(ctr=0; ctr<totalStudents; ctr++)
	{
		cout<<setw(20)<<data_sn[sortedIndex[ctr]]
			<<data_ln[sortedIndex[ctr]]<<", "
			<<data_fn[sortedIndex[ctr]]<<" "
			<<data_mn[sortedIndex[ctr]]<<endl;
	}//end for
	
	cout<<endl<<endl
		<<"There are ("<<totalStudents<<") students registered in the system."
		<<endl<<endl;
}//end ViewStudents
////////////////////////////////////////////////////////////////////////////////
void getSched(string section)
{
	//declaration
	
	//executable
	system("cls");
	cout<<"****************************************************************" <<endl
		<<"|                   STUDENT INFORMATION SYSTEM                 |" <<endl
		<<"|                            schedule                          |" <<endl
		<<"****************************************************************" <<endl;
	if (section == "BM1")
	{
		cout << "		Mon	Tue	Wed 	Thu 	Fri	Sat" <<endl
		<< "07:30-09:00	GED101		GED101	CS126L	GED101	NSTP100" << endl
		<< "09:00-10:30	GED103		GED103 	CS126L	GED103 	NSTP100" << endl
		<< "10:30-12:00				CS126L		NSTP100" << endl
		<< "12:00-13:30	CS101		CS101 	IT152	CS101 	" << endl
		<< "13:30-15:00	CS126		CS126 	IT152	FW01 	" << endl
		<< "15:00-16:30			 	IT152	FW01 	" << endl;
	}//end if -- BM1
	else if (section == "BM2")
	{
		cout << "		Mon	Tue	Wed 	Thu 	Fri	Sat" <<endl
		<< "07:30-09:00	GED103		GED103	IT152L	GED103	NSTP100" << endl
		<< "09:00-10:30	GED101		GED101 	1T152L	GED101 	NSTP100" << endl
		<< "10:30-12:00				IT152L		NSTP100" << endl
		<< "12:00-13:30	CS126		CS126 	CS126L		FW01 	" << endl
		<< "13:30-15:00	CS101		CS101 	CS126L	CS101 	FW101" << endl
		<< "15:00-16:30			 	CS126L	 	" << endl;
	}//end else if -- BM2
	else if (section == "BM3")
	{
		cout << "		Mon	Tue	Wed 	Thu 	Fri	Sat" <<endl
		<< "07:30-09:00	GED101	IT152L	GED101	FW01	GED101	NSTP100" << endl
		<< "09:00-10:30	CS126	IT152L	CS126 	FW01	 	NSTP100" << endl
		<< "10:30-12:00		IT152L				NSTP100" << endl
		<< "12:00-13:30	GED103	CS126L	GED103 		GED103 	" << endl
		<< "13:30-15:00	CS101	CS126L	CS101 		CS101 	" << endl
		<< "15:00-16:30		CS126L 		 	" << endl;
	}//end else if -- BM3
	else if (section == "BM4")
	{
		cout << "		Mon	Tue	Wed 	Thu 	Fri	Sat" <<endl
		<< "07:30-09:00	GED103		GED103	CS126L	GED103	NSTP100" << endl
		<< "09:00-10:30	GED101		GED101 	CS126L	GED101 	NSTP100" << endl
		<< "10:30-12:00				CS126L		NSTP100" << endl
		<< "12:00-13:30	CS126		CS126 	CS126L		 	" << endl
		<< "13:30-15:00	IT101	FW01	IT101 	CS126L	IT101 	" << endl
		<< "15:00-16:30		FW01	 	CS126L	 	" << endl;	
	}//end else if -- BM4
	else if (section == "BM5")
	{
		cout << "		Mon	Tue	Wed 	Thu 	Fri	Sat" <<endl
		<< "07:30-09:00	GED101		GED101		GED101	NSTP100" << endl
		<< "09:00-10:30	GED103		GED103 		GED103 	NSTP100" << endl
		<< "10:30-12:00						NSTP100" << endl
		<< "12:00-13:30	MATH161	IT152L	MATH161 FW01	MATH161 	" << endl
		<< "13:30-15:00	IS100	IT152L	IS100 	FW01	IS100 	" << endl
		<< "15:00-16:30		IT152L	 		 	" << endl;
	}//end else if -- BM5
}//end getSched
////////////////////////////////////////////////////////////////////////////////
void lookUp()
{
	//declaration
	string input_sn; //input student number
	int stud_index; //index in student data arrays; used for validation
	
	//executable
	system("cls");
	cout<<"***********************************" <<endl
		<<"|   STUDENT INFORMATION SYSTEM    |" <<endl
		<<"|          look up student        |" <<endl
		<<"***********************************" <<endl;
	do{
		cout << "Enter student number: ";
		cin >> input_sn;
		
		stud_index = getDataIndex(input_sn);
		
		if(stud_index==-1)
		{
			cout << "Student not found!" << endl;
			
			do { //if not y/n, prompt again
				cout << "Try again? [Y/N] ";
				cin >> choice;
				choice=toupper(choice);
				
				if (choice != 'Y' && choice != 'N')
					cout << "Invalid input!" << endl;
			} while (choice != 'Y' && choice != 'N');
		}//end if
		
		cout<<endl;
	}while(stud_index==-1&&choice=='Y');
	
	if(stud_index>=0)
		ViewStudentInfo(stud_index);
}//end lookUp
////////////////////////////////////////////////////////////////////////////////
int getDataIndex(string xStudentNum)
{
	//declaration
	int dataIndex=-1; //return index in student data arrays; used for validation
	
	//executable
	for(ctr=0; ctr<totalStudents; ctr++)
	{
		if(data_sn[ctr]==string(xStudentNum))
			dataIndex=ctr;
	}//end for
	
	return dataIndex;
}//end getDataIndex
////////////////////////////////////////////////////////////////////////////////
int StringToInt(string xStrNum)
{
	//declaration
	
	//executable
	if(xStrNum=="1")
		return 1;
	else if (xStrNum=="2")
		return 2;
	else if (xStrNum=="3")
		return 3;
	else if (xStrNum=="4")
		return 4;
	else if (xStrNum=="5")
		return 5;
	else if (xStrNum=="6")
		return 6;
	else if (xStrNum=="7")
		return 7;
	else if (xStrNum=="8")
		return 8;
	else if (xStrNum=="9")
		return 9;
	else if (xStrNum=="10")
		return 10;
	else if (xStrNum=="11")
		return 11;
	else if (xStrNum=="12")
		return 12;
	else if (xStrNum=="13")
		return 13;
	else if (xStrNum=="14")
		return 14;
	else if (xStrNum=="15")
		return 15;
	else if (xStrNum=="16")
		return 16;
	else if (xStrNum=="17")
		return 17;
	else if (xStrNum=="18")
		return 18;
	else if (xStrNum=="19")
		return 19;
	else if (xStrNum=="20")
		return 20;
	else if (xStrNum=="21")
		return 21;
	else if (xStrNum=="22")
		return 22;
	else if (xStrNum=="23")
		return 23;
	else if (xStrNum=="24")
		return 24;
	else if (xStrNum=="25")
		return 25;
	else if (xStrNum=="26")
		return 26;
	else if (xStrNum=="27")
		return 27;
	else if (xStrNum=="28")
		return 28;
	else if (xStrNum=="29")
		return 29;
	else if (xStrNum=="30")
		return 30;
	else if (xStrNum=="31")
		return 31;
	else if (xStrNum=="2005")
		return 2005;
	else if (xStrNum=="2004")
		return 2004;
	else if (xStrNum=="2003")
		return 2003;
	else if (xStrNum=="2002")
		return 2002;
	else if (xStrNum=="2001")
		return 2001;
	else if (xStrNum=="2000")
		return 2000;
	else if (xStrNum=="1999")
		return 1999;
	else if (xStrNum=="1998")
		return 1998;
	else if (xStrNum=="1997")
		return 1997;
	else if (xStrNum=="1996")
		return 1996;
	else if (xStrNum=="1995")
		return 1995;
	else if (xStrNum=="1994")
		return 1994;
	else if (xStrNum=="1993")
		return 1993;
	else if (xStrNum=="1992")
		return 1992;
	else if (xStrNum=="1991")
		return 1991;
	else if (xStrNum=="1990")
		return 1990;
	else if (xStrNum=="1989")
		return 1989;
	else if (xStrNum=="1988")
		return 1988;
	else if (xStrNum=="1987")
		return 1987;
	else if (xStrNum=="1986")
		return 1986;
	else if (xStrNum=="1985")
		return 1985;
	else if (xStrNum=="1984")
		return 1984;
	else if (xStrNum=="1983")
		return 1983;
	else if (xStrNum=="1982")
		return 1982;
	else if (xStrNum=="1981")
		return 1981;
	else if (xStrNum=="1980")
		return 1980;
	else if (xStrNum=="1979")
		return 1979;
	else if (xStrNum=="1978")
		return 1978;
	else if (xStrNum=="1977")
		return 1977;
	else if (xStrNum=="1976")
		return 1976;
	else if (xStrNum=="1975")
		return 1975;
	else if (xStrNum=="1974")
		return 1974;
	else if (xStrNum=="1973")
		return 1973;
	else if (xStrNum=="1972")
		return 1972;
	else if (xStrNum=="1971")
		return 1971;
	else if (xStrNum=="1970")
		return 1970;
	else if (xStrNum=="1969")
		return 1969;
	else if (xStrNum=="1968")
		return 1968;		
	else if (xStrNum=="1967")
		return 1967;		
	else if (xStrNum=="1966")
		return 1966;
	else if (xStrNum=="1965")
		return 1965;
	else if (xStrNum=="1964")
		return 1964;
	else if (xStrNum=="1963")
		return 1963;
	else if (xStrNum=="1962")
		return 1962;
	else if (xStrNum=="1961")
		return 1961;
	else if (xStrNum=="1960")
		return 1960;
}//end StringToInt
////////////////////////////////////////////////////////////////////////////////
string ConvertStudentNum(int xStudentNum)
{
	//declaration
	fstream temp; //declare fstream namespace
	string strStudentNum; //return student number converted to string
	
	//executable
	temp.open("temp.txt");
	temp << xStudentNum;
	temp.close();
	
	temp.open("temp.txt");
	while(!temp.eof())
	{
		getline(temp, strStudentNum);
	}//end while
	
	temp.close();
	return strStudentNum;
}//end ConvertStudentNum
////////////////////////////////////////////////////////////////////////////////
void getData()
{
	//declaration
	ifstream studentData; //declare ifstream namespace
	//student info
	string sn; //student number
	string ln, fn, mn; //name
	string by, bm, bd; //birthday
	string status, course, sec; //status, course, section
	
	//executable
	studentData.open("sn.txt");
	ctr=0;
	
	while(getline(studentData, sn, '\n')&&ctr<maxStudents) //student number
	{
		data_sn[ctr]=sn;
		ctr++;
		totalStudents++;
	}//end while
	
	studentData.close();
	studentData.open("ln.txt");
	ctr=0;
	
	while(getline(studentData, ln, '\n')&&ctr<maxStudents) //last name
	{
		data_ln[ctr]=ln;
		ctr++;
	}//end while
	
	studentData.close();
	studentData.open("fn.txt");
	ctr=0;
	
	while(getline(studentData, fn, '\n')&&ctr<maxStudents) //first name
	{
		data_fn[ctr]=fn;
		ctr++;
	}//end while
	
	studentData.close();
	studentData.open("mn.txt");
	ctr=0;
	
	while(getline(studentData, mn, '\n')&&ctr<maxStudents) //middle name
	{
		data_mn[ctr]=mn;
		ctr++;
	}//end while
	
	studentData.close();
	studentData.open("by.txt");
	ctr=0;
	
	while(getline(studentData, by, '\n')&&ctr<maxStudents) //year of birth
	{
		data_birth_year[ctr]=StringToInt(by);
		ctr++;
	}//end while
	
	studentData.close();
	studentData.open("bm.txt");
	ctr=0;
	
	while(getline(studentData, bm, '\n')&&ctr<maxStudents) //month of birth
	{
		data_birth_month[ctr]=StringToInt(bm);
		ctr++;
	}//end while
	
	studentData.close();
	studentData.open("bd.txt");
	ctr=0;
	
	while(getline(studentData, bd, '\n')&&ctr<maxStudents) //day of birth
	{
		data_birth_day[ctr]=StringToInt(bd);
		ctr++;
	}//end while
	
	studentData.close();
	studentData.open("status.txt");
	ctr=0;
	
	while(getline(studentData, status, '\n')&&ctr<maxStudents) //status
	{
		data_status[ctr]=status;
		ctr++;
	}//end while
	
	studentData.close();
	studentData.open("course.txt");
	ctr=0;
	
	while(getline(studentData, course, '\n')&&ctr<maxStudents) //course
	{
		data_course[ctr]=course;
		ctr++;
	}//end while
	
	studentData.close();
	studentData.open("section.txt");
	ctr=0;
	
	while(getline(studentData, sec, '\n')&&ctr<maxStudents) //section
	{
		data_section[ctr]=sec;
		ctr++;
	}//end while
}//end getData
////////////////////////////////////////////////////////////////////////////////
void UpdateFile()
{
	//declaration
	ofstream studentData; //declare ofstream namespace
	
	//executable
	studentData.open("sn.txt");
	for(ctr=0; ctr<totalStudents; ctr++) // student number
	{
		studentData << data_sn[ctr] << endl;
	}
	
	studentData.close();
	
	studentData.open("ln.txt");
	for(ctr = 0; ctr < totalStudents; ctr++) //last name
	{
		studentData << data_ln[ctr] << endl;
	}
	studentData.close();
	
	studentData.open("fn.txt");	
	for(ctr = 0; ctr < totalStudents; ctr++) // first name
	{
		studentData << data_fn[ctr] << endl;
	}
	studentData.close();
	
	studentData.open("mn.txt");
	for(ctr = 0; ctr < totalStudents; ctr++) // middle name
	{
		studentData << data_mn[ctr] << endl;
	}
	studentData.close();
	
	studentData.open("by.txt");	
	for(ctr = 0; ctr < totalStudents; ctr++) // year of birth
	{
		studentData << data_birth_year[ctr] << endl;
	}
	studentData.close();
	
	studentData.open("bm.txt");
	for(ctr = 0; ctr < totalStudents; ctr++) // month of birth
	{
		studentData << data_birth_month[ctr] << endl;
	}
	studentData.close();
	
	studentData.open("bd.txt");	
	for(ctr = 0; ctr < totalStudents; ctr++) // day of birth
	{
		studentData << data_birth_day[ctr] << endl;
	}
	studentData.close();
	
	studentData.open("status.txt");
	for(ctr = 0; ctr < totalStudents; ctr++) // status
	{
		studentData << data_status[ctr] << endl;
	}
	studentData.close();
	
	studentData.open("course.txt");
	for(ctr = 0; ctr < totalStudents; ctr++) // course
	{
		studentData << data_course[ctr] << endl;
	}
	studentData.close();
	
	studentData.open("section.txt");
	for(ctr = 0; ctr < totalStudents; ctr++) // section
	{
		studentData << data_section[ctr] << endl;
	}
	
	studentData.close();
}//end UpdateFile
