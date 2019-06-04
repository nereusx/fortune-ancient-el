#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	text[0x10000];

int main(int argc, char* argv[])
{
	FILE	*fp;
	char	buf[8192], *p, *d;
	int		bufsz = 8192, id = 1;
	
	printf("%s\n",
		"DROP TABLE IF EXISTS FORTUNES;" \
		"CREATE TABLE FORTUNES ("  \
		"ID INT PRIMARY KEY NOT NULL," \
		"CTEXT TEXT NOT NULL );" );

	fp = fopen("diogenis.txt", "rt");
	if ( fp ) {
		*text = '\0'; d = text;
		while ( fgets(buf, bufsz, fp) ) {
			p = buf;
			while ( *p == ' ' || *p == '\t' ) p ++;
			if ( *p == '%' ) {
				printf(
					"INSERT INTO FORTUNES "\
					"(ID, CTEXT) VALUES "\
					"(%d, '%s');\n", id, text);
				id ++;
				*text = '\0'; d = text;
				}
			else {
				p = buf;
				while ( *p ) {
					if ( *p == '\'' ) 
						*d ++ = '\'';
					*d ++ = *p ++;
					}
				*d = '\0';
				}
			}
		fclose(fp);
		}
	return 0;
}
