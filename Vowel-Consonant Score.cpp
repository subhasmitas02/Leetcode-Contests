class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowelCount = 0, consoCount = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') vowelCount++;
            else if(isalpha(s[i]))
                consoCount++;
        }
        if(consoCount > 0)
            return vowelCount / consoCount;
        return 0;
    }
};