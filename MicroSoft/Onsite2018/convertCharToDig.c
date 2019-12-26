#include<stdio.h>

int getCharToInt(char *str){

   int i = 0, ch;
   int result = 0, cur;

   while(str[i]){

      if (str[i] >= 97)
         ch = str[i] - 96;
      else
         ch = str[i] - 64;

      result = (result*26) + ch;
      ++i;
   }

   return result;
}

int main(){

   char str[10];

   printf ("Enter string to convert to char..\n");
   scanf ("%s",str);

   int res = getCharToInt(str);

   printf ("Result = %d\n",res);

   return 0;
}
