#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> count(26, 0);
    for (char c : str)
	{
        int idx = c - 'a';
        count[idx]++;
    }
    vector<int> weight(26);
    for (int i = 0; i < 26; ++i)
	{
        weight[i] = i + 1;
    }
    sort(weight.rbegin(), weight.rend());
    int sum = 0;
    for (int i = 0; i < 26; ++i)
	{
        sum += count[i] * weight[i];
    }
    cout << sum << endl;
    return 0;
}
