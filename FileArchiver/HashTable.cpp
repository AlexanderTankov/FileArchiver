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

#include "HashTable.h"

//#include <iostream> for testing

using namespace std;

HashTable::HashTable()
{
	this->table = new LinkedList[TABLE_SIZE];
}

HashTable::~HashTable()
{
	delete[] this->table;
}

HashTable::HashTable(const HashTable& other)
{
	copyFrom(other);
}

HashTable& HashTable::operator=(const HashTable& other)
{
	if (this != &other)
	{
		delete[] this->table;
		copyFrom(other);
	}

	return *this;
}


LinkedList* HashTable::getTable() const
{
	return this->table;
}


Hash* HashTable::getKeyAndValue(char key)
{
	int indexInArray = key % TABLE_SIZE;

	return findElement(key, this->table[indexInArray]);
}

void HashTable::pushKey(char key)
{
	int indexInArray = key % TABLE_SIZE;

	this->table[indexInArray].addElem(key);
}


void HashTable::printTable()
{
	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		this->table[i].printLinkedList();
	}
}


void HashTable::copyFrom(const HashTable& other)
{
	this->table = new LinkedList[TABLE_SIZE];

	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		this->table[i] = other.getTable()[i];
	}
}

Hash* HashTable::findElement(char key, const LinkedList& linkedList) const
{
	return linkedList.findElem(key);
}
