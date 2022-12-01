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

