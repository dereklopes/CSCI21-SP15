/* 
 * File Name: dynamic_string_array.h
 * Author: Derek Lopes
 * Sources: Luke Sathrum, Absolute C++ by Walter Savich
 */

#ifndef DYNAMICSTRING_LOPES
#define DYNAMICSTRING_LOPES

#include <iostream>
#include <sstream>

using std::ostream;
using std::string;
using std::stringstream;

class DynamicStringArray {
 public:
  /* Default constructor to initialize the array to size 10 and elements to NULL
   */
  DynamicStringArray();
 
  /* Constructor to initialize the array to provided size and elements to NULL.
   * Defaults to size 10 if parameter is invalid.
   * @param unsigned int - size the array should be initialized
   */
  DynamicStringArray(unsigned int size);

  /* Destructor to free all memory allocated to the arrays and strings.
   */
  ~DynamicStringArray();

  /* Returns a pointer to the string at the location provided.
   * If the location is invalid, throws "Invalid Location".
   * @param unsigned int - the location to find the string
   * @return string* - pointer to the string at provided location
   */
  string* At(unsigned int location);

  /* Returns a pointer to the first string in the array.
   * Throws "Array Empty" if the array is empty.
   * @return string* - pointer to the first string in the array.
   */
  string* GetFirst();

  /* Returns a pointer to the last string in the array.
   * Throws "Array Empty" if the array is empty.
   * @return string* - pointer to the last string in the array.
   */
  string* GetLast();

  /* Adds the provided string to the front of the array.
   * If the array is full, the capacity is increased first.
   * @param string* - string to add to the array
   */
  void AddFront(string* to_add);

  /* Adds the provided string to the back of the array.
   * If the array is full, the capacity is increased frist.
   * @param string* - string to add to the array
   */
  void AddBack(string* to_add);

  /* Deletes the first element in the array.
   * If the array is empty, the string "Array Empty" is thrown.
   */
  void DeleteFront();

  /* Deletes the last element in the array.
   * If the array is empty, the string "Array Empty" is thrown.
   */
  void DeleteBack();

  /* Const function that gets the current size of the array.
   * @return unsigned int - the current size of the array
   */
  unsigned int GetSize() const;
  
  /* Const function that gets the current maximum capacity of the array.
   * @return unsigned int - the maximum capacity of the array
   */
  unsigned int GetCapacity() const;

  /* Const function. Checks to see if the array is empty.
   * @return bool - returns true if array is empty (size 0)
   */
  bool Empty() const;
  
  /* Deletes all of the strings in the array and sets size to 0.
   */
  void Clear();

  /* Sorts the array alphabetically A-Z, case insensitive.
   * @uses ToUpper()
   */
  void Sort();

  /* Overloaded Friend Operator for << to output a comma separated list of the strings
   */
  friend const ostream& operator <<(ostream&, const DynamicStringArray&);
 private:
  /* Increases the capacity by 10.
   */
  void IncreaseCapacity();

  /* Takes a string and returns that string with all uppercase letters.
   * @param string - the string to be capitalized
   */
  void ToUpper(string word);

  string* string_array = NULL;

  unsigned int max_capacity;

  unsigned int size;
};

#endif  // DYNAMICSTRING_LOPES
