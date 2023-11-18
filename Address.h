#pragma once
#include <iostream>
#include <string>

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	bool equals(const Address& address);
	void print_address();
	~Address();
	//Setter
	void set_House(std::string house);
	void set_Street(std::string street);
	void set_City(std::string city);
	void set_Country(std::string country);
	// getters
	std::string get_House()const;
	std::string get_Street()const;
	std::string get_City()const;
	std::string get_Country()const;

	Address* copy_address();

	Address(std::string house, std::string street, std::string city, std::string country);
	Address();
	//friend istream& operator >>(istream& ccin, Address obj);
}; 
