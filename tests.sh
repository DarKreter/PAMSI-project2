#/bin/bash

mkdir -p build && cd build
cmake ..
cd ..
cmake --build build --target FilterData
cmake --build build --target firmware

echo "Filtering started!"
./build/FilterData/FilterData data/dane_original.csv
echo "Filtering finished!"



for sortAlg in "quicksort" "bucketsort" "mergesort"
do
    touch "result_$sortAlg.csv"
    echo "size,time,mean,middle value" > "result_$sortAlg.csv"
    echo "Start $sortAlg!"

    for i in {100..1000..100}
    do
        echo -n "$i," >> "result_$sortAlg.csv"
        ./build/firmware/firmware  data/dane_original_mod.csv $i $sortAlg >> "result_$sortAlg.csv"
        echo "$i - DONE"
    done

    # for i in {10000..1000000..10000}
    # do
    #     echo -n "$i," >> "result_$sortAlg.csv"
    #     ./build/firmware/firmware  data/dane_original_mod.csv $i $sortAlg >> "result_$sortAlg.csv"
    #     echo "$i - DONE"
    # done


    for i in {10000..100000..10000}
    do
        echo -n "$i," >> "result_$sortAlg.csv"
        ./build/firmware/firmware  data/dane_original_mod.csv $i $sortAlg >> "result_$sortAlg.csv"
        echo "$i - DONE"
    done

    for i in {200000..1000000..100000}
    do
        echo -n "$i," >> "result_$sortAlg.csv"
        ./build/firmware/firmware  data/dane_original_mod.csv $i $sortAlg >> "result_$sortAlg.csv"
        echo "$i - DONE"
    done

    echo "Finished $sortAlg!"
done