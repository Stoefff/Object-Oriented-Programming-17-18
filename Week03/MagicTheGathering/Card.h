#ifndef __CARD__HEADER__DEFINED__
#define __CARD__HEADER__DEFINED__

#include "ID.h"

extern ushort currentID; // Should this be in .h or in .cpp

enum Color{

};

struct Card{
    char name[64];
    ushort ID;
};

void serializeCard(const char * fileName, const Card& card);

void deserializeCard(const char * fileName, Card& card, ushort offset); // offset = n * sizeof(Player)

ushort extractCardID(const char * fileName, const char * cardName); // ID = 0 - invalid

void createCard(const char * cardName);

#endif
