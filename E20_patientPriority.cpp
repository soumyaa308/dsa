Consider a Scenario for Hospital to cater services to different kinds of patients as Serious (Top priority), 
Non-Serious (medium priority), General Checkup (Least Priority). Implement the priority queue to cater services to the patients.
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class HospitalPriorityQueue {
private:
    struct Patient {
        string name;
        int priority;

        // Constructor to initialize Patient object
        Patient(string n, int p) : name(n), priority(p) {}

        // Overloading the < operator to compare patients based on their priority
        bool operator<(const Patient& other) const {
            // Here, we define the priority order: 1 (Serious) < 2 (Non-Serious) < 3 (General Checkup)
            return priority > other.priority;
        }
    };

    priority_queue<Patient> patients;

public:
    void addPatient(const string& name, int priority) {
        patients.push(Patient(name, priority));
    }

    string serveNextPatient() {
        if (!patients.empty()) {
            string nextPatient = patients.top().name;
            patients.pop();
            return nextPatient;
        } else {
            return "No patients in the queue.";
        }
    }
};

int main() {
    HospitalPriorityQueue hospitalQueue;

    // Taking user input for adding patients and their health conditions
    char choice;
    do {
        string name;
        int priority;
        cout << "Enter patient's name: ";
        cin >> name;
        cout << "Enter patient's health condition (1: Serious, 2: Non-Serious, 3: General Checkup): ";
        cin >> priority;

        hospitalQueue.addPatient(name, priority);

        cout << "Do you want to add another patient? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nPatients served in order:\n";
    cout << "--------------------------\n";
    string nextPatient = hospitalQueue.serveNextPatient();
    while (nextPatient != "No patients in the queue.") {
        cout << nextPatient << endl;
        nextPatient = hospitalQueue.serveNextPatient();
    }

    return 0;
}

This C++ program simulates a hospital priority queue where patients are added with their names and health conditions (priority), and they are served based on their priority.

Here's a breakdown of the code:

Class HospitalPriorityQueue:
Private nested structure Patient: Represents a patient with a name and priority (health condition). It also overloads the < operator to compare patients based on their priority.
Private member patients: A priority queue of Patient objects where patients are stored based on their priority.
addPatient method:
Adds a new patient to the priority queue with the provided name and priority.
serveNextPatient method:
Serves the next patient in the queue by popping the top patient from the priority queue and returning their name. If the queue is empty, it returns a message indicating that there are no patients in the queue.
main function:
Creates an instance of HospitalPriorityQueue.
Accepts user input for adding patients and their priorities.
Adds patients to the queue using the addPatient method.
Displays the patients served in order by continuously calling serveNextPatient until there are no patients left in the queue.
