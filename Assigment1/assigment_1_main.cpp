#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
#include<cstdlib>

using namespace std;
int generateID();
string addSI(string a, int b);
string lower(string a);

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






class member{
    //Member ID, First name, Last name, Username, Password
    private:
    string FirstName, LastName, Username, Password;
    int MemberID;
    bool working;
    public:
      //inializing the functions
      member(string a, string b);
      member();

  
  
      // setters:
      void setmemberID(int x);
      void setFirstName(string x);
      void setLastName(string x);
      void setUsername(string x);
      void setPassword(string x);
      
      //getters:
      int getmemberID();
      string getFirstName();
      string getLastName();
      string getUsername();
      string getPassword();

      //functions:
      void makemember(string a, string b);

      void display();
      void displayToFile(ofstream& a);

      bool isworking(); //to check whether the function has variables stored in it or not
    


};

member::member(string a, string b):FirstName(a), LastName(b){
        //same as in the admins class.. generating random ID and sticking it to the username and generating new password and sticking it to the password
        setmemberID(generateID());
        setUsername( addSI( lower( a ), getmemberID()) ); //adding the firstname to the username with IDs sticked at it
        setPassword(addSI(lower(b),generateID())); //adding teh lastname to the password with random digits sticking in it
        display();
        working = 1; //letting the class object know that it has variables stored in it
      }
member::member(){working = 0;} //if there is nothing stored in it then



// setters: in case only one variable was going to change
void member::setmemberID(int x){
    MemberID = x;
}
void member::setFirstName(string x){
    FirstName = x;
}
void member::setLastName(string x){
    LastName = x;
}
void member::setUsername(string x){
    Username = x;
}
void member::setPassword(string x){
    Password = x;
}

//getters: //to get the variables from the object class
int member::getmemberID(){ return MemberID;}
string member::getFirstName(){return FirstName;}
string member::getLastName(){return LastName;}
string member::getUsername(){return Username;}
string member::getPassword(){return Password;}

//functions:
void member::makemember(string a, string b){
  setFirstName(a); setLastName(b);
  setmemberID(generateID());  
  setUsername( addSI( lower( a ), getmemberID()) );
  setPassword(addSI(lower(b),generateID()));
  
}

void member::display(){
  //displaying all the needed variables in the array.
  cout <<  to_string(getmemberID()) <<", " << getFirstName() << ", " << getLastName() << ", ";
  cout << getUsername() << ", " << getPassword() << endl;
    
}
void member::displayToFile(ofstream& a){
  //storing the members details in the file given
  a <<  to_string(getmemberID()) <<", " << getFirstName() << ", " << getLastName() << ", ";
  a << getUsername() << ", " << getPassword() << endl;
    
}

bool member::isworking(){return working;} //to know whether the function is working



class fitnessClass{
    private:
        //inializing the variables that will be used
        int ClassID, MaximumCapacity, roomNumber;
        string ClassName, Classtime, Classdate;
        bool working;
        int listCount;

    public:
      member * listOfmembers; //inializing the dynamic array of members
      //inializing the functions
      fitnessClass(int ID, int MC, int RN, string CN, string CT, string CD);
      fitnessClass();      

      int getID();
      bool getworking();
      void updateClassdate(string a);

      void updateClasstime(string a);

      void updateClassName(string a);

      void updateRoomNumber(int a);

      void updateMaximumCapacity(int a);

      void updateID(int a);

      void display();

      void displayForFile(ofstream& a);

      void membersInClass();


      void incrementListcount();
      int getlistcount();
      int getMaximumCapacity();

      ~fitnessClass();//deallocating the dynamically allocated list
};

