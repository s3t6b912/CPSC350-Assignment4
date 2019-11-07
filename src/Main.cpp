/* Main.cpp
  The main function which handles all of the logic of the simulation and calculates the metrics
  @author Sebastian Brumm
  @author brumm@chapman.edu
  @author Id:2319132
*/
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "GenQueue.h"
#include "Student.h"
#include "Window.h"

using namespace std;

int main(int argc, char *argv[]){
  //these are the variables needed to computes the metrics and run the simulation
  GenQueue<Student*> queue;
  ifstream input(argv[1]);
  int numStudents = 0;
  int numWindows = 0;
  int totalWait = 0;
  int totalIdle = 0;
  float meanWait = 0;
  float meanIdle = 0;
  int medianWait = 0;
  int longWait = 0;
  int longIdle = 0;
  int numWinIdle = 0;
  int numStudWait = 0;
  int time = 0;
  string line = "";
  GenQueue<int> waitTimes;

  //creates an array of window pointers with the number of windows specified in the input file
  getline(input,line);
  numWindows = stoi(line);
  Window** windows = new Window*[numWindows];
  for(int i = 0; i<numWindows; i++){
    Window* temp = new Window();
    windows[i] = temp;
  }

  while(getline(input,line)){
    time++;

    //adds the number of students and the time they will take to the queue in order that the file lists them
    getline(input,line);
    numStudents = numStudents + stoi(line);
    int tempStudents = stoi(line);
    Student *stud;

    for(int i = 1; i<=tempStudents; i++){
      getline(input,line);
      stud = new Student(stoi(line));
      queue.insert(stud);
    }

    //initially sets the first students to a window and leaves the rest in the queue if there are excess
    for(int i = 0; i<numWindows; i++){
      if(!queue.isEmpty()){
        windows[i]->setStudent(queue.remove());
      }else{
        break;
      }
    }

    //there is a queue that holds each of the students wait times and the below code inserts zeros depending on how many students start at a window
    int currWait = 0;
    bool y = false;
    if(tempStudents<numWindows){
      for(int i = 1; i<=tempStudents; i++){
        waitTimes.insert(0);
      }
    }else{
      for(int i = 1; i<=numWindows; i++){
        waitTimes.insert(0);
      }
    }

    //this block is the main section of the simulation where it goes through the queue of students and calculates their wait times
    while(!queue.isEmpty()){
      y = true;
      for(int i = 0; i<numWindows; i++){
        if(windows[i]->getStudent()->getTimeTaken() == 0){
          if(!queue.isEmpty()){
            windows[i]->setStudent(queue.remove());
            windows[i]->getStudent()->decrementTime();
            totalWait = totalWait + currWait;
            waitTimes.insert(currWait);
            if(currWait>=10){
              numStudWait++;
            }
          }else{
            windows[i]->setStudent(NULL);
          }
        }else{
          windows[i]->getStudent()->decrementTime();
        }
      }
      currWait++;
    }
    if(longWait<currWait-1){
      longWait = currWait-1;
    }

    //x represents a temporary variable to calculate window idle times
    int x = 0;
    for(int i = 0; i<numWindows; i++){
      if(!windows[i]->isIdle()){
        if(x<windows[i]->getStudent()->getTimeTaken()){
          x = windows[i]->getStudent()->getTimeTaken();
        }
      }
    }

    //this block of code calculates the windows idle times, and yes I know it is a bit of a mess
    for(int i = 0; i<numWindows; i++){
      if(!windows[i]->isIdle()){
        windows[i]->setTotalIdle(windows[i]->getTotalIdle() + (x-windows[i]->getStudent()->getTimeTaken()));
        windows[i]->setCurrIdle(x-windows[i]->getStudent()->getTimeTaken());
      }else if(y){
        windows[i]->setTotalIdle(windows[i]->getTotalIdle() + x + 1);
        windows[i]->setCurrIdle(x + 1);
      }else{
        windows[i]->setTotalIdle(windows[i]->getTotalIdle() + x);
        windows[i]->setCurrIdle(x);
      }
    }

    //finds the longest idle time of a window at the current time
    for(int i = 0; i<numWindows; i++){
      if(longIdle < windows[i]->getCurrIdle()){
        longIdle = windows[i]->getCurrIdle();
      }
    }
  }

  meanWait = (totalWait*1.0)/numStudents; //calculates mean wait time
  //calculates the number of windows idle for 5 or more minutes at some point
  for(int i = 0; i<numWindows; i++){
    totalIdle = totalIdle + windows[i]->getTotalIdle();
    if(5 <= windows[i]->getTotalIdle()){
      numWinIdle++;
    }
  }

  meanIdle = totalIdle/(numWindows*time*1.0); //calculates mean idle time

  //this block puts the queue of student wait times into an array then sorts it to find the median wait time
  int array[numStudents];
  for(int i = 0; i<numStudents; i++){
    array[i] = waitTimes.remove();
  }
  sort(array,array+numStudents);
  if(numStudents%2 == 0){
    medianWait = (array[numStudents/2] + array[(numStudents/2) + 1])/2;
  }else{
    medianWait = array[(numStudents/2) + 1];
  }

  //prints all of the metrics
  cout << "The mean student wait time is: " << meanWait << endl;
  cout << "The median student wait time is: " << medianWait << endl;
  cout << "The longest student wait time at a point in time is: " << longWait << endl;
  cout << "The number of students waiting over 10 minutes at a point in time is: " << numStudWait << endl;
  cout << "The mean window idle time is: " << meanIdle << endl;
  cout << "The longest window idle time at a point in time is: " << longIdle << endl;
  cout << "The number of windows idle over 5 minutes at one point in time is: " << numWinIdle << endl;

  return 0;
}
