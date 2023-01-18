#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <ctime>
using namespace std;

string username;
string password;
bool check=true;
int number;
// user number array
int num=0;
//admin number array
int i=0;
// book number array
int j=0;

// word color
void setcolor( unsigned char color ) {
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}

void exit() {
	setcolor(0x0D);
    cout<<"thanks for choosing our library";
	check=false;
}

// admin information
struct {
	string username;
	string password;
}admin[100];

//FIX ME
// book information
struct {
	string id;
	string name;
	string topic;
	string publisher;
	int copy_num;
	int edit_num;
	string publish_date;
	string last_edit_date;
	int price;
	string writer;
	bool borrow;
	int fine;
}book[100];

//FIX ME
// member information
struct {
	string username;
	string password;
	string first_name;
	string last_name;
	int year;
	string month;
	int day;
	string address;
	long number;
	string bio;
	// FIXME
	string membership_date;
	string finish_membership_date;
	//TA INJA
	string  membership_type = "regular";
	int limit_books = 3;
	int number_borrowed_books = 0;
	string borrowed_books = " ";
	string limit_time = "1 week";
	string total_delay = "0 days";
	
}user[100];

void add_books() {
	cout<<"enter book ID :";
	cin>>book[j].id;
	cout<<"enter book name :";
	cin>>book[j].name;
	cout<<"enter book topic :";
	cin>>book[j].topic;
	cout<<"enter book publisher :";
	cin>>book[j].publisher;
	cout<<"enter book copy number :";
	cin>>book[j].copy_num;
	cout<<"enter book edit number :";
	cin>>book[j].edit_num;
	cout<<"enter book publish date :";
	cin>>book[j].publish_date;
	cout<<"enter book last edit date :";
	cin>>book[j].last_edit_date;
	cout<<"enter book price :";
	cin>>book[j].price;
	cout<<"enter book writer/writers :";
	cin>>book[j].writer;
	cout<<"do we have premission to lend this book ? (yes/no):";
	string answer;
	cin>>answer;
	if(answer == "yes")
		book[j].borrow = true;
	else
	    book[j].borrow = false;
	cout<<"amount of fine :";
	cin>>book[j].fine;
	system("cls");
	setcolor( 0x06 );
	cout<<"book added successfully\n";
	system("pause");
	setcolor( 0x07 );
	
}

void file_books(){
	fstream file;
	file.open("book.txt", ios::app | ios::in);
	file<<book[j].id<<'-';
	file<<book[j].name<<'-';
	file<<book[j].topic<<'-';
	file<<book[j].publisher<<'-';
	file<<book[j].copy_num<<'-';
	file<<book[j].edit_num<<'-';
	file<<book[j].publish_date<<'-';
	file<<book[j].last_edit_date<<'-';
	file<<book[j].price<<'-';
	file<<book[j].writer<<'-';
	file<<book[j].borrow<<'-';
	file<<book[j].fine<<'/';
	file.close();
	j++;
	
}

 void password_weak(string pass){
 	
 	int n=pass.length();
 	while(n<5){
    setcolor(0x0c);
    cout<<endl<<"your password is too weak(more than four characters)";
    setcolor(0x07);
 	cout<<endl<<"enter password : ";
	cin>>user[num].password;
	n=user[num].password.length();
	 }
 	
 }

void sign_up() {
	setcolor( 0x09 );
	cout<<" ----------- sign up -----------\n";
	setcolor(0x07);
	cout<<"enter username : ";
	cin>>user[num].username;
	cout<<endl<<"enter password : ";
	cin>>user[num].password;
	password_weak(user[num].password);
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
	getline(cin , user[num].address);
	getline(cin,user[num].address);
	cout<<endl<<"enter phone number : ";
	cin>>user[num].number;
	cout<<endl<<"enter biography : ";
	getline(cin , user[num].bio);
	getline(cin , user[num].bio);
	cout<<endl;
	system("cls");
}

void file_member() {
	fstream file;
	file.open("member.txt", ios::app | ios::in);
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
	file<<user[num].membership_type<<'-';
	file<<user[num].limit_books<<'-';
	file<<user[num].number_borrowed_books<<'-';
	file<<user[num].borrowed_books<<'-';
	file<<user[num].limit_time<<'-';
	file<<user[num].total_delay<<'-';
	file<<user[num].borrowed_books<<'/';
	file.close();
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

void add_admin() {
	fstream file;
	file.open("admin.txt", ios::app | ios::in);
	cout<<"enter new admin username :";
	cin>>admin[i].username;
	file<<'/'<<admin[i].username<<'-';
	cout<<"enter new admin password :";
	cin>>admin[i].password;
	file.close();
	i++;
	
}

void admin_login() {
	string user;
	string pass;
    setcolor( 0x09 );
	cout<<" ----------- Admin Log in -----------\n";
	setcolor(0x07);
	cout<<"enter username : ";
	cin>>user;
	cout<<endl;
	cout<<"enter password : ";
	cin>>pass;
	cout<<endl;
	system("cls");

	if(user==username && pass==password){

		while(check){

		    cout<<"1.delete books\n"<<"2.add books\n"<<"3.edit books\n"<<"4.delete members\n"<<"5.add admin\n"<<"0.exit"<<endl;
		    cout<<"enter the number : ";
		    cin>>number;
		    cout<<endl;
            system("cls");
	        switch(number){

			    case 0:
			    	exit();
		    	    break;

		        case 1:
		        	// TODO delete books
			        break;

			    case 2:
			    	add_books();
			    	file_books();
				    break;

			    case 3:
			    	// TODO edit books
				    break;

			    case 4:
			    	// TODO delete members
				    break;

				case 5:
					add_admin();
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


int main() {
	RenderAdmin();
	setcolor( 0x09 );
	cout<<" ----------- WELCOME TO ARSANA LIBRARY ----------- \n"<<endl;

	while(check){

		setcolor(0x07);
		cout<<"1.sign up\n"<<"2.log in(member)\n"<<"3.log in(admin)\n"<<"0.exit"<<endl;
		cout<<"enter the number : ";
		cin>>number;
		cout<<endl;
        system("cls");
	    switch(number){

			case 0:
				exit();
		    	break;

			case 1:
				sign_up();
				file_member();
			    break;

			case 2:
				// TODO log in
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
