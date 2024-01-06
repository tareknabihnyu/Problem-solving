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
void askforusernamenpassword();



//Node stuff========================================================================================================
template  <typename E>
class DoublyLinkedList;
template  <typename E>
class Node
{
	private:
		E elem; //data element (type string in this case)
		Node* next; //Link (pointer) to the next Node
		Node* prev; //Link (pointer) to the previous Node
		friend class DoublyLinkedList<E>;
		
	public:
		Node(): next(NULL), prev(NULL)
		{}
		Node(E elem) : elem(elem), next(NULL), prev(NULL)
		{}
};
template  <typename E>
class DoublyLinkedList
{
	private:
		Node<E>* head; 	// pointer to the head of List
		Node<E>* tail; 	// pointer to the tail of List
		int size;
	public:
		DoublyLinkedList (); // empty list constructor
		~DoublyLinkedList (); // destructor to clean up all nodes
		bool empty() ; // is list empty?
		E& front(); // get the value (element) from front Node of list
		E& back() ;  // get the value (element) from last Node of the List 
		void addBefore(Node<E> *ptr,  E elem);	 //add a new node before ptr
		void addFront( E elem); // add a new node to the front of list
		void addBack( E  elem); //add a new node to the back of the list
		void removeFront(); // remove front node from list
		void removeBack();  // remove last node from list
		void displayadmin();
		void displaymember();
		void displayfitness();
		E& findTheNumber(int f);
		int givesize(){return size;}
		void removebefore(Node<E> *ptr){
			//Node<E>* u = ptr;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			delete ptr;
		}
		Node<E>* findTherefrence(int f){
			int ff = 0;
			Node<E> * a = head;              
			do{
				a = a->next;  
				if(a == NULL || a->next == NULL){
					break;                  //if a is null then the seris had ended
				}
				if(f == ff)
					break;
				ff++;
			}while( a->next != NULL );          
			return a;
		}
};
//END-Node stuff==================================================================================================================================



//fix the display stuff
//random numbers






//admin class================================================================================================================================
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
      void setEverything(int ID, string firstname, string lastname, string username, string password);
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
void admin::setEverything(int ID, string firstname, string lastname, string username, string password){
	AdminID = ID;
	FirstName = firstname;
	LastName = lastname;
	Username = username;
	Password = password;
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
  a <<  to_string(getAdminID()) <<"," << getFirstName() << "," << getLastName() << ",";
  a << getUsername() << "," << getPassword();
    
}
//End admin class================================================================================================================================





//Members Class begin============================================================================================================================
class member{
    //Member ID, First name, Last name, Username, Password
    private:
    string FirstName, LastName, Username, Password;
    int MemberID;
    bool working;
    public:
      //inializing the functions
      member(string a, string b);
	  member(int ID, string firstname, string lastname, string username, string password);
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
	  void setEverything(int ID, string firstname, string lastname, string username, string password);
      void display();
      void displayToFile(ofstream& a);
      bool isworking(); //to check whether the function has variables stored in it or not
	  int getID();

	

};
member::member(string a, string b):FirstName(a), LastName(b){
        //same as in the admins class.. generating random ID and sticking it to the username and generating new password and sticking it to the password
        setmemberID(generateID());
        setUsername( addSI( lower( a ), getmemberID()) ); //adding the firstname to the username with IDs sticked at it
        setPassword(addSI(lower(b),generateID())); //adding teh lastname to the password with random digits sticking in it
        display();
        working = 1; //letting the class object know that it has variables stored in it
      }
member::member(int ID, string firstname, string lastname, string username, string password){
        //same as in the admins class.. generating random ID and sticking it to the username and generating new password and sticking it to the password
        MemberID = ID;
		FirstName = firstname;
		LastName = lastname;
		Username = username;
		Password = password;
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
  a <<  to_string(getmemberID()) <<"," << getFirstName() << "," << getLastName() << ",";
  a << getUsername() << "," << getPassword();   
}
bool member::isworking(){return working;} //to know whether the function is working
void member::setEverything(int ID, string firstname, string lastname, string username, string password){
	MemberID = ID;
	FirstName = firstname;
	LastName = lastname;
	Username = username;
	Password = password;
}
int member::getID(){return MemberID;}
//Members class end==============================================================================================================================




