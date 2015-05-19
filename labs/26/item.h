/* Filename: item.h
 * Author: Derek Lopes
 * Description: Header file for a class to handle items and their properties.
 */

#ifndef ITEM_DLOPES
#define ITEM_DLOPES

#include <sstream>
#include <string>

using std::string;
using std::stringstream;

class Item {
 public:
  /* Constructor. Initializes name and value of the item.
   */
  Item(string name = "item", unsigned int value = 0)
    : name_(name), value_(value) { }

  /* Virtual destructor, does nothing
   */
  virtual ~Item() { }

  /* Accessor for the name attribute.
   */
  string name() {
    return name_;
  }

  /* Accessor for the value attribute.
   */
  unsigned int value() {
    return value_;
  }

  /* Mutator for the name attribute.
   */
  void set_name(string name) {
    name_ = name;
  }

  /* Mutator for the value attribute.
   */
  void set_value(unsigned int value) {
    value_ = value;
  }

  /* Creates a string of the values.
   */
  string ToString();

 private:
  string name_;
  unsigned int value_;
};

#endif  // ITEM_DLOPES
