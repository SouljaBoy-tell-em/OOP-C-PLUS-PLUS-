#include <iostream>
#include <iterator>
#include <vector>


namespace LIST {

	template<typename T>
	class List {

		private:
			List<T> *         next;
			List<T> *         prev;
			static uint64_t * head;
			static uint64_t * tail;
			static size_t     size; // size of List;
			T                 elem;

		public:
			void Connect(T m_elem, List<T> * prevElem = NULL);
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

	std:: vector<int> v(5);

	LIST:: List<int>   list1;
	LIST:: List<int>   list2;
	LIST:: List<int>   list3;
	list1.Connect(1,   NULL);
	list2.Connect(2, &list1);
	list3.Connect(3, &list2);

	list1.Show();
	std:: cout << std:: endl << std:: endl;
	list2.Show();
	std:: cout << std:: endl << std:: endl;
	list3.Show();


	return 0;
}


template<typename T>
LIST:: List<T>:: List() {

	next = prev = NULL;
	size = 0;
}


template<typename T>
LIST:: List<T>:: List(std:: vector<T> v) {


}


template<typename T>
void LIST:: List<T>:: Connect(T m_elem, List<T> * prevElem) {

	if (!size) {

		tail = (uint64_t * )this;
		head = (uint64_t * )tail;
		next = NULL;
		prev = prevElem;
		size++;
		elem = m_elem;

		return;
	}

	tail = (uint64_t *)this;
	next = NULL;
	prev = prevElem;
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
}
