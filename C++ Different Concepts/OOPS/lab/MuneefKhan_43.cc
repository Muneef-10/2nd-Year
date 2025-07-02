#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Patient {
protected:
    string name;
    int age;
    string medicalHistory;

public:
    Patient(string n, int a, string mh) : name(n), age(a), medicalHistory(mh) {}

    string getName() const { return name; } 

    virtual void viewDetails() {
        cout << "Patient Name: " << name << "\nAge: " << age << "\nMedical History: " << medicalHistory << endl;
    }
    virtual void scheduleAppointment() {
        cout << "Scheduling appointment for: " << name << endl;
    }
    virtual ~Patient() {}
};

class InPatient : public Patient {
private:
    string roomNumber;

public:
    InPatient(string n, int a, string mh, string room)
        : Patient(n, a, mh), roomNumber(room) {}

    void viewDetails() override {
        Patient::viewDetails();
        cout << "Room Number: " << roomNumber << endl;
    }
};

class OutPatient : public Patient {
private:
    string appointmentTime;

public:
    OutPatient(string n, int a, string mh, string time)
        : Patient(n, a, mh), appointmentTime(time) {}

    void viewDetails() override {
        Patient::viewDetails();
        cout << "Appointment Time: " << appointmentTime << endl;
    }
};

class Doctor {
private:
    string name;
    string specialization;
    vector<string> appointments;

public:
    Doctor(string n, string spec) : name(n), specialization(spec) {}

    string getName() const { return name; } 

    void viewAppointments() {
        cout << "Doctor: " << name << "\nSpecialization: " << specialization << endl;
        cout << "Appointments:\n";
        for (const auto &appt : appointments) {
            cout << "  - " << appt << endl;
        }
    }
    void addAppointment(const string &appointment) {
        appointments.push_back(appointment);
    }
};

class Appointment {
private:
    string date;
    Patient *patient;
    Doctor *doctor;

public:
    Appointment(string d, Patient *p, Doctor *dctr)
        : date(d), patient(p), doctor(dctr) {}

    void schedule() {
        if (!patient || !doctor) {
            throw runtime_error("Invalid appointment details!");
        }
        cout << "Appointment Scheduled:\nDate: " << date
             << "\nPatient: " << patient->getName() 
             << "\nDoctor: " << doctor->getName() << endl; 
        doctor->addAppointment(date);
    }
    void cancel() {
        cout << "Appointment on " << date << " has been canceled." << endl;
    }
};

class Billing {
private:
    Patient *patient;
    float amount;

public:
    Billing(Patient *p, float amt) : patient(p), amount(amt) {}

    void generateInvoice() {
        if (!patient) {
            throw runtime_error("Billing error: No patient assigned!");
        }
        cout << "Invoice:\nPatient: " << patient->getName() 
             << "\nAmount Due: $" << amount << endl;
    }
};

int main() {
    try {
        InPatient inpatient("Arpit", 45, "Diabetes", "Room 101");
        OutPatient outpatient("Sahitya", 30, "Flu", "10:30 AM");

        Doctor doctor("Dr. Sakib", "Cardiology");

        cout << "\n--- Patient Details ---" << endl;
        inpatient.viewDetails();
        outpatient.viewDetails();

        cout << "\n--- Scheduling Appointments ---" << endl;
        Appointment appointment1("2024-11-20", &inpatient, &doctor);
        appointment1.schedule();

        Appointment appointment2("2024-11-21", &outpatient, &doctor);
        appointment2.schedule();

        cout << "\n--- Doctor's Schedule ---" << endl;
        doctor.viewAppointments();

        cout << "\n--- Billing ---" << endl;
        Billing billing1(&inpatient, 1200.50);
        billing1.generateInvoice();

        Billing billing2(&outpatient, 300.75);
        billing2.generateInvoice();

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
