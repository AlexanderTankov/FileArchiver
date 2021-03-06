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

#include <string>

using namespace std;

class Hash
{
public:
	Hash(string Key);
	Hash(string Key, int Value);
	~Hash();
	Hash(const Hash& other);
	Hash& operator=(const Hash& other);

public:
	void setValue(int Value);
	string getKey() const;
	int getValue() const;
	void printHash() const;

private:
	string key;
	int value;
};