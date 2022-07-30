#include "student.h"

// default constructor init a student object to empty fields.
Student::Student() {
    memset(name, 0, MAX_CHARS);
    memset(gnum, 0, MAX_CHARS);
    memset(grade, 0, MAX_CHARS);
    size = 0;
    capacity = 0;
    numAssignments = 0;
}

/**
 * Get the name field of this student object
 * @param name a char pointer in which we can copy this
 * objs current name into.
 */
void Student::GetName(char * name) const {
    strcpy(name, this->name);
}

/**
 * Set the name of this current student object
 * @param name the name we wish to change too.
 */
void Student::SetName(const char name[]) {
    strcpy(this->name, name);
}

/**
 * Get the grade of this student object.
 * @param grade
 */
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
    char gnum[MAX_CHARS];
    Student newStudent;
    int counter = 0;
    strcpy(filePath, "./");
    strcat(filePath, fileName);

    file.open(filePath);
    if(!file) {
        cout << "Error opening file: " << fileName << endl;
        return false;
    }

    file.getline(gnum, MAX_CHARS);
    newStudent.SetGnum(gnum);
    while(!file.eof() && size != capacity) {
        roster[size] = newStudent;
        size++;
        counter++;

        file.getline(gnum, MAX_CHARS);
        newStudent.SetGnum(gnum);
    }

    file.close();
    return counter;

}

