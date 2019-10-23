#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std ;

struct Date
{
	unsigned short int Year;
	unsigned short int Month;
	unsigned short int Day;
};

struct Student
{
	string Firstname;
	string Lastname;
	unsigned long long int ID;
	Date Birthday;
	float Grade;
};

struct Class
{
	string ClassName;
	float Average;
	unsigned short int Capacity;
	vector <Student> Data;
};

vector <Class> Database;
string currentclass ; 
void Help()
{
}
//******************************************************
void SelectClass(string newclass)
{
 	string currentclass = newclass ;
	cout << endl << currentclass ;
}
//*********************************************************
void AddClass(string filename)
{
	ifstream classfile ("filename",ios::in) ; 
	Class newcls ;
	getline(classfile,newcls.ClassName) ;
	cin >> newcls.Average;
	cin >> newcls.Capacity;
	string date ;
	size_t count=0 ;
	string temp[3] ;
	for(size_t j=0 ; j<newcls.Capacity;j++)
	{
		Student newstd ;
		classfile >> newstd. Firstname ;
		classfile >> newstd. Lastname ;
		classfile >> newstd. ID ;	
		classfile >> newstd. Grade ;
		classfile >> date ;

		for ( auto i : date )
		{
			if  (i == '/' )
				count ++ ;
			else
			{
				temp[count] += i ;
			}
		}
		cout << temp[0];
		cout << temp[1];
		cout << temp[2];
		newstd.Birthday.Day   =  stoi(temp[0]) ;
		newstd.Birthday.Month =  stoi(temp[1]) ;
		newstd.Birthday.Year  =  stoi(temp[2]) ;
		newcls.Data.push_back(newstd);
	}	
	Database.push_back(newcls);
}	
//*********************************************************
void RemoveClass(string nameclass)
{
	for(Class i : Database)
	{
		if(i.ClassName == currentclass)
		{
			
		}
	}
}
//********************************************************* 
void AddStudent(string flname, Date birthday, unsigned long long int id, float gray)
{
	Student newstudent ;
	string date ;
	string temp[3] ;
	size_t count = 0 ;
	newstudent.Firstname ;
	newstudent.Lastname ;
	newstudent.ID == id ;
	newstudent.Grade == gray ;
	for ( auto i : date )
	{
		if  (i == '/' )
			count ++ ;
		else
		{
			temp[count] += i ;
		}
	}
	newstudent.Birthday.Day   =  stoi(temp[0]) ;
	newstudent.Birthday.Month =  stoi(temp[1]) ;
	newstudent.Birthday.Year  =  stoi(temp[2]) ;
	//Data.push_back(newstudent) ;
}
//********************************************************* 
void RemoveStudent(unsigned long long int id)
{
	for(Class i : Database)
	{
		if(i.ClassName == currentclass)
		{
			for(size_t j=0 ; j< 10;j++)
			{
				if(i.Data.at(j).ID == id)
				{
					i.Data.erase(i.Data.begin()+j) ;
				}
			}
		}
	}
}
//********************************************************* 
void Search(unsigned long long int id) 
{
	for (auto i : Database)
	{
		for (size_t j=0 ; j < i.Capacity ; j++)
			{
				if (i.Data.at(j).ID == id)
				{
					cout << i.Data.at(j).Firstname ;
					cout << i.Data.at(j).Lastname  ;
					cout << i.Data.at(j).Grade ;
					cout << i.Data.at(j).Birthday.Day << "/" << i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Year ;
				}
			}
	}
	
}
//********************************************************* 
void Search( string Name , string Familyname )
{
	for (auto i : Database)
	{
		for (size_t j=0 ; j < i.Capacity ; j++)
			{
				if (i.Data.at(j).Firstname == Name && i.Data.at(j).Lastname == Familyname)
				{
					cout << i.Data.at(j).ID  ;
					cout << i.Data.at(j).Grade ;
					cout << i.Data.at(j).Birthday.Day << "/" << i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Year ;
				}
			}
	}
}
//********************************************************* 
void ShowClass(string nameclass)
{
	for (auto i : Database)
	{
		if (i.ClassName == currentclass )
		{
			for (size_t j = 0; j < i.Capacity; j++)
			{
				cout << i.Data.at(j).ID    ;
				cout << i.Data.at(j).Grade ;
				cout << i.Data.at(j).Birthday.Day ;
				cout << "/" << i.Data.at(j).Birthday.Month ;
				cout << "/" << i.Data.at(j).Birthday.Year  ;
			}
			
		}
		
	}
	
}
//********************************************************* 
void ShowAll()
{
	for (auto i : Database)
	{
		for (size_t j = 0; j < i.Capacity; j++)
		{
			cout << i.Data.at(j).ID    ;
			cout << i.Data.at(j).Grade ;
			cout << i.Data.at(j).Birthday.Day ;
			cout << "/" << i.Data.at(j).Birthday.Month ;
			cout << "/" << i.Data.at(j).Birthday.Year  ;
		}
	}
}
//********************************************************* 
void SortByName();
//********************************************************* 
void SortByID();
//********************************************************* 
void Save();
//********************************************************* 
void Start()
{
	vector <string> cmdline ;
	string str ;
	string temp ;  
	do{
		getline(cin,str) ;
		for( auto i : str )
		{
			
			if( i != ' ')
			{
				temp += i ;
			}else
			{
				cmdline.push_back(temp) ;
				cout << temp ;
				temp = "" ;
			
			}
		}
		size_t t=0 ;
		/*for (auto i : cmdline)
		{
			cout << cmdline.at(t) ;
			t++ ;
		}
		*/
		cout << endl ;
		cout << cmdline.at(1) ;
		if ( cmdline.at(1) == "select" && cmdline.at(2) == "class" )
		{
			cout<< 6666 ;
			cout<< cmdline[t+=3] ;
			SelectClass( cmdline.at(3));
		}
				
		if ( cmdline.at(1) == "add" && cmdline.at(2) == "class" )
		{
			ddClass(string);
		}

		if ( cmdline.at(1) == "remove" &&  cmdline.at(2) == "class"  )
		{
			RemoveClass(string);
		}

		
		if ( cmdline.at(1)=="select" && cmdline.at(2)=="class" && cmdline.at(3)=="none")
		{
			SelectClass(string);
		}
		
		if ( cmdline.at(1)=="remove" && cmdline.at(2)=="student" )
		{
			RemoveStudent(unsigned long long int);
		}
		
		if ( cmdline.at(1)=="search" )
		{
			Search(unsigned long long int);
			Search(string, string);
		}
		
		if ( cmdline.at(1)=="show") 
		{
			ShowClass(string);
			ShowAll();
		}
		
		if ( cmdline.at(1)=="sort" && cmdline.at(2)=="name" )
		{
			SortByName();
		}
		
		if ( cmdline.at(1)=="sort" && cmdline.at(2)=="id" )
		{
			SortByID();
		}
		
		if ( cmdline.at(1)=="save" )
		{
			Save();
		}
		
		if ( cmdline.at(1)=="help" )
		{
			Help();
		}

	} while ( cmdline.at(0) == "exit") ;
	
}
//******************************************************
int main()
 {
	Start()  ; 
	return 0 ;
 }