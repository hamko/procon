#include <bits/stdc++.h>
using namespace std;

template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss;
    ss.str(s);
    string item;
    if (delim == ' ' || delim == '\t' || delim == '\n') 
        while (ss >> item) 
            *(result++) = item;
    else 
        while (getline(ss, item, delim)) 
            *(result++) = item;
}


vector<string> split(const string &s, char delim = ' ') {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

int main(void) {
    {
        vector<string> ret = split("This is a test, thanks");
        for (auto s : ret) 
            cout << s << endl;
    }
    {
        vector<string> ret = split("This is a test, thanks", ',');
        for (auto s : ret) 
            cout << s << endl;
    }
    return 0;
}
