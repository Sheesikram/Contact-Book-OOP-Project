#include "ContactBook.h"
#include<fstream>

ContactsBook::ContactsBook()
{
	size_of_contacts = 5;
	contacts_list = new Contact[size_of_contacts];
	contacts_count = 1;
	
}

void ContactsBook::add_contact(const Contact& contact)
{

	if (this->size_of_contacts == this->contacts_count) {
		this->resize_list();
	}
	
	
		contacts_list[contacts_count++] = contact;
	



	
	/*
		- Check if the list is full, if it is full call the resize function
		- If list is not full add the contact to the end of the array
		- (end means the place where last contact was inserted)
		- At start it will be 0th index as no contact has been inserted before so
		- count is zero (contacts_count member)
		- Increment the count
		- As inserted successfully, return 1
	*/
}



int ContactsBook::total_contacts()
{
	return contacts_count;
	/*
	*	Return the total contacts currently stored
	*/

	/*
	*	Remove this return -1; before writing your code
	*/
}

bool ContactsBook::full()
{
	if (contacts_count == size_of_contacts)
	{
		return true;
	}
	/*
	* Return true if list is full, false otherwise
	*/

	/*
	*	Remove this return false; before writing your code
	*/
	return false;
}

void ContactsBook::set_size_of_contacts(int size_of_contacts) {
	this->size_of_contacts = size_of_contacts;
}
void ContactsBook::set_contacts_count(int contacts_count) {
	this->contacts_count = contacts_count;
}
int ContactsBook::get_size_of_contacts() {
	return size_of_contacts;
}
int ContactsBook::get_contacts_count() {
	return contacts_count;
}
void ContactsBook::advance_search(std::string word)
{
	int count = 0;

	for (int i = 0; i < contacts_count; i++)
	{
		advance_search_attribues(word, contacts_list[i].get_first_name(), count);
		advance_search_attribues(word, contacts_list[i].get_last_name(), count);
		advance_search_attribues(word, contacts_list[i].get_mobile_number(), count);
		advance_search_attribues(word, contacts_list[i].get_email_address(), count);
		//address

		advance_search_attribues(word, contacts_list[i].get_Address()->get_House(), count);
		advance_search_attribues(word, contacts_list[i].get_Address()->get_Street(), count);
		advance_search_attribues(word, contacts_list[i].get_Address()->get_City(), count);
		advance_search_attribues(word, contacts_list[i].get_Address()->get_Country(), count);


		if (count >= word.length())
		{
			std::cout << i + 1 << ". ";
			//contacts_list[i].//some thing for print 
		}


		count = 0;
	}
	if (count == 0)
		std::cout << "No Results Found";
}
void ContactsBook::advance_search_attribues(std::string word, std::string attribute, int& count)
{
	for (int i = 0; i < attribute.length(); i++)
	{
		if (word[count] == attribute[i] || word[count] == attribute[i] + 32 || word[count] == attribute[i] - 32)
			count++;
	}
}
void ContactsBook::resize_list()
{
	Contact* cptr;
	cptr = new Contact[size_of_contacts * size_of_contacts];
	for (int i = 0; i < size_of_contacts; i++)
	{
		cptr[i] = *(contacts_list[i].copy_contact());

	}

	delete[]contacts_list;
	contacts_list = NULL;
	contacts_list = cptr;
	size_of_contacts = size_of_contacts * size_of_contacts;
	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from
	*       previous array to this array one by one, get the copy of each contact using copy_contact
	*       function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/
}

Contact* ContactsBook::search_contact(std::string first_name, std::string last_name)
{
	/*
	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
	*	Remove this return nullptr; before writing your code
	*/
	Contact* p = new Contact[size_of_contacts];
	for (int i = 0; i < size_of_contacts; i++)
	{
		if (first_name == contacts_list[i].get_first_name() && last_name == contacts_list->get_last_name())
		{
			p[i] = *(contacts_list[i].copy_contact());
		}
	}
	return p;
}

Contact* ContactsBook::search_contact(std::string phone)
{
	/*
	*	Remove this return nullptr; before writing your code
	*/
	Contact* p = new Contact[size_of_contacts];
	for (int i = 0; i < size_of_contacts; i++)
	{
		if (phone == contacts_list[i].get_mobile_number())
		{
			p[i] = *(contacts_list[i].copy_contact());
		}
	}
	return p;
}

Contact* ContactsBook::search_contact(const Address& address)
{
	/*
	*	Remove this return nullptr; before writing your code
	*/
	Contact* p = new Contact[size_of_contacts];
	for (int i = 0; i < size_of_contacts; i++)
	{
		if (contacts_list[i].get_Address()->equals(address))
		{
			p[i] = *(contacts_list[i].copy_contact());
		}
	}
	return p;
}

ContactsBook::ContactsBook(int size_of_list)
{
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/
	size_of_contacts = size_of_list;
	this->contacts_list = new Contact[size_of_list];
	for (int i = 0; i < size_of_contacts; i++)
	{
		contacts_list[i].set_first_name("shees");
		contacts_list[i].set_last_name("ikram");
		contacts_list[i].set_mobile_number("0323-5766237");
		contacts_list[i].set_email_address("sheesikram@gmail.com");
		contacts_count++;
	}
}

