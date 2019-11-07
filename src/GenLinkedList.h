/* GenLinkedList.h
  Template class for a doubly linked list using the ListNode class
  @author Sebastian Brumm
  @author brumm@chapman.edu
  @author Id:2319132
*/
#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class GenLinkedList{
private:
  //variables
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;

public:
  //Constructors
  GenLinkedList();
  ~GenLinkedList();

  //core
  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  ListNode<T>* remove(T d);
  int find(T d);

  //aux
  bool isEmpty();
  void printList();
  T getFront();
  T getBack();
  unsigned int getSize();
};

//Default and only constructor, initializes size to 0 and the front and back pointers to null
template <class T>
GenLinkedList<T>::GenLinkedList(){
  size = 0;
  front = NULL; //null pointer
  back = NULL;
}

//Destructor, iterates through the list deleting each ListNode pointer
template <class T>
GenLinkedList<T>::~GenLinkedList(){
  ListNode<T>* curr = front;
  ListNode<T>* next = curr;
  while(curr != NULL){
    next = curr->next;
    delete curr;
    curr = next;
  }
  curr = NULL;
}

//Returns the list size
template <class T>
unsigned int GenLinkedList<T>::getSize(){
  return size;
}

//prints the list to the console
template <class T>
void GenLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(curr !=NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

//inserts a ListNode to the front of the list and updates the size and pointers of the list
template <class T>
void GenLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(size == 0){
    back = node;
  }else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

//inserts a ListNode to the back of the list and updates the size and pointers of the list
template <class T>
void GenLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(size == 0){
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

//removes the front ListNode from the list and updates the size and pointers while returning the value
template <class T>
T GenLinkedList<T>::removeFront(){
  if(size==0){
    cout << "Error: Cannot return a value, list empty." << endl;
    exit(0);
  }
  ListNode<T> *ft = front;
  if(size == 1){ //Only one element
    back = NULL;
  }else{ //More than one element
    front->next->prev = NULL;
  }
  front = front->next;
  T temp = ft->data;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}

//removes the back ListNode from the list and updates the size and pointers while returning the value
template <class T>
T GenLinkedList<T>::removeBack(){
  if(size==0){
    cout << "Error: Cannot return a value, list empty." << endl;
    exit(0);
  }
  ListNode<T> *bt = back;
  if(size == 1){ //Only one element
    front = NULL;
  }else{ //More than one element
    back->prev->next = NULL;
  }
  back = back->prev;
  T temp = bt->data;
  bt->prev = NULL;
  delete bt;
  size--;

  return temp;
}

//will return the ListNode pointer of the value inserted if it exists in the list and will return null otherwise
template <class T>
ListNode<T>* GenLinkedList<T>::remove(T d){
  ListNode<T> *curr = front;

  while(curr->data != d){
    curr = curr->next;
    if(curr == NULL){ //The value is not found
      return NULL;
    }
  }
  //Found it
  //Have to check if the node is in the front or back first
  if(curr == front){
    front = curr->next;
  }else{
    curr->prev->next = curr->next;
  }
  if(curr == back){
    back = curr->prev;
  }else{
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  size--;
  return curr;
}

//returns the position of the value in the list
template <class T>
int GenLinkedList<T>::find(T d){
  int idx = 0;
  ListNode<T> *curr = front;

  while(curr != NULL){
    if(curr->data == d){
      break;
    }
    idx++;
    curr = curr->next;
  }
  if(curr == NULL){
    idx = -1;
  }
  return idx;
}

//return the front value of the list without removing it
template <class T>
T GenLinkedList<T>::getFront(){
  if(size==0){
    cout << "Error: Cannot return a value, list empty." << endl;
    exit(0);
  }
  T temp = front->data;
  return temp;
}

//return the back value of the list without removing it
template <class T>
T GenLinkedList<T>::getBack(){
  if(size==0){
    cout << "Error: Cannot return a value, list empty." << endl;
    exit(0);
  }
  T temp = back->data;
  return temp;
}
