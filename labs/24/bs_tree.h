/* Filename: bs_tree.h
 * Author: Derek Lopes
 * Description: Header file for binary search trees
 * Sources: Luke Sathrum
 */

#ifndef BSTREE_LOPES
#define BSTREE_LOPES

#include "bst_node.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class BSTree {
 public:
  /* Default constructor. Sets root to NULL and size to 0.
   */
  BSTree();

  /* Destructor. Calls the clear function.
   */
  ~BSTree();

  /* Inserts a value into the tree. Calls the private insert function.
   * @param int - the value to add to the tree
   * @return bool - true if the value was inserted
   */
  bool Insert(int value);

  /* Clears the entire tree. Calls the private clear funciton.
   */
  void Clear();

  /* Gets the size of the tree.
   * @return unsigned int - the size of the tree
   */
  unsigned int GetSize() const;

  /* Returns a string of the values in order
   * The values are separated by a space
   * @return string - the values of the tree in order
   */
  string InOrder();

 private:
  BSTNode* root_;
  unsigned int size_;

  /* Inserts the value into the tree starting at the root provided
   * @param int - value to insert into the tree
   * @param BSTNode*& - the root to start at
   * @return bool - true if the value was inserted
   */
  bool Insert(int value, BSTNode*& root);

  /* Clears the tree at the root provided.
   * @param BSTNODE*& - the root to clear of the tree
   */
  void Clear(BSTNode*& root);

  /* Creates a string of the tree values in order
   * @param BSTNode* - the root to start at
   * @return string - the values of the tree in order
   */
  string InOrder(BSTNode* root);
};

#endif  // BSTREE_LOPES
