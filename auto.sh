#!bin/bash

git add .vscode
git commit -m "C Exercise"
git push -u origin Test

for i in Icsd_Lab02/*
do
    git add "$i"
    git commit -m "C Exercise"
    git push -u origin Test
done

git add auto.sh
git commit -m "Automate shell script"
git push -u origin Test
