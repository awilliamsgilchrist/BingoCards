#include <cstdlib>
#include "Card.h"
#include "Error.h"

Card::Card(unsigned int size, unsigned int maxValue, unsigned int id) :
idNum(id),
m_size(size)
{
    std::vector<unsigned int> tempVect(m_size, 0);

    for(unsigned int i = 0; i < m_size; i++)
    {
        content.push_back(tempVect);
    }
    std::vector<unsigned int> usedNums;
    unsigned int temp = 0;
    unsigned int emergencyCounter = 0;
    bool isUsed = false;

    for(unsigned int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            temp = (std::rand() % maxValue) + 1;

            for(unsigned int k = 0; k < usedNums.size(); k++)
            {
                if(temp == usedNums[k])
                {
                    isUsed = true;
                    break;
                }
            }

            if(isUsed)
            {
                j -= 1;
                emergencyCounter++;
                if(emergencyCounter == 10000000)
                {
                    throw RandomNumberGeneratorError;
                }
                isUsed = false;
            }
            else
            {
                content[i][j] = temp;
                usedNums.push_back(temp);
            }
        }
    }
}

Card::~Card()
{}