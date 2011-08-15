/* Hamidr
   GPLed source */

#include "def.h"

void
getnode(data* node)
{
    data* dtmp = (data*)malloc(sizeof(data));
    printf("Enter a Number:");
    scanf("%d",&dtmp->cont);
    
    dtmp->pri = dtmp->next = NULL;

    data* tmp; // in fcondition

    // half free conditions
    if ( !node ) {
        printf("**1**");
        node = dtmp;
    } else if (node->next == NULL ) {
        printf("**2**");
        node->next = dtmp;
        dtmp->pri = node;
    } else if (node->pri == NULL ){
        printf("**3**");
        node->pri = dtmp;
        dtmp->next = node;
    } else {
        /*full conditions: Insert in the middle of the list*/
        printf("**4**");
        dtmp->pri = node;
        tmp = node->next;
        node->next = dtmp;
        dtmp->next = tmp;
        tmp->pri = dtmp;
    }
}

void
printlist(data* node)
{
    if ( node == NULL )
        return;

    while( node->pri )
        node = node->pri;

    while ( node->next ) {
        printf("%d\t",node->cont);
        node = node->next;
    }
    putchar('\n');
}

_Bool
search(data* node, const int num, const short way)
{
    if( -1 == way )
        while( node->pri ) {
            if( node->cont == num )
                return true;
            node = node->pri;
        }
    else if ( 1 == way )
        while( node->next ) {
            if( node->cont == num )
                return true;
            node = node->next;
        }
    return false;
}

void
freelist(data* node)
{
    /* Go all the list down then
       start cleaning.          */

    while( node->pri )
        node = node->pri;

    /* Now we are in the begining of the list.
       Start cleaning from here to the end! */
    data* tmp = node;
    while ( tmp ) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
}

