class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        for(int n : hand) count[n]++;

        for(int n : hand)
        {
            int start = n;
            while(count[start - 1] > 0) start--; //find the min from this num by going back
            while(start <= n)
            {
                while(count[start] > 0)
                {
                    for(int i = start; i < start + groupSize; i++)
                    {
                        if(count[i] == 0) return false;
                        count[i]--;
                    }
                }
                start++;
            }
        }

        return true;
    }
};