//fitness class functions=================================---------------------------------------------++++++++++++++++++++++++++++++++++++
fitnessClass::fitnessClass(int ID, int MC, int RN, string CN, string CT, string CD){
  //assigning the variables by the details given by the user
  ClassID = ID;
  MaximumCapacity = MC;
  roomNumber = RN;
  ClassName = CN;
  Classtime = CT;
  Classdate = CD; 
  working = 1;
  listCount = 0;
  listOfmembers = new member[MaximumCapacity];
}
fitnessClass::~fitnessClass(){delete [] listOfmembers;}//deallocating the dynamically allocated list
fitnessClass::fitnessClass(){working = 0;}//same as in members class.. i use working to know whether the function is working or not
int fitnessClass::getID(){ return ClassID;} //get the class's ID
bool fitnessClass::getworking(){return working;} //know whether the class is filled with details or not
//updating the class's details individually
void fitnessClass::updateClassdate(string a){ //updating the date
  Classdate = a;
}
void fitnessClass::updateClasstime(string a){ //updating the time
  Classtime = a;
}
void fitnessClass::updateClassName(string a){ //updating the name
  ClassName = a;
}
void fitnessClass::updateRoomNumber(int a){ //updating the room number
  roomNumber = a;
}
void fitnessClass::updateMaximumCapacity(int a){ //updating the maximum capacity
  MaximumCapacity = a;
}
void fitnessClass::updateID(int a){ //updating the ID
  ClassID = a;
}
void fitnessClass::display(){ //displaying the class's details
  cout << "Class Name: " << ClassName << endl;
  cout << "Class time: " << Classtime << endl;
  cout << "Class date: " << Classdate << endl;
  cout << "roomnumber: " << roomNumber<< endl;
  cout << "Class ID:   "   << ClassID   << endl;
  cout << "============================================" << endl;
}
void fitnessClass::displayForFile(ofstream& a){ //saving the details into a given file
  a << ClassID << ", "<< ClassName << ", " << Classdate << ", "<< Classtime<< ", "<< MaximumCapacity << ", " << roomNumber << endl;
}
void fitnessClass::membersInClass(){ //outputting the names of the members in a certain class
  int z = 0;
  if(listCount != 0){ //checking if the list is empty or not
    cout << "> members for class "<< ClassName << ": " << endl;
    for(int i = 0; i < listCount; i++){
      if(listOfmembers[i].isworking()){          
        z++; //z is to give an accurate number of members in the list in case a member cancelled his booking
        cout << z << "- " << listOfmembers[i].getFirstName() << " " << listOfmembers[i].getLastName() << endl ; //outputting first and last name
      }
    }
  }else{
    cout << "> class is empty" << endl;
  }
  cout << "---" << endl;
}
void fitnessClass::incrementListcount(){listCount++;} //incrementing the the number of members in the list
int fitnessClass::getlistcount(){ return listCount;}  //getting the number of members in the list
int fitnessClass::getMaximumCapacity(){return MaximumCapacity;} //getting the maximum capacity 

//fittness class functions are done here---------------------------------------------++++++++++++++++++++++++++++++++++++
fitnessClass* refresharrayf(fitnessClass* a, int& size); //in case the function's size should be increased.. however, it is not used in this program 

