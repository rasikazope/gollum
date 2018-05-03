#include <iostream>
using namespace std;



void neuronym(string ostring)
{

    cout << ostring[0] << ostring.length() - 2 << ostring[ostring.length() - 1] << endl;
    for ( int i = ostring.length() - 3; i>= 1 ; i-- ) {
        for(int k = 0; k <= ostring.length() - 2 - i; k++) {
            cout << ostring.substr(0, k+1) << i << ostring.substr(i+k+1)  << endl; 
        }
    }

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    neuronym("Rasika");
    return 0;
}

//note to self
//we find all neuronyms with len-3, len-4 etc
