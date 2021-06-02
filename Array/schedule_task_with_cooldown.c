/* We have a list of various types of tasks to perform.
   Task types are identiﬁed with an integral identiﬁer:
   task of type 1, task of type 2, task of type 3, etc.
   Each task takes 1 time slot to execute, and once we
   have executed a task we need cooldown (parameter)
   time slots to recover before we can execute another
   task of the same type.  However, we can execute tasks
   of other types in the meantime.  The recovery interval
   is the same for all task types. We do not reorder the
   tasks: always execute in order in which we received them
   on input.  Given a list of input tasks to run, and the
   cooldown interval, output the minimum number of time
   slots required to run them. Follow up: If reordering of
   tasks is allowed, return an optimal ordering of tasks

   Tasks: 1, 1, 2, 1
   Recovery interval (cooldown): 2
   Output: 7  (order is 1 _ _ 1 2 _ 1)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define COOLDOWN_TIME 4
#define TASK_SIZE 9

void schedule_task(int *tasks, int cooldown_time, int task_size){

	if (tasks == NULL){

		printf ("Tasks could not be null.\n");
		return ;
	}

	// look_up to keep track of last executed task of same type.
	int *look_up = malloc(sizeof(int) * task_size);

	// Fill look_up table with -1.
	memset((void*)look_up, -1, sizeof(int)*task_size);
	int i, j;

	for (i = 0 ; i < task_size ; ++i){

		if (look_up[tasks[i]] == -1){
			printf ("%d ", tasks[i]);
		} else{
			int diff = cooldown_time - (i - look_up[tasks[i]]) + 1;
			if (diff > 0){
				// Wait for cooldown period.
				for (j = 0 ; j < diff ; ++j){
					printf ("_ ");
				}
			}
			printf ("%d ", tasks[i]);
		}

		look_up[tasks[i]] = i;
	}

	printf ("\n");
}

int main(){

	int arr[TASK_SIZE] = {1, 1, 2, 1, 3, 4, 5, 2, 4};

	schedule_task(arr, COOLDOWN_TIME, TASK_SIZE);

	return EXIT_SUCCESS;
}
