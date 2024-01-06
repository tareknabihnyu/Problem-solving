#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
#include<cstdlib>
#include<admin.h>
using namespace std;


admin::admin(string a, string b):FirstName(a), LastName(b){
        setAdminID(generateID()); //generating random ID
        setUsername( addSI( lower( a ), getAdminID()) ); //making the integars strings and adding them to the username
        setPassword(addSI(lower(b),generateID())); //generating a new id and adding it to the password
        display(); //displaying
        
      }

admin::admin(){}

// setters: for all the functions the variables are being set to the given variavble
void admin::setAdminID(int x){
    AdminID = x;
}
void admin::setFirstName(string x){
    FirstName = x;
}
void admin::setLastName(string x){
    LastName = x;
}
void admin::setUsername(string x){
    Username = x;
}
void admin::setPassword(string x){
    Password = x;
}

//getters:  getting the variables inside the class
int admin::getAdminID(){ return AdminID;}
string admin::getFirstName(){return FirstName;}
string admin::getLastName(){return LastName;}
string admin::getUsername(){return Username;}
string admin::getPassword(){return Password;}

//functions: 
void admin::makeAdmin(string a, string b){ //in case the user wanted to add an admin at random time
  //basically the same code as the constructor
  setFirstName(a); setLastName(b);
  setAdminID(generateID());  
  setUsername( addSI( lower(a), getAdminID()) );
  setPassword(addSI( lower(b), generateID()));

  
}

void admin::display(){
  //displaying the variables
  cout <<  to_string(getAdminID()) <<", " << getFirstName() << ", " << getLastName() << ", ";
  cout << getUsername() << ", " << getPassword() << endl;
    
}

void admin::displayToFile(ofstream& a){
  //putting the variables in the given file
  a <<  to_string(getAdminID()) <<", " << getFirstName() << ", " << getLastName() << ", ";
  a << getUsername() << ", " << getPassword() << endl;
    
}



