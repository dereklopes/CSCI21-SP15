/* Filename: dl_list.h
 * Author: Derek Lopes
 * Description: Header file for doubly linked lists
 * Sources: Luke Sathrum
 */

#ifndef DLLIST_LOPES
#define DLLIST_LOPES

#include <iostream>
#include <sstream>

#include "dl_node.h"

using std::stringstream;
using std::cerr;
using std::cout;
using std::string;
using std::endl;

class DLList {
 public:
  /* Default constructor. Initializes the member variables and sets up the list.
   */
  DLList();

  /* Destructor. Clears the list with the Clear() member function.
   */
  ~DLList();

  /* Returns the size of the list. Const function.
   * @return unsigned int - the current size of the list.
   */
  unsigned int GetSize() const;

  /* Creates a DLNode with the given value and adds it to the front of the list.
   * @param int - the value to set the DLNode to.
   */
  void PushFront(int value);

  /* Creates a DLNode with the given value and adds it to the back of the list.
   * @param int - the value to set the DLNode to.
   */
  void PushBack(int value);

  /* Returns the integer stored in the first DLNode in the list.
   * Outputs "List Empty" to cerr and returns 0 if list is empty.
   * Const function.
   * @return int - the contents of the first node.
   */
  int GetFront() const;

  /* Returns the integer stored in the last DLNode in the list.
   * Outputs "List Empty" to cerr and returns 0 if list is empty.
   * Const function.
   * @return int - the contents of the last node.
   */
  int GetBack() const;

  /* Removes the first node in the list.
   * Outputs "List Empty" to cerr if the list is empty.
   */
  void PopFront();

  /* Removes the last node in the list.
   * Outputs "List Empty" to cerr if the list is empty.
   */
  void PopBack();

  /* Removes the first node with the provided value.
   * If the value is not found, outputs "Not Found" to cerr.
   * @param int - the value to remove from the list
   */
  void RemoveFirst(int value);

  /* Removes all the nodes with the provided value.
   * If the value is not found, outputs "Not Found" to cerr.
   * @param int - the value to remove from the list
   */
  void RemoveAll(int value);

  /* Checks to see if the provided value is stored in the list.
   * @param int - the value to find in the list
   * @return bool - true if the value exists, false if not
   */
  bool Exists(int value);

  /* Clears the list by deleting all nodes, resetting size to 0, and
   * head and tail pointers to NULL.
   */
  void Clear();

  /* Returns a comma separated list of all nodes in order.
   * Outputs "List Empty" to cerr if the list is empty.
   * @return string - the comma separated list
   */
  string ToStringForwards();

  /* Outputs a comma separated list of all the nodes in reverse order.
   * Outputs "List Empty" to cerr if the list is empty.
   * @return string - the comma separated list
   */
  string ToStringBackwards();

 private:
  unsigned int size_;
  DLNode *head_, *tail_;
};

#endif  // DLLIST_LOPES
