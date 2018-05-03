#include <stdio.h>
#include <iostream>

using namespace std;

void t_of_h(int no_of_disc, char from, char to, char spare) 
{

    if (no_of_disc == 1) {
        cout << "Moving from " << from << " to " << to << endl;
        return;
    }
    t_of_h(no_of_disc-1, from, spare, to);
    t_of_h(1, from, to, spare);
    t_of_h(no_of_disc-1, spare, to, from);

}



int main() {

    t_of_h(6, 'A', 'B', 'C');
    return 0;
}