void ContactsBook::print_contacts_sorted(std::string choice)
{
	Contact* cp;

	// cp = new Contact[size_of_contacts]; 


		cp = contacts_list;
	sort_contacts_list(cp, choice);
	for (int i = 0; i < this->contacts_count; i++)
	{
		std::cout << "->" << cp[i].get_first_name() << "<- " << "->" << cp[i].get_last_name() << "<- "
			<< "<-" << cp[i].get_mobile_number() << "<- " << "->" << cp[i].get_email_address() << "<- " << std::endl;
		//std::cout << (cp[i].get_Address()) << std::endl;
	}
	Address* a;
	a = new Address;
	a->print_address();
	//delete cp;
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
}

void ContactsBook::sort_contacts_list(Contact* contacts_list, std::string choice)
{
	if (choice == "first name")
	{

		for (int i = 0; i < this->contacts_count - 1; i++)
		{
			for (int j = i + 1; j < this->contacts_count; j++)
			{
				std::string str1 = contacts_list[i].get_first_name();
				std::string str2 = contacts_list[j].get_first_name();
				if (str1[0] < str2[0])
					std::swap(contacts_list[i], contacts_list[j]);
			}
		}

	}
	else if (choice == "last name")
	{

		for (int i = 0; i < this->contacts_count - 1; i++)
		{
			for (int j = i + 1; j < this->contacts_count; j++)
			{
				std::string str1 = contacts_list[i].get_last_name();
				std::string str2 = contacts_list[j].get_last_name();
				if (str1[0] < str2[0])
					std::swap(contacts_list[i], contacts_list[j]);
			}
		}
	}
	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/
}

void ContactsBook::merge_duplicates()
{
	Contact s;
	int k = 0;
	int e = 0;
	int* ptr = new int[10];
	Contact* p = new Contact[10];
	for (int i = 0; i < size_of_contacts - 1; i++)
	{
		for (int j = i + 1; j < size_of_contacts; j++)
		{
			//if (contacts_list[i].Checker(contacts_list[i],contacts_list[j]))
			if (s.Checker(contacts_list[i], contacts_list[j]))
			{
				ptr[e] = j;
				p[e] = contacts_list[i];
				e++;
				for (k = j; k < (size_of_contacts)-1; k++)
				{
					contacts_list[k] = contacts_list[k + 1];
				}
				contacts_count--;
			}
		}
	}
	std::cout << "The merged contacts are as follows;" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < k; i++)
	{
		std::cout << "Index Number: " << ptr[i] << std::endl;
		std::cout << p[i].get_first_name() << std::endl;
		std::cout << p[i].get_last_name() << std::endl;
		std::cout << p[i].get_mobile_number() << std::endl;
		std::cout << p[i].get_email_address() << std::endl;
		std::cout << p[i].get_Address()->get_City() << std::endl;
		std::cout << p[i].get_Address()->get_Country() << std::endl;
		std::cout << p[i].get_Address()->get_House() << std::endl;
		std::cout << p[i].get_Address()->get_Street() << std::endl;


	}
	std::cout << "Count is:" << contacts_count;
	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts merged, and count of merged contacts
}


void ContactsBook::load_from_file(std::string file_name)
{
	Contact* cb;
	std::ifstream in;
	in.open(file_name);
	in >> size_of_contacts;
	in >> contacts_count;
	ContactsBook* obj = new ContactsBook[size_of_contacts];
	cb = new Contact[contacts_count];
	
	std::string str;
	
	for (int i = 0; i < contacts_count; i++)
	{
		in >> str;
		str.replace(str.length() - 1, 1, "");//str::swap() function use
		
		obj[i].contacts_list[i].set_first_name(str);
		in >> str;
		str.replace(str.length() - 1, 1, "");
		
		obj[i].contacts_list[i].set_last_name(str);
		in >> str;
		str.replace(str.length() - 1, 1, "");
		
		obj[i].contacts_list[i].set_email_address(str);
		in >> str;
		str.replace(str.length() - 1, 1, "");
		
		obj[i].contacts_list[i].set_mobile_number(str);

	}
	in.close();
	//return obj;
	/*
	*	Read contacts back from file in the same format
	*	Read the contacts_count, and run a loop for this contacts_count and read the
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close the file
	*/
}


void ContactsBook::save_to_file(std::string file_name)
{

	Contact c;
	Address a;
	std::ofstream out;
	out.open(file_name);
	out << size_of_contacts << std::endl;
	out << contacts_count << std::endl;
	out << c.get_first_name() << "," << c.get_last_name() << "," << c.get_mobile_number() << "," << c.get_email_address() << std::endl;
	out << a.get_House() << "," << a.get_Street() << "," << a.get_City() << "," << a.get_Country() << std::endl;
	out.close();
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
}


