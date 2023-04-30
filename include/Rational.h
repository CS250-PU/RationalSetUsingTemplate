//***************************************************************************
// File name:  Rational.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Rational 
// Purpose:    Interface for class Rational. A Rational number is of the form
//             numerator / denominator.
//***************************************************************************
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational {                                                                                                   
	public:                                                                                                                                                                                      
		Rational (int numerator = 0, int denominator = 1);                                                                                   
		void print (ostream &rcOutput) const;
		int getNumerator () const;
		int getDenominator () const;
		void setNumerator (int numerator);
		void setDenominator (int numerator);
		bool isEqual (const Rational &rcRational) const;
        Rational reduce () const;
        Rational multiply (const Rational &rcRational) const;                                                                   
		Rational operator* (const Rational &rcRational) const;                                                               
		Rational operator+ (const Rational &rcRational) const;                                                               
		Rational operator- (void) const;
		bool operator== (const Rational &rcRational) const;   

		friend ostream & operator<< (ostream &rcOutput, const Rational &rcRational);    
		friend istream & operator>> (istream &rcInput, Rational &rcRational);

    static int gcd (int num1, int num2); 

  private:
		int mNumerator, mDenominator;                                                                             
};

#endif