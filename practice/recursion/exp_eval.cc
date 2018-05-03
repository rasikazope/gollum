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

int 
evaluate(list <int> operands, list <char> operators)
{
    int result;
    auto itr_operands = operands.begin();
    auto itr_operators = operators.begin();
    while (itr_operators != operators.end()) {
        if (*itr_operators == '*') {
            int product = *itr_operands;
            itr_operands = operands.erase(itr_operands);
            product = product * (*itr_operands);
            *itr_operands = product;
        } else {
            itr_operands++;
        }
        itr_operators++;
    }
    result = accumulate(operands.cbegin(), operands.cend(), 0);
    return result;
}

void 
expressionCreator_helper(string strDigits, int offset, int cur, list<int> &operands, list<char> &operators, int iK, vector <string> &res) 
{
    cur = cur * 10 + (strDigits[offset] - '0');
    if (offset >= strDigits.length() - 1) {
        operands.push_back(cur);
        //Print the operand and operator list
        if (evaluate(operands, operators) ==  iK) {
            string tmp_str;
            auto operand_itr = operands.begin();
            tmp_str += to_string(*operand_itr); 
            for (auto op: operators) {
                tmp_str.push_back(op); 
                operand_itr++;
                tmp_str += to_string(*operand_itr); 
            }
            tmp_str.push_back('='); 
            tmp_str += to_string(iK); 
            res.push_back(tmp_str);
        }
        operands.pop_back();
        return;
    }

    expressionCreator_helper(strDigits, offset+1, cur, operands, operators, iK, res); 
    
    operands.push_back(cur);
    operators.push_back('+');
    expressionCreator_helper(strDigits, offset+1, 0, operands, operators, iK, res); 
    operators.pop_back();
    operands.pop_back();

    operands.push_back(cur);
    operators.push_back('*');
    expressionCreator_helper(strDigits, offset+1, 0, operands, operators, iK, res); 
    operators.pop_back();
    operands.pop_back();

}



/*
 *  * Complete the function below.
 *   */
vector < string > expressionCreator(string strDigits, int iK) 
{
    list<int> operands;
    list<char> operators; 
    vector <string> res;
    expressionCreator_helper(strDigits, 0, 0, operands, operators, iK, res); 
    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < string > res;
    string _strDigits;
    getline(cin, _strDigits);

    int _iK;
    cin >> _iK;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    res = expressionCreator(_strDigits, _iK);
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}


