#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // stores the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // stores the larger half

public:
    MedianFinder() {
        // constructor initializes empty heaps
    }
    
    void addNum(int num) {
        // Step 1: Add to maxHeap first
        maxHeap.push(num);
        
        // Step 2: Balance by moving the largest from maxHeap to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Step 3: Ensure size property (maxHeap >= minHeap)
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            // even number of elements → average of two middle values
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            // odd number of elements → top of maxHeap
            return maxHeap.top();
        }
    }
};
