#ifndef __PLAYER__HEADER__DEFINED__
#define __PLAYER__HEADER__DEFINED__

#include "ID.h"

extern ushort currentID;

struct Player{
    char name[128];
    ushort ID;
};

void serializePlayer(const char * fileName, const Player& player);

void deserializePlayer(const char * fileName, Player& player, ushort offset); // offset = n * sizeof(Player)

ushort extractPlayerID(const char * fileName, const char * playerName); // ID = 0 - invalid

void createPlayer(const char * playerName);

#endif
