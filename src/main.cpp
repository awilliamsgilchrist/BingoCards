#include <ctime>
#include <fstream>
#include "Deck.h"
#include "Error.h"

void getInput(std::string& input)
{
    bool isValid = false;
    while(!isValid)
    {
        if(!(input == "1" || input == "2" || input == "3" || input == "4"))
        {
            std::cout << "Invalid input. Please enter one of the available options" << std::endl;
            input = "";
            std::cin >> input;
        }
        else
        {
            isValid = true;
        }
    }
}

void userMain();
void testMain();

int main() {
    std::srand(static_cast<unsigned int>(time(0)));

    char config;
    std::cout << "Test or run?(t/r): ";
    std::cin >> config;
    if(config == 'r')
    {
        userMain();
    }
    else if(config == 't')
    {
        testMain();
    }
    return 0;
}

void testMain()
{
    const std::string GOOD_OUTCOME = "Anticipated result\n";
    const std::string BAD_OUTCOME = "This message should not display\n";

    try{
        Deck testDeck1(5, 5, 50);
        std::cout << "Build successful. " << GOOD_OUTCOME;
    } catch (Error e)
    {
        std::cout << "Failed to build in some way. " << BAD_OUTCOME;
    }

    try{
        Deck testDeck2(1, 5, 3);
        std::cout << "Build successful" << BAD_OUTCOME;
    } catch (Error e)
    {
        if(e == CardSizeRangeError){
            std::cout << "Failed to build due to invalid card size. " << GOOD_OUTCOME;
        }
        else{
            std::cout << "Threw unexpected error. " << BAD_OUTCOME;
        }
    }

    try{
        Deck testDeck3(5, 1, 50);
        std::cout << "Build successful. " << BAD_OUTCOME;
    } catch (Error e)
    {
        if(e == CardQuantityRangeError){
            std::cout << "Failed to build due to invalid card quantity. " << GOOD_OUTCOME;
        }
        else{
            std::cout << "Threw unexpected error. " << BAD_OUTCOME;
        }
    }

    try{
        Deck testDeck4(5, 5, 25);
        std::cout << "Build successful. " << BAD_OUTCOME;
    } catch (Error e)
    {
        if(e == CardValueRangeError){
            std::cout << "Failed to build due to invalid card max value. " << GOOD_OUTCOME;
        }
        else{
            std::cout << "Threw unexpected error. " << BAD_OUTCOME;
        }
    }

    Deck testDeck5(5, 5, 50);
    std::ofstream testOutput("resource/testOutput.txt");
    std::cout << "Testing deck printing to output file\n";
    testDeck5.printDeck(testOutput);

    std::cout << "Deck testing finished" << std::endl;

    std::cout << "Small card test\n";

    testDeck5.printCard(3, std::cout);

    std::cout << "\n\nLarge card test\n";
    Deck testDeck6(15, 5, 450);
    testDeck6.printCard(3, std::cout);

    std::cout << "\n\nTesting complete\n";
}

void userMain() {
    bool isDone = false;
    bool isDeck = false;
    Deck* deck;
    std::string input;

    while(!isDone)
    {
        std::cout << "Welcome to the Bingo Deck Maker. What would you like to do?" << std:: endl;
        std::cout << "1. Create a new deck\n";
        if(isDeck)
        {
            std::cout << "2. Print a card from the deck\n";
            std::cout << "3. Print the whole deck\n";
        }
        std::cout << "4. Quit\n" << std::endl;
        std::cin >> input;
        getInput(input);

        if(!isDeck && (input == "2" || input == "3"))
        {
            std::cout << "That's not a valid input right now" << std::endl << std::endl;
        }
        else
        {
            if(input == "1")
            {
                unsigned int boardSize;
                unsigned int numCards;
                unsigned int maxValue;

                do {
                    std::cout << "Input board width :";
                    std::cin >> boardSize;
                } while(boardSize < 3 || boardSize > 15);

                do{
                    std::cout << "Input number of cards: ";
                    std::cin >> numCards;
                } while (numCards < 3 || numCards > 10000);

                do{
                    std::cout << "Input maximum number value";
                    std::cin >> maxValue;
                } while (maxValue < boardSize*boardSize*2 || maxValue > boardSize*boardSize*4);

                if(isDeck)
                {
                    delete deck;
                }

                deck = new Deck(boardSize, numCards, maxValue);
                isDeck = true;
                std::cout << "New deck created!\n\n\n";
            }
            else if(input == "2")
            {
                unsigned int index;
                do {
                    std::cout << "Choose which card you'd like to print: ";
                    std::cin >> index;
                } while(index >= deck->getCards().size());

                deck->printCard(index, std::cout);
                std::cout << "\n\n\n";
            }
            else if(input == "3")
            {
                deck->printDeck(std::cout);
                std::cout << "\n\n\n";
            }
            else
            {
                std::cout << "Exiting..." << "\n\n\n";
                isDone = true;
                if(deck) {
                    delete deck;
                    deck = nullptr;
                }
            }
        }
    }

    return;
}