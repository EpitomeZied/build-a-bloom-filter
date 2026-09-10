#include <bits/stdc++.h>
using namespace std;

// TODO (idea): implement per the lesson description.
class BloomFilter {
private:
    int M = 64;
    vector<int> bits;

    int h1(const string &s) const {
        int sum = 0;
        for (unsigned char c: s) {
            sum += int(c);
        }
        return sum % M;
    }

    int h2(const string &s) const {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            sum += s[i] * (i + 1);
        }
        return sum % M;
    }

public:
    BloomFilter() : bits(M, 0) {
    }

    string add(const string &s) {
        bits[h1(s)] = 1;
        bits[h2(s)] = 1;
        return "OK";
    }

    string check(const string &s) {
        if (bits[h1(s)] == 1 && bits[h2(s)] == 1) {
            return "MAYBE";
        }
        return "NO";
    }

    string get_bits() const {
        string res;
        for (int b: bits) {
            res += to_string(b);
        }
        return res;
    }
};

int main() {
    BloomFilter bf;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string cmd, arg;
        ss >> cmd;

        if (cmd == "ADD") {
            ss >> arg;
            cout << bf.add(arg) << "\n";
        } else if (cmd == "CHECK") {
            ss >> arg;
            cout << bf.check(arg) << "\n";
        } else if (cmd == "BITS") {
            cout << bf.get_bits() << "\n";
        }
    }
}
