#include <unordered_map>
#include <vector>
#include <iostream>
#include <time.h>


using namespace std;

class magicmap {

    int size;
    unordered_map<int, int> mm;
    vector <pair <int, int> > v_map;

public:
    magicmap() {
        size = 0;
    }
    int get(int k);
    void set(int k, int v);
    void delete_map(int k);
    int get_random_val();
};

int magicmap::get(int k)
{
    if (!mm[k]) {
        return -1;
    }
    int v_index= mm[k];
    return v_map[v_index].second;
}


void magicmap::set(int k, int v) 
{
    if (size < v_map.size()) {
        v_map[size] = make_pair(k, v);
    } else {
        v_map.push_back(make_pair(k, v));
    }
    mm[k] = size; 
    size++;
}

void magicmap::delete_map(int k)
{
    int v_index= mm[k];
    mm[v_map[size - 1].first] = v_index;
    mm.erase(k);
    
    auto tuple = v_map[size - 1];
    v_map[v_index] = v_map[size - 1];
    v_map[size - 1] = tuple;
    size--;
}

int magicmap::get_random_val() 
{
    srand (time(NULL));
    int index = rand() % size ;
    return v_map[index].second;
}

// get random value should be O(1) too
int main() {

       magicmap MM;
       MM.set(10, 11);
       MM.set(20, 21);
       MM.set(30, 31);
       cout << "Random " << MM.get_random_val() << endl;
       cout << "20: " << MM.get(20)<< endl; 
       MM.delete_map(20); 
       MM.set(40, 41);
       MM.set(50, 51);
       MM.set(60, 61);
       cout << "Random "<< MM.get_random_val() << endl;
       cout << "50: " << MM.get(50)<< endl; 
       cout << "30: " << MM.get(30)<< endl; 
       cout << "40: " << MM.get(40)<< endl; 
       cout << "20: " << MM.get(20)<< endl; 
       cout << "Random "<< MM.get_random_val() << endl;
       return 0;
}




