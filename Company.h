#ifndef EX3_COMPANY_H
#define EX3_COMPANY_H

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "mtm_ex3.h"
#include "set.h"
#include "Room.h"

typedef struct company* Company;

MtmErrorCode init_company(Company company,char* email,TechnionFaculty faculty);
MtmErrorCode reset_company(Company company);

/***** check update on github */

Company copy_company(Company company);
void destroy_company(Company company);
int compare_companies(Company company1,Company company2);

#endif //EX3_COMPANY_
