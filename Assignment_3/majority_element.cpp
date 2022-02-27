#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int find_majority_element(vector<int> &v)
{
    map<int, int> mp;
    for (auto i : v)
    {
        mp[i]++;
    }
    int res = -1;
    for (const auto &i : mp)
    {
        if (i.second > v.size() / 2)
        {
            res = i.first;
        }
    }
    return res;
}
int main()
{
    freopen("output_majority_element.json", "w", stdout);
    std::cout << "{\n \"data\" : [\n";
    for (int i = 1; i < 1000; ++i)
    {
        std::cout << "{\"input_size\":" << i << ",\n";
        std::cout << "\"input\":[";
        vector<int> v(i);
        for (int j = 0; j < i; ++j)
        {
            v[j] = rand() % 10;
            std::cout << v[j];
            if (j != i - 1)
            {
                std::cout << ",";
            }
        }
        std::cout << "],\n";
        auto start = high_resolution_clock::now();
        auto res = find_majority_element(v);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        std::cout << "\"output\":" << res << ",\n";
        std::cout << "\"time\":" << duration.count() << "\n";
        if (i != 1000 - 1)
        {
            std::cout << "},\n";
        }
        else
        {
            std::cout << "}\n";
        }
    }
    std::cout << "]\n}";
    return 0;
}