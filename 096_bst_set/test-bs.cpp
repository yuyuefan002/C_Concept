#include <assert.h>

#include <cstdlib>
#include <iostream>

#include "bstset.h"
void testBstset() {
  BstSet<int> set1;
  set1.add(3);
  set1.add(1);
  set1.add(0);
  set1.add(2);
  set1.add(5);
  set1.add(4);
  set1.add(6);
  assert(set1.contains(6) == true);
  assert(set1.contains(5) == true);
  assert(set1.contains(3) == true);
  assert(set1.contains(4) == true);
  assert(set1.contains(2) == true);
  assert(set1.contains(1) == true);
  assert(set1.contains(0) == true);
  assert(set1.root->right->key == 5);
  assert(set1.root->left->key == 1);
  assert(set1.root->right->right->key == 6);
  assert(set1.root->right->left->key == 4);
  assert(set1.root->left->right->key == 2);
  assert(set1.root->left->left->key == 0);
  std::cout << "add pass\n";
  BstSet<int> set2(set1);
  std::cout << "remove start\n";
  BstSet<int> set3;
  set3 = set1;
  set1.remove(5);
  assert(set1.root->right->key == 6);
  set1.remove(3);
  //  std::cout << (set1.root->right->right->key);
  assert(set1.root->key == 4);
  assert(set1.root->left->key == 1);
  assert(set1.root->right->key == 6);
  assert(set1.root->left->left->key == 0);
  assert(set1.root->left->right->key == 2);
  assert(set1.root->left->left->right == NULL);
  assert(set1.root->left->left->left == NULL);

  assert(set1.root->right->right == NULL);
  assert(set1.root->right->left == NULL);
  std::cout << "remove pass" << std::endl;
  assert(set2.contains(6) == true);
  assert(set2.contains(5) == true);
  assert(set2.contains(3) == true);
  assert(set2.contains(4) == true);
  assert(set2.contains(2) == true);
  assert(set2.contains(1) == true);
  assert(set2.contains(0) == true);
  assert(set2.root->right->key == 5);
  assert(set2.root->left->key == 1);
  assert(set2.root->right->right->key == 6);
  assert(set2.root->right->left->key == 4);
  assert(set2.root->left->right->key == 2);
  assert(set2.root->left->left->key == 0);
  std::cout << "copy constructor pass\n";
  assert(set3.contains(6) == true);
  assert(set3.contains(5) == true);
  assert(set3.contains(3) == true);
  assert(set3.contains(4) == true);
  assert(set3.contains(2) == true);
  assert(set3.contains(1) == true);
  assert(set3.contains(0) == true);
  assert(set3.root->right->key == 5);
  assert(set3.root->left->key == 1);
  assert(set3.root->right->right->key == 6);
  assert(set3.root->right->left->key == 4);
  assert(set3.root->left->right->key == 2);
  assert(set3.root->left->left->key == 0);
  std::cout << "operator =  pass\n";
}
int main(void) {
  testBstset();
  std::cout << "pass all tests" << std::endl;
  return EXIT_SUCCESS;
}
