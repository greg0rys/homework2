#include "assignment.h"

Assignment::Assignment() {
    memset(name, 0, 1);
    grade = 0;
    weight = 0.00;
    memset(gnum, 0 , 1);

}

void Assignment::GetName(char * name) const {
    strcpy(name, this->name);
}

void Assignment::SetName(const char name[]) {
    strcpy(this->name, name);
}

int Assignment::GetGrade() const {
    return this->grade;
}

void Assignment::SetGrade(int grade) {
    this->grade = grade;
}

float Assignment::GetWeight() const {
    return this->weight;
}

void Assignment::SetWeight(float weight) {
    this->weight = weight;
}

void Assignment::GetGnum(char * gnum) const {
    strcpy(gnum, this->gnum);
}

void Assignment::SetGnum(const char gnum[]) {
    strcpy(this->gnum, gnum);
}