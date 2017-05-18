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
Order copy_order(Order order);
void destroy_order(Order order);
int compare_orders(Order order1,Order order2);

#endif //EX3_ORDER_H
