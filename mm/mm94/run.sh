input_dir=tests

binary=$1
if [ -z $1 ] ; then
    echo "./run [C++ binary] [run name] [time (sec)]"
    exit
fi

if [ -z $2 ] ; then
    runname=`date +%Y%m%d%H%M%S`
else
    runname=$2
fi

time=$3

cp $binary $runname.out
mkdir out/$runname
    
ls $input_dir/* | parallel -j 4 "(./$runname.out $time < {} > out/$runname/{/}.log); echo {/} is done; "

cd $input_dir/$runname
../score.sh .
cat score | sed -e 's/#final_score//' > s
cd -
rm $runname.out
