#include "mtm_ex3.h"
#include "Room.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define IS_NULL(param1) if(param1==NULL) return MTM_NULL_PARAMETER
#define INIT_VAL 0

static char* stringDuplicate(const char* str){
    char* copy=(char*)malloc(strlen(str)+1);
    return copy? strcpy(copy,str): NULL;
}


struct room {
    char** email;
    int id;
    int price;
    int num_of_people;
    int difficulty;
    char* working_hours;
};

MtmErrorCode init_room(Room room, char** room_email, int id, int price,
                       int num_of_people, char* working_hours, int difficulty){
    IS_NULL(room);
    room->email=room_email;
    room->id=id;
    room->price=price;
    room->difficulty=difficulty;
    room->num_of_people=num_of_people;
    room->working_hours=stringDuplicate(working_hours);
    if(!room->working_hours){
        return MTM_OUT_OF_MEMORY;
    }
    return MTM_SUCCESS;
}

MtmErrorCode reset_room(Room room){
    IS_NULL(room);
    room->email=NULL;
    room->id=INIT_VAL;
    room->price=INIT_VAL;
    room->difficulty=INIT_VAL;
    room->num_of_people=INIT_VAL;
    free(room->working_hours);
    return MTM_SUCCESS;
}

Room copy_room(Room room){
    Room new_room=(Room)malloc(sizeof(*new_room));
    if(!new_room){ return NULL; }
    new_room->email=room->email;
    new_room->id=room->id;
    new_room->difficulty=room->difficulty;
    new_room->num_of_people=room->num_of_people;
    new_room->price=room->price;
    new_room->working_hours=stringDuplicate(room->working_hours);
    if(!new_room->working_hours){
        free(new_room);
        return NULL; }
    return new_room;
}

void destroy_room(Room room){
    reset_room(room);
    free(room);
}

int compare_rooms(Room room1,Room room2){
    if(room1->id>room2->id){
        return 1;
    } else if (room1->id<room2->id){
        return -1;
    }
    return 0;
}