void addFitnessClass(fitnessClass * arrayOfclasses, int& size ){ //adding a new class
  int ID; int MC; int RN; string CN; string CT; string CD;
  bool p = 1;
  do{
  p =1 ;
  cout << "What is the class's ID?" << endl;
  cin >> ID;

  for(int i = 0; i < size-1; i++){
    if( ID == arrayOfclasses[i].getID()){
      cout << "This ID already exists.. please enter a new one" << endl << endl;
      p = 0;
    }
  }
  }while(!p);

  cout << "What is the Maximum Capacity?" << endl;
  cin >> MC;

  cout << "What is the roomnumber?" << endl;
  cin >> RN;

  cout << "What is the class name?" << endl;
  cin >> CN;

  cout << "what is the class's time?" << endl;
  cin >> CT;

  cout << "What is the class's date" << endl;
  cin >> CD;


  arrayOfclasses[size - 1] = fitnessClass(ID,MC,RN,CN,CT,CD); //making the array that includes the class details
  arrayOfclasses[size-1].display(); //displaying
  size++; //incrementing the current pointer of where we should put the size in
  //arrayOfclasses = refresharrayf(arrayOfclasses, size);
}
//not working ->
void deleteFitnessClass(fitnessClass * arrayOfclasses, int& size){
  int ID;
  cout << "what is the class's ID?" << endl;
  cin >> ID; //getting the desired ID
  int num = -1; // to get the number of where that ID exits
  for(int i = 0; i < size-1; i++){
    if( ID == arrayOfclasses[i].getID()){
      arrayOfclasses[i] = fitnessClass(); num = 0; //make that class empty
      break;
    }
  }
  if(num == -1){
    cout << "no such ID idenitified, please try again!" << endl; //if that ID was not found call the function again
    deleteFitnessClass(arrayOfclasses, size); //calling the same function
  }
}

void updateClassDetails(fitnessClass * arrayOfclasses, int& size){ //updating the class's details
  int num = -1;  //to get where that arrayOfclasses exits
  do{
  int ID; cout << "what is the class's ID?" << endl;
  cin >> ID;
  for(int i = 0; i < size-1; i++){
    if( ID == arrayOfclasses[i].getID()){ //checking if the array's id is equal to the desired id
      num = i; break; 
    }
  }
  if(num == -1){
    cout << "no such ID idenitified, please try again!" << endl;
  }
  }while(num == -1);//repeat while the ID does not exit
  
  //checking which detail the user wants to change
  cout << "what detail do you want:" << endl;
  cout << "a- ClassID" << endl;
  cout << "b- Maximum Capacity" << endl;
  cout << "c- roomNumber" << endl;
  cout << "d- class name" << endl;
  cout << "e- class time" << endl;
  cout << "g- class date" << endl;
  char ch; cin >> ch;
  int temp; string tem;
  switch (ch){ //give the user the ability to change the details of the class by his choice
    //updating the class
    case('a'):
      cout << "what is the new class ID" << endl; cin >> temp;
      arrayOfclasses[num].updateID(temp);
      break;
    case('b'):
      cout << "what is the new Maximum Capicty" << endl; cin >> temp;
      arrayOfclasses[num].updateMaximumCapacity(temp);
      break;
    case('c'):
      cout << "what is the new roomnumber" << endl; cin >> temp;
      arrayOfclasses[num].updateRoomNumber(temp);
      break;
    case('d'):
      cout << "what is the new class name" << endl; cin >> tem;
      arrayOfclasses[num].updateClassName(tem);
      break;
    case('e'):
      cout << "what is the new class time" << endl; cin >> tem;
      arrayOfclasses[num].updateClasstime(tem);
      break;
    case('g'):
      cout << "what is the new class date" << endl; cin >> tem;
      arrayOfclasses[num].updateClassdate(tem);
      break;
  }

}

void bookAClass(fitnessClass * arrayOfclasses, int& size, member memb){ //book a class
  int num = -1; int id;
  do{
  cout << "Input the class's ID:" << endl; cin >> id;
  for(int i = 0; i < size-1; i++){
    if( id == arrayOfclasses[i].getID()){
      num = i; break;
    }
  }
  if(num == -1){
    cout << "no such ID idenitified, please try again!" << endl;
    //bookAClass(arrayOfclasses, size, memb);
  }
  }while(id == -1); //repeat while the ID was not found
  if(arrayOfclasses[num].getlistcount() != arrayOfclasses[num].getMaximumCapacity()){
    arrayOfclasses[num].listOfmembers[arrayOfclasses[num].getlistcount()] = memb; //adding the current member to the list of members at the number listcount
    arrayOfclasses[num].incrementListcount();
    cout << "booking was done successfully" << endl;
  }else{
    cout << "booking unsuccessful! (class does not exist or maximum capacity acheived)" << endl;
  }
}

