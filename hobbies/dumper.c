#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void dump(const void *data, const uint len)
{
    static int n = 0;
    const unsigned  const char *c = (unsigned char*) data;
    unsigned int i;
    for( i = 0; i<len;i++ ) {
        printf("%02d ",c[i]);
        n++;
        if ( (n % 16 ) == 0 )
            putchar('\n');
    }
}

int main(int argc, char** argv)
{
    unsigned char byte = 0;
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

    while ( (fread(&byte, sizeof(char), 1, pfile)) != 0 )
		dump(&byte,1);

    fclose(pfile);
    return 0;
}
