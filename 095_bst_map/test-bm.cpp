#include <assert.h>

#include <cstdlib>
#include <iostream>

#include "bstmap.h"
void testBstMap() {
  BstMap<int, int> map1;
  map1.add(3, 3);
  map1.add(1, 1);
  map1.add(0, 0);
  map1.add(2, 2);
  map1.add(5, 5);
  map1.add(4, 4);
  map1.add(6, 6);
  assert(map1.lookup(6) == 6);
  assert(map1.lookup(5) == 5);
  assert(map1.lookup(3) == 3);
  assert(map1.lookup(4) == 4);
  assert(map1.lookup(2) == 2);
  assert(map1.lookup(1) == 1);
  assert(map1.lookup(0) == 0);
  assert(map1.root->right->key == 5);
  assert(map1.root->left->key == 1);
  assert(map1.root->right->right->key == 6);
  assert(map1.root->right->left->key == 4);
  assert(map1.root->left->right->key == 2);
  assert(map1.root->left->left->key == 0);
  std::cout << "add pass\n";
  BstMap<int, int> map2(map1);

  BstMap<int, int> map3;
  map3 = map1;
  map1.remove(5);
  assert(map1.root->right->key == 6);
  map1.remove(3);
  std::cout << map1.root->key << std::endl;
  assert(map1.root->key == 4);
  std::cout << "remove pass" << std::endl;
  assert(map2.lookup(6) == 6);
  assert(map2.lookup(5) == 5);
  assert(map2.lookup(3) == 3);
  assert(map2.lookup(4) == 4);
  assert(map2.lookup(2) == 2);
  assert(map2.lookup(1) == 1);
  assert(map2.lookup(0) == 0);
  assert(map2.root->right->key == 5);
  assert(map2.root->left->key == 1);
  assert(map2.root->right->right->key == 6);
  assert(map2.root->right->left->key == 4);
  assert(map2.root->left->right->key == 2);
  assert(map2.root->left->left->key == 0);
  std::cout << "copy constructor pass\n";
  assert(map3.lookup(6) == 6);
  assert(map3.lookup(5) == 5);
  assert(map3.lookup(3) == 3);
  assert(map3.lookup(4) == 4);
  assert(map3.lookup(2) == 2);
  assert(map3.lookup(1) == 1);
  assert(map3.lookup(0) == 0);
  assert(map3.root->right->key == 5);
  assert(map3.root->left->key == 1);
  assert(map3.root->right->right->key == 6);
  assert(map3.root->right->left->key == 4);
  assert(map3.root->left->right->key == 2);
  assert(map3.root->left->left->key == 0);
  std::cout << "operator =  pass\n";
}
int main(void) {
  testBstMap();
  std::cout << "pass all tests" << std::endl;
  return EXIT_SUCCESS;
}
