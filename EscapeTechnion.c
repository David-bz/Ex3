#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "EscapeTechnion.h"


struct escapetechnion{
    Set company_set;
    Set escaper_set;
    Set order_set;
};

bool check_email(char* mail){
    char* ptr=mail;
    int i=0;
    while (ptr){
        if(ptr[i++]=='@'){ return true;}
    }
    return false;
}
MtmErrorCode add_company(char* email,TechnionFaculty faculty){
    if(!check_email(email)){
        return MTM_INVALID_PARAMETER;
    }
    
}
MtmErrorCode create_system(EscapeTechnion system){
    system->escaper_set=setCreate((copySetElements)copy_escaper,(freeSetElements)destroy_escaper,
              (compareSetElements)compare_escaper);
    system->company_set=setCreate((copySetElements)copy_company,(freeSetElements)destroy_company,
                                  (compareSetElements)compare_companies);
    system->order_set=setCreate((copySetElements)copy_order,(freeSetElements)destroy_order,
                                 (compareSetElements)compare_orders);
    return SET_SUCCESS;
}