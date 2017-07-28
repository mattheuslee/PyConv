#!/usr/bin/env bash
cd ./gcov_folder
while read line;
    do
        gcov $line > gcovlog.txt
    done < ./filenames.txt
