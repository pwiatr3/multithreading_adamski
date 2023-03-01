// CPP program to rotate vector
// using rotate algorithm

#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int main () {
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    // vector<int> vec = {1,2,4,5,6,7,3};


    rotate(vec.begin(), vec.begin() + 8, vec.end());
    cout << "Rotated vector: ";
    for (int x: vec)
        cout << x << " ";


return 0;
}
