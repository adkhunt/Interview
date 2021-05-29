#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>

#define BUFFER_SIZE 10
#define PRODUCER_LIMIT 100

typedef struct buffer{

   int *data;        // Data produced by producer will be stored here.
   int total_size;   // Size of buffer.
   int writer_index; // Writer index used by producer thread.
   int reader_index; // Reader index used by consumer thread.
   bool is_reset;    // Flag to indicate if producer has exceed size and reset the counter.
   int spin_pshared; // Variable used by spinlock.
   int spin_ret;     // Variable used by spinlock.
   pthread_spinlock_t lock;  // Thread spinlock.

} buffer;

buffer* init_buffer(){

   buffer *buff = (buffer*) malloc(sizeof(buffer));
   buff->data = (int*) malloc(sizeof(int)*BUFFER_SIZE);
   buff->writer_index = 0;
   buff->reader_index = 0;
   buff->is_reset = false;
   buff->spin_ret = pthread_spin_init(&(buff->lock), buff->spin_pshared);

   if (buff->spin_ret != 0){
      printf ("Spin lock initialization failed.\n");
      free(buff->data);
      free(buff);
      return NULL;
   }

   printf ("Buffer initialization completed!\n");
   return buff;
}

void destroy_buff(buffer *buff){

   buff->spin_ret = pthread_spin_destroy (&(buff->lock));
   printf ("Destroying buffer.\n");

   if (buff->spin_ret != 0){
      printf ("Error while destroying spin lock.\n");
   }

   free(buff->data);
   free(buff);
   printf ("Buffer destroyed successfully!\n");
}

void* producer_thread(void *args){

   buffer *buff = (buffer*) args;
   printf ("Producer thread started.\n");
   int counter = 0;

   while(counter < PRODUCER_LIMIT){

      pthread_spin_lock(&(buff->lock));
      if (buff->writer_index == BUFFER_SIZE){
         buff->writer_index = 0;   // Reset writer's buffer index.
         buff->is_reset = true;
      }
      if (buff->writer_index != buff->reader_index || !buff->is_reset){
         printf ("Producer written = %d\n", counter);
         buff->data[buff->writer_index++] = counter++;
      }
      pthread_spin_unlock(&(buff->lock));
   }
}

void* consumer_thread(void *args){

   buffer *buff = (buffer*) args;
   int counter = 0;

   while(counter < PRODUCER_LIMIT){
      pthread_spin_lock(&(buff->lock));
      if (buff->reader_index == BUFFER_SIZE){
         buff->reader_index = 0;
         buff->is_reset = false;
      }
      if (buff->reader_index < buff->writer_index || buff->is_reset){
         printf ("Consumer read = %d\n", buff->data[buff->reader_index++]);
         ++counter;
      }
      pthread_spin_unlock(&(buff->lock));
   }
}

int main(){

   pthread_t producer, consumer;

   buffer *buff = init_buffer();
   if (buff == NULL){
      printf ("Buffer creation failed!\n");
      return EXIT_FAILURE;
   }
   
   pthread_create(&producer, NULL, producer_thread, buff);
   pthread_create(&consumer, NULL, consumer_thread, buff);
   pthread_join(producer, NULL);
   pthread_join(consumer, NULL);
   destroy_buff(buff);

   return EXIT_SUCCESS;
}
