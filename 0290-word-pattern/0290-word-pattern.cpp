class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss >> word) {
            words.push_back(word);

        }
        if(pattern.size()!=words.size())
        return false;

        unordered_map<char,string>chartoword;
        unordered_map<string,char>wordtochar;
        for(int i=0;i<pattern.size();i++) {
            char ch = pattern[i];
            string w = words[i];

            if(chartoword.count(ch) && chartoword[ch]!=w)
            return false;

            if(wordtochar.count(w) && wordtochar[w]!=ch)
            return false;

            chartoword[ch]=w;
            wordtochar[w]=ch;
        }
        return true;

        
    }
};