void viewClassesWithVacancies(fitnessClass * arrayOfclasses, int& size){//outputting the all class's details
  cout << "displaying: " << endl;
  for(int i = 0; i < size-1; i++){
    if(arrayOfclasses[i].getlistcount() != arrayOfclasses[i].getMaximumCapacity() && arrayOfclasses[i].getworking() ){
      arrayOfclasses[i].display();
      arrayOfclasses[i].membersInClass();
    }
  }

}

void cancelBooking(fitnessClass * arrayOfclasses, int& size, member memb){
  int num = -1; int id;
  cout << "Input the class's ID:" << endl; cin >> id;

  for(int i = 0; i < size-1; i++){
    if( id == arrayOfclasses[i].getID()){
      num = i; break;
    }
  }
  if(num == -1){
    cout << "no such ID idenitified, please try again!" << endl;
    cancelBooking(arrayOfclasses, size, memb);
  }

  bool isthere(0);
  for(int i = 0; i < arrayOfclasses[num].getlistcount(); i++){
    if(arrayOfclasses[num].listOfmembers[i].getmemberID() == memb.getmemberID()){
      arrayOfclasses[num].listOfmembers[i] = member();
      isthere = 1;break;
    }
  }
  if(!isthere)
    cout << "member not registerred in the class" << endl;

  // if(arrayOfclasses[num].getlistcount() != arrayOfclasses[num].getMaximumCapacity()){
  //   arrayOfclasses[num].listOfmembers[arrayOfclasses[num].getlistcount()] = memb;
  //   arrayOfclasses[num].incrementListcount();
  // }else
  //   cout << "maximum capcity acheived, booking unsuccessful!" << endl;

}

