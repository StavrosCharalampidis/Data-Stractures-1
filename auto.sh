#!bin/bash

for i in {2..10}
do
    echo "output: $i"
done

git add Icsd_Lab02/*
git commit -m "C Exercise"
git push -u origin Test

git add auto.sh
git commit -m "Automate shell script"
git push -u origin Test

git add .
git commit -m "extesion"

git push -u origin Test