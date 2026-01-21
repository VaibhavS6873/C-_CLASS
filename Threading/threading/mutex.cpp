#include "thread.hpp"

cpa::mutex::mutex()
{
    pthread_mutex_init(&mu, NULL);
}

void cpa::mutex::lock()
{
    pthread_mutex_lock(&mu);
}

void cpa::mutex::unlock()
{
    pthread_mutex_unlock(&mu);
}

