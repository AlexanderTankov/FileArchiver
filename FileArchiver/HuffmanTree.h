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

#include "Queue.h"
#include "HashTable.h"

struct Node
{
	Node(Hash* hash)
	{
		this->value = hash;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}

	Hash* value;
	Node* parent;
	Node* left;
	Node* right;
};

class HuffmanTree
{
public:
	HuffmanTree();
	HuffmanTree(PriorityQueue* queue);
	~HuffmanTree();
	HuffmanTree(const HuffmanTree& other);
	HuffmanTree& operator=(const HuffmanTree& other);

public:
	Node* getHead() const;
	void createTreeFromQueue(PriorityQueue* queue);
	HashTable* generateBinaryHash();

private:
	HashTable* generateBinaryHash(Node* root, HashTable& table);

private:
	Node* head;
};
