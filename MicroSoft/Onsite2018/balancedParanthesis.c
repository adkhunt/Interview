#include<stdio.h>
#include<stdbool.h>
#include"stack.h"

int strLen(char *str){

   int i = 0;
   while(str[i])
      ++i;

   return i;
}

bool isValidBraces(char *str){

   if (str == NULL)
      return false;

   int len = strLen(str);
   int i = 0;
   bool ret = true;
   stack *s = create_stack(len);

   while (str[i]){

      if (str[i] == '{' || str[i] == '(' || str[i] == '[')
         push(s, str[i]);
      else if (str[i] == ')' && pop(s) != '('){
         ret = false;
         break;
      }else if (str[i] == '}' && pop(s) != '{'){
         ret = false;
         break;
      }else if (str[i] == ']' && pop(s) != '['){
         ret = false;
         break;
      }
      ++i;
   }

   destroy_stack(s);
   return ret;
}

int main(){

   char *str[2] = {"{]}{})(",
                   "{}()[()]"};
   int i;

   for (i = 0 ; i < 2 ; ++i){
      printf ("String = %s\n",str[i]);
      if(isValidBraces(str[i]))
         printf ("%s -> Valid String\n",str[i]);
      else
         printf ("%s -> Invalid String\n",str[i]);
   }

   return 0;
}
