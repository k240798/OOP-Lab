#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Entity {
    int id;
    string name;
};

bool compareById(const Entity& a, const Entity& b) {
    return a.id < b.id;
}

bool compareByName(const Entity& a, const Entity& b) {
    return a.name[0] < b.name[0];
}

int main() {
    int N;
    cout << "Enter the number of entities: ";
    cin >> N;
    vector<Entity> entities(N);

    for (int i = 0; i < N; i++) {
        cout << "Enter ID and Name for entity " << i + 1 << ": ";
        cin >> entities[i].id >> entities[i].name;
    }

    sort(entities.begin(), entities.end(), compareById);
    cout << "\nSorted by ID:\n";
    for (const auto& entity : entities) {
        cout << "ID: " << entity.id << ", Name: " << entity.name << "\n";
    }

    sort(entities.begin(), entities.end(), compareByName);
    cout << "\nSorted by First Character of Name:\n";
    for (const auto& entity : entities) {
        cout << "ID: " << entity.id << ", Name: " << entity.name << "\n";
    }

    return 0;
}
