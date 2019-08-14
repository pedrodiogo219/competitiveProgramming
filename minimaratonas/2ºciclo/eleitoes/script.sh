# rm -rf "in"
# rm -rf "sol"
# mkdir "in"
# mkdir "sol"

g++ sol.cpp -o certo
g++ gera.cpp -o gera

for i in {24..50}
do
	#./gera > ./in/file$i
	#./certo < ./in/file$i > ./sol/file$i
	python3 solution.py < ./in/file$i > ./candsol/file$i;
#	sleep 1
done
