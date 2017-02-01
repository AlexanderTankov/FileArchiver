#include "Queue.h"
#include <iostream>

Queue::Queue()
{
	this->head = NULL;
	size = 0;
}

Queue::~Queue()
{
}

Queue::Queue(const Queue& other)
{
	//TODO
}

Queue& Queue::operator=(const Queue& other)
{
	//TODO
	return *this;
}


void Queue::push(Hash* newElem)
{
	//TODO: Make it priority
	LinkedList* temp = new LinkedList(newElem);
	temp->setNextElem(head);
	head = temp;
	size++;
}

Hash* Queue::pop()
{
	Hash* result = NULL;
	if (size == 0)
	{
		return result;
	}
	else if (size == 1)
	{
		LinkedList* temp = this->head;
		result = temp->getData();
		this->head = NULL;
		delete temp;
		this->size--;
		return result;
	}
	else
	{
		for (LinkedList* i = this->head; i->getNextElem()->getNextElem() != NULL; i = i->getNextElem())
		{
			if (i->getNextElem() == NULL)
			{
				LinkedList* temp = i->getNextElem();
				result = temp->getData();
				i->setNextElem(NULL);
				delete temp;
				size--;
			}
		}
		return result;
	}
}

Hash* Queue::peek() const
{
	Hash* result = NULL;
	if (size == 0)
	{
		return result;
	}
	else if (size == 1)
	{
		result = this->head->getData();
		return result;
	}
	else
	{
		LinkedList* i = this->head;
		for (; i->getNextElem() != NULL; i = i->getNextElem()){}
		return i->getData();
	}
}
	
	
//TODO: to check is it needed
void Queue::split(Queue* dest/*out*/)
{
	int needed = this->getSize() / 2;
	LinkedList* destHead = dest->GetHead();
	destHead = this->head;
	for (LinkedList* i = this->head; i->getNextElem()->getNextElem() != NULL; i = i->getNextElem(), needed--)
	{
		if (needed == 0)
		{
			this->head = i->getNextElem();
			i->setNextElem(NULL);
			return;
		}
	}
}

bool Queue::isEmpty() const
{
	return size == 0;
}

void Queue::clear()
{
	//TODO: If head != NULL delete this->head i posle recursivno
	this->head = NULL;
}

size_t Queue::getSize() const
{
	return size;
}