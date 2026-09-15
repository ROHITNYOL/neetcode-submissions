class Solution {
public:
// Same as next greater element 
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> s;
        int n = temperatures.size();

        vector<int> result(n,0);

        for(int i=n-1;i>=0;i--){

            while(s.size()>0 && temperatures[s.top()]<=temperatures[i]) s.pop();

            if(s.size()>0) result[i] = s.top()-i;

            s.push(i);
        }

        return result;
    }
};
