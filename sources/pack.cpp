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

	std::cout << "First name: ";
	std::cin >> temp;
	man.first_name = temp;
	name.append_child(pugi::node_pcdata).set_value(man.first_name.c_str());

	std::cout << "Last name: ";
	std::cin >> temp;
	man.last_name = temp;
	last_name.append_child(pugi::node_pcdata).set_value(man.last_name.c_str());

	std::cout << "email: ";
	std::cin >> temp;
	std::string nickname;
	std::string server;
	std::copy(temp.begin(), temp.begin() + temp.find('@'), std::back_inserter(nickname));
	std::copy(temp.begin() + temp.find('@'), temp.end(), std::back_inserter(server));
	man.email.nickname = nickname;
	man.email.server = server;
	email.append_child(pugi::node_pcdata).set_value(temp.c_str());

	std::cout << "age(optional): ";
	std::string temp_age;
	std::cin.get();
	std::getline(std::cin, temp_age);
	if (temp_age.size() != 0) {
		man.age = std::stoi(temp_age);
		age.append_child(pugi::node_pcdata).set_value(temp_age.c_str());
	}
	
	std::cout << "phone(optional): ";
	std::string temp_phone;
	std::getline(std::cin, temp_phone);
	if (temp_phone.size() != 0) {
		man.phone = temp_age;
		phone.append_child(pugi::node_pcdata).set_value(temp_phone.c_str());
	}
	doc.save_file(myarg);
	std::cout << "Done";

}
