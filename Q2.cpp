#include <iostream>
#include <string>
using namespace std;

class MedicationEntry {
public:
    string drugName;
    string dose;
    string timeGiven;

    MedicationEntry(string d, string ds, string t) {
        drugName = d;
        dose = ds;
        timeGiven = t;
    }

    void display() {
        cout << "Medication:\n";
        cout << " Drug: " << drugName << endl;
        cout << " Dose: " << dose << endl;
        cout << " Time Given: " << timeGiven << endl;
    }
};

class VitalSignsCheck {
public:
    float temperature;
    int heartRate;
    string timeChecked;

    VitalSignsCheck(float temp, int hr, string t) {
        temperature = temp;
        heartRate = hr;
        timeChecked = t;
    }

    void display() {
        cout << "Vital Signs:\n";
        cout << " Temperature: " << temperature << endl;
        cout << " Heart Rate: " << heartRate << endl;
        cout << " Time Checked: " << timeChecked << endl;
    }
};

class DiagnosisNote {
public:
    string noteText;
    string doctorName;
    string date;

    DiagnosisNote(string note, string doc, string d) {
        noteText = note;
        doctorName = doc;
        date = d;
    }

    void display() {
        cout << "Diagnosis:\n";
        cout << " Note: " << noteText << endl;
        cout << " Doctor: " << doctorName << endl;
        cout << " Date: " << date << endl;
    }
};

class PatientRecord {
private:
    int patientId;
    string name;
    string dob;

    MedicationEntry* med;
    VitalSignsCheck* vitals;
    DiagnosisNote* diagnosis;

public:
    PatientRecord(int id, string n, string d) {
        patientId = id;
        name = n;
        dob = d;

        med = new MedicationEntry("Paracetamol", "500mg", "10:00 AM");
        vitals = new VitalSignsCheck(98.6, 72, "10:30 AM");
        diagnosis = new DiagnosisNote("Fever", "Dr. Ahmed", "26-02-2026");
    }

    ~PatientRecord() {
        delete med;
        delete vitals;
        delete diagnosis;
        cout << "PatientRecord and all medical entries deleted.\n";
    }

    void displayRecord() {
        cout << "----- Patient Record -----\n";
        cout << "ID: " << patientId << endl;
        cout << "Name: " << name << endl;
        cout << "DOB: " << dob << endl << endl;

        med->display();
        cout << endl;

        vitals->display();
        cout << endl;

        diagnosis->display();
        cout << endl;
    }
};

int main() {
    PatientRecord* patient = new PatientRecord(1, "Lily Smith", "01-01-2000");

    patient->displayRecord();

    delete patient;

    return 0;
}