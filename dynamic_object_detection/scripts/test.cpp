#include <cstdio>
#include <ros/ros.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

// Men and women are represented by integers 1...N

// ManPref is the preference list of all men for all women.
// ManPref[m][i] = w iff w is at ith position in the preference list of m

// WomanPref is the preference list of all women for all men.
// WomanPref[w][i] = m iff m is at ith position in the preference list of w

// Ranking gives the ranking of each man in the preference list of each woman
// Ranking[w][m] = i iff WomanPref[w][i] = m

// Current gives the current engagement of each women
// Current[w] = m iff w is currently engaged to m

// Next gives the index of next woman to propose to in the preference list of each man
// Next[m] = i iff m has proposed to all w s.t. ManPref[m][j] = w for j = 1...i-1 but not ManPref[m][i]
int Ranking[505][505], ManPref[505][505], WomanPref[505][505], Next[505], Current[505];

double Cal_dis(double x,double y,double z, double a, double b, double c){
    return sqrt((x-a)*(x-a)+(y-b)*(y-b)+(z-c)*(z-c));
}

int main()  {
    int N, i, j, m, w;

	N = 7;
	double before_x[N+1];
    double before_y[N+1];
    double now_x[N+1];
    double now_y[N+1];

	double temp_w_x[N+1];
    double temp_w_y[N+1];
    double temp_m_x[N+1];
    double temp_m_y[N+1];
    // list of men who are not currently engaged
    queue <int> freeMen;

	before_x[1] = 0.999964;
	before_x[2] = -1.39042;
	before_x[3] = 5.67496;
	before_x[4] = -3.4917;
	before_x[5] = -3.36948;
	before_x[6] = 3.71068;
	before_x[7] = -0.728607;

	before_y[1] = -3.025;
	before_y[2] = 4.2625;
	before_y[3] = 2.6125;
	before_y[4] = -2.42917;
	before_y[5] = 2.36806;
	before_y[6] = 1.74821;
	before_y[7] = -3.47679;

	now_x[1] = 3.68121;
	now_x[2] = -3.4917;
	now_x[3] = -1.39042;
	now_x[4] = 0.999964;
	now_x[5] = -3.36948;
	now_x[6] = -0.741702;
	now_x[7] = 99.9;

	now_y[1] = 1.85625;
	now_y[2] = -2.42917;
	now_y[3] = 4.2625;
	now_y[4] = -3.025;
	now_y[5] = 2.36806;
	now_y[6] = -3.4375;
	now_y[7] = 99.9;

	// turn lacations to preference
	for(int k=1; k<=N; k++){
		// data copy
		for(int j=1; j<=N; j++){
			temp_w_x[j] = now_x[j];
			temp_w_y[j] = now_y[j];
			temp_m_x[j] = before_x[j];
			temp_m_y[j] = before_y[j];
		}

		for(int i=1; i<=N; i++){
			double min_w_dis = 999;
			double min_m_dis = 999;
			int min_w_flag = -1;
			int min_m_flag = -1;
			for(int j=1; j<=N; j++){
				if(Cal_dis(before_x[k],before_y[k],0,temp_w_x[j],temp_w_y[j],0)<min_w_dis){
					min_w_dis = Cal_dis(before_x[k],before_y[k],0,temp_w_x[j],temp_w_y[j],0);
					min_w_flag = j;
				}
				if(Cal_dis(now_x[k],now_y[k],0,temp_m_x[j],temp_m_y[j],0)<min_m_dis){
					min_m_dis = Cal_dis(now_x[k],now_y[k],0,temp_m_x[j],temp_m_y[j],0);
					min_m_flag = j;
				}
			}
			WomanPref[k][i] = min_w_flag;
			ManPref[k][i] = min_m_flag;
			temp_w_x[min_w_flag] = 999;
			temp_w_y[min_w_flag] = 999;
			temp_m_y[min_m_flag] = 999;
			temp_m_y[min_m_flag] = 999;
		}
	}

	// for(int k=1; k<=N; k++){
	// 	for(int i=1; i<=N;i++){
	// 		cout<<WomanPref[k][i]<<" ";
	// 	}cout <<endl;
	// }cout<<endl;
	// for(int k=1; k<=N; k++){
	// 	for(int i=1; i<=N;i++){
	// 		cout<<ManPref[k][i]<<" ";
	// 	}cout <<endl;
	// }






	// WomanPref[1][1] = 1;
	// WomanPref[1][2] = 5;
	// WomanPref[1][3] = 3;
	// WomanPref[1][4] = 2;
	// WomanPref[1][5] = 4;

	// WomanPref[2][1] = 1;
	// WomanPref[2][2] = 3;
	// WomanPref[2][3] = 2;
	// WomanPref[2][4] = 5;
	// WomanPref[2][5] = 4;

	// WomanPref[3][1] = 3;
	// WomanPref[3][2] = 4;
	// WomanPref[3][3] = 2;
	// WomanPref[3][4] = 1;
	// WomanPref[3][5] = 5;

	// WomanPref[4][1] = 1;
	// WomanPref[4][2] = 2;
	// WomanPref[4][3] = 3;
	// WomanPref[4][4] = 4;
	// WomanPref[4][5] = 5;

	// WomanPref[5][1] = 5;
	// WomanPref[5][2] = 4;
	// WomanPref[5][3] = 2;
	// WomanPref[5][4] = 3;
	// WomanPref[5][5] = 1;

	// ManPref[1][1] = 1;
	// ManPref[1][2] = 2;
	// ManPref[1][3] = 4;
	// ManPref[1][4] = 3;
	// ManPref[1][5] = 5;

	// ManPref[2][1] = 4;
	// ManPref[2][2] = 3;
	// ManPref[2][3] = 1;
	// ManPref[2][4] = 5;
	// ManPref[2][5] = 2;

	// ManPref[3][1] = 3;
	// ManPref[3][2] = 2;
	// ManPref[3][3] = 5;
	// ManPref[3][4] = 1;
	// ManPref[3][5] = 4;

	// ManPref[4][1] = 5;
	// ManPref[4][2] = 1;
	// ManPref[4][3] = 4;
	// ManPref[4][4] = 2;
	// ManPref[4][5] = 3;

	// ManPref[5][1] = 5;
	// ManPref[5][2] = 2;
	// ManPref[5][3] = 3;
	// ManPref[5][4] = 4;
	// ManPref[5][5] = 1;



	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			Ranking[i][WomanPref[i][j]] = j;

	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			cout << " "<<Ranking[i][j];
		}cout<<endl;
	}cout<<endl;

	memset(Current, 0, (N + 1) * sizeof(int));

	for (i = 1; i <= N; i++) {
		freeMen.push(i);
		Next[i] = 1;
	}

	while (!freeMen.empty())    {
		m = freeMen.front();
		// cout << "Next"<<Next[m]<<endl;
		w = ManPref[m][Next[m]++];
		cout <<"man"<< m<<endl;
		cout << "weman"<<w<<endl;
		if (Current[w] == 0)   {
			cout<<"=="<<endl;
			Current[w] = m;
			freeMen.pop();
		} else if (Ranking[w][m] < Ranking[w][Current[w]])  {
			cout<<"wwwww"<<endl;
			freeMen.pop();
			freeMen.push(Current[w]);
			Current[w] = m;
		}
	}

	// (m, w) pairs in the stable matching
	for (w = 1; w <= N; w++)
		printf("%d %d\n", Current[w], w);


	cout << atan2(1,1)*180/M_PI<<endl;;

    return 0;
}
