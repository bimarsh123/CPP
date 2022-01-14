#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
#include <iomanip>
using namespace std;

class Student
{
	private:
	 string m_No;
     string m_Name;
	 char m_Gender;
     string m_Phone;
     string m_WeChat;
     string m_Dormitory;
	 double m_Score;

	public:

	 Student(string no="", string name="", char gender='F', string phone="",string wechat="",string dormitory="",double score=0)
     {
     	m_No=no;
     	m_Name=name;
     	m_Gender=gender;
     	m_Phone=phone;
     	m_WeChat=wechat;
     	m_Dormitory=dormitory;
     	m_Score=score;
     }

     Student(const Student &stu)
     {
     	m_No=stu.m_No;
     	m_Name=stu.m_Name;
     	m_Gender=stu.m_Gender;
     	m_Phone=stu.m_Phone;
     	m_WeChat=stu.m_WeChat;
     	m_Dormitory=stu.m_Dormitory;
		m_Score=stu.m_Score;
     }

    friend bool operator==(const Student &a,const Student &b)//关系运算符重载
	{
		return (a.m_No==b.m_No)&&(a.m_Name==b.m_Name)&&(a.m_Phone==b.m_Phone)
		&&(a.m_WeChat==b.m_WeChat)&&(a.m_Dormitory==b.m_Dormitory)
		&&(a.m_Score==b.m_Score)&&(a.m_Gender==b.m_Gender);
	}

     friend bool operator!=(const Student& a,const Student& b)//关系运算符重载
	{
     	return (a.m_No!=b.m_No)||(a.m_Name!=b.m_Name)||(a.m_Phone!=b.m_Phone)
		 ||(a.m_WeChat!=b.m_WeChat)||(a.m_Dormitory!=b.m_Dormitory)
		 ||(a.m_Gender!=b.m_Gender)||(a.m_Score!=b.m_Score);
    }

    //输入流/输出流类定义中赋值、复制构造函数都是私有的
	//如果形参不是引用类型，传递实参的时候会调用形参类型的赋值构造函数
	//而复制构造函数为私有，所以一旦调用cout<<s;就会出现编译时错误
    //引用返回 按引用返回可以连续使用
	friend ostream & operator<<(ostream & output, const Student &stu) //<<运算符重载
    {
    	output<<setw(8)<<left<<stu.m_No<<"  ";
		//output.width(12);
		output<<setw(12)<<stu.m_Name<<"  ";
		output.width(6);
		if(stu.m_Gender=='M')
		{
			output<<"Male";
		}
		else if(stu.m_Gender=='F')
		{
			output<<"Female";
		}
		else
		{
			cout<<"Unkown";
		}

		output<<"  "<<setw(11)<<stu.m_Phone<<"  "<<setw(5)<<stu.m_WeChat<<"\t"<<setw(8)<<stu.m_Dormitory<<"   "
		<<stu.m_Score<<endl;
		return output;
    }

    void setNo(string no)
    {
    	m_No=no;
    }

    void setName(string name)
    {
    	m_Name=name;
    }

	void setPhone(string phone)
    {
    	m_Phone=phone;
    }

    void setWechat(string wechat)
    {
    	m_WeChat=wechat;
    }
    void setDormitory(string dormitory)
    {
    	m_Dormitory=dormitory;
    }
    void setGender(char gender)
    {
    	m_Gender=gender;
    }

    bool  setScore(double score)
    {
    	if(score<0)
    	{
	    	cout<<"\n\t Score cannot be less than 0."<<endl;
	    	return false;
	    }
    	m_Score=score;

    	return true;
    }


    //不加const时，定义为const变量时，不能调用此函数，会报错 discards qualifiers
    //例如函数：bool ComStuNo_Asc(const Student &a, const Student &b)
    string getNo()const
    {
    	return m_No;
    }

    string getName()const
    {
    	return m_Name;
    }

	string getPhone()const
    {
    	return m_Phone;
    }

    string getWechat()const
    {
    	return m_WeChat;
    }
    string getDormitory()const
    {
    	return m_Dormitory;
	}
	char getGender()const
	{
		return m_Gender;
	}
	double getScore()const
	{
		return m_Score;
	}
};

#endif
