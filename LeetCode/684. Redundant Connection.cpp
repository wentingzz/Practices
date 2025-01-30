class BestSpaceSolution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(edges.size()+1);

        for(int i = 0; i < p.size(); i++){
            p[i] = i;
        }

        for(auto& edge: edges){
            int p1 = findP(p, edge[0]);
            int p2 = findP(p, edge[1]);
            cout << p1 << " " << p2 << endl;
            if(p1 == p2){
                return edge;
            }
            if(p1 < p2){
                p[p2] = p1;
            } else {
                p[p1] = p2;
            }
        }
        return {};
    }

    int findP(vector<int>& p, int node){
        if(p[node] != node){
            p[node] = findP(p, p[node]);
        }
        return p[node];
    }
};
