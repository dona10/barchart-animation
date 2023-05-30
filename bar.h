// This header file contains bar class. Each bar consist of name, data value and 
// category

#include <iostream>
#include <string>
//#include "myrandom.h" // used in graders, do not remove

using namespace std;

class Bar {
 private:
    string name, category;
    int value;

 public:

    // This is the default construtor for the class Bar
    Bar() {
        name = "";
        category = "";
        value = 0;
    }

    // This is the parameterized constructor for the class Bar.
    // This takes in name, value and category as parameters.
    Bar(string name, int value, string category) {  
        this->name = name;
        this->value = value;
        this->category = category;
    }

    // destructor for the class Bar which runs automatically
    virtual ~Bar() {
    }

    // Accessor function which returns name
	  string getName() {
        return name;  
	  }

    // Accessor function which returns value
	  int getValue() {
        return value;    
	  }

    // Accessor function which returns category
	  string getCategory() {
        return category; 
	  }

    // operator overloading for < operator
    // returns true is the value of the first bar is less than the 
    // value of the second bar
	  bool operator<(const Bar &other) const {
        return (value < other.value);  
	  }

    // operator overloading for <= operator
    // returns true is the value of the first bar is less or equal to the 
    // value of the second bar
	  bool operator<=(const Bar &other) const {
        return (value <= other.value);  
	  }

    // operator overloading for > operator
    // returns true is the value of the first bar is greater than the 
    // value of the second bar
	  bool operator>(const Bar &other) const {
        return (value > other.value);  
	  }

    // operator overloading for >= operator
    // returns true is the value of the first bar is greater or equal to the 
    // value of the second bar
	  bool operator>=(const Bar &other) const {
        return (value >= other.value);  
	  }
};