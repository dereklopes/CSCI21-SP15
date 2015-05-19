/* Filename: magic_item.h
 * Author: Derek Lopes
 * Description: Header file for a class to handle items and their properties.
 */

#ifndef MAGICITEM_DLOPES
#define MAGICITEM_DLOPES

#include "item.h"

class MagicItem : public Item {
 public:
  /* Constructor. Initializes all Magic Item variables and Item variables.
   */
  MagicItem(string name = "magicitem", unsigned int value = 0,
            string description = "no description",
            unsigned int mana_required = 0)
    : Item(name, value), description_(description),
      mana_required_(mana_required) { }

  /* Virtal desctructor. Does nothing.
   */
  virtual ~MagicItem() { }

  /* Accessor for description.
   */
  string description() {
    return description_;
  }

  /* Accessor for mana required.
   */
  unsigned int mana_required() {
    return mana_required_;
  }

  /* Mutator for description.
   */
  void set_description(string description) {
    description_ = description;
  }

  /* Mutator for mana required.
   */
  void set_mana_required(unsigned int mana_required) {
    mana_required_ = mana_required;
  }

  /* Creates a string of the values.
   */
  string ToString();

 private:
  string description_;
  unsigned int mana_required_;
};

#endif  // MAGICITEM_DLOPES
