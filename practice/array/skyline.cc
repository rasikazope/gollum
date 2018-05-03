  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
  
        vector <pair<<int, int> > walls, ans;
        for (auto itr: buildings) {
            walls.insert(make_pair(itr[0], -itr[2]));
            walls.insert(make_pair(itr[0], itr[2]));
        }
        
        sort(walls.begin(), walls.end());
        multiset <int>  pq;
        int top = 0;
        while (auto wall_itr: walls) 
        {
            if (wall_itr.second > 0) {
                pq.insert(-walls_itr.second);
            } else {
                pq.erase(pq.find(walls_itr.first));
            }
            if (*pq.rbegin() != top) {
                ans.push_back(make_pair(wall_itr.first, top = *pq.rbegin()));
            }
        }
        return ans;
  }
