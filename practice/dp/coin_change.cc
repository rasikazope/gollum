#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;



/*
 *  * Complete the function below.
 *   */
void makeChange(int C, vector < int > intDenominations) {


}



int main() {
    int _C;
    cin >> _C;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _intDenominations_size;
    cin >> _intDenominations_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _intDenominations;
    int _intDenominations_item;
    for(int _intDenominations_i=0; _intDenominations_i<_intDenominations_size; _intDenominations_i++) {
        cin >> _intDenominations_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _intDenominations.push_back(_intDenominations_item);
    }

    makeChange(_C, _intDenominations);

    return 0;
}

#if 0 
i/p
4
3
1
2
3
o/p
1,3
2,2


#endif
