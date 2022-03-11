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
./run.sh download_mtx_from_URL
```
<br>

[4] Run test program
本節ではtest programの実行方法およびtest programの並列実行方法について説明する。

4.1  
```
./run.sh spmv_sparse_real_all ./result/result.csv
```
4.2
```
./run.sh spmv_sparse_real_one ./result/result.csv ./data/reorientation_7/reorientation_7.mtx
```
4.3
```
./run.sh spmv_sparse_rand_all ./result/result.csv
```
4.4
```
./run.sh spmm_sparse_rand_all ./result/result.csv
```
4.5
```
./run.sh spmm_sparse_rand_one ./result/result.csv
```
4.6
```
./run.sh spmm_sparse_rand_irregular_size ./result/result.csv
```
4.6
```
./run.sh　all
```
4.6
```
./run.sh all_parallel
```




### 検証

<!-- - 翌日リリース予定のアイテム一覧を確認
- リストのアイテムをひとつずつ確認し、変更箇所をすべて検証

| テスト項目 | 結果 |
|---|---|
|ファイル生成 | [×] OK<br> [ ] NG|
|シェル起動| [ ] OK<br> [ ] NG| -->


不明点があれば、[sugahara.takuya.tech@gmail.com](sugahara.takuya.tech@gmail.com)へお問い合わせください。
