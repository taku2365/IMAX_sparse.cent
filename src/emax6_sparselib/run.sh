
# tail -n +2 filename.csv

# if [ "$1" = "arch_cross" ]; then
#     make ARM_CROSS=1
#     exit
# fi


arch_name=$(arch)
if [ $arch_name = "aarch64" ]; then
    base_dir="build_arm"
    tail_name="+dma"
elif [ $arch_name = "x86_64"]; then
    base_dir="build_cent"
    tail_name=""
fi


if [ $# -eq 0 ]; then
echo 'You need to specify arguments'
fi

if [ "$1" = "spmv_sparse_all" ]; then
    if [ $# -eq 2 ]; then
        csv_name="$2"
    elif [ $# -eq 1 ]; then
        # csv_name='./result/result.csv'
        csv_name='./result/result_spmv_real_data_sparse_ver.csv'
    else
    echo 'This pattern does not exist'
    fi
    eval "./${base_dir}/test_chipA_spmv_multi_real_data_test${tail_name}" ${csv_name}
    ##最後のdata名を名前のみ抽出
    sed -i 's@\./.*/@@g' ${csv_name}

fi