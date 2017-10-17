vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> hashmap;
    for(const auto& i : strs){
        string s = i;
        sort(s.begin(), s.end());
        hashmap[s].push_back(i);
    }
    for(const auto& i : hashmap){
        vector<string> s = i.second;
        sort(s.begin(), s.end());
        result.push_back(s);
    }
    return result;  
}

