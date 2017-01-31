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

#include <iostream>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	this->nextElem = NULL;
	this->data = NULL;
}

LinkedList::LinkedList(Hash* data)
{
	this->nextElem = NULL;
	this->data = data;
}

LinkedList::~LinkedList()
{
}

LinkedList::LinkedList(const LinkedList& other)
{
	this->data = other.getData();
	this->nextElem = other.getNextElem();
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this != &other)
	{
		delete this->data;
		delete this->nextElem;

		this->data = other.getData();
		this->nextElem = other.getNextElem();
	}

	return *this;
}


void LinkedList::setNextElem(LinkedList* NextElem)
{
	this->nextElem = NextElem;
}

void LinkedList::setData(Hash* Data)
{
	this->data = Data;
}

LinkedList* LinkedList::getNextElem() const
{
	return this->nextElem;
}

Hash* LinkedList::getData() const
{
	return this->data;
}


bool LinkedList::addElem(char key)
{
	return addElem(key, *this);
}

Hash* LinkedList::findElem(char key) const
{
	return findElem(key, this);
}

/*
void LinkedList::printLinkedList() const
{
	printLinkedList(this);
}*/


bool LinkedList::addElem(char key, LinkedList& list)
{
	if (list.getData() == NULL)
	{
		Hash* newD = new Hash(key);
		list.setData(newD);
		return true;
	}
	else if (list.getData() != NULL && list.getNextElem() == NULL)
	{
		if (list.getData()->getKey() == key)
		{
			list.getData()->setValue(list.getData()->getValue() + 1);
			return true;
		}
		else
		{
			Hash* newD = new Hash(key);
			LinkedList* newL = new LinkedList(newD);
			list.setNextElem(newL);
			return true;
		}
	}
	else
	{
		return addElem(key, *list.getNextElem());
	}

	return false;
}

Hash* LinkedList::findElem(char key, const LinkedList* list) const
{
	if (list->getData() == NULL)
	{
		return NULL;
	}
	else if (list->getData()->getKey() == key)
	{
		return list->getData();
	}
	else
	{
		return findElem(key, list->getNextElem());
	}
}

/*
void LinkedList::printLinkedList(const LinkedList* list) const
{
	if (list->getData() != NULL)
	{
		cout << list->getData()->getKey() << " : " << list->getData()->getValue() << endl;
		if (list->getNextElem() != NULL)
		{
			printLinkedList(list->getNextElem());
		}
	}
}*/