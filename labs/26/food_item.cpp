/* Filename: food_item.h
 * Author: Derek Lopes
 * Description: Header file for a class to handle items and their properties.
 */

#include "food_item.h"

/* Creates a string of the values.
 */
string FoodItem::ToString() {
  stringstream ss;
  ss.setf(std::ios::showpoint | std::ios::fixed);
  ss.precision(2);
  ss << Item::ToString() << ", " << units_ << " " << unit_of_measure_ << ", "
     << calories_ << " calories";
  return ss.str();
}
