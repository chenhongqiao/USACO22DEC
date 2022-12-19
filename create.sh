#!/bin/zsh

name=($1)
prob_name=($2)

if [ -z $name ] || [ -z $prob_name ]
then
	echo "Error: not all parameters are supplied."
	exit -1
fi
	

if [ ! -d $name ] 
then
	mkdir -p $name
	src_path=($name/$name.cpp)
	touch $src_path
	code $src_path
	echo "// $prob_name" > $src_path
	echo "Solution folder created."
else
	echo "Error: problem exists."
fi