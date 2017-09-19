g++ -std=c++11 list_duplicates.cpp
find .. -name '*.cpp' | xargs md5sum | ./a.out | sort | uniq
