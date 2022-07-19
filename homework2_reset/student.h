#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include "assignment.h"

using namespace std;
#define MAX_CHARS 30
#define MAX_SUBMISSIONS 10

class Student {
public:
    Student();

    void GetName(char * name) const;
    void SetName(const char name[]);
    void GetGrade(char * grade) const;
    void SetGrade(const char grade[]);
    void GetGnum(char * gnum) const;
    void SetGnum(const char gnum[]);
    void SetNumAssignments(int numAssignments);
    int GetNumAssignments() const;

    void load(fstream &file, Student roster[], int &size, int &capacity);
    void display(Student roster[], int size);
    void gpa(Student roster[], int size);
    void pct(Student roster[], int size);
    void AddSubmission(Student &student, Assignment &assignment, int numOfAssignments);

private:
    char name[MAX_CHARS + 1];
    char gnum[MAX_CHARS + 1];
    char grade[MAX_CHARS + 1];
    int  size;
    int  capacity;
    int  numAssignments;
    Assignment submissions[MAX_SUBMISSIONS];

    // private helpers
    int ReadInGnums(fstream &file, int &size, int &capacity,
                    Student roster[], const char fileName[]);
    int  ReadInNames(fstream &file, Student roster[], int &size, const char fileName[]);
    int ReadInAssignments(fstream &file, Student roster[], int &size, const char fileName[]);
};