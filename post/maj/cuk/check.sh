DIR="$(cd "$(dirname "$0")" && pwd)"
g++ cuk.cpp -o wzor 
for ((i=1; i>0; i++))
do
	./wzor < $DIR/in/cuk$i.in > w.out
	if diff w.out $DIR/out/cuk$i.out > confl
	then
		echo "$i OK";
	else
		echo "$i WRONG";
		break;
	fi
done

