#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <utility>
#include <string>


template <typename T>
std:: ostream & operator<<(std:: ostream & os, const std:: vector<T> v);

template <typename T, typename U>
std:: ostream & operator<<(std:: ostream & os, std:: map<T, U> m);

template<typename T>
std:: string output(T container, std:: string symb);

template<typename T, typename U>
std:: ostream & operator<<(std:: ostream & os, std:: pair<T, U> p);


int main() {



	/*

	std:: vector<int> v(5);

	int i = 0;
	for (i = 0; i < 5; i++)
		v[i] = i + 7;

	std:: cout << v;

	*/


	/*

	std:: pair <int, std:: string> p;
	p.first = 1;
	p.second = "ACCEPTED!";

	std:: cout << p;
	
	*/


	std:: map<std:: string, int> m;
	m["lol"] = 1;
	std:: cout << m;


	return 0;
}


template<typename T>
std:: string output(T container, std:: string symb) {

    bool isFirst = true;
    std:: stringstream buf;

    for (auto i : container) {

        if (isFirst) {

            buf << i;
            isFirst = false;
        }

        else
            buf << symb << i;
    }

    return buf.str();
}


//--------
// << MAP
//--------

template <typename T, typename U>
std:: ostream & operator<<(std:: ostream & os, std:: map<T, U> m) {

	os << output(m, ";");

	return os;
}


//---------
// << PAIR
//---------

template<typename T, typename U>
std:: ostream & operator<<(std:: ostream & os, std:: pair<T, U> p) {
	
    os << p.first << " " << p.second;
    return os;
}


//-----------
// << VECTOR
//-----------

template <typename T>
std:: ostream & operator<<(std:: ostream & os, const std:: vector<T> v) {

	std:: cout << output(v, ",");

	return os;
}



