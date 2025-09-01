class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) { 
        priority_queue<tuple<double, int, int>> maxHeap;

        for(vector<int> cls: classes) {
            int pass = cls[0], total = cls[1];
            double diff = (double) (pass + 1)/(total + 1) - (double) pass /total;
            maxHeap.push({diff, pass, total});
        }        

        while(extraStudents > 0) {
            auto [diff, pass, total] = maxHeap.top();
            maxHeap.pop();

            pass ++;
            total++;
            double change = (double) (pass + 1)/(total + 1) - (double) pass /total;

            maxHeap.push({change, pass, total});
            extraStudents--;
        }

        double ans = 0;
        while(!maxHeap.empty()) {
            auto [ratio, pass, total] = maxHeap.top();
            ans += (double) pass/total;
            maxHeap.pop();
        }
        return (double) ans / classes.size();
    }
};