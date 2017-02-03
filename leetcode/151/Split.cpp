#include <bits/stdc++.h>
using namespace std;

template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

class Solution {
    public:
        void reverseWords(string &s) {
            vector<string> ret = split("This is a test.", ' ');
            reverse(ret.begin(), ret.end());
            string s; 
            for (int i = 0; i < ret.size(); i++) {
                string += x;
                if (i != ret.size() - 1) 
                    string += " ";
            }
            return string;
        }

};
