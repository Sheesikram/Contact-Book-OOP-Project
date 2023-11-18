//void ContactsBook::advance_search(std::string word)
//{
//	int count = 0;
//
//	for (int i = 0; i < contacts_count; i++)
//	{
//		advance_search_attribues(word, contacts_list[i].get_first_name(), count);
//		advance_search_attribues(word, contacts_list[i].get_last_name(), count);
//		advance_search_attribues(word, contacts_list[i].get_mobile_number(), count);
//		advance_search_attribues(word, contacts_list[i].get_email_address(), count);
//		//address
//
//		advance_search_attribues(word, contacts_list[i].get_address()->get_house(), count);
//		advance_search_attribues(word, contacts_list[i].get_address()->get_street(), count);
//		advance_search_attribues(word, contacts_list[i].get_address()->get_city(), count);
//		advance_search_attribues(word, contacts_list[i].get_address()->get_country(), count);
//
//
//		if (count >= word.length())
//		{
//			std::cout << i + 1 << ". ";
//			contacts_list[i].print_contacts();
//		}
//
//
//		count = 0;
//	}
//	if (count == 0)
//		std::cout << "No Results Found";
//}
//void ContactsBook::advance_search_attribues(std::string word, std::string attribute, int& count)
//{
//	for (int i = 0; i < attribute.length(); i++)
//	{
//		if (word[count] == attribute[i] || word[count] == attribute[i] + 32 || word[count] == attribute[i] - 32)
//			count++;
//	}
//}