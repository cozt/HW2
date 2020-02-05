#include <stdio.h>
#include <stdlib.h>
int main(int argc, char*argv[])
{
if(argc!=2 && argc!=3)
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
int c;
int counterp, counterb,counterbrace,counter1,counter2;
while((c= getc(fin))!= EOF){
  if(c=='('||c==')')
  {
    counterp++;
  }
  if(c=='{'||c=='}')
  {
    counterb++;
  }
  if(c=='['||c==']')
  {
    counterbrace++;
  }
 if(c=='"'||c=='"')
  {
    counter1++;
  }
  if(c=='\''||c=='\'')
  {
    counter2++;
  }
  else putc(c, fout);
}
if((counterp%2)!=0)
{
  printf( "Parantheses error \n");
}
 if((counterb%2)!=0)
{
    printf("brakets error \n");
}
 if((counterbrace%2)!=0)
{
  printf("braces error \n");
}
 if((counter1%2)!=0)
{
    printf(" Double Qoutation error \n");
}
 if((counter2%2)!=0)
{
    printf( " Single Qoutation error \n");
}
fclose(fin);
fclose(fout);
return 0;
}
