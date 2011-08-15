#include "def.c"

int main(void)
{
    data *node = (data*)malloc(sizeof(data));
    node->cont = 0;
    node->next = NULL;
    node->pri = NULL;

    getnode(node);

    printf("\nprinting:");
    printlist(node);
    
    if (search(node,12,FORWARD) )
        printf("\n found\n");

    freelist(node);
    return 0;
}
