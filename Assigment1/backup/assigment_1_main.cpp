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
      string FirstName, LastName, Username, Password;
      int AdminID;
    public:
      admin(string a, string b):FirstName(a), LastName(b){
        setAdminID(generateID());
        setUsername( addSI( lower( a ), getAdminID()) );
        setPassword(addSI(lower(b),getAdminID()));
        display();
        
      }
      admin(){}

  
  
      // setters:
      void setAdminID(int x){
          AdminID = x;
      }
      void setFirstName(string x){
          FirstName = x;
      }
      void setLastName(string x){
          LastName = x;
      }
      void setUsername(string x){
          Username = x;
      }
      void setPassword(string x){
          Password = x;
      }
      
      //getters:
      int getAdminID(){ return AdminID;}
      string getFirstName(){return FirstName;}
      string getLastName(){return LastName;}
      string getUsername(){return Username;}
      string getPassword(){return Password;}

      //functions:
      void makeAdmin(string a, string b){
        setFirstName(a); setLastName(b);
        setAdminID(generateID());  
        setUsername( addSI( lower( a ), getAdminID()) );
        setPassword(addSI(lower(b),getAdminID()));
      
        
      }

      void display(){
        cout <<  to_string(getAdminID()) <<", " << getFirstName() << ", " << getLastName() << ", ";
        cout << getUsername() << ", " << getPassword() << endl;
          
      }

      void displayToFile(ofstream& a){
        a <<  to_string(getAdminID()) <<", " << getFirstName() << ", " << getLastName() << ", ";
        a << getUsername() << ", " << getPassword() << endl;
          
      }


      


};

class member{
    //Member ID, First name, Last name, Username, Password
    private:
    string FirstName, LastName, Username, Password;
    int MemberID;
    bool working;
    public:
      member(string a, string b):FirstName(a), LastName(b){
        setmemberID(generateID());
        setUsername( addSI( lower( a ), getmemberID()) );
        setPassword(addSI(lower(b),getmemberID()));
        display();
        working = 1;
      }
      member(){working = 0;}

  
  
      // setters:
      void setmemberID(int x){
          MemberID = x;
      }
      void setFirstName(string x){
          FirstName = x;
      }
      void setLastName(string x){
          LastName = x;
      }
      void setUsername(string x){
          Username = x;
      }
      void setPassword(string x){
          Password = x;
      }
      
      //getters:
      int getmemberID(){ return MemberID;}
      string getFirstName(){return FirstName;}
      string getLastName(){return LastName;}
      string getUsername(){return Username;}
      string getPassword(){return Password;}

      //functions:
      void makemember(string a, string b){
        setFirstName(a); setLastName(b);
        setmemberID(generateID());  
        setUsername( addSI( lower( a ), getmemberID()) );
        setPassword(addSI(lower(b),getmemberID()));
        
      }

      void display(){
        cout <<  to_string(getmemberID()) <<", " << getFirstName() << ", " << getLastName() << ", ";
        cout << getUsername() << ", " << getPassword() << endl;
          
      }
      void displayToFile(ofstream& a){
        a <<  to_string(getmemberID()) <<", " << getFirstName() << ", " << getLastName() << ", ";
        a << getUsername() << ", " << getPassword() << endl;
          
      }

      bool isworking(){return working;}
    


};

class fitnessClass{
    private:
        int ClassID, MaximumCapacity, roomNumber;
        string ClassName, Classtime, Classdate;
        // class time and class date to be created
        bool working;
        int listCount;

