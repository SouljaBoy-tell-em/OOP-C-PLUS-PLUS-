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
			Iterator<T> & insert(T m_elem);
			Iterator<T> & erase();

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
