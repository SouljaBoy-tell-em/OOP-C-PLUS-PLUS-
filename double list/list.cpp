#include <iostream>
#include <iterator>
#include <vector>


template <typename T>
class List {

	private:
		List * next;
		List * prev;
		List * head;
		List * tail;
		size_t    size; // size of List;

		friend 

	public:
		List();
		List(int num);
		List(std:: vector<T> vect);
		~List();
		void Show(void) const;
};


int main(void) {

	std:: vector<int> v(5);

	int i = 0;
	for(i = 0; i < 5; i++)
		v[i] = i + 1;

	List<int> list(v);
 

	return 0;
}


template <typename T>
List<T>:: List() {

	next = prev = head = tail = NULL;
	size = 0;
}


template <typename T>
List<T>:: List(std:: vector<T> v) {


}


template <typename T>
List<T>:: List(int num) {


}


template <typename T>
List<T>:: ~List() {

	std:: cout << "closed." << std:: endl;
}

template <typename T>
void List<T>:: Show(void) const {

	std:: cout << "INFO:"          << std:: endl;
	std:: cout << "next: " << next << std:: endl;
	std:: cout << "prev: " << prev << std:: endl;
	std:: cout << "head: " << head << std:: endl;
	std:: cout << "tail: " << size << std:: endl;
}
