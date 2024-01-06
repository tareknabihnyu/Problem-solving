#ifndef FLIGHT_TICKET_H
#define FLIGHT_TICKET_H

#include<iostream>
#include<string>
#include <stdlib.h>
#include<iomanip>
#include<fstream>
using namespace std;


string getstring(int i){ return to_string(i);}


class Flight_Ticket
{
	private:
		string companyName;
		int flightNumber;
		string country_of_origin;
		string country_of_destination;
		string stopOver;
		string price;
		string time_of_departure;
		string time_of_arrival;
		string date;

	public:
		Flight_Ticket(string companyName, int flightNumber, string country_of_origin, string country_of_destination, string stopOver, string price, string time_of_departure, string time_of_arrival, string date);
		Flight_Ticket(){}
		void display();
		string getcompanyname(){return companyName;}
		int getflightnumber(){return flightNumber;}
		string getdate(){return date;}
		string getdestination(){return country_of_destination;}
		string getkey(){return (companyName  + getstring(flightNumber)  );}
		void displaytofile(ofstream& file);
		friend class fligthhashtable;
		// Please add additional methods, contructor if needed
};


Flight_Ticket::Flight_Ticket(string companyName, int flightNumber, string country_of_origin, string country_of_destination, string stopOver, string price, string time_of_departure, string time_of_arrival, string date){
	this->companyName = companyName;
	this->flightNumber= flightNumber;
	this->country_of_origin = country_of_origin;
	this->country_of_destination = country_of_destination;
	this->stopOver = stopOver;
	this->price = price;
	this->time_of_departure = time_of_departure;
	this->time_of_arrival = time_of_arrival;
	this->date = date;

}

void Flight_Ticket::display(){
	cout << companyName << ", " << flightNumber << ", " << country_of_origin<< ", " <<country_of_destination<< ", " << stopOver << ", " << price << ", " << time_of_departure << ", " << time_of_arrival<< ", " <<date << endl;
}

void Flight_Ticket::displaytofile(ofstream& file){
	file << companyName << "," << flightNumber << "," << country_of_origin<< "," <<country_of_destination<< "," << stopOver << "," << price << "," << time_of_departure << "," << time_of_arrival<< "," <<date << endl;
}

#endif
