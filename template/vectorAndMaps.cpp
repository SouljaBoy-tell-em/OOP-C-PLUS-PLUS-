#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <iomanip>


class Checker {

	private:
		int counter;

	public:
		Checker(void);
		~Checker(void);
		template<class function, class T, typename U>
		void check(function executor, std:: vector<T> v, U check_element);
		void show (void);
};


template<typename T>
bool CheckElement(std:: vector<T> v, T check_element);

template<typename T, typename U>
bool CheckElement(std:: map<T, U> m, std:: pair<T, U> p);

template<typename T>
bool EvenNumberOfData(std:: vector<T> v);

template<typename T, typename U>
bool EvenNumberOfData(std:: map<T, U> m);


int main() {

	//std:: vector<int> v(4);
	//std:: cout << EvenNumberOfData(v) << std:: endl;

	/*

	std:: map<int, double> m;
	m[0] = 2;
	m[1] = 3;
	std:: pair<int, double> p;
	p.first = 0;
	p.second = 2;
	std:: cout << EvenNumberOfData(m);

	*/
	


	std:: vector<std:: vector<int> > vVector(5);
	int i = 0, j = 0;
	for(i = 0; i < 5; i++)
		for(j = 0; j < 4; j++)
			vVector[i].push_back(1);

	Checker checkerVector = Checker();
	checkerVector.check(CheckElement<int>, vVector, 1);



	std:: vector<std:: map<int, double> > vMap(5);
	for(i = 0; i < 5; i++)
		vMap[i][i + 1] = (double)(i + 228);

	std:: pair<int, double> p;
	p.first = 1;
	p.second = 228;

	Checker checkerMap = Checker();
	checkerMap.check(CheckElement<int, double>, vMap, p);


	return 0;
}

Checker:: Checker(void) {

	counter = 0;
}


Checker:: ~Checker(void) {

	std:: cout << counter << std:: endl;
}


template<class function, class T, typename U>
void Checker:: check(function executor, std:: vector<T> v, U check_element) {

	int i = 0;
	for (i = 0; i < v.size(); i++)
		if (executor(v[i], check_element))
			counter++;
}


template<typename T>
bool EvenNumberOfData(std:: vector<T> v) {

	return (!(v.size() % 2)) ? true : false;
}

template<typename T, typename U>
bool EvenNumberOfData(std:: map<T, U> m) {

	return (!(m.size() % 2)) ? true : false;
}


template<typename T>
bool CheckElement(std:: vector<T> v, T check_element) {

	int i = 0;
	for(i = 0; i < v.size(); i++)
		if (v[i] == check_element)
			return true;

	return false;
}


template<typename T, typename U>
bool CheckElement(std:: map<T, U> m, std:: pair<T, U> p) {

	typename std:: map<T, U>::const_iterator it = m.begin();

    for(; it != m.end(); ++it)
    	if ((*it).first == p.first && (*it).second == p.second)
        	return true;

	return false;
}


void Checker:: show (void) {

	std:: cout << "counter: " << counter << std:: endl;
}

