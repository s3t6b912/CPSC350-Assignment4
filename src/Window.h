/* Window.h
  A basic class just containing some variables and methods to change them, represents a student in this assignment
  @author Sebastian Brumm
  @author brumm@chapman.edu
  @author Id:2319132
*/
#include <iostream>

using namespace std;

class Window{
public:
  //variables
  int currIdleTime;
  int totalIdleTime;
  Student *student;

  //Constructors
  Window();
  ~Window();

  //Core func
  void setCurrIdle(int d);
  void setTotalIdle(int d);
  int getCurrIdle();
  int getTotalIdle();
  bool isIdle();
  void setStudent(Student* s);
  Student* getStudent();
};

//default and only constructor, sets all variables to 0
Window::Window(){
  currIdleTime = 0;
  totalIdleTime = 0;
  student = NULL;
}

//destructor, sets student pointer to null
Window::~Window(){
  delete student;
}

//sets the currIdleTime variable representing how long the window has been idle for that time period
void Window::setCurrIdle(int d){
  currIdleTime = d;
}

//sets the totalIdleTime variable representing the total time it has been idle
void Window::setTotalIdle(int d){
  totalIdleTime = d;
}

//returns the currIdleTime variable
int Window::getCurrIdle(){
  return currIdleTime;
}

//returns the totalIdleTime variable
int Window::getTotalIdle(){
  return totalIdleTime;
}

//returns true if there is not a student at the window
bool Window::isIdle(){
  return (student==NULL);
}

//sets the student pointer
void Window::setStudent(Student* s){
  student = s;
}

//returns the student pointer at the window
Student* Window::getStudent(){
  return student;
}
