#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

/*
 * Program to find the level in tree which 
 * has the maximum number of nodes
 */

/*
 * This struct variable holds the level of max 
 * nodes and the level.
 */

struct LEVEL_PAIR{
			int level, count;
};

typedef struct LEVEL_PAIR level_pair;

/*
 * This function will traverse the tree in 
 * level order fashion using queue so we
 * countinuous keep track of the level and 
 * the node count of that node
 */

level_pair get_max_level(struct node *root)
{
	if(root == NULL)
		return ;

Queue *q = create_queue(15);
int count = 0;
int size = 0;
int level = 1;
level_pair res = {0,0};

	enqueue(q, root);
	++size;

	while(! isQueueEmpty(q))
	{
		count = size;

		if(res.count < size)
		{
			res.level = level;
			res.count = size;
		}		

		while(count > 0)
		{
			root = dequeue(q);
			--size;

			if(root->left != NULL)
			{
				enqueue(q, root->left);
				++size;
			}

			if(root->right != NULL)
			{
				++size;
				enqueue(q, root->right);
			}
			--count;
		}

		++level;
	}

	return res;

}

int main()
{
struct node *root = getReadyTree();

	level_pair res = get_max_level(root);

	printf("Level %d has %d nodes\n",res.level,res.count);

	return EXIT_SUCCESS;
}
