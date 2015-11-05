#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

int calcSyllable(const string &word) {
    if (word.size() == 6 and (word.find("ng") != string::npos or word.find("ny") != string::npos)) {
        return 2;
    }
    bool vowel = false;
    const string vowels = "aiueoAIUEO";
    for (char c: vowels) if (word[0] == c) vowel = true;
    
    if (word.size() == 3 and vowel) {
        return 2;
    }

    if (word.size() >= 6) return 3;
    if (word.size() >= 4) return 2;
    return 1;        
}

int calcSyllable(const vector<string> &verse) {
    int sum = 0;
    rep(i, verse.size()) {
        sum += calcSyllable(verse[i]);
    }
    return sum;
}

int calcSyllable(const vector<vector<string> > &pantun) {
    int cnt = 0;
    rep(i, min(4, (int) pantun.size())) {
        int syl = 0;
        rep(j, pantun[i].size()) syl += calcSyllable(pantun[i][j]);
        if (8 <= syl && syl <= 12) cnt++;
    }
    return cnt;
}

int calcRythm(const vector<vector<string> > &pantun) {
    int cnt = 0;
    rep(i, 2) {
        if (i + 2 >= (int)pantun.size()) continue;
        const vector<string> &verse1 = pantun[i];
        const vector<string> &verse2 = pantun[i+2];
        if (verse1.size() && verse2.size()) {
            const string &str1 = verse1[(int)verse1.size() - 1];
            const string &str2 = verse2[(int)verse2.size() - 1];
            if (str1.size() >= 2 && str2.size() >= 2) {
                if (str1.substr((int)str1.size()-2) == str2.substr((int)str2.size() - 2)) cnt++;
            }
        }
    }
    return cnt;
}

int calcSameSyllable(const vector<vector<string> > &pantun) {
    int cnt = 0;
    rep(i, 2) {
        if (i + 2 >= (int)pantun.size()) continue;
        if (calcSyllable(pantun[i]) == calcSyllable(pantun[i+2])) cnt++;
    }
    return cnt;
}

void solve() {    
    vector<vector<string> > pantun;
    vector<string> verse;
    string word;

    while(char c = getchar()) {
        if (c == '.') {
            verse.pb(word);
            pantun.pb(verse);
            verse.clear();
            word = "";
            break;
        } else if (c == ',') {
            verse.pb(word);
            pantun.pb(verse);
            verse.clear();
            word = "";
        } else if (c == ' ' || c == '\r' || c == '\n') {
            if (word != "") verse.pb(word);
            word = "";
        } else {
            word += c;
        }
    }

    /*
    for (auto &verse: pantun) {
        for (auto &word: verse) cout << word << ",";
        cout << endl;
    }
    cout << endl;
    */
    
    int A = 10 * calcSyllable(pantun);
    int B = 20 * calcRythm(pantun);
    int C = 10 * calcSameSyllable(pantun);
    int D = 10 * max(0, ((int)pantun.size() - 4));
    cout << A << " " << B << " " << C << " " << D << " " << A + B + C - D;
}

void input() {
}

int main() {
    assert(calcSyllable("aku") == 2);
    assert(calcSyllable("kau") == 1);
    assert(calcSyllable("berlari") == 3);
    assert(calcSyllable("belang") == 2);
    assert(calcSyllable("si") == 1);
    assert(calcSyllable("seorang") == 3);
    
    
    cout << fixed << setprecision(12);
    int t; cin >> t;
    rep(i,t) {
        cout << "Case #" << i+1 << ": ";
        input();
        solve();
        cout << endl;
    }
    return 0;
}
