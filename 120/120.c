#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
if(argc!=3 && argc!=4)
{
  fprintf(stderr, "Usage ./detab input file output file tabsstops(optional)\n");
  exit(1);
}
FILE *fin=fopen(argv[1], "r");
FILE *fout =fopen(argv[2],"w");
if(fin == NULL|| fout ==NULL){
  printf("Error \n");
  exit(1);
}
  unsigned ts = atoi(argv[3]);
  int c;

  while ((c = getc(fin)) != EOF){
    if (c == '\t')
      fprintf(fout,"%*s", ts, "");
    else
      putc(c,fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
