/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Aleksandar Tankov
* @idnumber 71492
* @task 5
* @compiler VC
*
*/

#pragma once

#include "LinkedList.h"

#include <fstream>

const int TABLE_SIZE = 128;

class HashTable
{
public:
	HashTable();
	~HashTable();
	HashTable(const HashTable& other);
	HashTable& operator=(const HashTable& other);

public:
	LinkedList* getTable() const;

public:
	Hash* getKeyAndValue(char key);
	void pushKey(char key);
	void printTable();

private:
	void copyFrom(const HashTable& other);
	Hash* findElement(char key, const LinkedList& linkedList) const;

private:
	LinkedList* table;
};