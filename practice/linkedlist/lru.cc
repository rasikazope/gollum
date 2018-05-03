#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRU {

    private:
        int _capacity;
        typedef list <pair<string, string> > LRU_DLL;
        LRU_DLL lru_dll;
        unordered_map <string, LRU_DLL::iterator> lru_map;         
    
    public:
        LRU(int capacity) :
            _capacity (capacity)
        {
        }

        void set(string k, string v);
        string get(string k);
        void evict();
};

void 
LRU::evict()
{
    lru_map.erase(lru_dll.back().first);
    lru_dll.pop_back();
}

void 
LRU::set(string k, string v) 
{
    if (lru_dll.size() >= _capacity) {
        evict(); 
    }
    
    lru_dll.push_front(make_pair(k, v));
    lru_map[k] = lru_dll.begin();

}


string 
LRU::get(string k)
{
    auto itr = lru_map.find(k);

    if ( lru_map.end() == itr) {
        return "Not Found";
    } else {
        lru_dll.push_front(*itr->second);
        lru_dll.erase(itr->second);
        lru_map[k] = lru_dll.begin(); 
        return itr->second->second;
    }
}



int main() {

    LRU lru(3);
    lru.set("k1", "v1");
    lru.set("k2", "v2");
    lru.set("k3", "v3");
    cout << lru.get("k1") << endl;
    lru.set("k4", "v4");

    cout << lru.get("k1") << endl;
    cout << lru.get("k2") << endl;
    cout << lru.get("k3") << endl;
    cout << lru.get("k4") << endl;
    return 1;
}
