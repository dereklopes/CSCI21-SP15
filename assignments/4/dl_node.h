/* Filename: dl_node.h
 * Author: Derek Lopes
 * Description: Header file for doubly linked nodes
 * Sources: Luke Sathrum
 */

#ifndef DL_NODE_LOPES
#define DL_NODE_LOPES

#include <iostream>

class DLNode {
 public:
  /* Default constructor. Sets the contents of the node to 0 and both links to NULL.
   */
  DLNode();

  /* Overloaded constructor. Sets the contents of the node to the provided value
   * and both links to NULL.
   * @param int - the value to set the contents of the node to
   */
  DLNode(int value);

  /* Destructor, included for completeness.
   */
  ~DLNode();

  /* Mutator for contents_. Sets the value of contents to the provided value.
   * @param int - value to set contents to
   */
  void SetContents(int contents);

  /* Mutator for next_node_. Sets the pointer to the next node.
   * @param DLNode* - pointer to the next node in the list.
   */
  void SetNext(DLNode* next_node);

  /* Mutator for previous_node_. Sets the pointer to the previous node.
   * @param DLNode* - pointer to the previous node in the list.
   */
  void SetPrevious(DLNode* previous_node);

  /* Accessor for contents_. Gets the value held in the node.
   */
  int GetContents() const;

  /* Accessor for next_node_. Gets the pointer to the next node.
   */
  DLNode* GetNext() const;

  /* Accessor for previous_node_. Gets the pointer to the previous node.
   */
  DLNode* GetPrevious() const;

 private:
 int contents_;
 DLNode *next_node_, *previous_node_;
};

#endif  // DL_NODE_LOPES
