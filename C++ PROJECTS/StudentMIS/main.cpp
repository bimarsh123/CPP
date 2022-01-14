/*
Student Name :Bimarsh Khatri
Student ID:20170903
project 7:Student management and information system

*/
#include <iostream>
#include <fstream>
#include "student.h"
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

#include "sdw.h" //to a set font color

using namespace std;

void showMenu();
void selection();

//load data from file
bool LoadData();
void ShowData();
bool LoadDefaultData();
bool SaveDataToFile();
bool ClearData();

void CheckData();

void ShowNotice();
void ShowTitle();
void Search();

string ToLower(string s);

void AddStudent();
bool ModifyStudent();
bool DeleteStudent();
bool DeletebyName();
double toDouble(string str);

void SortByStuNo();
void SortByStuName();
void SortByStuGender();
void SortByStuPhone();
void SortByStuWechat();
void SortByStuDormitory();
void SortByStuScore();
void StatisticsData();
void ShowSelectedData();


bool ComStuNo_Asc(const Student &a, const Student &b);
bool ComStuNo_Desc(const Student &a, const Student &b);
bool ComStuName_Asc(const Student &a, const Student &b);
bool ComStuName_Desc(const Student &a, const Student &b);
bool ComStuGender_Asc(const Student &a, const Student &b);
bool ComStuGender_Desc(const Student &a, const Student &b);
bool ComStuPhone_Asc(const Student &a, const Student &b);
bool ComStuPhone_Desc(const Student &a, const Student &b);
bool ComStuWechat_Asc(const Student &a, const Student &b);
bool ComStuWechat_Desc(const Student &a, const Student &b);
bool ComStuDormitory_Asc(const Student &a, const Student &b);
bool ComStuDormitory_Desc(const Student &a, const Student &b);
bool ComStuScore_Asc(const Student &a, const Student &b);
bool ComStuScore_Desc(const Student &a, const Student &b);


vector<Student> STU;

int main(int argc, char *argv[])
{


	int choice=1;
	LoadDefaultData();
	do
	{
		showMenu(); //show the menu

		cout<<"\n\tPlease choose:";

   	    cin.sync();

		while (!(cin >> choice))
	    {
	        cin.clear();
	        cin.sync();
	        cout<<"Invalid. Please choose again:";
	    }

		cin.sync();

	   switch(choice)
	    {
		    case 1:
		    	 LoadData();
				 break;

		    case 2:
				ShowData();
				break;

		    case 3:
		    	Search();
				break;

		    case 4:
      			AddStudent();
		        break;

		    case 5:
      			ModifyStudent();
		        break;

		    case 6:
      			DeleteStudent();
		        break;

		    case 7:
      			SortByStuNo();
		        break;

		    case 8:
      			SortByStuName();;
		        break;

		    case 9:
      			SortByStuGender();
		        break;

		    case 10:
      			SortByStuPhone();
		        break;

		    case 11:
      			SortByStuWechat();
		        break;

		    case 12:
      			SortByStuDormitory();
		        break;

		    case 13:
      			SortByStuScore();
		        break;

		    case 14:
      			StatisticsData();
		        break;

		    case 15:
		    	ClearData();
		        break;

		    case 16:
      			SaveDataToFile();
		        break;

		    case 17:
      			ShowSelectedData();
		        break;

	    }
	    if(choice!=18)
	    {

    		selection();
    	}

	}while(choice!=18);

	return 0;
}

void  showMenu()
{

	   cout<<endl;
cout<<"\t\t-------------------- C++ programming --------------------"<<endl;
cout<<endl;
cout<<"\t\t********************* Students MIS **********************"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t$   1.Load Data                 2.Show All Students     $"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t$   3.Search Student            4.Add Student           $"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t$   5.Modify Student            6.Delete Student        $"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t$   7.Sort by Std no.           8.Sort by Name          $"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t$   9.Sort by Gender            10.Sort by Phone        $"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t$   11.Sort by WeChat           12.Sort by Dormitory    $"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t$   13.Sort by Score            14.Statistics Data      $"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t$   15.Clear Data               16.Save Data to File    $"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t$   17.Show Selected Data       18.Exit                 $"<<endl;
cout<<"\t\t$                                                       $"<<endl;
cout<<"\t\t******************* CopyRight@Bimarsh *******************"<<endl;
cout<<endl;
}

void selection()
{
	char choice;
	cin.sync();

	cout<<"\n\tPRESS ANY KEY TO RETURN TO THE MENU.";
	choice = cin.get();


	cout<<"\n\n";
}

