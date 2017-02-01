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

#include "LinkedList.h"

#pragma once

class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();
	PriorityQueue(const PriorityQueue& other);
	PriorityQueue& operator=(const PriorityQueue& other);

public:
	void push(Hash* newElem);
	Hash* pop();
	Hash* peek() const;

public:
	LinkedList* getHead() const;
	bool isEmpty() const;
	size_t getSize() const;
	void printQueue() const;

private:
	void clear();

private:
	LinkedList* head;
	size_t size;
};
