// This header file contains the class BarChartAnimate
// Containes function to read files and convert into barcharts

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
//#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

class BarChartAnimate {
 private:
    BarChart* barcharts;  
    int size;
    int capacity;
    string title;
    string xlabel;
    string source;
    map<string, string> colorMap;

    // helper function for overloading operator []
    BarChart& at(int i)
    {
      if (i < 0 || i >= size)
      {
        throw out_of_range("ourvector: i out of bounds");
      }
      return barcharts[i];
    }

    // helper function for the animate function
    void animateHelper(ostream &output, int microsecond, int endIter, int top) {
      for (int i = 0; i < endIter; i++)
         { 
           usleep(3 * microsecond);
           output << CLEARCONSOLE;
           output << WHITE << title << '\n' << source << endl;
           barcharts[i].graph(output,colorMap, top);
           output << WHITE << xlabel << endl;
           output << "Frame: " << barcharts[i].getFrame() << endl;
         }
    }

    // helper function to double the capacity when the size is equal to the capacity
    void doubleCapacity() {
      if (size == capacity)
      {
        int newCapacity = capacity * 2;
        BarChart* newBarcharts = new BarChart[newCapacity];
        for (int i = 0; i < size; ++i)
        {
          newBarcharts[i] = barcharts[i];
        } 
        delete[] barcharts;
        barcharts = newBarcharts;
        capacity = newCapacity;
      }
    }

 public:

    // a parameterized constructor with initial capacity 4
    BarChartAnimate(string title, string xlabel, string source) {
      barcharts = new BarChart[4];
      capacity = 4;
      size = 0;
      this->title = title;
      this->xlabel = xlabel;
      this->source = source;
    }

    // destructor to free the memory associated by BarChartAnimate.
    virtual ~BarChartAnimate() {
      if (barcharts != nullptr)
        delete[] barcharts;
    }

    // addFrame adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity 
    void addFrame(ifstream &file) {
      string line, fileYear, fileName1, fileName2, fileValue, fileCategory;
      doubleCapacity();
      getline(file, line, '\n');
      if (file.eof())
        return;
      getline(file, line, '\n');
      int num = stoi(line);
      barcharts[size] = BarChart(num);
      int i = 0, j = 0;
      while ( i < num)
        {
          getline(file, fileYear, ',');
          getline(file, fileName1, ',');
          getline(file, fileName2, ',');
          getline(file, fileValue, ',');
          getline(file, fileCategory, '\n');
          if (!colorMap.count(fileCategory))
          {
            colorMap[fileCategory] = COLORS[j];
            j++;
            if (j == COLORS.size())
              j = 0;
          }
          barcharts[size].addBar(fileName1, stoi(fileValue), fileCategory);
          i++;
        }
      barcharts[size].setFrame(fileYear);
      size = size + 1;
    }

    // animate function plays each frame stored in barcharts.  
	  void animate(ostream &output, int top, int endIter) {
		  unsigned int microsecond = 50000;
      if (endIter == -1)
      {
        animateHelper(output, microsecond, size, top);
      }
      else
      {
        animateHelper(output, microsecond, endIter, top);
      }
	  } 

    // Creative Component part
    /*void animate(ostream &output, int top, string frameStart, int numFrames) {
		  unsigned int microsecond = 50000;
      int num;
      for (int k = 0; k < Size; k++)
        {
          if (barcharts[k].getFrame() ==frameStart)
          {
            num = k;
             break;
          } 
        }
      
      for (int i = num; i < num + numFrames; i++)
        {
          usleep(3 * microsecond);
          output << CLEARCONSOLE;
          output << WHITE << title << '\n' << source << endl;
          barcharts[i].graph(output,colorMap, top);
          output << WHITE << xlabel << endl;
          output << "Frame: " << barcharts[i].getFrame() << endl;
        }
    } */

    // Accessor function returns the size of the BarChartAnimate object.
    int getSize() {   
        return size;    
    }

    // This gives public access to BarChart stored in the BarChartAnimate.
    BarChart& operator[](int i){
       return at(i); 
    }
};