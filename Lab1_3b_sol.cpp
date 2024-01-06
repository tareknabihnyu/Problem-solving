#include <iostream>

using namespace std;

int main() {
  //getting a number from a user
  int x; cout << "enter a number: "; cin>>x;
  if((x % 2 == 0)||(x % 3 == 0)){ //checking if it is divisable by two or three
    cout << "not a prime number" << endl;
  }else{
    cout << "a prime number "<< endl;
  }


}