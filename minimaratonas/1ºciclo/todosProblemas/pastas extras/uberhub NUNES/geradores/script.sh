#!/bin/bash
g++ minhocaGen.cpp
for (( counter=0; counter<100; counter++ ))
do
	if [ $counter -lt 10 ];
	then ./a.out > "minhoca/input0$counter.txt"
	else ./a.out > "minhoca/input$counter.txt"
	fi
done

g++ minhoca.cpp

for (( counter=0; counter<100; counter++ ))
do
	if [ $counter -lt 10 ];
	then ./a.out < "minhoca/input0$counter.txt" > "minhoca/output0$counter.txt"
	else ./a.out < "minhoca/input$counter.txt" > "minhoca/output$counter.txt"
	fi
done



printf "\n"
