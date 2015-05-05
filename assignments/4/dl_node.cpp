/* Filename: dl_node.cpp
 * Author: Derek Lopes
 * Description: Implimentation file for doubly linked nodes
 * Sources: Luke Sathrum
 */

#include "dl_node.h"


/* Default constructor. Sets the contents of the node to 0 and both links to NULL.
 */
DLNode::DLNode()
  : contents_(0), next_node_(NULL), previous_node_(NULL)
{ }

/* Overloaded constructor. Sets the contents of the node to the provided value
 * and both links to NULL.
 * @param int - the value to set the contents of the node to
 */
DLNode::DLNode(int value)
  : contents_(value), next_node_(NULL), previous_node_(NULL)
{ }

/* Destructor, included for completeness.
 */
DLNode::~DLNode() {
  // empty, included for completeness
}

/* Mutator for contents_. Sets the value of contents to the provided value.
 * @param int - value to set contents to
 */
void DLNode::SetContents(int contents) {
  contents_ = contents;
}

/* Mutator for next_node_. Sets the pointer to the next node.
 * @param DLNode* - pointer to the next node in the list.
 */
void DLNode::SetNext(DLNode* next_node) {
  next_node_ = next_node;
}

/* Mutator for previous_node_. Sets the pointer to the previous node.
 * @param DLNode* - pointer to the previous node in the list.
 */
void DLNode::SetPrevious(DLNode* previous_node) {
  previous_node_ = previous_node;
}

/* Accessor for contents_. Gets the value held in the node.
 */
int DLNode::GetContents() const {
  return contents_;
}

/* Accessor for next_node_. Gets the pointer to the next node.
 */
DLNode* DLNode::GetNext() const {
  return next_node_;
}

/* Accessor for previous_node_. Gets the pointer to the previous node.
 */
DLNode* DLNode::GetPrevious() const {
  return previous_node_;
}
