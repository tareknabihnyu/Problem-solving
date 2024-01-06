#ifndef FlightHASHTABLE_H
#define FlightHASHTABLE_H

#include<iostream>
#include<string>
#include<iterator>
#include<iomanip>
#include<fstream>
#include "flightticket.h"
#include "MyList.h"
// include additional header files if needed

using namespace std;

class HashNode
{
	private:
		string key; // key = companyName+flightNumber
		Flight_Ticket value;
	public:
		HashNode(string key, Flight_Ticket value)
		{
			this->key = key;
			this->value = value;
		}
		HashNode(){}
		string getkey(){return key;}
		Flight_Ticket getvalue(){return value;}
		friend class FlightHASHTABLE;
};

//=============================================================================
class FlightHASHTABLE
{
	private:
		MyList<HashNode> *buckets;				//List of Buckets, Please create your own List Class called MyList
		int size;					    //Current Size of HashTable
		int capacity;				    // Total Capacity of HashTable
		int probes;
		// add more attributes needed
	public:
		FlightHASHTABLE();						//constructor
		~FlightHASHTABLE();						//destructor
		long hashCode(string str); 						//implement and test different hash functions 
		int importCSV(string path); 			//Load all the flight-tickets from the CSV file to the HashTable
		int exportCSV(string path); 			//Export all the flight-tickets from the HashTable to a CSV file in an ascending order		
		int count_collisions(){return probes;}				//return the number of collisions on the HashTable
		int add(Flight_Ticket* data);			//add new flight to the HashTable
		void removeRecord (string companyName, int flightNumber);	//Delete a record with key from the hashtable
		void find(string companyName, int flightNumber);		//Find and Display records with same key entered 
		void allinday(string date);  					//Find and Display records with same day entered
		void printASC(string companyName, int flightNumber);  		//display the collisions for the entered key in an ascending order 
		void printToFile(ofstream& file, int & x);
		void display();
		//Add more methods and contructors, destructors if needed	
};
FlightHASHTABLE::FlightHASHTABLE(){ //constructing everything
	capacity = 24851;
	size = 0;
	probes = 0;
	buckets = new MyList<HashNode>[capacity];
}
FlightHASHTABLE::~FlightHASHTABLE(){ //deleteing bucks
	delete[] buckets;
}

void neekha(string k){
	string ii = "";
	for(int i = 0; i < k.size() ; i++){
		ii += k[i];
	}
	// cin.ignore();
	cout << ">" << ii << "<" ;
	cout << endl;
}



int FlightHASHTABLE::importCSV(string path){
	 //opening file and getting all things from each single line
	ifstream file;
	file.open(path);
	string line, word;
	int counter(0);
	if(file.is_open())
	{	
		getline(file,line);
		while(getline(file, line))
		{
			string companyName;
			int flightNumber;
			string country_of_origin;
			string country_of_destination;
			string stopOver;
			string price;
			string time_of_departure;
			string time_of_arrival;
			string date;
			stringstream str(line);
			getline(str, word, ',');
			companyName = word; //doing this in each single line
			
			getline(str, word, ',');
			flightNumber = stoi(word);

			getline(str, word, ','); //continue to do the same thing till u finish the city and the 
			country_of_origin = word;

			getline(str, word, ',');
			country_of_destination = word;

			getline(str, word, ',');
			stopOver = word;

			getline(str, word, ',');
			price = word;

			getline(str, word, ',');
			time_of_departure = word;

			getline(str, word, ',');
			time_of_arrival = word;
			// cout << time_of_arrival << " | ";
			getline(str, word, ',');
			// cin.ignore();
			date = word;

			date.erase(date.size()-1,date.size()-0);

			// cout << ">" << date << "<" << endl;
			// cout << "zeby" << endl;
			//mking a new flight ticket object
			
			Flight_Ticket* data = new Flight_Ticket(companyName,flightNumber,country_of_origin,country_of_destination,stopOver,price,time_of_departure,time_of_arrival,date);
			// data->display();
			add(data);
			// data->display();
			counter++;

		}
	}
	file.close();
	return counter;
}


int FlightHASHTABLE::exportCSV(string path){
	ofstream file;
	file.open(path); //to be changed
	int x = 0;
	printToFile(file, x); //you pass the file name and get the number of thing outputted by the program
	return (x == 0)? -1 : x;
}


void FlightHASHTABLE::printToFile(ofstream& file, int & x){
	file << "companyName" << "," << "flightNumber" << "," << "countryoforigin" << "," << "countryofdestination" << "," << "stopover" << "," << "price" << "," << "timeofdeparture" << ","  << "timeofarrival" << "," << "date"<<endl;
	for(int i = 0; i < capacity; i++ ){
		if(buckets[i].givesize() == 0) continue; 
		int sizee = buckets[i].givesize();	//give out the bucket size
		int z(0);
		while(z < sizee){
			buckets[i].front().getvalue().displaytofile(file); //display to file individually
			buckets[i].addBack(buckets[i].front());
			buckets[i].removeFront();
			x++; z++; //increment x as it displays to file more flight tickets data
		}

	}
}

