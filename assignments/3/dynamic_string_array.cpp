/* 
 * File Name: dynamic_string_array.cpp
 * Author: Derek Lopes
 * Sources: Luke Sathrum, Absolute C++ by Walter Savich
 */

#include "dynamic_string_aarray.cpp"

/* Default constructor to initialize the array to size 10 and elements to NULL
 * Sets amount of elements to 0.
 */
DynamicStringArray() {
  max_capacity = 10;
  string_array = new string[max_capacity];    
  size = 0;
  for (unsigned int i = 0; i < max_capacity; i++) {
    string_array[i] = NULL;
  }
} 
/* Constructor to initialize the array to provided size and elements to NULL.
 * Defaults to size 10 if parameter is invalid.
 * @param unsigned int - size the array should be initialized
 */
DynamicStringArray(unsigned int size) {
  max_capacity = size;
  string_array = new string[max_capacity];    
  size = 0;
  for (unsigned int i = 0; i < max_capacity; i++) {
    string_array[i] = NULL;
  }
}

/* Destructor to free all memory allocated to the arrays and strings.
 */
~DynamicStringArray() {
  size = 0;
  for (unsigned int i = 0; i < max_capacity; i++) {
    string_array[i] = NULL;
  }
  delete[] string_array;
}

/* Returns a pointer to the string at the location provided.
 * If the location is invalid, throws "Invalid Location".
 * @param unsigned int - the location to find the string
 * @return string* - pointer to the string at provided location
 */
string* At(unsigned int location) {
  if (location > size || location < 0)
    throw "Invallid Location";
  return &string_array[location];
}

/* Returns a pointer to the first string in the array.
 * Throws "Array Empty" if the array is empty.
 * @return string* - pointer to the first string in the array.
 */
string* GetFirst() {
  if (size != 0)
    throw "Invallid Location";
  return &string_array[0];
}

/* Returns a pointer to the last string in the array.
 * Throws "Array Empty" if the array is empty.
 * @return string* - pointer to the last string in the array.
 */
string* GetLast() {
  if (size != 0)
    throw "Invallid Location";
  return &string_array[size];
}

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
unsigned int GetCpacity() const;

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
const ostream& operator <<(ostream& out, const DynamicStringArray& array) {
  
  return out;
}
