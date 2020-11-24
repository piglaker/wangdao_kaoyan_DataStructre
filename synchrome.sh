#!/bin/bash

t=`date`

filelist='line_table.cpp linked_table.cpp SqStack.cpp SString.cpp BiTree.cpp Graph.cpp Sort.cpp line_table.h linked_table.h SqStack.h SString.h BiTree.h Graph.h Sort.h Makefile README.md c_stl/run.sh c_stl/test2.cpp c_stl/demo_if_tree.cpp b-tree.cpp '

echo 'Trans the following Files to docker:ubt_linux && 39.107.229.211 :'

log_path="synchrome.log"

tmp_path="tmp_newlog.log"

touch $tmp_path

if [[ ! -f "$testFile" ]]; then
echo "Create log file：$log_path" >> $tmp_path
touch $log_path
fi

echo $t >> $tmp_path

docker_ready=1

if ! docker info >/dev/null 2>&1;then
	echo "Docker Daemon is not RUNNING ..."
	docker_ready=0
else
	echo "Docker Daemon RUNNING ..."
fi



for file in $filelist
do
	echo 'Please Wait...'
	git add $file >> $tmp_path
	if [ $docker_ready == 1 ];then
		docker cp ./$file ubt_linux:/home/piglaker/c_pck/$file >> $tmp_path
	fi
	sshpass -p ZYX1999zyx scp ./$file root@39.107.229.211:/home/zxt/c_prac/$file >> $tmp_path
	echo $file >> $tmp_path
done

echo 'Push to github ...' >> $tmp_path

git commit -m "$t" >> $tmp_path

git push -u origin master >> $tmp_path

echo 'Done !' >> $tmp_path

echo '-----------------------------------------------' >> $tmp_path

cat $tmp_path

cat $tmp_path >> $log_path

rm $tmp_path

