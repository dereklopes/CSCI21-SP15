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
  BSTreeT();

  /* Destructor. Calls the clear function.
   */
  ~BSTreeT();

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
  BSTNodeT<T>* Get(T value);

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
  BSTNodeT<T>* root_;
  unsigned int size_;

  /* Inserts the value into the tree starting at the root provided
   * Increments count if the value is already present
   * @param T - value to insert into the tree
   * @param BSTNode*& - the root to start at
   * @return unsigned int - the number of times that value has been inserted 
   */
  unsigned int Insert(T value, BSTNodeT<T>*& root);

  /* Searches the tree for the given value.
   * @param T - the value to search for
   * @return bool - true if the value was found
   */
  bool Exists(T value, BSTNodeT<T>* root);

  /* Clears the tree at the root provided.
   * @param BSTNODE*& - the root to clear of the tree
   */
  void Clear(BSTNodeT<T>*& root);

  /* Creates a string of the tree values in order
   * @param BSTNode* - the root to start at
   * @return string - the values of the tree in order
   */
  string ToStringForwards(BSTNodeT<T>* root, T last_value);

  /* Creates a string of the tree values in reverse order
   * @param BSTNode* - the root to start at
   * @return string - the values of the tree in reverse order
   */
  string ToStringBackwards(BSTNodeT<T>* root, T first_value);

  /* Deletes the given value in the given tree.
   * Decrements count if the value exists.
   * @param T - the value to remove
   * @param BSTNode*& - the root of the tree to search
   * @return int - count, or -1 if it does not exist
   */
  int Remove(T value, BSTNodeT<T>*& root);

  /* Gets a pointer to the node containing the provided value.
   * @param T - the value to search for
   * @return BSTNodeT* - a pointer to the node searched for, NULL if not found 
   */
  BSTNodeT<T>* Get(T value, BSTNodeT<T>* root);
};

// PUBLIC MEMEBER FUNCTIONS

/* Default constructor. Sets root to NULL and size to 0.
 */
template <typename T>
BSTreeT<T>::BSTreeT()
  : root_(NULL), size_(0) { }

/* Destructor. Calls the clear function.
 */
template <typename T>
BSTreeT<T>::~BSTreeT() {
  Clear();
}

/* Gets the size of the tree.
 * @return unsigned int - the size of the tree
 */
template <typename T>
unsigned int BSTreeT<T>::GetSize() const {
  return size_;
}

/* Clears the entire tree. Calls the private clear funciton.
 */
template <typename T>
void BSTreeT<T>::Clear() {
  Clear(root_);
}

/* Inserts a value into the tree. Calls the private insert function.
 * @param T - the value to add to the tree
 * @return bool - true if the value was inserted
 */
template <typename T>
unsigned int BSTreeT<T>::Insert(T value) {
  return Insert(value, root_);
}

/* Searches the tree for the given value.
 * @param T - the value to search for
 * @return bool - true if the value was found
 */
template <typename T>
bool BSTreeT<T>::Exists(T value) {
  return Exists(value, root_);
}

/* Calls the private remove function
 * @param T - the value to remove
 * @return int - count, or -1 if it does not exist
 */
template <typename T>
int BSTreeT<T>::Remove(T value) {
  if (root_ == NULL)
    return (-1);
  return Remove(value, root_);
}

/* Calls the private get function 
 * @param T - the value to search for
 * @return BSTNodeT* - a pointer to the node searched for, NULL if not found 
 */
template <typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T value) {
  return Get(value, root_);
}

/* Returns a string of the values in order
 * The values are separated by a comma
 * @return string - the values of the tree in order
 */
template <typename T>
string BSTreeT<T>::ToStringForwards() {
  // Finds the last value in the tree so that no extra comma is added
  T last_value;
  if (root_ == NULL) {
    return string(""); 
  } else {
    BSTNodeT<T> *root = root_;
    while (root->GetRightChild() != NULL) {
      root = root->GetRightChild();
    }
    last_value = root->GetContents();
  }
  return ToStringForwards(root_, last_value);
}

/* Returns a string of the values in reverse order
 * The values are separated by a comma
 * @return string - the values of the tree in reverse order
 */
template <typename T>
string BSTreeT<T>::ToStringBackwards() {
  // Finds the first value in the tree so that no extra comma is added
  T first_value;
  if (root_ == NULL) {
    return string(""); 
  } else {
    BSTNodeT<T> *root = root_;
    while (root->GetLeftChild() != NULL) {
      root = root->GetLeftChild();
    }
    first_value = root->GetContents();
  }
  return ToStringBackwards(root_, first_value);
}

