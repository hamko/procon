// ハッシュの定義方法
struct S {
    string first_name;
    string last_name;
};
using argument_type = S;
template<> struct hash<argument_type>
{
    size_t operator()(argument_type const& s) const
    {
        return hash<string>{}(s.first_name) ^ (hash<string>{}(s.last_name) << 1); 
    }
};


// unordered_set<S> s;
