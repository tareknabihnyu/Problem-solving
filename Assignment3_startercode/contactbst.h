#ifndef ContactBST_H
#define ContactBST_H
#include <string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include "contact.h"
#include "myvector.h"  

using namespace std;

class Node
{
	private:
		string key;
		MyVector<Contact>* contactVector;
		Node* left;
		Node* right;
	public:
		Node(string key, MyVector<Contact>* contactVector);
		~Node();
		string getKey() { return this->key;}
		MyVector<Contact>* getData() { return this->contactVector;}
		void addContact(Contact data){contactVector->push_back(data);}
		void displayvector();
		friend class ContactBST;
};


void Node::displayvector(){
	cout << contactVector->size() << " records found:" << endl << endl;;
	for(int i = 0; i < contactVector->size(); i++){
		cout << i + 1 << ".";
		contactVector->at(i).displayContact();
	}
	cout << endl;
	cout << "------------" << endl;
}

Node::Node(string key, MyVector<Contact>* contactVector){
	this->key = key;
	this->contactVector = contactVector;
	this->left = nullptr;
	this->right = nullptr;
}

Node::~Node()
{
	cout<<"deleted.."<<this->key<<endl;
}

//=============================================================================
class ContactBST
{
	private:
		Node* root;
	public:
		ContactBST();									//constructor
		~ContactBST();									//destructor
		Node* getRoot();						//returns the root of the Tree
		Node* add(Node* ptr,string key, Contact* data);		//add key into tree/subtree with root ptr
		Node* update(Node* ptr, string key); //Edit the node with key
		Node* del(Node* ptr,string key);		//Delete a node with key from the tree/subtree with root
		Node* search(Node* ptr,string key);	//Find and returns the node with key
		Node* findMin(Node *ptr);
		void display1node(Node *ptr);
		bool markFav(Node* ptr, string key);  //Mark a contact as favorite 
		bool unmarkFav(Node* ptr, string key);  //Unmark a contact as favorite 
		void printASC(Node* ptr);			//Print the data at nodes in an ascending order
		void printDES(Node* ptr);			//Print the data at nodes in a descending order
		void printFav(Node* ptr);           //Print the favorite data at nodes in an ascending order
		void printToFile(ofstream & file, Node* ptr, int&x);
		int importCSV(Node* ptr, string path); //Load all the contacts from the CSV file to the BST
		int exportCSV(Node* ptr, string path); //Export all the contacts from the BST to a CSV file in an ascending order

	public:	//helper methods
		void insert_helper(string key, Contact* data);				//Helper method for insert method
		void remove_helper(string key);								//Helper method for remove method
	private:
		void printTreeHelper(string* A, bool* B, Node* ptr, int n); //Helper method for PrintTree()
};


ContactBST::ContactBST(){
	root = nullptr;
}

ContactBST::~ContactBST(){
	// to be made
}

int ContactBST::exportCSV(Node* ptr, string path){
	ofstream file;
	file.open(path); //to be changed
	int x = 0;
	printToFile(file, ptr, x);
	file.close();
	return (x == 0)? -1 : x;

}

Node* ContactBST::update(Node* ptr, string key){
	if(ptr == nullptr)
		return 0;
	else if(ptr->key == key){
		if(ptr->contactVector->size() == 1){
			ptr->contactVector->at(0).edit();
		}else{
			ptr->displayvector();
			cout << "which one would you like to update?" << endl;
			int ch; cin >> ch;
			ptr->contactVector->at(ch-1).edit();
		}
		return ptr;
	}
	else
		return (key < ptr->key) ? update(ptr->left,key):update(ptr->right,key);
}

bool ContactBST::markFav(Node* ptr, string key){
	if(ptr == nullptr)
		return 0;
	else if(ptr->key == key){
		if(ptr->contactVector->size() == 1){
			ptr->contactVector->at(0).markFav();
		}else{
			ptr->displayvector();
			cout << "which one would you like to markFav?" << endl;
			int ch; cin >> ch;
			ptr->contactVector->at(ch-1).markFav();
		}
		return 1;
	}
	else
		return (key < ptr->key) ? markFav(ptr->left,key):markFav(ptr->right,key);
}

bool ContactBST::unmarkFav(Node* ptr, string key){
	if(ptr == nullptr)
		return 0;
	else if(ptr->key == key){
		if(ptr->contactVector->size() == 1){
			ptr->contactVector->at(0).unmarkFav();
		}else{
			ptr->displayvector();
			cout << "which one would you like to unmarkFav?" << endl;
			int ch; cin >> ch;
			ptr->contactVector->at(ch-1).unmarkFav();
		}
		return 1;
	}
	else
		return (key < ptr->key) ? unmarkFav(ptr->left,key):unmarkFav(ptr->right,key);
	cin.ignore();
}

