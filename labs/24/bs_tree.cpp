/* Filename: bs_tree.cpp
 * Author: Derek Lopes
 * Description: Implimentation file for binary search trees
 * Sources: Luke Sathrum
 */

#include "bs_tree.h"

// PUBLIC MEMBER FUNCTIONS

/* Default constructor. Sets root to NULL and size to 0.
 */
BSTree::BSTree()
  : root_(NULL), size_(0) { }


/* Destructor. Calls the clear function.
 */
BSTree::~BSTree() {
  Clear();
}

/* Inserts a value into the tree. Calls the private insert function.
 * @param int - the value to add to the tree
 * @return bool - true if the value was inserted
 */
bool BSTree::Insert(int value) {
  return Insert(value, root_);
}

/* Clears the entire tree. Calls the private clear funciton.
 */
void BSTree::Clear() {
  Clear(root_);
  root_ = NULL;
}

/* Gets the size of the tree.
 * @return unsigned int - the size of the tree
 */
unsigned int BSTree::GetSize() const {
  return size_;
}

/* Returns a string of the values in order
 * The values are separated by a space
 * @return string - the values of the tree in order
 */
string BSTree::InOrder() {
  return InOrder(root_);
}

// PRIVATE MEMBER FUNCTIONS

/* Inserts the value into the tree starting at the root provided
 * @param int - value to insert into the tree
 * @param BSTNode*& - the root to start at
 * @return bool - true if the value was inserted
 */
bool BSTree::Insert(int value, BSTNode*& root) {
  if (root == NULL) {
    root = new BSTNode(value);
    size_++;
    return true;
  }
  if (root->GetContents() > value) {
    return Insert(value, root->GetLeftChild());
  }
  if (root->GetContents() < value) {
    return Insert(value, root->GetRightChild());
  }
  return false;
}

/* Clears the tree at the root provided.
 * @param BSTNODE*& - the root to clear of the tree
 */
void BSTree::Clear(BSTNode*& root) {
  if (root == NULL)
    return;
  Clear(root->GetLeftChild());
  Clear(root->GetRightChild());
  delete root;
  size_--;
}

/* Creates a string of the tree values in order
 * @return string - the values of the tree in order
 */
string BSTree::InOrder(BSTNode* root) {
  if (root == NULL)
    return string("");
  stringstream ss;
  ss << InOrder(root->GetLeftChild());
  ss << root->GetContents() << " ";
  ss << InOrder(root->GetRightChild());
  return ss.str();
}

