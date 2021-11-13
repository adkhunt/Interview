#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

// Total number of blocks to be allocated in each thread.
#define ARRAY_SIZE 50

// Size of each block that will be allocated in each thread.
#define BLOCK_SIZE 4

// Mapping of thread_id vs allocated memory by that thread.
typedef struct alloc_map{
	pthread_t id;
	int size;
} alloc_map;

// Linklist of total threads for monitor thread.
typedef struct mem_list{
	alloc_map *res;
	struct mem_list *next;
} mem_list;

typedef struct mem_thread_info{
	pthread_mutex_t lock;   // Lock used while adding thread to linklist.
	pthread_t *t_list;
	mem_list *hptr;
	int total_thread;      // total number of thread.
}mem_thread_info;

mem_thread_info* init_mem_thread_info(int size){

	mem_thread_info *info = (mem_thread_info*) malloc(
					sizeof(mem_thread_info));
	info->t_list = (pthread_t*) malloc(sizeof(pthread_t)*size);
	info->hptr = NULL;
	info->total_thread = size;

	return info;
}

mem_list* get_thread_node(pthread_t id){

	mem_list *node = (mem_list*) malloc(sizeof(mem_list));
	node->res = (alloc_map*) malloc(sizeof(alloc_map));
	node->res->id = id;
	node->res->size = 0;
	node->next = NULL;
	return node;
}

void register_thread(mem_thread_info *info, mem_list *node){

	pthread_mutex_lock(&(info->lock));
	node->next = info->hptr;
	info->hprt = node;
	//mem_list *temp = info->hptr;
	//info->hptr = node;
	//node->next = temp;
	pthread_mutex_unlock(&(info->lock));
}

void* allocator_thread(void *args){

	mem_thread_info *cur_info = (mem_thread_info*) args;
	pthread_t id = pthread_self();
	mem_list *node = get_thread_node(id);
	register_thread(cur_info, node);

	int i, **ptr;
	// Each thread will allocate 200 bytes.
	ptr = (int**) malloc(sizeof(int*)*ARRAY_SIZE);

	for (i = 0 ; i < ARRAY_SIZE ; ++i){
		ptr[i] = (int*) malloc(BLOCK_SIZE);
		node->res->size += BLOCK_SIZE;
		sleep(1);
	}

	// Free memory before returning.
	for (i = 0 ; i < ARRAY_SIZE ; ++i){
		free(ptr[i]);
		node->res->size -= BLOCK_SIZE;
		ptr[i] = NULL;
	}

	free(ptr);
	ptr = NULL;
	return NULL;
}

void* monitor_thread(void *args){

	mem_thread_info *cur_info = (mem_thread_info*) args;
	int i = 0;

	while(i < 60){
		sleep(10);
		mem_list *temp = cur_info->hptr;
		while(temp){
			printf ("Thread Id = %lu, Size = %d\n", temp->res->id,
								temp->res->size);
			temp = temp->next;
		}
		i += 10;
	}
}

int main(){

	int total_thread, i;
	printf ("Enter total allocator thread to run: ");
	scanf("%d", &total_thread);

	pthread_t monitor_t;
	mem_thread_info *res = init_mem_thread_info(total_thread);

	for (i = 0 ; i < total_thread ; ++i){
		pthread_create(res->t_list+i, NULL, allocator_thread, res);
	}

	pthread_create(&monitor_t, NULL, monitor_thread, res);

	for (i = 0 ; i < total_thread ; ++i){
		pthread_join(res->t_list[i], NULL);
	}

	pthread_join(monitor_t, NULL);

	return 0;
}
