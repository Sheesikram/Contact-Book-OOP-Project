#include<iostream>
#include<string>
#include"address.h"
#include"Contact.h"
#include"ContactBook.h"
#include<fstream>
using namespace std;


int main()
{
	std::ifstream in;
	int size=10      ;
	Address a;


	
	Contact* cbk = new Contact[size];
	ContactsBook co;
	/*for (int i = 0; i < size; i++)
	{
		cbk[i].set_first_name("shees");
		cbk[i].set_last_name("ikram");
		cbk[i].set_email_address("sgfuk");
		cbk[i].set_mobile_number("2893758o7");

	}*/

	std::cout << "Enter 1 for Add Contact" << std::endl;
	std::cout << "Enter 2 for Marge Dublicates" << std::endl;
	std::cout << "Enter 3 for Store to file" << std::endl;
	std::cout << "Enter 4 for Load from file" << std::endl;
	std::cout << "Enter 5 for Print Contact sorted" << std::endl;
	std::cout << "Enter 6 for Print Contact" << std::endl;
	std::cout << "Enter 7 for Search contacts by number " << std::endl;
	std::cout << "Enter 8 for Search contacts by address" << std::endl;
	std::cout << "Enter 9 for Display count of contacts" << std::endl;
	int choicee;
	std::cin >> choicee;
	switch (choicee)
	{
	case 1:
		co.add_contact(*cbk);
		break;
	case 2:
		co.merge_duplicates();
		break;
	case 3:
		co.save_to_file("shees.txt");
		break;
	case 4:
		co.load_from_file("shees.txt");
		break;
	case 5:
		co.print_contacts_sorted("first_name");
		break;
	case 6:
		co.search_contact("shees", "lastname");
		break;
	case 7:
		co.search_contact("8370897");
		break;
	case 8:
		co.search_contact(a);
		break;
	case 9:
		cout << co.total_contacts();
		break;
	default:
		break;
	}


	//scinario 1 
	ContactsBook* ContactsBooks = new ContactsBook[5];
	Contact* Contacts = new Contact[5];



	Contacts[0].set_first_name("Shees");
	Contacts[0].set_last_name("ikram");
	Contacts[0].set_mobile_number("03207497709");
	Contacts[0].set_email_address("sheikh@gmail.com");
	Contacts[0].get_Address()->set_City("Faisalabad");
	Contacts[0].get_Address()->set_Country("Pakistan");
	Contacts[0].get_Address()->set_House("Amin Town");
	Contacts[0].get_Address()->set_Street("ST#07");






	Contacts[1].set_first_name("Ahshan");
	Contacts[1].set_last_name("Asim");
	Contacts[1].set_mobile_number("03207497709");
	Contacts[1].set_email_address("sheoik@gmail.com");
	Contacts[1].get_Address()->set_City("Faisalabad");
	Contacts[1].get_Address()->set_Country("Pakistan");
	Contacts[1].get_Address()->set_House("Mansoorabad");
	Contacts[1].get_Address()->set_Street("ST#06");


	Contacts[2].set_first_name("Danish");
	Contacts[2].set_last_name("lja ckln");
	Contacts[2].set_mobile_number("03207497709");
	Contacts[2].set_email_address("sheoik@gmail.com");
	Contacts[2].get_Address()->set_City("Faisalabad");
	Contacts[2].get_Address()->set_Country("Pakistan");
	Contacts[2].get_Address()->set_House("Mansoorabad");
	Contacts[2].get_Address()->set_Street("ST#06");


	Contacts[3].set_first_name("Faisal");
	Contacts[3].set_last_name("Z");
	Contacts[3].set_mobile_number("03207497709");
	Contacts[3].set_email_address("sheoik@gmail.com");
	Contacts[3].get_Address()->set_City("Faisalabad");
	Contacts[3].get_Address()->set_Country("Pakistan");
	Contacts[3].get_Address()->set_House("Mansoorabad");
	Contacts[3].get_Address()->set_Street("ST#06");

	Contacts[4].set_first_name("ajbcj");
	Contacts[4].set_last_name("awjlbklwn");
	Contacts[4].set_mobile_number("03207497709");
	Contacts[4].set_email_address("sheoik@gmail.com");
	Contacts[4].get_Address()->set_City("Faisalabad");
	Contacts[4].get_Address()->set_Country("Pakistan");
	Contacts[4].get_Address()->set_House("Mansoorabad");
	Contacts[4].get_Address()->set_Street("ST#06");

	for (int i = 0; i < 5; i++)
	{
		ContactsBooks[i].print_contacts_sorted("first name");
	}
}
	///Scenarion 02

	/*cout << "Total contacts:" << co.get_contacts_count() << endl;
	Contact* obj = new Contact[2];
	for (int i = 0; i < 2; i++)
	{
		co.add_contact(obj[i]);
	}
	cout << endl;
	cout << "Total contacts:" << co.get_contacts_count() << endl;*/

	////scenarion 03

//	Contact* obj1 = new Contact[5];
//	for (int i = 0; i < 5; i++)
//	{
//		co.add_contact(obj1[i]);//You want to give one same argumented object in the add_contact function when it calls you name etc
//	}
//	co.merge_duplicates();
//
//
//}