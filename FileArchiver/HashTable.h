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
	Hash* getKeyAndValue(string key);
	void pushHash(Hash* hash);
	void pushKey(string key);
	void pushKey(char key);
	void printTable();

private:
	void copyFrom(const HashTable& other);
	Hash* findElement(string key, const LinkedList& linkedList) const;

private:
	LinkedList* table;
};