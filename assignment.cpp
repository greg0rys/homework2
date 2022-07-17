#include "assignment.h"

// default constructor
assignment::assignment() {
		// set everything to 0;
}

// constructor with values
assignment::assignment(const char name[], int grade, float weight,
						const char gnum[]){
		// set up an assignment with values
}

// get the name of this assignment
void assignment::getName(char name[]) const {
		strcpy(name, this->name);
}

// get the grade of this assignment
int assignment::getGrade() const{
		return this->grade;
}

// get the weight of this assignment
float assignment::getWeight() const{
		return this->weight;
}

// get the gnum of the student who this assignment belongs
void assignment::getGnum(char gnum[]) const {
		strcpy(gnum, this->gnum);
}

// set the name of this assignment
void assignment::setName(const char name[]) {
		strcpy(this->name, name);
}

// set the grade for this assignment
void assignment::setGrade(int grade) {
		this->grade = grade;
}

// set the weight for this assignment
void assignment::setWeight(float weight) {
		this->weight = weight;
}

// set the gnum of the student who did this assignment
void assignment::setGnum(const char gnum[]) {
		strcpy(this->gnum, gnum);
}


