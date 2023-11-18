#include "Address.h"
#include<iostream>

/*
*	Implement a constructor that initializes all the address parts
*
*/
Address::Address()
{
	this->house = "Sweet Home";
	this->street = "06";
	this->city = "Faisalabad";
	this->country = "Pakistan";
}


/*
*	Implement getter/setters for all the member variables of Address. Also declare them in the Address.h header file
*
*/
void Address::set_House(std::string house)
{
	this->house = house;
}
void Address::set_Street(std::string street)
{
	this->street = street;
}
void Address::set_City(std::string city)
{
	this->city = city;
}
void Address::set_Country(std::string country)
{
	this->country = country;
}



std::string Address::get_House()const
{
	return house;
}
std::string Address::get_Street()const
{
	return street;
}
std::string Address::get_City()const
{
	return city;
}
std::string Address::get_Country()const
{
	return country;
}



/*
*	Implement the equals function that takes an Address object and checks if it is equal to
*	current object refered by (this pointer)
*	Two addresses are equal if all the attributes of addresses are equal
*/
bool Address::equals(const Address& address)
{
	if (this->get_City() != address.get_City())
	{
		return false;
	}
	if (this->get_House() != address.get_House())
	{
		return false;
	}
	if (this->get_Country() != address.get_Country())
	{
		return false;
	}
	if (this->get_Street() != address.get_Street())
	{
		return false;
	}
	/*
	* Todo
	*/
	return false;
}

void Address::print_address()
{
	std::cout << get_House() << " " << get_Street() << " " << get_City() << " " <<
		get_Country() << std::endl;
	/*
	*	Print address on one line as
	*	House, Street, City, Country
	*/
}

Address* Address::copy_address()
{
	Address* ptr = new Address;
	ptr->house = this->house;
	ptr->street = this->street;
	ptr->city = this->city;
	ptr->country = this->country;
	/*
		return a copy of this
	*/
	return ptr;
	/*
		return a copy of this
	*/
}

Address::~Address()
{
	//delete ptr;
}

//istream& operator >>(istream& ccin, Address& obj)
//{
//	std::cout << "Enter the street:";
//	ccin >> obj.st
//} 