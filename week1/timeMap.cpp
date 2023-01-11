#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string,map<int,string>> time;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        time[key][timestamp] = value; 
    }
    
    string get(string key, int timestamp) {
        if(time.find(key) == time.end()) return "";

        // get smallest value that is greater than timestamp
        auto it = time[key].upper_bound(timestamp);

        // if it dont exist
        if(it == time[key].begin()) return "";

        // Return value stored at previous position of current iterator
        return it->second;
        // else return prev(it)->second; 
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */