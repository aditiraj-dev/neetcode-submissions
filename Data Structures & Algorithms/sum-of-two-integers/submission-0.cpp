class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for(int i = 31; i >=0 ; i--)
        {
            int b1 = a >> 31 - i & 1;
            int b2 = b >> 31 - i & 1;
            
            if(b1 && b2 && carry)
            {
                res |= 1 << 31 - i;
                carry = 1;
            }
            else if(carry == 1)
            {
                if(b1 || b2)
                {
                    carry = 1;
                }
                else
                {
                    res |= 1 << 31 - i;
                    carry = 0;
                }
            }
            else if(carry == 0)
            {
                if(b1 && b2)
                {
                    carry = 1;
                }
                else if(b1 || b2)
                {
                    res |= 1 << 31 - i;
                    carry = 0;
                }
                else carry = 0;
            }
        }

        return res;
    }
};
