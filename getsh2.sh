#!/bin/bash
echo "Input target ID:"
read TAR
curl -s http://www.lydsy.com/JudgeOnline/userinfo.php?user=$TAR | egrep '[p();0-9]+</script>' | sed 's/);/ /g' | tr -d '(a-z</>' | sort >target.dat
echo "Input your ID:"
read MYSELF
curl -s http://www.lydsy.com/JudgeOnline/userinfo.php?user=$MYSELF | egrep '[p();0-9]+</script>' | sed 's/);/ /g' | tr -d '(a-z</>' | sort >myself.dat
./differ2

