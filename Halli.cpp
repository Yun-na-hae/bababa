#include "Halli.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Card::Card(char color,int number)
{
	this->c_color = color;
	this->c_number = number;
}

char Card::get_color()
{
	return this->c_color;
}

int Card::get_number()
{
	return this->c_number;
}

template <typename T>
void Card_list<T>::shuffle(int pre,int pos)
{
	if(pos<pre)
	{
		throw "pos must smaller than pre";
	}

	if(pos > this->size())
	{
		throw "Out of Index";
	}

	srand((unsigned)time(NULL));

	for(int i = 0;i<100;i++)
	{
		int n = rand()%(pos-pre) + pre;
		int m = rand()%(pos-pre) + pre;

		this->swap(n,m);
	}

}

template <typename T>
T Card_list<T>::get(int i)
{
	if(i > this->size()-1)
	{
		throw "Out of Index";
	}

	typename Card_list<T>::iterator iter;

	iter = this->begin();

	for(int j = 0;j<i;j++)
	{
		iter++;
	}

	return *iter;

}

template <typename T>
void Card_list<T>::push_back(Card card) {
	list<Card>::push_back(card);
}

