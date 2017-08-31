#include <stdio.h>
#include <iostream>

using namespace std;


class Hitcount {

private:
    int timestamp[60];
    int hitcount[60];

public:
    Hitcount() {
        memset(timestamp, 0, sizeof(timestamp));
        memset(hitcount, 0, sizeof(hitcount));
    }
    void hit(int ts) {
       int bucket = ts % 60;
       if (timestamp[bucket] == ts) {
        hitcount[bucket]++;
       } else {
        timestamp[bucket] = ts; 
        hitcount[bucket] = 1;
       }
    }

    int get_count(int ts) {
        int count = 0;
        for (int i = 0; i < 60; i++) {
            if (ts - timestamp[i] < 60) {
                count += hitcount[i];
            }
        }
        return count;
    }
};

int main() {

    Hitcount hc;
    hc.hit(6);
    hc.hit(7);
    hc.hit(58);
    hc.hit(58);
    hc.hit(58);
    hc.hit(58);
    cout << endl << hc.get_count(70) << endl;


    return 0;
}
