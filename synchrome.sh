#!/bin/bash

t=`date`

filelist='synchrome.sh line_table.cpp linked_table.cpp SqStack.cpp SString.cpp BiTree.cpp Graph.cpp line_table.h linked_table.h SqStack.h SString.h BiTree.h Graph.h
 Makefile README.md c_stl/run.sh c_stl/test2.cpp c_stl/demo_if_tree.cpp '

echo 'Trans the following Files to docker:ubt_linux && 39.107.229.211 :'

log_path="synchrome.log"

tmp_path="tmp_newlog.log"

touch $tmp_path

if [[ ! -f "$testFile" ]]; then

echo "create log file：$log_path" >> $tmp_path

touch $log_path

fi

echo $t >> $tmp_path

for file in $filelist
do
	echo 'please wait...'
	git add $file >> $tmp_path
	docker cp ./$file ubt_linux:/home/piglaker/c_pck/$file >> $tmp_path
	sshpass -p ZYX1999zyx scp ./$file root@39.107.229.211:/home/zxt/c_prac/$file >> $tmp_path
	echo $file >> $tmp_path
done

echo 'push to github' >> $tmp_path

git commit -m "$t" >> $tmp_path

git push -u origin master >> $tmp_path

echo 'done' >> $tmp_path

echo '-----------------------------------------------' >> $tmp_path

cat $tmp_path

cat $tmp_path >> $log_path

rm $tmp_path

