#include<stdio.h>

void reverseWord(char *str){

   if (str == NULL)
      return;

   int i = 0, start = 0, end = 0;
   char temp;

   while (str[i]){

      if(str[i+1] == ' ' || str[i+1] == '\0'){

         end = i;
         while(start<end){
            temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            ++start, --end;
         }
         start = i + 2;
      }
      ++i;
   }

   start = 0, end = i - 1;
   while(start < end){
      temp = str[start];
      str[start] = str[end];
      str[end] = temp;
      ++start, --end;
   }
}

int main(){

   char str[20] = "how are you";

   printf ("Before Reverse = %s\n",str);
   reverseWord(str);
   printf ("After reverse = %s\n",str);

   return 0;
}
