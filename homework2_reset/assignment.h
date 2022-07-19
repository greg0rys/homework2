#pragma once

#include <iostream>
#include <cctype>
#include <fstream>
#include <cstring>

#define MAX_CHAR 30
class Assignment {
public:
    Assignment();
    void GetName(char * name) const;
    void SetName(const char name[]);
    int GetGrade() const;
    void SetGrade(int grade);
    float GetWeight() const;
    void SetWeight(float weight);
    void GetGnum(char * gnum) const;
    void SetGnum(const char gnum[]);

private:
    char name[MAX_CHAR + 1];
    int  grade;
    float weight;
    char gnum[MAX_CHAR + 1];

};