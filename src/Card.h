#ifndef BINGOCARDS_CARD_H
#define BINGOCARDS_CARD_H


class Card {
private:
    unsigned int m_size;
public:
    //Public variables
    unsigned int** content;
    unsigned int idNum;

    //Getters
    unsigned int getSize() {return m_size;}

    //Constructors
    Card(unsigned int size, unsigned int maxValue, unsigned int id); // May throw RandomNumberGeneratorError if random number generator takes too long
    ~Card();
};


#endif //BINGOCARDS_CARD_H
