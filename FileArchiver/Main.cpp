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

using namespace std;

int main()
{
	Hash htest('a');
	htest.setValue(3);

	LinkedList ltest(&htest);
	ltest.addElem('b');

	HashTable tabletest;
	tabletest.pushKey('c');

	return 0;
}