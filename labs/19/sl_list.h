/* File name: sl_list.h
 * Author: Derek Lopes
 * Description: Class to handle linked lists
 */

#ifndef SLLIST_LOPES
#define SLLIST_LOPES

#include "sl_node.h"

#include <iostream>
#include <sstream>

using std::string;
using std::stringstream;

class SLList {
 public:
  /* Default constructor. Sets head to null and size to 0.
   */
  SLList();

  /* Default destructor. Calls the clear algoritm to free dynamic memory.
   */
  ~SLList();

  /* Inserts a node at the head of the linked list.
   * @param int - value to set the new node to 
   */
  void InsertHead(int value);

  /* Deletes the first node in the linked list.
   */
  void RemoveHead();

  /* Inserts a node at the tail of the linked list.
   * @param int - value to set the new node to
   */
  void InsertTail(int value);

  /* Deletes the last node in the linked list.
   */
  void RemoveTail();

  /* Deletes all the nodes in the linked list.
   */
  void Clear();


  /* Returns the size of the linked list.
   * @return unsigned int - size of the linked list
   */
  unsigned int size() const;

  /* Returns a string of the values, comma separated.
   * @return string - the values as a string list, comma separated
   */
  string ToString() const;

  /* Returns the contents at the head.
   */
  int GetHead() const;

  /* Returns the contents at the tail.
   */
  int GetTail() const;

 private:
  SLNode *head_, *tail_;
  unsigned int size_;
};

#endif  // SLIST_LOPES
