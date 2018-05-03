#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int count_bits(int num)
{
    int count_bit = 0;
    while (num) {
        num = num & (num -1);
        count_bit++;
    }
    return count_bit;
}


/*
 *  * Complete the function below.
 *   */
int printCountOfBitsSet(vector < int > intArr) {


    //TODO Use hash to store the number to bit mapping.
    int total_bit_count = 0;
    for (auto itr: intArr) {
        //cout << itr << " : " << count_bits(itr) << endl;
        total_bit_count += count_bits(itr);
    }
    return total_bit_count;
}


int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;

    int _intArr_size = 0;
    cin >> _intArr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _intArr;
    int _intArr_item;
    for(int _intArr_i=0; _intArr_i<_intArr_size; _intArr_i++) {
        cin >> _intArr_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _intArr.push_back(_intArr_item);
    }

    res = printCountOfBitsSet(_intArr);
    cout << res << endl;

    fout.close();
    return 0;
}