int Student::ReadInNames(fstream &file, Student roster[], int &size, const char *fileName) {
    char filePath[MAX_CHARS] = {0};
    int counter = 0;
    Student newStudent;
    char name[MAX_CHARS + 1] ={0};
    char gnum[MAX_CHARS + 1] ={0};
    char studentNumber[MAX_CHARS];
    strcpy(filePath, "./");
    strcat(filePath, fileName);

    file.open(filePath);
    if(!file) {
        cout << "Error opening: " << fileName << endl;
        cout << endl << endl;
        return false;
    }

    file.getline(name, MAX_CHARS, ',');
    while(!file.eof() && counter < size) {
        file.getline(gnum, MAX_CHARS);

        for(int i = 0; i < size; i++) {
            roster[i].GetGnum(studentNumber);
            int result = strcmp(gnum, studentNumber);
            if(strcmp(gnum, studentNumber) == 0) {
                roster[i].SetName(name);
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
        file.getline(name, MAX_CHARS, ',');
        assignment.SetName(name);
        file >> grade;
        assignment.SetGrade(grade);
        file.ignore(MAX_CHARS, ',');
        file >> weight;
        assignment.SetWeight(weight);
        file.ignore(MAX_CHARS, '\n');

        for(int i = 0; i < size; i++) {
            roster[i].GetGnum(studentNumber);
            assignment.GetGnum(gnum);
            numberOfAssignments = roster[i].GetNumAssignments();

            if(strcmp(gnum, studentNumber) == 0) {
                roster[i].AddSubmission(roster[i], assignment, numberOfAssignments);
                numberOfAssignments+=1;
                roster[i].SetNumAssignments(numberOfAssignments);
                counter += roster[i].GetNumAssignments();
            }
        }
        file.getline(gnum, MAX_CHARS, ',');
        assignment.SetGnum(gnum);
    }

    file.close();
    return counter;
}


void Student::AddSubmission(Student &student, Assignment &assignment,
                            int numOfAssignments){
    char name[MAX_CHARS + 1];
    int grade = 0;
    float weight = 0.00;
    student.GetName(name);

    if(numOfAssignments < MAX_SUBMISSIONS) {
        student.submissions[numOfAssignments] = assignment;
    }
    else {
        cout << name << " already has " << MAX_SUBMISSIONS << endl;
    }

}
void Student::display(Student roster[], int size) {
    char name[MAX_CHARS + 1] = {0};
    char gnum[MAX_CHARS + 1] = {0};
    int num = 0;
    Assignment list[10];
    int assignmentGrade = 0;
    float assignmentWeight = 0;
    char grade[MAX_CHARS] = {0};

    for(int i = 0; i < size; i++) {
        roster[i].GetWeightedGrade(roster[i]);
        roster[i].GetName(name);
        roster[i].GetGnum(gnum);
        roster[i].GetGrade(grade);
        num = roster[i].GetNumAssignments();
        roster[i].GetSubmissions(list);

        cout << gnum << " " <<   name << " Final Grade: " << grade << endl;
        for(int i = 0; i < num; i++){
            cout.width(5);
            assignmentGrade = list[i].GetGrade();
            assignmentWeight = list[i].GetWeight() * 100;
            list[i].GetName(name);
            cout << assignmentGrade << " " <<  "(" << assignmentWeight << "%) " << name << endl;
        }
    }

}

void Student::gpa(Student roster[], int size) {
    double averageGpa = 0;
    char studentGrade[MAX_CHARS];
    Student tempStudent;
    for(int i = 0; i < size; i++) {
        tempStudent = roster[i];
        tempStudent.GetWeightedGrade(tempStudent);
        tempStudent.GetGrade(studentGrade);
        if(strcmp(studentGrade, "A") == 0) {
            averageGpa += 4;
        }
        else if(strcmp(studentGrade, "B") == 0) {
            averageGpa += 3;
        }
        else if(strcmp(studentGrade, "C") == 0) {
            averageGpa += 2;
        }
        else if(strcmp(studentGrade, "D") == 0) {
            averageGpa += 1;
        }
        else {
            continue; // current student failed go to next.
        }
    }
    averageGpa /= size;
    cout.precision(4);
    cout << endl;
    cout << "Average GPA for a class of " << size
         << " students is: " << averageGpa << endl;
    cout << endl << endl;
}

void Student::GetSubmissions(Assignment * array) {
    for(int i=0; i < MAX_SUBMISSIONS; i++) {
        array[i] = this->submissions[i];
    }
}

// change the name of this to calculate student grade.
void Student::GetWeightedGrade(Student &student)  {
    int grade = 0;
    float weight = 0.00;
    double finalGrade = 0.00;
    int num = student.GetNumAssignments();
    Assignment list[num + 1];
    student.GetSubmissions(list);

    for(int i=0; i < num; i++){
        grade = list[i].GetGrade();
        weight = list[i].GetWeight();
        finalGrade += grade * weight;
        if(finalGrade >= 3.4) {
            student.SetGrade("A");
        }
        else if(finalGrade >= 2.8 && finalGrade <= 3.4) {
            student.SetGrade("B");
        }
        else if(finalGrade >= 2.0 && finalGrade <= 2.8) {
            student.SetGrade("C");
        }
        else if(finalGrade >= 1.2 && finalGrade <= 2.0) {
            student.SetGrade("D");
        }
        else {
            student.SetGrade("F");
        }
    }

}

void Student::pct(Student roster[], int size) {
    double totalPassed = 0;
    double totalFailed = 0;
    double totalAudits = 0;
    char studentGrade[MAX_CHARS] = {0};

    for(int i = 0; i < size; i++){
        roster[i].GetWeightedGrade(roster[i]);
        roster[i].GetGrade(studentGrade);
        if(strcmp(studentGrade, "A") == 0 || strcmp(studentGrade,"B") == 0 || strcmp(studentGrade,"C") == 0){
            totalPassed++;
        }
        else if(strcmp(studentGrade, "AUD") == 0) {
            totalAudits++;
        }
        else {
            totalFailed++;
        }
    }
    cout << endl;
    cout << "Total Students: " << size << " (100%)" << endl;
    cout << "Total Completions: " << totalPassed <<
        " (" << (totalPassed / size) * 100 << "%)" << endl;
    cout << "Passing Grades: " << totalPassed <<
         " (" << (totalPassed / size) * 100 << "%)" << endl;
    cout << "Non-Passing Grades: " << totalFailed <<
         " (" << (totalFailed/ size) * 100 << "%)" << endl;
    cout << "AUD Grades: " << totalAudits<<
         " (" << (totalAudits / size) * 100 << "%)" << endl;

}