//FitnessClass begins========================================================================================================================================
class fitnessClass{
    private:
        //inializing the variables that will be used
        int ClassID, MaximumCapacity, roomNumber;
        string ClassName, Classtime, Classdate;
        bool working;
        int listCount;

				
    public:
		//inializing the functions
		DoublyLinkedList<member>* membersInClass;
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
		void displaya();
		void displayForFile(ofstream& a);
		void allmembersInClass();
		void incrementListcount();
		void geteverything(int ID, int MC, int RN, string CN, string CT, string CD);
		int getlistcount();
		int getMaximumCapacity();
		int getroomnumber(){return roomNumber;}
		string getname(){return ClassName;}
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
}
//fitnessClass::~fitnessClass(){delete [] listOfmembers;}//deallocating the dynamically allocated list
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
  	// cout << "Class Name: " << ClassName << endl;
  	// cout << "Class time: " << Classtime << endl;
  	// cout << "Class date: " << Classdate << endl;
  	// cout << "roomnumber: " << roomNumber<< endl;
  	// cout << "Class ID:   "   << ClassID   << endl;
	// cout << "MaximumCap: " << MaximumCapacity << endl;
  	// cout << "============================================" << endl;
	cout << ClassID << ", " << ClassName << ", " << Classdate << ", " << Classtime << ", " << MaximumCapacity << ", " << roomNumber;
	cout << ", " << "[";
	for(int i = 0; i < membersInClass->givesize(); i++){
		cout << membersInClass->findTheNumber(i).getID();
		if(i == membersInClass->givesize()-1){}
		else{cout << ", ";} 
	}
	cout << "]" << endl;
}
void fitnessClass::displaya(){ //displaying the class's details
  cout << "Class Name: " << ClassName << endl;
  cout << "Class time: " << Classtime << endl;
  cout << "Class date: " << Classdate << endl;
  cout << "roomnumber: " << roomNumber<< endl;
  cout << "Class ID:   "   << ClassID   << endl;
  cout << "============================================" << endl;
}
void fitnessClass::displayForFile(ofstream& a){ //saving the details into a given file
  	a << ClassID << "," << ClassName << "," << Classdate << "," << Classtime << "," << MaximumCapacity << "," << roomNumber;
	a << "," << "[";
	for(int i = 0; i < membersInClass->givesize(); i++){
		a << membersInClass->findTheNumber(i).getID();
		if(i == membersInClass->givesize()-1){}
		else{a << ",";} 
	}
	a << "]" ;
}
void fitnessClass::allmembersInClass(){ //outputting the names of the members in a certain class
	// int z = 0;
	// if(listCount != 0){ //checking if the list is empty or not
	// 	cout << "> members for class "<< ClassName << ": " << endl;
	// 	for(int i = 0; i < listCount; i++){
	// 	if(listOfmembers[i].isworking()){          
	// 		z++; //z is to give an accurate number of members in the list in case a member cancelled his booking
	// 		cout << z << "- " << listOfmembers[i].getFirstName() << " " << listOfmembers[i].getLastName() << endl ; //outputting first and last name
	// 	}
	// 	}
	// }else{
	// 	cout << "> class is empty" << endl;
	// }
	// cout << "---" << endl;
	membersInClass->displaymember(); 
}
void fitnessClass::incrementListcount(){listCount++;} //incrementing the the number of members in the list
void fitnessClass::geteverything(int ID, int MC, int RN, string CN, string CT, string CD){
	ClassID = ID;
	MaximumCapacity = MC;
	roomNumber = RN;
	ClassName = CN;
	Classtime = CT;
	Classdate = CD; 
	working = 1;
	listCount = 0;
} //incrementing the the number of members in the list
int fitnessClass::getlistcount(){ return listCount;}  //getting the number of members in the list
int fitnessClass::getMaximumCapacity(){return MaximumCapacity;} //getting the maximum capacity 
//FitnessClass Ends========================================================================================================================================







DoublyLinkedList<admin> adminlist;
DoublyLinkedList<member> memberlist;
DoublyLinkedList<fitnessClass> fitnesslist;

//main functions=======================================================================================================================================

