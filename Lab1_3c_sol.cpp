#include <iostream>

using namespace std;

int main() {
  int x; cout << "enter a number: "; cin>>x;
  int count(0);
  for(int i = x; i > 1; i-- ){
    if((i % 2 != 0)&&(i % 3 != 0)){ //checking if it is divisable by two and 3
     count++; 
    }
    if(i == 2 || i == 3){ //because 2 and 3 will never be divisable by each other
      count ++;
    }
  }

  //outputting the numbers
  cout << "there are " << count << " prime numbers under " << x << endl;

}