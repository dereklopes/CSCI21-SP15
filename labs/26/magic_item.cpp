/* Filename: item.h
 * Author: Derek Lopes
 * Description: Header file for a class to handle items and their properties.
 */

#include "magic_item.h"


/* Creates a string of the values.
 */
string MagicItem::ToString() {
  stringstream ss;
  ss.setf(std::ios::showpoint | std::ios::fixed);
  ss.precision(2);
  ss << Item::ToString() << ", " << description_ << ", requires "
     << mana_required_ << " mana";
  return ss.str();
}

