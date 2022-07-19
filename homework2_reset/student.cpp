#include "student.h"

Student::Student() {
    memset(name, 0, MAX_CHARS);
    memset(gnum, 0, MAX_CHARS);
    memset(grade, 0, MAX_CHARS);
    memset(submissions, 0, MAX_SUBMISSIONS);
    size = 0;
    capacity = 0;
    numAssignments = 0;
}

void Student::GetName(char * name) const {
    strcpy(name, this->name);
}

void Student::SetName(const char name[]) {
    strcpy(this->name, name);
}

void Student::GetGrade(char * grade) const {
    strcpy(grade, this->grade);
}

void Student::SetGrade(const char grade[]) {
    strcpy(this->grade, grade);
}

void Student::GetGnum(char * gnum) const {
    strcpy(gnum, this->gnum);
}

void Student::SetGnum(const char gnum[]) {
    strcpy(this->gnum, gnum);
}

void Student::SetNumAssignments(int numAssignments) {
    this->numAssignments = numAssignments;
}

int Student::GetNumAssignments() const {
    return this->numAssignments;
}

void Student::load(fstream &file, Student roster[], int &size, int &capacity) {
    char    gnumFile[MAX_CHARS + 1] = {0};
    char    namesFile[MAX_CHARS + 1] = {0};
    char    assignmentsFile[MAX_CHARS + 1] = {0};
    int     numberOfGnums = 0;
    int     numberOfNames = 0;
    int     numberOfAssignments = 0;

    cout << "Please enter the name of a gnum file: ";
    cin.getline(gnumFile, MAX_CHARS, '\n');
    cout << "Please enter the name of a names file: ";
    cin.getline(namesFile, MAX_CHARS, '\n');
    cout << "Please enter the name of an Assignments file: ";
    cin.getline(assignmentsFile, MAX_CHARS, '\n');

    numberOfGnums = ReadInGnums(file, size, capacity, roster, gnumFile);
    numberOfNames = ReadInNames(file, roster, size, namesFile);
    numberOfAssignments = ReadInAssignments(file, roster, size, assignmentsFile);

    cout << numberOfGnums << endl;
    cout << numberOfNames << endl;
    cout << numberOfAssignments << endl;


}

int Student::ReadInGnums(fstream &file, int &size, int &capacity, Student roster[],
                         const char fileName[]) {
    char filePath[MAX_CHARS] = {0};
    char gnum[MAX_CHARS + 1] = {0};
    Student newStudent;
    int counter = 0;
    strcpy(filePath, "./");
    strcat(filePath, fileName);

    file.open(filePath);
    if(!file) {
        cout << "Error opening file: " << fileName << endl;
        return false;
    }

    file.getline(gnum, MAX_CHARS, '\n');
    newStudent.SetGnum(gnum);
    while(!file.eof() && size != capacity) {
        roster[size] = newStudent;
        size++;
        counter++;

        file.getline(gnum, MAX_CHARS, '\n');
        newStudent.SetGnum(gnum);
    }

    file.close();
    return counter;

}

int Student::ReadInNames(fstream &file, Student *roster, int &size, const char *fileName) {
    char filePath[MAX_CHARS] = {0};
    int counter = 0;
    Student newStudent;
    char name[MAX_CHARS + 1];
    char gnum[MAX_CHARS + 1];
    char studentNumber[MAX_CHARS + 1];
    strcpy(filePath, "./");
    strcat(filePath, fileName);

    file.open(filePath);
    if(!file) {
        cout << "Error opening: " << fileName << endl;
        return false;
    }

    file.getline(name, MAX_CHARS, ',');
    while(!file.eof() && counter < size) {
        file.get();
        file.getline(gnum, MAX_CHARS);

        for(auto i = 0; i < size; i++) {
            newStudent = roster[i];
            newStudent.GetGnum(studentNumber);
            if(strstr(studentNumber, gnum) != NULL) {
                newStudent.SetName(name);
                counter++;
            }
        }

        file.getline(name, MAX_CHARS, ',');
    }

    file.close();
    return counter;
}

int Student::ReadInAssignments(fstream &file, Student *roster, int &size, const char *fileName) {
    Assignment assignment;
    Student newStudent;
    char gnum[MAX_CHARS + 1] = {0};
    char name[MAX_CHARS + 1] = {0};
    char studentNumber[MAX_CHARS + 1] = {0};
    int numberOfAssignments = 0;
    int grade = 0;
    int counter = 0;
    float weight = 0.00;
    char filePath[MAX_CHARS] = {0};
    strcpy(filePath, "./");
    strcat(filePath, fileName);

    file.open(filePath);
    if(!file) {
        cout << "Error opening file: " << fileName << endl;
        return false;
    }

    file.getline(gnum, MAX_CHARS, ',');
    assignment.SetGnum(gnum);

    while(!file.eof() ) {
        file.get();
        file.getline(name, MAX_CHARS, ',');
        assignment.SetName(name);
        file >> grade;
        assignment.SetGrade(grade);
        file.ignore(MAX_CHARS, ',');
        file >> weight;
        assignment.SetWeight(weight);
        file.ignore(MAX_CHARS, '\n');

        for(auto i = 0; i < size; i++) {
            newStudent = roster[i];
            newStudent.GetGnum(studentNumber);
            assignment.GetGnum(gnum);
            numberOfAssignments = newStudent.GetNumAssignments();

            if(strstr(studentNumber, gnum) != NULL && numberOfAssignments < 10) {
                newStudent.AddSubmission(newStudent, assignment, numberOfAssignments);
                counter++;
            }

        }

        file.getline(gnum, MAX_CHARS, ',');
    }

    file.close();
    return counter;
}

void Student::display(Student roster[], int size) {
    Student newStudent;

}