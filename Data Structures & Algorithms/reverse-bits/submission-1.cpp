class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t copy = 0;
        for(int i = 0; i < 32; i++)
        {
            if((n >> 31-i) & 1) //check if this bit is set
            {
                //set 31 - i th bit
                copy |= 1 << i;
            }
        }

        return copy;
    }
};
