g++ zap.cpp -o zap
g++ chk.cpp -o chk
Folder="testy";
Plik="zap";
for ((i=1; i <=10000;i++))   
do
    cp $Folder/$Plik$i.in test.in
    cp $Folder/$Plik$i.out test.out
    ./zap < test.in > testb.out
    ./chk > OK.txt
    if diff -b OK.txt OK2.txt
    then
        echo -ne "Test $i OK \r";
    else
        echo -ne "Test $i ZLE!!!!";
        exit 0; 
    fi
done
