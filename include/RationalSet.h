//***************************************************************************
// File name:  RationalSet.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: RationalSet 
// Purpose:    Interface for class RationalSet. A set of Rational numbers is
//             of the form {}, {1/2}, {1/2 2/3}, ...
//***************************************************************************

#ifndef RATIONALSET_H
#define RATIONALSET_H

#include "Rational.h"
#include <iostream>
#include <vector>

using namespace std; 

class RationalSet {                                                                                                   
	public:
    // static const int MAX_RATIONALS = 100;
		RationalSet ();
		bool isIn (const Rational &rcRational) const;
		size_t size () const;
	  void print (ostream &rcOutput)  const;

    RationalSet add (const Rational &rcRational);
    bool isEqual (const RationalSet &rcRationalSet) const;
    RationalSet operator* (const RationalSet &rcRationalSet) const;

    friend ostream& operator<< (ostream &rcOutput, 
                                const RationalSet &rcRationalSet);

    friend istream& operator>> (istream &rcInput, 
                                RationalSet &rcRationalSet);

  private:
    vector<Rational> mcRationals;
};

#endif
