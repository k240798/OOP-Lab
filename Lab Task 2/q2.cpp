#include<iostream>
using namespace std;
void* sumArray(void* arr, int size);

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Please enter numbers to modify." << endl;
	}

	int array[argc - 1];
	for (int i = 0; i < argc - 1; i++) {
		array[i] = stoi(argv[i+1]);
	}

	sumArray(static_cast<void*>(array), argc -1);

	 cout << "Modified array: ";
    for (int i = 0; i < argc - 1; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;

}


void* sumArray(void* arr, int size) {
	int* resultantArray = static_cast<int*>(arr);

	for (int i = 0; i < size; i++) {
		resultantArray[i] += 5;
	}

	return arr;
}

