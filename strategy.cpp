#include <functional>
#include <iostream>
#include <string>

using namespace std;

int Cnt3(string &s) {
	// возвращает количество подпоследовательностей s из трех одинаковых букв
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			for (int k = j+1; k < n; ++k) {
				ans += (s[i] == s[j] && s[j] == s[k]);
			}
		}
	}
	return ans;
}

class Cntlet {
private:
	function<int(string&)> solve;
public:
	Cntlet (function<int(string&)> f) {
		solve = f;
	}

	string operator()(string &s) {
		if ((int) s.size() > 600) {
			return "String size is too large";
		}
		return "Answer: " + to_string(solve(s));
	}
};


int main() {
	Cntlet f(Cnt3);
	string s = "aaabbbccca";
	cout << f(s) << '\n';
	string t = "";
	for (int i = 0; i < 2000; ++i) {
		t += 't';
	}
	cout << f(t);
	return 0;
}