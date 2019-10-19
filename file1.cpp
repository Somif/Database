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

vector<Class> Database;
string currentclass ;

void Start()
{
	vector <string> cmdline(4) ;
	cmdline.resize(10);
	string str ;
	string temp ;
	getline(cin,str) ;

	for( auto i : str )
	{
		if( i != ' ')
		{
			temp+=i ;
		}else
		{
			cmdline.push_back(temp) ;
			cout<< temp ;
			temp=' ';
		}
	}
	cout<<cmdline.size();
	cout<<endl ;
	cout<<cmdline.at(0) ;
}

//*********************************************************
void SelectClass(string newclass)
{
 	string currentclass = newclass ;
}
//*********************************************************
void AddClass(string filename)
{
	ifstream classfile ("filename",ios::in)
	class newcls ;
	getline(filename,newcls.ClassName) ;
	cin >> newcls.Average;
	cin >> newcls.Capacity;
	string date ;
	size_t count=0 ;
	string temp[3] ;
	for(size_t j=0 ; j<newcls.Capacity;j++)
	{
		Student newstd ;
		classfile << newstd. Firstname ;
		classfile << newstd. Lastname ;
		classfile << newstd. ID ;	
		classfile << newstd. Grade ;
		classfile << date ;

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
	Database.push_back(Newcls);
}	
//*********************************************************
void RemoveClass(string nameclass)
{
}
//********************************************************* 
void AddStudent(string flname, Date birthday, unsigned long long int id, float gray)
{

}
//********************************************************* 
void RemoveStudent(unsigned long long int id)
{
	for(class &i : Database)
	{
		if(i.ClassName==currentclass)
		{
			for(size_t j=0 ; j< 10;j++)
			{
				if(i.Data.at(j).ID == id)
				{
					i.Data.erase(i.Data.begin()+j)
				}
			}
		}
	}
}
//********************************************************* 
void Search(unsigned long long int);
//********************************************************* 
void Search(string, string);
//********************************************************* 
void ShowClass(string nameclass)
{
	
}
//********************************************************* 
void ShowAll();
//********************************************************* 
void SortByName();
//********************************************************* 
void SortByID();
//********************************************************* 
void Save();
//********************************************************* 
int main()
 {
	Start(); 
	return 0 ;
} 
