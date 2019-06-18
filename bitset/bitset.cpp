#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int get_distinct(unsigned long long N, unsigned long long S, unsigned long long P, unsigned long long Q)
{

    if (p == 0)
    {
        if (s == q)
        {
            return 1;
        }

        return 2;
    }

    if (s == 0 && q == 0)
    {
        return 1;
    }
    set<unsigned long long> distinct;
    unsigned long long current, last = 0;
    unsigned const long long shift = 1UL << 31UL;

    last = S % shift;
    unsigned long long carry_shift = Q % shift;
    distinct.insert(last);
    for (int i = 1; i < N; i++)
    {
        current = last * P + carry_shift;
        last = current;

        distinct.insert(current);
    }

    return distinct.size();
}

int main() {
    unsigned long long N, S, P, Q;

    cin >> N;
    cin >> S;
    cin >> P;
    cin >> Q;

    int distinct = get_distinct(N, S, P, Q);

    cout << distinct << endl;
    return 0;
}
