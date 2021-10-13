#!/bin/bash
h=0
l=0
t=${1:-0.05}
clear
while IFS= read -r line; do
    for (( i=0 ; i<${#line} ; i++)); do
            echo -n "$i $h ${line:i:1}"
            echo
    done
    let h++
done | shuf | 
while read -r x y symbol; do
            tput cup $y $x
	        echo -n $symbol
	        sleep $t
            l=$(( y > l ? y : l ))
            tput cup $l 0
done
echo