//____functions
void refresharray(admin* a, int& size); //inializing the functions to increase the size of the array of admin
void refresharraym(member* a, int& size); //inializing the functions to increase the size of the array of admin
void registerAdmin(admin * arrayOfadmins, int & s ){ //registring a new admin
  //making the admin object
  string F,L;
  cout << "please enter the admin's first name: " << endl;
  cin >> F;
  cout << "please enter the admin's last name: " << endl;
  cin >> L;
  arrayOfadmins[s-1] = admin(F,L); //it will make a username and password for the names
  //refresharray(arrayOfadmins, s);
  s++;
}
void registerMember(member * arrayOfmembers, int& ss){ //registring a new member
  string F,L;
  cout << "please enter the member's first name: " << endl;
  cin >> F;
  cout << "please enter the member's last name: " << endl;
  cin >> L;
  arrayOfmembers[ss-1] = member(F,L); //it will make a username and password for the names
  //refresharraym(arrayOfmembers, ss);
  ss++;
}
void adminLogin(admin * arrayOfadmins, member * arrayOfmembers, int& s, int& ss, fitnessClass * arrayOfclasses, int& sss){
  bool isuserthere(0);
    while(!isuserthere){
      string user , pass; //loogging in
      cout << "please enter your username: " << endl;
      cin >> user;
      cout << "please enter your password: " << endl;
      cin >> pass;
      

      for(int i = 0; i < s-1; i++){
        if( arrayOfadmins[i].getUsername() == user && arrayOfadmins[i].getPassword() == pass ){ //checking if the username and password already exitss
          isuserthere = 1; break; 
        }
      }
      if(!isuserthere){
        cout << "username or password invalid, please try again." << endl; //i
        //adminLogin(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss);

      }else{
        cout << "admin login in successful" << endl << endl;
      }
    }

    int ch;
    do{
      // a list for each option the user have
    cout << "The list of available operations for admins:" << endl;
    cout << "1) register a new member" << endl;
    cout << "2) register a new admin" << endl;
    cout << "3) add a fitness class" << endl;
    cout << "4) delete a fitness class" << endl;
    cout << "5) update the details of a fitness class" << endl;
    cout << "6) display the class with vacancies" << endl;
    cout << "7) quit the program" << endl;

     cin >> ch;
    switch(ch){
      //calling a function for each of the admin's selection
      case 1:
        registerMember(arrayOfmembers, ss);
        cout << "done!" << endl;
        break;
      case 2:
        registerAdmin(arrayOfadmins,s);
        cout << "done!" << endl;
        break;
      case 3:
        addFitnessClass(arrayOfclasses,sss);
        cout << "done!" << endl;
        break;
      case 4:
        deleteFitnessClass(arrayOfclasses,sss);
        cout << "done!" << endl;
        break;
      case 5:
        updateClassDetails(arrayOfclasses,sss);
        cout << "done!" << endl;
        break;
      case 6:
        viewClassesWithVacancies(arrayOfclasses,sss);
        cout << "done!" << endl;
        break;
      case 7:
        //adminLogin(arrayOfadmins,s);
        cout << "quitting!" << endl;
        break;
      default:
        cout << "invalid input try again." << endl;
        //adminLogin(arrayOfadmins, arrayOfmembers, s, ss,  arrayOfclasses, sss);
        break;
    }
    }while(  ch != 7);


}
void memberLogin(member * arrayOfmembers, int& ss, fitnessClass * arrayOfclasses, int& sss){
    int num;
   bool isuserthere(0);
    while(!isuserthere){
      string user , pass;
      cout << "please enter your username: " << endl;
      cin >> user;
      cout << "please enter your password: " << endl;
      cin >> pass;
    
      //getting username and password
      for(int i = 0; i < ss-1; i++){
        if( arrayOfmembers[i].getUsername() == user && arrayOfmembers[i].getPassword() == pass ){ //checking if the username and password already exitss so the program can log in the user
          cout << "login successful" << endl;
          num = i; isuserthere = 1; break;
        }
      }
    
      if(!isuserthere){ //let the user know if it does exist
        cout << "username or password invalid, please try again." << endl;
        //memberLogin(arrayOfmembers,ss, arrayOfclasses, sss);
      }else{
        cout << "member login in successful" << endl << endl;
      }
    }

    int ch;
    do{
    //providing the member of the list of options he have to choose from
    cout << "The list of available operations for members:" << endl;
    cout << "1) book a class" << endl;
    cout << "2) cancel booking" << endl;
    cout << "3) display the class with vacancies" << endl;
    cout << "4) quit the program " << endl;
    cin >> ch;
    switch(ch){ //letting the user choose what functions to select from
      case 1:
        bookAClass(arrayOfclasses, sss, arrayOfmembers[num]);
        //cout << "done!" << endl;
        break;
      case 2:
        cancelBooking(arrayOfclasses, sss, arrayOfmembers[num]);
        cout << "done!" << endl;
        break;
      case 3:
        viewClassesWithVacancies(arrayOfclasses, sss);
        cout << "done!" << endl;
        break;
      case 4:
        cout << "quitting!" << endl;
        break;
      default:
        cout << "invalid input try again." << endl;
        //memberLogin(arrayOfmembers, ss,  arrayOfclasses, sss);
        break;
    }
    }while(  ch != 4);

}
void login(admin * arrayOfadmins, member * arrayOfmembers, int& s, int& ss, fitnessClass * arrayOfclasses, int& sss ){
  // the basic loging function that selects whether the user is and admin or a member
  cout << "please enter the category of your account before logging in: [admin / member]" << endl;
  string ans; cin >> ans;
  if(ans == "admin"){ // i can put this in a function
    adminLogin(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss); //logging an admin in
  }else if(ans == "member"){
    memberLogin(arrayOfmembers,ss, arrayOfclasses, sss); //logging a member in
  }else{
    cout << "Invalid, please enter a valid category" << endl;
    login(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss); //calling the same function again if the input is not valid
  }
 
}
void saveInfile(admin * arrayOfadmins, member * arrayOfmembers, int& s, int& ss, fitnessClass * arrayOfclasses, int& sss ){
  ofstream classesFile; //making af file to write in
  classesFile.open("FitnessClassesTable.txt");
  if(classesFile.fail()){
    cerr << "FitnessClasstable file could not be created" << endl; //in case the file could not be openned
  }
  for(int i = 0; i < sss-1; i ++){
    arrayOfclasses[i].displayForFile(classesFile); //outputting all details in the array in it
  }
  classesFile.close(); //close the file

  ofstream adminFile;
  adminFile.open("AdminsTable.txt");
  if(adminFile.fail()){
    cerr << "AdminsTable file could not be created" << endl; //in case the file could not be openned
  }
  for(int i = 0; i < s-1; i ++){
    arrayOfadmins[i].displayToFile(adminFile); //outputting all details in the array in it
  }
  adminFile.close(); //closing the file

  ofstream memberfile; //making a file to write in
  memberfile.open("MembersTable.txt"); 
  if(memberfile.fail()){ //in case the openning faild
    cerr << "MembersTable file could not be created" << endl;
  }
  for(int i = 0; i < ss-1; i ++){
    arrayOfmembers[i].displayToFile(memberfile); //putting the details into the file
  }
  memberfile.close(); //closing the file

}

