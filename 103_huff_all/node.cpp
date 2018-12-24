#include "node.h"
void Node::buildMap(BitString & b, std::map<unsigned, BitString> & theMap) {
  //WRITE ME!
  if (this->sym != NO_SYM) {
    //assert(this->left == NULL && this->right == NULL);
    theMap[unsigned(this->sym)] = b;
    return;
  }
  b.plusZero();
  this->left->buildMap(b, theMap);
  b.pop();
  b.plusOne();
  this->right->buildMap(b, theMap);
  b.pop();
}
