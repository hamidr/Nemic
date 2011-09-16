#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BLOCK 16

void dump(const void *data, const uint len)
{
    static int n = 0;
    const unsigned  const char *c = (unsigned char*) data;
    int i;
    for( i = 0; i<len;i++ ) {
        printf("%02x ",c[i]);
        n++;
        if ( (n % 16 ) == 0 )
            putchar('\n');
    }
}

int main(int argc, char** argv)
{
    unsigned char bytes[BLOCK] = {0};
	FILE *pfile = NULL;

	if ( argc > 1 )
	    pfile = fopen(argv[1],"rb");
	else {
		printf("No argument!\n");
		return -1;
	}

	if ( errno ) {
		printf("Error on file: %d.\nWhat kind of file is this?!\n",errno);
		return -2;
	}

    while ( (fread(bytes, sizeof(char), BLOCK, pfile)) != 0 ) {
        dump(bytes,BLOCK);
        /* clean the buffer */
        memset(bytes,0,BLOCK);
    }

    putchar('\n');

    fclose(pfile);
    return 0;
}
