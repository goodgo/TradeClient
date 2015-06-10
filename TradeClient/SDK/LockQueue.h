#pragma once 

#include <queue>
#include <boost/thread.hpp>
#define SDK_API __declspec(dllexport)
template<typename Data>  
class LockQueue  
{  
private:  
    std::queue<Data> the_queue;  
    mutable boost::mutex the_mutex;  
    boost::condition_variable the_condition_variable;  
public:  
    void push(Data const& data);
    bool empty() const;
    bool try_pop(Data& popped_value);
    void wait_and_pop(Data& popped_value); 
	int size();
};  

template<typename Data>  
void LockQueue<Data>::push(Data const& data)  
{  
    boost::mutex::scoped_lock lock(the_mutex);  
    the_queue.push(data);  
    lock.unlock();  
    the_condition_variable.notify_one();  
}  

template<typename Data>  
bool LockQueue<Data>::empty() const  
{  
    boost::mutex::scoped_lock lock(the_mutex);  
    return the_queue.empty();  
}  

template<typename Data>  
int LockQueue<Data>::size() 
{  
    boost::mutex::scoped_lock lock(the_mutex);  
    return the_queue.size();  
}  

template<typename Data>  
bool LockQueue<Data>::try_pop(Data& popped_value)  
{  
    boost::mutex::scoped_lock lock(the_mutex);  
    if(the_queue.empty())  
    {  
        return false;  
    }  
      
    popped_value=the_queue.front();  
    the_queue.pop();  
    return true;  
}  

template<typename Data>  
void LockQueue<Data>::wait_and_pop(Data& popped_value)  
{  
    boost::mutex::scoped_lock lock(the_mutex);  
    while(the_queue.empty())  
    {  
        the_condition_variable.wait(lock);  
    }  
      
    popped_value=the_queue.front();  
    the_queue.pop();  
}
