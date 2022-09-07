class MedianFinder {
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        if((int)right.size() > 0 && right.top() < left.top()){
            right.push(left.top());
            left.pop();
        }
        // if(left.size() == 0 || num < left.top())
        //     left.push(num);
        // else
        //     right.push(num);
        
        if((int)right.size() - (int)left.size() >= 2){
            left.push(right.top());
            right.pop();
        }
        if((int)left.size() - (int)right.size() >= 2){
            right.push(left.top());
            left.pop();
        }
        
    }
    
    double findMedian() {
        if(left.size() > right.size())
            return left.top();
        if(right.size() > left.size())
            return right.top();
        
        return (left.top() + right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */