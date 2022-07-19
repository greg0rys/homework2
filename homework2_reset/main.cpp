
#include "student.h"

int main() {

    cout << "Welcome" << endl;
    char name[MAX_CHARS + 1] = {0};
    char setName[MAX_CHARS + 1] = {0};
    Student greg;
    strcpy(name, "Greg");
    greg.SetName(name);
    cout << "Enter a name: ";
    cin.getline(setName, MAX_CHARS, '\n');
    greg.SetName(setName);
    greg.GetName(setName);

    cout << setName;
    return 0;
}

void welcome() {
    cout <<"hello again" << endl;
}

char menu() {
    char n = 'n';
    return n;
}