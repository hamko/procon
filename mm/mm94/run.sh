if [ -z $1 ]; then
    echo "./run [C++ binary] [time (sec)]"
    exit
fi

dir=`date +%Y%m%d%H%M%S`
cp $1 ${dir}.out
mkdir out/${dir}
for filename in `ls tests`; do
    echo "running: " $filename
    ./${dir}.out $2 < tests/$filename > out/${dir}/${filename}.log
done
cd in/${dir}
../score.sh .
cat score | sed -e 's/#final_score//' > s
cd -
rm ${dir}.out
