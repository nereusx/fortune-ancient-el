#!/bin/sh

# find suitable directory
DIR=/usr/local/share/fortunes
for e in \
	/usr/local/share/fortunes \
	/usr/share/fortunes \
	/usr/share/games/fortunes \
	/usr/local/share/games/fortunes	\
	; do
	if [ -d "$e" ]; then
		DIR="$e"
		break
	fi
done

# copy
cp diogenis.txt ${DIR}/diogenis

# create fortune's .dat file
strfile ${DIR}/diogenis

# test
echo testing...
fortune diogenis
	
echo "Run 'fortune diogenis' for more famous quotes"
echo '* done *'
