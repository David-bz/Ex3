#ifndef EX3_ORDER_H
#define EX3_ORDER_H

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "mtm_ex3.h"

typedef struct order* Order;

MtmErrorCode init_order(Order order,TechnionFaculty faculty,int id,int time);
MtmErrorCode reset_order(Order order);

#endif //EX3_ORDER_H
