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

vector <int> get_neighbors(int num)
{
    vector <int> res;
    if (num >= 0 && num <=9) {
        if (num == 0) {
            res.push_back(4);
            res.push_back(6);
        } else if (num == 1) {
            res.push_back(8);
            res.push_back(6);
        } else if (num == 2) {
            res.push_back(7);
            res.push_back(9);
        } else if (num == 3) {
            res.push_back(4);
            res.push_back(8);
        } else if (num == 4) {
            res.push_back(3);
            res.push_back(9);
            res.push_back(0);
        } else if (num == 5) {
        } else if (num == 6) {
            res.push_back(1);
            res.push_back(7);
            res.push_back(0);
        } else if (num == 7) {
            res.push_back(6);
            res.push_back(2);
        } else if (num == 8) {
            res.push_back(1);
            res.push_back(3);
        } else if (num == 9) {
            res.push_back(4);
            res.push_back(2);
        } 
    } else {
        cout << "Error";
    }
    return res;

}

/*
 *  * Complete the function below.
 *   */
int numPhoneNumbers(int startdigit, int phonenumberlength) {

    int num_way = 0;
    vector < vector <int> > cache(phonenumberlength + 1, vector <int> (10, 0)); 

    for (int sd = 0; sd <= 10; sd++) {
        cache[1][sd] = 1; 
    }
    for (int pn = 2; pn <= phonenumberlength; pn++) {

        for (int sd = 0; sd < 10; sd++) {
            vector <int> neighbor = get_neighbors(sd);
            for (auto itr_neighbor = neighbor.begin(); itr_neighbor != neighbor.end(); ++itr_neighbor) {
                cache[pn][sd] += cache[pn -1][*itr_neighbor];
            }
        }
    }
#if 0 
    for (auto itr : cache ) {
        for (auto itr_ins : itr ) {
            cout << itr_ins << "  ";
        }
        cout << endl;
    }
#endif
    return cache[phonenumberlength][startdigit];
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    int _startdigit;
    cin >> _startdigit;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    int _phonenumberlength;
    cin >> _phonenumberlength;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    res = numPhoneNumbers(_startdigit, _phonenumberlength);
    cout << res << endl;

    fout.close();
    return 0;
}

// Sample input
#if 0
i/p:
1
5
o/p
26
i/p
6
10
o/p
2304
#endif
