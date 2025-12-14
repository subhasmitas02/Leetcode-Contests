class Solution {
public:
    int cntVowels(const string &wd)
    {
        int cnt = 0;
        const set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(char ch : wd)
        {
            if(vowels.count(ch))
                cnt++;
        }
        return cnt;
    }
    string reverseWords(string s) {
        stringstream s1(s);
        string wd;
        vector<string> wds;
        while(s1 >> wd)
        {
            wds.push_back(wd);      
        }
        if(wds.empty())
            return "";

        int vowelCnt = cntVowels(wds[0]);
        for(int i=1; i<wds.size(); ++i)
        {
            if(cntVowels(wds[i]) == vowelCnt)
            {
                reverse(wds[i].begin(), wds[i].end());
            }
        }
        string ans = "";
        for(int i=0; i<wds.size(); ++i)
        {
            ans += wds[i];
            if(i < wds.size()-1)
                ans += " ";
        }
        return ans;
    }
};