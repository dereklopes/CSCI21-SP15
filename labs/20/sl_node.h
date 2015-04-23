/* File: sl_node.h
 * Author: Derek Lopes
 * Description: 
 * Sources: Luke Sathrum
 */

#ifndef SLNODE_LOPES
#define SLNODE_LOPES

#include <iostream>

class SLNode {
 public:
  /* Default constructor. Sets next_node_ to NULL and contents(0) 
   */
  SLNode();

  /* Overloaded constructor. Sets next_node_ to NULL and contents to provided value.
   * @param int - value to set contents to.
   */
  SLNode(int contents);

  /* Deconstructor. Included for completeness.
   */
  ~SLNode();

  /* Function to set the value of contents.
   * @param int - value to set contents to.
   */
  void set_contents(int value);

  /* Accessor for the value stored in the node.
   * @return int - the value stored in the node.
   */
  int contents() const;

  /* Sets the pointer to the next node in the linked list.
   * @param SLNode* - the location of the next node
   */
  void set_next_node(SLNode* next_node);

  /* Accessor for the location of the next node.
   * @return SLNode* - the location of the next node.
   */
  SLNode* next_node() const;

 private:
  int contents_;
  SLNode* next_node_;
};

#endif  // SLNODE_LOPES