int ContactBST::importCSV(Node* ptr, string path){
	ifstream file;
	file.open(path);
	string line, word;
	int counter(0);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			string fname; string lname; string email; string phone; string city; string country; bool isFav;
			stringstream str(line);
			getline(str, word, ',');
			fname = word;
			getline(str, word, ',');
			lname = word;
			// lname.erase(0,1);
			getline(str, word, ','); //continue to do the same thing till u finish the city and the 
			email = word;
			// email.erase(0,1);
			getline(str, word, ',');
			phone = word;
			// phone.erase(0,1);
			getline(str, word, ',');
			city = word;
			// city.erase(0,1);
			getline(str, word, ',');
			country = word;
			// country.erase(0,1);
			getline(str, word, ',');
			// cout << ">"<< lname << "<"<< endl;
			int x = word[0] - '0';
			isFav = x;
			// cout << fname << ", " << lname << ", " << email << ", " << phone << ", " << city << ", " << country <<", " << isFav << endl; 

			Contact* data = new Contact(fname,lname,email,phone,city,country,isFav);
			MyVector<Contact>* a = new MyVector<Contact>;
			a->push_back(*data);
			string key = fname + " " + lname;
			insert_helper(key,data);
			counter++;

		}
	}
	file.close();
	return counter;
}

void ContactBST::insert_helper(string key, Contact* data)
{	
	// cout << key << endl;
	root = add(root,key, data);
}

void ContactBST::remove_helper(string key){
	if(search(root,key) == nullptr) cout << "key not found" << endl;
	else{cout << "deleted successfully!" << endl;}
	root = del(root, key);
}

void ContactBST::display1node(Node *ptr){
	ptr->displayvector();
}

Node* ContactBST::search(Node *ptr,string key){
	if(ptr == nullptr)
		return nullptr;
	else if(ptr->key == key)
		return ptr;
	else
		return (key < ptr->key) ? search(ptr->left,key):search(ptr->right,key);
}


Node* ContactBST::getRoot(){
	return this->root;
}

void ContactBST::printASC(Node* ptr){
	if(ptr != nullptr){
		printASC(ptr->left);

		if(ptr->contactVector->size() == 0){
			ptr->contactVector->at(0).displayContact2();
		}else{
			for(int i = 0; i < ptr->contactVector->size();i++ ){
				ptr->contactVector->at(i).displayContact2();
			}
		}

		printASC(ptr->right);
	}
}

void ContactBST::printToFile(ofstream & file, Node* ptr, int&x){
	if(ptr != nullptr){
		printToFile(file, ptr->right,x);
		if(ptr->contactVector->size() == 0){
			ptr->contactVector->at(0).displayTofile(file);
			x++;
		}else{
			for(int i = 0; i < ptr->contactVector->size();i++ ){
				ptr->contactVector->at(i).displayTofile(file);
				x++;
			}
		}
		printToFile(file, ptr->left,x);
	}
}


void ContactBST::printDES(Node* ptr){
	if(ptr != nullptr){
		printDES(ptr->right);
				if(ptr->contactVector->size() == 0){
			ptr->contactVector->at(0).displayContact2();
		}else{
			for(int i = 0; i < ptr->contactVector->size();i++ ){
				ptr->contactVector->at(i).displayContact2();
			}
		}
		printDES(ptr->left);
	}
}

void ContactBST::printFav(Node* ptr){
	if(ptr != nullptr){
		printFav(ptr->right);
		if(ptr->contactVector->size() == 0){
			if(ptr->contactVector->at(0).isFavourite()) ptr->contactVector->at(0).displayContact2();
		}else{
			for(int i = 0; i < ptr->contactVector->size();i++ ){
				if(ptr->contactVector->at(i).isFavourite()) ptr->contactVector->at(i).displayContact2();
			}
		}
		printFav(ptr->left);
	}
}


Node* ContactBST::findMin(Node *ptr){
	return (ptr->left == NULL)? ptr: findMin(ptr->left)  ;
}

Node* ContactBST::add(Node* ptr, string key, Contact* data)
{
	if(ptr ==  nullptr){
		MyVector<Contact>* a = new MyVector<Contact>;
		a->push_back(*data);
		return ptr = new Node(key, a);

	}

	if(key == ptr->getKey()){
		// MyVector<Contact>* a = ptr->getData();
		// a->push_back(*data);
		// return ptr = new Node(key, a);
		ptr->addContact(*data);
		return ptr ;
	}


	else if(key < ptr->getKey())
	{
		ptr->left = add(ptr->left,key, data);
	}
	else if(key > ptr->getKey())
	{
		ptr->right = add(ptr->right,key, data);
	}

	return ptr;
	//return (key > ptr->key)? insert(ptr->right,key) : insert(ptr->left,key);
}

Node* ContactBST::del(Node *ptr,string key){ //when called it is supposed to be ptr(or whatever) = del(...);
	
	//search for it and if it was only one then excute this, otherwise remove only one time.


	if (ptr == nullptr){
        return ptr;
	}
    if (key < ptr->key){
        ptr->left = del(ptr->left, key);
	}
    else if (key > ptr->key){
        ptr->right = del(ptr->right, key);
	}
 
    else {
		if(ptr->contactVector->size() == 1){
			if (ptr->left==nullptr && ptr->right==nullptr)
				return nullptr;
			
			else if (ptr->right == nullptr) {
				Node* temp = ptr->left;
				free(ptr);
				return temp;
			}
		
			else if (ptr->left == nullptr) {
				Node* temp = ptr->right;
				free(ptr);
				return temp;
			}

			Node* temp = findMin(ptr->right);
			ptr->key = temp->key;
			ptr->right = del(ptr->right, temp->key);
		}else{
			ptr->displayvector();
			cout << "which one would you like to remove?" << endl;
			int ch; cin >> ch;
			ptr->contactVector->erase(ch-1);
		}
    }
    return ptr;

}
#endif