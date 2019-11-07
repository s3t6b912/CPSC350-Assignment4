/* Student.h
  A basic class just containing some variables and methods to change them, represents a student in this assignment
  @author Sebastian Brumm
  @author brumm@chapman.edu
  @author Id:2319132
*/
#include <iostream>

using namespace std;

class Student{
public:
  //variables
  int waitTime;
  int timeTaken;

  //Constructors
  Student();
  Student(int d);
  ~Student();

  //core func
  int getTimeTaken();
  int getWaitTime();
  void setWait(int d);
  void decrementTime();
};

//Default constructor, sets both variables to 0
Student::Student(){
  waitTime = 0;
  timeTaken = 0;
}

//Overloaded constructor, takes input representing the wait time
Student::Student(int d){
  waitTime = 0;
  timeTaken = d;
}

//destructor, empty since the only variables are primitives
Student::~Student(){

}

//returns timeTaken variable
int Student::getTimeTaken(){
  return timeTaken;
}

//returns the students waiting time
int Student::getWaitTime(){
  return waitTime;
}

//takes input to set the wait time
void Student::setWait(int d){
  waitTime = d;
}

//decrements the timeTaken variable, used in the main function to represent a minute has passed while the student is at a window
void Student::decrementTime(){
  timeTaken--;
}
