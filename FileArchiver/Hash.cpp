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

#include "Hash.h"

#include <iostream>

using namespace std;

Hash::Hash(string Key)
{
	this->key = Key;
	this->value = 1;
}

Hash::Hash(string Key, int Value)
{
	this->key = Key;
	this->value = Value;
}

Hash::~Hash()
{
}

Hash::Hash(const Hash& other)
{
	this->key = other.getKey();
	this->value = other.getValue();
}

Hash& Hash::operator=(const Hash& other)
{
	if (this != &other)
	{
		this->key = other.getKey();
		this->value = other.getValue();
	}

	return *this;
}

void Hash::setValue(int Value)
{
	this->value = Value;
}

string Hash::getKey() const
{
	return this->key;
}

int Hash::getValue() const
{
	return this->value;
}

void Hash::printHash() const
{
	cout << this->key << " : " << this->value << endl;
}