#include "thread.hpp"

cpa::thread::thread(void*(*pfn)(void*),
                    void* _data,
                    pthread_attr_t* _attrs):thread_entry_function(pfn),
                                            thread_input_data(_data),
                                            thread_attrs(_attrs){}

void cpa::thread::run()
{
    pthread_create(&thread_id,
                    thread_attrs,
                    thread_entry_function,
                    thread_input_data);
}

void* cpa::thread::join()
{
    pthread_join(thread_id, &return_value);
    return return_value;
}