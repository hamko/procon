make
for i in `seq 500`; do name=$(printf %03d $i); ./input > ./in/$name; done
