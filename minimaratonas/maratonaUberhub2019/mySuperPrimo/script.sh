rm -rf "in"
rm -rf "out"
mkdir "in"
mkdir "out"

g++ sol.cpp -o certo
g++ gera.cpp -o gera

cont=0
for i in 1 2 3
do
	for j in 1 2 3 4 5 6 7 8
	do
		cont=$((cont+1))

		if [ $cont -le 9 ]
		then
		./gera $RANDOM $i > ./in/in0$cont.txt
		./certo < ./in/in0$cont.txt > ./out/out0$cont.txt
		else
		./gera $RANDOM $i > ./in/in$cont.txt
		./certo < ./in/in$cont.txt > ./out/out$cont.txt
		fi


	done
done

#
# for i in {1..10}
# do
# 	./gera > ./in/file$i.in
# 	./certo < ./in/file$i.in > ./sol/file$i.out
# 	sleep 1
# done
