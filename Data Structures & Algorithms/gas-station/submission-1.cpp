class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++)
        {
            int j = i;
            int tank = gas[i];
            while(tank >= cost[j]) //to go to next stations
            {
                tank -= cost[j]; //subtrack cost to go to next station
                j = (j + 1) % n; //reach next station
                tank += gas[j]; //update gas from this station
                if(j == i) return i;
            }
        }

        return -1;
    }
};
