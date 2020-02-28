#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool sortByDist(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second - b.second;
}

int main()
{
    // deschid fisierele
    ifstream input ("p1.in");
    ofstream output ("p1.out");
    
    int n;
    input >> n;
    
    vector<int> lista;
    lista.resize(n);

    for(int i = 0; i < n; i++) input >> lista[i];

    vector<pair<int, int>> distArr;
    distArr.resize(n);
    for(int i = 0; i < n; i++) {
        distArr[i] = make_pair(i+1, lista[i]);
    }

    sort(distArr.begin(), distArr.end(), sortByDist);
    int prev = distArr[0].second;
    for(int i = 1; i < n; i++) {
        if(distArr[i].second == 0 || (distArr[i].second - prev) > 1) {
            output << "-1\n";
            output.close();
            return 0;
        }
        prev = distArr[i].second;
    }

    output << n-1 << "\n";

    for(int i = 1; i < n; i++) {
        int dist = distArr[i].second - distArr[i - 1].second;
        if(dist == 1) prev = distArr[i - 1].first;
        output << prev << " " << distArr[i].first << "\n";
    }


    output.close();
    return 0;
}
