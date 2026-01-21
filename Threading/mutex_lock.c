#include <pthread.h>

int gnum = 100;

void* thread_entry_1(void* args)
{
   pthread_mutex_lock(&mu_lck); 
    //MODIFY gnum
    pthread_mutex_unlock(&mu_lck);
}

void* thread_entry_2(void* args)
{
    pthread_mutex_lock(&mu_lck);
    //MODIFY gnum
    pthread_mutex_unlock(&mu_lck);
}

////////////////////////////////////

pthread_mutex_t mu_lck = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_init(&mu_lck);

void* threaad_common_entry(void* args)
{
    int local_data; //per thread copy
    gnum; //single copy amongst multiple threads

    //modification of gnum must be inside
    //mutex lock and unlock

    pthread_mutex_lock(&mu_lck);
    //MODIFY gnum
    pthread_mutex_unlock(&mu_lck);
}