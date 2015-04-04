/*
 * Name        : assignment_3_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class DynamicStringArray.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include <iostream>
#include <sstream>
#include <streambuf>
#include "dynamic_string_array.h"
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void Test(bool test, string more_info = "");
void UnitTest();
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 0;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // START DEBUGGING CODE

  // END DEBUGINH CODE
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;

  // Tests
  cout << "\n*****Constructor*****\n";
  DynamicStringArray list;
  Test(list.GetSize() == 0, "GetSize()");
  Test(list.GetCapacity() == 10, "GetCapacity()");
  Test(list.ToString() == "", "ToString()");
  Test(list.Empty() == true, "Empty()");

  try {
    list.At(0);
  } catch (const string &e) {
    Test(e == "Invalid Location", "At(0) EXCEPTION HANDLING");
  }

  try {
    list.GetFirst();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetFirst() EXCEPTION HANDLING");
  }

  try {
    list.GetLast();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetLast() EXCEPTION HANDLING");
  }

  try {
    list.DeleteFront();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteFront() EXCEPTION HANDLING");
  }

  try {
    list.DeleteBack();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteBack() EXCEPTION HANDLING");
  }

  cout << "\n*****Member Functions with 1 Item*****\n";
  list.AddFront(new string("Hello"));
  Test(list.GetSize() == 1, "AddFront(\"Hello\") && GetSize()");
  Test(list.GetCapacity() == 10, "GetCapacity()");
  Test(list.ToString() == "Hello", "ToString()");
  Test(list.Empty() == false, "Empty()");
  try {
    list.At(1);
  } catch (const string &e) {
    Test(e == "Invalid Location", "At(1) EXCEPTION HANDLING");
  }
  Test(*list.At(0) == "Hello", "At(0)");
  Test(*list.GetFirst() == "Hello", "GetFirst()");
  Test(*list.GetLast() == "Hello", "GetLast()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****Changing \"Hello\" to \"Goodbye\"*****\n";
  *list.At(0) = "Goodbye";
  Test(list.GetSize() == 1, "GetSize()");
  Test(list.GetCapacity() == 10, "GetCapacity()");
  Test(list.ToString() == "Goodbye", "ToString()");
  Test(*list.At(0) == "Goodbye", "At(0)");
  Test(*list.GetFirst() == "Goodbye", "GetFirst()");
  Test(*list.GetLast() == "Goodbye", "GetLast()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****Testing Deletion*****\n";
  list.DeleteFront();
  Test(list.GetSize() == 0, "DeleteFront() && GetSize()");
  list.AddFront(new string("Hello"));
  list.DeleteBack();
  Test(list.GetSize() == 0, "AddFront(), DeleteBack() && GetSize()");

  cout << "\n*****Member Functions with 2 Items*****\n";
  list.AddFront(new string("Goodbye"));
  list.AddFront(new string("Hello"));
  Test(list.GetSize() == 2,
       "AddFront(\"Goodbye\"), AddFront(\"Hello\"), && GetSize()");
  Test(list.GetCapacity() == 10, "GetCapacity()");
  Test(list.ToString() == "Hello, Goodbye", "ToString()");
  Test(list.Empty() == false, "Empty()");
  Test(*list.At(1) == "Goodbye", "At(0)");
  Test(*list.GetFirst() == "Hello", "GetFirst()");
  Test(*list.GetLast() == "Goodbye", "GetLast()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****Testing Deletion*****\n";
  list.DeleteBack();
  Test(list.GetSize() == 1, "DeleteBack() && GetSize()");
  Test(list.ToString() == "Hello", "ToString()");
  list.DeleteFront();
  Test(list.GetSize() == 0, "DeleteFront() && GetSize()");
  Test(list.ToString() == "", "ToString()");

  cout << "\n*****Member Functions with 10 Items*****\n";
  stringstream ss;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      ss << "StRiNg #" << i + 1;
      list.AddFront(new string(ss.str()));
    } else {
      ss << "sTrInG #" << i + 1;
      list.AddBack(new string(ss.str()));
    }
    ss.str("");
  }
  Test(list.GetSize() == 10, "Alternating AddFront && AddBack(), && GetSize()");
  Test(list.GetCapacity() == 10, "GetCapacity()");
  Test(list.ToString() == "StRiNg #9, StRiNg #7, StRiNg #5, StRiNg #3, StRiNg #"
      "1, sTrInG #2, sTrInG #4, sTrInG #6, sTrInG #8, sTrIn"
      "G #10",
       "ToString()");
  Test(list.Empty() == false, "Empty()");
  Test(*list.At(3) == "StRiNg #3", "At(3)");
  Test(*list.At(6) == "sTrInG #4", "At(6)");
  try {
    list.At(10);
  } catch (const string &e) {
    Test(e == "Invalid Location", "At(10) EXCEPTION HANDLING");
  }
  Test(*list.GetFirst() == "StRiNg #9", "GetFirst()");
  Test(*list.GetLast() == "sTrInG #10", "GetLast()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  list.Sort();
  Test(list.ToString() == "StRiNg #1, sTrInG #10, sTrInG #2, StRiNg #3, sTrInG "
      "#4, StRiNg #5, sTrInG #6, StRiNg #7, sTrInG #8, StRi"
      "Ng #9",
       "Sort() && ToString()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****Testing Deletion*****\n";
  for (unsigned int i = 0; i < 5; i++) {
    list.DeleteBack();
    list.DeleteFront();
  }

  Test(list.GetSize() == 0, "DeleteBack() / DeleteFront() x 10 && GetSize()");
  Test(list.ToString() == "", "ToString()");

  try {
    list.At(0);
  } catch (const string &e) {
    Test(e == "Invalid Location", "At(0) EXCEPTION HANDLING");
  }

  try {
    list.GetFirst();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetFirst() EXCEPTION HANDLING");
  }

  try {
    list.GetLast();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetLast() EXCEPTION HANDLING");
  }

  try {
    list.DeleteFront();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteFront() EXCEPTION HANDLING");
  }

  try {
    list.DeleteBack();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteBack() EXCEPTION HANDLING");
  }

  cout << "\n*****Member Functions with 31 Items*****\n";

  for (int i = 0; i < 31; i++) {
    if (i % 2 == 0) {
      ss << "StRiNg #" << i + 1;
      list.AddFront(new string(ss.str()));
    } else {
      ss << "sTrInG #" << i + 1;
      list.AddBack(new string(ss.str()));
    }
    ss.str("");
  }
  Test(list.GetSize() == 31, "Alternating AddFront && AddBack(), && GetSize()");
  Test(list.GetCapacity() == 40, "GetCapacity()");
  Test(
      list.ToString()
          == "StRiNg #31, StRiNg #29, StRiNg #27, StRiNg #25, StRiNg #23, StRiN"
              "g #21, StRiNg #19, StRiNg #17, StRiNg #15, StRiNg #13, StRiNg #1"
              "1, StRiNg #9, StRiNg #7, StRiNg #5, StRiNg #3, StRiNg #1, sTrInG"
              " #2, sTrInG #4, sTrInG #6, sTrInG #8, sTrInG #10, sTrInG #12, sT"
              "rInG #14, sTrInG #16, sTrInG #18, sTrInG #20, sTrInG #22, sTrInG"
              " #24, sTrInG #26, sTrInG #28, sTrInG #30",
      "ToString()");
  Test(list.Empty() == false, "Empty()");
  Test(*list.At(3) == "StRiNg #25", "At(3)");
  Test(*list.At(29) == "sTrInG #28", "At(29)");
  try {
    list.At(31);
  } catch (const string &e) {
    Test(e == "Invalid Location", "At(31) EXCEPTION HANDLING");
  }
  Test(*list.GetFirst() == "StRiNg #31", "GetFirst()");
  Test(*list.GetLast() == "sTrInG #30", "GetLast()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  list.Sort();
  Test(list.ToString() == "StRiNg #1, sTrInG #10, StRiNg #11, sTrInG #12, StRiN"
      "g #13, sTrInG #14, StRiNg #15, sTrInG #16, StRiNg #17, sTrInG #18, StRiN"
      "g #19, sTrInG #2, sTrInG #20, StRiNg #21, sTrInG #22, StRiNg #23, sTrInG"
      " #24, StRiNg #25, sTrInG #26, StRiNg #27, sTrInG #28, StRiNg #29, StRiNg"
      " #3, sTrInG #30, StRiNg #31, sTrInG #4, StRiNg #5, sTrInG #6, StRiNg #7,"
      " sTrInG #8, StRiNg #9",
       "Sort() && ToString()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****Member Functions with 1000 Items*****\n";
  for (int i = 0; i < 969; i++)
    list.AddFront(new string("A"));
  Test(list.GetSize() == 1000, "AddFront(Adding 969 More Items) / GetSize()");
  Test(list.GetCapacity() == 1000, "GetCapacity()");

  cout << "\n*****Clearing All Items*****\n";
  list.Clear();
  Test(list.GetSize() == 0, "Clear() && GetSize()");
  Test(list.GetCapacity() == 1000, "GetCapacity()");
  Test(list.ToString() == "", "ToString()");
  Test(list.Empty() == true, "Empty()");

  try {
    list.At(0);
  } catch (const string &e) {
    Test(e == "Invalid Location", "At(0) EXCEPTION HANDLING");
  }

  try {
    list.GetFirst();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetFirst() EXCEPTION HANDLING");
  }

  try {
    list.GetLast();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetLast() EXCEPTION HANDLING");
  }

  try {
    list.DeleteFront();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteFront() EXCEPTION HANDLING");
  }

  try {
    list.DeleteBack();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteBack() EXCEPTION HANDLING");
  }

  cout << "\n*****Member Functions with 1 Item*****\n";
  list.AddFront(new string("Hello"));
  Test(list.GetSize() == 1, "AddFront(\"Hello\") && GetSize()");
  Test(list.GetCapacity() == 1000, "GetCapacity()");
  Test(list.ToString() == "Hello", "ToString()");
  Test(list.Empty() == false, "Empty()");
  try {
    list.At(1);
  } catch (const string &e) {
    Test(e == "Invalid Location", "At(1) EXCEPTION HANDLING");
  }
  Test(*list.At(0) == "Hello", "At(0)");
  Test(*list.GetFirst() == "Hello", "GetFirst()");
  Test(*list.GetLast() == "Hello", "GetLast()");
  cout << "Testing Overloaded <<:\n" << list << endl;

  // Tests
  cout << "\n*****Overloaded Constructor*****\n";
  DynamicStringArray list2(0);
  Test(list2.GetSize() == 0, "DynamicStringArray(0) && GetSize()");
  Test(list2.GetCapacity() == 10, "GetCapacity()");
  Test(list2.ToString() == "", "ToString()");
  Test(list2.Empty() == true, "Empty()");

  try {
    list2.At(0);
  } catch (const string &e) {
    Test(e == "Invalid Location", "At(0) EXCEPTION HANDLING");
  }

  try {
    list2.GetFirst();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetFirst() EXCEPTION HANDLING");
  }

  try {
    list2.GetLast();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetLast() EXCEPTION HANDLING");
  }

  try {
    list2.DeleteFront();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteFront() EXCEPTION HANDLING");
  }

  try {
    list2.DeleteBack();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteBack() EXCEPTION HANDLING");
  }

  DynamicStringArray list3(758);
  Test(list3.GetSize() == 0, "DynamicStringArray(758) && GetSize()");
  Test(list3.GetCapacity() == 758, "GetCapacity()");
  Test(list3.ToString() == "", "ToString()");
  Test(list3.Empty() == true, "Empty()");

  try {
    list3.At(0);
  } catch (const string &e) {
    Test(e == "Invalid Location", "At(0) EXCEPTION HANDLING");
  }

  try {
    list3.GetFirst();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetFirst() EXCEPTION HANDLING");
  }

  try {
    list3.GetLast();
  } catch (const string &e) {
    Test(e == "Array Empty", "GetLast() EXCEPTION HANDLING");
  }

  try {
    list3.DeleteFront();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteFront() EXCEPTION HANDLING");
  }

  try {
    list3.DeleteBack();
  } catch (const string &e) {
    Test(e == "Array Empty", "DeleteBack() EXCEPTION HANDLING");
  }

  // Testing Destructors
  cout << "\n*****Testing Destructor*****" << endl
       << "If the next line is the \"END Testing Destructor\" then you passed!"
       << endl;
  DynamicStringArray *dynamic_list = new DynamicStringArray();
  delete dynamic_list;
  dynamic_list = new DynamicStringArray();
  for (int i = 0; i < 50; i++)
    dynamic_list->AddFront(new string("testing"));
  delete dynamic_list;
  cout << "*****END Testing Destructor*****" << endl << endl;
  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "Unit Test Complete!\n";
  cout << string(40, '-') << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  ut_total++;
  if (test) {
    cout << "PASSSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED  TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << test_number << " " << more_info << "!" << endl;
  test_number++;
}

void OutputFailedTests() {
  if (failed_tests.size()) {
    cout << "Failed test number(s): ";
    for (unsigned int i = 0; i < failed_tests.size() - 1; i++)
      cout << failed_tests.at(i) << ", ";
    cout << failed_tests.at(failed_tests.size() - 1) << endl;
  }
}

