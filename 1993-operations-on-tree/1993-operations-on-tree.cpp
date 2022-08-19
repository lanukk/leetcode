class LockingTree {
    vector<vector<int>> desendants, ascendants;
    int n;
    vector<int> checkLock;
public:
    LockingTree(vector<int>& parent) {
        n = (int)parent.size();
        ascendants.resize(n);
        desendants.resize(n);
        checkLock.assign(n, -1);
        
        for(int i = 1; i < n; i++){
            desendants[parent[i]].push_back(i);
            ascendants[i].push_back(parent[i]);
        }
    }
    
    bool lock(int num, int user) {
        if(checkLock[num] != -1)
            return false;
        checkLock[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(checkLock[num] != user)
            return false;
        
        checkLock[num] = -1;
        return true;
    }
    
    bool checkDesendant(int v){
        if(checkLock[v] != -1)
            return true;
        
        bool ans = false;
        
        for(int u : desendants[v]){
            ans = (ans | checkDesendant(u));
        }
        
        return ans;
    }
    
    bool checkAscendant(int v){
        if(checkLock[v] != -1)
            return false;
        
        bool ans = true;
        
        for(int u : ascendants[v]){
            ans = (ans & checkAscendant(u));
        }
        
        return ans;
    }
    
    void unlockDesendants(int v){
        checkLock[v] = -1;
        for(int u : desendants[v])
            unlockDesendants(u);
        
        return;
    }
    
    bool upgrade(int num, int user) {
        if(checkLock[num] != -1)
            return false;
        
        if(!checkDesendant(num))
            return false;
        
        if(!checkAscendant(num))
            return false;
        
        unlockDesendants(num);
        
        checkLock[num] = user;
        
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */