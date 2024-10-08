#include<iostream>
using namespace std;
int main() {
    int x = 0;
    int y = 10;

    //addはキャプチャなし、引数あり
    auto add = [](int a, int b) {return a + b; };
//    auto nc = []() { cout << x << ", " << y << endl; }; //コンパイルエラー
    //ncはキャプチャなし、引数なし
    auto nc = []() { cout << "NotCapture" << endl; };
    //ccはxとyの値をコピーして取得
    auto cc = [=]() { cout << x << ", " << y << endl; };      // 全てをコピーキャプチャ
    //crはyの値は参照（アドレス）で取得,それ以外はコピー
    auto cr = [=, &y]() { cout << x << ", " << y << endl; };    // デフォルトコピー、yを参照キャプチャ
    //すべての変数を参照で取得
    auto rr = [&]() { cout << x << ", " << y << endl; };      // 全てを参照キャプチャ
 
    cout << "add(2,5)=" << add(2, 5) << endl;

    cout << "nc()" << endl;
    nc();
    x = 1;
    y = 11;
    cout << "cc()" << endl;
    cc();   //0,10　このときのxはccを定義したときのxとyの値がコピー
    cout << "cr()" << endl;
    cr();   //0,11  このときはxはcrを定義したときのx、yは参照なので更新された11となる
    cout << "rr()" << endl;
    rr();   //1,11  xとyともに参照なので最新のxとyの値が入る

    [&x]() { x += 1; }();          // 参照キャプチャは変数の変更が可能
    //上記の時点でxの値が+1されて2になる
    //[y](){ y+=1; }();         // Copyキャプチャは変数を変更不可能（Const)
    [y]() mutable { y += 1; }();   // mutableにすると変数の変更が可能（だがコピーなので元の変数は不変）
    //こちらのyは複製されたyを+1するが、元のyは変更されない
    rr();   //2,11

    return 0;
}