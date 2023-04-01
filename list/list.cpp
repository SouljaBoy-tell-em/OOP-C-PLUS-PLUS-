#include "header_list.hpp"
#include "list.hpp"


int main(void) {

	/*
	LIST:: Node<int> a1(1);
	LIST:: Node<int> a2(2);
	LIST:: List<int> list(&a1);
	list.Push(&a2);
	list.Show();
	if (a1 == a2)
		std:: cout << "a1 = a2"  << std:: endl;
	if (a1 != a2)
		std:: cout << "a1 != a2" << std:: endl;
	*/


	std:: vector<LIST:: Node<int> > a(5);
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;

	LIST:: List<int> list(a);
	//list.Show(); 
	
	LIST:: Iterator<int> it1;
	LIST:: Iterator<int> it2;
	LIST:: Iterator<int> it3;
	it1 = list.begin();
	it2 = list.end();
	it3 = list.begin();


	/*

	std:: cout << "it1 begin: " << *it1 << std:: endl;
	std:: cout << "it2 end: "   << *it2 << std:: endl;


	it1++;
	std:: cout << "new it1: "   << *it1 << std:: endl;
	it1++;
	std:: cout << "new it1: "   << *it1 << std:: endl;
	it1++;
	std:: cout << "new it1: "   << *it1 << std:: endl;
	it1++;
	std:: cout << "new it1: "   << *it1 << std:: endl;
	it1++;
	std:: cout << "new it1: "   << *it1 << std:: endl;

	it2-=31;
	std:: cout << "new it2: "   << *it2 << std:: endl;

	it1+=10;
	std:: cout << "new it1: "   << *it1 << std:: endl;

	it2--;
	it2++;
	std:: cout << "new it2: "   << *it2 << std:: endl;

	it2+=10;
	std:: cout << "new it2: "   << *it2 << std:: endl;

	it2-=10;
	std:: cout << "new it2: "   << *it2 << std:: endl;

	it1 = it2;
	std:: cout << "new it1: "   << *it1 << std:: endl;
	std:: cout << std:: endl            << std:: endl;





	std:: cout << "new it3: "  << *it3  << std:: endl;

	it1++;
	it2 = it1;
	it3 = it1 + 2;
	it3 -= 3;
	std:: cout << "new it1: "  << *it1  << std:: endl;
	std:: cout << "new it2: "  << *it2  << std:: endl;
	std:: cout << "new it3: "  << *it3  << std:: endl;

	it3--;
	std:: cout << "new it3: "  << *it3  << std:: endl;

	it3+=5;
	std:: cout << "new it3: "  << *it3  << std:: endl;

	it3 = it1 - 10;
	std:: cout << "new it3: "  << *it3  << std:: endl;

	*/



	/*

	it3++;
	std:: cout << "new it3: "  << *it3  << std:: endl;


	it3.erase();
	std:: cout << "new it3: "  << *it3  << std:: endl;
	it3++;
	std:: cout << "new it3: "  << *it3  << std:: endl;

	*/

	std:: cout << "new it3: "  << *it3  << std:: endl;

	it3++;
	it3.insert(228);
	std:: cout << "new it3: "  << *it3  << std:: endl;

	list.Show();

	//std:: cout << "new it3: "  << *it3  << std:: endl;

	return 0;
}
