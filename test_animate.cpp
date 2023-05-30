// This test file tests all the public member functions in Bar.h amnd 
// BarChart.h files

/*#include "barchartanimate.h"
#include <iostream>
#include <sstream>
using namespace std;

// test for the default constructor in class Bar
bool testBarDefaultConstructor() {
  Bar b;
  if (b.getName() != "") {
    cout << "testBarDefaultConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != 0) {
    cout << "testBarDefaultConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "") {
    cout << "testBarDefaultConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarDefaultConstructor: all passed!" << endl;
  return true;
}

// test for the parameterized constructor in class Bar
bool testBarParamConstructor() {
  Bar b("Chicago", 9234324, "US");
  if (b.getName() != "Chicago") {
    cout << "testBarParamConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != 9234324) {
    cout << "testBarParamConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "US") {
    cout << "testBarParamConstructor: getCategory failed" << endl;
    return false;
  }
  Bar c("New York City", 8234324, "US");
  if (c.getName() != "New York City") {
    cout << "testBarParamConstructor: higetName failed" << endl;
    return false;
  } else if (c.getValue() != 8234324) {
    cout << "testBarParamConstructor: getValue failed" << endl;
    return false;
  } else if (c.getCategory() != "US") {
    cout << "testBarParamConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarParamConstructor: all passed!" << endl;
  return true;
}

// test for operator overload <
bool testBarLesser() {
  Bar a("Chicago", 9234324, "US");
  Bar b("New York City", 8234324, "US");
  if ((a < b) != 0) {
    cout << "testBarLesser: failed" << endl;
    return false;
  } else if ((b < a) != 1) {
    cout << "testBarLesser: failed" << endl;
    return false;
  }
  cout << "testBarLesser: all passed!" << endl;
  return true;
}

// test for operator overload >
bool testBarGreater() {
  Bar a("Chicago", 9234324, "US");
  Bar b("New York City", 8234324, "US");
  if ((a > b) != 1) {
    cout << "testBarGreater: failed" << endl;
    return false;
  } else if ((b > a) != 0) {
    cout << "testBarGreater: failed" << endl;
    return false;
  }
  cout << "testBarGreater: all passed!" << endl;
  return true;
}

// test for operator overload <=
bool testBarLesserEqual() {
  Bar a("Chicago", 9234324, "US");
  Bar b("New York City", 8234324, "US");
  if ((a <= b) != 0) {
    cout << "testBarLesserEqual: failed" << endl;
    return false;
  } else if ((b <= a) != 1) {
    cout << "testBarLesserEqual: failed" << endl;
    return false;
  } else if ((b <= b) != 1) {
    cout << "testBarLesserEqual: failed" << endl;
    return false;
  } else if ((a <= a) != 1) {
    cout << "testBarLesserEqual: failed" << endl;
    return false;
  }
  cout << "testBarLesserEqual: all passed!" << endl;
  return true;
}

// test for operator overload >=
bool testBarGreaterEqual() {
  Bar a("Chicago", 9234324, "US");
  Bar b("New York City", 8234324, "US");
  if ((a >= b) != 1) {
    cout << "testBarGreaterEqual: failed" << endl;
    return false;
  } else if ((b >= a) != 0) {
    cout << "testBarGreaterEqual: failed" << endl;
    return false;
  } else if ((b >= b) != 1) {
    cout << "testBarGreaterEqual: failed" << endl;
    return false;
  } else if ((a >= a) != 1) {
    cout << "testBarGreaterEqual: failed" << endl;
    return false;
  }
  cout << "testBarGreaterEqual: all passed!" << endl;
  return true;
}

// test for the default constructor in class BarChart
bool testBarChartDefaultConstructor() {
  BarChart bc;
  if (bc.getFrame() != "") {
    cout << "testBarChartDefaultConstructor: Frame failed" << endl;
    return false;
  } else if (bc.getSize() != 0) {
    cout << "testBarChartDefaultConstructor: size failed" << endl;
    return false;
  } 
  cout << "testBarChartDefaultConstructor: all passed!" << endl;
  return true;
}

// test for the parameterized constructor in class BarChart
bool testBarChartParamConstructor() {
  BarChart bc(10);
  if (bc.getFrame() != "") {
    cout << "testBarChartParamConstructor: Frame failed" << endl;
    return false;
  } else if (bc.getSize() != 0) {
    cout << "testBarChartParamConstructor: size failed" << endl;
    return false;
  } 
  cout << "testBarChartParamConstructor: all passed!" << endl;
  return true;
}

// test for the copy constructor in class BarChart
bool testBarChartCopyConstructor() {
  BarChart bc(10);
  BarChart bcCopy(bc);
  if (bcCopy.getFrame() != "") {
    cout << "testBarChartCopyConstructor: Frame failed" << endl;
    return false;
  } else if (bcCopy.getSize() != 0) {
    cout << "testBarChartCopyConstructor: size failed" << endl;
    return false;
  } 
  cout << "testBarChartCopyConstructor: all passed!" << endl;
  return true;
}

// test for operator =
bool testEqual() {
  BarChart bc1;
  bc1.setFrame("1520");
  bc1.addBar("Chicago", 300, "US");
  BarChart bc2;
  bc2 = bc1;
  if (bc2.getFrame() != "1520") {
    cout << "testEqual: Frame failed" << endl;
    return false;
  } 
  cout << "testEqual: all passed!" << endl;
  return true;
}

//test for the clear function which is a member of the BarChart class
bool testBarChartClear() {
  BarChart bc(10);
  bc.clear();
  if (bc.getFrame() != "") {
    cout << "testBarChartClear: Frame failed" << endl;
    return false;
  } else if (bc.getSize() != 0) {
    cout << "testBarChartClear: size failed" << endl;
    return false;
  }
  bc.addBar("Chicago", 1020, "US");
  bc.clear();
  if (bc.getFrame() != "") {
    cout << "testBarChartClear: Frame failed" << endl;
    return false;
  } else if (bc.getSize() != 0) {
    cout << "testBarChartClear: size failed" << endl;
    return false;
  } 
  cout << "testBarChartClear: all passed!" << endl;
  return true;
}

//test for the setFrame function which is a member of the BarChart class
bool testBarChartFrame() {
  BarChart bc(3);
  bc.setFrame("1950");
  if (bc.getFrame() != "1950") {
    cout << "testBarChartFrame: Frame failed" << endl;
    return false;
  } 
  cout << "testBarChartFrame: all passed!" << endl;
  return true;
}

//test for the addFrame function which is a member of the BarChart class
bool testBarChartAdd() {
  BarChart bc(3);
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  
  if (bc[0].getName() != "Chicago") {
    cout << "testBarChartAdd: name failed" << endl;
    return false;
  } else if (bc[0].getValue() != 1020) {
    cout << "testBarChartAdd: value failed" << endl;
    return false;
  } else if (bc[0].getCategory() != "US") {
    cout << "testBarChartAdd: category failed" << endl;
    return false;
  }

  if (bc[1].getName() != "NYC") {
    cout << "testBarChartAdd: name failed" << endl;
    return false;
  } else if (bc[1].getValue() != 1300) {
    cout << "testBarChartAdd: value failed" << endl;
    return false;
  } else if (bc[1].getCategory() != "US") {
    cout << "testBarChartAdd: category failed" << endl;
    return false;
  }

  if (bc[2].getName() != "Paris") {
    cout << "testBarChartAdd: name failed" << endl;
    return false;
  } else if (bc[2].getValue() != 1200) {
    cout << "testBarChartAdd: value failed" << endl;
    return false;
  } else if (bc[2].getCategory() != "France") {
    cout << "testBarChartAdd: category failed" << endl;
    return false;
  }

  cout << "testBarChartAdd: all passed!" << endl;
  return true;
}

//test for the dump function which is a member of the BarChart class
bool testBarChartDump() {
  BarChart bc(3);
  bc.setFrame("1950");
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  stringstream ss;
  string line;
  bc.dump(ss);
  getline(ss, line);
  if (line != "frame: 1950") {
    cout << "dump() failed" << endl;
    return false;
  }
  getline(ss, line);
  if (line != "NYC 1300 US") {
    cout << "dump() failed" << endl;
    return false;
  }
  getline(ss, line);
  if (line != "Paris 1200 France") {
    cout << "dump() failed" << endl;
    return false;
  }
  getline(ss, line);
  if (line != "Chicago 1020 US") {
    cout << "dump() failed" << endl;
    return false;
  }
  cout << "testBarChartDump: all passed!" << endl;
  return true;
}

// test for the graph function where the values for colorMap is given
bool testBarChartGraph1() {
  BarChart bc(3);
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  string red("\033[1;31m");
  string blue("\033[1;34m");
  map<string, string> colorMap;
  colorMap["US"] = red;
  colorMap["France"] = blue;
  stringstream ss;
  string line;
  bc.graph(ss, colorMap, 3);
  getline (ss, line, ' ');
  getline (ss,line);
  if (line != "NYC 1300") {
    cout << "graph failed" << endl;
    return false;
  }
  getline (ss, line, ' ');
  getline (ss,line);
  if (line != "Paris 1200") {
    cout << "graph failed" << endl;
    return false;
  }
  getline (ss, line, ' ');
  getline (ss,line);
  if (line != "Chicago 1020") {
    cout << "graph failed" << endl;
    return false;
  }
  cout << "testBarChartGraph1: all passed!" << endl;
  return true;
}

// test for the graph function where the values for colorMap is not given
bool testBarChartGraph2() {
  BarChart bc(5);
  bc.addBar("Gared", 21, "other");
  bc.addBar("Waymar", 21, "other");
  bc.addBar("Will", 21, "other");
  map<string, string> colorMap;
  stringstream ss;
  string line;
  bc.graph(ss, colorMap, 3);
  getline (ss, line, ' ');
  getline (ss,line);
  if (line != "Gared 21") {
    cout << "graph failed" << endl;
    return false;
  }
  getline (ss, line, ' ');
  getline (ss,line);
  if (line != "Waymar 21") {
    cout << "graph failed" << endl;
    return false;
  }
  getline (ss, line, ' ');
  getline (ss,line);
  if (line != "Will 21") {
    cout << "graph failed" << endl;
    return false;
  }
  cout << "testBarChartGraph2: all passed!" << endl;
  return true;
}

int main() {
  testBarDefaultConstructor();
  testBarParamConstructor();
  testBarLesser();
  testBarGreater();
  testBarLesserEqual();
  testBarGreaterEqual();
  testBarChartDefaultConstructor();
  testBarChartParamConstructor();
  testBarChartCopyConstructor();
  testEqual();
  testBarChartClear();
  testBarChartFrame();
  testBarChartAdd();
  testBarChartDump();
  testBarChartGraph1();
  testBarChartGraph2();
  return 0;
}*/