#include <stdio.h>
#include <stdlib.h>

//Defição do grafo e do seu número máximo de vértices
#define max 20

int grafo[max][max];
int visitado[max];
int numVertices = 0;

//Adiciona um vértice no grafo
void adicionarVertice() {
  
  if (numVertices < max) {

    //Incializa o marcador do vértice para a busca em profundidade
    visitado[numVertices] = 0;
    numVertices++;

    //Inicializa as arestas do novo vértice
    for (int i = 0; i < numVertices; i++) {
      grafo[i][numVertices - 1] = 0;
      grafo[numVertices - 1][i] = 0;
    }
    
    printf("Vértice número %d adicionado com sucesso.\n", numVertices);
  }
  
  else {
    printf("Número máximo de vértices atingido.\n");
  }
}

//Adiciona um aresta ao grafo
void adicionarAresta(int origem, int destino, int valor) {
  
  if (origem > 0 && origem <= numVertices && destino > 0 && destino <= numVertices) {
    grafo[origem - 1][destino - 1] = valor;
    printf("Aresta de %d para %d com valor %d adicionada com sucesso.\n", origem, destino, valor);
  }
  
  else {
    printf("Vértices inválidos. Certifique-se de que os vértices existem.\n");
  }
}

//Realiza a busca em profundidade (dfs)
void dfs(int vertice) {

  int pilha[max]; // Pilha para rastrear os vértices
  int topo = -1;  // Inicializa o topo da pilha

  int somaArestas = 0; // Variável para armazenar a soma das arestas

  // Inicializa a pilha e marca o vértice inicial como visitado
  pilha[++topo] = vertice;
  visitado[vertice - 1] = 1;
  
  //Exibe o caminho que a dfs percorre dentro do grafo
  printf("Caminho percorrido pela dfs: ");

  while (topo != -1) {
    int verticeAtual = pilha[topo];
    printf("%d ",verticeAtual);
    int proximoVertice = -1;

    // Encontra o próximo vértice adjacente que não foi visitado
    for (int i = 0; i < numVertices; i++) {
      if (grafo[verticeAtual - 1][i] && !visitado[i]) {
        proximoVertice = i + 1;
        break;
      }
    }

    if (proximoVertice != -1) {
      // Empilha o próximo vértice e o marca como visitado
      pilha[++topo] = proximoVertice;
      visitado[proximoVertice - 1] = 1;

      // Soma o valor da aresta à contagem
      somaArestas += grafo[verticeAtual - 1][proximoVertice - 1];
    }
    
    else {
      // Desempilha se não houver vértices adjacentes ainda não visitados
      topo--;
    }
  }

  printf("\nBusca em profundidade concluída. Soma das arestas: %d\n", somaArestas);

  // Exibe os vértices visitados
  printf("Vértices visitados: ");
  for (int i = 0; i < numVertices; i++) {
    if (visitado[i] == 1) {
      printf("%d ", i + 1);
    }
  }
  printf("\n");
}

//Main, menu principal
int main() {
  int escolha, origem, destino, peso, verticeInicial;

  printf("-- Criador de Grafo --\n");
  printf("\nQuantos vértices iniciais terá o grafo (max %d)? ",max);
  scanf("%d",&numVertices);

  while(numVertices>max || numVertices<0){
    if(numVertices>max){
      printf("\nO número máximo de vértices suportados é %d.\n",max);
      printf("Quantos vértices iniciais terá o grafo (max %d)? ",max);
      scanf("%d",&numVertices);
    }

    else{
      printf("\nNúmero de vértices inválido.\n");
      printf("Quantos vértices iniciais terá o grafo (max %d)? ",max);
      scanf("%d",&numVertices);
    }
  }

  for (int i = 0; i < numVertices; i++){
    visitado[i] = 0;
  }
  
  for (int i = 0; i < numVertices; i++){
    for (int j = 0; j <numVertices; j++){
      grafo[i][j] = 0;
    }
  }

  printf("\nGrafo com %d vértices iniciais criado com sucesso.\n", numVertices);
  
  while (escolha!=4) {
    printf("\n- Menu -\n");
    printf("1 - Adicionar vértice\n");
    printf("2 - Adicionar aresta\n");
    printf("3 - Realizar busca em profundidade (DFS)\n");
    printf("4 - Sair\n");
    printf("\nEscolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
      case 1:
        adicionarVertice();
        break;
      
      case 2:
        printf("Origem: ");
        scanf("%d", &origem);
        printf("Destino: ");
        scanf("%d", &destino);
        printf("Peso: ");
        scanf("%d", &peso);
        adicionarAresta(origem, destino, peso);
        break;
      
      case 3:
        printf("Vértice inicial para a busca em profundidade: ");
        scanf("%d", &verticeInicial);
        if (verticeInicial > 0 && verticeInicial <= numVertices) {
          for (int i = 0; i < numVertices; i++) {
            visitado[i] = 0;
          }
          
          dfs(verticeInicial);
        }
        
        else {
          printf("Vértice inicial inválido.\n");
        }
        break;
      
      case 4:
        printf("Saindo do programa.\n");
        break;
      
      default:
      printf("Escolha inválida. Tente novamente.\n");
    }
    
  }
  return 0;
}