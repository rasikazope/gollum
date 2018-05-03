#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct ele {
    int val;
    int arr_num;
    int arr_index;
};

struct compare {
    bool operator () (ele ele1, ele ele2) { return ele1.val > ele2.val; }
};

int *
merge_arr(int arr[][3], int k, int n)
{
    int *res_arr = new int[k*n];
    priority_queue <ele, vector<ele>, compare > pq;
    for (int i = 0; i < k; i++) {
        ele ele_t;
        ele_t.val = arr[i][0];
        ele_t.arr_num = i;
        ele_t.arr_index = 1;
        pq.push(ele_t);
    }

    int i = 0;

    while (!pq.empty()) {
        res_arr[i] = pq.top().val;
        
        ele ele_t;

        if (pq.top().arr_index < n) {
            ele_t.val = arr[pq.top().arr_num][pq.top().arr_index];
            ele_t.arr_num = pq.top().arr_num;
            ele_t.arr_index = pq.top().arr_index + 1;
            pq.push(ele_t);
        }
        pq.pop();
        
        i++;
    }
    return res_arr;

}




int main() {

    int arr[][3] = {
        {2, 5, 7},
        {3, 7 ,9},
        {1, 4, 8},
    };

    int k = (sizeof(arr)/sizeof(arr[0])) ; 
    int *res_arr = merge_arr(arr, k, 3);
    for (int i = 0; i < k * 3; i++) {
        cout << res_arr[i] << endl;
    }

    return 0;
}
