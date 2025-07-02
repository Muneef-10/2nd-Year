#include <iostream>
#include <string>
using namespace std;
const int MAX_APPOINTMENTS = 10;
class Patient
{
protected:
    string name;
    int age;
    string medicalHistory;

public:
    Patient(string n, int a, string mh) : name(n), age(a), medicalHistory(mh) {}
    virtual void viewDetails()
    {
        cout << "Name: " << name << ", Age: " << age << ", Medical History: " << medicalHistory
             << endl;
    }
    virtual void scheduleAppointment()
    {
        cout << "Scheduling appointment for " << name << endl;
    }
    virtual ~Patient() {}
};
class InPatient : public Patient
{
private:
    string roomNumber;

public:
    InPatient(string n, int a, string mh, string room) : Patient(n, a, mh), roomNumber(room) {}
    void viewDetails() override
    {
        Patient::viewDetails();
        cout << "Room Number: " << roomNumber << endl;
    }
};
class OutPatient : public Patient
{
private:
    string appointmentTime;

public:
    OutPatient(string n, int a, string mh, string time) : Patient(n, a, mh), appointmentTime(time)
    {
    }
    void viewDetails() override
    {
        Patient::viewDetails();
        cout << "Appointment Time: " << appointmentTime << endl;
    }
};
class Doctor
{
private:
    string name;
    string specialization;
    string appointments[MAX_APPOINTMENTS];
    int appointmentCount;

public:
    Doctor(string n, string spec) : name(n), specialization(spec), appointmentCount(0) {}
    void viewAppointments()
    {
        cout << "Doctor: " << name << ", Specialization: " << specialization << endl;
        cout << "Appointments:" << endl;
        for (int i = 0; i < appointmentCount; i++)
        {
            cout << "- " << appointments[i] << endl;
        }
    }
    void addAppointment(const string &appointment)
    {
        if (appointmentCount < MAX_APPOINTMENTS)
        {
            appointments[appointmentCount++] = appointment;
            cout << "Appointment added: " << appointment << endl;
        }
        else
        {
            cout << "Error: Cannot add more appointments. Maximum limit reached!" << endl;
        }
    }
};
class Appointment
{
private:
    string date;
    Patient *patient;
    Doctor *doctor;

public:
    Appointment(string d, Patient *p, Doctor *dctr) : date(d), patient(p), doctor(dctr) {}
    void schedule()
    {
        cout << "Appointment Scheduled:" << endl;
        cout << "Date: " << date << endl;
        cout << "Patient Details: ";
        patient->viewDetails();
        cout << "Doctor Details: ";
        doctor->viewAppointments();
    }
    void cancel()
    {
        cout << "Appointment on " << date << " canceled." << endl;
    }
};
class Billing
{
private:
    Patient *patient;
    float amount;

public:
    Billing(Patient *p, float amt) : patient(p), amount(amt) {}
    void generateInvoice()
    {
        cout << "Generating Invoice:" << endl;
        patient->viewDetails();
        cout << "Amount Due: $" << amount << endl;
    }
};
int main()
{
    InPatient inp("Rahul", 65, "Diabetes", "Room 503");
    OutPatient outp("Ritik", 50, "Healthy", "10:30 AM");
    Doctor doc("Dr. Chetan", "Cardiology");
    inp.viewDetails();
    outp.viewDetails();
    doc.addAppointment("2024-11-20 10:00 AM");
    doc.addAppointment("2024-11-20 11:00 AM");
    doc.viewAppointments();
    Appointment app("2024-11-20 10:00 AM", &outp, &doc);
    app.schedule();
    Billing bill(&inp, 4500.00);
    bill.generateInvoice();
    return 0;
}