#!/bin/bash
echo -n > /projects/os_lab_2019/lab1/src/numbers.txt 
for i in {1..150};
do 
echo "$(od -vAn -N1 -tu1 /dev/random)" >> /projects/os_lab_2019/lab1/src/numbers.txt
done