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

#include "../include/RationalSet.h"
#include "../include/Rational.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

RationalSet::RationalSet () {
	//mNumRationals = 0;
}

bool RationalSet::isIn (const Rational &rcRational) const {
	return find (mcRationals.begin (), mcRationals.end (), rcRational) != mcRationals.end ();
}

size_t RationalSet::size () const {
	return mcRationals.size ();
}

void RationalSet::print (ostream &rcOutput)  const {
  bool bIsFirst = true;

  rcOutput << '{';
  for (const Rational &rcRational : mcRationals) {
    if (!bIsFirst) {
      rcOutput << ' ';
    }
    else {
      bIsFirst = false;
    }
    rcOutput << rcRational;
  }
  rcOutput << '}';
}

RationalSet RationalSet::add (const Rational &rcRational) {
  if (!isIn (rcRational)) {
    mcRationals.push_back (rcRational);
  }
  return *this;
}

bool RationalSet::isEqual (const RationalSet &rcRationalSet) const {
  bool bIsEqual = true;

  if (mcRationals.size () == rcRationalSet.size ()) {
    for (size_t i = 0; i < mcRationals.size () && bIsEqual; ++i) {
      if (!isIn (mcRationals.at (i))) {
        bIsEqual = false;
      }
    }
  }
  else {
    bIsEqual = false;
  }
  return bIsEqual;
}

RationalSet RationalSet::operator* (const RationalSet &rcRationalSet) const {
  RationalSet cRationalSetIntersection;

  for (const Rational &rcRational : rcRationalSet.mcRationals) {
    if (isIn (rcRational)) {
      cRationalSetIntersection.add (rcRational);
    }
  }
  return cRationalSetIntersection;
}

ostream& operator<< (ostream &cOutput, const RationalSet &cRationalSet) {
  cRationalSet.print (cOutput);

  return cOutput;
}

// Assumes RationalSet is well formed ... {}, {1/2}, {1/2 2/3}, ...
istream& operator>> (istream &rcInput, 
                     RationalSet &rcRationalSet) {
  Rational cRational;

  rcInput.get ();
  while (rcInput.peek () != '}') {
    rcInput >> cRational;
    if (!rcRationalSet.isIn (cRational)) {
      rcRationalSet.mcRationals.push_back (cRational);
    }
  }
  return rcInput;
}