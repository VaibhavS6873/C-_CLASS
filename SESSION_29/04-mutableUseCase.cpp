class TheadSafeStack
{
    private: 
        int arr[10]; 
        int top_index; 
        mutable cpa::mutex mu_lock; 
    public: 
        TheadSafeStack() : top_index(-1){

        }

        void push(int new_data)
        {
            mu_lock.acquire(); 
            // push logic 
            mu_lock.release(); 
        }

        int pop()
        {
            mu_lock.acquire(); 
            // pop logic 
            mu_lock.release(); 
        }

        int top() const 
        {
            mu_lock.acquire(); 
            // top logic 
            mu_lock.release(); 
        }

        bool is_empty() const 
        {
            mu_lock.acquire(); 
            // is_empty logic 
            mu_lock.release(); 
        }
}; 