#include <iostream> 
#include <ostream>
#include <istream>
#include <stdlib.h>


using namespace std;


class Fraction {

	public:
		
		Fraction (int Numerator, int Denominator) {

			if (Denominator == 0)
				throw std:: invalid_argument ("Denominator = 0. Error.\n");

			sign = (Numerator / abs (Numerator)) * (Denominator / abs (Denominator));
			numerator   = abs (Numerator);
			denominator = abs (Denominator);
		}

		int opFraction (int a, int b) {

			int startA = abs (a);
			int startB = abs (b);

			while (a != 0 && b != 0) {

				if (a > b) 
					a %= b; 

				else 
					b %= a;
			}

			if (a + b != 1) {

				startA /= (a + b);
				startB /= (a + b);
				opFraction (startA, startB);
			}

			numerator   = startA * sign;
			denominator = startB;
			return a + b;
		}

		Fraction operator= (Fraction frac) {

			numerator = frac.numerator * frac.sign;
			denominator = frac.denominator;

			return * this;
		}

		Fraction operator++ (int) {

			numerator = numerator * sign;
			numerator += denominator;

			if (numerator > 0)
				sign = 1;

			if (numerator < 0)
				sign = -1;

			numerator = numerator * sign;


			return * this;
		}

		Fraction & operator++ () {

			numerator = numerator * sign;
			numerator += denominator;

			if (numerator > 0)
				sign = 1;

			if (numerator < 0)
				sign = -1;

			numerator = numerator * sign;

			return * this;
		}

int       sign;
int   numerator;
int denominator;
};


Fraction operator+     (Fraction frac1, Fraction frac2);
Fraction operator-     (Fraction frac1, Fraction frac2);
Fraction operator*     (Fraction frac1, Fraction frac2);
Fraction operator/     (Fraction frac1, Fraction frac2);
bool     operator==    (Fraction frac1, Fraction frac2);
bool     operator>     (Fraction frac1, Fraction frac2);
bool     operator<     (Fraction frac1, Fraction frac2);

std:: ostream & operator<< (std:: ostream &os,  Fraction   frac);
std:: istream & operator>> (std:: istream & is, Fraction & frac);