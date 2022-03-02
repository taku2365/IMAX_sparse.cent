
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
    sotre_name="$3"
elif [ $# -eq 2 ]; then
    csv_name="$2"
    data_name='./data/reorientation_7/reorientation_7.mtx'
elif [ $# -eq 1 ]; then
    csv_name='./result/result.csv'
    data_name='./data/reorientation_7/reorientation_7.mtx'
else
echo 'This pattern does not exist'
fi


if [ "$1" = "spmv_sparse_all" ]; then
    eval "./${base_dir}/test_chipA_spmv_multi_real_data_test${tail_name} ${csv_name}"
    #最後のdata名を名前のみ抽出
    sed -i -e  's@\./.*/@@g' -e 's@\.mtx$@@g' ${csv_name}
    # ex ./run.sh spmv_sparse_all ./result/result_spmv_real_data_dense_ver.csv
    # ex ./run.sh spmv_sparse_all ./result/result_spmv_real_data_sparse_ver.csv
elif [ "$1" = "spmv_sparse_one" ]; then
    eval "./${base_dir}/test_chipA_spmv_real_data_test${tail_name} ${csv_name} ${data_name}"
    #最後のdata名を名前のみ抽出
    sed -i -e  's@\./.*/@@g' -e 's@\.mtx$@@g' ${csv_name}
fi



# -regextype posix-basicでgrepと同じ正規表現  拡張正規表現ならposix-egrep　!で否定
# 末尾がgz以外削除
# find ./* -type d -regextype posix-basic !  -regex ".*\.gz$"| xargs rm -ir 
# 展開
# find ./* -type f -regextype posix-basic   -regex ".*\.gz$" | xargs -n 1 tar zxvf elif [ "$1" = "spmv_sparse_one" ]; then


#     eval "./${base_dir}/test_chipA_spmv_multi_real_data_test${tail_name} ${csv_name} &"
#     pid1=$!
#     echo "aaaaaaaaaaaaaaaaa"
#     eval "./${base_dir}/test_chipA_spmv_real_data_test${tail_name} ${csv_name} ${data_name} &"
#     echo "bbbbbbbbbbbbbbbbbb"
#     pid2=$!
#     #最後のdata名を名前のみ抽出
#     sed -i -e  's@\./.*/@@g' -e 's@\.mtx$@@g' ${csv_name}

# fi

# wait $pid1
# result1=$?

# wait $pid2
# result2=$?
# if [ $result1 -eq 0 ] && [ $result2 -eq 0 ] 
# then
#    echo "success"
#    exit 0
# else
#    echo "fail"
#    exit 6
# fi