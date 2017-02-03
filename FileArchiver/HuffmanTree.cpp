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

HuffmanTree::HuffmanTree(PriorityQueue* queue)
{
	this->head = NULL;
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

		Hash* merged = new Hash(mergedKey, mergedValue);

		Node* nodeFirst = new Node(first);
		Node* nodeSecond = new Node(second);
		Node* nodeMerged = new Node(merged);

		this->head = nodeMerged;
		nodeMerged->left = nodeFirst;
		nodeMerged->right = nodeSecond;

		nodeFirst->parent = nodeMerged;
		nodeSecond->parent = nodeMerged;

		queue->push(merged);

		//for debuging
		//std::cout << "====" << std::endl;
		//queue->printQueue();

		createTreeFromQueue(queue);
		
	}
}

HashTable* HuffmanTree::generateBinaryHash()
{
	HashTable table;

	generateBinaryHash(this->head, table);

	return &table;
}

void HuffmanTree::printTree() const
{
	printTree(this->head);
}


//TODO: da dobavq da vzima i koda
HashTable* HuffmanTree::generateBinaryHash(Node* root, HashTable& table)
{
	if (root->left == NULL && root->right == NULL)
	{
		table.pushHash(root->value);
	}
	else
	{
		generateBinaryHash(root->left, table);
		generateBinaryHash(root->right, table);
	}

	return &table;
}

//TODO:It doesnt work because when generating the tree i push in the queue Hash objects not Node objects and because of that
//the pointers of the childs are lost
void HuffmanTree::printTree(Node* root) const
{
	if (root->left == NULL && root->right == NULL)
	{
		root->value->printHash();
		return;
	}
	else
	{
		printTree(root->left);
		printTree(root->right);
	}
}