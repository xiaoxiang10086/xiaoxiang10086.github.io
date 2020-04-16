class Solution {
public:
    string replaceSpace(string s) {
        //空字符串的情况
        if (s.empty()){
            return s; 
        }

        string str;
        for (auto c : s) {
            if(c == ' ') {
                str.push_back('%');	//push_back() 在字符串str后添加字符
                str.push_back('2');
                str.push_back('0');
            } else {
                str.push_back(c);
            }
        }
        return str;
    }       
};