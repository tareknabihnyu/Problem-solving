
//=================================================================================
// Name         : DS Assignment#3 
// Author       : 
// Version      : 1.0
// Date Created : 03-20-2022
// Date Modified: 
// Description  : Starter Code for Contact Management System using BST Tree in C++
// Copyright © 2022 Khalid Mengal and Mai Oudah. All rights reserved.
//=================================================================================
#include<iostream>
#include<cstdlib>
#include<sstream>
#include <string>
#include<iomanip>



#include "contact.h"
#include "contactbst.h"

string keycreator(string a, string b){
	string final = a + " " + b;
	return final;
}


void addContact(ContactBST& myContactBST){
	cout << "Please enter the details of the contact" << endl;
	cout << "First Name: " ; string fname; cin >> fname;
	cout << "Last Name: " ; string lname; cin >> lname;
	cout << "Email: " ; string email; cin >> email;
	cout << "Phone: " ; string phone; cin >> phone;
	cout << "City: " ; string city; cin >> city;
	cout << "Country: " ; string country; cin >> country; char fav;
	while(fav!= 'y' && fav != 'n') {cout << "Do you want it to be in favorite contacts(y/n)? " ;  cin >> fav;}
	bool isFav;
	isFav = (fav == 'y')? 1:0 ;
	Contact* data = new Contact(fname,lname,email,phone,city,country,isFav);
	myContactBST.insert_helper( keycreator(fname,lname) , data );
	cin.ignore();
}

void displaySearch(ContactBST& myContactBST, Node *ptr,string key){
	if((myContactBST.search(ptr,key) != nullptr)) myContactBST.display1node(myContactBST.search(ptr,key));
	else cout << "contact not available!" << endl << endl;

}





//==========================================================
void listCommands()
{
	cout<<"----------------------------------"<<endl;
	cout<<"import <path>      :Import contacts from a CSV file"<<endl
		<<"export <path>      :Export contacts to a CSV file"<<endl
		<<"add                :Add a new contact"<<endl
		<<"edit <key>         :Update a contact's details"<<endl
		<<"del <key>          :Delete a contact"<<endl
		<<"searchFor <key>    :Search for a contact"<<endl
		<<"markfv <key>       :Mark as favourite"<<endl
		<<"umarkfv <key>      :Unmark as favourite"<<endl
		<<"printASC           :Print contacts in ascending order"<<endl
		<<"printDES           :Print contacts in descending order"<<endl
		<<"printfv            :Print all favourite contacts"<<endl
		<<"help               :Display the available commands"<<endl
		<<"exit               :Exit the program"<<endl;
}
//==========================================================

// to be completed with all the necessary method definitions

//==========================================================
int main(void)
{
	ContactBST myContactBST;
	string user_input;
	string command;
	string key;

			

	while(true)
	{
		listCommands();
		cout<<">";
		getline(cin,user_input);
		
		// parse userinput into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr,command,' ');
		getline(sstr,key);
		
		Node* root = myContactBST.getRoot();	//get the root of the tree
		cout<<"----------------------------------"<<endl;
		if( user_input =="add" or command=="i" or command =="add" or user_input =="i")    addContact(myContactBST);
		else if( user_input =="display" || user_input =="printASC")	myContactBST.printASC(root);
		else if( user_input =="printDES")	myContactBST.printDES(root);
		else if( user_input =="printFav" || user_input =="printfv")	myContactBST.printFav(root);
		else if( command =="search" || command == "searchFor" )	displaySearch(myContactBST,root,key);
		else if( command =="export" || command == "export " )	{ cout << myContactBST.exportCSV(root,key) << endl;  }
		else if( command =="markfv" )	{ if(myContactBST.markFav(root,key) == 1 ){ cout << key << " has succussfully been marked favourite!"<< endl;}  }
		else if( command =="unmarkfv" )	{ if(myContactBST.unmarkFav(root,key) == 1 ){ cout << key << " has succussfully been unmarked favourite!"<< endl;}  }
		else if( command =="edit" )	{ if(myContactBST.update(root,key) != nullptr ){ cout << key << " has succussfully been updated!"<< endl;} else{cout << "could not find key" <<endl ;} }
		else if( command =="import" || command == "import " )	{ cout << myContactBST.importCSV(root,key) << endl;  }
		else if( command =="delete" || command == "remove" || command =="del"  )	{myContactBST.remove_helper(key); }
		else if( command == "help") continue;
		else if( command == "exit") break;
		else {cout << "invalid command!" << endl;}

		

	}

	return 0;
}

//if (displaySearch(myContactBST,root,key) == nullptr){cout << "key could not be found!"}