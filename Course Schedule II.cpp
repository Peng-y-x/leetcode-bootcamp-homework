class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> cQueue;
        for(auto& p : prerequisites){
            int i = p[1], j = p[0];
            graph[i].push_back(j);
            inDegree[j]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                cQueue.push(i);
            }    
        }
        int vNum = 0;
        while(!cQueue.empty()){
            int i = cQueue.front();
            cQueue.pop();
            vNum++;
            res.push_back(i);
            for(int j : graph[i]){
                inDegree[j]--;
                if(inDegree[j] == 0){
                    cQueue.push(j);
                }
            }
        }
        if(vNum < numCourses){
            res = {};
        }
        return res;
    }
};
