/* WriteaStudent class and use it in your program. Store the data of 10 students and display
 the sorted data according to their roll numbers, dates of birth, and total marks. */

#include <iostream>
using namespace std;

class Student {
    int roll,total_marks;
    string dob;
    int sorted [2];
    
    public:
    void accept();
    void display();
    int getRoll();
};

void Student :: accept() {
    cout<<"Enter the roll No.";
    cin>>roll;
    cout<<"Enter the dob in dd/mm/yy format:";
    cin>>dob;
    cout<<"Enter the marks acquired";
    cin>>total_marks;
}

int Student :: getRoll() {
    return roll;
}

void Student :: display() {
    cout<<"The roll No. :"<< roll << "\t";
    cout<<"DoB :"<< dob << "\t";
    cout<<"Marks acquired :"<< total_marks<<endl;
}

int main() {
    int n;
    cout<<"Enter the No. of students:";
    cin>>n;

    Student s[n];

    for(int i=0; i<n; i++){
        s[i].accept();
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s[i].getRoll() > s[j].getRoll()){
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        s[i].display();
    }
}