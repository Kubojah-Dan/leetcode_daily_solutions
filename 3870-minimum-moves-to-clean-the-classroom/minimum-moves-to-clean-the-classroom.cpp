class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        int k = 0;
        int start_r = 0, start_c = 0;

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(classroom[r][c] == 'S'){
                    start_r = r;
                    start_c = c;
                }else if(classroom[r][c] == 'L'){
                    litter_id[r][c] = k++;
                }
            }
        }

        if(k == 0) return 0;
        int full_mask = (1 << k) - 1;

        vector<vector<vector<int>>> best_energy(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        struct State {
            int r, c, mask, e, moves;
        };

        queue<State> q;
        q.push({start_r, start_c, 0, energy, 0});
        best_energy[start_r][start_c][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            State curr = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = curr.r + dr[i];
                int nc = curr.c + dc[i];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X'){
                    continue;
                }
                int ne = curr.e - 1;
                if(ne < 0) continue;

                int nmask = curr.mask;

                if(classroom[nr][nc] == 'R'){
                    ne = energy;
                }

                if(classroom[nr][nc] == 'L'){
                    nmask |= (1 << litter_id[nr][nc]);
                }

                if(nmask == full_mask){
                    return curr.moves + 1;
                }

                if(ne <= best_energy[nr][nc][nmask]) continue;

                best_energy[nr][nc][nmask] = ne;
                q.push({nr, nc, nmask, ne, curr.moves + 1});
            }
        }
        return -1;
    }
};