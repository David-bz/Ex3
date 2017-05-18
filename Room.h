#ifndef EX3_ROOM_H
#define EX3_ROOM_H
#include "mtm_ex3.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define INIT_VAL 0

typedef struct room* Room;

MtmErrorCode init_room(Room room, char** room_email, int id, int price,
                       int num_of_people, char* working_hours, int difficulty);
MtmErrorCode reset_room(Room room);
Room copy_room(Room room);
void destroy_room(Room room);
int compare_rooms(Room room1,Room room2);


#endif //EX3_ROOM_H
