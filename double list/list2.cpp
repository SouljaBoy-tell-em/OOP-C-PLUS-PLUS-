#pragma GCC diagnostic ignored "-Wnon-template-friend"


#include <iostream>
#include <iterator>
#include <vector>


namespace LIST {
	
	template<class T>
	class Node {

		private:
			T         elem;
		
		public:
			Node<T> * prev;
			Node<T> * next;
			
			void Connect(Node<T> * head, Node<T> * tail);
			Node();
			Node(T m_elem);
			~Node();
			void Show() const;

			bool operator==(const Node<T> & node);
			bool operator!=(const Node<T> & node);
			Node<T> operator=(const Node<T> & node);
			Node<T> operator=(T m_elem);
	};
	
	template<class T>
	class List {

		private:
			Node<T> *  tail;
			size_t     size; // size of List;

		public:
			Node<T> *  head;

			List(Node<T> * m_head = NULL);
			List(std:: vector<LIST:: Node<T> > & vect);
			void Push(Node<T> * addNode);
			~List();
			void Show(void) const;
	};
}


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
	list.Show(); 


	return 0;
}


template<class T>
LIST:: List<T>:: List(Node<T> * m_head) {

	size = 0;
	this->Push(m_head);
}


template<typename T>
LIST:: List<T>:: List(std:: vector<LIST:: Node<T> > & vect) {
	
	size = 0;

	int index = 0;
	for(index = 0; index < vect.size(); index++)
		this->Push(&vect[index]);
}


template<class T>
LIST:: List<T>:: ~List() {

	std:: cout << "list closed." << std:: endl;
}


template<class T>
void LIST:: List<T>:: Push(Node<T> * addNode) {

	if (!size) {

		head = addNode;
		tail = addNode;
		size++;

		return;
	}

	tail->next       =    addNode;
	addNode->Connect(head,  tail);
	tail             =    addNode;
	head->prev       =       tail;
	size++;
}


template<class T>
void LIST:: List<T>:: Show(void) const {

	LIST:: Node<T> * save = head;
	while(save->next != head) {

		save->Show();
		save = save->next;
	}

	save->Show();
}


template<class T>
LIST:: Node<T>:: Node() {

	next = prev = NULL;
	elem = (T)0;
}


template<class T>
LIST:: Node<T>:: Node(T m_elem) {

	next = prev = NULL;
	elem = m_elem;
}


template<class T>
LIST:: Node<T>:: ~Node() {

	std:: cout << "node closed." << std:: endl;
}


template<class T>
void LIST:: Node<T>:: Show(void) const {

	std:: cout << "INFO NODE: "         << std:: endl;
	std:: cout << "next: "      << next << std:: endl;
	std:: cout << "prev: "      << prev << std:: endl;
	std:: cout << "elem: "      << elem << std:: endl;
	std:: cout << "current: "   << this << std:: endl;
}


template<typename T>
void LIST:: Node<T>:: Connect(Node<T> * head, Node<T> * tail) {

	next = head;
	prev = tail;
}


template<class T>
bool LIST:: Node<T>:: operator==(const LIST:: Node<T> & node) {

	return (this->elem == node.elem);
}


template<class T>
bool LIST:: Node<T>:: operator!=(const LIST:: Node<T> & node) {

	return (this->elem != node.elem);
}


template<class T>
LIST:: Node<T> LIST:: Node<T>:: operator=(const LIST:: Node<T> & node) {
	
	this->elem = node.elem;
	return node.elem;
}


template<class T>
LIST:: Node<T> LIST:: Node<T>:: operator=(T m_elem) {

	this->elem = m_elem;
	return m_elem;
}
