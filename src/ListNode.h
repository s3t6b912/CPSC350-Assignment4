/* ListNode.h
  Template class for a node in a doubly linked list
  @author Sebastian Brumm
  @author brumm@chapman.edu
  @author Id:2319132
*/
#include <iostream>

template <class T>
class ListNode{
public:
  //variables
  T data;
  ListNode *next;
  ListNode *prev;

  //Constructor/Destructor
  ListNode();
  ListNode(T d);
  ~ListNode();
};

//Default Constructor, will probably never be called
template <class T>
ListNode<T>::ListNode(){

}

//Overloaded constructor, sets the two pointers to null and inserts the data
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL; //null pointer
  prev = NULL;
}

//Destructor, just sets the pointers to null
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}
