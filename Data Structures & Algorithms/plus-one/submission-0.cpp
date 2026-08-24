class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            else carry = 0;

            res.push_back(sum);
        }

        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
