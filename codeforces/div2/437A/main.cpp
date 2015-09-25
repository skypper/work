#include <iostream>
#include <set>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    int a_l = a.size() - 2;
    int b_l = b.size() - 2;
    int c_l = c.size() - 2;
    int d_l = d.size() - 2;

    multiset<pair<int, char>> q;
    q.insert({a_l, 'A'});
    q.insert({b_l, 'B'});
    q.insert({c_l, 'C'});
    q.insert({d_l, 'D'});
    bool cond1A = (*q.begin()).first <= (*(++q.begin())).first / 2;
    bool cond1B = (*q.rbegin()).first / 2 >= (*(++q.rbegin())).first;
    if (cond1A && cond1B || !cond1A && !cond1B) {
        cout << 'C';
    } else if (cond1A) {
        cout << (*q.begin()).second;
    } else if (cond1B) {
        cout << (*q.rbegin()).second;
    } else {
        cout << 'C';
    }


    return 0;
}
