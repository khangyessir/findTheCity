class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }
        for(const auto& e : edges) {
            int from = e[0];
            int to = e[1];
            int weight = e[2];
            dist[from][to] = weight;
            dist[to][from] = weight;
        }
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int minReach = n;
        int resCity = -1;
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if(count <= minReach) {
                if(count < minReach || count == minReach && i > resCity) {
                    minReach = count;
                    resCity = i;
                }
            }
        }
        return resCity;
    }
};
