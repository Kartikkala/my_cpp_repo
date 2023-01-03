#include <stdlib.h>
#include <assert.h>
#include <iostream>

template<typename T> struct Node {
	T value;
	Node* next = nullptr;
};

template<typename T> struct Pool {
	Node <T>* data;
	unsigned used = 0;
	unsigned length;
	Node <T>* free = nullptr;
	Pool(void *memory, unsigned sizeInBytes) {
		this->data = (Node<T>*)memory;
		this->length = sizeInBytes / sizeof(Node<T>);
	}
	T* take() {
		if (this->free) {
			Node<T>* node = this->free;
			this->free = node->next;
			return &node->value;
		}
		if (this->used >= this->length) {
			return nullptr;
		}
		Node<T>* node = &this->data[this->used];
		this->used++;
		return &node->value;
	}
	void give(T* value) {
		// Assert this pool owns the pointer
		assert(
			(unsigned long long)value >= (unsigned long long)this->data &&
			(unsigned long long)value < (unsigned long long)(this->data + this->length)
		);
		Node<T>* node = (Node<T>*)value;
		node->next = this->free;
		this->free = node;
	}
};


// == Usage ==

struct Foo {
	int foo;
	int bar;
};

int main() {
    int a;
	unsigned long size = sizeof(Node<Foo>) * 1024*1024*128;
    std::cout<<sizeof(Node<Foo>);
	void *mem = malloc(size);
	Pool<Foo> pool = Pool<Foo>(mem, size);

	Foo* foo = pool.take();

    for(int i=0;i<1024*1024*128;i++)
    {
        foo[i].bar = 10;
    }
    std::cout<<"enter input: ";
    std::cin>>a;

	pool.give(foo);

    std::cin>>a;

	Foo* foo2 = pool.take();

    std::cin>>a;
	assert(foo == foo2);
}