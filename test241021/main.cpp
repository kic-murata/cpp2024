/*
vectorに構造体を格納して、特定のメンバの値を使ってソートを行うサンプル
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {
	int a, b, c;
} Item;

int main() {
	vector<Item> vec{ {11,9,8},{8,10,12},{20,5,1},{10,2,3} };
	//第三引数に比較関数（ラムダ式）を記述して、昇順降順を切り替え
	//今回はメンバcの大小比較で降順ソートしている
	sort(vec.begin(), vec.end(), 
		[](const Item& it1, const Item& it2) { return it1.c > it2.c; }
	);

	cout << "a  b  c" <<  endl;
	for (Item it : vec) {
		cout << it.a << " " << it.b << " " << it.c << endl;
	}
}