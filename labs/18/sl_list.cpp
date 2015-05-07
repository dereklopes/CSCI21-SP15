/* File name: sl_list.cpp
 * Author: Derek Lopes
 * Description: Implimentation file for string linked lists
 */

#include "sl_list.h"

/* Default constructor. Sets head to null and size to 0.
 */
SLList::SLList() {
  head_ = NULL;
  size_ = 0;
}

/* Default destructor. Calls the clear algoritm to free dynamic memory.
 */
SLList::~SLList() {
  Clear();
}

/* Inserts a node at the head of the linked list.
 * @param int - value to set the new node to
 */
void SLList::InsertHead(int value) {
  SLNode *new_node = new SLNode(value);
  if (head_ == NULL) {
    head_ = new_node;
  } else {
    new_node->set_next_node(head_);
    head_ = new_node;
  }
  size_++;
}

/* Deletes the first node in the linked list.
 */
void SLList::RemoveHead() {
  if (head_ != NULL) {
    SLNode *temp = head_;
    head_ = head_->next_node();
    delete temp;
    size_--;
  }
}

/* Deletes all the nodes in the linked list.
 */
void SLList::Clear() {
  SLNode *temp = head_;
  while (head_ != NULL) {
    head_ = head_->next_node();
    delete temp;
    temp = head_;
  }
  size_ = 0;
}

/* Returns the size of the linked list.
 * @return unsigned int - size of the linked list
 */
unsigned int SLList::size() const {
  return size_;
}

/* Returns a string of the values, comma separated.
 * @return string - the values as a string list, comma separated
 */
string SLList::ToString() const {
  if (head_ == NULL)
    return "";
  stringstream ss;
  SLNode *it = head_;
  while (it->next_node() != NULL) {
    ss << it->contents() << ", ";
    it = it->next_node();
  }
  ss << it->contents();
  return ss.str();
}
