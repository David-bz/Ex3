#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "escaper.h"
#include "mtm_ex3.h"

#define INIT_VAL 0
#define IS_NULL(param1) if(param1==NULL) return MTM_NULL_PARAMETER;

struct Escaper {
    char* email;
    TechnionFaculty faculty;
    int skill_level;
};

static  char* stringDuplicate(const char* str){
    char* copy=(char*)malloc(strlen(str)+1);
    return copy? strcpy(copy,str): NULL;
}

MtmErrorCode init_escaper(Escaper escaper, char* email,TechnionFaculty faculty,int skill_level){
    IS_NULL(escaper);
    escaper->faculty=faculty;
    escaper->skill_level=skill_level;
    escaper->email=stringDuplicate(email);
    if(!escaper->email){ return MTM_OUT_OF_MEMORY; }
    return MTM_SUCCESS;
}

MtmErrorCode reset_escaper(Escaper escaper){
    IS_NULL(escaper);
    free(escaper->email);
    escaper->email=NULL;
    escaper->skill_level=CIVIL_ENGINEERING;
    escaper->skill_level=INIT_VAL;
    return MTM_SUCCESS;
}


Escaper copy_escaper(Escaper escaper) {
    Escaper new_escaper = (Escaper) malloc(sizeof(*new_escaper));
    new_escaper->faculty = escaper->faculty;
    new_escaper->skill_level = escaper->skill_level;
    new_escaper->email = stringDuplicate(escaper->email);
    if (!escaper->email) {
        free(new_escaper);
        return NULL;
    }
    return new_escaper;
}

void destroy_escaper(Escaper escaper){
    reset_escaper(escaper);
    free(escaper);
}

int compare_escapers(Escaper escaper1,Escaper escaper2){
    return strcmp(escaper1->email,escaper2->email);
}


