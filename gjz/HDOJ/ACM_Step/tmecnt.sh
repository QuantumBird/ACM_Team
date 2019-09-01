start_time=`date +'%Y-%m-%d %H:%M:%S'`
./a.out
end_time=`date +'%Y-%m-%d %H:%M:%S'`
start_sec=$(date --date="$start_time" +%s);
end_sec=$(date --date="$end_time" +%s);
echo "running time: "$((end_sec - start_sec))"s"

