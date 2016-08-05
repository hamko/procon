#include <vector>     // vector
#include <iterator>   // advance
#include <utility>    // pair
#include <algorithm>  // implace_merge, sort, etc.
#include <iterator>
#include <cassert>    // assert
#include <iostream>

template<typename Pair>
struct first_less {
  bool operator()(const Pair& x, const Pair& y) const {
    return x.first < y.first;
  }
};

namespace sparse {

template<typename T>
class matrix {
public:
  using key_type   = std::pair<int,int>;      // 位置(first,second) = (y,x)
  using value_type = std::pair<key_type,T>;   // 行列の[y][x]成分
  using container  = std::vector<value_type>;
  using compare    = first_less<value_type>;
private:
  container dictionary_; // 可変長配列による辞書
  typename container::size_type sorted_size_; // dictionary_の先頭からココまでソート済

public:

  matrix() : sorted_size_(0) {}

  void finalize() {
    // dictionary_を再ソートする
    if ( dictionary_.size() != sorted_size_ ) {
      // dictionary_.begin() から mid まで（前半）はソート済なので
      typename container::iterator mid = dictionary_.begin();
      std::advance(mid, sorted_size_);
      // mid から　dictionary_.end() まで（後半）をソートし
      std::sort(mid, dictionary_.end(), compare());
      // 前半と後半をマージする
      std::inplace_merge(dictionary_.begin(), mid, dictionary_.end(), compare());
      sorted_size_ = dictionary_.size();
    }
  }

  void clear() {
    // dictionary_を空にする
    sorted_size_ = 0; dictionary_.clear();
  }

  std::size_t size() const { return dictionary_.size(); }

  bool ok() const {
    // dictionary_にrow.colの重複がなければtrueを返す
    // ただし、dictionary_は（finalize()によって）ソート済でなければならない
    return std::adjacent_find(dictionary_.begin(), dictionary_.end()) == dictionary_.end();
  }

  typename container::const_iterator find_at(int row, int col) const {
    // row,col の組を dicrtionary_ から探す
    assert( dictionary_.size() == sorted_size_ );
    value_type tmp(std::make_pair(row,col), T());
    typename container::const_iterator iter = 
      std::lower_bound(dictionary_.cbegin(), dictionary_.cend(), tmp, compare());
    return ( iter != dictionary_.cend() && iter->first == tmp.first ) 
      ? iter : dictionary_.end();
  }

  void insert(int row, int col, const T& val) {
    // row, col, val の組を dictionary_の末尾に挿入する
    dictionary_.emplace_back(std::make_pair(row,col), val);
  }

  T* at(int row, int col, T* valp) const {
    // rpw,colの組がdictionary_にあるなら対応する値を(*valp)
    // にセットし、valpを返す(なければnullptrを返す)
    typename container::const_iterator iter = find_at(row, col);
    if ( iter == dictionary_.end() ) return nullptr;
    *valp = iter->second;
    return valp;
  }

  bool at(int row, int col, T& val) const {
    // rpw,colの組がdictionary_にあるなら対応する値をval
    // にセットし、trueを返す（なければfalseを返す）
    return at(row, col, &val) != nullptr;
  }

  bool replace_at(int row, int col, const T& val) {
    // rpw,colの組がdictionary_にあるなら対応する値をval
    // に変更し、を返す（なければfalseを返す）
    typename container::iterator iter = find_at(row, col);
    bool found = iter != dictionary_.end();
    if ( found ) {
      iter->second = val;
    }
    return found;
  }

  template<typename Function>
  void enumerate(Function fn) const {
    // dictionary_内の各 row,col,val を引数としてfnを呼ぶ
    for ( const value_type& entry : dictionary_ ) {
      fn(entry.first.first, entry.first.second, entry.second);
    }
  }



};

// k : row
// m : col
// l : ??
template<typename T>
matrix<T> multiplies(const matrix<T>& A, const matrix<T>& B, int k, int l, int m) {
  matrix<T> out;
  // out[row, col] = Σ(A[row,i] * B[i,col]
  for ( int row = 0; row < k; ++row ) {
    for ( int col = 0; col < m; ++col ) {
      T sum = T(0);
      T aval;
      T bval;
      for ( int i = 0; i < l; ++i ) {
        aval = T(0); A.at(row, i, aval);
        bval = T(0); B.at(i, col, bval);
        sum += aval * bval;
      }
      if ( sum != T(0) ) {
        out.insert(row, col, sum);
      }
    }
  }
  out.finalize();
  return out;
}

template<typename T>
void fill_diagonal(matrix<T>& mtx, int n, const T& val) {
  // (0,0), (1,1) ... (n-1,n-1) を val で埋める
  for ( int i = 0; i < n; ++i ) {
    mtx.insert(i, i, val);
  }
  mtx.finalize();
}


}

int main() {
    using namespace sparse;

    matrix<float> A;
    fill_diagonal(A, 4, 1.0f); // 4x4の単位行列

    matrix<float> B; // 隣接行列
    B.insert(0, 0, 1.0f);
    B.insert(0, 1, 1.0f);
    B.insert(0, 2, 1.0f);
    B.insert(1, 2, 1.0f);
    B.insert(2, 3, 1.0f);
    B.insert(3, 1, 1.0f);
    B.finalize();

    // A = A * B を3回行う
    A = multiplies(A, B, 4, 4, 4);
    A = multiplies(A, B, 4, 4, 4);
    A = multiplies(A, B, 4, 4, 4);

    A.enumerate([](int row, int col, float val) {
            std::cout << '[' << row << ',' << col << "] " 
            << val << std::endl;}); 
    std::cout << std::endl;
}
