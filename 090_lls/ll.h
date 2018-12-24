#ifndef _LL_H_
#define _LL_H_
#include <assert.h>

#include <cstdlib>
#include <exception>
#include <iostream>

//YOUR CODE GOES HERE
class myException : public std::exception
{
  const char * what() const throw() { return "Index exceed list size"; }
};
void testlist();
template<typename T>
class LinkedList
{
 private:
  class Node
  {
   public:
    T data;
    Node * next;
    Node * prev;
    //Node():data(0),next(NULL),prev(NULL){}
    Node(const T & d) : data(d), next(NULL), prev(NULL) {}
    Node(const T & d, Node * n, Node * p) : data(d), next(n), prev(p) {}
  };
  Node * head;
  Node * tail;
  int size;
  Node * remove(const T & data, Node * current, bool & isRemoved) {
    if (current == NULL) {
      return NULL;
    }
    if (data == current->data) {
      Node * ans = current->next;
      delete current;
      isRemoved = true;
      size--;
      if (head == tail) {
        tail = NULL;
      }
      return ans;
    }
    current->next = remove(data, current->next, isRemoved);
    if (current->next != NULL) {
      current->next->prev = current;
    }
    return current;
  }

 public:
  class iterator
  {
   private:
    Node * current;

   public:
    iterator() : current(NULL) {}
    iterator(Node * c) : current(c) {}
    bool operator!=(const iterator & rhs) const { return current != rhs.current; }
    iterator & operator++() {
      current = current->next;
      return *this;
    }
    bool operator==(const iterator & rhs) const { return current == rhs.current; }
    T & operator*() { return current->data; }
  };
  iterator begin() { return iterator(head); }
  iterator end() { return iterator(NULL); }
  LinkedList() : head(NULL), tail(NULL), size(0) {}
  LinkedList(const LinkedList & rhs) : head(NULL), tail(NULL), size(0) {
    Node * cur = rhs.tail;
    while (cur != NULL) {
      addFront(cur->data);
      cur = cur->prev;
    }
  }
  LinkedList & operator=(const LinkedList & rhs) {
    if (this == &rhs) {
      return *this;
    }
    LinkedList temp(rhs);
    std::swap(temp.head, head);
    std::swap(temp.tail, tail);
    std::swap(temp.size, size);
    return *this;
  }
  ~LinkedList() {
    while (head != NULL) {
      Node * temp = head->next;
      delete head;
      head = temp;
    }
  };
  void addFront(const T & item) {
    head = new Node(item, head, NULL);
    if (tail == NULL) {
      tail = head;
    }
    else {
      head->next->prev = head;
    }
    size++;
  }
  void addBack(const T & item) {
    tail = new Node(item, NULL, tail);
    if (head == NULL) {
      head = tail;
    }
    else {
      tail->prev->next = tail;
    }
    size++;
  }
  bool remove(const T & item) {
    bool isRemoved = false;
    head = remove(item, head, isRemoved);
    return isRemoved;
  }
  T & operator[](int index) {
    if (index >= size) {
      throw myException();
    }
    Node * cur = head;
    while (index--) {
      cur = cur->next;
    }
    return cur->data;
  }
  const T & operator[](int index) const {
    if (index >= size) {
      throw myException();
    }
    Node * cur = head;
    while (index--) {
      cur = cur->next;
    }
    return cur->data;
  }
  int find(const T & item) {
    int ans = -1;
    int count = 0;
    Node * current = head;
    while (current != NULL) {
      if (item == current->data) {
        ans = count;
        break;
      }
      current = current->next;
      count++;
    }
    return ans;
  }
  int getSize() const { return size; }
  friend void testList();
};
#endif
