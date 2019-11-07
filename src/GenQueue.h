/* GenQueue.h
  Template class for a queue using a doubly linked list
  @author Sebastian Brumm
  @author brumm@chapman.edu
  @author Id:2319132
*/
#include <iostream>
#include "GenLinkedList.h"

using namespace std;

template <class T>
class GenQueue{
public:
  //constructors
  GenQueue();
  ~GenQueue();

  //core
  void insert(T d);
  T remove();

  //aux
  T peek();
  bool isEmpty();
  unsigned int getSize();

  //variables
  unsigned int size;

  GenLinkedList<T> myQueue;
};

//default and only constructor, just initializes the linked list and sets size to 0
template <class T>
GenQueue<T>::GenQueue(){
  GenLinkedList<T> myQueue;
  size = 0;
}

//Destructor, is empty because the only thing to delete is the list and that has a destructor
template <class T>
GenQueue<T>::~GenQueue(){

}

//inserts the argument into the queue by adding it to the back of the linked list and updates size
template <class T>
void GenQueue<T>::insert(T d){
  myQueue.insertBack(d);
  size = myQueue.getSize();
}

//removes and returns the item at the front of the linked list and updates size
template <class T>
T GenQueue<T>::remove(){
  T c = myQueue.removeFront();
  size = myQueue.getSize();
  return c;
}

//calls the getFront() function from the linked list
template <class T>
T GenQueue<T>::peek(){
  return myQueue.getFront();
}

//returns true if the size is 0
template <class T>
bool GenQueue<T>::isEmpty(){
  return (size == 0);
}

//returns the size of the queue
template <class T>
unsigned int GenQueue<T>::getSize(){
  return size;
}
