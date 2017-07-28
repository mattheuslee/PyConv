#!/usr/bin/env bash
while read line;
    do
        gcov $line > gcovlog.txt
    done < ./filenames.txt
