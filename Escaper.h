#ifndef EX3_ESCAPER_H
#define EX3_ESCAPER_H

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "mtm_ex3.h"

typedef struct escaper* Escaper;

MtmErrorCode init_escaper(Escaper escaper, char* email,TechnionFaculty faculty,int skill_level);
MtmErrorCode reset_escaper(Escaper escaper);
Escaper copy_escaper(Escaper escaper);
void destroy_escaper(Escaper escaper);
int compare_escaper(Escaper escaper1,Escaper escaper2);

#endif //EX3_ESCAPER_H
