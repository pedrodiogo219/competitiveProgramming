cont=0
for i in 1 2 3 4 5
do
	for j in 1 2 3 4 5 6
	do
		
		
		if [ $cont -le 9 ]
		then	
			mv output/output0$cont.txt output/file0$cont;
			mv input/input0$cont.txt input/file0$cont;
		else
			mv output/output$cont.txt output/file$cont;
			mv input/input$cont.txt input/file$cont;
		fi
		cont=$((cont+1))
		
		
	done
done
