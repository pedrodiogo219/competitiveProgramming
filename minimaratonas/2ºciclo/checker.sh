g++ teste.cpp -o "teste"
mkdir $1candsol

cont=0
for f in $1in/*;
do
  ./teste < $f > "$1candsol/$cont"
  cont=$((cont+1))
done


cont=0
for f in $1sol/*;
do
  echo $f
  diff $f "$1candsol/$cont"
  cont=$((cont+1))
done
