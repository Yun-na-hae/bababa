#ifndef _HALLI_H_
#define _HALLI_H_

#include <list>

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
		void shuffle(int pre,int pos);
		T get(int i);
		void push_back(Card);
};


#endif
