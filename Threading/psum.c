#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<pthread.h>

#define CAP 500

int* build_input_array(size_t N);
void* thread_function(void*);

struct input
{
    int* p_arr;
    size_t start_index;
    size_t nr_elements;
};

int main(void)
{
    size_t nr_threads = 4;
    size_t chunk_size = 2500;
    size_t N = 10000;
    size_t i;
    size_t total_sum;
    int* p_arr = NULL;
    struct input* p_input_arr = NULL;
    pthread_t* thread_ids = NULL;
    size_t** op_results = NULL;

    p_arr = build_input_array(N);

    p_input_arr = (struct input*)calloc(nr_threads, sizeof(struct input));
    if(p_input_arr == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < nr_threads; ++i)
    {
        p_input_arr[i].p_arr = p_arr;
        p_input_arr[i].start_index = chunk_size * i;
        p_input_arr[i].nr_elements = chunk_size;
    }

    thread_ids = (pthread_t*)calloc(nr_threads, sizeof(pthread_t));
    if(thread_ids == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    op_results = (size_t**)calloc(nr_threads, sizeof(size_t*));
    if(op_results == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    //Splitting the computation
    for(i=0; i<nr_threads; ++i)
    {
        pthread_create(&thread_ids[i],
                        NULL,
                        thread_function,
                        (void*)&p_input_arr[i]);
    }

    for(i=0; i<nr_threads; ++i)
    {
        pthread_join(thread_ids[i],(void**)&op_results[i]);
    }

    /*Merging the result of individual threads*/
    total_sum = 0;
    for(i=0; i<nr_threads; ++i)
    {
        total_sum += *op_results[i];
    }

    printf("Total Sum = %lu\n", total_sum);

    total_sum = 0;
    for(i=0; i<N; ++i)
    {
        total_sum += p_arr[i];
    }

    printf("Total sum (Serial) = %lu\n", total_sum);

    free(p_arr);
    p_arr = NULL;

    free(p_input_arr);
    p_input_arr = NULL;

    free(thread_ids);
    thread_ids = NULL;

    for(i=0; i<nr_threads; ++i)
    {
        free(op_results[i]);
        op_results[i] = NULL;
    }

    free(op_results);
    op_results = NULL;

    exit(EXIT_SUCCESS);
}

int* build_input_array(size_t N)
{
    int* p_arr = NULL;
    size_t i;

    p_arr = (int*)malloc(N*sizeof(int));
    if(p_arr == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    srand(time(0));
    for(i=0; i<N; ++i)
        p_arr[i] = rand()%CAP;

    return (p_arr);
}


/*Individual thread computation*/
void* thread_function(void* input)
{
    struct input* p_input = (struct input*)input;
    size_t i;
    size_t sum = 0;
    size_t* p_result = (size_t*)calloc(1, sizeof(size_t));

    if(p_result == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    for(i = p_input->start_index; i<p_input->start_index + p_input->nr_elements; ++i)
    {
        sum += p_input->p_arr[i];
    }

    *p_result = sum;
    return ((void*)p_result);
}
