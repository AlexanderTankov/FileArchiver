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
#include "HuffmanTree.h"

#include <iostream>

using namespace std;

int main()
{
	Hash htest("a");
	htest.setValue(3);

	LinkedList ltest(&htest);
	ltest.addElem("b");

	HashTable tabletest;

	string pesho = "Hello world";

	for (size_t i = 0; i < 11; i++)
	{
		tabletest.pushKey(pesho[i]);
	}

	tabletest.printTable();

	PriorityQueue qtest;
	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		if (tabletest.getTable()[i].getData() != NULL)
			qtest.push((tabletest.getTable()[i].getData()));
	}

	//for debuging
	std::cout << "======================" << std::endl;
	qtest.printQueue();

	HuffmanTree tree(&qtest);

	//tree.printTree();

	return 0;
}