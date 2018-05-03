#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;


void
stock_span(int arr[], int n)
{
    stack<int> mystack;

    mystack.push(0);
    for (int i = 1; i < n; i++) {
        while (arr[mystack.top()] < arr[i]) {
            mystack.pop();
        }
        cout << i - mystack.top() <<  " ";
        mystack.push(i);
    }
    cout << endl;
}


int main() {

    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    stock_span(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
