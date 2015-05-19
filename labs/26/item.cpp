/* Filename: item.cpp
 * Author: Derek Lopes
 * Description: Implimentation file for a class to handle items and their properties.
 */

#include "item.h"


/* Creates a string of the values.
 */
string Item::ToString() {
  stringstream ss;
  ss.setf(std::ios::showpoint | std::ios::fixed);
  ss.precision(2);
  ss << name_ << ", $" << value_;
  return ss.str();
}