// to determine if there is data in the current system.
void CheckData()
{
	if(STU.size()==0)
	{
		LoadData();
	}
}

bool LoadData()
{
	ShowNotice();
	string fileName="";
	if(STU.size()==0)
	{
		cout<<"\n\tThere is no data in the Students Management Information System.";
	}
	cout<<"\n\tPress ENTER to load default file(student_data.txt), or input a file name:";
	cin.sync();

	fstream infile;

	//returns the next character in the stream or EOF if the end of file is read.
	//peek() does not remove the character from the stream.
	// If the user press ENTER key directly, then fileName gets default value.
	while( (cin.peek()=='\n') ||(cin>>fileName) )
	{
		if( fileName=="" ) fileName="student_data.txt";  //press ENTER key
		if( strcmp(fileName.c_str(),"000")==0 )
		{
			return false;
		}

		infile.open(fileName.c_str());
		if(!infile)
		{
			cout<<"\n\tFile "<<fileName<<" opened failed."<<endl;
			cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
			infile.clear();
			cin.sync(); 	// clear the cin buffer
			fileName=""; 	// restore the default value
		}
		else
		{
			cout<<"\n\tFile "<<fileName<<" opened success."<<endl;
			break;
		}
	}

	string stuNo,stuName,stuPhone,stuWechat,stuDormitory;
	char stuGender;
	double stuScore;
	STU.clear(); //removes all elements

	// Remove the header field from the first line of the file
	// before you can start reading the data
	char removeLine[1024];
	infile.getline(removeLine,1024,'\n');


	while(!infile.eof())
	{
		infile>>stuNo;
		infile>>stuName;
		infile>>stuGender;
		infile>>stuPhone;
		infile>>stuWechat;
		infile>>stuDormitory;
		infile>>stuScore;
		if(stuNo!="")
		{
			Student s(stuNo,stuName,stuGender,stuPhone,stuWechat,stuDormitory,stuScore);
			STU.push_back(s);
		}
	}
	infile.close();
	cout<<"\n\tThere are "<<STU.size()<<" students imported."<<endl;
	return true;
}

bool LoadDefaultData()
{
	string fileName="stu.txt";

	fstream infile;


    infile.open(fileName.c_str());
	if(!infile)
	{
		return false;
	}

	string stuNo,stuName,stuPhone,stuWechat,stuDormitory;
	char stuGender;
	double stuScore;
	STU.clear(); //removes all elements

	// Remove the header field from the first line of the file
	// before you can start reading the data
	char removeLine[1024];
	infile.getline(removeLine,1024,'\n');


	while(!infile.eof())
	{
		infile>>stuNo;
		infile>>stuName;
		infile>>stuGender;
		infile>>stuPhone;
		infile>>stuWechat;
		infile>>stuDormitory;
		infile>>stuScore;
		if(strcmp(stuNo.c_str(),"")!=0)
		{
			Student s(stuNo,stuName,stuGender,stuPhone,stuWechat,stuDormitory,stuScore);
			STU.push_back(s);
		}
	}
	infile.close();
	return true;
}


void ShowTitle()
{
	setGreenonBlack();
	cout<<"StuNo.    Name          Gender\t  Phone\t     WeChat\tDormitory  Score"<<endl;
	setWhiteonBlack();
}

void ShowData()
{
	CheckData();

	ShowTitle();

	vector<Student>::iterator it;

	int k=0;
	for( it = STU.begin(); it != STU.end(); it++ )
	{
		  cout<<*it;
		  k++;
		  if(k%20==0)
		  {
  			//getchar();
  		  }
	}
 }

