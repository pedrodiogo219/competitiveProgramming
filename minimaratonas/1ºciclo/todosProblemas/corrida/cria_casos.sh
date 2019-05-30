rm -rf input
rm -rf output
mkdir input
mkdir output

cont=0
for i in 1 2 3 4 5 6
do
	for j in 1 2 3 4 5
	do
		cont=$((cont+1))
		./gera $RANDOM $i > ./input/input$cont.txt
		./sol < ./input/input$cont.txt > ./output/output$cont.txt
	done
done
