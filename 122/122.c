#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
if(argc!=3 && argc!=4)
{
  fprintf(stderr, "Error not enoguh commands\n");
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
  int counter=0;

  while ((c = getc(fin)) != EOF){
  if(c== ' ')
  {
    counter++;
  }
  if(counter==ts)
  {
    counter=0;
    putc('\n',fout);
  }
  putc(c,fout);

  }

    fclose(fin);
    fclose(fout);
    return 0;
}
