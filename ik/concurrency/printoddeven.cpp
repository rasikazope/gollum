#include <mutex>
#include <iostream>
#include <thread>

using namespace std;

bool even_turn = true;
condition_variable cv;
mutex m;

void even() 
{
    static int counter = 0;
    unique_lock<mutex> ul(m);
    while (counter <= 10) {
  
        while (!even_turn) {
            cv.wait(ul);
        }
        cout << counter << endl;
        even_turn = false;
        counter += 2;
        cv.notify_all();
    }
}

void odd()
{
    static int counter = 1;
    unique_lock<mutex> ul(m);
    while (counter <= 10) {
        while (even_turn) {
            cv.wait(ul);
        }
        cout << counter << endl;
        even_turn = true;
        counter += 2;
        cv.notify_all();
    }
}

int main() 
{
    thread t1(even);
    thread t2(odd);

    t1.join();
    t2.join();
    return 0;
}
