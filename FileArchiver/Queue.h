#include "LinkedList.h"

#pragma once

class Queue
{
public:
	Queue();
	~Queue();
	Queue(const Queue& other);
	Queue& operator=(const Queue& other);

public:
	void push(Hash* data);
	Hash* pop();
	Hash* peek() const;

public:
	LinkedList* GetHead() { return head; }
	void split(Queue* dest/*out*/);
	bool isEmpty() const;
	void clear();
	size_t getSize() const;

private:
	LinkedList* head;
	size_t size;
};
