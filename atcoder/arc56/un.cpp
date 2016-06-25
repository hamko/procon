#include <unordered_map>
#include <iostream>

namespace std {
    template <>
        class hash<std::pair<int, int>> {
            public:
                size_t operator()(const std::pair<int, int>& x) const{
                    return hash<int>()(x.first) ^ hash<int>()(x.second);
                }
        };
}

int main(void) {
    std::unordered_map<std::pair<int, int>, int> umap;
    umap[std::make_pair(0, 0)] = 0;
    std::cout << umap[std::make_pair(0, 0)] << std::endl;

    return 0;
}
