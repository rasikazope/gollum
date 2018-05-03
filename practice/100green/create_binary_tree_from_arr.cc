#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;

    int _arrHouseValues_size = 0;
    cin >> _arrHouseValues_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _arrHouseValues;
    int _arrHouseValues_item;
    for(int _arrHouseValues_i=0; _arrHouseValues_i<_arrHouseValues_size; _arrHouseValues_i++) {
        cin >> _arrHouseValues_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _arrHouseValues.push_back(_arrHouseValues_item);
    }

    create_binary_tree(_arrHouseValues);
    cout << res << endl;

    fout.close();
    return 0;
}
