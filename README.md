Example usage:

`mkdir build && cd build`

`cmake ..`

`cmake --build . --target firmware`

`cmake --build . --target FilterData`

`./FilterData/FilterData fileName`

`./firmware/firmware fileName size algorithmType`

`fileName` - from this file program will read movies

`size` - size of data to read form file and sort

`algorithmType` - type of algorithm with which program will sort movies 
        available options: quicksort, mergesort, bucketsort

For full tests use bash script:

`./tests.sh`
