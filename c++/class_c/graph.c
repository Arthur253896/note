#include <stdio.h>
#include <stdlib.h>
#define CQ_INIT_SIZE 100
#define MAX_VERTEX_NUM 100 // 图中最大节点数
typedef char VertexType;
 
// 边表节点
typedef struct node {
    VertexType adjvex; // 与顶点相连的邻接点下标(adjoin：邻接)
    struct node* next; // 指向顶点的下一个邻接点
} EdgeNode;
 
// 顶点结构
typedef struct vnode {
    VertexType vex;      // 存储顶点名
    EdgeNode* firstedge; // 边表头指针，指向顶点第一个邻接点
} VertexNode, AdjList[MAX_VERTEX_NUM];
 
typedef struct {
    AdjList adjlist; // 描述图结构的邻接表
    int vexnum;      // 节点的数目
    int edgenum;     // 边的数目
} ALGraph;           // adjacency list：邻接表
typedef int dataType;
typedef struct {
    dataType* data; //存储队列元素
    int front;      //指向队列中第一个元素
    int rear;       //指向队列中最后一个元素下一位置
    int cqCapacity; //最多能容纳的元素个数(队列容量)
} CQueue;
 
CQueue* initCQueue();            //创建一个空循环队列
int push(CQueue* Q, dataType x); //将元素x入队。操作成功返回1，失败返回0
int pop(CQueue* Q, dataType* x); //队首元素出队，并将其值赋给x。操作成功返回1，失败返回0
int isEmpty(CQueue* Q);          //队列空返回1，否则返回0
int isFull(CQueue* Q);           //队列满返回1，否则返回0
void CreateALG(ALGraph* ALG);     // 邻接表法创建图
void TraverseALG(ALGraph ALG);    // 输出图ALG的邻接表
void DFSTraverseALG(ALGraph ALG); // 深度优先遍历以邻接表存储的图ALG
void DFSALG(ALGraph ALG, int i);  // 以Vi为出发点对邻接表存储的图ALG开始DFS搜索
// 定位节点vertex，并将其下标赋给index
void LocateVex(ALGraph ALG, VertexType vertex, int* index);
int visited[MAX_VERTEX_NUM]; // 标志数组
void CreateALG(ALGraph* ALG)
{
    VertexType ch;
    int i = 0, count = 0;
    EdgeNode* temp;
 
    printf("请输入图的顶点：");
    // 建立顶点表
    while ((ch = getchar()) != '\n') {
        ALG->adjlist[i].vex = ch;
        ALG->adjlist[i].firstedge = NULL;
        i++;
    }
    ALG->vexnum = i; // 顶点数
 
    // 头插法建立顶点的邻接边表
    for (i = 0; i < ALG->vexnum; i++) {
        printf("请输入顶点 %c 的邻接顶点：", ALG->adjlist[i].vex);
        // 按下回车结束邻接点的创建
        while ((ch = getchar()) != '\n') {
            temp = (EdgeNode*)malloc(sizeof(EdgeNode));
            temp->adjvex = ch;
            temp->next = ALG->adjlist[i].firstedge;
            ALG->adjlist[i].firstedge = temp;
            count++;
        }
    }
    // 无向图中每条边连接两个顶点，故：节点总度数 = 边数 * 2
    ALG->edgenum = count / 2;
}
void TraverseALG(ALGraph ALG)
{
    int i;
    EdgeNode* temp;
 
    if (ALG.vexnum == 0) {
        printf("图为空\n");
        return;
    }
 
    // 遍历图
    for (i = 0; i < ALG.vexnum; i++) {
        printf("顶点 %c ：", ALG.adjlist[i].vex);
        temp = ALG.adjlist[i].firstedge;
        // 输出图的信息
        while (temp) {
            printf("[ %c ] -> ", temp->adjvex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
// 深度优先遍历以邻接表存储的图ALG
void DFSTraverseALG(ALGraph ALG)
{
    int i;
 
    // 初始化标志数组
    for (i = 0; i < ALG.vexnum; i++) {
        visited[i] = 0;
    }
 
    printf("图的深度优先遍历序列：");
    // 从第一个节点开始DFS搜索
    for (i = 0; i < ALG.vexnum; i++) {
        if (!visited[i]) {
            DFSALG(ALG, i);
        }
    }
}
// 以下标为i的节点为出发点对图ALG开始DFS搜索
void DFSALG(ALGraph ALG, int i)
{
    EdgeNode* temp;
    int index;
 
    printf("%c, ", ALG.adjlist[i].vex);
    visited[i] = 1; // 标记节点i已被访问
 
    temp = ALG.adjlist[i].firstedge;
    while (temp) {
        LocateVex(ALG, temp->adjvex, &index);
        // 若以index为下标的节点未被遍历，则遍历。并从该节点开始进行下一轮DFS搜索
        if (!visited[index]) {
            DFSALG(ALG, index);
        }
        // 若以index为下标的节点被遍历，则寻找节点的下一个邻接点
        temp = temp->next;
    }
}
void LocateVex(ALGraph ALG, VertexType vertex, int* index)
{
    int i;
 
    for (i = 0; i < ALG.vexnum; i++) {
        if (ALG.adjlist[i].vex == vertex) {
            *index = i; // 将节点vertex的下标赋给index
            return;
        }
    }
}
void BFSTraverseALG(ALGraph ALG)
{
    int i, index; // index为当前访问节点的索引
    char ch;      // 从节点ch开始对图进行BFS搜索
    EdgeNode* temp;
    CQueue* que = initCQueue();
 
    // 初始化标志数组
    for (i = 0; i < ALG.vexnum; i++) {
        visited[i] = 0;
    }
 
    printf("请输入开始节点：\n");
    scanf("%c", &ch);
    LocateVex(ALG, ch, &index); // 将开始节点ch的下标赋给index
 
    printf("图的广度优先遍历序列：");
    if (!visited[index]) {
        push(que, index); // 开始节点入队，并修改visited数组
        visited[index] = 1;
 
        // 当队列不空时
        while (!isEmpty(que)) {
            pop(que, &index); // 队首元素出队并访问
            printf("%c, ", ALG.adjlist[index].vex);
 
            temp = ALG.adjlist[index].firstedge;
            // 将节点的所有邻接点入队
            while (temp) {
                LocateVex(ALG, temp->adjvex, &index);
                // 若节点未被遍历，则入队并修改visited数组
                if (!visited[index]) {
                    push(que, index);
                    visited[index] = 1;
                }
                temp = temp->next;
            }
        }
    }
}

// 建立空队列
CQueue* initCQueue()
{
    CQueue* Q = (CQueue*)malloc(sizeof(CQueue));
    Q->data = (dataType*)malloc(CQ_INIT_SIZE * sizeof(dataType));
    Q->front = 0;
    Q->rear = 0;
    Q->cqCapacity = CQ_INIT_SIZE;
 
    return Q;
}
int isFull(CQueue* Q)
{
    return (Q->rear + 1) % Q->cqCapacity == Q->front ? 1 : 0;
}
 
int isEmpty(CQueue* Q)
{
    return Q->front == Q->rear ? 1 : 0;
}
// 入队
int push(CQueue* Q, dataType x)
{
    if (isFull(Q)) {
        // 若达到最大容量，则将新容量扩大至旧容量 1.5 倍
        int increment = Q->cqCapacity / 2;
        Q->data = (dataType*)realloc(Q->data,
            (Q->cqCapacity + increment) * sizeof(dataType));
 
        if (!Q->data) {
            return 0;
        }
        Q->cqCapacity += increment;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % Q->cqCapacity;
    return 1;
}
// 出队
int pop(CQueue* Q, dataType* x)
{
    if (isEmpty(Q)) {
        return 0;
    } else {
        *x = Q->data[Q->front];
        Q->front = (Q->front + 1) % Q->cqCapacity;
        return 1;
    }
}
int main()
{
    ALGraph g;
 
    CreateALG(&g);
    printf("------------------------------\n");
    printf("vexnum = %d ; edgenum = %d\n", g.vexnum, g.edgenum);
    printf("------------------------------\n");
    TraverseALG(g);
    printf("------------------------------\n");
    DFSTraverseALG(g);
    BFSTraverseALG(g);
    return 0;
}