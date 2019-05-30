rm -rf input
rm -rf output
mkdir input
mkdir output

cont=0
for i in 1 2 3 4
do
	for j in 1 2 3 4 6 7 8
	do
		cont=$((cont+1))
		
		if [ $cont -le 9 ]
		then
		./gera $RANDOM $i > ./input/input0$cont.txt
		./sol < ./input/input0$cont.txt > ./output/output0$cont.txt
		else
		./gera $RANDOM $i > ./input/input$cont.txt
		./sol < ./input/input$cont.txt > ./output/output$cont.txt
		fi
		
		
	done
done
