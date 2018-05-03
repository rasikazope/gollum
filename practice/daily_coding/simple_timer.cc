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

using namespace std;

condition_variable cv;
mutex cv_m;

void waits(int second) {
    this_thread::sleep_for(chrono::milliseconds(second * 100));
    cout << "Done with " << second << endl;
}

void signals() {

}


int main() {

    thread t1(waits, 1), t2(waits, 2), t3(waits, 3), t4(signals);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
