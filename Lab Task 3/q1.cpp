#include <iostream>
#include <string>

using namespace std;

class User {
public:
	int age;
	string name;
};

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Insufficient arguments." <<endl;
		return 1;
	}

	User user1;
	user1.name = argv[argc - 2];
	// strcpy(user1.name, argv[argc-2]);
	user1.age = stoi(argv[argc - 1]);

	cout << "My name is " << user1.name << 
	" and my age is " << user1.age << " years old." << endl;

	return 0;
}