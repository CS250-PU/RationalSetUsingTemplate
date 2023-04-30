//***************************************************************************
// File name:  Rational.cpp
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Rational 
// Purpose:    Implements constructors & functions of class Rational. There is
//             no real error checking in this implementation.
//***************************************************************************

#include <iostream>
#include "../include/Rational.h"

using namespace std;

//***************************************************************************
// Constructor: Rational
//
// Description: Initializes data members to default values
//
// Parameters:  numerator   – the numerator of the rational number
//              denominator – the denominator of the rational number
//
// Returned:    None
//***************************************************************************

Rational::Rational (int numerator, int denominator) {
  mNumerator = numerator;
  mDenominator = denominator;
}

//***************************************************************************
// Method:	    setNumerator
//
// Description: Changes the value of the numerator to the value input. Shows
//              the use of this although it is not necessary.
//
// Parameters:  numerator   - numerator of the rational number
//
// Returned:    None
//***************************************************************************


void Rational::setNumerator (int numerator) {
  this->mNumerator = numerator;
}

//***************************************************************************
// Method:	    setDenominator
//
// Description: Changes the value of the denominator to the value input.
//
// Parameters:  denominator   - denominator of the rational number
//
// Returned:    None
//***************************************************************************


void Rational::setDenominator (int denominator) {
  this->mDenominator = denominator;
}

//***************************************************************************
// Method:	    getNumerator
//
// Description: Returns the value of the numerator.
//
// Parameters:  None
//
// Returned:    The numerator value
//***************************************************************************


int Rational::getNumerator () const {
  return this->mNumerator;
}

//***************************************************************************
// Method:	    getDenominator
//
// Description: Returns the value of the denominator.
//
// Parameters:  None
//
// Returned:    The denominator value
//***************************************************************************


int Rational::getDenominator () const {
  return this->mDenominator;
}

//***************************************************************************
// Method:	    print
//
// Description: Outputs a rational number in the form numerator / denominator
//              to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************


void Rational::print (std::ostream &rcOutput) const {
  rcOutput << " " << getNumerator() << "/" << getDenominator();
}

//***************************************************************************
// Method:	    isqual
//
// Description: Compares two objects of Rational returning a value of true if 
//              the numerators and denominators of both rational numbers are 
//              the same.
//
// Parameters:  fraction – rational object having a numerator and denominator
//
// Returned:    true if objects are equal; else, false
//***************************************************************************


bool Rational::isEqual (const Rational &rcRational)  const {
  return (mNumerator == rcRational.mNumerator && 
          mDenominator == rcRational.mDenominator);
}

//***************************************************************************
// Method:	    multiply
//
// Description: Multiples the numerators and denominators of two objects. 
//
// Parameters:  fraction – rational object having a numerator and denominator
//
// Returned:    An object of type Rational that contains the result of the             
//              multiplication.
//***************************************************************************

Rational Rational::multiply (const Rational &rcRational) const {
  return Rational (mNumerator * rcRational.mNumerator, 
                   mDenominator * rcRational.mDenominator);
}

//***************************************************************************
// Method:	    reduce
//
// Description: Divides the numerator and denominator of a Rational number
//              by the greatest common divisor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Rational Rational::reduce () const {
	int gcd = Rational::gcd (mNumerator, mDenominator);

  return Rational (mNumerator / gcd, mDenominator / gcd);
}

//***************************************************************************
// Method:	    gcd
//
// Description: Finds the greatest common divisor of two integers 
//
// Parameters:  num1 – first integer
//              num2 - second integer
//
// Returned:    The greatest common divisor is returned
//***************************************************************************
int Rational::gcd (int num1, int num2) {
	int lower = num1;
	int gcdVal = 1;

	if (num2 < num1) {
		lower = num2;
	}

	for (int i = lower; i > 1 && gcdVal == 1; --i) {
		if (num1 % i == 0 && num2 % i == 0) {
			gcdVal = i;
		}
	}
	return gcdVal;
}

//*********************************************************************
// Operator function * - binary operation that multiplies two rational
//                       numbers
//*********************************************************************

Rational Rational::operator* (const Rational &rcRational) const {
	return Rational (mNumerator * rcRational.mNumerator, 
		                mDenominator * rcRational.mDenominator);
}

//*********************************************************************
// Operator function + - binary operation that adds two rational
//                       numbers
// Note: a/b + c/d = (ad + bc) / bd
//*********************************************************************

Rational Rational::operator+ (const Rational &rcRational) const {
	return Rational ((mNumerator * rcRational.mDenominator) +
									 (mDenominator * rcRational.mNumerator),
									 (mDenominator * rcRational.mDenominator));
}

//*********************************************************************
// Operator function - - unary operation that negates a rational number
//*********************************************************************

Rational Rational::operator- () const {
	return Rational (-mNumerator, mDenominator);
}

//*********************************************************************
// Operator function ==  compares two rational numbers for equivalency
//*********************************************************************

bool  Rational::operator== (const Rational &rcRational) const {
	return (mNumerator == rcRational.mNumerator) && 
		     (mDenominator == rcRational.mDenominator);
}

//*********************************************************************
// Operator function << outputs a rational number
//*********************************************************************

ostream & operator<< (ostream &rcOutput, const Rational &crRational) {
	rcOutput << crRational.mNumerator << '/' << crRational.mDenominator;

	return rcOutput;
}

//*********************************************************************
// Operator function >> inputs a rational number
//*********************************************************************

istream & operator>> (istream &rcInput, Rational &rcRational) {
	char ch;

	rcInput >> rcRational.mNumerator >> ch >> rcRational.mDenominator;

	return rcInput;
}