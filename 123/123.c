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
int counter;
while((c= getc(fin))!= EOF){
  if(c=='/'){
    counter =0;
    c= getc(fin);
    if(c== '/'){
      counter =1;
      while((c=getc(fin))!= '\n');
    }else if(c=='*'){
      counter =1;
      while((c=getc(fin))!=EOF){
        if((c=getc(fin))=='*'&&(c=getc(fin))=='/' ){
          c='\n';
          break;
        }
      }
    }
    else putc('/',fout);
  }
  putc(c, fout);
}
fclose(fin);
fclose(fout);
return 0;
}
