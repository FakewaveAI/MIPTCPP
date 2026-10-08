#include <functional>
#include <iostream>
#include <string>

using namespace std;

int Cnta(string &s) {
	int ans = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		ans += (s[i] == 'a');
	}
	return ans;
}

int Len2(string &s) {
	int ans = (int)s.size() * 2;
	return ans;
}

class Cntlet {
private:
	function<int(string&)> solve;
public:
	Cntlet (function<int(string&)> f) {
		solve = f;
	}

	int operator()(string &s) {
		return solve(s);
	}
};


int main() {
	string s;
	cin >> s;

	Cntlet f1(Cnta);
	cout << f1(s) << endl;

	Cntlet f2(Len2);
	cout << f2(s);
	return 0;
}
