#include <iostream>
#include <iterator>
#include <vector>


namespace LIST {
	
	template<class T>
	class Node {
		
		public:
			Node<T> * prev;
			Node<T> * next;
			T         elem;

			void Connect(Node<T> * head, Node<T> * tail);
			Node<T> * GetLastElem();
			Node();
			Node(T m_elem);
			~Node() {}
			void Show() const;

			bool    operator==(const Node<T> & node) {return (this->elem == node.elem); }
			bool    operator!=(const Node<T> & node) {return (this->elem != node.elem); }
			Node<T> operator= (const Node<T> & node);
			Node<T> operator= (T             m_elem);
	};
	
	template<class T>
	class List {

		public:
			Node<T> *  head;
			Node<T> *  tail;

			List(Node<T> * m_head = NULL);
			List(std:: vector<LIST:: Node<T> > & vect);
			~List() {}
			void Push(Node<T> * addNode);
			void Show(void) const;

			Node<T> * begin() {return head;              }
			Node<T> * end() {return head->GetLastElem(); }

		private:
			size_t     size; // size of List;
	};

	template<class T>
	class Iterator {

		private:
			Node<T> * head;
			Node<T> * tail;
			Node<T> * node;
			T *       elem;

		public:
			Iterator() {head = NULL; tail = NULL; node = NULL; elem = NULL;}
			Iterator<T> & insert(const Iterator<T> & iterator, T m_elem);

			void operator=(Node<T> * node);
			Iterator<T> operator+(int delta);
			Iterator<T> operator-(int delta);
			friend T operator*(Iterator<T> & iterator) {return *(iterator.elem); }
			Iterator<T> & operator++(T);
			Iterator<T> & operator--(T);
			Iterator<T> & operator+=(int delta);
			Iterator<T> & operator-=(int delta);
			//Iterator<T> & operator+(int delta);
			bool operator!=(const Iterator<T> & iterator) {return (this->elem != iterator.elem); }
			bool operator==(const Iterator<T> & iterator) {return (this->elem == iterator.elem); }
			Iterator<T> & operator=(const Iterator<T> & iterator);
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
	//list.Show(); 
	
	LIST:: Iterator<int> it1;
	LIST:: Iterator<int> it2;
	LIST:: Iterator<int> it3;
	it1 = list.begin();
	it2 = list.end();
	it3 = list.begin();

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
	it3 -= 10;
	std:: cout << "new it1: "  << *it1  << std:: endl;
	std:: cout << "new it2: "  << *it2  << std:: endl;
	std:: cout << "new it3: "  << *it3  << std:: endl;

	it3--;
	std:: cout << "new it3: "  << *it3  << std:: endl;

	it3+=5;
	std:: cout << "new it3: "  << *it3  << std:: endl;

	std:: cout << "new it3: "  << *it3  << std:: endl;
	std:: cout << "new it3: "  << *it3  << std:: endl;


	return 0;
}


//----------
// ITERATOR
//----------

template<typename T>
LIST:: Iterator<T> & LIST:: Iterator<T>:: insert(const Iterator<T> & iterator, T m_elem) {

	//(iterator.next)->elem = m_elem;

	return iterator;
}


template<class T>
LIST:: Iterator<T> LIST:: Iterator<T>:: operator+(int delta) {

	Iterator<T> CurrentIterator = * this;

	int index = 0;
	for(index = 0; index < delta; index++) {

		if(CurrentIterator.node == this->tail)
			return CurrentIterator;

		CurrentIterator.elem = &(((CurrentIterator.node)->next)->elem);
		CurrentIterator.node = (CurrentIterator.node)->next;
	}

	return CurrentIterator;
}


template<class T>
LIST:: Iterator<T> LIST:: Iterator<T>:: operator-(int delta) {

	Iterator<T> CurrentIterator = * this;

	int index = 0;
	for(index = 0; index < delta; index++) {

		if(CurrentIterator.node == this->head)
			return CurrentIterator;

		CurrentIterator.elem = &(((CurrentIterator.node)->prev)->elem);
		CurrentIterator.node = (CurrentIterator.node)->prev;
	}

	return CurrentIterator;
}


template<class T>
void LIST:: Iterator<T>:: operator=(Node<T> * m_node) {

	if(m_node - m_node->next < 0) {

		head = node = m_node;
		tail = head->prev;
		elem = &(m_node->elem);
	}

	else {

		tail = node = m_node;
		head = tail->next;
		elem = &(m_node->elem);
	}
}


template<typename T>
LIST:: Iterator<T> & LIST:: Iterator<T>:: operator=(const Iterator<T> & iterator) {

	this->elem = iterator.elem;
	this->head = iterator.head;
	this->node = iterator.node;
	this->tail = iterator.tail;

	return * this;
}


template<typename T>
LIST:: Iterator<T> & LIST:: Iterator<T>:: operator++(T) {

	if(node == tail)
		return * this;

	elem = &((node->next)->elem);
	node = node->next;

	return * this;
}


template<typename T>
LIST:: Iterator<T> & LIST:: Iterator<T>:: operator--(T) {

	if(node == head)
		return * this;

	elem = &((node->prev)->elem);
	node = node->prev;

	return * this;
}


template<typename T>
LIST:: Iterator<T> & LIST:: Iterator<T>:: operator+=(int delta) {

	int i = 0;
	for(i = 0; i < delta; i++) {

		if(node == tail)
			return * this;

		elem = &((node->next)->elem);
		node = node->next;
	}

	return * this;
}


template<typename T>
LIST:: Iterator<T> & LIST:: Iterator<T>:: operator-=(int delta) {

	int i = 0;
	for(i = delta; i > 0; i--) {

		if (node == head)
			return * this;
		
		elem = &((node->prev)->elem);
		node = node->prev;
	}

	return * this;
}


//------
// LIST
//------

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
LIST:: Node<T> * LIST:: Node<T>:: GetLastElem() {

	LIST:: Node<T> * save = this;
	while(save->next != this)
		save = save->next;

	return save;
}


//------
// NODE
//------

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
LIST:: Node<T> LIST:: Node<T>:: operator=(const LIST:: Node<T> & node) {
	
	this->elem = node.elem;
	return node.elem;
}


template<class T>
LIST:: Node<T> LIST:: Node<T>:: operator=(T m_elem) {

	this->elem = m_elem;
	return m_elem;
}
