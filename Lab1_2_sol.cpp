#include <iostream>

using namespace std;

int main() {
  int currentbill, cfils(0);
  int beforebill;
  //declaring the two initial values and the amount of money
  cout << "enter the current bill" << endl;
  cin >> currentbill;
  cout << "enter the previous bill" << endl;
  cin >> beforebill;
  //inputting the bills
  currentbill = currentbill - beforebill;
  //pre calculation
  if(currentbill >= 500){
    cfils += (10+20+150); //because they will already exist as it is more than 500
    cfils += (currentbill - 500);
  } else if(currentbill >= 200){
    cfils += (10+20); //because they will already exist as it is more than 500
    cfils += (currentbill - 200)*0.5;
  }else if(currentbill >= 100){
    cfils += (10);
    cfils += (currentbill - 100)*0.2;
  }else if(currentbill >= 0){
    cfils += (currentbill * 0.1);
  }else{
    cout << "please enter a positive number" << endl;
  }
  
  //outputting the total cost
  cout << ">>" << cfils;

}