void ShowSelectedData()
{
	CheckData();

	vector<Student>::iterator it;

	int a[8]={0};
	setGreenonBlack();
	cout<<"\n\tPress ENTER to SHOW the data field, others to HIDE it:";
	setWhiteonBlack();

	cout<<"\n\n\tShow or Hide the Student Number: ";
	cin.sync();
	if( cin.peek()=='\n') a[1]=1;

	cout<<"\n\tShow or Hide the Name: ";
	cin.sync();
	if( cin.peek()=='\n') a[2]=1;

	cout<<"\n\tShow or Hide the Gender: ";
	cin.sync();
	if( cin.peek()=='\n') a[3]=1;

	cout<<"\n\tShow or Hide the Phone: ";
	cin.sync();
	if( cin.peek()=='\n') a[4]=1;

	cout<<"\n\tShow or Hide the Wechat: ";
	cin.sync();
	if( cin.peek()=='\n') a[5]=1;

	cout<<"\n\tShow or Hide the Dormitory: ";
	cin.sync();
	if( cin.peek()=='\n') a[6]=1;

	cout<<"\n\tShow or Hide the Score: ";
	cin.sync();
	if( cin.peek()=='\n') a[7]=1;

	cout<<endl;

	setGreenonBlack();
	if( a[1] )
	{
		cout<<setw(8)<<"  StuNo.  "<<"  ";
	}
	if( a[2] )
	{
		cout<<setw(12)<<"  Name   "<<"  ";
	}
	if( a[3] )
	{
		cout<<setw(2)<<"Gender"<<" ";
	}
	if( a[4] )
	{
		cout<<setw(8)<<"   Phone"<<"  ";
	}
	if( a[5] )
	{
		cout<<setw(8)<<"    WeChat  "<<" ";
	}
	if( a[6] )
	{
		cout<<setw(10)<<"Dormitory"<<"  ";
	}
	if( a[7] )
	{
		cout<<setw(4)<<"Score";
	}
	cout<<endl;

	setWhiteonBlack();




	for( it = STU.begin(); it != STU.end(); it++ )
	{
		if( a[1] )
		{
			cout<<setw(8)<< it->getNo()<<"  ";
		}
		if( a[2] )
		{
			cout<<setw(12) << it->getName()<<"  ";
		}
		if( a[3] )
		{
			cout<<setw(6) << it->getGender()<<"  ";
		}
		if( a[4] )
		{
			cout<<setw(11) << it->getPhone()<<"  ";
		}
		if( a[5] )
		{
			cout<<setw(8) << it->getWechat()<<"  ";
		}
		if( a[6] )
		{
			cout<<setw(10) << it->getDormitory()<<"  ";
		}
		if( a[7] )
		{
			cout<<setw(4)<< it->getScore();
		}
		cout<<endl;
	}
}
bool ClearData()
{
	setGreenonBlack();
	cout<<"\n\tAll the "<<STU.size()<<" data has bee cleared."<<endl;
	setWhiteonBlack();

	STU.clear();
	return true;

}

bool SaveDataToFile()
{
	ShowNotice();
	string fileName="";
	if(STU.size()==0)
	{
		cout<<"\n\tThere is no data in the Students Management Information System.";
		return false;
	}

	cout<<"\n\tPress ENTER to save data to stu_out.txt, or input a file name:";
	cin.sync();

	fstream outfile;

	//returns the next character in the stream or EOF if the end of file is read.
	//peek() does not remove the character from the stream.
	// If the user press ENTER key directly, then fileName gets default value.
	while( (cin.peek()=='\n') ||(cin>>fileName) )
	{
		if( fileName=="" ) fileName="stu_out.txt";  //press ENTER key
		if( strcmp(fileName.c_str(),"000")==0 )
		{
			return false;
		}
		outfile.open(fileName.c_str(),ios::out|ios::trunc);
		if(!outfile)
		{
			cout<<"\n\tFile "<<fileName<<" opened failed."<<endl;
			cout<<"\n\tPress ENTER to save data to stu_out.txt, or input a file name:";

			outfile.clear();
			cin.sync();
			fileName=""; 	// restore the default value
		}
		else
		{
			cout<<"\n\tFile "<<fileName<<" opened success."<<endl;
			break;
		}
	}

	string stuNo,stuName,stuPhone,stuWechat,stuDormitory;
	char stuGender;
	double stuScore;

	vector<Student>::iterator it;
	outfile<<setw(8)<<" StuNo. \t"<<setw(12)<<"   Name     \t"
		<<setw(2)<<"Gender \t"<<setw(11)<<"Phone\t"<<setw(8)<<"  WeChat\t"
		<<setw(10)<<"  Dormitory\t"<<setw(2)<<"Score"<<endl;

	for(it=STU.begin();it!=STU.end();it++)
	{
		outfile <<setw(8)<< (*it).getNo()<<"\t";
		outfile <<setw(12)<< (*it).getName()<<"\t";
		outfile <<setw(2)<< (*it).getGender()<<"\t";
		outfile <<setw(11)<< (*it).getPhone()<<"\t";
		outfile <<setw(8)<< it->getWechat()<<"\t";
		outfile <<setw(10)<< it->getDormitory()<<"\t";
		outfile <<setw(2)<< it->getScore();
		outfile << endl;
	}
	outfile.close();
	cout<<"\n\tThere are "<<STU.size()<<" students saved to file: "<<fileName<<"."<<endl;
	return true;
}

