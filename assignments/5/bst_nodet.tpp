/* Name: bst_nodet.tpp
 * Author Derek Lopes
 * Description: Implimentation file for the BSTNodeT class. 
 * Sources: Luke Sathrum
 */

#include "bst_nodet.h"

/* Default constructor. Sets left and right pointers to NULL, count to 0,
 * and contents to default.
 */
template <typename T>
BSTNodeT()
  : contents_(T()), count_(0), left_child_(NULL), right_child_(NULL) { } 

/* Overloaded constructor. Sets left and right pointers to NULL.
 * Sets the contents to the provided value. Sets count to 0.
 * @param T - value to set contents of node to
 */
template <typename T>
BSTNodeT(T value)
  : contents_(value), count_(0), left_child_(NULL), right_child_(NULL) { } 

/* Destructor. Sets left and right pointers to NULL.
 */
template <typename T>
~BSTNodeT() {
  left_child_ = right_child_ = NULL;
}

/* Sets the contents of the node.
 * @param T - value to set contents of node to
 */
template <typename T>
void SetContents(T value) {
  contents_ = value;
}

/* Gets the contents of the node. Const function.
 * @return T - the contents of the node
 */
template <typename T>
T GetContents() const {
  return contents_;
}

/* Sets the left child node.
 * @param BSTNodeT* - a pointer to the left child node.
 */
template <typename T>
void SetLeft(BSTNodeT* left_child) {
  left_child_ = left_child;
}

/* Sets the right child node.
 * @param BSTNodeT* - a pointer to the right child node.
 */
template <typename T>
void SetRight(BSTNodeT* right_child) {
  right_child_ = right_child;
}

/* Gets a reference to a pointer to the left child.
 * @return BSTNodeT*& - a reference to the pointer to the left child.
 */
template <typename T>
BSTNodeT*& GetLeft() {
  return left_child_;
}

/* Gets a reference to a pointer to the right child.
 * @return BSTNodeT*& - a reference to the pointer to the right child.
 */
template <typename T>
BSTNodeT*& GetRight() {
  return right_child_;
}

/* Increments count by 1.
 */
template <typename T>
void IncrementCount() {
  count_++;
}

/* Decrements count by 1.
 */
template <typename T>
void DecrementCount() {
  count_--;
}

/* Gets the value of count.
 */
template <typename T>
int GetCount() {
  return count_;
}

