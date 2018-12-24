#include <iostream>

#include "map.h"
template<typename K, typename V>
class BstMap : public Map<K, V>
{
 private:
  class Node
  {
   public:
    K key;
    V value;
    Node * left;
    Node * right;

   public:
    Node(K k, V v, Node * l, Node * r) : key(k), value(v), left(l), right(r) {}
    Node(K k, V v) : key(k), value(v), left(NULL), right(NULL) {}
  };
  Node * root;
  Node * add(Node * cur, const K & key, const V & value) {
    if (cur == NULL) {
      Node * ans = new Node(key, value);
      return ans;
    }
    else {
      if (key < cur->key) {
        Node * newLeft = add(cur->left, key, value);
        cur->left = newLeft;
      }
      else if (key > cur->key) {
        Node * newRight = add(cur->right, key, value);
        cur->right = newRight;
      }
      else {
        cur->value = value;
      }
    }
    return cur;
  }
  Node * remove(const K & key, Node * cur) {
    if (cur == NULL) {
      return NULL;
    }
    if (key == cur->key) {
      if (cur->left == NULL) {
        Node * temp = cur->right;
        delete cur;
        return temp;
      }
      else if (cur->right == NULL) {
        Node * temp = cur->left;
        delete cur;
        return temp;
      }
      else {
        Node * temp = cur->right;
        while (temp->left) {
          temp = temp->left;
        }
        cur->key = temp->key;
        cur->value = temp->value;
        cur->right = remove(key, cur->right);
      }
    }
    else if (key < cur->key) {
      Node * newLeft = remove(key, cur->left);
      cur->left = newLeft;
    }
    else {
      Node * newRight = remove(key, cur->right);
      cur->right = newRight;
    }
    return cur;
  }
  void destroy(Node * cur) {
    if (cur != NULL) {
      destroy(cur->left);
      cur->left = NULL;
      destroy(cur->right);
      cur->right = NULL;
      delete cur;
    }
  }
  Node * preorderTraversal(Node * cur, Node * new_cur) {
    if (cur == NULL) {
      return NULL;
    }
    new_cur = new Node(cur->key, cur->value);
    new_cur->left = preorderTraversal(cur->left, new_cur->left);
    new_cur->right = preorderTraversal(cur->right, new_cur->right);
    return new_cur;
  }

 public:
  BstMap() : root(NULL) {}
  BstMap(const BstMap & rhs) : root(NULL) {
    Node * cur = rhs.root;
    root = preorderTraversal(cur, root);
  }
  BstMap & operator=(const BstMap & rhs) {
    if (this == &rhs) {
      return *this;
    }
    BstMap temp(rhs);
    std::swap(root, temp.root);
    return *this;
  }
  ~BstMap() {
    destroy(root);
    root = NULL;
  }
  void add(const K & key, const V & value) { root = add(root, key, value); }
  const V & lookup(const K & key) const throw(std::invalid_argument) {
    Node * cur = root;
    while (cur != NULL) {
      if (key == cur->key) {
        return cur->value;
      }
      else if (key < cur->key) {
        cur = cur->left;
      }
      else {
        cur = cur->right;
      }
    }
    throw std::invalid_argument("key is not found\n");
  }
  void remove(const K & key) { root = remove(key, root); }
  friend void testBstMap();
};
