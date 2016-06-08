今はKawigiEditじゃないとだめ。
Enable to add test cases from arena!!

Add ボタンを押下し、以下の設定を入力
Name: KawigiEdit
EntryPoint: kawigi.KawigiEdit
ClassPath: ダウンロードした jar ファイルのパス
好みに応じて Default, At Startup のチェックを付けて Save

Editor Preferences の画面で KawigiEdit を選択し Configure ボタンを押下
General/Testing
作業ディレクトリの指定
IDEを使ってコードを書く場合には、そのソースディレクトリを指定するとよい。
Synchronization with external file
外部ファイルとの連携。チェックONにする。
Always prefer external file to TC source
外部ファイルを優先ソースとする。チェックONに。
Save problem statement to external file
外部ファイルにコメントとして問題文を記述。チェックONに。
Languages C++ ComplileCommandに-std=c++11をつける
Use c++11 feature in tester codeにチェック

Temeplate->Open->testprogram/myc++.ket
save ->cpp.ketに上書き
もしそれでテンプレートが変わっていないように見えたら、Generate Codeボタンを押す








以下過去の情報。
Greedはエラーはくし、
CodeProcessorはテストケース作ってくれないので、topcoderアリーナはクソ

# topcoder
Competition Arenaの「Options → Editor」で「Editor Preferences」を開く

Common ClassPathにBrowseボタンでTZTester.jar, FileEdit.jarを追加

Addボタンを押して以下のように入力してOKを押す
Name: CodeProcessor
EntryPoint: codeprocessor.EntryPoint
ClassPath: CodeProcessor.jarのパス

CodeProcessorを選択し、Configureを押して「CodeProcessor Configuration」を開く

「Editor EntryPoint」にfileedit.EntryPointと入力してConfigureを押す

「General」タブで「Enter directory to read/write problems to」にソースを置きたいディレクトリを記入
Saveボタンを押したら今度は「Processor Class」に「tangentz.TZTester」と
記入して「Verify」を押す。3つのメソッドについて「found」と出たらOK。
だめだったらCompetition Arenaを再起動してからチェック。

