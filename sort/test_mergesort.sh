#!/bin/bash

# Testing Merge Sort

for a in `seq 10000 10000 990000`
do
    echo -n .
    value="$(./merge $a | cut -d: -f2)"
    values="$values $value"
done

# bloat the values because spark seems to hate small numbers
for b in $values
do
    tmp=0`echo "$b*10" | bc`
    bloated_values="$bloated_values $tmp"
done

spark $bloated_values
