#include <bits/stdc++.h>
using namespace std;
const int mxN = 800;
int n, k;
string tb[mxN];
bool mvis[mxN][mxN];
bool bvis[mxN][mxN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool ok(int x){
    memset(mvis, 0, sizeof mvis);
    memset(bvis, 0, sizeof bvis);
    int ex, ey;
    queue<pair<int, int>> q1, q2, b1, b2;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(tb[i][j] == 'M'){
                b1.push({i, j});
                mvis[i][j] = 1;
            }else if(tb[i][j] == 'H'){
                q1.push({i, j});
                bvis[i][j] = 1;
            }else if(tb[i][j] == 'D'){
                ex = i;
                ey = j;
            }
        }
    }
    for(int i = 0;i<x;i++){
        while(!q1.empty()){
            auto [x, y] = q1.front();
            q1.pop();
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || bvis[nx][ny] || tb[nx][ny] == 'T' || tb[nx][ny] == 'D') continue;
                bvis[nx][ny] = 1;
                q2.push({nx, ny});
            }
        }
        swap(q1, q2);
    }
    while(1){
        auto [x, y] = b1.front();
        if(bvis[x][y]){
            return false;
        }
        break;
    }
    while(!b1.empty()){
        for(int i = 0;i<k;i++){
            while(!b1.empty()){
                auto [x, y] = b1.front();
                b1.pop();
                if(bvis[x][y]) continue;
                for(int j = 0;j<4;j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n || bvis[nx][ny] || mvis[nx][ny] || tb[nx][ny] == 'T') continue;
                    mvis[nx][ny] = 1;
                    b2.push({nx, ny});
                }
            }
            swap(b1, b2);
        }
        while(!q1.empty()){
            auto [x, y] = q1.front();
            q1.pop();
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || bvis[nx][ny] || tb[nx][ny] == 'T' || tb[nx][ny] == 'D') continue;
                bvis[nx][ny] = 1;
                q2.push({nx, ny});
            }
        }
        swap(q1, q2);
    }
    return mvis[ex][ey];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> tb[i];
    }
    int l = 0, r = n * n + 1, ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(ok(mid)){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << ans;
}