void registerAdmin(string firstname, string lastname){ //registring a new admin
	adminlist.addFront(admin(firstname,lastname)); 
}
void registerMember(string firstname, string lastname){ //registring a new admin
	memberlist.addFront(member(firstname,lastname)); 
}
void viewMemberList(){
	memberlist.displaymember();
}
void viewClassesWithVacancies(){//outputting the all class's details
  cout << "displaying: " << endl;
  for(int i = 0; i < fitnesslist.givesize(); i++){
    if(fitnesslist.findTheNumber(i).getlistcount() != fitnesslist.findTheNumber(i).getMaximumCapacity() && fitnesslist.findTheNumber(i).getworking() ){
		fitnesslist.findTheNumber(i).display();
    }
  }
}
void addFitnessClass(){ //adding a new class
	int ID; int MC; int RN; string CN; string CT; string CD;
	bool p = 1;
	do{
	p =1 ;
	cout << "What is the class's ID?" << endl;
	cin >> ID;

	for(int i = 0; i < fitnesslist.givesize(); i++){
		if( ID == fitnesslist.findTheNumber(i).getID()){
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

	fitnessClass b;
	b.geteverything(ID,MC,RN,CN,CT,CD);
	b.membersInClass = new DoublyLinkedList<member>; 
	fitnesslist.addFront(b);
	b.display();
	// 
	// fitnesslist.findTheNumber(0).display();
}
void deleteFitnessClass(int class_id){
	int where = -1;
	for(int i = 0; i < fitnesslist.givesize(); i++){
		if( class_id == fitnesslist.findTheNumber(i).getID()){
			where = i;
		}
	}

	Node<fitnessClass>* jj = fitnesslist.findTherefrence(where);
	fitnesslist.removebefore(jj);
}

void updateClassDetails(int ID){ //updating the class's details
  int num = -1;  //to get where that arrayOfclasses exits
  do{
	  if(num  == -2){
		  cout << "enter the class's ID" << endl;
		cin >> ID;
	  }
  for(int i = 0; i < fitnesslist.givesize(); i++){
		if( ID == fitnesslist.findTheNumber(i).getID()){
	      num = i; break; 
    }
  }
  if(num == -1){
    cout << "no such ID idenitified, please try again!" << endl;
	num = -2;
  }
  }while(num < 0);//repeat while the ID does not exit
  
  //checking which detail the user wants to change
  cout << "what detail do you want:" << endl;
//  cout << "a- ClassID" << endl;
//  cout << "b- Maximum Capacity" << endl;
  cout << "c- roomNumber" << endl;
//  cout << "d- class name" << endl;
  cout << "e- class time" << endl;
  cout << "g- class date" << endl;
  char ch; cin >> ch;
  int temp; string tem;
  switch (ch){ //give the user the ability to change the details of the class by his choice
    //updating the class
    // case('a'):
    //   cout << "what is the new class ID" << endl; cin >> temp;
    //   fitnesslist.findTheNumber(num).updateID(temp);
    //   break;
    // case('b'):
    //   cout << "what is the new Maximum Capicty" << endl; cin >> temp;
    //   fitnesslist.findTheNumber(num).updateMaximumCapacity(temp);
    //   break;
    case('c'):
      cout << "what is the new roomnumber" << endl; cin >> temp;
      fitnesslist.findTheNumber(num).updateRoomNumber(temp);
      break;
    // case('d'):
    //   cout << "what is the new class name" << endl; cin >> tem;
    //   fitnesslist.findTheNumber(num).updateClassName(tem);
    //   break;
    case('e'):
      cout << "what is the new class time" << endl; cin >> tem;
      fitnesslist.findTheNumber(num).updateClasstime(tem);
      break;
    case('g'):
      cout << "what is the new class date" << endl; cin >> tem;
      fitnesslist.findTheNumber(num).updateClassdate(tem);
      break;
	default:
		cout << "invalid input.." << endl;
		updateClassDetails( ID);
  }

}
void changeClassCapacity(int ID, int new_cap){
	int num = -1;  //to get where that arrayOfclasses exits
	do{
		if(num  == -2){
			cout << "enter the class's ID" << endl;
			cin >> ID;
		}
	for(int i = 0; i < fitnesslist.givesize(); i++){
			if( ID == fitnesslist.findTheNumber(i).getID()){
			num = i; break; 
		}
	}
	if(num == -1){
		cout << "no such ID idenitified, please try again!" << endl;
		num = -2;
	}
	}while(num < 0);//repeat while the ID does not exit

	while(fitnesslist.findTheNumber(num).membersInClass->givesize() > new_cap){
		fitnesslist.findTheNumber(num).membersInClass->removeFront();
	}


	fitnesslist.findTheNumber(num).updateMaximumCapacity(new_cap);
}
void splitClass(int ID, int new_cap){
	int num = -1;  //to get where that arrayOfclasses exits
	do{
		if(num  == -2){
			cout << "enter the class's ID" << endl;
			cin >> ID;
		}
	for(int i = 0; i < fitnesslist.givesize(); i++){
			if( ID == fitnesslist.findTheNumber(i).getID()){
			num = i; break; 
		}
	}
	if(num == -1){
		cout << "no such ID idenitified, please try again!" << endl;
		num = -2;
	}
	}while(num < 0);//repeat while the ID does not exit

	fitnessClass temp;
	DoublyLinkedList<member>* members = new DoublyLinkedList<member> ;
	
	cout << "what is the capacity of the new class?" << endl;
	int secondClassCapp; cin >> secondClassCapp;
	string CT; string CD;
	cout << "what is the class's time?" << endl;
	cin >> CT;
	cout << "What is the class's date" << endl;
	cin >> CD;

	temp.geteverything(generateID(),secondClassCapp, fitnesslist.findTheNumber(num).getroomnumber(), fitnesslist.findTheNumber(num).getname() ,CT, CD);

	while(fitnesslist.findTheNumber(num).membersInClass->givesize() > new_cap){
		members->addFront(fitnesslist.findTheNumber(num).membersInClass->front());
		fitnesslist.findTheNumber(num).membersInClass->removeFront();
	}
	fitnesslist.findTheNumber(num).updateMaximumCapacity(new_cap);
	
	temp.membersInClass = members;

	fitnesslist.addFront(temp);


}

void bookAClass(int ID, member memb){ //book a class
		int num = -1;  //to get where that arrayOfclasses exits
		do{
			if(num  == -2){
				cout << "enter the class's ID" << endl;
				cin >> ID;
			}
			for(int i = 0; i < fitnesslist.givesize(); i++){
				if( ID == fitnesslist.findTheNumber(i).getID()){
				num = i; break; 
			}
		}
		if(num == -1){
			cout << "no such ID idenitified, please try again!" << endl;
			num = -2;
		}
		}while(num < 0);//repeat while the ID does not exit


		//repeat while the ID was not found
		if(fitnesslist.findTheNumber(num).getlistcount() != fitnesslist.findTheNumber(num).getMaximumCapacity()){
			fitnesslist.findTheNumber(num).membersInClass[fitnesslist.findTheNumber(num).getlistcount()].addFront(memb); //adding the current member to the list of members at the number listcount
			fitnesslist.findTheNumber(num).incrementListcount();
			cout << "booking was done successfully" << endl;
		}else{
			cout << "booking unsuccessful! (class does not exist or maximum capacity acheived)" << endl;
		}

	}

void cancelBooking(int ID, member memb){
  int num = -1;  //to get where that arrayOfclasses exits
		do{
			if(num  == -2){
				cout << "enter the class's ID" << endl;
				cin >> ID;
			}
			for(int i = 0; i < fitnesslist.givesize(); i++){
				if( ID == fitnesslist.findTheNumber(i).getID()){
				num = i; break; 
			}
		}
		if(num == -1){
			cout << "no such ID idenitified, please try again!" << endl;
			num = -2;
		}
		}while(num < 0);//repeat while the ID does not exit


  bool isthere(0);
  for(int i = 0; i < fitnesslist.findTheNumber(num).membersInClass->givesize(); i++){
    if(fitnesslist.findTheNumber(num).membersInClass->findTheNumber(i).getmemberID() == memb.getmemberID()){
      //fitnesslist.findTheNumber(num).membersInClass->displaymember();
	  fitnesslist.findTheNumber(num).membersInClass->findTheNumber(i) = member();
	  //fitnesslist.findTheNumber(num).membersInClass->displaymember();
      isthere = 1;
	  cout << "cancelling done successfully" << endl;
	  break;
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

void viewBookingList(member memb){
	for(int i = 0; i < fitnesslist.givesize(); i++){
		for(int z = 0; z < fitnesslist.findTheNumber(i).membersInClass->givesize(); z++){
			if(memb.getID() == fitnesslist.findTheNumber(i).membersInClass->findTheNumber(z).getID()){
				fitnesslist.findTheNumber(i).display();
				break;
			}
		}
	}

}

void adminLogin(string username, string password){
	bool isuserthere(0);
    while(!isuserthere){

      for(int i = 0; i < adminlist.givesize(); i++){
        if( adminlist.findTheNumber(i).getUsername() == username && adminlist.findTheNumber(i).getPassword() == password ){ //checking if the username and password already exitss
          isuserthere = 1; break; 
        }
      }
      if(!isuserthere){
        cout << "username or password invalid, please try again." << endl; //i
        //adminLogin(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss);
		      	cout << "please enter your username: " << endl;
     			cin >> username;
      			cout << "please enter your password: " << endl;
      			cin >> password;
      }else{
        cout << "admin login in successful" << endl << endl;
      }
    }

	int ch;
    do{
      // a list for each option the user have
    cout << "The list of available operations for admins:" << endl;
    cout << "1) register a new admin" << endl;
    cout << "2) register a new member" << endl;
    cout << "3) view the list of members" << endl;
    cout << "4) add a fitness class" << endl;
    cout << "5) delete a fitness class" << endl;
    cout << "6) update the details of a fitness class" << endl;
    cout << "7) update the capacity of a fitness class" << endl;
	cout << "8) Split a fitness class into two classes " << endl;
	cout << "9) view the classes with vaccancies " << endl;
	cout << "10) logout " << endl;
	cout << "11) quit the program " << endl;



    cin >> ch;
    switch(ch){
      //calling a function for each of the admin's selection
      case 1:{
	  	string F,L;
		cout << "please enter the admin's first name: " << endl;
		cin >> F;
		cout << "please enter the admin's last name: " << endl;
		cin >> L;
		registerAdmin(F,L);
        cout << "done!" << endl;
        break;
	  }
      case 2:{
	  	string F,L;
		cout << "please enter the member's first name: " << endl;
		cin >> F;
		cout << "please enter the member's last name: " << endl;
		cin >> L;
		registerMember(F,L);
        cout << "done!" << endl;
        break;
	  }
      case 3:
	  	viewMemberList();
        cout << "done!" << endl;
        break;
      case 4:
	  	addFitnessClass();
        cout << "done!" << endl;
        break;
      case 5:
	  	int a;
	  	cout << "enter the class's ID" << endl;
		cin >> a;
	  	deleteFitnessClass(a);
        cout << "done!" << endl;
        break;
      case 6:{
		int a;
	  	cout << "enter the class's ID" << endl;
		cin >> a;
		updateClassDetails(a);
      	cout << "done!" << endl;
        break;}
	case 7:{
		int a;
	  	cout << "enter the class's ID" << endl;
		cin >> a;
		int cap;
		do{
			cout << "enter the new capacity value" << endl;
			cin >> cap;
		}while(!(cap >= 5) && !(cap <= 15));
		changeClassCapacity(a,cap);
      	cout << "done!" << endl;
        break;}
	case 8:{
		int a;
	  	cout << "enter the class's ID" << endl;
		cin >> a;
		int cap;
		do{
			cout << "enter the new capacity value" << endl;
			cin >> cap;
		}while(!(cap >= 5) && !(cap <= 15));
		splitClass(a,cap);
      	cout << "done!" << endl;
        break;}
      case 9:
		viewClassesWithVacancies();
        cout << "done!" << endl;
        break;
	case 10:
		askforusernamenpassword();
		break;
    case 11:
		break;
	  default:
        cout << "invalid input try again." << endl;
        //adminLogin(arrayOfadmins, arrayOfmembers, s, ss,  arrayOfclasses, sss);
        break;
    }
    }while(  ch != 10 && ch != 11 );



}

void memberLogin(string username, string password){
	int num;
	bool isuserthere(0);
    while(!isuserthere){

      for(int i = 0; i < adminlist.givesize(); i++){
        if( memberlist.findTheNumber(i).getUsername() == username && memberlist.findTheNumber(i).getPassword() == password ){ //checking if the username and password already exitss
          num = i; isuserthere = 1; break; 
		  cout << memberlist.findTheNumber(i).getUsername() << " " <<  memberlist.findTheNumber(i).getPassword() << endl;
        }
      }
      if(!isuserthere){
        cout << "username or password invalid,, please try again." << endl; //i
        //adminLogin(arrayOfadmins, arrayOfmembers, s, ss, arrayOfclasses, sss);
			cout << "please enter your username: " << endl;
			cin >> username;
			cout << "please enter your password: " << endl;
			cin >> password;
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
	cout << "4) view booking " << endl;
	cout << "5) logout" << endl;
    cout << "6) quit the program " << endl;
	// view booking, logout
    cin >> ch;
    switch(ch){ //letting the user choose what functions to select from
		case 1:{
			int a;
			cout << "enter the class's ID" << endl;
			cin >> a;
			bookAClass(a,memberlist.findTheNumber(num));
			break;}
		case 2:{
			int a;
			cout << "enter the class's ID" << endl;
			cin >> a;
			cancelBooking(a,memberlist.findTheNumber(num));
			break;
			cout << "done!" << endl;
			break;}
		case 3:
			viewClassesWithVacancies();
			cout << "done!" << endl;
			break;
		case 4:
			viewBookingList(memberlist.findTheNumber(num));
			break;
		case 5:
			askforusernamenpassword();
			break;
		case 6:
			cout << "quitting!" << endl;
			break;
		default:
			cout << "invalid input try again." << endl;
			//memberLogin(arrayOfmembers, ss,  arrayOfclasses, sss);
			break;
    }
	}while(  ch != 6 && ch != 5);


}

void askforusernamenpassword(){
	cout << "please enter the category of your account before logging in: [admin / member]" << endl;
	string ans; cin >> ans;
	string username,password;
	cout << "please enter your username: " << endl;
	cin >> username;
	cout << "please enter your password: " << endl;
	cin >> password;
	if(ans == "admin"){
		adminLogin(username,password);
	}else if(ans == "member"){
		memberLogin(username,password);
	}

}

void saveInfile( ){
  ofstream classesFile; //making af file to write in
  classesFile.open("FitnessClasses.txt");
  if(classesFile.fail()){
    cerr << "FitnessClasstable file could not be created" << endl; //in case the file could not be openned
  }
  for(int i = 0; i < fitnesslist.givesize(); i ++){
    fitnesslist.findTheNumber(i).displayForFile(classesFile); //outputting all details in the array in it
	if(i < fitnesslist.givesize()-1) classesFile << endl;
  }
  classesFile.close(); //close the file

  ofstream adminFile;
  adminFile.open("Admins.txt");
  if(adminFile.fail()){
    cerr << "AdminsTable file could not be created" << endl; //in case the file could not be openned
  }
  for(int i = 0; i < adminlist.givesize(); i ++){
    adminlist.findTheNumber(i).displayToFile(adminFile); //outputting all details in the array in it
	if(i < adminlist.givesize()-1) adminFile << endl;
  }
  adminFile.close(); //closing the file

  ofstream memberfile; //making a file to write in
  memberfile.open("Members.txt"); 
  if(memberfile.fail()){ //in case the openning faild
    cerr << "MembersTable file could not be created" << endl;
  }
  for(int i = 0; i < memberlist.givesize(); i ++){
    memberlist.findTheNumber(i).displayToFile(memberfile); //putting the details into the file
    if(i < memberlist.givesize()-1) memberfile << endl;
  }
  memberfile.close(); //closing the file

}












//suporter functions========================================================================================================================
member findmember(int id){
	for(int i = 0; i < memberlist.givesize(); i++){
		if(id == memberlist.findTheNumber(i).getmemberID()){
			return memberlist.findTheNumber(i);
		}
	}
	member a;
	string b = "null";
	a.setEverything(0,b,b,b,b);
	return a;
}








//loading data from files====================================================================================================================
void loadfromAdmin(){

	ifstream adminfile;
	adminfile.open("Admins.txt");
	while(!adminfile.eof()){
		string a;
		adminfile >> a;
		int comma = 0; int indicator = 0;
		int ID ; string firstname,lastname,username,password;
		for(int i = 0; i <= a.size(); i++){
			if(a[i] == ',' || i == a.size() ){
				if(indicator == 0){
					string idd = "";
					for(int z = comma; z < i; z++){
						idd += a[z]; 
					}
					comma = i + 1;
					//cout << idd << endl << idd <<endl<< idd << endl;
					ID =  std::stoi(idd);
					indicator++;
				}
				else if(indicator == 1){
					firstname = "";
					for(int z = comma; z < i; z++){
						firstname += a[z]; 
					}
					comma = i + 1;
					indicator++;
				}else if(indicator == 2){
					lastname = "";
					for(int z = comma; z < i; z++){
						lastname += a[z];
					}
					comma = i + 1;
					indicator++;
				
				}else if(indicator == 3){
					username = "";
					for(int z = comma; z < i; z++){
						username += a[z];
					}
					comma = i + 1;
					indicator++;
				
				}else if(indicator == 4){
					password = "";
					for(int z = comma; z < i; z++){
						password += a[z] ;
					}
					comma = i + 1;
					indicator++;
				}

			}
		}
		admin u;
		u.setEverything(ID, firstname, lastname, username, password);
		adminlist.addFront(u);
		//cout << a << endl;
	}

}
void loadfromMembers(){

	ifstream adminfile; //no nead to change the name as it will do same as the last function... we only need to change the file's name
	adminfile.open("Members.txt");
	while(!adminfile.eof()){
		string a;
		adminfile >> a;
		int comma = 0; int indicator = 0;
		int ID; string firstname,lastname,username,password;
		for(int i = 0; i <= a.size(); i++){
			if(a[i] == ','|| i == a.size() ){
				if(indicator == 0){
					string idd = "";
					for(int z = comma; z < i; z++){
						idd += a[z]; 
					}
					comma = i + 1;
					ID = stoi(idd);
					indicator++;
				}
				else if(indicator == 1){
					firstname = "";
					for(int z = comma; z < i; z++){
						firstname += a[z]; 
					}
					comma = i + 1;
					indicator++;
				}else if(indicator == 2){
					lastname = "";
					for(int z = comma; z < i; z++){
						lastname += a[z];
					}
					comma = i + 1;
					indicator++;
				
				}else if(indicator == 3){
					username = "";
					for(int z = comma; z < i; z++){
						username += a[z];
					}
					comma = i + 1;
					indicator++;
				
				}else if(indicator == 4){
					password = "";
					for(int z = comma; z < i; z++){
						password += a[z] ;
					}
					comma = i + 1;
					indicator++;
				}

			}
		}
		member u;
		u.setEverything(ID, firstname, lastname, username, password);
		memberlist.addFront(u);
		//cout << a << endl;
	}

}
void loadfromFitnessClass(){
	ifstream fitnessfile;
	fitnessfile.open("FitnessClasses.txt");
	while(!fitnessfile.eof()){
		fitnessClass temp;
		string a;
		fitnessfile >> a;
		int comma = 0; int indicator = 0;
		int ID, maximumCapacity, roomnumber; string name,date,time;
		for(int i = 0; i < a.size(); i++){
			if(a[i] == ','){
				if(indicator == 0){
					string idd = "";
					for(int z = comma; z < i; z++){
						idd += a[z]; 
					}
					comma = i + 1;
					ID = stoi(idd);
					indicator++;
				}else if(indicator == 1){
					name = "";
					for(int z = comma; z < i; z++){
						name += a[z]; 
					}
					comma = i + 1;
					indicator++;
				}else if(indicator == 2){
					date = "";
					for(int z = comma; z < i; z++){
						date += a[z]; 
					}
					comma = i + 1;
					indicator++;
				}else if(indicator == 3){
					time = "";
					for(int z = comma; z < i; z++){
						time += a[z]; 
					}
					comma = i + 1;
					indicator++;
				}else if(indicator == 4){
					string idd = "";
					for(int z = comma; z < i; z++){
						idd += a[z]; 
					}
					comma = i + 1;
					maximumCapacity = stoi(idd);
					indicator++;
				}else if(indicator == 5){
					string idd = "";
					for(int z = comma; z < i; z++){
						idd += a[z]; 
					}
					comma = i + 1;
					roomnumber = stoi(idd);
					indicator++;
				}
			}
			if(a[i] == '['){
				DoublyLinkedList<member>* members = new DoublyLinkedList<member> ;
				int comma = i+1;
				while(a[i] != ']'){
					i++;
					 
					
						if(a[i] == ',' || a[i] == ']' ){
							int tempp;string idd = "";
							for(int zz = comma; zz < i; zz++){
								idd += a[zz]; 
							}
							//temp = stoi(idd);
							tempp = stoi(idd);
							//cout << ">>>" << tempp << endl;
							comma = i + 1;
							members->addFront(findmember(tempp));
						}
				}
				//members.displaymember();
				temp.membersInClass = members;
			}
		}
		
		temp.geteverything(ID,maximumCapacity, roomnumber, name,time, date);
		//temp.display();
		fitnesslist.addFront(temp);
		//cout << a << endl;
	}

}
//done loading data=================================

int main(){
	cout << "working...." << endl;
	srand ( time(NULL) );
	admin a;
	a.setAdminID(1);
	a.setFirstName("admin");
	a.setLastName("admin");
	a.setUsername("admin1");
	a.setPassword("admin1");
	adminlist.addFront(a);
	loadfromAdmin();
	loadfromMembers();
	loadfromFitnessClass();


	cout << "welcome to the fitness management system!" << endl;
	askforusernamenpassword();
	

	
	saveInfile();


	return 0;
}







//doubly linked list functions================================================================================================================================
template  <typename E>
DoublyLinkedList<E>::DoublyLinkedList ()
{
	head = new  Node<E>;
	tail = new  Node<E>;
	head->next=tail;
	tail->prev=head;
	size = 0;
}
template  <typename E>
DoublyLinkedList<E>::~DoublyLinkedList () // destructor to clean up all nodes
{
	while (!empty()) removeFront();
	delete head;
	delete tail;
}
template  <typename E>
bool DoublyLinkedList<E>::empty()  // is list empty?
{
	return (head->next == tail);
}
template  <typename E>
E& DoublyLinkedList<E>::front()  // get front element
{
	return head->next->elem;
}
template  <typename E>
E& DoublyLinkedList<E>::back()  // get front element
{
	return tail->prev->elem;
}
template  <typename E>
void DoublyLinkedList<E>::addBefore(Node<E> *ptr,  E eelem)
{
	Node<E>* u = new Node<E>;
	u->elem = eelem;
	u->next = ptr;
	u->prev = ptr->prev;
	ptr->prev->next = u;
	ptr->prev = u;
	size++;
}
template  <typename E>
void DoublyLinkedList<E>::addFront( E eelem) // add to front of list
{

	Node<E>* u = new Node<E>;
	u->elem = eelem;
	u->next = head->next;
	u->prev = head;
	head->next->prev = u;
	head->next = u;
	size++;
}
template  <typename E>
void DoublyLinkedList<E>::addBack( E elem) // add to Back of the list
{
	Node<E>* u = new Node<E>;
	u->elem = elem;
	u->prev = tail->prev;
	u->next = tail;
	tail->prev->next = u;
	tail->prev = u;
	size++;
}
template  <typename E>
void DoublyLinkedList<E>::removeFront() // remove front item from list
{
	Node<E>* u = new Node<E>;
	u = head->next;
	head->next = head->next->next;
	head->next->prev= head;
	delete u;
	size--;
}
template  <typename E>
void DoublyLinkedList<E>::removeBack() // remove last item from list
{
	Node<E>* u = new Node<E>;
	u = tail->prev;
	tail->prev = tail->prev->prev;
	tail->prev->next= tail;
	delete u;
	size--;
}
template  <class admin>
void DoublyLinkedList<admin>::displayadmin(){
	Node<admin> * a = head;              //initialzing the node into the head 
 	 //cout << "<<<<<<<<<<<admins>>>>>>>>>>>" << endl;     // making the series of nodes
	do{
	a = a->next;  
    if(a == NULL || a->next == NULL){
      break;                  //if a is null then the seris had ended
    }
     a->elem.display() ;   // printing out the element of the node              // moving to the next index
  }while( a->next != NULL );          
  //cout << "<<<<<<<done>>>>>>>" << endl;

}
template  <class member>
void DoublyLinkedList<member>::displaymember(){
	Node<member> * a = head;              //initialzing the node into the head 
 	 //cout << "<<<<<<<<<<<members>>>>>>>>>>>" << endl;     // making the series of nodes
	do{
	a = a->next;  
    if(a == NULL || a->next == NULL){
      break;                  //if a is null then the seris had ended
    }
     a->elem.display() ;   // printing out the element of the node              // moving to the next index
  }while( a->next != NULL );          
  //cout << "<<<<<<<done>>>>>>>" << endl;
}
template  <class fitnessClass>
void DoublyLinkedList<fitnessClass>::displayfitness(){
	Node<fitnessClass> * a = head;              //initialzing the node into the head 
 	 //cout << "<<<<<<<<<<<FitnessClasses>>>>>>>>>>>" << endl;     // making the series of nodes
	do{
	a = a->next;  
    if(a == NULL || a->next == NULL){
      break;                  //if a is null then the seris had ended
    }
     a->elem.display() ; 
	 //a->elem.allmembersInClass();
  }while( a->next != NULL );          
  //cout << "<<<<<<<done>>>>>>>" << endl;
}
template  <typename E>
E& DoublyLinkedList<E>::findTheNumber(int f){
			int ff = 0;
			Node<E> * a = head;              
			do{
				a = a->next;  
				if(a == NULL || a->next == NULL){
					break;                  //if a is null then the seris had ended
				}
				if(f == ff)
					break;
				ff++;
			}while( a->next != NULL );          
			return a->elem;
}
//================================================================================================================================



//functions to generate ID
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


/* 
example to remove stuff

memberlist.displaymember();
	Node<member>* jj = memberlist.findTherefrence(2);
	memberlist.removebefore(jj);
	cout << "--------" << endl;
	memberlist.displaymember();
	


 */