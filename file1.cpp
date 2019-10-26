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
 
//******************************************************
void AddClass(string filename)
{
	ifstream classfile (filename.c_str(),ios::in) ; 
	Class newcls ;
	
	getline(classfile,newcls.ClassName) ;
	classfile >> newcls.Capacity;
	string date ;
	
	for( size_t j=0 ; j < newcls.Capacity ; j++)
	{
		cout << j << "    ";
		Student newstd ;
		classfile >> newstd. Firstname ;
		classfile >> newstd. Lastname ;
		classfile >> date ;
		string temp[3] ;
		size_t count = 0 ;
		for( auto i : date )
		{
			if( i != '/')
			{
				temp[count] += i ;
			}else
			{
				count ++ ;
			}
		}
		newstd.Birthday.Day   = stoi (temp[0] ) ;
		newstd.Birthday.Month = stoi ( temp[1]) ;
		newstd.Birthday.Year  = stoi ( temp[2] ); 
		classfile >> newstd. Grade ;
		classfile >> newstd. ID ;
		newcls.Data.push_back(newstd);
	}	
	Database.push_back(newcls);
	classfile.close() ;
}
//********************************************************************************************
void Help()
{
	cout <<" _If you want " << endl ;
	cout << right << setfill(' ') << setw(29) << "add a classfile"          ;
    cout << right << setfill(' ') << setw(29) << "Enter :"<< setfill(' ') << setw(37)<< "basu add class <file Name>"<< endl  ;

    cout << right << setfill(' ') << setw(28) << "remove a class"          ;
    cout << right << setfill(' ') << setw(30) << "Enter :"<< setfill(' ') << setw(40)<< "basu remove class <Class Name>"<< endl  ;

    cout << right << setfill(' ') << setw(28) << "select a class"          ;
    cout << right << setfill(' ') << setw(30) << "Enter :"<< setfill(' ') << setw(40)<< "basu select class <Class Name>"<< endl  ;

    cout << right << setfill(' ') << setw(25) << "select none"          ;
    cout << right << setfill(' ') << setw(33) << "Enter :"<< setfill(' ') << setw(26)<< "basu select none"<< endl  ;

    cout << right << setfill(' ') << setw(28) << "remove student"          ;
    cout << right << setfill(' ') << setw(30) << "Enter :"<< setfill(' ') << setw(34)<< "basu remove student <ID>"<< endl  ;

    cout << right << setfill(' ') << setw(38) << "search a student with ID"          ;
    cout << right << setfill(' ') << setw(20) << "Enter :"<< setfill(' ') << setw(26)<< "basu search <ID>"<< endl  ;

    cout << right << setfill(' ') << setw(45) << "serach a student with Full Name"          ;
    cout << right << setfill(' ') << setw(13) << "Enter :"<< setfill(' ') << setw(33)<< "basu serach <Full Name>"<< endl  ;

    cout << right << setfill(' ') << setw(18) << "show"          ;
    cout << right << setfill(' ') << setw(40) << "Enter :"<< setfill(' ') << setw(19)<< "basu show"<< endl  ;

    cout << right << setfill(' ') << setw(26) << "show a class"          ;
    cout << right << setfill(' ') << setw(32) << "Enter :"<< setfill(' ') << setw(32)<< "basu show <Class Name>"<< endl  ;

    cout << right << setfill(' ') << setw(23) << " sort name"          ;
    cout << right << setfill(' ') << setw(34) << "Enter :"<< setfill(' ') << setw(24)<< "basu sort name"<< endl  ;

    cout << right << setfill(' ') << setw(21) << "sort id"          ;
    cout << right << setfill(' ') << setw(36) << "Enter :"<< setfill(' ') << setw(23)<< "basu  sort id"<< endl  ;

    cout << right << setfill(' ') << setw(18) << "save"          ;
    cout << right << setfill(' ') << setw(38) << "Enter :"<< setfill(' ') << setw(19)<< "basu save"<< endl  ;

    cout << right << setfill(' ') << setw(18) << "exit"          ;
    cout << right << setfill(' ') << setw(40) << "Enter :"<< setfill(' ') << setw(14)<< "exit"<< endl  ;
}
//********************************************************************************************
string currentclass ;
void SelectClass(string nclass)
{
 	currentclass = nclass ;
}	
//********************************************************************************************
void SortByName()
{
	for (auto &b : Database)
	{
		if (b.ClassName == ::currentclass )
		{
			int count = b.Capacity ;
			string temp ;
			for (size_t i = count-1 ; i > 0 ; i--)
			{
				for (int j = 0; j < i; j++)
				{
					if ( b.Data.at(j).Firstname > b.Data.at(j+1).Firstname )
					{
						temp = b.Data.at(j).Firstname ;
						b.Data.at(j).Firstname = b.Data.at(j+1).Firstname ;
						b.Data.at(j+1).Firstname = temp ;
					}
				}	
			}
		}	
	}	
}
//********************************************************************************************
void RemoveClass(string nameclass)
{
	for(Class &i : Database)
	{
		int j =0 ;
		if(i.ClassName == nameclass)
		{
			Database.erase(Database.begin()+j) ;
		}
	}
}
//********************************************************************************************
void AddStudent(string fname,string lname ,string birthday, unsigned long long int id, float gray)
{
	Student newstudent ; 
	string temp[3] ;
	size_t count = 0 ;
	newstudent.Firstname = fname ;
	newstudent.Lastname  = lname ;
	newstudent.ID = id ;
	newstudent.Grade = gray ;
	for ( auto i : birthday )
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
	for (auto &i : Database)
	{
		if (i.ClassName == ::currentclass)
		{
			i.Data.push_back(newstudent) ;
		}
		
	}
}
//********************************************************************************************
void RemoveStudent(unsigned long long int id)
{
	for(Class &i : Database)
	{
		if(i.ClassName == ::currentclass)
		{
			for(size_t j=0 ; j< 10;j++)
			{
				if(i.Data.at(j).ID == id)
				{
					i.Data.erase(i.Data.begin()+j) ;
					i.Capacity -- ;
				}
			}
		}
	}
}
//********************************************************************************************
void Search(unsigned long long int id) 
{
	for (auto i : Database)
	{
		for (size_t j=0 ; j < i.Capacity ; j++)
			{
				if (i.Data.at(j).ID == id)
				{
					cout << i.Data.at(j).Firstname <<"  " ;
					cout << i.Data.at(j).Lastname  << "  " ;
					cout << i.Data.at(j).Grade << "  " ;
					cout << i.Data.at(j).Birthday.Day << "/" << i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Year  << endl ;
				}
			}
	}
	
}
//********************************************************************************************
void Search( string Name , string Familyname )
{
	for (auto i : Database)
	{
		for (size_t j=0 ; j < i.Capacity ; j++)
			{
				if (i.Data.at(j).Firstname == Name && i.Data.at(j).Lastname == Familyname)
				{
					cout << i.Data.at(j).ID  << "  " ;
					cout << i.Data.at(j).Grade  << "  ";
					cout << i.Data.at(j).Birthday.Day << "/" << i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Year  << endl ;
					break ;
				}
			}
	}
}
//********************************************************************************************
void ShowClass(string nameclass) 
{
	for (auto i : Database)
	{
		if (i.ClassName == nameclass )
		{
			for (size_t j = 0; j < i.Capacity; j++)
			{
				cout << i.Data.at(j).Firstname << "  " ;
				cout << i.Data.at(j).Lastname << "  " ;
				cout << i.Data.at(j).ID << "  " ;
				cout << i.Data.at(j).Grade << "  " ;
				cout << i.Data.at(j).Birthday.Day ;
				cout << "/" << i.Data.at(j).Birthday.Month ;
				cout << "/" << i.Data.at(j).Birthday.Year << endl  ;
			}
			
		}
		
	}
}
//******************************************************************************************** 
void ShowClass ()
{
	for (auto i : Database)
	{
		if (i.ClassName == ::currentclass )
		{
			for (size_t j = 0; j < i.Capacity; j++)
			{
				cout << i.Data.at(j).Firstname << "  " ;
				cout << i.Data.at(j).Lastname << "  " ;
				cout << i.Data.at(j).ID << "  " ;
				cout << i.Data.at(j).Grade << "  " ;
				cout << i.Data.at(j).Birthday.Day ;
				cout << "/" << i.Data.at(j).Birthday.Month ;
				cout << "/" << i.Data.at(j).Birthday.Year << endl  ;
			}
			
		}
		
	}
}
//******************************************************************************************** 
void ShowAll()
{
	for (auto i : Database)
	{
		cout << i.ClassName << endl ;
		for (size_t j = 0; j < i.Capacity; j++)
		{
			cout << i.Data.at(j).Firstname  << "  " ;
			cout << i.Data.at(j).Lastname << "  " ;
			cout << i.Data.at(j).ID  << "  "   ;
			cout << i.Data.at(j).Grade <<"  ";
			cout << i.Data.at(j).Birthday.Day ;
			cout << "/" << i.Data.at(j).Birthday.Month ;
			cout << "/" << i.Data.at(j).Birthday.Year << endl  ;
		}
	}
}
//********************************************************************************************
void SortByID()
{
	for (auto &b : Database)
	{
		if (b.ClassName == ::currentclass )
		{
			unsigned long long int temp ;
			for (int i = (b.Capacity)-1 ; i > 0 ; i--)
			{
				for (int j = 0; j < i; j++)
				{
					if ( b.Data.at(j).ID > b.Data.at(j+1).ID )
					{
						temp = b.Data.at(j).ID ;
						b.Data.at(j).ID = b.Data.at(j+1).ID ;
						b.Data.at(j+1).ID = temp ;
					}
				}
				
			}
		}
	}
}
//********************************************************************************************
void Save()
{
	 for (auto &i : Database )
    {
		if (i.ClassName == "Advanced_Programming" )
        {
            ofstream savefile ("l1(1).basu",ios::out) ;
			savefile << "Advanced_Programming"  << endl ;
			savefile << i.Capacity  << endl ;
			for (size_t j = 0; j < i.Capacity; j++)
		    {
				savefile << i.Data.at(j).Firstname  << "  " ;
				savefile << i.Data.at(j).Lastname << "  " ;
				savefile << i.Data.at(j).ID  << "  "   ;
				savefile << i.Data.at(j).Grade <<"  ";
				savefile << i.Data.at(j).Birthday.Day ;
				savefile << "/" << i.Data.at(j).Birthday.Month ;
				savefile << "/" << i.Data.at(j).Birthday.Year << endl  ;
		    }
			savefile.close();
        }
		if (i.ClassName == "Logic_Circuits" )
        {
            ofstream savefile ("l2(1).basu",ios::out) ;
			savefile << "Logic_Circuits"  << endl ;
			savefile << i.Capacity  << endl ;
			for (size_t j = 0; j < i.Capacity; j++)
		    {
				savefile << i.Data.at(j).Firstname  << "  " ;
				savefile << i.Data.at(j).Lastname << "  " ;
				savefile << i.Data.at(j).ID  << "  "   ;
				savefile << i.Data.at(j).Grade <<"  ";
				savefile << i.Data.at(j).Birthday.Day ;
				savefile << "/" << i.Data.at(j).Birthday.Month ;
				savefile << "/" << i.Data.at(j).Birthday.Year << endl  ;
		    }
			savefile.close();
        }
		if (i.ClassName == "Discrete_Mathematics" )
        {
            ofstream savefile ("l3(1).basu",ios::out) ;
			savefile << "Discrete_Mathematics"  << endl ;
			savefile << i.Capacity  << endl ;
			for (size_t j = 0; j < i.Capacity; j++)
		    {
				savefile << i.Data.at(j).Firstname  << "  " ;
				savefile << i.Data.at(j).Lastname << "  " ;
				savefile << i.Data.at(j).ID  << "  "   ;
				savefile << i.Data.at(j).Grade <<"  ";
				savefile << i.Data.at(j).Birthday.Day ;
				savefile << "/" << i.Data.at(j).Birthday.Month ;
				savefile << "/" << i.Data.at(j).Birthday.Year << endl  ;
		    }
			savefile.close();
        }
        if (i.ClassName == "Data_Structure" )
        {
            ofstream savefile ("l4(1).basu",ios::out) ;
			savefile << "Data_Structure"  << endl ;
			savefile << i.Capacity  << endl ;
			for (size_t j = 0; j < i.Capacity; j++)
		    {
				savefile << i.Data.at(j).Firstname  << "  " ;
				savefile << i.Data.at(j).Lastname << "  " ;
				savefile << i.Data.at(j).ID  << "  "   ;
				savefile << i.Data.at(j).Grade <<"  ";
				savefile << i.Data.at(j).Birthday.Day ;
				savefile << "/" << i.Data.at(j).Birthday.Month ;
				savefile << "/" << i.Data.at(j).Birthday.Year << endl  ;
		    }
			savefile.close();
        }
        if (i.ClassName == "Artificial_Intelligence" )
        {
            ofstream savefile ("l5(1).basu",ios::out) ;
			savefile << "Artificial_Intelligence"  << endl ;
			savefile << i.Capacity  << endl ;
			for (size_t j = 0; j < i.Capacity; j++)
		    {
				savefile << i.Data.at(j).Firstname  << "  " ;
				savefile << i.Data.at(j).Lastname << "  " ;
				savefile << i.Data.at(j).ID  << "  "   ;
				savefile << i.Data.at(j).Grade <<"  ";
				savefile << i.Data.at(j).Birthday.Day ;
				savefile << "/" << i.Data.at(j).Birthday.Month ;
				savefile << "/" << i.Data.at(j).Birthday.Year << endl  ;
		    }
			savefile.close();
        }
    }
}
//******************************************************************************************** 
void Start()
{
	vector <string> cmdline ;
	string str ;
	string temp ;  
	do{
		cout << endl << "Database >> " ;
		getline(cin,str) ;
		for( auto i : str )
		{
			if( i != ' ')
			{
				temp += i ;
			}else
			{
				cmdline.push_back(temp) ;
				temp = "" ;
			
			}
		}
		cmdline.push_back(temp) ;
		temp = "" ;
		cout << endl ;
		if ( cmdline.at(1) == "select" && cmdline.at(2) == "class" )
		{
			SelectClass( cmdline.at(3) );
		}
				
		if ( cmdline.at(1) == "add" && cmdline.at(2) == "class" )
		{
			AddClass( cmdline.at(3) );
		}

		if ( cmdline.at(1) == "remove" &&  cmdline.at(2) == "class"  )
		{
			RemoveClass( cmdline.at(3) );
		}

		
		if ( cmdline.at(1)=="select" && cmdline.at(2)=="class" && cmdline.at(3)=="none")
		{
			SelectClass( cmdline.at(3) );
		}
		
		if ( cmdline.at(1)=="remove" && cmdline.at(2)=="student" )
		{
		    RemoveStudent( stoull(cmdline.at(3)) );
		}
		
		if ( cmdline.at(1)=="add" && cmdline.at(2)=="student" )
		{
		    AddStudent( cmdline.at(3),cmdline.at(4),cmdline.at(5) ,stoull(cmdline.at(6)),stof(cmdline.at(7)) );
		}

		if ( cmdline.at(1)=="search" )
		{
			if ( cmdline.size()== 3 )
			{
				Search( stoull ( cmdline.at(2) ) );
			}
			if (cmdline.size() == 4)
			{
				Search( cmdline.at(2),cmdline.at(3) );
			}
		}
		
		if ( cmdline.at(1)=="show") 
		{
			if (cmdline.size() == 3)
			{
				if ( cmdline.at(2) == "all")
				{
					ShowAll() ;
				}
				if (cmdline.at(2) == "class")
				{
					ShowClass();
				}
			}
			if (cmdline.size() == 4)
			{
				ShowClass( cmdline.at(3)) ;
			}
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
		if ( cmdline.at(0) == "exit")
		{
			cout << "bye" ;
			break ;
		}
		cmdline.clear() ;
	} while ( true) ;
	cout << "bye" ;
}
//******************************************************
int main()
 {
	Start()  ; 
	return 0 ;
 }