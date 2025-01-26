class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        //everyone sits next to two persons and one of which is their favorite person
        int n = favorite.size();
        vector<int> indgr(n, 0), chain(n, 1);
        for(int& f: favorite) indgr[f]++;

        queue<int> q;
        vector<bool> seen(n, false);
        for(int i = 0; i < n; i++) if(!indgr[i]) q.push(i);
        while(!q.empty()){
            int cur = q.front(), next = favorite[cur]; q.pop();
            seen[cur] = true;
            chain[next] = max(chain[next], chain[cur] + 1);
            if(--indgr[next] == 0) q.push(next);
        }

        int maxCycle = 0, totalChain = 0;
        for(int i = 0; i < n; i++){
            if(seen[i]) continue;
            int cycle = 0, cur = i;
            while(!seen[cur]){
                seen[cur] = true;
                cur = favorite[cur];
                cycle++;
            }

            if(cycle == 2) totalChain += chain[i] + chain[favorite[i]];
            else maxCycle = max(maxCycle, cycle);

        }
        return max(maxCycle, totalChain);
    }
};
