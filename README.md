# Competitive programming template

## 必要なものは以下の通りです

- clang (コンパイル用)
- make (makeでほげほげ)
- xclip or pbcopy (コピペ用)

## 使い方

| コード | 何が起こるか |
| --- | --- |
| make | build/に実行ファイルをコンパイルします |
| make run | makeの後実行ファイルを実行します |
| make cp | pbcopyかxclipを用いてコードをコピーします。Makefileのコメントアウトが必要です |
| make clean | build/*を削除します |
| make check | ファイル&フォルダにエラーが無いか確かめます |