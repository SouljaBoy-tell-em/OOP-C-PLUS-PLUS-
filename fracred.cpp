#include <iostream> 
#include <ostream>
#include <istream>
#include <stdlib.h>


class Fraction {

	public:
		
		Fraction (int Numerator, int Denominator) {

			if (Denominator == 0)
				throw std:: invalid_argument ("Denominator < 0. Error.\n");

			sign = '\r';

			if (Numerator < 0)
				if (Denominator > 0)
					sign = '-';

			if (Numerator > 0)
				if (Denominator < 0)
					sign = '-';


			numerator   = abs (Numerator);
			denominator = abs (Denominator);

		}

		int opFraction (int a, int b) {

			static int startA = a;
			static int startB = b;

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

			numerator   = startA;
			denominator = startB;
			return a + b;
		}

		Fraction operator= (Fraction frac) {

			numerator = frac.numerator;
			denominator = frac.denominator;

			return * this;
		}

		Fraction operator++ (int) {

			numerator += denominator;

			return * this;
		}

		Fraction & operator++ () {

			numerator += denominator;

			return * this;
		}

char       sign;
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


int main (void) {


	Fraction frac1 (-1, 3);
	std:: cin >> frac1;
	std:: cout << frac1 << std:: endl;

	return 0;
}


Fraction operator+ (Fraction frac1, Fraction frac2) {

	return Fraction (frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator, frac1.denominator * frac2.denominator);
}


Fraction operator- (Fraction frac1, Fraction frac2) {

	return Fraction (frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator, frac1.denominator * frac2.denominator);
}


Fraction operator* (Fraction frac1, Fraction frac2) {

	return Fraction (frac1.numerator * frac2.numerator, frac1.denominator * frac2.denominator);
}


Fraction operator/ (Fraction frac1, Fraction frac2) {

	return Fraction (frac1.numerator * frac2.denominator, frac2.numerator * frac1.denominator);
}


bool operator== (Fraction frac1, Fraction frac2) {

	return (frac1.numerator == frac2.numerator && frac1.denominator == frac2.denominator);
}


bool operator> (Fraction frac1, Fraction frac2) {

	return (frac1.numerator * frac2.denominator > frac2.numerator * frac1.denominator);
}


bool operator< (Fraction frac1, Fraction frac2) {

	return (frac1.numerator * frac2.denominator < frac2.numerator * frac1.denominator);
}

std:: ostream & operator<< (std:: ostream &os, Fraction frac) {

	frac.opFraction (frac.numerator, frac.denominator);
	return os << frac.sign << frac.numerator << "/" << frac.denominator << std:: endl;
}


std:: istream & operator>> (std:: istream & is, Fraction & frac) {

    int numerator = 0, denominator = 0;
    char sign = '\0';
    frac.sign = '\r';

    is >> numerator >> sign >> denominator;

    if (sign != '/') {

        is.setstate (std:: ios_base:: failbit);
        return is;
    }

    frac = Fraction (numerator, denominator);
   
    sign = '\r';

		if (numerator < 0)
			if (denominator > 0)
				frac.sign = '-';

		if (numerator > 0)
			if (denominator < 0)
				frac.sign = '-';
    
    return is;
}