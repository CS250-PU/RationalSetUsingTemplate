//***************************************************************************
// File name:  RationalSet.cpp
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: RationalSet 
// Purpose:    Implementation for class RationalSet. A set of Rational numbers 
//             is of the form {}, {1/2}, {1/2 2/3}, ...
//
//***************************************************************************

#include <iostream>
#include "../include/RationalSet.h"
#include "../include/Rational.h"

using namespace std;

int main () {
  RationalSet cRationalSet1, cRationalSet2, cRationalSetIntersection;
  
  for (int i = 0; i < 5; ++i) {
    cRationalSet1.add (Rational (i, i + 1));
  }

  cout << cRationalSet1 << endl;

  cout << "Enter Rational Set: ";
  cin >> cRationalSet2;
  cout << "The Rational Set Is: " << cRationalSet2 << endl;
  cRationalSetIntersection = cRationalSet1 * cRationalSet2;
  cout << "Intersection Is: " << cRationalSetIntersection << endl;

  if (cRationalSet1.isEqual (cRationalSetIntersection)) {
    cout << "Same Set" << endl;
  }
  else {
    cout << "Not Same Set" << endl;
  }

  if (cRationalSet1.isEqual (cRationalSet1)) {
    cout << "Same Set" << endl;
  }
  else {
    cout << "Not Same Set" << endl;
  }

  exit (EXIT_SUCCESS);
}