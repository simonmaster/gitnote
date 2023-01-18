

#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>

/************************************
*									*
*	xDumpbuf -- dump the buffer		*
*									*
************************************/
void	xDumpbuf(outfp, buf, size)
FILE	*outfp;
int		size ;
char	*buf ;
{
	int		i;
	char	sbuf[0x20];

	while (size) {
		for (i = 0; (i < 0x10) && size; i++, size--, buf++) {
			fprintf(outfp, "%02X ", ((unsigned int)*buf)&0xff) ;
			if ((*buf < ' ') || (*buf >= 0x7f))
				sbuf[i] = '.' ;
			else
				sbuf[i] = *buf;
		}
		sbuf[i--] = '\0' ;
		while (i++ < 0x10)
			fprintf(outfp, "   ") ;
		fprintf(outfp, "\t%s\n", sbuf) ;
	}
}

/************************************************
*												*
*	xDumpbuftag - dump out the buffer with tag	*
*												*
************************************************/
void	xDumpbuftag(outfp, buf, size, tag)
FILE	*outfp;
unsigned char	*buf;
int		size, tag;
{
	int		i;
	char	sbuf[0x20];

	while (size) {
		fprintf(outfp, "%08x ", tag);
		for (i = 0; (i < 0x10) && size; i++, size--, buf++, tag++) {
			if ((*buf < ' ') || (*buf >= 0x7f))
				sbuf[i] = '.' ;
			else
				sbuf[i] = *buf;
		}
		sbuf[i--] = '\0' ;
		while (i++ < 0x10)
			fprintf(outfp, "   ") ;
		fprintf(outfp, "\t%s\n", sbuf) ;
	}
}


/* Test program */

#define INT_ARRAY_SIZE 0x21
#define CHAR_ARRAY_SIZE 0x21

int myIntArray[INT_ARRAY_SIZE];	/* 33 integers */
char myCharArray[CHAR_ARRAY_SIZE];	/* 33 chars */

void initAll() {
	int len = INT_ARRAY_SIZE;;
	int i;
	int *ip;
	ip = myIntArray;
	for (i = 0; i < len; i++, ip++) {
		*ip = i+1 + 0x07080900;
	}

	char *cp;
	cp = myCharArray;
	for (i = 0; i < len; i++, cp++) {
		*cp = i + 'A';
	}
}

void dumpHex( int size ) {
	for (int i = 0; i < size; i++) {
		printf("%02d %02X %04o\n", i, i, i);
	}
}


int main(int ac, char * av[]) {

	printf("Dump hex table\n");
	dumpHex( INT_ARRAY_SIZE );
	printf("\n\n");
	initAll();
	printf("myIntArray size %d\n", INT_ARRAY_SIZE);
	xDumpbuf(stdout, myIntArray, INT_ARRAY_SIZE * sizeof(int) );
	printf("myCharArray size %d\n", CHAR_ARRAY_SIZE);
	xDumpbuf(stdout, myCharArray, CHAR_ARRAY_SIZE * sizeof(char) );

	return 0;
}




