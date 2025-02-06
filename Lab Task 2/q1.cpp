#include<iostream>

using namespace std;

int main(int argc, char* argv[]) {

	if (argc < 2) {
		cout << "Please enter numbers to sum." <<endl;
	}
	int sum = 0;
	int *arr = new int[argc-1];

	for (int i = 0; i < argc - 1; i++) {
		*(arr + i) = stoi(argv[i + 1]);
	}

	for (int i = 0; i < argc - 1; i++) {
		sum += *(arr + i);
	}

	cout << "Sum = " << sum << endl;

	delete[] arr;

}