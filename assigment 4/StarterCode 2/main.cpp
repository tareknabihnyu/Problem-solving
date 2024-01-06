
//=================================================================================
// Name         : DS Assignment#4 
// Author       : 
// Version      : 1.0
// Date Created : 00-00-2022
// Date Modified: 
// Description  : Starter Code for Contact Travel Management System using HASH TABLE in C++
//=================================================================================
#include<iostream>
#include<cstdlib>
#include<sstream>

#include "flightticket.h"
#include "flighthashtable.h"

int addflight(FlightHASHTABLE& myFlightHASHTABLE){
	string companyName;
	int flightNumber;
	string country_of_origin;
	string country_of_destination;
	string stopOver;
	string price;
	string time_of_departure;
	string time_of_arrival;
	string date;

	cout << "please insert the company's name: "; cin >> companyName;
	cout << "please insert the flight number: "; cin >> flightNumber;
	cout << "please insert the country of origin: ";cin >> country_of_origin;
	cout << "please insert the country of destination: ";cin >> country_of_destination;
	cout << "please insert the stop over ocountry: ";cin >> stopOver;
	cout << "please insert the price: ";cin >>price;
	cout << "please insert the time_of departure: ";cin >> time_of_departure;
	cout << "please insert the time_of_arrival: ";cin >> time_of_arrival;
	cout << "please insert the date: ";cin >> date;

	Flight_Ticket* data = new Flight_Ticket(companyName,flightNumber,country_of_origin,country_of_destination,stopOver,price,time_of_departure,time_of_arrival,date);
	cin.ignore();
	return myFlightHASHTABLE.add(data);
}



//==========================================================
void listCommands()
{
	cout<<"\n----------------------------------"<<endl;
	cout<<"import <path>      	:Import flight-tickets from a CSV file"<<endl
		<<"export <path>      	:Export flight-tickets to a CSV file"<<endl
		<<"count_collisions   	:Print Number of Collisions"<<endl
		<<"add                	:Add a new flight-ticket"<<endl
		<<"delete <key>       	:Delete a flight-ticket"<<endl
		<<"find <key>         	:Find a flight-ticket's details"<<endl
		<<"allinday <date>    	:Display all flight-tickets in a day"<<endl
		<<"printASC <key>     	:Print flight-tickets in ascending order"<<endl
		<<"exit               	:Exit the program"<<endl;
}
//==========================================================

// to be completed with all the necessary method definitions

//==========================================================
int main(void)
{
	FlightHASHTABLE myFlightHASHTABLE;
	string user_input;
	string command;
	string parameter;
	string extra;
	while(true)
	{
		listCommands();
		cout<<">";
		getline(cin,user_input);

			// parse userinput into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr,command,' ');
		getline(sstr,parameter,',');
		getline(sstr,extra);
		if(user_input == "add"){ if(addflight(myFlightHASHTABLE) == 1) cout << "added successfully!" << endl; else {cout << "error happened!" << endl;}}
		else if(command == "printASC"){myFlightHASHTABLE.printASC(parameter,stoi(extra));}
		else if(command == "find"){myFlightHASHTABLE.find(parameter,stoi(extra));}
		else if(command == "allinday"){myFlightHASHTABLE.allinday(parameter);}
		else if(command == "delete"){myFlightHASHTABLE.removeRecord(parameter,stoi(extra));}
		else if(command == "import"){cout << myFlightHASHTABLE.importCSV(parameter) << endl;}
		else if(command == "display"){myFlightHASHTABLE.display();}
		else if(command == "export"){cout << myFlightHASHTABLE.exportCSV(parameter) << endl;}
		else if(command == "exit"){break;}
		else if(command == "count_collisions"){cout << "The number of collisions is " << myFlightHASHTABLE.count_collisions() << endl;}
		else{cout << "Invalid input, please try again!" << endl;}
		//to be completed 

	}
	// printASC tarek,123
	return 0;
}

/*
import flight-ticket1k.csv
allinday 28Apr
printASC Viva Air Colombia,102
find Viva Air Colombia,102
delete Viva Air Colombia,102


*/
