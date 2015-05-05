/* Filename: dl_list.cpp
 * Author: Derek Lopes
 * Description: Implimentation file for doubly linked lists
 * Sources: Luke Sathrum
 */

#include "dl_list.h"

/* Default constructor. Initializes the member variables and sets up the list.
 */
DLList::DLList()
  : size_(0), head_(NULL), tail_(NULL) 
{ }

/* Destructor. Clears the list with the Clear() member function.
 */
DLList::~DLList() {
  Clear();
}

/* Returns the size of the list. Const function.
 * @return unsigned int - the current size of the list.
 */
unsigned int DLList::GetSize() const {
  return size_;
}

/* Creates a DLNode with the given value and adds it to the front of the list.
 * @param int - the value to set the DLNode to.
 */
void DLList::PushFront(int value) {
  DLNode *new_node = new DLNode(value);
  if (head_ == NULL) {
    tail_ = new_node;
    head_ = new_node;
  } else {
    new_node->SetNext(head_);
    head_->SetPrevious(new_node);
    head_ = new_node;
  }
  size_++;
}

/* Creates a DLNode with the given value and adds it to the back of the list.
 * @param int - the value to set the DLNode to.
 */
void DLList::PushBack(int value) {
  if (head_ == NULL) {
    PushFront(value);
  } else {
    DLNode *new_node = new DLNode(value);
    tail_->SetNext(new_node);
    new_node->SetPrevious(tail_);
    tail_ = new_node;
    size_++;
  }
}

/* Returns the integer stored in the first DLNode in the list.
 * Outputs "List Empty" to cerr and returns 0 if list is empty.
 * Const function.
 * @return int - the contents of the first node.
 */
int DLList::GetFront() const {
  if (head_ == NULL) {
    cerr << "List Empty";
    return 0;
  }
  return head_->GetContents();
}

/* Returns the integer stored in the last DLNode in the list.
 * Outputs "List Empty" to cerr and returns 0 if list is empty.
 * Const function.
 * @return int - the contents of the last node.
 */
int DLList::GetBack() const {
  if (head_ == NULL) {
    cerr << "List Empty";
    return 0;
  }
  return tail_->GetContents();
}

/* Removes the first node in the list.
 * Outputs "List Empty" to cerr if the list is empty.
 */
void DLList::PopFront() {
  if (head_ == NULL) {
    cerr << "List Empty";
    return;
  }
  if (head_ != NULL && size_ > 1) {
    DLNode *temp = head_;
    head_ = head_->GetNext();
    head_->SetPrevious(NULL);
    delete temp;
    size_--;
  } else if (size_ == 1) {
    delete head_;
    head_ = tail_ =  NULL;
    size_ = 0;
  }
}

/* Removes the last node in the list.
 * Outputs "List Empty" to cerr if the list is empty.
 */
void DLList::PopBack() {
  if (head_ == NULL) {
    cerr << "List Empty";
    return;
  }
  if (size_ == 1) {
    PopFront();
  } else if (size_ > 1) {
    DLNode *iterator = head_;
    while (iterator->GetNext() != tail_) {
      iterator = iterator->GetNext();
    }
    iterator->SetNext(NULL);
    delete tail_;
    tail_ = iterator;
    size_--;
  }
}

/* Removes the first node with the provided value.
 * If the value is not found, outputs "Not Found" to cerr.
 * @param int - the value to remove from the list
 */
void DLList::RemoveFirst(int value) {
  if (head_ == NULL) {
    cerr << "Not Found";
    return;
  }
  bool did_delete = false;
  if (value == head_->GetContents()) {
    PopFront();
    did_delete = true;
  } else if (value == tail_->GetContents()) {
    PopBack();
    did_delete = true;
  } else {
    DLNode *iterator = head_->GetNext();
    iterator = iterator->GetNext();
    while (iterator->GetNext() != NULL && !did_delete) {
      if (iterator->GetContents() == value) {
        // sets the node behind the iterator's next node to the one
        // after the iterator
        (iterator->GetPrevious())->SetNext(iterator->GetNext());

        // sets the node after the iterator's previous node to the
        // one before the iterator
        (iterator->GetNext())->SetPrevious(iterator->GetPrevious());

        // deletes the node at the iterator
        delete iterator;
        did_delete = true;
      }
      if (!did_delete)
        iterator = iterator->GetNext();
    }
  }
  if (!did_delete) {  // checks to see if it did not delete the node
    cerr << "Not Found";
    size_--;
  }
}
        

