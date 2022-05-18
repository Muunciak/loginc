#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void reg();
void fp();
void output();


int main(){
	
	int c;
	cout<<"\t\t\t____________________________________________________\n\n\n";
	cout<<"\t\t\t                     Login skills                    \n\n\n";
	cout<<"\t\t\t________________    Choose option    _______________\n\n\n";
	cout<<" 														   \n\n";
	
	cout<<"\t| Press 1 to LOGIN             |"<<endl;
	cout<<"\t| Press 2 to REGISTER          |"<<endl;
	cout<<"\t| Press 3 to Forgot password?  |"<<endl;
	cout<<"\t| Press 4 to EXIT              |"<<endl;
	
	cout<<"\n\t\t\t Please enter your choice: ";
	cin>>c;
	cout<<endl;
	switch(c){
		case 1:
			login();
			break;
		case 2:
			reg();
			break;
		case 3:
			fp();
		case 4:
			cout<<"\t\t\t Thank you for visiting. \n\n";
			break;
		default:
			system("cls");
			cout<<"Please select from the options above \n"<<endl;
			main();
	}
}

	void login(){
		int count; 
		string userId, passw, id, pass;
		system("cls");
	
		cout<<"\t\t\t Please enter the suername and password: "<<endl;
		cout<<"\t\t\t Username: ";cin>>userId;
		cout<<"\t\t\t Password: ";cin>>passw;


		ifstream input("records.txt");
	
		while(input>>id>>pass){
			if(id==userId && pass==passw){
				count=1;
				system("cls");
			}
		}
		input.close();
	
		if(count==1){
			cout<<userId<<" \n your login is successfull."<<endl;
			main();
		}
		else{
			cout<<"\n Wrong username or password."<<endl;
			main();
		}
	}

	void reg(){
		string ruserId, rpassword, rid, rpass,lid;
		system("cls");
		int count=0,o;
		string Cuser;
		ifstream check("records.txt");
		cout<<"\t\t\t Enter the username: ";
		cin>>ruserId;
		 while (!check.eof()){
		 	check >> Cuser;
			if(ruserId==Cuser)
			{
				cout<<"\t\t\t This username is already taken. \n";
				cout<<"\t\t\t Choose other username(1) or back to menu(2)";
				cin>>o;
				switch(o){
					case 1:reg();break;
					case 2:main();break;
				}
			}
			}
		cout<<"\t\t\t Enter the password: ";
		cin>>rpass;
			
		cout<<"\t\t\t Sucessfully registered!";
		ofstream op("records.txt", ios::app);
		op<<ruserId<<' '<<rpass<<endl;
		main();
	}
	void fp(){
		int option; 
		system("cls");
		cout<<"\t\t\t Don't remember password? No worries my friend. \n";
		cout<<" Press 1 to serach you id by username "<<endl;
		cout<<" Press 2 to go back to the main menu"<<endl;
		cout<<"\t\t\t Enter your choice: ";cin>>option;
		cout<<option;
		
		
		switch(option){
			case 1:{
				int count=0;
				string suserId,sId,spass;
				cout<<"\n\t\t Enter the username which you remembered: ";
				cin>>suserId;
				ifstream op1("records.txt");
				while(op1>>sId>>spass){
					if(sId==suserId){
						count=1;
					}
				}
				op1.close();
				if(count==1){
					cout<<"\n\n Your account is found! \n";
					cout<<"\n\n Your password is: "<<spass;
					main();
				}
				else{ 
					cout<<"\n\t Sorry, we haven't be able to find your account. \n";
					main();
				}
				break;
			}
			case 2:{
				main();
				break;
			}
				default:{
					cout<<"\t\t\t You didnt choice good number, try again or exit. ";
					cout<<"\n\t\t\t 1- try again | 2-menu" <<endl;
					int o;
					cin>>o;
					switch(o){
						case 1:fp();break;
						case 2:main();break;
					}
				}break;
		}
	}
	void output(){
		
		
				
	}

