#include <assert.h>

#include <cstdlib>
#include <iostream>

#include "ll.h"
void testList() {
  LinkedList<int> list1;
  assert(list1.getSize() == 0);
  assert(list1.head == NULL);
  assert(list1.tail == NULL);
  assert(list1.size == 0);
  std::cout << "pass default" << std::endl;
  //addFront
  list1.addFront(3);
  assert(list1[0] == 3);
  assert(list1.head != NULL);
  assert(list1.tail != NULL);
  list1.addFront(2);
  assert(list1[0] == 2);
  assert(list1[1] == 3);
  assert(list1.head != list1.tail);
  assert(list1.head->next->data == 3);
  assert(list1.head->prev == NULL);
  assert(list1.tail->next == NULL);
  assert(list1.tail->prev != NULL);
  list1.addFront(10);
  assert(list1[0] == 10);
  assert(list1[1] == 2);
  assert(list1[2] == 3);
  assert(list1.head != list1.tail);
  std::cout << "pass addFront" << std::endl;
  //copy constructor
  LinkedList<int> list4(list1);
  //std::cout << list1.getSize() << std::endl;
  std::cout << list4.size << std::endl;
  //std::cout << list4[0] << list4[1] << list4[2] << std::endl;
  assert(list4.getSize() == 3);
  std::cout << "right size" << std::endl;
  assert(list4.size == 3);
  std::cout << "right size" << std::endl;

  assert(list4[0] == 10);
  assert(list4[1] == 2);
  assert(list4[2] == 3);
  assert(list4.head != list4.tail);
  std::cout << "pass copy constructor" << std::endl;
  //opertor=
  LinkedList<int> list2;
  list2 = list1;
  list1[0] = 100;
  assert(list2.getSize() == 3);
  assert(list2.size == 3);
  assert(list2[0] == 10);
  assert(list2[1] == 2);
  assert(list2[2] == 3);
  assert(list2.head != list2.tail);
  std::cout << "pass operator=" << std::endl;
  //addBack
  LinkedList<int> list3;
  list3.addBack(1);
  assert(list3[0] == 1);
  assert(list3.head == list3.tail);
  assert(list3.head->next == NULL);
  assert(list3.head->prev == NULL);
  list3.addBack(2);
  assert(list3.head != list3.tail);
  assert(list3[1] == 2);
  assert(list3[0] == 1);
  assert(list3.head->next != NULL);
  assert(list3.head->prev == NULL);
  assert(list3.tail->next == NULL);
  assert(list3.tail->prev != NULL);
  list3.addBack(3);
  assert(list3.head != list3.tail);
  assert(list3[2] == 3);
  assert(list3[1] == 2);
  assert(list3[0] == 1);
  std::cout << "pass addBack" << std::endl;
  //remove
  list3.remove(1);
  assert(list3[0] == 2);
  assert(list3[1] == 3);
  assert(list3.getSize() == 2);
  assert(list3.size == 2);
  list3.remove(2);
  assert(list3[0] == 3);
  assert(list3.getSize() == 1);
  //std::cout << list3.size;
  assert(list3.size == 1);
  list3.remove(3);
  assert(list3.getSize() == 0);
  assert(list3.size == 0);
  assert(list3.head == NULL);
  assert(list3.tail == NULL);
  //find
  assert(list1.find(3) == 2);
  //std::cout << list1.find(10);
  assert(list1.find(100) == 0);
  assert(list1.find(2) == 1);
  assert(list1.find(-1) == -1);
  LinkedList<int> list5;
  list5.addFront(1);
  list5.addFront(2);
  list5.addFront(3);
  list5.remove(2);
  assert(list5.tail->prev->data == 3);
  assert(list5.head->next->data == 1);
  for (LinkedList<int>::iterator it = list5.begin(); it != list5.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
int main(void) {
  testList();
  std::cout << "pass all tests" << std::endl;
  return EXIT_SUCCESS;
}
