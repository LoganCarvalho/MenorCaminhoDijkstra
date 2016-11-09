#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define A 100000    //valor maximo do custo da ligacoes

int grafo[1000][1000];
int distancia[1000], n, m, s, d;

/*void uDistancia(){

	u = 0;
	disAux = A;
	for(int i = 0; i < n; i++) {
      	if(visitado[i] != 2 && distancia[i] < disAux) {
				u = i;
				disAux = distancia[i];
      	}
    }
}*/

void dijkstra()
{
    for (int i = 0; i < n; i++)
    {
   		distancia[i] = A; //seto a distancia pra infinito
    }

    distancia[s] = 0; //custo no primeiro vertice recebe 0
    queue<int> fila;
    fila.push(s);

    while (!fila.empty())
    {
        int u = fila.front();  //tiro o s que e inica=ial e coloco no U
        fila.pop();
                //printf("%d aqui\n",u );
        for (int i = 0; i < n; i++)
        {
            if ((grafo[u][i] < A) && (distancia[i] > distancia[u] + grafo[u][i]))
            {
               	distancia[i] = distancia[u] + grafo[u][i];  //coloca a soma do custo no local onde tinha distancia inficito
                
                fila.push(i);  //empilha o i para continuar com o laço.
            }
        }
    }
    if( distancia[d] != A) //se a distancia do destino existir e for diferente de infinito
			printf("%d\n", distancia[d]);
		else
			printf("-1\n");
    //return distancia[d];
}


/*int dijkstra(){

	visitado[s-1] = 1;
	distancia[s-1] = 0;
	for (int i = 0; i < n; i++)
	{
		//uDistancia();
		//printf("%d aqui\n",u );
		for(int j = 0; j < n; j++) {
	      	if(grafo[u][j] < A) {
	        		if(distancia[j] > distancia[u] + grafo[u][j]){
		  				distancia[j] = distancia[u] + grafo[u][j];
	        		}
					if(visitado[j] == 0) {
		  				visitado[j] = 1;
					}
	      	}
    	}
    	visitado[u] = 2;
	}
	for (int i = 0; i < n; i++)
	{
		//printf("%d  a\n",distancia[i] );

	}
	return distancia[d-1];
}*/

int main(){
	ios_base::sync_with_stdio(false);
	int c, v, t;
	while(1){
		cin>>n>>m;   //N é o numero de vertices e M o numero de arestas
		if (n==0 && m==0)
		{
			return 0;
		}
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++)
			{
				grafo[i][j] = A;
			}
		}
		for(int i=0; i<m; i++){
			cin>>t>>v>>c; //ler os valors do grafo
			grafo[t-1][v-1] = c;   //insere um custo diferente de infinito do t para o v
		}
        
        //print a matriz(Fazer método para impressão)
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                cout<<grafo[i][j]<<" ";
            }
            cout<<endl;
        }
        
		cin>>s>>d;   //origem e destino repectivamente
		s--;d--;     //
		//int result;
		dijkstra();
		
	}

	return 0;
}