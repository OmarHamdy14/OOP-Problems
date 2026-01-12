#include "P61.h"
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