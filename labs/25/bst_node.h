/* File Name: bst_node.h
 * Author: Derek Lopes
 * Description: Header file for binary search trees
 * Surces: Luke Sathrum
 */

#ifndef BSTNODE_LOPES
#define BSTNODE_LOPES

#include <cstddef>

class BSTNode {
 public:
  /* Default constructor. Sets left and right pointers to NULL and contents to 0.
   */
  BSTNode();

  /* Overloaded constructor. Sets left and right pointers to NULL.
   * Sets the contents to the provided value.
   * @param int - value to set contents of node to
   */
  BSTNode(int value);

  /* Destructor. Sets left and right pointers to NULL.
   */
  ~BSTNode();

  /* Sets the contents of the node.
   * @param int - value to set contents of node to
   */
  void SetContents(int value);

  /* Gets the contents of the node. Const function.
   * @return int - the contents of the node
   */
  int GetContents() const;

  /* Gets a reference to the contents of the node.
   * @return int& - a reference to the contents of the node
   */
  int& GetContents();

  /* Sets the left child node.
   * @param BSTNode* - a pointer to the left child node.
   */
  void SetLeftChild(BSTNode* left_child);

  /* Sets the right child node.
   * @param BSTNode* - a pointer to the right child node.
   */
  void SetRightChild(BSTNode* right_child);

  /* Gets a pointer to the left child.
   * @return BSTNode* - a pointer to the left child node.
   */
  BSTNode* GetLeftChild() const;

  /* Gets a reference to a pointer to the left child.
   * @return BSTNode*& - a reference to the pointer to the left child.
   */
  BSTNode*& GetLeftChild();

  /* Gets a pointer to the right child.
   * @return BSTNode* - a pointer to the right child node.
   */
  BSTNode* GetRightChild() const;

  /* Gets a reference to a pointer to the right child.
   * @return BSTNode*& - a reference to the pointer to the right child.
   */
  BSTNode*& GetRightChild();

 private:
  BSTNode *left_child_, *right_child_;
  int contents_;
};

#endif  // BSTNODE_LOPES

