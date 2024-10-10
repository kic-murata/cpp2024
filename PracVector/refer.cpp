#include <iostream>
#include<stdio.h>
using namespace std;
void kansu(int a, int& b) {
	cout << "a:" << a << endl
		<< "b:" << b << endl;
	a = 0;	//a‚ÍmainŠÖ”‚©‚ç“n‚³‚ê‚½’l‚ÌƒRƒs[‚ðŠi”[
	b = 1;	//b‚ÍmainŠÖ”‚©‚ç“n‚³‚ê‚½•Ï”iŽÀ‘Ìj‚Ì•Ê–¼
}
int main() {
	int a = 100, b = 200;
	//printf("a:%d b:%d\n", a, b);
	kansu(a, b);
	cout << "a:" << a << endl
		<< "b:" << b << endl;
	return 0;
}
