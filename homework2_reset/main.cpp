
#include "main.h"

int main() {
    fstream file;
    Student roster[MAX_STUDENTS];
    Student newStudent;
    int size = 0;
    int capacity = MAX_STUDENTS;
    char option = 'a';

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

void welcome() {
    cout << endl << endl;
    cout << "Welcome to the student roster management program " << endl;
    cout << "This program will allow you to manage a class of students. " << endl;
    cout << endl << endl;
}

char menu() {
    char userChoice[MAX_CHARS + 1] = {0};
    char option = 'a';
    cout << "Please enter a choice from the menu below: " << endl;
    cout << "Load: " << endl;
    cout << "\tLoad roster data from file input " << endl;
    cout << "Display: " << endl;
    cout << "\tDisplay the current roster data " << endl;
    cout << "GPA: " << endl;
    cout << "\tDisplay the average GPA for the roster " << endl;
    cout << "PCT: " << endl;
    cout << "\tDisplay pass, fail, and completion percentages " << endl;
    cout << "Quit: " << endl;
    cout << "\tExit this program " <<endl;
    cout << "> ";
    cin.getline(userChoice, MAX_CHARS, '\n');
    option = toupper(userChoice[0]);

    return option;

}

//# need to implement file reads