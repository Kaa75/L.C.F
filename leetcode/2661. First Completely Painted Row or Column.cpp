#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> locations;
        int rowSize = mat.size(), colSize = mat[0].size();
        vector<int> rowFreq(rowSize, 0), colFreq(colSize, 0);
        
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                locations[mat[i][j]] = {i, j};
            }
        }

        for (int index = 0; index < arr.size(); index++) {
            int row = locations[arr[index]].first;
            int col = locations[arr[index]].second;

            rowFreq[row]++;
            colFreq[col]++; 

            if (rowFreq[row] == colSize)
                return index;

            if (colFreq[col] == rowSize)
                return index;
        }

        return -1;
    }
};
