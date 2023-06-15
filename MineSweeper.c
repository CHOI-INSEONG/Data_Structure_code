#define __CRT__NO__WARNINGS__
#include <stdio.h>
#include <stdbool.h>
#define NUM	300
int grid[NUM][NUM];
// grid의 특정 원소를 탐사했는지 확인하기 위해 같은 크기의 bool형 배열 선언
bool visited[NUM][NUM] = {false, false};

// MODIFY THIS CODE
void travel(int col, int row) {
	visited[col][row] = true; 
	if (grid[col][row] == 0) return 0; // 재귀함수 탈출 조건: grid의 값이 0이라면 탈출
	else if(grid[col][row] == 1) { //grid의 값이 1일때
		if (visited[col + 1][row] == false) {  // 한칸 오른쪽으로 이동
			travel(col + 1, row);
		}
		if (visited[col][row + 1] == false) {	//한 칸 밑으로 이동
			travel(col, row + 1);
		}
		if (visited[col - 1][row] == false) {// 한 칸 왼쪽으로 이동 
			travel(col - 1, row);
		}
		if (visited[col][row - 1]) {// 한 칸 밑으로 이동
			travel(col, row - 1);
		}

	}
}

int get_mine(int m, int n) {
	int i, j;
	int result = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (visited[i][j] == true) { //이미 방문한 원소라면 그냥 넘김
				continue; 
			}
			else{
				visited[i][j] = true; // 방문한 곳은 방문했다고 표시함
				//만약 grid의 값이 1이라면 travel함수를 호출하고, result의 값을 1 올립니다.
				if (grid[i][j] == 1) { 
					travel(i, j);
					result++;
				}
				else { // grid의 값이 0이라면 그냥 넘김
					continue;
				}
			}
		}
	}

	return result;
}

int main() {
	/* do not modify */
	int i = 0, j = 0, m = 0, n = 0, result = 0;

	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
		}
	}

	result = get_mine(m, n);
	printf("%d\n", result);
	/* do not modify */
}