// PRIVATE MEMBER FUNCTIONS

/* Inserts the value into the tree starting at the root provided
 * Increments count if the value is already present
 * @param T - value to insert into the tree
 * @param BSTNode*& - the root to start at
 * @return unsigned int - the number of times that value has been inserted 
 */
template <typename T>
unsigned int BSTreeT<T>::Insert(T value, BSTNodeT<T>*& root) {
  if (root == NULL) {
    root = new BSTNodeT<T>(value);
    size_++;
    return root.GetCount();
  }
  if (root->GetContents() == value) {
    root.IncrementCount();
    return root.GetCount();
  }
  if (root->GetContents() > value) {
    return Insert(value, root->GetLeftChild());
  }
  if (root->GetContents() < value) {
    return Insert(value, root->GetRightChild());
  }
  return (-1);  // for error checking, should never reach this
}

/* Clears the tree at the root provided.
 * @param BSTNODE*& - the root to clear of the tree
 */
template <typename T>
void BSTreeT<T>::Clear(BSTNodeT<T>*& root) {
  if (root == NULL)
    return;
  Clear(root->GetLeftChild());
  Clear(root->GetRightChild());
  delete root;
  size_--;
}

/* Creates a string of the tree values in order
 * @param BSTNode* - the root to start at
 * @return string - the values of the tree in order
 */
template <typename T>
string BSTreeT<T>::ToStringForwards(BSTNodeT<T>* root, T last_value) {
  if (root == NULL)
    return string("");
  stringstream ss;
  if (root->GetContents() == last_value) {
    ss << root->GetContents();
  } else {
    ss << InOrder(root->GetLeftChild());
    ss << root->GetContents() << " ";
    ss << InOrder(root->GetRightChild());
  } 
  return ss.str();
}

/* Creates a string of the tree values in reverse order
 * @param BSTNode* - the root to start at
 * @return string - the values of the tree in reverse order
 */
template <typename T>
string BSTreeT<T>::ToStringBackwards(BSTNodeT<T>* root, T first_value) {
  if (root == NULL)
    return string("");
  stringstream ss;
  if (root->GetContents() == first_value) {
    ss << root->GetContents();
  } else {
    ss << InOrder(root->GetRightChild());
    ss << root->GetContents() << " ";
    ss << InOrder(root->GetLeftChild());
  } 
  return ss.str();
}

/* Deletes the given value in the given tree.
 * Decrements count if the value exists.
 * @param T - the value to remove
 * @param BSTNode*& - the root of the tree to search
 * @return int - count, or -1 if it does not exist
 */
template <typename T>
int BSTreeT<T>::Remove(T value, BSTNodeT<T>*& root) {
  if (value == root->GetContents()) {
    if (root->GetCount() > 0) {
      root->DecrementCount();
      return root->GetCount();
    }
    if (root->GetLeftChild() == NULL && root->GetRightChild() == NULL) {
      delete root;
      root = NULL;
      size_--;
      return true;
    } else if (root->GetLeftChild() == NULL) {
      BSTNodeT<T>* temp = root;
      root = root->GetRightChild();
      delete temp;
      size_--;
      return true;
    } else if (root->GetRightChild() == NULL) {
      BSTNodeT<T>* temp = root;
      root = root->GetLeftChild();
      delete temp;
      size_--;
      return true;
    } else {
      root->SetContents(FindMin(root->GetRightChild()));
      return Remove(root->GetContents(), root->GetRightChild());
    }
  } else if (value > root->GetContents() && root->GetRightChild() != NULL) {
    return Remove(value, root->GetRightChild());
  } else if (value < root->GetContents() && root->GetLeftChild() != NULL) {
    return Remove(value, root->GetLeftChild());
  } else {
    return (-1);
  }
}


/* Gets a pointer to the node containing the provided value.
 * @param T - the value to search for
 * @return BSTNodeT* - a pointer to the node searched for, NULL if not found 
 */
template <typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T value, BSTNodeT<T>* root) {
  if (value == root->GetContents())
    return root;
  if (root->GetLeftChild() == NULL && root->GetRightChild() == NULL) {
    return NULL;
  } else if (value < root->GetContents() && root->GetLeftChild() != NULL) {
    return Get(value, root->GetLeftChild());
  } else if (value > root->GetContents() && root->GetRightChild() != NULL) {
    return Get(value, root->GetRightChild());
  } else {
    return NULL;
  }
}


#endif  // BSTREET_LOPES
