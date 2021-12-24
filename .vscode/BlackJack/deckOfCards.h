#ifndef H_deckOfCards
#define H_deckOfCards
#include "card.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int CARDS_PER_DECK = 52;

class deckOfCards
{
private:
    card *deck;
    int currentCard;
public:
    deckOfCards();
    void shuffle();
    card dealCard();
    void printDeck() const;
};

deckOfCards::deckOfCards()
{
    string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int values[] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
    deck = new card[CARDS_PER_DECK];
    currentCard = 0;
    for (int i = 0; i < CARDS_PER_DECK; i++)
    {
        deck[i] = card(faces[i % 13], suits[i / 13], values[i % 13]);
    }
    
}

void deckOfCards::printDeck() const 
{
    cout << left;
    for (int i = 0; i < CARDS_PER_DECK; i++)
    {
        cout<<setw(19)<<deck[i].print();
        if ((i+1) % 4 == 0)
        {
            cout<<endl;
        }
        
    }
    
}

void deckOfCards::shuffle()
{
    currentCard = 0;
    for (int i = 0; i < CARDS_PER_DECK; i++)
    {
        int second = (rand() + time(0)) % CARDS_PER_DECK;
        card temp = deck[i];
        deck[i] = deck[second];
        deck[second] = temp;
    }
    
}

card deckOfCards::dealCard()
{
    if (currentCard > CARDS_PER_DECK)
    {
        shuffle();
    }
    if (currentCard < CARDS_PER_DECK)
    {
        return (deck[currentCard++]);
    }
    return (deck[0]);
}
#endif