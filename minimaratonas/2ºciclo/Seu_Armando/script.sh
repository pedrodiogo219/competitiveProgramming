rm -rf "in"
rm -rf "sol"
mkdir "in"
mkdir "sol"

g++ sol.cpp -o certo
g++ gera.cpp -o gera

for i in {1..10}
do
	./gera > ./in/file$i.in
	./certo < ./in/file$i.in > ./sol/file$i.out
	sleep 1
done
