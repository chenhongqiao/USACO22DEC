#!/bin/zsh

name=($1)
div=($2)
prob_name=($3)

if [ -z $name ] || [ -z $div ] || [ -z $prob_name ]
then
	echo "Error: not all parameters are supplied."
	exit -1
fi
	

if [ ! -d $div/$name ] 
then
	mkdir -p $div/$name
	src_path=($div/$name/$name.cpp)
	touch $src_path
	code $src_path
	echo "// $prob_name" > $src_path
	echo "Solution folder created."
else
	echo "Error: problem exists."
fi