#!/bin/bash
for filename in `find . | egrep '\.cpp'`; 
do 
  gcov -n -o . $filename > /dev/null; 
done
for filename in `find . | egrep '\.c'`; 
do 
  gcov -n -o . $filename > /dev/null; 
done
