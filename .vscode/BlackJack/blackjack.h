#include "deckOfCards.h"
#include "card.h"

using namespace std;

class BlackJack
{
private:
    deckOfCards deck;
    int cardIndex = 0;
    int player = 0;
    int playerMoney = 1000;
    int bet;
    int dealer = 0;
    // card playerCards[];
    string answer;
    string answer2;
    card playerCardOne;
    card playerCardTwo;
    card playerCardThree;
    card dealerCardOne;
    card dealerCardTwo;
    bool busted = false;
public:
    BlackJack();
    void startGame();
    void placeBet();
    void deal();
    void decision();
    void hit();
    void stay();
    void doubleDown();
    void playAgain();
    void bust();
    void lose();
    void win();
    void outOfMoney();
    void endGame();
};

BlackJack::BlackJack()
{
}

void BlackJack::startGame()
{
    cout << "Welcome to BlackJack! Would you like to play? (y/n)" << endl;
    cin >> answer;
    if (answer == "y")
    {
        cout << "Please place a bet! You start off with $1000." << endl;
        placeBet();
    }
    else cout << "Thanks for coming!";
}

void BlackJack::placeBet()
{
    cout << "I bet $";
    cin >> bet;
    if (bet > playerMoney)
    {
        cout << "You do not have the funds, you only have $" << playerMoney << endl;
        placeBet();
    }
    cout << "Thank you, ";
    deal();
}

void BlackJack::deal()
{
    deck.shuffle();
    playerCardOne = deck.dealCard();
    cout << "your first card is: " << playerCardOne.print() << endl << endl;
    player = playerCardOne.getValue(); 
    dealerCardOne = deck.dealCard();
    dealer = dealerCardOne.getValue();
    cout << "The dealer's first card is hidden. " << endl << endl;
    playerCardTwo = deck.dealCard();
    player += playerCardTwo.getValue(); 
    dealerCardTwo = deck.dealCard();
    dealer += dealerCardTwo.getValue();
    cout << "Your second card is: " << playerCardTwo.print() << endl << endl;
    cout << "The dealer's  second card is: " << dealerCardTwo.print() << endl << endl;
    cout << "Your total is " << player << endl << endl;
    decision();
}

void BlackJack::decision()
{
    cout << "Would you like to hit or stay?" << endl;
    cin >> answer;
    cout << endl << endl;
    if (answer == "hit" || answer == "Hit")
    {
        hit();
    }
    else if (answer == "stay" || answer == "Stay")
    {
        stay();
    }
}

void BlackJack::hit()
{
    playerCardThree = deck.dealCard();
    player += playerCardThree.getValue();
    if (player > 21)
    {
        bust();
    }
    else 
    {
        cout << "Your next card is: " << playerCardThree.print() << endl << endl << "Your total is " << player << endl << endl;
        decision();
    }
}

void BlackJack::stay() 
{
    cout << "You stayed with " << player << endl << endl;
    cout << "The dealers first card was " << dealerCardOne.print() << endl << "The dealers total is " << dealer << endl << endl;
    if (dealer >= player)
    {
        lose();
    }
    else 
    {
        win();
    }
    
}

void BlackJack::bust()
{
    cout << "You busted!" << endl;
    cout << "Your last card is: " << playerCardThree.print() << endl << endl << "Your total is " << player << endl << endl;
    playerMoney -= bet;
    playAgain();
}

void BlackJack::lose()
{
    cout << "You lost!" << endl << endl;
    playerMoney -= bet;
    playAgain();
}

void BlackJack::win()
{
    cout << "You won!" << endl << endl;
    playerMoney += bet;
    playAgain();
}

void BlackJack::playAgain()
{
    if (playerMoney == 0)
    {
        outOfMoney();
    }
    else
    {
        cout << "You have $" << playerMoney << " left, would you like to play again? (y/n)" << endl;
        cin >> answer;
        if (answer == "y")
        {
            placeBet();
        }
        else
        {
            endGame();
        }
    }
}

void BlackJack::outOfMoney()
{
    cout << "You ran out of money! Thank you for playing and come again!" << endl;
}

void BlackJack::endGame()
{
    cout << "Thank you for playing and come again!" << endl;
    system("PAUSE");
}