void FlightHASHTABLE::display(){ //same as print to file but print by cout 
	for(int i = 0; i < capacity; i++ ){
		if(buckets[i].givesize() == 0) continue;
		int sizee = buckets[i].givesize();
		int z(0);
		while(z < sizee){
			buckets[i].front().getvalue().display();
			buckets[i].addBack(buckets[i].front());
			buckets[i].removeFront(); 
			z++;
		}

	}
}


void FlightHASHTABLE::allinday(string date){
	int choice(0);
	for(int i = 0; i < capacity; i++ ){
		if(buckets[i].givesize() == 0) continue;
		int sizee = buckets[i].givesize();
		int z(0);
		while(z < sizee){
			string realdate = buckets[i].front().getvalue().getdate(); 
			// cout << ">" <<realdate << "<" << ">" << date << "<"   << endl; //<< date 
			if(buckets[i].front().getvalue().getdate() == date){   //similar to display but it checks if the day is the same or not
				choice++; cout << choice << ". "; buckets[i].front().getvalue().display();  
				} 
			buckets[i].addBack(buckets[i].front());
			buckets[i].removeFront(); 
			z++;
		}

	}
}



long FlightHASHTABLE::hashCode(string str){ //function used to gene3rate hashcode
	int count(0), num(1);
	for(int i = 0; i < str.size(); i++){
		count+= 333 * ((unsigned int)str[i]);
		count -= 'a';
	}
	count%= capacity;
	return count;
}


int FlightHASHTABLE::add(Flight_Ticket* data){ //basically making new node and getting it's hashcode then just adding it.
	HashNode* temp = new HashNode(data->getkey(),*data);
	int hashindex = hashCode(data->getkey());

	// cout << hashindex << endl;
	//int index=1;
	buckets[hashindex].addBack(*temp);
	//buckets[hashindex].front().getvalue().display(); //fhgjklhgfhjklhgfhjklhgfhjkhgcvvbnmj
	if(buckets[hashindex].givesize() > 1) probes++;
	size++;
	return 1;
}

void bubbleSort(HashNode* array, int size) {	//typical bubble sort
  for (int step = 0; step < size; ++step) {
    for (int i = 0; i < (size-1) - step; ++i) {
      if (array[i].getvalue().getdestination() > array[i + 1].getvalue().getdestination() ) {
        HashNode temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void FlightHASHTABLE::printASC(string companyName, int flightNumber){
	string hhh = companyName + to_string(flightNumber);
	int hashindex = hashCode(hhh);			
	int size = buckets[hashindex].givesize();
	HashNode* arr = new HashNode[size];
	int sizee = 0;
	for(int i = 0; i < size; i++){
		// buckets[hashindex].front().getvalue().display();
		if(buckets[hashindex].front().getvalue().getflightnumber() == flightNumber){
			arr[sizee] = buckets[hashindex].front();
			sizee++;
		}	//you copy everything into an array
			buckets[hashindex].addBack(buckets[hashindex].front());
			buckets[hashindex].removeFront();	
	}
	size = sizee;
	bubbleSort(arr,size); //bubble sort that array
	for(int i = 0; i < size; i++){
		arr[i].getvalue().display();		//display it
	}
	// for(int i = 0; i < size; i++){
	// 	buckets[hashindex].addBack(arr[i]);		//add it back
	// }

}

void FlightHASHTABLE::find(string companyName, int flightNumber){ //you get the hashindex from the company name and the size
	int hashindex = hashCode(companyName+to_string(flightNumber));
	int size = buckets[hashindex].givesize();
	int z(0);
	while(z < size){ //you keep going around in a loop untill find the desired flight ticket
		if(buckets[hashindex].front().getvalue().getflightnumber() == flightNumber) buckets[hashindex].front().getvalue().display(); 
		buckets[hashindex].addBack(buckets[hashindex].front());
		buckets[hashindex].removeFront();
		z++;
	}
}

void FlightHASHTABLE::removeRecord(string companyName, int flightNumber){
	string hhh = companyName + to_string(flightNumber);
	int hashindex = hashCode(hhh);
	int size = buckets[hashindex].givesize(); 
	int z(0); int choice(1);
	while(z < size){
		if(buckets[hashindex].front().getvalue().getflightnumber() == flightNumber){ cout << choice << ". "; buckets[hashindex].front().getvalue().display(); choice++;} 
		buckets[hashindex].addBack(buckets[hashindex].front());
		buckets[hashindex].removeFront(); //display all things with the same in the buckets with the  same company name and flight number
		z++;
	}
	cin >> choice;
	int choicee(1); z = 0;
	//doikng the same thing as before but removing a specific one...
	while(z < size){
		//it will remove only one thing but the rest will be normal
		if(buckets[hashindex].front().getvalue().getflightnumber() == flightNumber){ 
			if(choicee == choice){
				buckets[hashindex].removeFront();
				choicee++; 
				cout << endl << "the flight ticket was removed successfully!" << endl;
				continue;
			}
			choicee++;
		} 
		buckets[hashindex].addBack(buckets[hashindex].front());
		buckets[hashindex].removeFront();
		z++;
	}
	cin.ignore();

}



#endif
