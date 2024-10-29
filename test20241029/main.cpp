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
•W€“ü—Í‚©‚ç“ü—Í‚³‚ê‚é•¶š—ñ‚ğŠi”[‚·‚éstringŒ^•Ï”line‚ğéŒ¾B
getlineŠÖ”‚É‚æ‚èA•W€“ü—Í‚©‚çline‚Ö•¶š—ñ‚ğŠi”[B
cout‚É‚æ‚èA"Hello"‚ÌŒã‚ÉAline‚ÉŠi”[‚³‚ê‚½•¶š—ñ‚É"!"‚ğ•t‰Á‚µ‚Ä•\¦B
*/