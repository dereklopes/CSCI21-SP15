/* Name: bst_nodet.tpp
 * Author Derek Lopes
 * Description: Implimentation file for the BSTNodeT class. 
 * Sources: Luke Sathrum
 */

#include "bst_nodet.h"

/* Default constructor. Sets left and right pointers to NULL, count to 0,
 * and contents to default.
 */
BSTNodeT()
  : contents_(T()), count_(0), left_child_(NULL), right_child_(NULL) { } 

/* Overloaded constructor. Sets left and right pointers to NULL.
 * Sets the contents to the provided value. Sets count to 0.
 * @param T - value to set contents of node to
 */
BSTNodeT(T value)
  : contents_(value), count_(0), left_child_(NULL), right_child_(NULL) { } 

/* Destructor. Sets left and right pointers to NULL.
 */
~BSTNodeT() {
  left_child_ = right_child_ = NULL;
}

/* Sets the contents of the node.
 * @param T - value to set contents of node to
 */
void SetContents(T value) {
  contents_ = value;
}

/* Gets the contents of the node. Const function.
 * @return T - the contents of the node
 */
T GetContents() const {
  return contents_;
}

/* Sets the left child node.
 * @param BSTNodeT* - a pointer to the left child node.
 */
void SetLeft(BSTNodeT* left_child) {
  left_child_ = left_child;
}

/* Sets the right child node.
 * @param BSTNodeT* - a pointer to the right child node.
 */
void SetRight(BSTNodeT* right_child) {
  right_child_ = right_child;
}

/* Gets a reference to a pointer to the left child.
 * @return BSTNodeT*& - a reference to the pointer to the left child.
 */
BSTNodeT*& GetLeft() {
  return left_child_;
}

/* Gets a reference to a pointer to the right child.
 * @return BSTNodeT*& - a reference to the pointer to the right child.
 */
BSTNodeT*& GetRight() {
  return right_child_;
}

/* Increments count by 1.
 */
void IncrementCount() {
  count_++;
}

/* Decrements count by 1.
 */
void DecrementCount() {
  count_--;
}

/* Gets the value of count.
 */
unsigned int GetCount() {
  return count_;
}
