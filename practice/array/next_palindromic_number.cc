#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// I have not handled the 999 part
/*
 * Complete the function below.
 */
void
generateNextPalindrome(int num[], int n) 
{
     int mid = n/2;
     int i = 0, j = 0;
     bool left_smaller = false;

     i = mid - 1;

     (n % 2 == 0) ? j = mid: j = mid +1;

     while(i >= 0) {
         if (num[i] != num[j]) {
             break;
         }
         i--;
         j++;
     }      

        
    if (i < 0 || (num[i] < num[j])) {
         left_smaller = true;
     }

     while (i >= 0) {
         num[j++] = num[i--];
     } 

        int carry = 1;
        // get i and j again
     i = mid - 1;
     if (left_smaller) {
        if (n % 2 != 0) {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] = num[mid] % 10;    
            j = mid + 1; 
        } else {
            j = mid;
        }

        while (i >= 0) {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] = num[i] % 10;    
            num[j] = num[i];
            i--;
            j++;
        }
     }
}


bool all_nine(int arr[], int n)
{
        for (int i = 0; i < n; i++) {
            if(arr[i] !=9) {
                return false;
            }
        }        
        return true;
}

int nextPalindrome(unsigned int iInputNum) {

        vector<int> num;
        while(iInputNum) {
               num.push_back(iInputNum % 10);
               iInputNum =  iInputNum / 10;
        }
        reverse(num.begin(), num.end());
        int ans;

        if (all_nine(&num[0], num.size())) {
                int size = num.size() - 1;
                num.clear();
                num.push_back(1);
                        for (int i = 0; i < size; i++) {
                                num.push_back(0);
                        }
                num.push_back(1);

        } else {
                generateNextPalindrome(&num[0], num.size()); 
        }
     stringstream ss;
     for (auto itr: num) {
         ss << itr;
     }
        ss >> ans;
        return ans;
} 


int main()
{

        cout << nextPalindrome(99);


    return 0;
}
