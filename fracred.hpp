Fraction operator+ (Fraction frac1, Fraction frac2) {

	return Fraction ((frac1.numerator * frac1.sign) * frac2.denominator + (frac2.numerator * frac2.sign) * frac1.denominator, frac1.denominator * frac2.denominator);
}


Fraction operator- (Fraction frac1, Fraction frac2) {

	return Fraction ((frac1.numerator * frac1.sign) * frac2.denominator - (frac2.numerator * frac2.sign) * frac1.denominator, frac1.denominator * frac2.denominator);
}


Fraction operator* (Fraction frac1, Fraction frac2) {

	return Fraction (frac1.numerator * frac2.numerator * frac1.sign * frac2.sign, frac1.denominator * frac2.denominator);
}


Fraction operator/ (Fraction frac1, Fraction frac2) {

	return Fraction (frac1.numerator * frac1.sign * frac2.denominator, frac2.numerator * frac2.sign * frac1.denominator);
}


bool operator== (Fraction frac1, Fraction frac2) {

	return (frac1.numerator * frac1.sign == frac2.numerator * frac2.sign && frac1.denominator == frac2.denominator);
}


bool operator> (Fraction frac1, Fraction frac2) {

	return (frac1.numerator * frac1.sign * frac2.denominator > frac2.numerator * frac2.sign * frac1.denominator);
}


bool operator< (Fraction frac1, Fraction frac2) {

	return (frac1.numerator * frac1.sign * frac2.denominator < frac2.numerator * frac2.sign * frac1.denominator);
}

std:: ostream & operator<< (std:: ostream &os, Fraction frac) {

	frac.opFraction (frac.numerator, frac.denominator);

	return os << frac.numerator << "/" << frac.denominator << std:: endl;
}


std:: istream & operator>> (std:: istream & is, Fraction & frac) {

    int numerator = 0, denominator = 0;
    char sign = '\0';

    is >> numerator >> sign >> denominator;

    if (sign != '/') {

        is.setstate (std:: ios_base:: failbit);
        return is;
    }

    frac = Fraction (numerator, denominator);
    
    return is;
}