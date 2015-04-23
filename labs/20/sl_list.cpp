/* File name: sl_list.cpp
 * Author: Derek Lopes
 * Description: Implimentation file for string linked lists
 */

#include "sl_list.h"

/* Default constructor. Sets head to null and size to 0.
 */
SLList::SLList() {
  head_ = NULL;
  tail_ = NULL;
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

/* Deletes the first node that contains the value provided
 * @param int - the value to delete
 * @return bool - true if value is found and deleted, false if not
 */
bool SLList::RemoveFirstOccurence(int value) {
  SLNode *iterator = head_, *trailer = head_;
  while (iterator != NULL && iterator->contents() != value) {
    trailer = iterator;
    iterator = iterator->next_node();
  }
  if (iterator == NULL) {
    return false;
  } else if (iterator == head_) {
    RemoveHead();
    return true;
  } else if (iterator == tail_) {
    RemoveTail();
    return true;
  } else if (iterator->contents() == value) {
    trailer->set_next_node(iterator->next_node());
    delete iterator;
    size_--;
    return true;
  }
  return false;
}

/* Inserts a node with the value provided into the sorted list
 * @param int - the value of the node to be inserted
 */
void SLList::Insert(int value) {
  if (head_ == NULL || head_->contents() >= value) {
    InsertHead(value);
  } else if (tail_->contents() <= value) {
    InsertTail(value);
  } else {
    SLNode *iterator = head_, *trailer = head_;
    SLNode *new_node = new SLNode(value);
    while (iterator->contents() <= value) {
      trailer = iterator;
      iterator = iterator->next_node();
    }
    new_node->set_next_node(iterator);
    trailer->set_next_node(new_node);
    size_++;
  }
}
