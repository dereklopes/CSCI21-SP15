/* Filename: bs_treet.h
 * Author: Derek Lopes
 * Description: Header file for templated binary search trees
 * Sources: Luke Sathrum
 */

#ifndef BSTREET_LOPES
#define BSTREET_LOPES

#include "bst_nodet.h"
#include <cstddef>  // FOR NULL
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

template <typename T>
class BSTreeT {
 public:
  /* Default constructor. Sets root to NULL and size to 0.
   */
  BSTree();

  /* Destructor. Calls the clear function.
   */
  ~BSTree();

  /* Gets the size of the tree.
   * @return unsigned int - the size of the tree
   */
  unsigned int GetSize() const;

  /* Clears the entire tree. Calls the private clear funciton.
   */
  void Clear();

  /* Inserts a value into the tree. Calls the private insert function.
   * @param T - the value to add to the tree
   * @return bool - true if the value was inserted
   */
  unsigned int Insert(T value);

  /* Searches the tree for the given value.
   * @param T - the value to search for
   * @return bool - true if the value was found
   */
  bool Exists(T value);

  /* Calls the private remove function
   * @param T - the value to remove
   * @return int - count, or -1 if it does not exist
   */
  int Remove(T value);

  /* Calls the private get function 
   * @param T - the value to search for
   * @return BSTNodeT* - a pointer to the node searched for, NULL if not found 
   */
  BSTNodeT* Get(T value);

  /* Returns a string of the values in order
   * The values are separated by a comma
   * @return string - the values of the tree in order
   */
  string ToStringForwards();

  /* Returns a string of the values in reverse order
   * The values are separated by a comma
   * @return string - the values of the tree in reverse order
   */
  string ToStringBackwards();

 private:
  BSTNodeT* root_;
  unsigned int size_;

  /* Inserts the value into the tree starting at the root provided
   * Increments count if the value is already present
   * @param T - value to insert into the tree
   * @param BSTNode*& - the root to start at
   * @return unsigned int - the number of times that value has been inserted 
   */
  unsigned int Insert(T value, BSTNode*& root);

  /* Searches the tree for the given value.
   * @param T - the value to search for
   * @return bool - true if the value was found
   */
  bool Exists(T value, BSTNode* root);

  /* Clears the tree at the root provided.
   * @param BSTNODE*& - the root to clear of the tree
   */
  void Clear(BSTNode*& root);

  /* Creates a string of the tree values in order
   * @param BSTNode* - the root to start at
   * @return string - the values of the tree in order
   */
  string ToStringForwards(BSTNode* root);

  /* Creates a string of the tree values in reverse order
   * @param BSTNode* - the root to start at
   * @return string - the values of the tree in reverse order
   */
  string ToStringBackwards(BSTNode* root);

  /* Deletes the given value in the given tree.
   * Decrements count if the value exists.
   * @param T - the value to remove
   * @param BSTNode*& - the root of the tree to search
   * @return int - count, or -1 if it does not exist
   */
  int Remove(T value, BSTNode*& root);

  /* Searches for the given value in the given tree 
   * @param T - the value to search for
   * @return BSTNodeT* - a pointer to the node searched for, NULL if not found 
   */
  BSTNodeT* Get(T value, BSTNode* root);

  /* Gets a pointer to the node containing the provided value.
   * @param T - the value to search for
   * @return BSTNodeT* - a pointer to the node searched for, NULL if not found 
   */
  BSTNodeT* Get(T value, BSTNodeT* root);
};

#endif  // BSTREET_LOPES
