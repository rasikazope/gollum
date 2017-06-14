#include <math.h>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv_not_empty;
condition_variable cv_not_full;
mutex m_lock;
mutex m_cv_lock;
int buffer[10];
int buf_index = 0;
int my_count = 0;

void producer() 
{
    std::unique_lock<std::mutex> lck_not_full(m_cv_lock);
    while(1) {
        cv_not_full.wait(lck_not_full, [](){return my_count != 10; });
        m_lock.lock();
        cout << "In producer: ";
        int produced = rand() % 100;
        cout << produced << endl;

        buf_index = (buf_index + 1) % 10;
        buf_index++;
        my_count++;
        buffer[buf_index] = produced;
        m_lock.unlock();
        lck_not_full.unlock();
        cv_not_empty.notify_one();
    }
}

void consumer()
{
    std::unique_lock<std::mutex> lck(m_cv_lock);
    while (1) {
        cv_not_empty.wait(lck, []() { return my_count != 0; });
        m_lock.lock();
        cout << "In consumer: ";
        cout << buffer[buf_index] << endl;
        buf_index = (buf_index + 1) % 10;
        buf_index--;
        my_count--;
        m_lock.unlock();
        lck.unlock();
        cv_not_full.notify_one();
    }
}

int main()
{

    thread t1[10];
    for (int i = 0; i < 10; i++) {
        t1[i] = thread(producer);
    }

    thread t2[10];
    for (int i = 0; i < 10; i++) {
        t2[i] = thread(consumer);
    }
    cv_not_empty.notify_all();   
    cv_not_full.notify_all();   

    for (int i = 0; i < 10; i++) {
        t1[i].join();
        t2[i].join();
    }

    return 0;
}
