#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct node{
                    int num;
                    struct node *next;
} list_node;

list_node* getNewNode (int num){

   list_node *new_node = (list_node*) malloc(sizeof(list_node));
   new_node->num = num;
   new_node->next = NULL;

   return new_node;
}

void add_begin (list_node **hptr, int num){

   if (*hptr){
      list_node *new_node = getNewNode(num);
      new_node->next = *hptr;
      *hptr = new_node;
   } else
      *hptr = getNewNode (num);
}

void printList (list_node *hptr){

   while (hptr){
      printf ("%d ",hptr->num);
      hptr = hptr->next;
   }

   printf ("\n");
}

list_node* getRandomAddr (list_node *hptr){

   int randomNumber = rand()%10;
   int i;

   for (i = 0 ; i < randomNumber ; ++i)
      hptr = hptr->next;

   return hptr;
}

void changeLink (list_node *node){

   list_node *temp = node->next;
   node->num = temp->num;
   node->next = temp->next;
   free(temp);
   temp = NULL;
}

void delete_random_ptr (list_node **hptr, list_node *randomPtr){

   if (*hptr == randomPtr){
      changeLink (*hptr);
      goto done;
   }

   list_node *temp = *hptr;

   while (temp){

      if (temp->next == NULL){
         printf ("Last node can not be deleted..\n");
         goto done;
      }

      else if (temp == randomPtr){

         changeLink (temp);
         goto done;
      }

      temp = temp->next;
   }

   done:
      return;
}

int main(){

   list_node *hptr = NULL;
   int i, num;
   srand (getpid());

   for (i = 0 ; i < 10 ; ++i)
      add_begin (&hptr, rand()%50);

   printList (hptr);

   list_node *random_ptr = getRandomAddr (hptr);

   printf ("Random Node To Delete is %d\n",random_ptr->num);

   delete_random_ptr(&hptr, random_ptr);

   printList (hptr);

   return 0;
}
