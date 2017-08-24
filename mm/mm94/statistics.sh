cat ok | sed -e 's/#feature_ok//' > ok_p
cat ng | sed -e 's/#feature_ng//' > ng_p
./statistics < ok_p > ok_pp
./statistics < ng_p > ng_pp
# plot "ok_pp", rep "ng_pp"
