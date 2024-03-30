for ((i=1; i>0; i++))
do
	echo $i > seed
	./gen < seed > t.in
	./brut < t.in > b.out
	./wzor < t.in > w.out

	if diff w.out b.out > conflict
	then	
		echo "$i OK";
	else
		echo "$i WRONG";
		break;
	fi
done

