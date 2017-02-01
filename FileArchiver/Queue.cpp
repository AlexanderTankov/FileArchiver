/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Aleksandar Tankov
* @idnumber 71492
* @task 0
* @compiler VC
*
*/

#include "Queue.h"

PriorityQueue::PriorityQueue()
{
	this->head = NULL;
	size = 0;
}

PriorityQueue::~PriorityQueue()
{
	clear();
}

PriorityQueue::PriorityQueue(const PriorityQueue& other)
{
	this->head = other.getHead();
	this->size = other.getSize();
}

PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other)
{
	if (this != &other)
	{
		delete this->head;

		this->head = other.getHead();
		this->size = other.getSize();
	}

	return *this;
}

void PriorityQueue::push(Hash* newElem)
{
	LinkedList* temp = new LinkedList(newElem);

	if (this->head == NULL)
	{
		this->head = temp;
		size++;
	}
	else if (this->head->getNextElem() == NULL)
	{
		if (this->head->getData()->getValue() >= newElem->getValue())
		{
			temp->setNextElem(this->head);
			this->head = temp;
		}
		else
		{
			this->head->setNextElem(temp);
		}

		size++;
	}
	else
	{
		LinkedList* iter = this->head;

		//Add at first position
		if (iter->getData()->getValue() >= newElem->getValue())
		{
			temp->setNextElem(iter);
			this->head = temp;
			size++;
			return;
		}

		// this->size - 2 because we have another case for the first element and for the last element
		for (size_t i = 0; i < this->size - 2; i++)
		{
			if (iter->getNextElem()->getData()->getValue() >= newElem->getValue())
			{
				temp->setNextElem(iter->getNextElem());
				iter->setNextElem(temp);
				size++;
				return;
			}
			iter = iter->getNextElem();
		}

		if (iter->getNextElem()->getData()->getValue() >= newElem->getValue())
		{
			temp->setNextElem(iter->getNextElem());
			iter->setNextElem(temp);
		}
		else
		{
			iter->setNextElem(temp);
		}

		size++;
	}
}

Hash* PriorityQueue::pop()
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

Hash* PriorityQueue::peek() const
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
	

LinkedList* PriorityQueue::getHead() const
{
	return this->head;
}

bool PriorityQueue::isEmpty() const
{
	return size == 0;
}

size_t PriorityQueue::getSize() const
{
	return size;
}

void PriorityQueue::printQueue() const
{
	this->head->printLinkedList();
}


void PriorityQueue::clear()
{
	if (this->head != NULL)
	{
		delete this->head;
		this->head = NULL;
	}
}
