#include <iostream>
#include <vector>
#include <set>


std:: string GetString (void);
std:: vector<std:: string> Initialize (std:: string str);
void ReverseOutput (std::vector<int> array, int number);

template <typename T>
std:: vector<T> ReverseOutputSet (std:: set<T> s, T elem);


int main (void) {	


	//----1st part:----

	/*

	std::vector<int> arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = i + 7;

	ReverseOutput (arr, 9);

	*/



	//----2nd part:----

	/*

	std:: string str = GetString ();
	std:: vector<std:: string> v = Initialize (str);

	for (int i = 0; i < v.size(); i++)
		std:: cout << v[i] << std:: endl;

	*/



	//----3rd part:----

	std:: set<int> s;
	s.insert (8);
	s.insert (1);
	s.insert (2);
	s.insert (3);

	std:: vector<int> v = ReverseOutputSet (s, 1);

	int i = 0;
	for (i = 0; i < v.size(); i++)
		std:: cout << v[i] << " ";

	return 0;
}


std:: vector<std:: string> Initialize (std:: string str) {

	std:: vector<char> buf;
	std:: vector<std:: string> strBuf;
	
	int i = 0;
	for (i = 0; i < str.size(); i++)
		buf.push_back (str[i]);

	std:: vector<char>:: iterator iter = buf.begin ();
	std:: string capacityBuffer = "";
	while (iter != buf.end()) {

		if (( * iter) == ' ') {

			iter++;
			strBuf.push_back(capacityBuffer);
			capacityBuffer = "";
		}

		capacityBuffer += ( * iter);
		iter++;
	}

	strBuf.push_back(capacityBuffer);

	return strBuf;
}


std:: string GetString (void) {

	std:: string str;
	getline (std:: cin, str);

	return str;
}


void ReverseOutput (std::vector<int> array, int number) {

	std:: vector<int>:: iterator iter = array.begin();
	int saveIndex = 0;

	while (iter != array.end()) {

		if (( * iter) > number)
			break;

		saveIndex++;
		iter++;
	}

	if (saveIndex < array.size() && saveIndex >= 2) {

		int i = 0;
		for (i = saveIndex - 2; i >= 0; i--)
			std:: cout << array[i] << " ";

		return;
	}
}


template <typename T>
std:: vector<T> ReverseOutputSet (std:: set<T> s, T elem) {

	std:: vector<T> save;
	std:: vector<T> reverse;
	std:: copy (s.begin(), s.end(), std:: back_inserter(save));

	int i = 0, saveIndex = 0;
	for (i = 0; i < save.size(); i++) {

		if (save[i] > elem)
			break;

		saveIndex++;
	}

	for (i = save.size() - 1; i >= saveIndex; i--)
		reverse.push_back(save[i]);

	return reverse;
}
