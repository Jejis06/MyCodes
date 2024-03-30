echo ""
for ((i=1; i>0; i++))
do
	echo $i > ziarno

	./gen < ziarno > t.in
	./wzor < t.in > w.out
	./brut < t.in > b.out

	if diff w.out b.out > testDiff
	then
		echo -e "\e[1A\e[Ktest $i OK";
	else
		echo -e "test $i ZLE";
		break;
	fi
done
