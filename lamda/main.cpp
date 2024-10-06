#include<iostream>
using namespace std;
int main() {
    int x = 0;
    int y = 10;

//    auto nc = []() { cout << x << ", " << y << endl; }; //コンパイルエラー
    auto nc = []() { cout << "NotCapture" << endl; };
    auto cc = [=]() { cout << x << ", " << y << endl; };      // 全てをコピーキャプチャ
    auto cr = [=, &y]() { cout << x << ", " << y << endl; };    // デフォルトコピー、yを参照キャプチャ
    auto rr = [&]() { cout << x << ", " << y << endl; };      // 全てを参照キャプチャ

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

    return 1;
}