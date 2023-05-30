// Name: Dona Maria
// NetId: dmari21
// Course: CS 251
// Program Description: This application uses BarChartAnimate to read text files and 
// transform them to an animated bar chart
// Creative Component: For my creative component, I wrote a function in which the user 
// can see the barcharts of a specific timespan. 
// It takes in two other parameter apart from ostream &output and int top. 
// The user should type in the starting frame (string frameStart) 
// and the number of frames (int numFrames).
// I thought this would be useful to see the data for a specific frame and to see how 
// the data changed during a certain time period.

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"

using namespace std;

int main() {
	string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;

	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
	BarChartAnimate bca(title, xlabel, source);
  
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}

  bca.animate(cout, 12, -1); 

  // Creative component part
  //string frameStart;
  //int numFrames;
  //cout << "Enter the frame you want to start with" << endl;
  //getline (cin,frameStart);
  //cout << "And enter the number of frames you want to see" << endl;
  //cin >> numFrames;
  //bca.animate(cout, 12, frameStart, numFrames);
  
  return 0;
}