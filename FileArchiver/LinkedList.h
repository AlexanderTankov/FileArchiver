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

#include "Hash.h"

#include <fstream>

class LinkedList
{
public:
	LinkedList();
	LinkedList(Hash* data);
	~LinkedList();
	LinkedList(const LinkedList& other); 
	LinkedList& operator=(const LinkedList& other);

public:
	void setNextElem(LinkedList* NextElem);
	void setData(Hash* Data);
	LinkedList* getNextElem() const;
	Hash* getData() const;

public:
	bool addElem(Hash* hash);
	bool addElem(string key);
	Hash* findElem(string key) const;
	void printLinkedList() const;

private:
	bool addElem(string key, LinkedList& list);
	bool addElem(Hash* hash, LinkedList& list);
	Hash* findElem(string key, const LinkedList* list) const;
	void printLinkedList(const LinkedList* list) const;

private:
	LinkedList* nextElem;
	Hash* data;
};
