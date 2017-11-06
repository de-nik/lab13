#include "pugixml.hpp"
#include <iostream>
#include <fstream>
#include <string>
struct Email {
	std::string nickname;
	std::string server;
};

struct Person {
	std::string  first_name;
	std::string  last_name;
	Email        email;
	size_t       age;
	std::string  phone;
};

int main(int argc, char* argv[]) {
	const char * myarg = argv[1];
	Person man;

	std::string temp;
	pugi::xml_document doc;
	pugi::xml_node person = doc.append_child("person");
	pugi::xml_node name = person.append_child("First_name");
	pugi::xml_node last_name = person.append_child("Last_name");
	pugi::xml_node email = person.append_child("email");
	pugi::xml_node age = person.append_child("age");
	pugi::xml_node phone = person.append_child("phone");

	std::cin >> temp;
	man.first_name = temp;
	const char * tmp = man.first_name.c_str();
	name.append_child(pugi::node_pcdata).set_value(tmp);
	
	std::cin >> temp;
	man.last_name = temp;
	tmp = man.last_name.c_str();
	last_name.append_child(pugi::node_pcdata).set_value(tmp);

	std::cin >> temp;
	std::string nickname;
	std::string server;
	std::copy(temp.begin(), temp.begin() + temp.find('@'), std::back_inserter(nickname));
	std::copy(temp.begin() + temp.find('@'), temp.end(), std::back_inserter(server));
	man.email.nickname = nickname;
	man.email.server = server;
	tmp = temp.c_str();
	email.append_child(pugi::node_pcdata).set_value(tmp);

	while (std::cin.peek() != '\n')
	{
		std::cin >> man.age;
		break;
	}

	std::cin >> temp;
	man.phone = temp;
	tmp = man.phone.c_str();
	phone.append_child(pugi::node_pcdata).set_value(tmp);

	doc.save_file(myarg);
}
