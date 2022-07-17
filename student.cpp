#include "student.h"

student::student() {
		memset(name, 0, 1);
		memset(gnum, 0, 1);
		memset(grade, 0, 1);
		memset(submissions, 0, 1);
		size = 0;
		capacity = 0;
}

student::student(const char name[], const char gnum[], const char grade[],
					const int size, const int capacity) {
		strcpy(this->name, name);
		strcpy(this->gnum, gnum);
		strcpy(this->grade, grade);
		this->size = size;
		this->capacity = capacity;
}

// load in files with data about students
void student::load(fstream &file, student roster[], int &size, int &capactiy) {
}

// display information about all of our students
void student::display(student roster[], int size) {
		for(auto i = 0; i < size; i++) {
				cout.width(5);
				cout << name;
				cout.width(5);
				cout << gnum;
				cout.width(5);
				cout << grade << endl;
		}
}
// get the average gpa for the class roster
void student::gpa(student roster[], int size){
}

// get the pass fail and completion percentages for the roster
void student::pct(student roster[], int size){
}

// get the current students name
void student::getName(char name[]) const {
	strcpy(name, this->name);
}

// get the current students Gnum
void student::getGnum(char gnum[]) const {
	strcpy(gnum, this->gnum);	
}

// get the current students grade
void student::getGrade(char grade[]) const {
	strcpy(grade, this->grade);
}

//set this current students name
void student::setName(const char name[]) {
	strcpy(this->name, name);
}

// set this current students gnum
void student::setGnum(const char gnum[]) {
	strcpy(this->gnum, gnum);
}

// set this current students grade 
void student::setGrade(const char grade[]) {
	strcpy(this->grade, grade);
}

//add a new assignment to this students submissions
void student::addSubmission(student &student, assignment &submission, 
				            int &size, int &capactiy) {
	assignment assignment = submission;
	
   if( size != capactiy) {
	  this->submissions[size] = assignment;
	  size++;
	}	   

}
