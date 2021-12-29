#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int Min(int &a,int &b);
int Max(int &a,int &b);

class Calendar{
	public:
		Calendar(int yy):year(yy),start(Tue){
			cout<<setw(35)<<"this is "<<yy<<endl;
			cout<<setw(38)<<"welcome! "<<endl;
		};
		void display(int month);//2 months each time
	private:
		enum week{Sun=0,Mon,Tue,Wed,Thu,Fri,Sat};
		int year;
	    	week start;//2019.1.1
	    	int isLeap(int year);
	    	int get_total_days_between(int  year,int begin=2019);
	    	int get_startday_of(int year);
	    	string getname(int month);
		int getdays(int month);
};

int Calendar::isLeap(int year){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    	else return 0;
}

int Calendar::get_total_days_between(int  year,int  begin){
	int total=0;
	for(int i=Min(year,begin);i<Max(year,begin);i++){
		if(year>begin){
			if(isLeap(i)) total+=366;
					 else total+=365;
		} else if(year<begin){
			if(isLeap(i)) total-=366;
			else total-=365;
		} else return 0;
	}
	return total;
}

int Calendar::get_startday_of(int year){
	int re=start+get_total_days_between(year,2019)%7;
	if(re<0)re+=7;
	return re;
}

void Calendar::display(int month){
	static int startday=get_startday_of(year);
	int first_total=getdays(month);int second_total=getdays(month+1);
	int first_date=1;int second_date=1;
	int date=1;
	
	cout<<" "<<getname(month)<<setw(35)<<getname(month+1)<<endl;//Januray 1 for example
	cout<<"==============================    =============================="<<endl;
	cout<<"  Sun Mon Tue Wed Thu Fri Sat       Sun Mon Tue Wed Thu Fri Sat "<<endl;
	
	int first_startday=startday%7;

	if(first_startday) cout<<setw(4*first_startday)<<" ";

	int second_startday=(first_startday+first_total%7)%7;
	
	while(first_date<=first_total){
		cout<<setw(4)<<first_date;
		first_startday++;

		if(first_startday==7){
			cout<<"      ";first_startday=0;
			if(second_startday) cout<<setw(4*second_startday)<<" ";
			while(second_startday<7&&second_date<=second_total){
				cout<<setw(4)<<second_date;second_date++;second_startday++;
			}
			cout<<'\n';
			second_startday=second_startday%7;
		}
		
		first_date++;

	}
	//以下代码考虑到month最后一天不是Sat时month+1最后一行无法输出问题 
	if(second_date<=second_total){
		cout<<setw(4*(Sat-first_startday+1))<<" ";
		cout<<"      ";
	}
	while(second_startday<7&&second_date<=second_total){
				cout<<setw(4)<<second_date;second_date++;second_startday++;
		}
	//以上
	startday=second_startday;
	cout<<endl;
}//每两个月一输出

string Calendar::getname(int month){
	switch(month){
		case 1 : return "Janurary 1";
		case 2 : return "February 2";
		case 3 : return "March 3";
		case 4 : return "April 4";
		case 5 : return "May 5";
		case 6 : return "June 6";
		case 7 : return "July 7";
		case 8 : return "August 8";
		case 9 : return "September 9";
		case 10 :return "October 10";
		case 11 :return "November 11";
		case 12 :return "December 12";
	}
}

int Calendar:: getdays(int month){
	switch(month){
		case 1:   ;
		case 3:   ;
		case 5:   ;
		case 12:  ;
		case 10:  ;
		case 7:   ;
		case 8:   return 31;
		
		case 2:   return isLeap(year)?29:28;
		
		case 4:   ;
		case 6:   ;
		case 9:   ;
		case 11:  return 30;
		
	}	
}

int Min(int &a,int &b){
	return (a>b)?b:a;
}

int Max(int &a,int &b){
	return (a>b)?a:b;
}

int main(){
	Calendar c(2021);

		c.display(1);
		c.display(3);
		c.display(5);
		c.display(7);
		c.display(9);
		c.display(11);
}
