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
    tail_ = new_node;
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
  if (head_ != NULL && size_ > 1) {
    SLNode *temp = head_;
    head_ = head_->next_node();
    delete temp;
    size_--;
  } else if (size_ == 1) {
    delete head_;
    head_ = tail_ =  NULL;
    size_ = 0;
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
  tail_ = NULL;
  size_ = 0;
}

/* Inserts a node at the tail of the linked list.
 * @param int - value to set the new node to
 */
void SLList::InsertTail(int value) {
  if (head_ == NULL) {
    InsertHead(value);
  } else {
    SLNode *new_node = new SLNode(value);
    tail_->set_next_node(new_node);
    tail_ = new_node;
    size_++;
  }
}

/* Deletes the last node in the linked list.
 */
void SLList::RemoveTail() {
  if (size_ == 1) {
    RemoveHead();
  } else if (size_ > 1) {
    SLNode *iterator = head_;
    while (iterator->next_node() != tail_) {
      iterator = iterator->next_node();
    }
    iterator->set_next_node(NULL);
    delete tail_;
    tail_ = iterator;
    size_--;
  }
}

/* Returns the contents at the head.
 */
int SLList::GetHead() const {
  if (head_ == NULL)
    return 0;
  return head_->contents();
}

/* Returns the contents at the tail.
 */
int SLList::GetTail() const {
  if (tail_ == NULL)
    return 0;
  return tail_->contents();
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
