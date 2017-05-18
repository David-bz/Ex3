#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Order.h"
#include "mtm_ex3.h"

#define INIT_VAL 0
#define IS_NULL(param1) if(param1==NULL) return MTM_NULL_PARAMETER;

struct order {
    char** email;
    TechnionFaculty faculty;
    int id;
    int time;
};

MtmErrorCode init_order(Order order,TechnionFaculty faculty,int id,int time){
    IS_NULL(order);
    order->faculty=faculty;
    order->id=id;
    order->time=time;
    order->email=NULL;
    return MTM_SUCCESS;
}

MtmErrorCode reset_order(Order order){
    IS_NULL(order);
    free(order->email);
    order->id=INIT_VAL;
    order->faculty=CIVIL_ENGINEERING;
    order->time=INIT_VAL;
    return MTM_SUCCESS;
}

Order copy_order(Order order){
    Order new_order=(Order)malloc(sizeof(*new_order));
    new_order->id=order->id;
    new_order->email=order->email;
    new_order->faculty=order->faculty;
    new_order->time=order->time;
    return new_order;
}

void destroy_order(Order order){
    reset_order(order);
    free(order);
}

int compare_orders(Order order1,Order order2){
    if(order1->time>order2->time){
        return 1;
    } else if (order1->time>order2->time){
        return -1;
    }
    return 0;
}


