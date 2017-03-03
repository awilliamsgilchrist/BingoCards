#include <ctime>
#include "Deck.h"
#include "Error.h"

void errorHandle(Error e)
{
    if(e == RandomNumberGeneratorError)
    {
        std::cout << "ERROR: Random number generator took too long to generate bingo card" << std::endl;
    }
    else if(e == CardQuantityRangeError)
    {
        std::cout << "ERROR: Number of cards generated was outside the bounds of the deck" << std::endl;
    }
    else if(e == CardValueRangeError)
    {
        std::cout << "ERROR: Maximum card value fell outside the allowable range" << std::endl;
    }
    else
    {
        std::cout << "ERROR: Size of card fell outside allowable range" << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned int>(time(0)));

    try
    {
        Deck(5, 5, 50);
    } catch(Error e)
    {
        errorHandle(e);
    }

    return 0;
}