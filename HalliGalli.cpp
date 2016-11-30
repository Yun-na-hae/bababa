#include <list>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iostream>

using namespace std;

class Card
{
	private :
		char c_color;
		int c_number;
	public :
		Card(char color = '*',int number = 0);
		char get_color();
		int get_number();
};

template <typename T>
class Card_list : list<T>
{
	public :
		void shuffle(int,int);
		T get(int);
		void push_back(Card);
		void pop_front();
		void swap(int n,int m);
		void insert(int index,T card);
};

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
void Card_list<T>::push_back(Card card) 
{
	list<Card>::push_back(card);
}


template <typename T>
void Card_list<T>::pop_front()
{
	list<Card>::pop_front();
}

template <typename T>
void Card_list<T>::insert(int index,T card)
{
	list<Card>::insert(index,card);
}

template <typename T>
void swap(int n,int m)
{
	T tmp;
	tmp = this->get(m);
	this->insert(m,this->get(n));	
	this->insert(n,tmp);
}

int main(void) {

	Card_list<Card> All_cards,P1_cards,P2_cards;

	char color[4] = {'G','Y','B','R'};

	//모든 카드 초기화
	for(int i = 0;i<4;i++)
		for(int j = 0;j<5;j++)
		{
			Card card(color[i],1);
			All_cards.push_back(card);
		}
	
	for(int i = 0;i<4;i++)
		for(int j = 0;j<5;j++)
		{
			Card card(color[i],2);
			All_cards.push_back(card);
		}

	for(int i = 0;i<4;i++)
		for(int j = 0;j<5;j++)
		{
			Card card(color[i],3);
			All_cards.push_back(card);
		}

	for(int i = 0;i<4;i++)
		for(int j = 0;j<5;j++)
		{
			Card card(color[i],4);
			All_cards.push_back(card);
		} 

	for(int i = 0;i<4;i++)
		for(int j = 0;j<5;j++)
		{
			Card card(color[i],5);
			All_cards.push_back(card);
		} 
	//모든 카드 섞기
	All_cards.shuffle(0,55);
/*
	//Player 1과 Player 2에게 28장씩 분배
	for(int i = 0 ; i < 28 ;i++)
	{
		P1_cards.push_back(All_cards.get(0));
		All_cards.pop_front();
		P2_cards.push_back(All_cards.get(0));
		All_cards.pop_front();
	}
*/
	return 0;
}


