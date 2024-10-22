/*
vectorに構造体を格納して、特定のメンバの値を使ってソートを行うサンプル
*/

#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

typedef struct {
	int a, b, c;
} Item;

struct CompItem { // 大小比較用の関数オブジェクトを定義する
	bool operator()(const Item& item1, const Item& item2) const noexcept {
		// キーとして比較したい要素を列挙する(今回はcメンバのみの大小比較)
		return std::tie(item1.c) < std::tie(item2.c);
	}
};

int main() {
	vector<Item> vec{ {11,9,8},{8,10,12},{20,5,1},{10,2,3} };
//	sort(vec.begin(), vec.end(), CompItem{});
	//第三引数に比較関数（ラムダ式）を記述して、昇順降順を切り替え
	//今回はcメンバのみの大小比較
	sort(vec.begin(), vec.end(), 
		[](const Item& it1, const Item& it2) { return it1.c > it2.c; }
	);
	for (Item it : vec) {
		cout << it.a << " " << it.b << " " << it.c << endl;
	}
}