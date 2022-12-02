#include <err.h>
#include <stdio.h>
#include <stdlib.h>

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

#include <stdio.h>
#include <stdlib.h>
int large_alloc (int argc, char** argv) {
  const long long int size = {3501001000};
  char *p = 0;
  p = malloc(size);
// {
//  *p = 0x00;
//  *(p+1) = 0x01;
//  *(p+2) = 0x02;
//  *(p+3) = 0x03;
//  p = calloc(size, sizeof(char));
// }
  printf("&p==%p\n", p);
  for (int i = 0; i < 10; i++) printf("%c", *(p+i)+0x41);
  for (int i = 0; i < size; i++) *(p+i) = 0x41;
  free(p);
  return 0;
}

#include <stdio.h>
int environment()
{
  for (char **env = envp; *env != 0; env++)
  {
    char *thisEnv = *env;
    printf("%s\n", thisEnv);    
  }
  return 0;
}


int arc() {
#ifdef __unix__
	printf("unix\n");
#endif
#ifdef __APPLE__
	printf("APPLE\n");
#endif
#ifdef _WIN32
	printf("WIN32\n");
#endif
}



int pipes() {
	// Write stdin to file
	{
		FILE *fp_stdin;
		FILE *fp_stdout;
		char str [1024];
		fp_stdin=fopen("/dev/stdin","r");
		fp_stdout=fopen("out.txt","w");
		while (fscanf(fp_stdin, "%s", str)!=EOF)
			fprintf(fp_stdout, "<%s>",str);
		fclose(fp_stdin);
		fclose(fp_stdout);
		return 1;
	}	
	// Write stdin to stdout
	{
		FILE *fp_stdin;
		char str [1024];
		fp_stdin=fopen("/dev/stdin","r");
		while (fscanf(fp_stdin, "%s", str)!=EOF)
			printf("<%s>",str);
		fclose(fp_stdin);
		return 1;
	}
	// cat a.txt
	{
		FILE *fp;
		fp=fopen("a.txt", "rw");
		char *line = NULL;
		size_t linesize = 0;
		ssize_t linelen;
		while ((linelen = getline(&line, &linesize, fp)) != -1)
			fwrite(line, linelen, 1, stdout);
		free(line);
		if (ferror(fp))
			err(1, "getline");
		fclose(fp);
	}
}

