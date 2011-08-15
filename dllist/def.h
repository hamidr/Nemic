/*
   Hamidr
   GPLed source */

#define FORWARD 1
#define BACKWARD -1
#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>

struct datalist
{
    struct datalist* pri;
    int cont;
    struct datalist* next;
};

typedef struct datalist data;

_Bool search(data*, const int, const short);
void freelist(data*);
void getnode(data*);
void printlist(data*);
