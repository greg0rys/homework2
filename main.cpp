#include "main.h"

int main()
{
    fstream file;
    student roster[MAX_STUDENTS];
    student newStudent;
    int size = 0;
    int capacity = MAX_STUDENTS;
    int option = 0;

    welcome();

    while((option = menu()) != 'Q') {
        switch(option) {
            case 'Q':
                break;
            case 'L':
                newStudent.load(file, roster, size, capacity);
                file.close();
                break;
            case 'D':
                newStudent.display(roster, size);
                break;
            case 'G':
                newStudent.gpa(roster,size);
                break;
            case 'P':
                newStudent.pct(roster,size);
                break;
            default:
                cerr << "Invalid menu choice, try again!" << endl;
                menu();
                break;
        }
    }

}

void welcome()
{
    cout << " Welcome to the student roster program ";
    cout.width(2);
    cout << "This program allows you to manage a class of students";
    cout << endl;
    cout << endl;
}

char menu()
{
    char option = 0;
    char userChoice [MAX_CHARS + 1] = {0};

    cout << "Please select a choice: " << endl;
    cout.width(4);
    cout << "Load ";
    cout.width(5);
    cout << "-Load roster data from an input file " << endl;
    cout.width(4);
    cout << "Display ";
    cout.width(5);
    cout << "-Display the current roster data " << endl;
    cout.width(4);
    cout << "GPA ";
    cout.width(5);
    cout << "-Display the average GPA for the roster " << endl;
    cout.width(4);
    cout << "PCT ";
    cout.width(5);
    cout << "-Display pass, fail, and completion percentages " << endl;
    cout.width(4);
    cout << "Quit ";
    cout.width(5);
    cout << "-Quit this program " << endl;

    cin.getline(userChoice, MAX_CHARS, '\n');
    option = toupper(userChoice[0]);
    return option;
}