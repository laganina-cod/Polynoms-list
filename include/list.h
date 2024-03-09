#pragma once
#include <iostream>

template <typename T>
class myNode {
	T data;
	myNode* next;
public:
	myNode(const T& _data, myNode* _next = nullptr) {
		this->data = _data;
		this->next = _next;
	}
	myNode() {
		this->data = 0;
		this->next = nullptr;
	}
	myNode(const myNode& other) {
		this->data = other.data;
		this->
	}
	template <typename U>
	friend class myList;
	template <typename K>
	friend class myIteraror;
};
template <typename  T>

class myList  {
	myNode<T>* head;
	size_t sz;

public:

	myList() {
		sz = 0;
		head = nullptr;
	}
	void push_front(const T& el) {
		if (head) {
			myNode<T>* node = new myNode<T>;
			node->data = el;
			node->next = head;
			head = node;
		}
		else {
			myNode<T>* node = new myNode<T>(el);
			head = node;
		}
		sz++;
	}
	void push_back(const T& el) {
		if (head) {
			myNode<T>* current = head;
			while (current->next) {
				current = current->next;
			}
			myNode<T>* node = new myNode<T>(el);
			current->next = node;
		}
		else {
			myNode<T>* node = new myNode<T>(el);
			head = node;
		}
		sz++;
	}
	T pop_front() {
		if (head) {
			myNode<T>* next = head->next;
			T data = head->data;
			delete head;
			head = next;
			sz--;
			return data;
		}
		else {
			throw "list is empty";
			return 0;
		}
	}
	T pop_back() {
		if (head == nullptr) {
			throw "list is empty";
			return 0;
		}
		else {
			myNode<T>* prev = head;
			while (prev->next->next) {
				prev = prev->next;
			}
			T data = prev->next->data;
			delete prev->next;
			prev->next = nullptr;
			sz--;
			return data;
		}
	}
	~myList() {
		myNode<T>* current = head;
		while (current) {
			myNode<T>* next = current->next;
			delete current;
			current = next;
		};
	}
	size_t size() {
		return sz;
	}
	myNode<T> * Head() {
		return head;
	}

	void insert(int pos,  T _data) {
		myNode<T>* current = head;
		for (int i = 0; i < pos - 1; i++) {
			current = current->next;
		}
		myNode<T>* middle = current->next;
		myNode<T>* el = new myNode<T>;
		el->data = _data;
		current->next = el;
		el -> next = middle;
	}
	T search(int pos) {
		myNode<T>* current = head;
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}
		return current->data;
	}
	T delete_el(int pos) {
		myNode<T>* current = head;
		for (int i = 0; i < pos - 1; i++) {
			current = current->next;
		}
		myNode<T>* new_prev = current;
		myNode<T>* elem_to_delete = current->next;
		T  data = elem_to_delete->data;
		current->next = current->next->next;
		delete elem_to_delete;
		return data;
	}
	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const myList<U>& list);
	template <typename K>
	friend std::istream& operator>>(std::istream& is, const myList<K>& list);
	class myIterator {
		myNode* current;
	public:
		myIterator() {
			current = nullptr;
		}
		myIterator(myNode* el) {
			current = el;
		}
		myIterator(const myIterator& other) {
			current = other.current;
		}
		myIterator& operator++() {
			current = current->next;
			return *this;
		}
		T& operator*() {
			return current->data;
		}
		bool operator==(const myIterator& other) {
			return (this->current == other.current);
		}
		bool operator !=(const myIterator& other) {
			return (this->current != other.current);
		}
		myIterator begin() {
			return Iterator(head);
		}
		myIterator end() {
			return  Iterator(nullptr);
		}

	};
};

template <typename T>

std::ostream& operator<<(std::ostream& os, const myList<T>& list) {
	myNode* current = list.head;
	os << "List size=" << sz << " / n";
	while (current) {
		os << current->data << " / n";
		current = current->next;
	}
	return os;
}
template <typename T>
std::istream& operator>>(std::istream& is, const myList<T>& list) {
	int n;
	is >> n;
	T data;
	if (list.head) {
		throw "List isn't empty"
	}
	else {
		for (int i = 0; i < n; i++) {
			is >> data;
			myNode* el = new myNode(data);
			push_back(el);
		}
	}
	return is;
}

