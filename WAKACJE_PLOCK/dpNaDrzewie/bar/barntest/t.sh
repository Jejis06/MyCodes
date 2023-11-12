for i in 1 2 3 4 5 6 7 8 9 10
do
	./.bar < $i.in > prog.out

	if diff -b prog.out $i.out
	then
		echo -ne "OK $i 	\r"
	else
		echo "BLAD $i"
		break
	fi

done
