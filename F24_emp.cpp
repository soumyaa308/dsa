Company maintains employee information as employee ID, name, designation and salary. 
Allow user to add, delete information of employee. Display information of particular employee. 
If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. 
Use index sequential file to maintain the data.

*/
#include <iostream>
#include <fstream>
using namespace std;

class Record {
    int id;
    string name;
    int salary;
    string designation;

public:
    Record();
    int getIdno();
    void getData();
    void putData();
};

Record::Record() {
    id = 0;
    name = ' ';
    designation = ' ';
    salary = 0;
}

int Record::getIdno() {
    return (id);
}

void Record::getData() {
    cout << "\nEnter Details: ";
    cout << "\nId no: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Salary: ";
    cin >> salary;
    cout << "Designation: ";
    cin >> designation;
}

void Record::putData() {
    cout << "\nId No.: ";
    cout << id;
    cout << "\t\tName: ";
    cout << name;
    cout << "\nSalary: ";
    cout << salary;
    cout << "\tDesignation: ";
    cout << designation;
}

class File {
    ifstream fin;
    ofstream fout;
    fstream fs;

public:
    void insert();
    void display();
    void search(int);
    int Delete(int);
    int edit(int);
};

void File::insert() {
    Record r;
    r.getData();
    fout.open("EmployeeDB", ios::ate | ios::app);
    fout.write((char *)&r, sizeof(r));
    fout.close();
}

void File::display() {
    Record r;
    fin.open("EmployeeDB");
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r)))
        r.putData();

    fin.close();
}

void File::search(int id) {
    Record r;
    int flag = 0;
    fin.open("EmployeeDB");
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
            break;
        }
    }

    fin.close();
    if (flag == 1) {
        cout << "\nRecord Found:";
        r.putData();
    }
    else
        cout << "\nRecord not Found ";
}

int File::Delete(int id) {
    Record r;
    int flag = 0;
    fin.open("EmployeeDB");
    fout.open("Temp", ios::ate | ios::app);
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
        }
        else {
            fout.write((char *)&r, sizeof(r));
        }
    }
    fin.close();
    fout.close();
    remove("EmployeeDB");
    rename("Temp", "EmployeeDB");
    return (flag);
}

int File::edit(int id) {
    Record r;
    int flag = 0;
    fs.open("EmployeeDB");
    fs.seekg(0, ios::beg);
    while (fs.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
            cout << "\nEnter New Details: ";
            r.getData();
            fs.seekp((int)fs.tellg() - sizeof(r), ios::beg);
            fs.write((char *)&r, sizeof(r));
        }
    }
    fs.close();
    return (flag);
}

int main() {
    File f;
    int ch, n, i, flag = 0;
    do {
        cout << "\n\n\t-----M E N U-----";
        cout << "\n\n1. Build A Master Table";
        cout << "\n2. List A Table";
        cout << "\n3. Insert a New Entry";
        cout << "\n4. Delete Old Entry";
        cout << "\n5. Edit an Entry";
        cout << "\n6. Search for a Record";
        cout << "\n7. Quit";
        cout << "\nEnter your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                if (flag == 0) {
                    cout << "\nEnter No of Records to insert : ";
                    cin >> n;
                    for (i = 0; i < n; i++) {
                        f.insert();
                    }
                    flag = 1;
                }
                else {
                    cout << "\nSorry.. Table is Already build... \n If want to add record please select Insert a New Entry in option.....";
                }
                break;
            case 2:
                f.display();
                break;
            case 3:
                f.insert();
                break;
            case 4:
                cout << "\nEnter Id No of Employee Whose Record is to be Deleted: ";
                cin >> n;
                i = f.Delete(n);
                if (i == 1)
                    cout << "\nRecord Deleted Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 5:
                cout << "\nEnter Id No of Employee Whose Record is to be Edit: ";
                cin >> n;
                i = f.edit(n);
                if (i == 1)
                    cout << "\nRecord Modified Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 6:
                cout << "\nEnter Id No of Employee Whose Record is to be Searched: ";
                cin >> n;
                f.search(n);
                break;
            case 7:
                break;
            default:
                cout << "\nEnter Valid Choice.....";
        }
    } while (ch != 7);
    return (0);
}

This C++ program is for managing employee records using file handling. Here's a breakdown of the code:

Class Record:
It represents a single employee record with fields for ID, name, salary, and designation.
It has methods to get and put data for an employee record.
Constructor:
Initializes the member variables of the Record class.
Member functions:
getData(): Accepts input for the employee details.
putData(): Displays the employee details.
getIdno(): Returns the ID number of the employee.
Class File:
It handles file operations related to employee records, such as insertion, display, search, deletion, and editing.
Member functions of File class:
insert(): Inserts a new employee record into the file.
display(): Displays all the employee records stored in the file.
search(int id): Searches for an employee record based on the given ID.
Delete(int id): Deletes an employee record based on the given ID.
edit(int id): Edits an existing employee record based on the given ID.
main() function:
Displays a menu to perform various operations on employee records.
Executes the chosen operation based on user input.
Continues to execute until the user chooses to quit.
Menu options:
Build a master table: Inserts multiple employee records into the file.
List a table: Displays all employee records.
Insert a new entry: Adds a new employee record.
Delete old entry: Deletes an existing employee record.
Edit an entry: Modifies an existing employee record.
Search for a record: Searches for an employee record based on ID.
Quit: Exits the program.

