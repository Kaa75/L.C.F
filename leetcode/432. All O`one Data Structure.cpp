#include <bits/stdc++.h>
using namespace std;

class AllOne
{
public:
    unordered_map<string, int> m; 
    set<pair<int, string>> se;        

    AllOne()
    {
        m.clear(); 
    }

    
    void inc(string key)
    {
        int n = m[key];      
        m[key]++;            
        se.erase({n, key});      
        se.insert({n + 1, key}); 
    }

    
    void dec(string key)
    {
        int n = m[key]; 
        m[key]--;       
        se.erase({n, key}); 
        if (m[key] > 0)
            se.insert({n - 1, key}); 
        else
            m.erase(key); 
    }

    
    string getMaxKey()
    {
        if (!se.empty())
            return se.rbegin()->second; 
        return "";
    }

    
    string getMinKey()
    {
        if (!se.empty())
            return se.begin()->second; 
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */