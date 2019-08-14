g++ sol.cpp -o certo
g++ candidata.cpp -o candidata

rm -rf "candsol"

mkdir candsol

for f in in/*
do
	#echo "$i"
	./candidata < "$f" > "candsol/${f:3:6}.out"
done
