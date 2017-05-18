#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Company.h"
#include "mtm_ex3.h"

#define INIT_VAL 0
#define IS_NULL(param1) if(param1==NULL) return MTM_NULL_PARAMETER;

struct company{
    char* email;
    TechnionFaculty faculty;
    Set rooms;
};

static  char* stringDuplicate(const char* str){
    char* copy=(char*)malloc(strlen(str)+1);
    return copy? strcpy(copy,str): NULL;
}

MtmErrorCode init_company(Company company,char* email,TechnionFaculty faculty) {
    IS_NULL(company);
    company->faculty = faculty;
    company->email = stringDuplicate(email);
    if (!company->email) { return MTM_OUT_OF_MEMORY; }
    company->rooms=setCreate((copySetElements)copy_room ,(freeSetElements)destroy_room ,(compareSetElements)compare_rooms);
    return MTM_SUCCESS;
}

MtmErrorCode reset_company(Company company) {
    IS_NULL(company);
    free(company->email);
    company->email = NULL;
    company->faculty = CIVIL_ENGINEERING;
    setDestroy(company->rooms);
    company->rooms = NULL;
    return MTM_SUCCESS;
}

Company copy_company(Company company){
    Company new_company=(Company)malloc(sizeof(*new_company));
    new_company->faculty=company->faculty;
    new_company->email=stringDuplicate(company->email);
    if(!new_company->email){
        free(new_company);
        return NULL;
    }
    new_company->rooms=setCopy(company->rooms);
    return new_company;
}

void destroy_company(Company company){
    reset_company(company);
    free(company);
}

int compare_companies(Company company1,Company company2){
    return strcmp(company1->email,company2->email);
}
