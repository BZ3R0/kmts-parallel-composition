#include <bits/stdc++.h>
#include <list>
#define V1 4
#define V2 5

using namespace std;

int main(){
  int i, u;
  int i_index = 0, u_index = 0;

  int graph1[V1][V1] = {
                        {0, 4, 0, 0},
                        {0, 0, 2, 2},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                       };

  int graph2[V2][V2] = {
                        {0, 4, 3, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 2},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                       };

  V3 = V2 * V2;
  int graph3[V3][V3];

  for (i = 0; i < V1; i++)
    for(u = 0; u < V2; u++)
      if((graph1[i][u] > 0) && (graph2[i][u] > 0)){
          if(i == 0){
            i_index = i + 6, u_index = u + 6;
            graph3[i_index][u_index] = 1;
            i_index = 0, u_index = 0;
          }
      }
      else if((graph1[i][u] == 0) && (graph2[i][u] > 0)){
        if(i == 0){
          i_index = i, u_index = u;
          graph3[i_index][u_index] = 1;
        }
      }
      else if((graph1[i][u] > 0) && (graph2[i][u] == 0)){
        graph3[u][i] = 1;
      }

      printf("%d tt %d\n", graph1[i][u], graph2[i][u]);
  return 0;
}
