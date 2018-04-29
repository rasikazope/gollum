/*Implement a job scheduler which takes in a function f and an integer n, and calls f after n mil
liseconds.*/
#include <thread>
#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <mutex>
#include <condition_variable>

using namespace std;
mutex cv_mutex;
condition_variable cv;
bool api_invoked_var = false;

void
func2() 
{
    cout << "In func2" << endl;
}

void
func1() 
{
    cout << "In func1" << endl;
}

struct api_input 
{
    chrono::system_clock::time_point abs_time;
    function <void(void)> callback;
    api_input(chrono::system_clock::time_point ms, function <void(void)> cb) {
        abs_time = ms;
        callback = cb;
    }
};

class compare {
    public:
    bool operator()(api_input ai1, api_input ai2) {
        return ai1.abs_time > ai2.abs_time; 
    }
};

priority_queue < api_input, vector<api_input>, compare> pq;   
class Timer {

    public:
    Timer() {
        auto wait_time = chrono::system_clock::now() + chrono::milliseconds(1000000);
        while (1) {
            
            unique_lock <mutex> pq_lock(cv_mutex);

            while (api_invoked_var == false) {
                if (cv_status::timeout == cv.wait_until(pq_lock, wait_time)) {

                    cout << endl << "Timeout " << endl << endl;  
                    if (!pq.empty()) {
                        pq.top().callback();
                        pq.pop();
                    }
                } else {
                    cout << endl << "Api called " << endl << endl;  
                    auto wait_time = pq.top();  
                    api_invoked_var = false;
                }
                if (!pq.empty()) {    
                    wait_time = pq.top().abs_time;                   
                } else {
                    wait_time = chrono::system_clock::now() + chrono::milliseconds(1000000); 
                }
            }
        }
    }
    
};

void call_api(int interval, function<void(void)> func) 
{
    api_input ap1(chrono::system_clock::now() + chrono::milliseconds(interval), func);
    unique_lock <mutex> pq_lock(cv_mutex);
    pq.push(ap1);
    api_invoked_var = true;
    cv.notify_all();
}

void timer_thread()
{
    Timer t1;

}

int main() {

    thread t1(timer_thread);
    thread t2(call_api, 100, func1);
    thread t3(call_api, 50, func2);
    t1.join();
    t2.join();
    t3.join();
}
