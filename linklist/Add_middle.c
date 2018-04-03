#include<stdio.h>
#include<stdlib.h>

typedef struct node{
                        int num;
                        struct node *next;
} node;

node* get_new_node(int num)
{
        node *new_node = (node*) malloc(sizeof(node));

        new_node->num = num;
        new_node->next = NULL;

        return new_node;
}

void add_at_middle (node **hptr, int num)
{
        if(*hptr == NULL || (*hptr)->num >= num)
        {
                node *temp = *hptr;
                *hptr = get_new_node(num);
                (*hptr)->next = temp;

                return;
        }

        else
        {
                node *cur = *hptr;
                node *pre = *hptr;

                while(cur != NULL)
                {
                        if(cur->num > num)
                        {
                                node *temp = cur;
                                node *new_node = get_new_node(num);
                                pre->next = new_node;
                                new_node->next = temp;
                                return ;
                        }

                        else if(cur->next == NULL)
                        {
                                cur->next = get_new_node(num);
                                return ;
                        }

                        pre = cur;
                        cur = cur->next;
                }
        }
}

void print_list (node *hptr)
{
        while(hptr != NULL)
        {
                printf("%d ",hptr->num);
                hptr = hptr->next;
        }
}

int main()
{
char ch;
node *hptr = NULL;
int num;

        do{
                printf("Enter number to add in linklist.\n");
                scanf("%d",&num);
                add_at_middle(&hptr, num);
                printf("Do you want to continue? (Y/y)\n");
                scanf(" %c",&ch);
        } while(ch == 'y' || ch == 'Y');

        print_list(hptr);

        printf("\n");

        return 0;
}
