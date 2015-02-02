#!/bin/bash

filenames=`ls ./`

for filename in $filenames
do
	echo "<file>images/$filename</file>" >> temp.qrc
done
