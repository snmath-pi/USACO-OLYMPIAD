/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

const int mxN = 1010;
char grid[mxN][mxN];
bool vis[mxN][mxN];
i64 curr_area = 0;
i64 curr_perimeter = 0;
i64 area = 0, perimeter = 0;
void Y() {
	int rows;
	cin >> rows;
	
	for(int r = 0; r < rows; r++) {
		for(int c = 0; c < rows; c++) {
			cin >> grid[r][c];
		}
	}

	function<void(int, int)> floodfill = [&](int r, int c) {
		if(r < 0 || r >= rows || c < 0 || c >= rows) {
			curr_perimeter++;
			return;
		}
		if(vis[r][c]) return;
		if(grid[r][c] == '.'){
			curr_perimeter++;
			return;
		}
		vis[r][c] = 1;
		if(grid[r][c] == '#') curr_area++;
		floodfill(r-1, c); floodfill(r+1, c); floodfill(r, c-1); floodfill(r, c+1);

	};
	for(int r = 0; r<rows; r++) {
		for(int c = 0; c < rows; c++) {
			if(grid[r][c] == '#' && !vis[r][c]) {
				floodfill(r, c);
				if(area == curr_area) {
					perimeter = min(perimeter, curr_perimeter);
				}
				else if(curr_area > area) {
					area = curr_area;
					perimeter = curr_perimeter;
				}
				curr_area = 0, curr_perimeter = 0;
			}
		}
	}
	cout << area << " " << perimeter;

}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    Y();
    
    return 0;
}
