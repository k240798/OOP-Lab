#include <iostream> 
#include <string>
#include <vector>

using namespace std;

// Forward declarations
class Doctor;
class BillingStaff;

class PatientRecord {
private:
    string name;
    string id;
    string dateOfBirth;
    
    vector<string> medicalHistory;
    vector<string> currentTreatments;
    vector<pair<string, double>> billingDetails; 

    void addMedicalEntry(const string& entry) {
        medicalHistory.push_back(entry);
    }

    void addTreatment(const string& treatment) {
        currentTreatments.push_back(treatment);
    }

    void addBillingEntry(const string& service, double amount) {
        billingDetails.push_back({service, amount});
    }

public:
    PatientRecord(const string& name, const string& id, const string& dob)
        : name(name), id(id), dateOfBirth(dob) {}

    struct PublicData {
        string name;
        string id;
        string dob;
    };

    PublicData getPublicData() const {
        return {name, id, dateOfBirth};
    }

    class MedicalAccess {
    protected:
        PatientRecord& record;
        MedicalAccess(PatientRecord& rec) : record(rec) {}
        
        const vector<string>& getMedicalHistory() const {
            return record.medicalHistory;
        }
        
        const vector<string>& getCurrentTreatments() const {
            return record.currentTreatments;
        }
        
        void recordMedicalEntry(const string& entry) {
            record.addMedicalEntry(entry);
        }
        
        void prescribeTreatment(const string& treatment) {
            record.addTreatment(treatment);
        }
        
        friend class Doctor;
    };

    class BillingAccess {
    protected:
        PatientRecord& record;
        BillingAccess(PatientRecord& rec) : record(rec) {}
        
        const vector<pair<string, double>>& getBillingDetails() const {
            return record.billingDetails;
        }
        
        void addServiceCharge(const string& service, double amount) {
            record.addBillingEntry(service, amount);
        }
        
        friend class BillingStaff;
    };
};

class Doctor {
private:
    string name;
    string licenseNumber;
    PatientRecord::MedicalAccess medicalAccess;

public:
    Doctor(const string& name, const string& license, PatientRecord& record)
        : name(name), licenseNumber(license), medicalAccess(record) {}

    void reviewMedicalHistory() const {
        cout << "Doctor " << name << " reviewing medical history:\n";
        for (const auto& entry : medicalAccess.getMedicalHistory()) {
            cout << "- " << entry << "\n";
        }
    }

    void addDiagnosis(PatientRecord& record, const string& diagnosis) {
        medicalAccess.recordMedicalEntry("Diagnosis: " + diagnosis);
        cout << "Diagnosis added by Dr. " << name << "\n";
    }

    void prescribeTreatment(PatientRecord& record, const string& treatment) {
        medicalAccess.prescribeTreatment(treatment);
        cout << "Treatment prescribed by Dr. " << name << "\n";
    }
};

class BillingStaff {
private:
    string name;
    string employeeId;
    PatientRecord::BillingAccess billingAccess;

public:
    BillingStaff(const string& name, const string& empId, PatientRecord& record)
        : name(name), employeeId(empId), billingAccess(record) {}

    void viewBillingDetails() const {
        cout << "Billing details viewed by " << name << ":\n";
        for (const auto& entry : billingAccess.getBillingDetails()) {
            cout << entry.first << ": $" << entry.second << "\n";
        }
    }

    void addServiceCharge(PatientRecord& record, const string& service, double amount) {
        billingAccess.addServiceCharge(service, amount);
        cout << "Service charge added by " << name << "\n";
    }
};

class Receptionist {
private:
    string name;
    string employeeId;

public:
    Receptionist(const string& name, const string& empId)
        : name(name), employeeId(empId) {}

    void viewPatientInfo(const PatientRecord& record) const {
        auto publicData = record.getPublicData();
        cout << "Receptionist " << name << " viewing patient info:\n";
        cout << "Name: " << publicData.name << "\n";
        cout << "ID: " << publicData.id << "\n";
        cout << "DOB: " << publicData.dob << "\n";
    }

    // Attempt to access medical data (should fail)
    void tryAccessMedicalData(PatientRecord& record) const {
        cout << "Receptionist attempting to access medical records...\n";
        // This would cause a compilation error if uncommented
        // auto treatments = record.getCurrentTreatments();
    }
};

int main() {
    PatientRecord sydneyCarton("John Doe", "P1001", "1985-05-15");

    Doctor drFinley("Oscar Finley", "MD12345", sydneyCarton);
    BillingStaff willSmith("Will Smith", "B7890", sydneyCarton);
    Receptionist receptionist("James Morgan", "R4567");

    cout << "\n=== Authorized Access Examples ===\n";
    receptionist.viewPatientInfo(sydneyCarton);
    
    drFinley.addDiagnosis(sydneyCarton, "Hypertension");
    drFinley.prescribeTreatment(sydneyCarton, "Lisinopril 10mg daily");
    drFinley.reviewMedicalHistory();
    
    willSmith.addServiceCharge(sydneyCarton, "Consultation", 150.00);
    willSmith.addServiceCharge(sydneyCarton, "Lab Work", 89.50);
    willSmith.viewBillingDetails();

    // Demonstrate unauthorized access attempts
    cout << "\n=== Unauthorized Access Attempts ===\n";
    receptionist.tryAccessMedicalData(sydneyCarton);
    
    // These would cause compilation errors if attempted:
    // receptionist.addDiagnosis(sydneyCarton, "Fake diagnosis");
    // willSmith.prescribeTreatment(sydneyCarton, "Unauthorized treatment");
    // drFinley.addServiceCharge(sydneyCarton, "Unauthorized charge", 100.00);

    return 0;
}
