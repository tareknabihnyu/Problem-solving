#include<iostream>
#include<cstdlib>
#include<sstream>
#include <string>

#include "contactbst.h"

using namespace std;




Node* ContactBST::getRoot(){
	return this->root;
}

void ContactBST::printInorder(Node* ptr){
	if(ptr != nullptr){
		printInorder(ptr->left);
		cout << ptr->key << endl;
		printInorder(ptr->right);
	}
}

void ContactBST::insert_helper(string key, Contact* data)
{	
	root = add(root,key, data);
}

void ContactBST::remove_helper(string key){
	root = del(root, key);
}

Node* ContactBST::findMin(Node *ptr){
	return (ptr->left == NULL)? ptr: findMin(ptr->left)  ;
}

Node* ContactBST::add(Node* ptr, string key, Contact* data)
{
	if(ptr ==  nullptr){
		MyVector<Contact>* a;
		a->push_back(*data);
		return ptr = new Node(key, a);
	}

	if(key == ptr->getKey()){
		MyVector<Contact>* a = ptr->getData();
		a->push_back(*data);
		return ptr = new Node(key, a);
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
	
	if (ptr == nullptr)
        return ptr;
 
    if (key < ptr->key)
        ptr->left = del(ptr->left, key);
 
    else if (key > ptr->key)
        ptr->right = del(ptr->right, key);
 
    else {
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
    }
    return ptr;

}
