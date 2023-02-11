#include "header_fracred.hpp"
#include "fracred.hpp"


int main (void) {


	Fraction frac1 (-4, -7);
	Fraction frac2 (-2, 7);
	cout << "op +: " << frac1 + frac2 << endl;	// -4/7 + (-2/7) = -6/7;
	cout << "op -: " << frac1 - frac2 << endl;	// -4/7 - (-2/7) = -2/7;
	cout << "op *: " << frac1 * frac2 << endl;	// -4/7 * (-2/7) = 8/49;
	cout << "op /: " << frac1 / frac2 << endl;	// (4 * 7)/ (-2 * (-7)) = 28/14 = 2/1;

	Fraction frac3 (95, -99);
	cout << "op ++: " << frac3++ << endl; // -95/99 + 1 = 4/99;
	cout << "++ op: " << ++frac3 << endl; // = 4/99 + 1 = 103/99;

	if (frac1 > frac2) // -4/7 > -2/7 - false;
		cout << "frac1 > frac2" << endl;

	frac1++;

	if (frac1 > frac2) // -4/7 + 1 = 3/7 > -2/7 - true;
		cout << "frac1 > frac2 and frac1 = " << frac1 << endl;

	// ANALOG: frac1 < frac2;

	Fraction frac4 = frac2; // frac4 = -2/7;
	cout << "frac1 = frac2 = -2/7: " << frac4 << endl;

	frac4++;
	cout << "frac4 = " << frac4 << endl; // frac4 = -2/7 + 1 = 5/7;

	Fraction frac5 (56, -49); 
	cout << "frac5: " << frac5 << endl; // -56/49 = -8/7;
	
	return 0;
}