#include <iostream>
#include <cstdlib>  

using namespace std;

int main(int argc, char *argv[]) {
    int sum = 0;
    
    if (argc < 2) {
        cout << "Please provide some numbers as command line arguments." << endl;
        return 1;
    }
    
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);  
    }

    cout << "Sum of the elements: " << sum << endl;
    
    return 0;
}
