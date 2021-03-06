#include "student.h"

student::student() {
		memset(name, 0, 1);
		memset(gnum, 0, 1);
		memset(grade, 0, 1);
		memset(submissions, 0, 1);
		size = 0;
		capacity = MAX_SUBMISSIONS;
		numAssignments = 0;
}

//student::student(const char name[], const char gnum[], const char grade[],
//					const int size, const int capacity) {
//		strcpy(this->name, name);
//		strcpy(this->gnum, gnum);
//		strcpy(this->grade, grade);
//		this->size = size;
//		this->capacity = capacity;
//        this->numAssignments = 0;
//}

// load in files with data about students
void student::load(fstream &file, student roster[], int &size, int &capacity) {
	student newStudent;
	char gnum[MAX_CHARS + 1];
	char gnumFile[MAX_CHARS + 1];
	char namesFile[MAX_CHARS + 1];
	char assignmentsFile[MAX_CHARS + 1];
	int  numberOfGnums = 0;
	int  numberOfStudentsAdded = 0;
	int  numberOfAssignmentsLoaded = 0;
	cout << "Enter the name of the gnums file up to 30 characters: ";
	cin.getline(gnumFile, MAX_CHARS);
	cout << "Enter the name of the names file up to 30 characters: ";
    cin.getline(namesFile, MAX_CHARS);
	cout << "Enter the name of the assignments file up to 30 characters: ";
	cin.getline(assignmentsFile, MAX_CHARS);	

	numberOfGnums = readInGnums(file,size,capacity,roster, gnumFile);
	numberOfStudentsAdded = readInNames(file,roster, size, namesFile);
	numberOfAssignmentsLoaded = readInAssignments(file,roster, size,assignmentsFile);

	cout << "[" << numberOfGnums << " G-Numbers loaded ]" << endl;
	cout << "[" << numberOfStudentsAdded << " names added to the roster ]"
			<< endl;
	cout << "[" << numberOfAssignmentsLoaded << " assignments added ]" << endl;

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

int student::readInGnums(fstream &file, int &size, int &capacity,
				student roster[], const char fileName[]) {
	char filePath[MAX_CHARS + 1];
	strcpy(filePath, "./");
	student newStudent;
	char gnumber[MAX_CHARS + 1];	
	int counter = 1;
	strcat(filePath, fileName);
	file.open(filePath);

	if(!file) {
			cout << "Error opening " << fileName << endl;
			return false;
	} 

	file.getline(gnumber, MAX_CHARS);
	newStudent.setGnum(gnumber);

	while(!file.eof() && size != capacity) {
			roster[size] = newStudent;
			size++;
			counter++;
			file.getline(gnumber, MAX_CHARS);
			newStudent.setGnum(gnumber);
	}
	return counter;


}

int student::readInNames(fstream &file, student roster[], 
						const char fName[], int &capacity, int &size) {
	char  name[MAX_CHARS + 1];
	char  gnum[MAX_CHARS + 1];
	char  filePath[MAX_CHARS + 1];
	strcpy(filePath, "./");
	strcat(filePath, fName);
	int counter = 0;
	student newStudent;

	file.open(filePath);
	if(!file) {
			cout << "Error opening: " << fName << endl;
			return false;
	}

	file.getline(name, MAX_CHARS, ',');
	while(!file.eof() && counter != capacity) {
		file.get();
		file.getline(gnum, MAX_CHARS);
		for(auto i = 0; i < size; i++) {
				newStudent = roster[i];
				if(strcmp(newStudent.getGnum(), gnum) == 0) {
						newStudent.setName(name);
						counter++;
						break;
				}
				else {
						continue;
				}
		}

		file.getline(name, MAX_CHARS);
	}

	return counter;

}

int student::readInAssignments(fstream &file, student roster[], 
								const char fileName[]) {
 	char filePath [MAX_CHARS + 1];
	char name[MAX_CHARS + 1];
	char gnum[MAX_CHARS + 1];
	int  grade = 0;
	float weight = 0;
	strcat(filePath, fileName);
	int counter = 0;
	assignment assignment;
	student newStudent;
	file.open(filePath);

	if(!file) {
			cout << "Error opening file: " << fileName << endl;
			return false;
	}

	file.getline(name, MAX_CHARS, ',');
	assignment.setName(name);
	counter++;

	while(!file.eof()) {
			file.get();
			file >> grade;
			file.get();
			file >> weight;
			file.get();
			file.getline(gnum, MAX_CHARS);
			assignment.setGnum(gnum);
			assignment.setGrade(grade);
			assignment.setWeight(weight);
			for(auto i = 0; i < size; i++) {
				newStudent = roster[i];

				if(strcmp(newStudent.gnum, assignment.getGnum) == 0
					&& newStudent.getNumberOfAssignments() < MAX_SUBMISSIONS) {
						newStudent.addSubmission[newStudent.getNumberOfAssignments()] = assignment;
						newStudent.setNumberOfAssignments(1);
					counter++;	
				}
			}
			file.getline(name,MAX_CHARS, ',');
	}

	return counter();
}

void student::setNumberOfAssignments(int num) {
		this->numAssignments += num;
}

int student::getNumberOfAssignments() {
		return this->numAssignments;
}

//add a new assignment to this students submissions
void student::addSubmission(fstream &inFile, student roster[]) {
	int counter = 0;
	char name[MAX_CHARS + 1] ={0}
	char gnum[MAX_CHARS + 1] = {0};
	assignment assignment;
	file.getline(name, MAX_CHARS);

	while(!file.eof() && counter != size){
	    file.getline(gnum, MAX_CHARS);
		for(auto i = 0; i < size; i++) {
				student newStudent = roster[0];
				if(strcmp(newStudent.getGnum('f'), gnum) == 0) {
						newStudent.setName(name);
						break;
				}
				else {
						continue;
				}
		}
		file.getline(name, MAX_CHARS);
		counter++;
	}

		
   if( size != capactiy) {
	  this->submissions[size] = assignment;
	  size++;
	}	   

}