    public:
      member * listOfmembers;
      fitnessClass(int ID, int MC, int RN, string CN, string CT, string CD){
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
      fitnessClass(){working = 0;}

      // void addFitnessClass(int ID, int MC, int RN, string CN, string CT, string CD){
      //   ClassID = ID;
      //   MaximumCapacity = MC;
      //   roomNumber = RN;
      //   ClassName = CN;
      //   Classtime = CT;
      //   Classdate = CD; 
      // }
      
      


      int getID(){
        return ClassID;
      }
      bool getworking(){return working;}
      
      void updateClassdate(string a){
        Classdate = a;
      }

      void updateClasstime(string a){
        Classtime = a;
      }

      void updateClassName(string a){
        ClassName = a;
      }

      void updateRoomNumber(int a){
        roomNumber = a;
      }

      void updateMaximumCapacity(int a){
        MaximumCapacity = a;
      }

      void updateID(int a){
        ClassID = a;
      }

      void display(){
        cout << "Class Name: " << ClassName << endl;
        cout << "Class time: " << Classtime << endl;
        cout << "Class date: " << Classdate << endl;
        cout << "roomnumber: " << roomNumber<< endl;
        cout << "Class ID:   "   << ClassID   << endl;
        cout << "============================================" << endl;
      }

      void displayForFile(ofstream& a){
        a << ClassID << ", "<< ClassName << ", " << Classdate << ", "<< Classtime<< ", "<< MaximumCapacity << ", " << roomNumber << endl;
      }

      void membersInClass(){
        int z = 0;
        
        cout << "members for class "<< ClassName << ": " << endl;
        

        for(int i = 0; i < listCount; i++){
          if(listOfmembers[i].isworking()){          
            z++;
            cout << i+1 << "- " << listOfmembers[i].getFirstName() << " " << listOfmembers[i].getLastName() << endl ;
          }
        }
        cout << "---" << endl;
      }


      void incrementListcount(){listCount++;}
      int getlistcount(){ return listCount;}
      int getMaximumCapacity(){return MaximumCapacity;}
};

fitnessClass* refresharrayf(fitnessClass* a, int& size);

void addFitnessClass(fitnessClass * arrayOfclasses, int& size ){
  int ID; int MC; int RN; string CN; string CT; string CD;
  cout << "What is the class's ID?" << endl;
  cin >> ID;

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

  arrayOfclasses[size - 1] = fitnessClass(ID,MC,RN,CN,CT,CD);
  //cout << ">>>" << size << endl;
  arrayOfclasses[size-1].display();
  size++;
  //arrayOfclasses = refresharrayf(arrayOfclasses, size);
}
//not working ->
void deleteFitnessClass(fitnessClass * arrayOfclasses, int& size){
  int ID;
  cout << "what is the class's ID?" << endl;
  cin >> ID;
  int num = -1;
  for(int i = 0; i < size-1; i++){
    if( ID == arrayOfclasses[i].getID()){
      arrayOfclasses[i] = fitnessClass(); num = 0;
      break;
    }
  }
  if(num == -1){
    cout << "no such ID idenitified, please try again!" << endl;
    deleteFitnessClass(arrayOfclasses, size);
  }
}

void updateClassDetails(fitnessClass * arrayOfclasses, int& size){
  int num = -1;
  int ID; cout << "what is the class's ID?" << endl;
  cin >> ID;
  for(int i = 0; i < size-1; i++){
    if( ID == arrayOfclasses[i].getID()){
      num = i; break;
    }
  }

  if(num == -1){
    cout << "no such ID idenitified, please try again!" << endl;
    updateClassDetails(arrayOfclasses, size);
  }

  cout << "what detail do you want:" << endl;
  cout << "a- ClassID" << endl;
  cout << "b- Maximum Capacity" << endl;
  cout << "c- roomNumber" << endl;
  cout << "d- class name" << endl;
  cout << "e- class time" << endl;
  cout << "g- class date" << endl;
  char ch; cin >> ch;
  int temp; string tem;
  switch (ch){
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

void bookAClass(fitnessClass * arrayOfclasses, int& size, member memb){
  int num = -1; int id;
  cout << "Input the class's ID:" << endl; cin >> id;

  for(int i = 0; i < size-1; i++){
    if( id == arrayOfclasses[i].getID()){
      num = i; break;
    }
  }
  if(num == -1){
    cout << "no such ID idenitified, please try again!" << endl;
    bookAClass(arrayOfclasses, size, memb);
  }
  if(arrayOfclasses[num].getlistcount() != arrayOfclasses[num].getMaximumCapacity()){
    arrayOfclasses[num].listOfmembers[arrayOfclasses[num].getlistcount()] = memb;
    arrayOfclasses[num].incrementListcount();
    cout << "booking was done successfully" << endl;
  }else{
    cout << "booking unsuccessful! (class does not exist or maximum capacity acheived)" << endl;
  }
}
// useless memmbers in class shit is here
void viewClassesWithVacancies(fitnessClass * arrayOfclasses, int& size){
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
void refresharray(admin* a, int& size);
void refresharraym(member* a, int& size);
void registerAdmin(admin * arrayOfadmins, int & s ){
  string F,L;
  cout << "please enter the admin's first name: " << endl;
  cin >> F;
  cout << "please enter the admin's last name: " << endl;
  cin >> L;
  arrayOfadmins[s-1] = admin(F,L);
  //refresharray(arrayOfadmins, s);
  s++;
}
void registerMember(member * arrayOfmembers, int& ss){
  string F,L;
  cout << "please enter the member's first name: " << endl;
  cin >> F;
  cout << "please enter the member's last name: " << endl;
  cin >> L;
  arrayOfmembers[ss-1] = member(F,L);
  //refresharraym(arrayOfmembers, ss);
  ss++;
}
void adminLogin(admin * arrayOfadmins, member * arrayOfmembers, int& s, int& ss, fitnessClass * arrayOfclasses, int& sss){

  bool isuserthere(0);
    while(!isuserthere){
      string user , pass;
      cout << "please enter your username: " << endl;
      cin >> user;
      cout << "please enter your password: " << endl;
      cin >> pass;
      
  
      for(int i = 0; i < s-1; i++){
        if( arrayOfadmins[i].getUsername() == user && arrayOfadmins[i].getPassword() == pass ){
          isuserthere = 1; break;
        }
      }
      if(!isuserthere){
        cout << "username or password invalid, please try again." << endl;
        adminLogin(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss);

      }
    }

    int ch;
    do{

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
    
  
      for(int i = 0; i < ss-1; i++){
        if( arrayOfmembers[i].getUsername() == user && arrayOfmembers[i].getPassword() == pass ){
          cout << "login successful" << endl;
          num = i; isuserthere = 1; break;
        }
      }
      if(!isuserthere){
        cout << "username or password invalid, please try again." << endl;
        memberLogin(arrayOfmembers,ss, arrayOfclasses, sss);
      }
    }

    int ch;
    do{

    cout << "The list of available operations for members:" << endl;
    cout << "1) book a class" << endl;
    cout << "2) cancel booking" << endl;
    cout << "3) display the class with vacancies" << endl;
    cout << "4) quit the program " << endl;
    cin >> ch;
    switch(ch){
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

  cout << "please enter the category of your account before logging in: [admin / member]" << endl;
  string ans; cin >> ans;
  if(ans == "admin"){ // i can put this in a function
    adminLogin(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss);
  }else if(ans == "member"){
    memberLogin(arrayOfmembers,ss, arrayOfclasses, sss);
  }else{
    cout << "Invalid, please enter a valid category" << endl;
    login(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss);
  }
 
}
void saveInfile(admin * arrayOfadmins, member * arrayOfmembers, int& s, int& ss, fitnessClass * arrayOfclasses, int& sss ){
  ofstream classesFile;
  classesFile.open("FitnessClassesTable.txt");
  if(classesFile.fail()){
    cerr << "FitnessClasstable file could not be created" << endl;
  }
  for(int i = 0; i < sss-1; i ++){
    arrayOfclasses[i].displayForFile(classesFile);
  }
  classesFile.close();

  ofstream adminFile;
  adminFile.open("AdminsTable.txt");
  if(adminFile.fail()){
    cerr << "AdminsTable file could not be created" << endl;
  }
  for(int i = 0; i < s-1; i ++){
    arrayOfadmins[i].displayToFile(adminFile);
  }
  adminFile.close();

  ofstream memberfile;
  memberfile.open("MembersTable.txt");
  if(memberfile.fail()){
    cerr << "MembersTable file could not be created" << endl;
  }
  for(int i = 0; i < ss-1; i ++){
    arrayOfmembers[i].displayToFile(memberfile);
  }
  memberfile.close();

}

int main(){
  //srand ( time(NULL) );
  int s = 2;  //everytime we add new admin we are gonna call the refresher / we add the member the refresh
  int ss = 1;
  int sss = 1;
  admin * arrayOfadmins = new admin[100]; 
  member * arrayOfmembers = new member[100];
  fitnessClass * arrayOfclasses = new fitnessClass[100];
  
  arrayOfadmins[0].setAdminID(1);
  arrayOfadmins[0].setFirstName("admin");
  arrayOfadmins[0].setLastName("admin");
  arrayOfadmins[0].setUsername("admin1");
  arrayOfadmins[0].setPassword("admin1");
  cout << "welcome to the fitness management system!" << endl;
  
  login(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss);
  int a = 1;
  
   //i think that's illegal
  do{
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

  return 0;
}
 

void refresharray(admin* a, int& size){
  size++;
  admin * array = new admin[size];
  for(int i = 0; i < size-1; i++ ){
    array[i] = a[i];
  } 
  delete [] a;
  a = array;
  
}

void refresharraym(member* a, int& size){
  size++;
  member * array = new member[size];
  for(int i = 0; i < size-1; i++ ){
    array[i] = a[i];
  } 
  delete [] a;
  a = array;
  
}

fitnessClass*  refresharrayf(fitnessClass* a, int& size){
  fitnessClass * array = new fitnessClass[size];
  for(int i = 0; i <= size-1; i++ ){
    array[i] = a[i];
  } 
  delete [] a;
  size++;
  return array;
}

int generateID(){
  return rand()%10000;
}


string addSI(string a, int b){
  return a + to_string(b);
}


string lower(string a){
  for(int i = 0; i < a.size(); i++){
    if(a[i]>=65 && a[i]<=92)
      {
	      a[i]=a[i]+32;
      }
  }
  return a;
}