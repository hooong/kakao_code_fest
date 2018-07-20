#include <iostream>
#include <vector>

using namespace std;

int M;
int N;
vector<vector <int>> Pic;

int flood_fill(int m,int n, int col) {
    int sum = 0;
    
    if(col == 0) {
        return 0;
    }
    
    if(n > 0 && col == Pic[m][n-1]) {       //왼쪽
        Pic[m][n] = 0;
        sum += flood_fill(m, n-1, col);
    }
    
    if(n < N-1 && col == Pic[m][n+1]) {       //오른쪽
        Pic[m][n] = 0;
        sum += flood_fill(m, n+1, col);
    }
    
    if(m > 0 && col == Pic[m-1][n]) {       //위쪽
        Pic[m][n] = 0;
        sum += flood_fill(m-1, n, col);
    }
    
    if(m < M-1 && col == Pic[m+1][n]) {       //아래쪽
        Pic[m][n] = 0;
        sum += flood_fill(m+1, n, col);
    }
    
    Pic[m][n] = 0;
    return 1 + sum;
    
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int max_area, cnt_area, tmp;
    Pic.clear();
    Pic = picture;
    
    M = m;
    N = n;
    max_area = 0;
    cnt_area = 0;
    tmp = 0;
    vector<int> answer;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            max_area = flood_fill(i, j, Pic[i][j]);
            if(max_area != 0) {
                cnt_area++;             //영역 수 증가
                if(tmp < max_area)      //난이도 크면 증가
                    tmp = max_area;
                max_area = 0;
            }
        }
    }
    
    answer.push_back(cnt_area);
    answer.push_back(tmp);
    
    return answer;
    
}

int main(int argc, const char * argv[]) {
    int m,n,tmp;
    vector<int> temp;
    vector<vector<int>> picture;
    vector<int> answer;
    
    cout << "m : ";
    cin >> m;
    cout << "n : ";
    cin >> n;
    
    picture.clear();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "picutre[" << i+1 << "][" << j+1 << "] : ";
            cin >> tmp;
            temp.push_back(tmp);
        }
        picture.push_back(temp);
        temp.clear();
    }
    
    answer.clear();
    answer = solution(m, n, picture);
    
    for(int i = 0; i < 2; i++) {
        cout << answer[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
    
}
