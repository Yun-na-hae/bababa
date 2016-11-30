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
		void set_card(Card card);
};

template <typename T>
class Card_list : public list<T>
{
	public :
		void shuffle(int,int);
		T get(int);
		void push_back(Card);
		void pop_front();
		void swap(int n,int m);
		void insert(typename Card_list<T>::iterator iter,T card);
		bool compare(T p1_card,T p2_card);
};

Card_list<Card> All_cards,P1_cards,P2_cards;	//전역변수 설정

bool p1_win,p2_win;	//누가 이겼는 지 


Card::Card(char color,int number)
{
	this->c_color = color;
	this->c_number = number;
}

void Card::set_card(Card card)
{
	this->c_color = card.get_color();
	this->c_number = card.get_number();
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
bool Card_list<T>::compare(T p1_card,T p2_card)
{
	if(p1_card.get_color() == p2_card.get_color())
	{
		if((p1_card.get_number() + p2_card.get_number()) == 5)
			return 1;
		else
			return 0;
	}
	else 
	{
		if(p1_card.get_number() == 5 || p2_card.get_number() == 5)
			return 1;
		else
			return 0;
	}
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
void Card_list<T>::insert(typename Card_list<T>::iterator iter,T card)
{
	list<Card>::insert(iter,card);
}

	template <typename T>
void Card_list<T>::swap(int n,int m)
{

	typename Card_list<T>::iterator iter1 = this->begin();
	typename Card_list<T>::iterator iter2 = this->begin();

	if(n == 55 || m == 55)
	{
		n--;m--;
	}
	for(int i = 0;i<n;i++)
		iter1++;
	for(int i = 0;i<m;i++)
		iter2++;

	T tmp = (this->get(n));

	(iter1)->set_card((this->get(m)));
	(iter2)->set_card(tmp);

}

void Game_start()	//게임을 시작시키는 전역함수
{
	//	Card_list<Card> All_cards,P1_cards,P2_cards;

	p1_win = p2_win = 0;

	char color[4] = {'G','Y','B','R'};

	//모든 카드 초기화
	for(int i = 0;i<4;i++)
		for(int j = 0;j<5;j++)
		{
			Card card(color[i],1);
			All_cards.push_back(card);
		}

	for(int i = 0;i<4;i++)
		for(int j = 0;j<3;j++)
		{
			Card card(color[i],2);
			All_cards.push_back(card);
		}

	for(int i = 0;i<4;i++)
		for(int j = 0;j<3;j++)
		{
			Card card(color[i],3);
			All_cards.push_back(card);
		}

	for(int i = 0;i<4;i++)
		for(int j = 0;j<2;j++)
		{
			Card card(color[i],4);
			All_cards.push_back(card);
		} 

	for(int i = 0;i<4;i++)
		for(int j = 0;j<1;j++)
		{
			Card card(color[i],5);
			All_cards.push_back(card);
		} 
	//모든 카드 섞기
	All_cards.shuffle(0,55);

	//모든 카드 출력해보기 
	/*
	   for(Card_list<Card>::iterator iter = All_cards.begin();iter != All_cards.end();iter++)
	   {
	   cout<<"Color : "<<iter->get_color()<<endl;
	   cout<<"Number : "<<iter->get_number()<<endl;
	   cout<<"________________"<<endl;
	   }
	 */	//result : 실제로 모든 카드가 섞인 것을 확인

	//Player 1과 Player 2에게 28장씩 분배
	for(int i = 0 ; i < 28 ;i++)
	{
		P1_cards.push_back(All_cards.get(0));
		All_cards.pop_front();
		P2_cards.push_back(All_cards.get(0));
		All_cards.pop_front();
	}

	//Player1과 Player2의 카드 출력해보기
	/*
	   cout<<"===Player1' Cards==="<<endl<<endl;

	   for(Card_list<Card>::iterator iter = P1_cards.begin();iter != P1_cards.end();iter++)
	   {
	   cout<<"Color : "<<iter->get_color()<<endl;
	   cout<<"Number : "<<iter->get_number()<<endl;
	   cout<<"________________"<<endl;
	   }

	   cout<<"===Player2' Cards==="<<endl<<endl;

	   for(Card_list<Card>::iterator iter = P2_cards.begin();iter != P2_cards.end();iter++)
	   {
	   cout<<"Color : "<<iter->get_color()<<endl;
	   cout<<"Number : "<<iter->get_number()<<endl;
	   cout<<"________________"<<endl;
	   }

	   cout<<"===All_cards' Cards==="<<endl<<endl;

	   for(Card_list<Card>::iterator iter = All_cards.begin();iter != All_cards.end();iter++)
	   {
	   cout<<"Color : "<<iter->get_color()<<endl;
	   cout<<"Number : "<<iter->get_number()<<endl;
	   cout<<"________________"<<endl;
	   }
	 */	//result : Player1과 Player2에게 임의의 28개 카드 모두 분배, All_cards list = NULL
}

// 디버깅을 위한 All_cards,P1_cards,P2_cards 의 카드 상태를 보여주는 출력 전용 함수
void Print()
{
	cout<<"===Player1' Cards==="<<endl<<endl;

	for(Card_list<Card>::iterator iter = P1_cards.begin();iter != P1_cards.end();iter++)
	{
		cout<<"Color : "<<iter->get_color()<<endl;
		cout<<"Number : "<<iter->get_number()<<endl;
		cout<<"________________"<<endl;
	}

	cout<<"===Player2' Cards==="<<endl<<endl;

	for(Card_list<Card>::iterator iter = P2_cards.begin();iter != P2_cards.end();iter++)
	{
		cout<<"Color : "<<iter->get_color()<<endl;
		cout<<"Number : "<<iter->get_number()<<endl;
		cout<<"________________"<<endl;
	}

	cout<<"===All_cards' Cards==="<<endl<<endl;

	for(Card_list<Card>::iterator iter = All_cards.begin();iter != All_cards.end();iter++)
	{
		cout<<"Color : "<<iter->get_color()<<endl;
		cout<<"Number : "<<iter->get_number()<<endl;
		cout<<"________________"<<endl;
	}

}

int main(void) {

	Game_start();

	//	Print();

	bool Game_process = 1;
	int who_rings_the_bell = 0;	//Player1가 벨을 울린 경우 : 1, Player 2가 벨을 울린 경우 : 2

	while(Game_process)
	{
		who_rings_the_bell = 0;

		//		cout<<"*********************************"<<endl;
		//		Print();

		Card_list<Card>::iterator iter_p1 = P1_cards.begin();
		Card_list<Card>::iterator iter_p2 = P2_cards.begin();

		Card p1 = *(iter_p1);
		Card p2 = *(iter_p2);

		P1_cards.pop_front();
		P2_cards.pop_front();

		All_cards.push_back(p1);
		All_cards.push_back(p2);


		if(All_cards.compare(p1,p2))	//종을 쳐야하는 상황인 경우
		{
			cin>>who_rings_the_bell;
			
			if(who_rings_the_bell == 1)	//Player 1이 종을 친 경우	=> All_cards의 카드를 P1_cards로 옮긴다.
			{
				while(All_cards.size() != 0)
				{
					Card_list<Card>::iterator iter = All_cards.begin();
					P1_cards.push_back(*iter);
					All_cards.pop_front();
				}
			}
			else if(who_rings_the_bell == 2)	//Player 2이 종을 친 경우	=> All_cards의 카드를 P2_cards로 옮긴다.
			{
				while(All_cards.size() != 0)
				{
					Card_list<Card>::iterator iter = All_cards.begin();
					P2_cards.push_back(*iter);
					All_cards.pop_front();
				}

			}

			Game_process = 1;
		}
		else	//종을 칠 상황이 아닌 경우
		{
			if(P1_cards.size() == 0 || P2_cards.size() == 0)    //두 사람 중 한 사람의 카드가 남아있지 않은 경우=> 게임 종료상황
			{
				if(P1_cards.size() == 0)	//Player2 승리
				{
					p2_win = 1;
				}
				if(P2_cards.size() == 0)	//Player1 승리
				{
					p1_win = 1;
				}
				Game_process = 0;                       //게임 종료
			}
			else	// 두 사람의 카드가 남아있는 경우 => 두 카드를 compare while 문으로 돌아가야 하는 상황
			{
				Game_process = 1;
			}
		}

	}

	return 0;
}

