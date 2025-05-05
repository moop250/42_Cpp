#!/bin/bash

make

# Check if PmergeMe exists and is executable
if ! [ -x "./PmergeMe" ]; then
    echo "Error: ./PmergeMe does not exist or is not executable."
    exit 1
fi

./PmergeMe 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 | grep Time && echo ""

./PmergeMe 2 11 0 17 6 15 8 16 3 10 1 21 9 18 14 19 5 12 4 20 7 13 | grep Time && echo ""

./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\n' ' ') | grep Time && echo ""