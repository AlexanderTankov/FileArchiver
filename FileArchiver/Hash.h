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

class Hash
{
public:
	Hash(char Key);
	Hash(char Key, int Value);
	~Hash();
	Hash(const Hash& other);
	Hash& operator=(const Hash& other);

public:
	void setValue(int Value);
	char getKey() const;
	int getValue() const;

private:
	char key;
	int value;
};