#ifndef BINGOCARDS_DECK_H
#define BINGOCARDS_DECK_H

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

class Deck {
private:
    unsigned int m_boardSize;
    unsigned int m_numCards;
    unsigned int m_maxValue;
    std::vector<Card> m_cards;

    std::string contentSpacer(unsigned int content);
    void printTopBottom(std::ostream& printLoc);
    void printFiller(std::ostream& printLoc);
public:
    //Methods
    void printDeck(std::ostream& printLoc);
    void printCard(unsigned int card, std::ostream& printLoc);
    std::vector<Card> getCards() { return m_cards;}

    //Constructors
    Deck(unsigned int size, unsigned int cards, unsigned int maxValue);
    ~Deck(){} //There are no pointers to clean in this class
};


#endif //BINGOCARDS_DECK_H
