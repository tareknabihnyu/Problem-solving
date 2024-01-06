#ifndef CONTACT_H
#define CONTACT_H

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

class Contact
{
	private:
		string fname;
		string lname;
		string email;
		string primaryPhone;
		string city;
		string country;
		bool isFav;

	public:
		Contact(string fname, string lname, string email, string primaryPhone, string city, string country, bool isFav);
		Contact();
		void displayContact();
		void displayContact2();
		void displayTofile(ofstream & file);
		bool isFavourite();
		void markFav();
		void unmarkFav();
		void edit();
		
		
};

Contact::Contact(string fname, string lname, string email, string primaryPhone, string city, string country, bool isFav){
	this->fname = fname;
	this->lname = lname;
	this->email = email;
	this->primaryPhone = primaryPhone;
	this->city = city;
	this->country = country;
	this->isFav = isFav;
}

Contact::Contact(){
	
}

void Contact::markFav(){
	isFav = 1;
}

void Contact::unmarkFav(){
	isFav = 0;
}

void nothing(){}

void Contact::edit(){
	cout << endl<< endl;
	int ch;
	cout << "which field do you want to edit? 1) Firstname 2)LastName 3)email 4)phone# 5)City, or 6)country : ";
	cin >> ch;
	switch(ch){
		case(1):{
			string temp;
			cout << "please enter the new FirstName: ";
			cin >> temp;
			fname = temp;
			break;
		}
		case(2):{
			string temp;
			cout << "please enter the new LastName: ";
			cin >> temp;
			lname = temp;
			break;
		}
		case( 3):{
			string temp;
			cout << "please enter the new Email: ";
			cin >> temp;
			email= temp;
			break;
		}
		case( 4):{
			string temp;
			cout << "please enter the new Phone: ";
			cin >> temp;
			primaryPhone = temp;
			break;
		}
		case(5):{
			string temp;
			cout << "please enter the new City: ";
			cin >> temp;
			city = temp;
			break;
		}
		case( 6):{
			string temp;
			cout << "please enter the new Country: ";
			cin >> temp;
			country = temp;
			break;
		}
	}

	char cha;
	cout << "do you want to edit another field?"; cin >> cha;
	while(cha == 'y' || cha == 'n'){
		if(cha == 'y') edit();
		else{break;}
	}
	cin.ignore();
}

void Contact::displayContact(){
	cout<< "" << "First Name: "<< fname << endl; 
	cout<< "  " << "Last Name: "<< lname<< endl; 
	cout<< "  " << "Email: " << email<< endl; 
	cout<< "  " << "PhoneNumber: " <<primaryPhone<< endl; 
	cout<< "  " << "City: "<< city<< endl; 
	cout<< "  " << "Country: "<< country<< endl; 
	cout<< "  " << "if favorite: " << isFav<< endl; 
}

void Contact::displayContact2(){
	cout << fname << ", " << lname << ", " << email << ", " << primaryPhone << ", " << city << ", " << country <<", " << isFav << endl;   
}

void Contact::displayTofile(ofstream & file){
	file << fname << "," << lname << "," << email << "," << primaryPhone << "," << city << "," << country <<"," << isFav << endl;   
}

bool Contact::isFavourite(){
	return isFav;
}

#endif