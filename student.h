#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include "assignment.h"

using namespace std;
#define MAX_CHARS 30
#define MAX_SUBMISSIONS 10

class student 
{
	public:
		student();
		student(const char name[], const char gnum[], const char grade[]);
		void load(fstream &file, student roster[], int &size, int &capcity);
		void display(student roster[], int size);
		void gpa(student roster[], int size);
		void pct(student roster[], int size);
		void getName(char name[]) const;
		void getGnum(char gnum[]) const;
		void getGrade(char grade[]) const;
		void setName(const char name[]);
		void setGnum(const char gnum[]);
		void setGrade(const char grade[]);
		void addSubmission(student &student,assignment &submission, int &size, int &capacity);
	private:
		char    name[MAX_CHARS + 1];
		char    gnum[MAX_CHARS + 1];
		char    grade[MAX_CHARS + 1];
		int     size;
		int     capacity;
		assignment submissions[MAX_SUBMISSIONS];

};
