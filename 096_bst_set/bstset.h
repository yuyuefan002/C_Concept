#include <iostream>

#include "set.h"
template<typename T>
class BstSet : public Set<T>
{
 private:
  class Node
  {
   public:
    T key;
    Node * left;
    Node * right;

   public:
    Node(T k, Node * l, Node * r) : key(k), left(l), right(r) {}
    Node(T k) : key(k), left(NULL), right(NULL) {}
  };
  Node * root;
  Node * add(Node * cur, const T & key) {
    if (cur == NULL) {
      Node * ans = new Node(key);
      return ans;
    }
    else {
      if (key < cur->key) {
        Node * newLeft = add(cur->left, key);
        cur->left = newLeft;
      }
      else if (key > cur->key) {
        Node * newRight = add(cur->right, key);
        cur->right = newRight;
      }
    }
    return cur;
  }
  Node * remove(const T & key, Node * cur) {
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
        while (temp->left != NULL) {
          temp = temp->left;
        }
        cur->key = temp->key;
        cur->right = remove(cur->key, cur->right);
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
    new_cur = new Node(cur->key);
    new_cur->left = preorderTraversal(cur->left, new_cur->left);
    new_cur->right = preorderTraversal(cur->right, new_cur->right);
    return new_cur;
  }

 public:
  BstSet() : root(NULL) {}
  BstSet(const BstSet & rhs) : root(NULL) {
    Node * cur = rhs.root;
    root = preorderTraversal(cur, root);
  }
  BstSet & operator=(const BstSet & rhs) {
    if (this == &rhs) {
      return *this;
    }
    BstSet temp(rhs);
    std::swap(root, temp.root);
    return *this;
  }
  ~BstSet() {
    destroy(root);
    root = NULL;
  }
  void add(const T & key) { root = add(root, key); }
  bool contains(const T & key) const {
    Node * cur = root;
    while (cur != NULL) {
      if (key == cur->key) {
        return true;
      }
      else if (key < cur->key) {
        cur = cur->left;
      }
      else {
        cur = cur->right;
      }
    }
    return false;
  }
  void remove(const T & key) { root = remove(key, root); }
  friend void testBstset();
};
