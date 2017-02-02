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

#include "HuffmanTree.h"
//#include <iostream> for debuging

HuffmanTree::HuffmanTree()
{
	this->head = NULL;
}

//TODO
HuffmanTree::HuffmanTree(PriorityQueue* queue)
{
	createTreeFromQueue(queue);
}

HuffmanTree::~HuffmanTree()
{
}

HuffmanTree::HuffmanTree(const HuffmanTree& other)
{
	this->head = other.getHead();
}

HuffmanTree& HuffmanTree::operator=(const HuffmanTree& other)
{
	if (this != &other)
	{
		this->head = other.getHead();
	}

	return *this;
}


Node* HuffmanTree::getHead() const
{
	return this->head;
}

void HuffmanTree::createTreeFromQueue(PriorityQueue* queue)
{
	if (queue->isEmpty())
	{
		return;
	}
	else if (queue->getSize() == 1)
	{
		Node temp(queue->pop());
		this->head = &temp;
	}
	else
	{
		Hash* first = queue->pop();
		Hash* second = queue->pop();

		string mergedKey = first->getKey() + second->getKey();
		int mergedValue = first->getValue() + second->getValue();

		Hash merged(mergedKey, mergedValue);

		Node nodeFirst(first);
		Node nodeSecond(second);
		Node nodeMerged(&merged);

		this->head = &nodeMerged;
		nodeMerged.left = &nodeFirst;
		nodeMerged.right = &nodeSecond;

		nodeFirst.parent = &nodeMerged;
		nodeSecond.parent = &nodeMerged;

		queue->push(&merged);

		//for debuging
		//std::cout << "====" << std::endl;
		//queue->printQueue();

		createTreeFromQueue(queue);
		
	}
}
