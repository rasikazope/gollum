#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.end());
    
    for (int i = 0; i + 1 < A.size();) {
        int temp = A[i];
        A[i] = A[i+1];
        A[i+1] = temp;
        i = i + 2;
    
    }
    
    return A;
    
    
}

 

int main() {

        vector <int> myarr =  {6, 17, 15, 13 };
        wave(myarr);
for (auto itr: myarr) {
        cout << itr << " ";
} 
    return 0;
}
