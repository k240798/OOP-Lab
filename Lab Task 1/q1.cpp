#include <iostream>
#include <cstdlib>  

using namespace std;

void findSecondHighest(float *arr, int size, float &highest, float &secondHighest) {
    highest = secondHighest = -__FLT_MAX__;  

    for (int i = 0; i < size; i++) {
        if (*(arr + i) > highest) {  
            secondHighest = highest;  
            highest = *(arr + i);     
        } 
        else if (*(arr + i) > secondHighest && *(arr + i) != highest) {  
            secondHighest = *(arr + i);  
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 21) {  
        cout << "Usage: " << argv[0] << " <20 float numbers>\n";
        return 1;  
    }

    float arr[20];
    for (int i = 1; i <= 20; i++) {  
        arr[i - 1] = atof(argv[i]);  
    }

    float highest, secondHighest;
    findSecondHighest(arr, 20, highest, secondHighest);

    cout << "Second Highest Number: " << secondHighest << endl;

    return 0;
}
