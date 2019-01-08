#!/bin/bash
for file in *; do
	read -n 1 -p "Proceed to next file? "
	echo "\nContent of the test file ${file}"
	cat ${file}
	echo "Result of the fillit program"
	./../src/fillit ${file}
	echo ""
done
