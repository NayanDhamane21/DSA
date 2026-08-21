class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();

        int firstZero = -1;
        int zeroCount = 0;

        for (int i = 0; i < n; i++) {
            if (binary[i] == '0') {
                if (firstZero == -1)
                    firstZero = i;
                zeroCount++;
            }
        }

        if (zeroCount <= 1)
            return binary;

        string ans(n, '1');

        ans[firstZero + zeroCount - 1] = '0';

        return ans;
    }
};