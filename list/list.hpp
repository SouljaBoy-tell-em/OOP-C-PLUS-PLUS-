

//----------
// ITERATOR
//----------

template<typename T>
LIST:: Iterator<T> & LIST:: Iterator<T>:: insert(T m_elem) {

	Node<T> * NewNode = (Node<T> * ) malloc(sizeof(Node<T>));
	NewNode->next = this->node->next;
	NewNode->prev = this->node;
	NewNode->elem = m_elem;

	this->node->next = NewNode;
	this->node->next->next->prev = NewNode;

	/*

	std:: cout << "this->node: " << this->node << std:: endl;
	std:: cout << "this->node: " << this->node->next << std:: endl;
	std:: cout << "node.next: " << NewNode->next << std:: endl;
	std:: cout << "node.prev: " << NewNode->prev << std:: endl;
	std:: cout << "node: "       << &NewNode    << std:: endl;

	*/

	return * this;
}


template<typename T>
LIST:: Iterator<T> & LIST:: Iterator<T>:: erase() {

	this->node->next->prev = this->node->prev;
	this->node->prev->next = this->node->next;
	this->node = this->node->next;
	this->elem = &(this->node->prev->elem);

	return * this;
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