string ToLower(string s)
{
	int i=0;
	for(i=0;i<s.length();i++)
	{
		s[i]=tolower(s[i]);
	}
	return s;
}

void ShowNotice()
{
	setRedonBlack();
	cout<<"\n\tNOTICE: Input 000 to Return to the Menu."<<endl;
	setWhiteonBlack();
}

bool ComStuNo_Asc(const Student &a, const Student &b)
{
	if( strcmp(a.getNo().c_str(),b.getNo().c_str())<0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuNo_Desc(const Student &a, const Student &b)
{
	if( strcmp(a.getNo().c_str(),b.getNo().c_str())>0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuName_Asc(const Student &a, const Student &b)
{
	if( strcmp(a.getName().c_str(),b.getName().c_str())<0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuName_Desc(const Student &a, const Student &b)
{
	if( strcmp(a.getName().c_str(),b.getName().c_str())>0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuPhone_Asc(const Student &a, const Student &b)
{
	if( strcmp(a.getPhone().c_str(),b.getPhone().c_str())<0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuPhone_Desc(const Student &a, const Student &b)
{
	if( strcmp(a.getPhone().c_str(),b.getPhone().c_str())>0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuWechat_Asc(const Student &a, const Student &b)
{
	if( strcmp(a.getWechat().c_str(),b.getWechat().c_str())<0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuWechat_Desc(const Student &a, const Student &b)
{
	if( strcmp(a.getWechat().c_str(),b.getWechat().c_str())>0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuDormitory_Asc(const Student &a, const Student &b)
{
	if( strcmp(a.getDormitory().c_str(),b.getDormitory().c_str())<0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuDormitory_Desc(const Student &a, const Student &b)
{
	if( strcmp(a.getDormitory().c_str(),b.getDormitory().c_str())>0 )
	{
		return true;
	}
	else
		return false;
}

bool ComStuGender_Asc(const Student &a, const Student &b)
{
	if( a.getGender()<b.getGender())
	{
		return true;
	}
	else
		return false;
}

bool ComStuGender_Desc(const Student &a, const Student &b)
{
	if( a.getGender()>b.getGender())
	{
		return true;
	}
	else
		return false;
}

bool ComStuScore_Asc(const Student &a, const Student &b)
{
	if( a.getScore()<b.getScore() )
	{
		return true;
	}
	else
		return false;
}

bool ComStuScore_Desc(const Student &a, const Student &b)
{
	if( a.getScore()>b.getScore() )
	{
		return true;
	}
	else
		return false;
}


void SortByStuNo()
{
	CheckData();

	cout<<"\n\tTo sort the students by their student Numbers."<<endl;
	cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order: ";
	char c;
	cin.sync();

	if( cin.peek()=='\n' )
	{
		sort(STU.begin(),STU.end(),ComStuNo_Asc);
	}
	else
	{
		sort(STU.begin(),STU.end(),ComStuNo_Desc);
	}

	cin.sync();

	ShowTitle();
	vector<Student>::iterator it;
	for(it=STU.begin();it!=STU.end();it++)
	{
		cout<<*it;
	}
}


void SortByStuName()
{
	CheckData();

	cout<<"\n\tTo sort the students by their names."<<endl;
	cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order: ";
	char c;
	cin.sync();

	if( cin.peek()=='\n' )
	{
		sort(STU.begin(),STU.end(),ComStuName_Asc);
	}
	else
	{
		sort(STU.begin(),STU.end(),ComStuName_Desc);
	}

	cin.sync();

	ShowTitle();
	vector<Student>::iterator it;
	for(it=STU.begin();it!=STU.end();it++)
	{
		cout<<*it;
	}
}


void SortByStuPhone()
{
	CheckData();

	cout<<"\n\tTo sort the students by their Phones."<<endl;
	cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order: ";
	char c;
	cin.sync();

	if( cin.peek()=='\n' )
	{
		sort(STU.begin(),STU.end(),ComStuPhone_Asc);
	}
	else
	{
		sort(STU.begin(),STU.end(),ComStuPhone_Desc);
	}

	cin.sync();

	ShowTitle();
	vector<Student>::iterator it;
	for(it=STU.begin();it!=STU.end();it++)
	{
		cout<<*it;
	}
}


void SortByStuWechat()
{
	CheckData();

	cout<<"\n\tTo sort the students by their Wechats."<<endl;
	cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order: ";
	char c;
	cin.sync();

	if( cin.peek()=='\n' )
	{
		sort(STU.begin(),STU.end(),ComStuWechat_Asc);
	}
	else
	{
		sort(STU.begin(),STU.end(),ComStuWechat_Desc);
	}

	cin.sync();

	ShowTitle();
	vector<Student>::iterator it;
	for(it=STU.begin();it!=STU.end();it++)
	{
		cout<<*it;
	}
}


void SortByStuDormitory()
{
	CheckData();

	cout<<"\n\tTo sort the students by their Dormitory."<<endl;
	cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order: ";
	char c;
	cin.sync();

	if( cin.peek()=='\n' )
	{
		sort(STU.begin(),STU.end(),ComStuDormitory_Asc);
	}
	else
	{
		sort(STU.begin(),STU.end(),ComStuDormitory_Desc);
	}

	cin.sync();

	ShowTitle();
	vector<Student>::iterator it;
	for(it=STU.begin();it!=STU.end();it++)
	{
		cout<<*it;
	}
}


void SortByStuScore()
{
	CheckData();

	cout<<"\n\tTo sort the students by their Scores."<<endl;
	cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order: ";
	char c;
	cin.sync();

	if( cin.peek()=='\n' )
	{
		sort(STU.begin(),STU.end(),ComStuScore_Asc);
	}
	else
	{
		sort(STU.begin(),STU.end(),ComStuScore_Desc);
	}

	cin.sync();

	ShowTitle();
	vector<Student>::iterator it;
	for(it=STU.begin();it!=STU.end();it++)
	{
		cout<<*it;
	}
}


void SortByStuGender()
{
	CheckData();

	cout<<"\n\tTo sort the students by their Genders."<<endl;
	cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order: ";
	char c;
	cin.sync();

	if( cin.peek()=='\n' )
	{
		sort(STU.begin(),STU.end(),ComStuGender_Asc);
	}
	else
	{
		sort(STU.begin(),STU.end(),ComStuGender_Desc);
	}

	cin.sync();

	ShowTitle();
	vector<Student>::iterator it;
	for(it=STU.begin();it!=STU.end();it++)
	{
		cout<<*it;
	}
}

void StatisticsData()
{
	CheckData();
	int student=0,male=0,female=0;
	double MaxScore=-1,MinScore=10000,TotalScore=0;
	vector<Student> maxStu,minStu;

	student=STU.size();

	vector<Student>::iterator it;
	for(it=STU.begin();it!=STU.end();it++)
	{
		if( it->getGender()=='M' )
		{
			male++;
		}
		else
		{
			female++;
		}

		TotalScore += it->getScore();

		if( MaxScore < it->getScore())
		{
			MaxScore = it->getScore();
		}

		if( MinScore > it->getScore() )
		{
			MinScore = it->getScore();
		}
	}

	for(it=STU.begin();it!=STU.end();it++)
	{
		if( it->getScore()== MaxScore )
		{
			maxStu.push_back(*it);
		}
		if( it->getScore()== MinScore )
		{
			minStu.push_back(*it);
		}
	}


	cout<<"\n\tThe Statistics Data of the Students are as follow:"<<endl;

	cout<<"\n\tStudents: "<<student;
	cout<<"\n\t    Male: "<<male;
	cout<<"\n\t  Female: "<<female;
	cout<<"\n\tMaxScore: "<<MaxScore;
	cout<<"\n\tMinScore: "<<MinScore;
	cout<<"\n\tAvgScore: "<<TotalScore/student;

	cout<<"\n\n\tThe Information of the MaxScore Students is : \n"<<endl;
	ShowTitle();
	for(it=maxStu.begin();it!=maxStu.end();it++)
	{
		cout<<*it;
	}

	cout<<"\n\n\tThe Information of the MinScore Students is : \n"<<endl;
	ShowTitle();
	for(it=minStu.begin();it!=minStu.end();it++)
	{
		cout<<*it;
	}

}

void AddStudent()
{
	string stuNo,stuName,stuPhone,stuWechat,stuDormitory;
	char stuGender;
	double stuScore;

	while(1)
	{
		ShowNotice();
		cout<<"\n\tInput student No.: ";
		cin.sync();
		cin>>stuNo;

		if(strcmp(stuNo.c_str(),"000")==0)
		{
			break;
		}

		cout<<"\n\tInput student Name: ";
		cin.sync();
		cin>>stuName;

		cout<<"\n\tInput student Gender(M/F): ";
		cin.sync();

		while( (cin>>stuGender)&&(stuGender!='M')&&(stuGender!='m')
			&&(stuGender!='F')&&(stuGender!='f') )
		{
			cout<<stuGender<<endl;
			cin.clear();
			cin.sync();
			cout<<"\n\tInvalid. Please input 'M' or 'F':";
		}

		cout<<"\n\tInput student Phone: ";
		cin.sync();
		cin>>stuPhone;

		cout<<"\n\tInput student WeChat: ";
		cin.sync();
		cin>>stuWechat;

		cout<<"\n\tInput student Dormitory: ";
		cin.sync();
		cin>>stuDormitory;

		cout<<"\n\tInput student Score: ";
		while( !(cin>>stuScore) || (stuScore<0) )
		{
			cin.clear();
			cin.sync();
			cout<<"\n\tInvalid. Please input a positive number:";
		}

		Student s(stuNo,stuName,toupper(stuGender),stuPhone,stuWechat,stuDormitory,stuScore);
		STU.push_back(s);

		cout<<"\n\tA student has been added."<<endl;
		cout<<s<<endl;
	}
}

double toDouble(string str)
{
	istringstream iStr(str);
	double data;

	iStr>>data;

	return data;
}

bool ModifyStudent()
{
	CheckData();

	int choice=1;
	while(choice!=0)
	{
		vector<Student> stu;
		vector<Student>::iterator it;
		int k=0;

		do
		{
			char sTmp[1024]={'\0'};

			ShowNotice();

			while(sTmp[0]=='\0')
			{
				cout<<"\n\tTo modify students, we need to find them first.";
				cout<<"\n\tPlease input information of the students to be changed:";
				cin.sync();
				cin.getline(sTmp,1024,'\n');
			}

			if( strcmp(sTmp,"000")==0 )
			{
				choice=0;
				break;
			}


			cout<<endl;

			ShowTitle();

			char gender='\0';
			if( ToLower(sTmp) == "m" ||  ToLower(sTmp) == "male"  )
			{
				gender='M';
			}

			if( ToLower(sTmp) == "f" ||  ToLower(sTmp) == "female"  )
			{
				gender='F';
			}


			for( it = STU.begin(); it != STU.end(); it++ )
			{
				if( ToLower(it->getNo())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( ToLower(it->getName())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( ToLower(it->getPhone())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( ToLower(it->getWechat())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( ToLower(it->getDormitory())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( tolower(it->getGender())==tolower(gender) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( it->getScore()==toDouble(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
			}
			if(k)
			{
				cout<<"\n\tThere are "<<k<<" students with \""<<sTmp<<"\"."<<endl;
			}
			else
			{
				cout<<"\n\tThere is no student with \""<<sTmp<<"\"."<<endl;
			}
		}while(k==0);

		if(choice==0)
		{
			break;
		}

		cout<<"\n\tPress ENTER to modify all or input the StudentNo.:";

		char stuGender='\0';
		double stuScore= -1;
		char stuNo[1024]={'\0'};
		char stuName[1024]={'\0'};
		char stuPhone[1024]={'\0'};
		char stuWechat[1024]={'\0'};
		char stuDormitory[1024]={'\0'};
		int flag=0;
		string strTmp;

		cin.sync();
		if( cin.peek()=='\n')
		{
			cout<<"\n\tYou are going to change all the above students. ";
			cout<<"Input the information to be changed. If make no change, press the ENTER key."<<endl;

			cout<<"\n\tInput a new student No.: ";
			cin.sync();
			if( cin.peek()=='\n') stuNo[0]='\0';
			else cin.getline(stuNo,1024,'\n');
			flag=0; //change all the above students
		}
		else
		{
			while(!flag)
			{
				cin.getline(stuNo,1024,'\n');
	 			for( it = STU.begin(); it != STU.end(); it++ )
				{
					if(it->getNo()==stuNo)
					{
						flag++;  //change only students with stuNo
						cout<<"\n\tYou are going to change the students with StudentNo.: "<<stuNo<<". ";
						cout<<"Input the information to be changed. If make no change, press the ENTER key."<<endl;
						break;
					}
				}

				if(flag==0)
				{
					cout<<"\n\tThere is no student with StudentNo.: "<<stuNo<<endl;
					cout<<"\n\tPlease input a StudentNo. again: ";
				}
			}

			strTmp=stuNo;
			cout<<"\n\tInput a new student No.: ";
			cin.sync();
			if( cin.peek()=='\n') flag=1;// no change
			else cin.getline(stuNo,1024,'\n');
		}


		cout<<"\n\tInput student Name: ";
		cin.sync();
		if( cin.peek()=='\n') stuName[0]='\0';
		else cin.getline(stuName,1024,'\n');

		cout<<"\n\tInput student Gender(M/F): ";
		cin.sync();
		if( cin.peek()=='\n') stuGender='\0';
		else
		{
			while( (cin>>stuGender)&&(stuGender!='M')&&(stuGender!='m')
				&&(stuGender!='F')&&(stuGender!='f') )
			{

				cin.clear();
				cin.sync();
				cout<<"\n\tInvalid. Please input 'M' or 'F':";
			}
		}

		cout<<"\n\tInput student Phone: ";
		cin.sync();
		if( cin.peek()=='\n') stuPhone[0]='\0';
		else cin.getline(stuPhone,1024,'\n');

		cout<<"\n\tInput student WeChat: ";
		cin.sync();
		if( cin.peek()=='\n') stuWechat[0]='\0';
		else cin.getline(stuWechat,1024,'\n');

		cout<<"\n\tInput student Dormitory: ";
		cin.sync();
		if( cin.peek()=='\n') stuDormitory[0]='\0';
		else cin.getline(stuDormitory,1024,'\n');

		cout<<"\n\tInput student Score: ";
		cin.sync();
		if( cin.peek()=='\n') stuScore=-1;
		else
		{
			while( !(cin>>stuScore) || (stuScore<0) )
			{
				cin.clear();
				cin.sync();
				cout<<"\n\tInvalid. Please input a positive number:";
			}
		}

		if( flag>=1 ) //change only one
		{
			for( it = STU.begin(); it != STU.end(); it++ )
			{
				if( it->getNo()==strTmp ) //the Student No. before
				{
					flag=1;
					if( stuNo[0]!='\0' )
					{
						it->setNo(stuNo);
					}
					if( stuName[0]!='\0' )
					{
						it->setName(stuName);
					}
					if( stuPhone[0]!='\0' )
					{
						it->setPhone(stuPhone);
					}
					if( stuWechat[0]!='\0' )
					{
						it->setWechat(stuWechat);
					}
					if( stuDormitory[0]!='\0')
					{
						it->setDormitory(stuDormitory);
					}
					if( stuGender!='\0' )
					{
						it->setGender(toupper(stuGender));
					}
					if( stuScore!=-1 )
					{
						it->setScore(stuScore);
					}
					cout<<*it;
				}

			}

			if(flag>0)
			{
				cout<<"\n\tThe student with StudentNo.: "<<stuNo<<" has been changed."<<endl;
			}
		}
		else
		{
			flag=0;
			for( it = stu.begin(); it != stu.end(); it++ )
			{
				strTmp=it->getNo();

				if( stuNo[0]!='\0' )
				{
					flag=1;
					it->setNo(stuNo);
				}
				if( stuName[0]!='\0' )
				{
					flag=1;
					it->setName(stuName);
				}
				if( stuPhone[0]!='\0' )
				{
					flag=1;
					it->setPhone(stuPhone);
				}
				if( stuWechat[0]!='\0' )
				{
					flag=1;
					it->setWechat(stuWechat);
				}
				if( stuDormitory[0]!='\0')
				{
					flag=1;
					it->setDormitory(stuDormitory);
				}
				if( stuGender!='\0' )
				{
					flag=1;
					it->setGender(toupper(stuGender));
				}
				if( stuScore!=-1 )
				{
					flag=1;
					it->setScore(stuScore);
				}
				if(flag==0)//no change
				{
					k--;
				}
				else
				{
					vector<Student>::iterator itStu;
					for(itStu=STU.begin();itStu!=STU.end();itStu++)
					{
						if( itStu->getNo()==strTmp )
						{
							*itStu=*it;
						}
					}
					cout<<*it;
				}
			}

			cout<<"\n\tThere are "<<k<<" students changed."<<endl;

		}
	}

	return true;
}

bool DeleteStudent()
{
	CheckData();

	int choice=1;
	while(choice!=0)
	{
		vector<Student> stu;
		vector<Student>::iterator it, itStu;
		int k=0;

		do
		{
			char sTmp[1024]={'\0'};

			ShowNotice();

			while(sTmp[0]=='\0')
			{
				cout<<"\n\tTo delete students, we need to find them first.";
				cout<<"\n\tPlease input information of the students to be deleted:";
				cin.sync();
				cin.getline(sTmp,1024,'\n');
			}

			if( strcmp(sTmp,"000")==0 )
			{
				choice=0;
				break;
			}


			cout<<endl;

			ShowTitle();

			char gender='\0';
			if( ToLower(sTmp) == "m" ||  ToLower(sTmp) == "male"  )
			{
				gender='M';
			}

			if( ToLower(sTmp) == "f" ||  ToLower(sTmp) == "female"  )
			{
				gender='F';
			}


			for( it = STU.begin(); it != STU.end(); it++ )
			{
				if( ToLower(it->getNo())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( ToLower(it->getName())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( ToLower(it->getPhone())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( ToLower(it->getWechat())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( ToLower(it->getDormitory())==ToLower(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( tolower(it->getGender())==tolower(gender) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
				if( it->getScore()==toDouble(sTmp) )
				{
					stu.push_back(*it);
					cout<<*it;
					k++;
				}
			}
			if(k)
			{
				cout<<"\n\tThere are "<<k<<" students with \""<<sTmp<<"\"."<<endl;
			}
			else
			{
				cout<<"\n\tThere is no student with \""<<sTmp<<"\"."<<endl;
			}
		}while(k==0);

		if(choice==0)
		{
			break;
		}

		cout<<"\n\tPress ENTER to delete all or input the StudentNo.:";


		char stuNo[1024]={'\0'};
		int flag=0;

		cin.sync();
		if( cin.peek()=='\n')
		{
			for(it=STU.begin();it!=STU.end();it++)
			{
				for(itStu=stu.begin();itStu!=stu.end();itStu++)
				{
					if( *it==*itStu )
					{
						STU.erase(it);
						flag++;
					}
				}
			}
			cout<<"\n\tThere are "<<flag<<" students deleted."<<endl;
		}
		else
		{
			while(!flag)
			{
				cin.getline(stuNo,1024,'\n');  // delete only students with stuNo
	 			if( strcmp(stuNo,"000")==0)
				{
					choice=0;
					break;
				}

				for( it = STU.begin(); it != STU.end(); )
				{
					if(it->getNo()==stuNo)
					{
						it=STU.erase(it);
						flag++;
					}
					else
					{
						it++;
					}
				}

				if(flag==0)
				{
					cout<<"\n\tThere is no student with StudentNo.: "<<stuNo<<endl;
					ShowNotice();
					cout<<"\n\tPlease input a StudentNo. again: ";
				}
			}

			cout<<"\n\tThere are "<<flag<<" students deleted with StudentNo.: "<<stuNo<<endl;
		}
	}

	return true;
}

void Search()
{
	CheckData();

	while(1)
	{
		char sTmp[1024]={'\0'};

		ShowNotice();

		while(sTmp[0]=='\0')
		{
			cout<<"\n\tPlease input information of the student: ";
			cin.sync();
			cin.getline(sTmp,1024,'\n');
		}

		if( strcmp(sTmp,"000")==0 )
		{
			break;
		}

		vector<Student>::iterator it;

		cout<<endl;

		ShowTitle();

		int k=0;

		char gender='\0';
		if( ToLower(sTmp) == "m" ||  ToLower(sTmp) == "male"  )
		{
			gender='M';
		}

		if( ToLower(sTmp) == "f" ||  ToLower(sTmp) == "female"  )
		{
			gender='F';
		}


		for( it = STU.begin(); it != STU.end(); it++ )
		{
			if( ToLower(it->getNo())==ToLower(sTmp) )
			{
				cout<<*it;
				k++;
			}
			if( ToLower(it->getName())==ToLower(sTmp) )
			{
				cout<<*it;
				k++;
			}
			if( ToLower(it->getPhone())==ToLower(sTmp) )
			{
				cout<<*it;
				k++;
			}
			if( ToLower(it->getWechat())==ToLower(sTmp) )
			{
				cout<<*it;
				k++;
			}
			if( ToLower(it->getDormitory())==ToLower(sTmp) )
			{
				cout<<*it;
				k++;
			}
			if( tolower(it->getGender())==tolower(gender) )
			{
				cout<<*it;
				k++;
			}
			if( it->getScore()==toDouble(sTmp) )
			{
				cout<<*it;
				k++;
			}
		}
		if(k)
		{
			cout<<"\n\tThere are "<<k<<" students with \""<<sTmp<<"\"."<<endl;
		}
		else
		{
			cout<<"\n\tThere is no student with \""<<sTmp<<"\"."<<endl;
		}
	}
}








