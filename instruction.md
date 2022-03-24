<aside>
βver
</aside>


# IMAX Sparse lib 実施手順書
 この手順書は最低限の実行手順を記したものである。

## 手順

実行の際に必要なコマンドをrun.shに記した

[0]Install source code to an arbitrary path
本節ではsource codeを任意のpathへコピーする方法を示す。
git hubに公開できた際はgit cloneでの方法も記す予定。

```
cp -r /home/takuya-s/IMAX_sparse.cent/src/emax6_sparselib "your path"
```
<br>

[1] Build
本節ではlibrayをbuildする方法を説明する。
zynqとcent osでは内部で切り替えるように作ったので、optionを付ける必要がない。
build directoryを分けることで実機を変えるたびに再コンパイルするコストを減らしている。
ただしcsimをbuildするときのみoptionが必要

[1.1] Build zynq or cent 
```
./run.sh build
```
[1.2] Build csim
```
./run.sh build ARM_CROSS=1
```
<br>

[2] Install a library to an arbitrary path
本節では任意のpathへlibraryをinstallする方法を説明する。
```
./run.sh install 
```
<br>

[3] Download and Unpack mtx file
本節ではmtx fileを[https://sparse.tamu.edu/](https://sparse.tamu.edu/)からダウンロードをして、解凍する方法を説明する。
```
./run.sh download_mtx_from_URL URL
```
<br>

[4] Run test program
本節ではtest programの実行方法およびtest programの並列実行方法について説明する。

4.1  複数のReal Dataで疎行列ベクトル積のテスト
```
./run.sh spmv_sparse_real_all ./result/result.csv
```
4.2 単体のReal Dataで疎行列ベクトル積のテスト
```
./run.sh spmv_sparse_real_one ./result/result.csv ./data/reorientation_7/reorientation_7.mtx
```
4.3　複数の人工データで疎行列ベクトル積のテスト
```
./run.sh spmv_sparse_rand_all ./result/result.csv
```
4.4　複数の人工データで疎行列積のテスト
```
./run.sh spmm_sparse_rand_all ./result/result.csv
```
4.5　単体の人工データで疎行列積のテスト
```
./run.sh spmm_sparse_rand_one ./result/result.csv
```
4.6　形が不均衡な行列で疎行列積テスト
```
./run.sh spmm_sparse_rand_irregular_size ./result/result.csv
```
4.7　すべてのパターンをテスト
```
./run.sh　all
```
4.8　すべてのパターンを並列実行
```
./run.sh all_parallel
```


### プログラムの説明
本節では、実行するための関数やパラメータの説明を行う。

src/emax6_sparselib/Include/emax6_sparselib.h
emax6_paramの説明
IMAXを実行するためのパラメータを格納している
```
typedef struct {
    Uint mode;    
    Uint data_format; 
    Uint data_type; 
    size_t H_param;
    size_t W_param;
    size_t A_col_blk_param     ;
    size_t A_row_blk_param     ;
    size_t B_col_blk_param     ;
    size_t B_row_blk_param     ;
    size_t C_col_blk_param     ;
    size_t C_row_blk_param     ;
    size_t NCHIP_param         ;
    size_t A_row_size_param    ;
    size_t A_col_size_param    ;
    size_t B_row_size_param    ;
    size_t B_col_size_param    ;
    size_t A_row_size_pad_param;
    size_t A_col_size_pad_param;
    size_t B_row_size_pad_param;
    size_t B_col_size_pad_param;
    int nnz                 ;  
    size_t col_max; //1行あたりのnnzの最大数 
    A_blk_set* A_blk_sets   ;
    B_blk_set* B_blk_sets   ;
    MM_typecode matcode     ;
    float sparsity          ;
    float LMM_usage_A_kbyte ;
    float LMM_usage_A_rate  ;
    float LMM_usage_B_kbyte ;
    float LMM_usage_B_rate  ;
    float LMM_usage_kbyte   ;
    float LMM_usage_rate    ;    
} emax6_param;
```

modeの説明
```
DENSE_DENSE_MODE 密行列積
DENSE_SPMV_MODE 密行列ベクトル積 
SPARSE_DENSE_46_MODE ×
SPARSE_DENSE_58_VER2_MODE 疎行列積
SPARSE_DENSE_58_VER3_MODE ×
SPARSE_DENSE_58_SPMV_MODE 疎行列ベクトル積
```

data_formatの説明
```
DENSE_DENSE_FORMAT -> 密行列積 format
DENSE_DENSE_SPMV_FORMAT -> 密行列ベクトル積 format
CSR_INDEX_VAL_SET_FORMAT -> CSR 疎行列積 format
JDS_INDEX_SEPARATE_FORMAT -> JDS indexとvalueを別々に格納 疎行列積 format
JDS_INDEX_VAL_SET_FORMAT   -> JDS indexとvalueをsetで格納 疎行列積 format
CSR_INDEX_VAL_SET_SPMV_FORMAT  -> CSR 疎行列ベクトル積 format
JDS_INDEX_VAL_SET_SPMV_FORMAT -> JDS indexとvalueをsetで格納 疎行 ベクトル　format
```

data_typeの説明
```
DENSE_TYPE  人工密行列
DENSE_SPMV_TYPE 人工密行列 
SPARSE_TYPE 人工疎行列
BIASED_SPARSE_TYPE データに偏りのある疎行列
SPARSE_SPMV_TYPE 人工疎行列(疎行列ベクトル積の時に使用)
REAL_DATA_TYPE 疎行列　Real data(疎行列積は非対応) 
```

init_paramの説明
memoryを確保して、membaseやmemsize、fpからの情報などを格納している
get_size()で使用する
```
typedef struct {
    Uint mode; //データの取得方法
    size_t init_allocate_mat_len; //確保したい初期の行列サイズ
    size_t memsize; //確保するメモリのサイズ
    Uchar* membase; //確保した先頭アドレス
    FILE* fp;
} init_param;
```

初期パラメータを取得する関数
```
void get_param(emax6_param* params,init_param* init_param);
```

IMAXのパラメータを自動チューニングする関数
```
void IMAX_param_tunig(emax6_param* params);
```

行列を所定のformatに変換して格納する関数
関数が汚くなっているので要リファクタリング
```
emax6_sparse2* sparse_format(int nnz,Ull* val,Uint* val_tmp, const int* const col_index, const int* const row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);

```

疎行列積を計算する関数
```
void sparse_gemm_CHIP_div_B(  Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);

```

疎行列ベクトル積を計算する関数
```
void sparse_spmv_CHIP_div_A(  Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);

```

### 検証

<!-- - 翌日リリース予定のアイテム一覧を確認
- リストのアイテムをひとつずつ確認し、変更箇所をすべて検証

| テスト項目 | 結果 |
|---|---|
|ファイル生成 | [×] OK<br> [ ] NG|
|シェル起動| [ ] OK<br> [ ] NG| -->


不明点があれば、[sugahara.takuya.tech@gmail.com](sugahara.takuya.tech@gmail.com)へお問い合わせください。
