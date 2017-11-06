nclude "pugixml.hpp"
#include <iostream>

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

std::ostream & operator<<(std::ostream &out, Person &man)
{
	std::cout << "[Person]" << std::endl;
	std::cout << "First name: " << man.first_name << std::endl;
	std::cout << "Last name: " << man.last_name << std::endl;
	std::cout << "email: " << man.email.nickname << man.email.server << std::endl;
	std::cout << "age: " << man.age << std::endl;
	std::cout << "phone: " << man.phone << std::endl;
	return out;
}

int main(int argc, char* argv[])
{
	const char * myarg = argv[1];
	Person person;
	//const char * myarg = "tree.xml";
	Person man;
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(myarg);
	if (result) {
		man.first_name = doc.child("person").child("First_name").text().as_string();
		man.last_name = doc.child("person").child("Last_name").text().as_string();

		std::string temp = doc.child("person").child("email").text().as_string();
		std::string nickname;
		std::string server;
		std::copy(temp.begin(), temp.begin() + temp.find('@'), std::back_inserter(nickname));
		std::copy(temp.begin() + temp.find('@'), temp.end(), std::back_inserter(server));
		man.email.nickname = nickname;
		man.email.server = server;

		man.age = doc.child("person").child("age").text().as_int(); 
		man.phone = doc.child("person").child("phone").text().as_string();

		std::cout << man;
	}
	else {
		std::cout << myarg << std::endl;
	}
	system("pause");
}


