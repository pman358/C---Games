#ifndef H_card
#define H_card
#include <string>
#include <iostream>

using namespace std;

class card
{
private:
    string face;
    string suit;
    int value;
public:
    card(string cardFace, string cardSuit, int cardValue);
    int getValue();
    string print() const;
    card();
};

card::card(string cardFace, string cardSuit, int cardValue)
{
    face = cardFace;
    suit = cardSuit;
    value = cardValue;
}

card::card()
{
}

string card::print() const
{
    return (face + " of " + suit);
}

int card::getValue() 
{
    return (value);
}
#endif