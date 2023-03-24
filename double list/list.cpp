#pragma GCC diagnostic ignored "-Wnon-template-friend"


#include <iostream>
#include <iterator>
#include <vector>


namespace LIST {

	template<typename T>
	class List {

		private:
			List<T> * next;
			List<T> * prev;
			static uint64_t * head;
			static uint64_t * tail;
			static size_t     size; // size of List;
			T                 elem;

		public:
			void Connect(T m_elem, List<T> * prevElem = NULL);
			void ConsistentShow();
			List();
			List(std:: vector<T> vect);
			~List();
			void Show(void) const;
	};

	template<typename T>
	size_t List<T>:: size = 0;

	template<typename T>
	uint64_t * List<T>:: head = NULL;

	template<typename T>
	uint64_t * List<T>:: tail = NULL;
}


int main(void) {

	LIST:: List<std:: string>   list1;
	LIST:: List<std:: string>   list2;
	LIST:: List<std:: string>   list3;
	list1.Connect("812",        NULL);
	list2.Connect("2014",     &list1);
	list3.Connect("string",   &list2);

	list1.Show();
	std:: cout << std:: endl << std:: endl;
	list2.Show();
	std:: cout << std:: endl << std:: endl;
	list3.Show();



	/*

	std:: vector<int> v(5);
	int i = 0;
	for(i = 0; i < 5; i++)
		v[i] = i + 1;

	LIST:: List<int> list1(v);
	list1.ConsistentShow();

	*/



	/*
	
	LIST:: List<int>   list1;
	LIST:: List<int>   list2;
	list1.Connect(1,   NULL);
	list2.Connect(1, &list1);

	*/

	return 0;
}


template<typename T>
LIST:: List<T>:: List() {

	next = prev = NULL;
	head = NULL;
	tail = NULL;

	size = 0;
}


template<typename T>
LIST:: List<T>:: List(std:: vector<T> vect) {

	std:: vector<LIST:: List<T> > arrList(vect.size());
	
	int index = 0;
	for(index = 0; index < vect.size(); index++) {

		if (!index) {

			arrList[index].Connect(vect[index], NULL);
			continue;
		}

		arrList[index].Connect(vect[index], &arrList[index - 1]);
	}

	( * this) = arrList[0];
}


template<typename T>
void LIST:: List<T>:: Connect(T m_elem, List<T> * prevElem) {

	if (!size) {

		tail = (uint64_t * )this;
		head = (uint64_t * )tail;
		next = (List<T> * )head;
		prev = (List<T> * )prevElem;
		size++;
		elem = m_elem;

		return;
	}

	tail = (uint64_t * )this;
	next = (List<T> * )head;
	prev = (List<T> * )prevElem;
	prevElem->next = this;
	size++;
	elem = m_elem;
}


template<typename T>
LIST:: List<T>:: ~List() {

	std:: cout << "closed." << std:: endl;
}

template<typename T>
void LIST:: List<T>:: Show(void) const {

	std:: cout << "INFO:"                          << std:: endl;
	std:: cout << "next: "    <<              next << std:: endl;
	std:: cout << "prev: "    <<              prev << std:: endl;
	std:: cout << "head: "    << (uint64_t * )head << std:: endl;
	std:: cout << "tail: "    <<              tail << std:: endl;
	std:: cout << "current: " <<              this << std:: endl;
	std:: cout << "size: "    <<              size << std:: endl;
	std:: cout << "elem: "    <<              elem << std:: endl;
	std:: cout <<                                     std:: endl;
}


template<typename T>
void LIST:: List<T>:: ConsistentShow() {

	LIST:: List<T> * save = this;
	while(save) {

		( * save).Show();
		save = save->next;
	}
}
