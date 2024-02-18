#pragma once
template <typename T>
class myNode {
	T data;
	myNode* next;
	myNode(const T& _data, myNode* _next = nullptr) {
		this->data = _data;
		this->next = _next;
	}
	myNode() {
		this->data = 0;
		this->next = nullptr;
	}
	template <typename U>
	friend class myList;
	template <typename K>
	friend class myIteraror;
};
template <typename  T>



class myList {
	myNode* head;
	size_t sz;
public:
	myList() {
		sz = 0;
		head = nullptr;
	}
	void push_front(const T& el) {
		if (head) {
			myNode* node = new myNode;
			node->data = el;
			node->next = head;
			head = node;
		}
		else {
			myNode* node = new myNode(el);
			head = node;
		}
		sz++;
	}
	void push_back(const T& el) {
		if (head) {
			myNode* current = head;
			while (current->next) {
				current = current->next;
			}
			myNode* node = new myNode(el);
			current->next = node;
		}
		else {
			myNode* node = new myNode(el);
			head = node;
		}
		sz++;
	}
	 T pop_front() {
		if (head) {
			myNode* next = head->next;
			T data = head->data;
			delete head;
			haed = next;
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
			 myNode* prev = head;
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
	 ~mylist() {
		 myNode* current = head;
		 while (current) {
			 myNode* next = current->next;
			 delete current;
			 current = next;
		 };
	 }
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
