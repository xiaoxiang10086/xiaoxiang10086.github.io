class Solution {
public:
	/*
	string& replace (size_t pos, size_t len, const string& str);

	pos：被替换字符串的起始下标
	len：被替换字符串的长度
	str：用来进行替换的字符串
	*/
    string replaceSpace(string s) {
        int pos;
        string with = "%20";
        while ((pos = s.find(" ")) >= 0) {
        	s = s.replace(pos, 1, with);
        }
    }       
};