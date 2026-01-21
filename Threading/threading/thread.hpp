#ifndef _THREAD_HPP
#define _THREAD_HPP

#include <pthread.h>

namespace cpa
{
    class thread
    {
        private:
            pthread_t thread_id;
            pthread_attr_t* thread_attrs;
            void* (*thread_entry_function)(void*);
            void* thread_input_data;
            void* return_value;
        public:
            thread(void*(*pfn)(void*),
                    void* _data = NULL,
                    pthread_attr_t* _attrs=NULL);
            void* join();
            void run();
    };

    class mutex
    {
        private:
            pthread_mutex_t mu;
        public:
            mutex();
            void lock();
            void unlock();
    };
}




#endif