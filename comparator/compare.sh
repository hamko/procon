echo "compiling input"
g++ -std=c++11 -o input input.cpp
echo "compiling user"
g++ -std=c++11 -o user user.cpp
echo "compiling answer"
g++ -std=c++11 -o answer answer.cpp

for i in `seq 100`; do
    echo "testcase" $i
    ./input > tmp
    ./user < tmp > user_output
    ./answer < tmp > answer_output
    diff user_output answer_output
    if [ $? -eq 1 ]; then
        echo "WA"
        echo "--input--"
        cat tmp
        echo "--user--"
        cat answer_output
        echo "--answer--"
        cat user_output
    fi
done
