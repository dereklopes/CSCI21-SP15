/* File: sl_node.cpp
 * Author: Derek Lopes
 * Description:
 * Sources: Luke Sathrum
 */

#include "sl_node.h"


/* Default constructor. Sets next_node_ to NULL and contents(0) 
 */
SLNode::SLNode() {
  next_node_ = NULL;
  contents_ = 0;
}

/* Overloaded constructor. Sets next_node_ to NULL and contents to provided value.
 * @param int - value to set contents to.
 */
SLNode::SLNode(int contents) {
  next_node_ = NULL;
  contents_ = contents;
}

/* Deconstructor. Included for completeness.
 */
SLNode::~SLNode() {
  // empty
}

/* Function to set the value of contents.
 * @param int - value to set contents to.
 */
void SLNode::set_contents(int value) {
  contents_ = value;
}

/* Accessor for the value stored in the node.
 * @return int - the value stored in the node.
 */
int SLNode::contents() const {
  return contents_;
}

/* Sets the pointer to the next node in the linked list.
 * @param SLNode* - the location of the next node
 */
void SLNode::set_next_node(SLNode* next_node) {
  next_node_ = next_node;
}

/* Accessor for the location of the next node.
 * @return SLNode* - the location of the next node.
 */
SLNode* SLNode::next_node() const {
  return next_node_;
}
