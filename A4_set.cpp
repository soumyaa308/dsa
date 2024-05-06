Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up clients 
telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a
set of telephone numbersTo create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set ,
 b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection, 
d. Size () Return number of values in collection Iterator 
() Return an iterator used to loop over collection, 
e. Intersection of two sets , 
f. Union of two sets, 
g. Difference between two sets, 
h. Subset
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Set {
private:
    vector<int> elements;

public:
    void Add(int newElement) {
        if (!Contains(newElement)) {
            elements.push_back(newElement);
        }
    }

    void Remove(int element) {
        auto it = find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        }
    }

    void Modify(int oldElement, int newElement) {
        auto it = find(elements.begin(), elements.end(), oldElement);
        if (it != elements.end() && !Contains(newElement)) {
            *it = newElement;
        }
    }

    bool Contains(int element) const {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    size_t Size() const {
        return elements.size();
    }

    void Display() const {
        for (int elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }

    static Set Intersection(const Set& a, const Set& b) {
        Set result;
        for (int elem : a.elements) {
            if (b.Contains(elem)) {
                result.Add(elem);
            }
        }
        return result;
    }

    static Set Union(const Set& a, const Set& b) {
        Set result = a;
        for (int elem : b.elements) {
            result.Add(elem);
        }
        return result;
    }

    static Set Difference(const Set& a, const Set& b) {
        Set result;
        for (int elem : a.elements) {
            if (!b.Contains(elem)) {
                result.Add(elem);
            }
        }
        return result;
    }

    bool IsSubset(const Set& other) const {
        for (int elem : elements) {
            if (!other.Contains(elem)) {
                return false;
            }
        }
        return true;
    }
};

void PopulateSet(Set& set) {
    int n, element;
    cout << "How many elements do you want to add? ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        set.Add(element);
    }
}

void AddElement(Set& set) {
    int element;
    cout << "Enter element to add: ";
    cin >> element;
    set.Add(element);
    cout << "Element added successfully." << endl;
}

void RemoveElement(Set& set) {
    int element;
    cout << "Enter element to remove: ";
    cin >> element;
    if (set.Contains(element)) {
        set.Remove(element);
        cout << "Element removed successfully." << endl;
    } else {
        cout << "Element not found in the set." << endl;
    }
}

int main() {
    Set setA, setB;

    cout << "Populate Set A:" << endl;
    PopulateSet(setA);

    cout << "Populate Set B:" << endl;
    PopulateSet(setB);

    char choice;
    do {
        cout << "\nOptions:\n";
        cout << "a. Add element to Set A\n";
        cout << "b. Add element to Set B\n";
        cout << "c. Remove element from Set A\n";
        cout << "d. Remove element from Set B\n";
        cout << "e. Display Sets\n";
        cout << "f. Return size of Set\n";
        cout << "g. Intersection of Sets\n";
        cout << "h. Check if a Set is a subset of another\n";
        cout << "i. Union of Sets\n";
        cout << "j. Set Difference\n";
        cout << "1. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                AddElement(setA);
                break;
            case 'b':
                AddElement(setB);
                break;
            case 'c':
                RemoveElement(setA);
                break;
            case 'd':
                RemoveElement(setB);
                break;
            case 'e':
                cout << "Set A: ";
                setA.Display();
                cout << "Set B: ";
                setB.Display();
                break;
            case 'f':
                cout << "Size of Set A: " << setA.Size() << endl;
                cout << "Size of Set B: " << setB.Size() << endl;
                break;
            case 'g':
                cout << "Intersection of Set A and Set B: ";
                Set::Intersection(setA, setB).Display();
                break;
            case 'h':
                if (setA.IsSubset(setB)) {
                    cout << "Set A is a subset of Set B." << endl;
                } else {
                    cout << "Set A is not a subset of Set B." << endl;
                }
                if (setB.IsSubset(setA)) {
                    cout << "Set B is a subset of Set A." << endl;
                } else {
                    cout << "Set B is not a subset of Set A." << endl;
                }
                break;
            case 'i':
                cout << "Union of Set A and Set B: ";
                Set::Union(setA, setB).Display();
                break;
            case 'j':
                cout << "Set A - Set B: ";
                Set::Difference(setA, setB).Display();
                cout << "Set B - Set A: ";
                Set::Difference(setB, setA).Display();
                break;
                
            case '1':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '1');

    return 0;
}


This code implements various operations on sets such as adding elements, removing elements, checking membership, finding the size, computing the union, intersection, difference, and checking for subsets.

Here's a breakdown of the functions:

create_set(): This function creates a set by repeatedly asking the user to enter numbers until they choose not to continue.
Add_Element(A, num): Adds an element num to set A at the specified position.
Remove_Element(A, num): Removes all occurrences of num from set A.
Union_Function(setA, setB): Computes the union of two sets setA and setB.
Intersection_Function(setA, setB): Computes the intersection of two sets setA and setB.
Difference_Function(setA, setB): Computes the set difference (setA - setB) between two sets.
Contains_Element(A, num): Checks if num is present in set A.
Size_of_Set(A): Returns the size of set A.
Subset_Function(A, B): Checks if set B is a subset of set A.
The driver code interacts with the user through a menu-based interface, allowing them to perform the desired operations on the sets A and B until they choose to exit.