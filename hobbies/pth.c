#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void *read_char(void *arg) {
    char *c = (char*) arg;
    printf("%s",c);
    return NULL;
}

int main(void)
{
    int res;
    pthread_t t1,t2;
    char msg1[]= "Hello World!\n";
    char msg2[]= "fyuck off!\n";

    res = pthread_create(&t1, NULL, read_char, msg1);
    if ( res != 0 )
        printf("pthread_create %d.\n",res);

    res = pthread_create(&t2, NULL, read_char, msg2);
    if ( res != 0 )
        printf("pthread_create %d.\n",res);

    res = pthread_join(t1, NULL);
    if ( res != 0 )
        printf("pthread_join %d.\n",res);

    res = pthread_join(t2, NULL);
    if ( res != 0 )
        printf("pthread_join %d.\n",res);


    return 0;
}

