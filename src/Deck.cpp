#include <cmath>
#include "Deck.h"
#include "Error.h"

std::string Deck::contentSpacer(unsigned int content)
{
    if(log10(content) >=2)
    {
        return "";
    }
    else if(log10(content) >= 1)
    {
        return " ";
    }
    else
    {
        return "  ";
    }
}

void Deck::printTopBottom(std::ostream& printLoc)
{
    for(unsigned int i = 0; i < m_boardSize; i++)
    {
        printLoc << "+-----";
    }
    printLoc << "+" << std::endl;
}

void Deck::printFiller(std::ostream& printLoc)
{
    for(unsigned int i = 0; i < m_boardSize; i++)
    {
        printLoc << "|     ";
    }
    printLoc << "|" << std::endl;
}

void Deck::printDeck(std::ostream& printLoc)
{
    for(unsigned int i = 0; i < m_cards.size(); i++)
    {
        printCard(i, printLoc);
        printLoc << std::endl << std::endl;
    }
}

void Deck::printCard(unsigned int card, std::ostream& printLoc)
{
    printLoc << "Card #" << card << std::endl;

    for(unsigned int i = 0; i < m_boardSize; i++)
    {
        printTopBottom(printLoc);
        printFiller(printLoc);
        for(unsigned int j = 0; j < m_boardSize; j++)
        {
            printLoc << "| " << contentSpacer(m_cards[card].content[i][j]) << m_cards[card].content[i][j] << " ";
        }
        printLoc << "|" << std::endl;
        printFiller(printLoc);
    }

    printTopBottom(printLoc);
}

Deck::Deck(unsigned int size, unsigned int cards, unsigned int maxValue) :
m_boardSize(size),
m_numCards(cards),
m_maxValue(maxValue)
{
    if(m_boardSize < 3 || m_boardSize > 15) throw CardSizeRangeError;
    if(m_numCards < 3 || m_numCards > 10000) throw CardQuantityRangeError;
    if(m_maxValue < m_boardSize*m_boardSize*2 || m_maxValue > m_boardSize*m_boardSize*4) throw CardValueRangeError;

    for(unsigned int i = 0; i < m_numCards; i++)
    {
        try {
            m_cards.push_back(Card(size, maxValue, i));
        } catch(Error e)
        {
            std::cout << "ERROR" << std::endl;
        }
    }
}