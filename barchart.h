// This header file contains the class BarChart
// It aggregates the information for each of the frames

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
//#include "myrandom.h" // used in graders, do not remove
#include "bar.h"

using namespace std;

const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
// const string RESET("\033[0m");

//
// NOTE: COMMENT AND UNCOMMENT AS NEEDED BASED ON YOUR TERMINAL
//
// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
// const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

class BarChart {
private:
  Bar *bars; 
  int capacity;
  int size;
  string frame;

  // helper function for overloading operator []
  Bar& at(int i)
  {
    if (i < 0 || i >= size)
    {
      throw out_of_range("ourvector: i out of bounds");
    }
    return bars[i];
  }

  // helper function for the graph function
  // runs only when there is no value in the colorMap
  void noColor (ostream &output, int lenMax, int i, int maxValue) {
    string color = "\033[1;37m";
    string barstr = "";
    double lenBox = (bars[i].getValue() * lenMax) / maxValue;
    for (int j = 0; j < lenBox; j++) 
      barstr += BOX;
    output << color << barstr << ' ' << bars[i].getName() << ' ' << bars[i].getValue() << endl;
  }

  // helper function for the graph function
  // runs only when there is a colorMap
  void withColor (ostream &output, int lenMax, int i, int maxValue, map<string, string> colorMap) {
    for (auto x : colorMap) {
      if (bars[i].getCategory() == x.first)
      {
        string color = x.second;
        string barstr = "";
        double lenBox = ((double)bars[i].getValue() * (double)lenMax) /(double)maxValue;
        for (int j = 0; j < lenBox; j++) 
          barstr += BOX;
        output << color << barstr << ' ' << bars[i].getName() << ' ' << bars[i].getValue() << endl;
      }
    }
}

public:

  // default constructor for the BarChart class
  BarChart() {
    capacity = 0;
    size = 0;
    frame = "";
    bars = nullptr;
  }

  // parameterized constructor for class BarChart
  // Parameter passed determines the number of bars.
  BarChart(int n) {
    while (n < 0) {
      cout << "Enter capacity greater than 0" << endl;
      cin >> n;
    }
    capacity = n;
    bars = new Bar[n];
    size = 0;
    frame = "";
  }

  // copy constructor called when BarChart is passed as an parameter
  BarChart(const BarChart &other) {
    this->bars = new Bar[other.capacity];
    this->capacity = other.capacity;
    this->size = other.size;
    this->frame = other.frame;
    for (int i =0; i < size; i++)
      this->bars[i] = other.bars[i];
  }
  
  // overload = operator
  // to assign one BarChart into another
  BarChart &operator=(const BarChart &other) {
    if (this == &other)
      return *this;

    delete[] bars;

    this->bars = new Bar[other.capacity];
    this->size = other.size;
    this->capacity = other.capacity;
    this->frame = other.frame;

    for (int i = 0; i < other.size; ++i)
      this->bars[i] = other.bars[i];

    return *this;
  }

  // clear function frees memory and resets all private member variables 
  // to default values.
  void clear() {
    delete[] bars;
    size = 0;
    capacity = 0;
    bars = nullptr;
    frame = "";
  }

  // destructor for the BarCHart class
  // Called automatically by C++ to free the memory associated by the
  // BarChart.
  virtual ~BarChart() {
    if (bars != nullptr)
      delete[] bars;
  }

  // Mutator function to initialize the variable frame
  void setFrame(string frame) { 
    this->frame = frame; 
  }

  // Accessor function which returns the frame of the BarChart object.
  string getFrame() { 
    return frame;
  }

  // The addBar funcion adds a Bar to the BarChart
  //  and returns true if successful or else false
  bool addBar(string name, int value, string category) {
    if (size < capacity) {
      bars[size] = Bar(name, value, category);
      size = size + 1;
      return true;
    }
    return false;
  }

  // Accessor function which returns the size (the number of bars)
  int getSize() {
    return size; 
  }

  // overloading operator[]
  // Returns Bar element in BarChart.
  Bar &operator[](int i) { 
    return at(i); 
  }

  // dump function for printing the BarChart object.
  void dump(ostream &output) {
    sort(bars, bars + size, greater<Bar>());
    output << "frame: " << getFrame() << endl;
    for (int i = 0; i < size; i++) {
      output << bars[i].getName() << " ";
      output << bars[i].getValue() << " ";
      output << bars[i].getCategory();
      output << endl;
    }
  }

  // graph function for printing out the bar.
  void graph(ostream &output, map<string, string> &colorMap, int top) {
    sort(bars, bars + size, greater<Bar>());
    int lenMax = 60;
    int maxValue = bars[0].getValue();
    if (size < top)
      top = size;
    for (int i = 0; i < top; i++) {
      if (colorMap.size() == 0)
      {
        noColor(output, lenMax, i, maxValue);
      }
      else
      {
        withColor(output, lenMax, i, maxValue, colorMap);
      }    
    } 
  }
};