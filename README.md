# RecordAnimEUWSample
![image](https://user-images.githubusercontent.com/8957600/180386310-9328030a-abcb-4848-b8d0-c6ff3fa486d1.png)

<blockquote class="twitter-tweet"><p lang="ja" dir="ltr">以前にツイートした、自作アニメーション録画ツールをサンプルとしてGithubに公開しました！<a href="https://t.co/lZLCMN1jq3">https://t.co/lZLCMN1jq3</a><br><br>たぶん映像系のプロジェクトで役に立つ気がします。あと、EditorUtility機能を使ってSequencer作業を楽したい人にも参考になると思います。詳細はGithubのページで<a href="https://twitter.com/hashtag/UE5?src=hash&amp;ref_src=twsrc%5Etfw">#UE5</a> <a href="https://twitter.com/hashtag/UE5Study?src=hash&amp;ref_src=twsrc%5Etfw">#UE5Study</a> <a href="https://t.co/fhnf33ccDJ">https://t.co/fhnf33ccDJ</a> <a href="https://t.co/ANDIEyPMfX">pic.twitter.com/ANDIEyPMfX</a></p>&mdash; おかず (@pafuhana1213) <a href="https://twitter.com/pafuhana1213/status/1550395383146094593?ref_src=twsrc%5Etfw">July 22, 2022</a></blockquote> 

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
6. Recordボタンを押し、Sequencerの再生とアニメーション録画を開始
7. 再生し終わると指定の場所に録画アニメーションアセットを保存

## 制限・注意
サンプル内にあるLevelSequenceのように、単独のLevelSequenceかShotTrackを複数持つLevelSequenceのみを想定しています。そのため、ShotTrackではなくSubSceneTrackで分けている場合は正常に動作しません。もしSubSceneも考慮したい場合はEUWのCollect Shot Track Infosをカスタムしてください。

複数のSkeletalMeshを同時に録画するのは試していませんが、多分うまくいきません。もし実現したい場合はCollect Record Targetをカスタムしてください

ShotTrackごとに録画・出力を行うため、「複数のShotTrackがあっても録画結果は1アセットにしたい」ということはできません。もし実現したい場合は、Collect Shot Track Infosにおける録画時間の設定処理やCheck Finish Record周りをいじればできるはずです。たぶん


## おまけ
残念ながら、C++側で実装したUEditorUtilityWidgetの派生クラスはEditorUtilityWidgetアセットのClassSettingsの候補に出てきません。そのため、親クラスを自作のクラスに変えれません。こまった  
![image](https://user-images.githubusercontent.com/8957600/180393828-5ae76ea8-13ee-4ea3-9e98-ab9fa66e181a.png)

ただ、EditorUtility系で使えるReparent Blueprintノードを使えば無理やり親クラスを変更できます。EUB_ReparentEUWClassアセットを見てください。  
![image](https://user-images.githubusercontent.com/8957600/180394293-c4efd1ec-56cd-4fa5-bec5-0629eda05cce.png)


## 動作環境
UE5.0.3以上

## ライセンス
MIT

## 作者
[おかず@pafuhana1213](https://twitter.com/pafuhana1213)
