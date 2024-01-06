#include <iostream>

using namespace std;

int main() {
  int max(0),freq(1); //initializing the maximum and the frequency
  for(int i = 1; i <= 10; i++){
    cout << "enter the " << i << "th number:"; int x; cin >>x; //taking all the 10 numbers inside of the loop
    if(x > max){
      max = x;
      freq = 1; //restarts the frequency everytime
    }else if(x == max){
      freq++; //increases the frequency
    }
  }
  cout << "the largest number is " << max << " it's frequency is: " << freq << endl;
}
