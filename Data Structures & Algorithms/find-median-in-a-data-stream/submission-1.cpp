class MedianFinder {
public:

    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int> > mn;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
         mx.push(num);
        
        // Step 2: Balance by moving the largest from maxHeap to minHeap
        mn.push(mx.top());
        mx.pop();
        if(mn.size()>mx.size()){
            mx.push(mn.top());
            mn.pop();
        }

    }
    
    double findMedian() {
        
        if(mx.size()>mn.size()) return mx.top();
        else{
            return (mn.top()+mx.top())/2.0;
        }
    }
};
