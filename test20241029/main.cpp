#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
	string line;
	getline(cin, line);
	cout << "Hello " << line << "!" << endl;
	return 0;
}
/*
標準入力から入力される文字列を格納するstring型変数lineを宣言。
getline関数により、標準入力からlineへ文字列を格納。
coutにより、"Hello"の後に、lineに格納された文字列に"!"を付加して表示。
*/