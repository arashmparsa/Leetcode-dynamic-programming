class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long long fuel = startFuel;
        priority_queue<int> maxHeap;  // max heap of fuel amounts
        int stops = 0;
        int i = 0;
        int n = stations.size();
        
        while (fuel < target) {
            // Add all reachable stations to heap
            while (i < n && stations[i][0] <= fuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }
            
            // If no stations available, we can't reach target
            if (maxHeap.empty()) {
                return -1;
            }
            
            // Refuel at the station with max fuel (greedy choice)
            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }
        
        return stops;
    }
};