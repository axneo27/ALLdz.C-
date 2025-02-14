#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
using namespace std;

struct Student {
    string id;
    string name;
};

map<string, Student> students;
multimap<string, int> grades;

void AddStudent() {
    string id, name;
    cout << "Enter id : ";
    cin >> id;

    cout << "Enter name : ";
    cin >> name;

    students[id] = { id, name };
    cout << "Student was added" << endl;
}


void AddMark() {
    string id;
    int mark;
    cout << "Enter id of student : " << endl;
    cin >> id;
    cin.ignore();
    if (students.find(id) == students.end()) {
        cout << "Student not found" << endl;
        return;
    }
    cout << "Enter mark : ";
    cin >> mark;
    grades.insert(make_pair(id, mark));
    cout << "Mark was added" << endl;
}

void ShowMarks() {
    string id;
    cout << "Enter id of student : " << endl;
    cin >> id;
    if (students.find(id) == students.end()) {
        cout << "Student not found" << endl;
        return;
    }
    cout << "Name: " << students[id].name << ", marks: " << endl;
    auto range = grades.equal_range(id);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << endl;
}


void ShowStudents() {
    cout << "___________________\n";
    for (auto st : students)
    {
        cout << "ID : " << st.second.id << " Name : " << st.second.name << endl;
    }
    cout << "___________________\n";
}

void getAvgMarks() {
    string id;
    cout << "Enter id of student : " << endl;
    cin >> id;
    if (students.find(id) == students.end()) {
        cout << "Student not found" << endl;
        return;
    }
    int s = 0;
    int a = 0;
    auto range = grades.equal_range(id);
    for (auto it = range.first; it != range.second; ++it) {
        s+=it->second;
        a++;
    }

    a == 0 ? cout << "No marks\n" : cout << "Average: " << s/a << "\n";
}

void SaveToFile() {
    ofstream fout("students.txt");
    for (const auto& st : students) {
        fout << st.second.id << " " << st.second.name << endl;
    }
    fout.close();

    ofstream gradesout("grades.txt");
    for (const auto& gr : grades) {
        gradesout << gr.first << " " << gr.second << endl;
    }
    gradesout.close();
    cout << "Data was saved successfully" << endl;
}

void mainLoop() {
    int choice;
    while (1) {
        cout << "Enter choice:\n1 - Show\n2 - Add\n3 - Show marks\n4 - Avg marks\n5 - Add mark\n6 - Exit: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ShowStudents();
            break;
        case 2:
            AddStudent();
            break;
        case 3:
            ShowMarks();
            break;      
        case 4:
            getAvgMarks();
            break;
        case 5:
            AddMark();
            break;
        case 6:
            cout << "Goodbye.\n";
            return;  
        default:
            cout << "Wrong command\n";
            break;
        }
    }
}

int main() {

    mainLoop();
}
