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

/* Calls the private remove function
 * @param value - the value to remove
 * @return bool - true if the value was deleted
 */
bool BSTree::Remove(int value) {
  if (root_ == NULL)
    return false;
  return Remove(value, root_);
}

/* Calls the private FindMin function
 * @return int - the smallest value in the tree
 */
int BSTree::FindMin() {
  if (root_ == NULL)
    return 0;
  return FindMin(root_);
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

/* Deletes the given value in the given tree
 * @param value - the value to remove
 * @param BSTNode*& - the root of the tree to search
 * @return bool - true if the value was deleted
 */
bool BSTree::Remove(int value, BSTNode*& root) {
  if (value == root->GetContents()) {
    if (root->GetLeftChild() == NULL && root->GetRightChild() == NULL) {
      delete root;
      root = NULL;
      size_--;
      return true;
    } else if (root->GetLeftChild() == NULL) {
      BSTNode* temp = root;
      root = root->GetRightChild();
      delete temp;
      size_--;
      return true;
    } else if (root->GetRightChild() == NULL) {
      BSTNode* temp = root;
      root = root->GetLeftChild();
      delete temp;
      size_--;
      return true;
    } else {
      root->SetContents(FindMin(root->GetRightChild()));
      return Remove(root->GetContents(), root->GetRightChild());
    }
  } else if (value > root->GetContents() && root->GetRightChild() != NULL) {
    return Remove(value, root->GetRightChild());
  } else if (value < root->GetContents() && root->GetLeftChild() != NULL) {
    return Remove(value, root->GetLeftChild());
  } else {
    return false;
  }
}

/* Calls the private find smallest function.
 * @param BSTNode* - the root of the tree to search
 * @return int - the smallest value in the tree
 */
int BSTree::FindMin(BSTNode* root) {
  if (root->GetLeftChild() == NULL)
    return root->GetContents();
  else
    return FindMin(root->GetLeftChild());
}
