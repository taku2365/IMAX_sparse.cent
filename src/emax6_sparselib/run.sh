
# tail -n +2 filename.csv

# if [ "$1" = "arch_cross" ]; then
#     make ARM_CROSS=1
#     exit
# fi


arch_name=$(arch)
if [ $arch_name = "aarch64" ]; then
    base_dir="build_arm"
    tail_name="+dma"
elif [ $arch_name = "x86_64" ]; then
    base_dir="build_cent"
    tail_name=""
fi


if [ $# -eq 0 ]; then
echo 'You need to specify arguments'
fi

if [ $# -eq 3 ]; then
    csv_name="$2"
    data_name="$3"
elif [ $# -eq 2 ]; then
    csv_name="$2"
    data_name='./data/reorientation_7/reorientation_7.mtx'
elif [ $# -eq 1 ]; then
    csv_name='./result/result.csv'
    data_name='./data/reorientation_7/reorientation_7.mtx'
else
echo 'This pattern does not exist'
fi


if [ "$1" = "all_parallel" ] && [ $arch_name = "aarch64" ]; then
    echo "This pattern does not support"
    exit
fi


###################### run program #############################################################
if [ "$1" = "spmv_sparse_real_all" ]; then
    eval "./${base_dir}/test_chipA_spmv_multi_real_data_test${tail_name} ${csv_name}"
    #最後のdata名を名前のみ抽出
    sed -i -e  's@\./.*/@@g' -e 's@\.mtx$@@g' ${csv_name}
    # ex ./run.sh spmv_sparse_real_all ./result/result.csv

elif [ "$1" = "spmv_sparse_real_one" ]; then
    eval "./${base_dir}/test_chipA_spmv_real_data_test${tail_name} ${csv_name} ${data_name}"
    sed -i -e  's@\./.*/@@g' -e 's@\.mtx$@@g' ${csv_name}
    # ex ./run.sh spmv_sparse_real_one ./result/result.csv ./data/reorientation_7/reorientation_7.mtx

elif [ "$1" = "spmv_sparse_rand_all" ]; then
    eval "./${base_dir}/test_chipA_spmv_size_test${tail_name} ${csv_name} "
    sed -i -e  's@\./.*/@@g' -e 's@\.mtx$@@g' ${csv_name}
    # ex ./run.sh spmv_sparse_rand_all ./result/result.csv

elif [ "$1" = "spmm_sparse_rand_all" ]; then
    eval "./${base_dir}/test_chipB_div_size_test${tail_name} ${csv_name} "
    # ex ./run.sh spmm_sparse_rand_all ./result/result.csv

elif [ "$1" = "spmm_sparse_rand_one" ]; then
    eval "./${base_dir}/test_chipB_div_one${tail_name} ${csv_name} "
    # ex ./run.sh spmm_sparse_rand_one ./result/result.csv

elif [ "$1" = "spmm_sparse_rand_irregular_size" ]; then
    eval "./${base_dir}/test_chipB_div_Acol_Brow_size_test${tail_name} ${csv_name} "
    # ex ./run.sh spmm_sparse_rand_irregular_size ./result/result.csv

elif [ "$1" = "all" ]; then
    start_time=$(date +s%)
    eval "./${base_dir}/test_chipA_spmv_multi_real_data_test${tail_name} ${csv_name} " 
    result1=$?
    eval "./${base_dir}/test_chipA_spmv_real_data_test${tail_name} ${csv_name} ${data_name} "
    result2=$?
    eval "./${base_dir}/test_chipA_spmv_size_test${tail_name} ${csv_name} "
    result3=$?
    eval "./${base_dir}/test_chipB_div_size_test${tail_name} ${csv_name} "
    result4=$?
    eval "./${base_dir}/test_chipB_div_one${tail_name} ${csv_name} "
    result5=$?
    eval "./${base_dir}/test_chipB_div_Acol_Brow_size_test${tail_name} ${csv_name} "
    result6=$?

    if [ $result1 -eq 0 ] && [ $result2 -eq 0 ] && [ $result3 -eq 0 ] \
       && [ $result4 -eq 0 ] && [ $result5 -eq 0 ] && [ $result6 -eq 0 ]\
       ; then
        echo "success"
        echo "spmv_sparse_all ${result1} spmv_sparse_one ${result2}  
              spmv_sparse_rand ${result3} spmm_sparse_rand_all ${result4} 
              spmm_sparse_rand_one ${result5} spmm_sparse_rand_irregular_size ${result6}
              "
    else
        echo "fail"
        echo "spmv_sparse_all ${result1} spmv_sparse_one ${result2}  
              spmv_sparse_rand ${result3} spmm_sparse_rand_all ${result4} 
              spmm_sparse_rand_one ${result5} spmm_sparse_rand_irregular_size ${result6}
              "
    fi
    end_time=$(date +%s)
    run_time=$((end_time - start_time))
    echo $run_time

elif [ "$1" = "all_parallel" ]; then
    start_time=$(date +%s)
    eval "./${base_dir}/test_chipA_spmv_multi_real_data_test${tail_name} ${csv_name} &" 
    pid1=$!
    eval "./${base_dir}/test_chipA_spmv_real_data_test${tail_name} ${csv_name} ${data_name} &"
    pid2=$!
    eval "./${base_dir}/test_chipA_spmv_size_test${tail_name} ${csv_name} &"
    pid3=$!
    eval "./${base_dir}/test_chipB_div_size_test${tail_name} ${csv_name} "
    pid4=$!
    eval "./${base_dir}/test_chipB_div_one${tail_name} ${csv_name} "
    pid5=$!
    eval "./${base_dir}/test_chipB_div_Acol_Brow_size_test${tail_name} ${csv_name} "
    pid6=$!
    wait $pid1
    result1=$?
    wait $pid2
    result2=$?
    wait $pid3
    result3=$?
    wait $pid4
    result4=$?
    wait $pid5
    result5=$?
    wait $pid6
    result6=$?
    if [ $result1 -eq 0 ] && [ $result2 -eq 0 ] && [ $result3 -eq 0 ] \
       && [ $result4 -eq 0 ] && [ $result5 -eq 0 ] && [ $result6 -eq 0 ]\
       ; then
        echo "success"
        echo "spmv_sparse_all ${result1} spmv_sparse_one ${result2}  
              spmv_sparse_rand ${result3} spmm_sparse_rand_all ${result4} 
              spmm_sparse_rand_one ${result5} spmm_sparse_rand_irregular_size ${result6}
              "
    else
        echo "fail"
        echo "spmv_sparse_all ${result1} spmv_sparse_one ${result2}  
              spmv_sparse_rand ${result3} spmm_sparse_rand_all ${result4} 
              spmm_sparse_rand_one ${result5} spmm_sparse_rand_irregular_size ${result6}
              "
    fi
    end_time=$(date +%s)
    run_time=$((end_time - start_time))
    echo $run_time
fi

# -regextype posix-basicでgrepと同じ正規表現  拡張正規表現ならposix-egrep　!で否定
# 末尾がgz以外削除
# find ./* -type d -regextype posix-basic !  -regex ".*\.gz$"| xargs rm -ir 
# 展開
# find ./* -type f -regextype posix-basic   -regex ".*\.gz$" | xargs -n 1 tar zxvf elif [ "$1" = "spmv_sparse_one" ]; then