#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <atomic>

using namespace std;

condition_variable cv;
mutex cv_m;
atomic<bool> done;


void waits(int second) {

    unique_lock <mutex> u_lock(cv_m);
    while (done == false) {
        cv.wait(u_lock);
        cout << "Timeout received " << second << endl;
    }
}

void signals() {
    this_thread::sleep_for(chrono::milliseconds(400));
    done = true;
    cv.notify_all();
}


int main() {

    done = false;
    thread t1(waits, 1), t2(waits, 2), t3(waits, 3), t4(signals);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
