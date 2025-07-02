#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;

    v.push_back(11);
    v.emplace_back(22); // generally emplace back is faster than push back
    v.emplace_back(33);
    v.emplace_back(44);
    v.emplace_back(55);
    v.emplace_back(66);
    v.emplace_back(77);
    v.emplace_back(88);


    vector<pair<int, int>> v2;

    v2.push_back({1, 2});  // Without {} you can't write(insert) element in push_back function
    v2.emplace_back(3, 4); // But in emplace_back fn. you can insert element without writing {} inside the (). It automatically assume is as pair

    vector<int> v3(5, 100); // 100 is in vector of 5 time

    vector<int> v4(5, 20);
    vector<int> v5(v4); // v5 is copy of v4 5 times 20

    cout << "V:" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << "\nV after erase:" << endl;
    v.erase(v.end() - 2);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << "\nV after 2nd erase:" << endl;
    v.erase(v.begin() + 1, v.begin() + 3); // it delete inx no. 1 and 2  END is not included
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << "\nElement at back of V: " << v.back() << endl;

    cout << "V2:" << endl;
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i].first << " " << v2[i].second << " ";
    }

    v.swap(v3);
    cout << "\nAfter swapping v to v3 V:-" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\nAfter swapping v to v3 V3:-" << endl;
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }

    cout << "\nV4:" << endl;
    for (int i = 0; i < v4.size(); i++)
    {
        cout << v4[i] << " ";
    }

    v4.insert(v4.begin() + 1, 3, 12); // (no. of position, no. of elements in insertion ,number )
    cout << "\nV4 After insertion:" << endl;
    for (int i = 0; i < v4.size(); i++)
    {
        cout << v4[i] << " ";
    }

    cout << "\nV5:" << endl;
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5[i] << " ";
    }

    cout << "\nV5 after pop:" << endl;
    v5.pop_back();
    for (auto it = v5.begin(); it != v5.end(); it++)
    {
        cout << *it << " ";
    }
    
    v5.clear();
    cout << "\nV5 after clear:" << endl;
    for (int i = 0; i < v5.size(); i++)
    {
        cout << v5[i] << " ";
    }

    cout << "V5 is empty or not:" << v5.empty() << endl;
    cout << "V is empty or not:" << v.empty() << endl;

    return 0;
}