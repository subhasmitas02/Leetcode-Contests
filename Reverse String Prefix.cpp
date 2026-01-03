class Solution {
public:
    string reversePrefix(string s, int k) {
        int i=0;
        while(i<k && k>0)
        {
            char temp = s[k-1];
            s[k-1] = s[i];
            s[i] = temp;
            i++;
            k--;
        }
        return s;
    }
};