
cont=0
var=( {a..z} )
for f in in/*
do
  cp $f SuperPrimo-${var[cont]}.in
  cont=$((cont+1))
done
