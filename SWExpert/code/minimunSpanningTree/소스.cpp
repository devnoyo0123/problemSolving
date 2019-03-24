#include <stdio.h>

const int MAXV = 100005;
const int MAXE = 500005;

struct EDGE {
	int x, y, w;
}edge[MAXE], tmp[MAXE];

int V, E;
int disjoint_set[MAXE];

void MergeSort(int s, int e);
void Kruskal();
int find_root(int);

int main() {
	int TC; 
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &V, &E);

		for (int i = 1; i <= V; i++)
		{
			printf("Draw vectex %d\n", i);
			disjoint_set[i] = i;
		}

		for (int i = 0; i < E; i++)
		{
			scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].w);
		}

		MergeSort(0, E - 1);

		static int testcase = 0;
		printf("#%d", ++testcase);

		Kruskal();
	}
	return 0;
}

void MergeSort(int s, int e) {
	//s부터 e까지 합병정렬하는데 소트 기준은 w 가중치
	if (s >= e) {
		return;
	}

	int m = (s + e) / 2;
	MergeSort(s, m);
	MergeSort(m + 1, e);
	
	int left = s, right = m + 1, pointer = s;

	while (left <= m && right <= e) {
		if (edge[left].w <= edge[right].w) {
			tmp[pointer++] = edge[left++];
		}
		else {
			tmp[pointer++] = edge[right++];
		}
	}

	while (left <= m) {
		tmp[pointer++] = edge[left++];
	}
	while (right <= e) {
		tmp[pointer++] = edge[right++];
	}

	for (int i = s; i <= e; i++) {
		edge[i] = tmp[i];
	}

}

void Kruskal() {
	int mst_total_weight = 0;

	for (int i = 0; i < E; i++) 
	{
		int group_x = find_root(edge[i].x);
		int group_y = find_root(edge[i].y);

		if (group_x == group_y) {
			continue;
		}

		mst_total_weight += edge[i].w;
		printf("x : %d, y : %d , weight: %d\n", group_x, group_y, edge[i].w);

		disjoint_set[group_y] = group_x;
		printf("Union %d -%d \n", group_x, group_y);

	}

	printf("%d\n", mst_total_weight);
}

int find_root(int x) {
	if (disjoint_set[x] == x)
		return x;

	disjoint_set[x] = find_root(disjoint_set[x]);
	return disjoint_set[x];
}

/*
1
5 8
1 2 4
1 3 9
1 4 21
2 3 8
2 4 17
3 4 16
5 2 20
5 4 30

*/