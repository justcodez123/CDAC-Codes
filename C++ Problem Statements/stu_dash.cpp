/*
    1. OOP Design
Class Student with:

rollNo, name, marks in 3 subjects

Class Gradebook to manage multiple students

2. Operator Overloading
Overload ++ to increment marks (e.g., bonus marks)

Overload > to compare students based on average marks

3. Exception Handling
Throw exceptions for:

Invalid marks (e.g., >100 or <0)

Duplicate roll numbers

Empty gradebook access

4. File Handling
Save student records to gradebook.txt

Load records at startup

Allow search by roll number and update marks

*/

#include<iostream>
#include<string>
#include<stdexcept>
#include<fstream>
using namespace std;

class Gradebook{
    Student students[100];
    int stud_count = 0;
    int bonus_marks;

    friend class Student;

    public:
    /* Gradebook filling*/
    void addStudent(const Student& s) {
        for(int i = 0; i < stud_count; ++i) {
            if(students[i].rollNo == s.rollNo) 
                throw invalid_argument("Duplicate roll number.");
        }
        if(stud_count >= 100) 
            throw overflow_error("Gradebook is full.");
        students[stud_count++] = s;
    }

    /*Empty Gradebook Access*/
    void displayAllStudents() {
        if(stud_count == 0) {
            throw runtime_error("No students in gradebook.");
        }
        for(int i = 0; i < stud_count; ++i) {
            students[i].display();
        }
    }

    /* File Handling */
    string filename = "gradebook.txt";
    void saveToFile(){
        ofstream file(filename);
        if(!file){
            throw runtime_error("Could not open file for writing.");
       }
        for(int i=0; i<stud_count; ++i){
            file<< students[i].rollNo << " " << students[i].name << endl
               << students[i].marks[0] << " " << students[i].marks[1] 
               << " " << students[i].marks[2] << endl;                
        }
    }

    /* Load from file */
    void loadfile(){
        ifstream file(filename);
        if(!file){
            cout << "No existing gradebook file found. A new one will be created." << endl;
            return;
        }
        while(!file.eof()){
            Student s(0, "", 0, 0, 0);
            file >> s.rollNo >> s.name >> s.marks[0] >> s.marks[1] >> s.marks[2];
            if(file){
                try{
                    addStudent(s);
                }catch(const exception& e){
                    cerr << "Error adding student from file: " << e.what() << endl;
                }
            }
        }
    }

    /* Search and Update */
    void searchAndUpdate(int rollNo){
        for(int i=0; i<stud_count; ++i){
            if(students[i].rollNo == rollNo){
                cout << "Student found: ";
                students[i].display();
                cout << "Enter new marks for 3 subjects: ";
                int m1, m2, m3;
                cin >> m1 >> m2 >> m3;
                if(m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100)
                    throw invalid_argument("Marks must be between 0 and 100.");
                students[i].marks[0] = m1;
                students[i].marks[1] = m2;
                students[i].marks[2] = m3;
                cout << "Marks updated." << endl;
                return;
            }
        }
        throw invalid_argument("Student with given roll number not found.");
    }

};

class Student {
    int rollNo;
    string name;
    int marks[3];

    friend class Gradebook;

    public:
    Student& operator++ (){
        int bonus_marks;
        cout << "Enter bonus marks to add: ";
        cin >> bonus_marks;
        for (int i = 0; i < 3; i++) {
            marks[i] += bonus_marks;
            if (marks[i] > 100) marks[i] = 100;
        }
        return *this;
    }

    bool operator>(const Student& other) {
        double avg1 = (marks[0] + marks[1] + marks[2]) / 3.0;
        double avg2 = (other.marks[0] + other.marks[1] + other.marks[2]) / 3.0;
        return avg1 > avg2;
    }

    Student(int r, string n, int m1, int m2, int m3) {
        if(m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100)
            throw invalid_argument("Marks must be between 0 and 100.");
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name 
             << ", Marks: [" << marks[0] << ", " << marks[1] 
             << ", " << marks[2] << "]" << endl;
    }

};

int main() {
    Gradebook gb;
    gb.loadfile();

    try {
        Student s1(1, "Alice", 85, 90, 95);
        Student s2(2, "Bob", 80, 70, 75);
        gb.addStudent(s1);
        gb.addStudent(s2);

        cout << "All Students:" << endl;
        gb.displayAllStudents();

        if(s1 > s2) {
            cout << s1.name << " has a higher average than " << s2.name << endl;
        } else {
            cout << s2.name << " has a higher average than " << s1.name << endl;
        }

        ++s1; // Add bonus marks to Alice
        cout << "After adding bonus marks to Alice:" << endl;
        gb.displayAllStudents();

        int searchRollNo;
        cout << "Enter roll number to search and update marks: ";
        cin >> searchRollNo;
        gb.searchAndUpdate(searchRollNo);

        cout << "All Students after update:" << endl;
        gb.displayAllStudents();

        gb.saveToFile();
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}