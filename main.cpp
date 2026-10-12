#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;
// Defining struct to store student info
struct Student {
  char firstname[80];
  char lastname[80];
  int id;
  float gpa;
};

void addStudent(vector<Student*> &v);
void removeStudent(vector<Student*> &v);

// Main code
int main () {
  bool end = false;
  vector<Student*> v;
  // Continuing loop until they say "QUIT"
  while (end == false) {
    char command[80];
    cout << "Please enter a command: ";
    cin >> command;
    // Conditons for different commands
    if (strcmp(command, "ADD") == 0) {
      addStudent(v);
    }
    else if (strcmp(command, "PRINT") == 0) {
      cout << "Students: " << endl;
      cout << endl;
      // Looping through vector to print all values
      for (vector<Student*>::iterator it = v.begin(); it != v.end(); it ++) {
	cout << (*it)->firstname <<  " " << (*it)->lastname << ", " << (*it)->id << ", " << fixed << setprecision(2) << (*it)->gpa << endl;
      }
    }
    else if (strcmp(command, "DELETE") == 0){
      removeStudent(v);
    }
    else if (strcmp(command, "QUIT") == 0) {
      end = true;
    }
    else {
      cout << "Command is not valid. Try again." << endl;
    }
  }
}

void addStudent(vector<Student*> &v) {
  // Making copies of struct values
  char firstname_copy[80];
  char lastname_copy[80];
  int id_copy;
  float gpa_copy;
  
  Student *x = new Student();

  // Prompting user
  cout << "What is your first name? ";
  cin >> firstname_copy;
  cout << "What is your last name? ";
  cin >> lastname_copy;
  cout << "What is your id? ";
  cin >> id_copy;
  cout << "What is your gpa? ";
  cin >> gpa_copy;

  // Assigning values of copies into actual struct values
  strcpy(x->firstname, firstname_copy);
  strcpy(x->lastname, lastname_copy);
  x->id = id_copy;
  x->gpa = gpa_copy;

  // Adding the struct to vector
  v.push_back(x);
  
}

void removeStudent(vector<Student*> &v) {
  int id_copy;
  cout << "What is the id of the student you want to delete? ";
  cin >> id_copy;
  // Looping through the vector to see if the given id matches an id in the vector
  for (vector<Student*>::iterator it = v.begin(); it != v.end(); it ++) {
    if ((*it)->id == id_copy) {
      delete (*it);
      v.erase(it);
      cout << "Deleted!" << endl;
      return;
    }
  }

  cout << "We didn't find that id in our system." << endl;
}
