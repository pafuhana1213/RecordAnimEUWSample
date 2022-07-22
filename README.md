# RecordAnimEUWSample
![image](https://user-images.githubusercontent.com/8957600/180386310-9328030a-abcb-4848-b8d0-c6ff3fa486d1.png)
UE標準のアニメーション録画機能であるAnimation Recorderを直接呼び出すことで、自分好みのアニメーション録画ツールを作るというサンプルです。

Take Recorder、Sequence Recorderなどアニメーションを録画するためのツールが標準でありますが、プロジェクトにあった形にカスタムしたり自動化するにはエンジン改造が必要になり少しハードルが高いです。
一方、Animation Recorderを直接呼び出せばプロジェクト側のBP・C++コードだけでオレオレアニメーション録画ツールを作ることができるはず…と思って作ってみました。

このサンプルではSequenerに対して再生処理を行ったり、LevelSequenceの内部データを元に処理を変更したりなども行っています。そのため、EditorUtility機能を使ってSequencer周りを便利に・自動化したいと考えている人にも多分参考になると思います。

こういったツールはプロジェクト毎にカスタムするものだと思うので、機能要望は基本的には受け付けていません。  
このサンプルが少しでも参考になれば幸いです。

Animation Recorderについて：  
https://qiita.com/EGJ-Kaz_Okada/items/7f91099e72f64c6c6285

## 使い方
1. Contents/RecordAnimEUWSample/EUW_SimpleRecordAnimation を右クリックメニューのRun～から開く
2. 録画したいLevel SequenceアセットをTarget Level Sequence に設定
3. Openボタンを押して2で設定したLevelSequenceを開く（既に開いていたらこの操作はスキップ可）
4. 録画対象のActorにBinding Tag Nameと同じ名前のTagを設定する。  
Binding Tagの設定方法：https://docs.unrealengine.com/5.0/ja/cinematic-tags-and-groups-in-unreal-engine/
5. Output Folder Path に録画結果を出力するフォルダを、Output Asset Name Base にはアセット名を設定

記入中


## 動作環境
UE5.0.3以上

## ライセンス
MIT

## 作者
[おかず@pafuhana1213](https://twitter.com/pafuhana1213)
