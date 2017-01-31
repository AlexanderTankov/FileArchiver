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
	bool addElem(char key);
	Hash* findElem(char key) const;
	//void printLinkedList() const; used only for testing

private:
	bool addElem(char key, LinkedList& list);
	Hash* findElem(char key, const LinkedList* list) const;
	//void printLinkedList(const LinkedList* list) const; used only for testing

private:
	LinkedList* nextElem;
	Hash* data;
};
