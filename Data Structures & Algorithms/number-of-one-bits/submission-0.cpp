class Solution {
public:
    int hammingWeight(uint32_t n) {
        //brute force approach is to convert the number to binary rep
        //iterate thr binary rep and count the number of 1s

        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            if((1 << i) & n) res++;
        }

        return res;
    }
};
