#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
#include<cstdlib>
using namespace std;

class admin{
    //Admin ID, First name, Last name, Username, Password.
    private:
      //initializing the  variables to be used
      string FirstName, LastName, Username, Password;
      int AdminID;
    public:
      admin(string a, string b);
      admin();

  
  
      // setters:
      void setAdminID(int x);
      void setFirstName(string x);
      void setLastName(string x);
      void setUsername(string x);
      void setPassword(string x);
      
      //getters:
      int getAdminID();
      string getFirstName();
      string getLastName();
      string getUsername();
      string getPassword();

      //functions:
      void makeAdmin(string a, string b);

      void display();

      void displayToFile(ofstream& a);
};