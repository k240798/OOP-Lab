#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Subject {
    string subjectName;  
};

struct Entity {
    int id;                    
    vector<Subject> subjects;  
};

int main() {
    int N;
    cout << "Enter the number of entities: ";
    cin >> N;

    vector<Entity> entities(N);  
    
    for (int i = 0; i < N; i++) {
        cout << "\nEnter ID for entity " << i + 1 << ": ";
        cin >> entities[i].id;

        int numSubjects;
        cout << "Enter the number of subjects for entity " << i + 1 << ": ";
        cin >> numSubjects;
        
        for (int j = 0; j < numSubjects; j++) {
            string subject;
            cout << "Enter subject name " << j + 1 << " for entity " << i + 1 << ": ";
            cin >> subject;

            entities[i].subjects.push_back(Subject{subject});
        }
    }

    cout << "\nEntities and their Subjects:\n";
    for (const auto& entity : entities) {
        cout << "Entity ID: " << entity.id << "\n";
        cout << "Subjects: ";
        for (const auto& subject : entity.subjects) {
            cout << subject.subjectName << " ";
        }
        cout << "\n";
    }

    return 0;
}
