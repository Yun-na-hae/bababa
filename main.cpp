#include "Halli.h"
#include "Halli.cpp"
#include <cstdio>
#include <iostream>

int main() {

	Card_list<Card> All_cards,P1_cards,P2_cards;

	char color[4] = {'G','Y','B','R'};

	for(int i = 0;i<4;i++)
		for(int j = 0;j<5;j++)
		{
			Card card(color[i],1);
			All_cards.push_back(card);
		}

	return 0;
}
