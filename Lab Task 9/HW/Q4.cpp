#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual double getTuition(const string& status, int creditHours) = 0;

    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;  

public:
    GraduateStudent(const string& research = "") : researchTopic(research) {}

    double getTuition(const string& status, int creditHours) override {
        double tuition = 0.0;
        
        if (status == "undergraduate") {
            tuition = creditHours * 200.0;
        } else if (status == "graduate") {
            tuition = creditHours * 300.0;
        } else if (status == "doctoral") {
            tuition = creditHours * 400.0;
        }

        return tuition;
    }

    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }
};

int main() {
    GraduateStudent gradStudent("Quantum Computing");

    gradStudent.setResearchTopic("Artificial Intelligence");

    cout << "Research Topic: " << gradStudent.getResearchTopic() << endl;

    string status = "graduate";
    int creditHours = 15;
    cout << "Tuition: $" << gradStudent.getTuition(status, creditHours) << endl;

    return 0;
}