int main(){
  srand ( time(NULL) );
  //the s acts as pointer to where we should fill in the array
  int s = 2;  
  int ss = 1;
  int sss = 1;
  //inializing the dynamically allocated arrays with size 10
  admin * arrayOfadmins = new admin[100]; 
  member * arrayOfmembers = new member[100];
  fitnessClass * arrayOfclasses = new fitnessClass[100];
  
  //making the default admin user
  arrayOfadmins[0].setAdminID(1);
  arrayOfadmins[0].setFirstName("admin");
  arrayOfadmins[0].setLastName("admin");
  arrayOfadmins[0].setUsername("admin1");
  arrayOfadmins[0].setPassword("admin1");
  cout << "welcome to the fitness management system!" << endl;
  
  login(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss); //calling the login function so the user can choose between member and admin
  int a = 1;
  
   //i think that's illegal
  do{ //it acts as a log out from member or admin
    cout << "do you want to go back to the main menu [1 for yes, 0 for no]?" << endl;
    cin >> a;
    if(a == 1)
      login(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss);
    else if(a != 1 && a != 0){
      a = 1;
      cout << "Invalid input!"<< endl << endl;
    }
  }while(a == 1);
  saveInfile(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss);
  delete [] arrayOfadmins;
  delete [] arrayOfmembers;
  delete [] arrayOfclasses;
  
  return 0;
}
 

void refresharray(admin* a, int& size){ //increases the size of the array
  size++;
  admin * array = new admin[size];
  for(int i = 0; i < size-1; i++ ){
    array[i] = a[i];
  } 
  delete [] a;
  a = array;
  
}

void refresharraym(member* a, int& size){ //increases the size of the array
  size++;
  member * array = new member[size];
  for(int i = 0; i < size-1; i++ ){
    array[i] = a[i];
  } 
  delete [] a;
  a = array;
  
}

fitnessClass*  refresharrayf(fitnessClass* a, int& size){ //increases the size of the array
  fitnessClass * array = new fitnessClass[size];
  for(int i = 0; i <= size-1; i++ ){
    array[i] = a[i];
  } 
  delete [] a;
  size++;
  return array;
}

int generateID(){ //generating a random digits
  return rand()%10000;
}

string addSI(string a, int b){ //adding to strings together
  return a + to_string(b);
}


string lower(string a){ //lowering the characters down
  for(int i = 0; i < a.size(); i++){
    if(a[i]>=65 && a[i]<=92)
      {
	      a[i]=a[i]+32; //because when you add 32 into an upper letter it becomes lower
      }
  }
  return a;
}