#include <stdio.h>

#define WORK_FILE a.txt

void main () {

FILE *f;
int c;
char *workfile="b.txt";
char *mode="a+";

printf("Will open the file %s at address %x.\n", workfile, workfile);

f = fopen(workfile, mode);

printf("File open.\n");

c = getchar ();

while (c != EOF)  {
        fputc(c,f);
        c = getchar ();
        }

printf("\nWill close the file.\n");

fclose (f);

printf("Correctly finished.\n");

}
