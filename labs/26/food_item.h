/* Filename: food_item.h
 * Author: Derek Lopes
 * Description: Header file for a class to handle items and their properties.
 */

#ifndef FOODITEM_DLOPES
#define FOODITEM_DLOPES

#include "item.h"

using std::string;

class FoodItem : public Item {
 public:
  /* Constructor. Initializes FoodItem variables and Item variables.
   */
  FoodItem(string name = "fooditem", unsigned int value = 0,
           unsigned int calories = 0, string unit_of_measure = "nounits",
           double units = 0)
     : Item(name, value), calories_(calories),
       unit_of_measure_(unit_of_measure), units_(units) { }

  /* Virtual destructor. Does nothing.
   */
  virtual ~FoodItem() { }

  /* Accessor for calories.
   */
  unsigned int calories() {
    return calories_;
  }

  /* Accessor for unit of meaure.
   */
  string unit_of_measure() {
    return unit_of_measure_;
  }

  /* Accessor for units.
   */
  double units() {
    return units_;
  }

  /* Mutator for calories.
   */
  void set_calories(unsigned int calories) {
    calories_ = calories;
  }

  /* Mutator for unit of measure.
   */
  void set_unit_of_measure(string unit_of_measure) {
    unit_of_measure_ = unit_of_measure;
  }

  /* Mutator for units.
   */
  void set_units(double units) {
    units_ = units;
  }

  /* Creates a string of the values.
   */
  string ToString();

 private:
  unsigned int calories_;
  string unit_of_measure_;
  double units_;
};

#endif  // FOODITEM_DLOPES
