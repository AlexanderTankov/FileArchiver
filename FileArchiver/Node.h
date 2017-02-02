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

class Node
{
public:
	Node();
	~Node();

private:
	Hash* value;
	Node* parent;
	Node* left;
	Node* right;
};