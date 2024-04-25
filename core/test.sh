#!/usr/bin/env bash

counter=1

while [[ 1 ]]; do
    echo `expr $counter % 2` | ./a.out
    counter=`expr $counter + 1`
done

