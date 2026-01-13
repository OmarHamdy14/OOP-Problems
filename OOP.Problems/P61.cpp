#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

/*
* Problem Statement
Hospital Information System
Doctors → manage Patients. 
Patients → have MedicalRecords, Prescriptions, LabTests. 
Treatments differ per department.
*/

class MedicalRecord {
    string diagnosis;
public:
    MedicalRecord(const string& d) : diagnosis(d) {}
    string GetDiagnosis() const { return diagnosis; }
};


class Prescription {
public:
    virtual ~Prescription() = default;
    virtual string Info() const = 0;
};

class DrugPrescription : public Prescription {
    string drug;
public:
    DrugPrescription(const string& d) : drug(d) {}
    string Info() const override {
        return "Drug Prescription: " + drug;
    }
};

class TherapyPrescription : public Prescription {
    string therapy;
public:
    TherapyPrescription(const string& t) : therapy(t) {}
    string Info() const override {
        return "Therapy: " + therapy;
    }
};


class LabTest {
public:
    virtual ~LabTest() = default;
    virtual string Result() const = 0;
};

class BloodTest : public LabTest {
public:
    string Result() const override {
        return "Blood Test: ....";
    }
};

class Test2 : public LabTest {
public:
    string Result() const override {
        return "Test2: ...";
    }
};

class Patient {
    string name;
    vector<MedicalRecord> records;
    vector<unique_ptr<Prescription>> prescriptions;
    vector<unique_ptr<LabTest>> tests;
public:
    Patient(const string& n) : name(n) {}

    string GetName() const { return name; }

    void AddRecord(const MedicalRecord& r) {
        records.push_back(r);
    }

    void AddPrescription(unique_ptr<Prescription> p) {
        prescriptions.push_back(move(p));
    }

    void AddLabTest(unique_ptr<LabTest> t) {
        tests.push_back(move(t));
    }

    void ShowHistory() const {
        cout << "\nPatient: " << name << endl;

        for (auto& r : records)
            cout << "Diagnosis: " << r.GetDiagnosis() << endl;

        for (auto& p : prescriptions)
            cout << p->Info() << endl;

        for (auto& t : tests)
            cout << t->Result() << endl;
    }
};


class Treatment {
public:
    virtual ~Treatment() = default;
    virtual void Apply(Patient& p) = 0;
};

class CardiologyTreatment : public Treatment {
public:
    void Apply(Patient& p) override {
        p.AddPrescription(make_unique<DrugPrescription>("Heart Medication"));
        p.AddLabTest(make_unique<BloodTest>());
    }
};

class NeurologyTreatment : public Treatment {
public:
    void Apply(Patient& p) override {
        p.AddPrescription(make_unique<TherapyPrescription>("Therapy"));
        p.AddLabTest(make_unique<Test2>());
    }
};


class Doctor {
    string name;
    unique_ptr<Treatment> treatment;
public:
    Doctor(const string& n, unique_ptr<Treatment> t)
        : name(n), treatment(move(t)) {
    }

    void Treat(Patient& patient) {
        cout << "\nDoctor " << name << " treating " << patient.GetName() << endl;
        treatment->Apply(patient);
    }
};
