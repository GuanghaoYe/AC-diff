#!/bin/bash
id=$1
curl http://www.lydsy.com/JudgeOnline/userinfo.php?user=$id | egrep '[p();0-9]+</script>' | sed 's/);/ /g' | tr -d '(a-z</>' | sort >target.dat

