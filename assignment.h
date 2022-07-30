#pragma once

#include <iostream>
#include <cstring>
#include <cctype>

#define MAX_CHAR 30
class assignment
{
	public:
		assignment();
		assignment(const char name[], int grade, float weight,
				   const char gnum[]);
		void getName(char name[]) const;
		int getGrade() const;
		float getWeight() const;
		void getGnum(char gnum[]) const;.
		void setName(const char name[]);.
		void setGrade(int grade);.
		void setWeight(float gpa);
		void setGnum(const char gnum[]);.
	private:
		char    name[MAX_CHAR + 1];
		int     grade;
		float   weight;
		char    gnum[MAX_CHAR + 1];
};
