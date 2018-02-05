#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// 意図的にint型として読めるが、
// int型を代入できないようにしている
#define iter(type,it,n) for(type it{0}; it.index < n; it++)
template < size_t Tag >
struct index_t {
    int index;
    index_t& operator++(){ ++index; return *this; }
    index_t operator++(int){ auto tmp = index; ++index; return {tmp}; }
    index_t operator+(index_t const& i) const { return {this->index + i.index}; }
    index_t operator-(index_t const& i) const { return {this->index - i.index}; }
    index_t operator*(index_t const& i) const { return {this->index * i.index}; }
    index_t operator/(index_t const& i) const { return {this->index / i.index}; }
    bool operator<(index_t const& i) const { return {this->index < i.index}; }
    bool operator>(index_t const& i) const { return {this->index > i.index}; }
};
template<size_t Tag>
ostream &operator<<(ostream &o, const index_t<Tag> &it) { o << it.index;  return o; }

template <size_t Tag, class Container>
class TypedIndexContainer : public Container
{
    public:
        using Container::Container;
        void resize(int n) { Container::resize(n); }
        int size() { return Container::size(); }
        auto operator[](index_t<Tag> i) -> decltype(Container::operator[](i.index)) {
            return Container::operator[](i.index);
        }
        auto operator[](index_t<Tag> i) const -> decltype(Container::operator[](i.index)) {
            return Container::operator[](i.index);
        }
        // 意図的にa[int型]で読めるが、
        // int型では代入できないようにしてる
        auto operator[](int i) const -> decltype(i) {
            return Container::operator[](i);
        }
};


int main() {
    {
        // 生っぽい使い方。
        //
        // iterの初期化は{}で
        TypedIndexContainer<1, std::vector<int>> a{1, 2, 3, 4, 5};
        index_t<1> i1{2};
        std::cout << a[i1] << std::endl;
        cout << a.size() << endl;

        cout << i1 << endl;
        i1 = i1 + index_t<1>{4};
        cout << i1 << endl;
        cout << a[index_t<1>{0}] << endl;
        cout << a[0] << endl;

        const TypedIndexContainer<2, std::vector<int>> b{1, 2, 3, 4, 5};
        //std::cout << b[i1] << std::endl; // error
    }

    {
        using vll_a = TypedIndexContainer<1, std::vector<int>>;
        using iter_a = index_t<1>;
        using vll_b = TypedIndexContainer<2, std::vector<int>>;
        using iter_b = index_t<2>;
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
        int n = 100;
        vll_a a(n);
        // rep使うとめんどいことになる
        rep(i, n) a[iter_a{(int)i}] = i;
        rep(i, n) cout << a[iter_a{(int)i}] * a[iter_a{(int)i}] << " "; cout << endl;

        // iterを使ってください
        // indexは指定させないといけない
        // （index_tにintキャストを入れると、
        //   iter_a, iter_bの暗黙のキャスト有効に鳴ってしまうので必要悪）
        iter(iter_a, it, n) a[it] = it.index; 
        iter(iter_a, it, n) cout << a[it] * a[it] << " "; cout << endl;

        vll_b b(n);
         iter(iter_b, it, n) b[it] = it.index; 
//         iter(iter_b, i, n) a[i] = i; // Error, no viable overloaded operator[]
//         iter(iter_b, i, n) cout << a[i] << " "; cout << endl; // Error, no viable overloaded operator[]
//         b[0] = 10; // Error, expression is not assignable
    }
    return 0;
}