/* Removes all the nodes with the provided value.
 * If the value is not found, outputs "Not Found" to cerr.
 * @param int - the value to remove from the list
 */
void DLList::RemoveAll(int value) {
  if (head_ == NULL) {
    cerr << "Not Found";
    return;
  }

  bool did_delete = false;
  if (value == head_->GetContents()) {
    PopFront();
    did_delete = true;
  }
  if (value == tail_->GetContents()) {
    PopBack();
    did_delete = true;
  }
  DLNode *iterator = head_->GetNext();
  iterator = iterator->GetNext();
  while (iterator->GetNext() != NULL) {
    if (iterator->GetContents() == value) {
      // sets the node behind the iterator's next node to the one
      // after the iterator
      (iterator->GetPrevious())->SetNext(iterator->GetNext());

      // sets the node after the iterator's previous node to the
      // one before the iterator
      (iterator->GetNext())->SetPrevious(iterator->GetPrevious());

      // deletes the node at the iterator
      delete iterator;
      did_delete = true;
    }
    if (!did_delete)
      iterator = iterator->GetNext();
  }
  if (!did_delete) {  // checks to see if it did not delete the node
    cerr << "Not Found";
    size_--;
  }
  /* OLD CODE
  DLNode* iterator = head_;
  if (size_ == 1) {
    if (value == iterator->GetContents())
      PopFront();
  } else {
    bool did_delete = false;
    unsigned int amount_deleted = 0;
    while (iterator != NULL) {
      if (iterator->GetContents() == value) {
        // sets the node behind the iterator's next node to the one
        // after the iterator
        iterator->GetPrevious()->SetNext(iterator->GetNext());
        // sets the node after the iterator's previous node to the
        // one before the iterator
        iterator->GetNext()->SetPrevious(iterator->GetPrevious());
        // deletes the node at the iterator
        delete iterator;
        did_delete = true;
        amount_deleted++;
      }
    }
    if (did_delete) {  // checks to see if it did not delete the node
      cerr << "Not Found";
      for (unsigned int i = 0; i < amount_deleted; i++) {
        size_--;
      }
    }
  }
  */
}

/* Checks to see if the provided value is stored in the list.
 * @param int - the value to find in the list
 * @return bool - true if the value exists, false if not
 */
bool DLList::Exists(int value) {
  if (head_ == NULL)
    return false;
  DLNode *iterator = head_;
  while (iterator != NULL) {
    if (value == iterator->GetContents())
      return true;
    iterator = iterator->GetNext();
  }
  return false;
}

/* Clears the list by deleting all nodes, resetting size to 0, and
 * head and tail pointers to NULL.
 */
void DLList::Clear() {
  DLNode *temp = head_;
  while (head_ != NULL) {
    head_ = head_->GetNext();
    delete temp;
    temp = head_;
  }
  tail_ = NULL;
  size_ = 0;
}

/* Returns a comma separated list of all nodes in order.
 * Outputs "List Empty" to cerr if the list is empty.
 * @return string - the comman separated list
 */
string DLList::ToStringForwards() {
  if (head_ == NULL) {
    cerr << "List Empty";
    return string("");
  }
  stringstream ss;
  DLNode *it = head_;
  while (it->GetNext() != NULL) {
    ss << it->GetContents() << ", ";
    it = it->GetNext();
  }
  ss << it->GetContents();
  return ss.str();
}

/* Returns a comma separated list of all the nodes in reverse order.
 * Outputs "List Empty" to cerr if the list is empty.
 * @return string - the comma separated list
 */
string DLList::ToStringBackwards() {
  if (head_ == NULL) {
    cerr << "List Empty";
    return string("");
  }
  stringstream ss;
  DLNode *it = tail_;
  while (it != head_) {
    ss << it->GetContents() << ", ";
    it = it->GetPrevious();
  }
  ss << it->GetContents();
  return ss.str();
}

