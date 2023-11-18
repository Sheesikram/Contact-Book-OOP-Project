#include "Contact.h"

/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/
Contact::Contact()
{
	address = new Address;
	this->address = address;
	this->first_name = "Shees";
	this->last_name = "Ikram";
	this->mobile_number = "03413466095";
	this->email_address = "sheesikram@";
	address->set_City("Faisalabad");
	address->set_Country("Pakistan");
	address->set_House("House");
	address->set_Street("St#06");
}

/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size).
*   Check in phone number setter, Phone number must be 11 digits
*/
void Contact::set_first_name(std::string first_name)
{
	if (first_name.empty())
	{
		std::cout << "Empty name" << std::endl;
		return;
	}
	this->first_name = first_name;
}
void Contact::set_last_name(std::string last_name)
{
	if (last_name.empty())
	{
		std::cout << "Empty last_name" << std::endl;
		return;
	}
	this->last_name = last_name;
}
void Contact::set_mobile_number(std::string mobile_number)
{
	if (mobile_number.empty())
	{
		std::cout << "Empty number" << std::endl;
		return;
	}
	if (mobile_number.length() != 11)
	{
		return;
	}

	this->mobile_number = mobile_number;
}
void Contact::set_email_address(std::string email_address)
{
	if (email_address.empty())
	{
		std::cout << "Empty Email" << std::endl;
		return;
	}
	this->email_address = email_address;
}
//getters
std::string Contact::get_first_name()const
{
	return first_name;
}
std::string Contact::get_last_name()const
{
	return last_name;
}
std::string Contact::get_mobile_number()const
{
	return mobile_number;
}
std::string Contact::get_email_address()const
{
	return email_address;
}



/*
*	Implement the equals function(as declared in header file) that takes a
*   Contact object and checks if it is equal to current object refered by (this pointer).
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/
bool Contact::equals(Contact contact)
{
	if (contact.get_first_name() != this->get_first_name())
	{
		return false;
	}
	if (contact.get_last_name() != this->get_last_name())
	{
		return false;
	}
	if (contact.get_email_address() != this->get_email_address())
	{
		return false;
	}
	if (contact.get_mobile_number() != this->get_mobile_number())
	{
		return false;
	}
	if (!(this->address->equals(*(address))))
	{
		return false;

	}
	return true;
}

Contact* Contact::copy_contact()
{
	Contact* ptr = new Contact;
	ptr->first_name = this->first_name;
	ptr->last_name = this->last_name;
	ptr->email_address = this->email_address;
	ptr->mobile_number = this->mobile_number;
	//ptr->address =&this -> address->copy_address();
	ptr->address = this->address->copy_address();
	/*
	Return a new object(deep copy of &quot;this&quot;[due to Address pointer, which

	should also be copied])
	*/
	return ptr;
	/*
		Return a new object(deep copy of "this"[due to Address pointer, which should also be copied])
	*/
}

bool Contact::Checker(Contact& s1, Contact& s2)
{
	if (s1.get_first_name() == s2.get_first_name() && s1.get_last_name() == s2.get_last_name() && s1.get_email_address() == s2.get_email_address()
		&& s1.get_mobile_number() == s2.get_mobile_number())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Contact::Contact(const Contact& obj)
{
	address = new Address;
	this->email_address = obj.email_address;
	this->first_name = obj.first_name;
	this->last_name = obj.last_name;
	this->mobile_number = obj.mobile_number;
	*this->address = *obj.address;
	
}



Address* Contact::get_Address()
{
	return address;
}


Contact& Contact::operator =(Contact obj)
{
	this->first_name = obj.first_name;
	this->last_name = obj.last_name;
	this->mobile_number = obj.mobile_number;
	this->email_address = obj.email_address;
	this->address = new Address;
	*this->address = *obj.address;
	return *this;
}