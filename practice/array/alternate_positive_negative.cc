#include <stdio.h>
#include <iostream>
using namespace std;

void rotate(int arr[], int i, int j) 
{
    int j_ele = arr[j];
    for (int ctr = j; ctr > i; ctr--) {
        int tmp = ctr - 1;
        arr[ctr] = arr[tmp]; 
    }
    arr[i] = j_ele;
}

int                
get_index_first_ele_with_opp_sign(int arr[], int start, int &j, bool is_pos, int size)
{
    // What if we do not find a value here ? 
    for (int i = start; i < size; i++) {
        if (is_pos && arr[i] >= 0) {
            j = i;
            break;
        } else if (!is_pos && arr[i] < 0) {
            j = i;
            break;
        }
    }
}

    
void 
alternate_neg_pos(int arr[], int size)
{
    int j;
    for (int i = 0; i < size; i++) {
        j = 0;
        if (i % 2 == 0) {
            // Number should be positive
            if(arr[i] < 0) {
                get_index_first_ele_with_opp_sign(arr, i+1, j, true, size);
                if (j != 0) {
                    rotate(arr, i, j);
                }
            }
        } else {
            if(arr[i] >= 0) {
                get_index_first_ele_with_opp_sign(arr, i+1, j, false, size);
                if (j != 0) {
                    rotate(arr, i, j);
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}


int main() 
{

    int arr[] = { 2, 3, -4, -9, -1, -7, 1, 5, -6};
    alternate_neg_pos(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
