#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

string username;
string password;
bool check=true;
int number;
int num=0;

// word color
void setcolor( unsigned char color )
{
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}

// admin information
struct admin{
	string username;
	string password;
};

// book information
struct book{
	string book_id;
	string name;
	string topic;
	string publisher;
	int copy_num;
	int edit_num;
	string publish_date;
	string last_edit_date;
	int price;
	string writer;
};

// member information
struct member{
	string username;
	string password;
	string first_name;
	string last_name;
	int year;
	int month;
	int day;
	string address;
	long number;
	string bio;
	string membership_date;
	string finish_membership_date;
};

admin admin_number[100];
book book_number[100];
member user[100];

// sign in(1)
void sign_in(){
	cout<<"enter username : ";
	cin>>user[num].username;
	cout<<endl<<"enter password : ";
	cin>>user[num].password;
	cout<<endl<<"enter first name : ";
	cin>>user[num].first_name;
	cout<<endl<<"enter last name : ";
	cin>>user[num].last_name;
	cout<<endl<<"enter birth year : ";
	cin>>user[num].year;
	cout<<" month : ";
	cin>>user[num].month;
	cout<<" day : ";
	cin>>user[num].day;
	cout<<endl<<"enter address : ";
	cin>>user[num].address;
	cout<<endl<<"enter number : ";
	cin>>user[num].number;
	cout<<endl<<"enter biography : ";
	cin>>user[num].bio;
	num++;
}

void memberfile(){
	fstream file;
	file.open("member.txt", ios::out | ios::in);
	file<<user[num].username<<'-';
	file<<user[num].password<<'-';
	file<<user[num].first_name<<'-';
	file<<user[num].last_name<<'-';
	file<<user[num].year<<'-';
	file<<user[num].month<<'-';
	file<<user[num].day<<'-';
	file<<user[num].address<<'-';
	file<<user[num].number<<'-';
	file<<user[num].bio<<'-';
	num++;
}

void RenderAdmin() {
	fstream file;
	string data;
	string temp;
	file.open("admin.txt", ios::out | ios::in);
	file>>data;
	file.close();
	for(int i = 0; i<data.length(); i++) {
		
		char a = (char)data[i];
		if(a == '-') {

			username = temp;
			temp = "";
		} else if (i == (data.length() - 1)) {
			temp += a;
			password = temp;
		} else {
			temp += a;
		}

	}

}

// admin log in(3)
void admin_login()
{
	string user;
	string pass;
	
	cout<<" ----------- Admin Log in -----------\n";
	cout<<"enter username : ";
	cin>>user;
	cout<<endl;
	cout<<"enter password : ";
	cin>>pass;
	cout<<endl;
	
	if(user==username && pass==password){
		
		while(check){
			
		    cout<<"1.delete books\n"<<"2.add books\n"<<"3.edit books\n"<<"4.delete members\n"<<"5.add admin\n"<<"0.exit"<<endl;
		    cout<<"enter the number : ";
		    cin>>number;
		    cout<<endl;
		    
	        switch(number){
	        	
			    case 0:
			    	cout<<"thanks for choosing our library";
		    	    check=false;
		    	    break;
		    	    
		        case 1:
			        break;
			        
			    case 2:
				    break;
				    
			    case 3:
				    break;
				    
			    case 4:
				    break;
				    
				case 5:
					break;
					
			    default:
				    setcolor(0x0c);
				    cout<<"wrong number\n"<<endl;
		    }
	    }
	}
	else {
		setcolor(0x0c);
		cout<<"wrong username or password\n"<<endl;
	}
}




int main(){
	RenderAdmin();
	setcolor( 0x09 );
	cout<<" ----------- WELCOME TO ARSANA LIBRARY ----------- \n"<<endl;
	
	while(check){
		
		setcolor(0x07);
		cout<<"1.sign in\n"<<"2.log in(member)\n"<<"3.log in(admin)\n"<<"0.exit"<<endl;
		cout<<"enter the number : ";
		cin>>number;
		cout<<endl;
		
	    switch(number){
	    	
			case 0:
				cout<<"thanks for choosing our library";
		    	check=false;
		    	break;
		    	
			case 1:
				sign_in();
				memberfile();
			    break;
			    
			case 2:
				break;
				
			case 3:
			    admin_login();
				break;
				
			default:
				setcolor(0x0c);
				cout<<"wrong number\n"<<endl;
		    }
	}
	return 0;
}