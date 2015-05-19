/* File Name: bst_node.cpp
 * Author: Derek Lopes
 * Description: Implimentation file for binariry search trees
 * Sources: Luke Sathrum
 */

#include "bst_node.h"


/* Default constructor. Sets left and right pointers to NULL and contents to 0.
 */
BSTNode::BSTNode()
  : left_child_(NULL), right_child_(NULL), contents_(0) { }

/* Overloaded constructor. Sets left and right pointers to NULL.
 * Sets the contents to the provided value.
 * @param int - value to set contents of node to
 */
BSTNode::BSTNode(int value)
  : left_child_(NULL), right_child_(NULL), contents_(value) { }

/* Destructor. Sets left and right pointers to NULL.
 */
BSTNode::~BSTNode() {
  right_child_ = left_child_ = NULL;
}

/* Sets the contents of the node.
 * @param int - value to set contents of node to
 */
void BSTNode::SetContents(int value) {
  contents_ = value;
}

/* Gets the contents of the node. Const function.
 * @return int - the contents of the node
 */
int BSTNode::GetContents() const {
  return contents_;
}

/* Gets a reference to the contents of the node.
 * @return int& - a reference to the contents of the node
 */
int& BSTNode::GetContents() {
  return contents_;
}

/* Sets the left child node.
 * @param BSTNode* - a pointer to the left child node.
 */
void BSTNode::SetLeftChild(BSTNode* left_child) {
  left_child_ = left_child;
}

/* Sets the right child node.
 * @param BSTNode* - a pointer to the right child node.
 */
void BSTNode::SetRightChild(BSTNode* right_child) {
  right_child_ = right_child;
}

/* Gets a pointer to the left child.
 * @return BSTNode* - a pointer to the left child node.
 */
BSTNode* BSTNode::GetLeftChild() const {
  return left_child_;
}

/* Gets a reference to a pointer to the left child.
 * @return BSTNode*& - a reference to the pointer to the left child.
 */
BSTNode*& BSTNode::GetLeftChild() {
  return left_child_;
}

/* Gets a pointer to the right child.
 * @return BSTNode* - a pointer to the right child node.
 */
BSTNode* BSTNode::GetRightChild() const {
  return right_child_;
}

/* Gets a reference to a pointer to the right child.
 * @return BSTNode*& - a reference to the pointer to the right child.
 */
BSTNode*& BSTNode::GetRightChild() {
  return right_child_;
}

