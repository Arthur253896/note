#include <stdio.h>
#include <stdlib.h>
#define CQ_INIT_SIZE 100
#define MAX_VERTEX_NUM 100 // ͼ�����ڵ���
typedef char VertexType;
 
// �߱�ڵ�
typedef struct node {
    VertexType adjvex; // �붥���������ڽӵ��±�(adjoin���ڽ�)
    struct node* next; // ָ�򶥵����һ���ڽӵ�
} EdgeNode;
 
// ����ṹ
typedef struct vnode {
    VertexType vex;      // �洢������
    EdgeNode* firstedge; // �߱�ͷָ�룬ָ�򶥵��һ���ڽӵ�
} VertexNode, AdjList[MAX_VERTEX_NUM];
 
typedef struct {
    AdjList adjlist; // ����ͼ�ṹ���ڽӱ�
    int vexnum;      // �ڵ����Ŀ
    int edgenum;     // �ߵ���Ŀ
} ALGraph;           // adjacency list���ڽӱ�
typedef int dataType;
typedef struct {
    dataType* data; //�洢����Ԫ��
    int front;      //ָ������е�һ��Ԫ��
    int rear;       //ָ����������һ��Ԫ����һλ��
    int cqCapacity; //��������ɵ�Ԫ�ظ���(��������)
} CQueue;
 
CQueue* initCQueue();            //����һ����ѭ������
int push(CQueue* Q, dataType x); //��Ԫ��x��ӡ������ɹ�����1��ʧ�ܷ���0
int pop(CQueue* Q, dataType* x); //����Ԫ�س��ӣ�������ֵ����x�������ɹ�����1��ʧ�ܷ���0
int isEmpty(CQueue* Q);          //���пշ���1�����򷵻�0
int isFull(CQueue* Q);           //����������1�����򷵻�0
void CreateALG(ALGraph* ALG);     // �ڽӱ�����ͼ
void TraverseALG(ALGraph ALG);    // ���ͼALG���ڽӱ�
void DFSTraverseALG(ALGraph ALG); // ������ȱ������ڽӱ�洢��ͼALG
void DFSALG(ALGraph ALG, int i);  // ��ViΪ��������ڽӱ�洢��ͼALG��ʼDFS����
// ��λ�ڵ�vertex���������±긳��index
void LocateVex(ALGraph ALG, VertexType vertex, int* index);
int visited[MAX_VERTEX_NUM]; // ��־����
void CreateALG(ALGraph* ALG)
{
    VertexType ch;
    int i = 0, count = 0;
    EdgeNode* temp;
 
    printf("������ͼ�Ķ��㣺");
    // ���������
    while ((ch = getchar()) != '\n') {
        ALG->adjlist[i].vex = ch;
        ALG->adjlist[i].firstedge = NULL;
        i++;
    }
    ALG->vexnum = i; // ������
 
    // ͷ�巨����������ڽӱ߱�
    for (i = 0; i < ALG->vexnum; i++) {
        printf("�����붥�� %c ���ڽӶ��㣺", ALG->adjlist[i].vex);
        // ���»س������ڽӵ�Ĵ���
        while ((ch = getchar()) != '\n') {
            temp = (EdgeNode*)malloc(sizeof(EdgeNode));
            temp->adjvex = ch;
            temp->next = ALG->adjlist[i].firstedge;
            ALG->adjlist[i].firstedge = temp;
            count++;
        }
    }
    // ����ͼ��ÿ���������������㣬�ʣ��ڵ��ܶ��� = ���� * 2
    ALG->edgenum = count / 2;
}
void TraverseALG(ALGraph ALG)
{
    int i;
    EdgeNode* temp;
 
    if (ALG.vexnum == 0) {
        printf("ͼΪ��\n");
        return;
    }
 
    // ����ͼ
    for (i = 0; i < ALG.vexnum; i++) {
        printf("���� %c ��", ALG.adjlist[i].vex);
        temp = ALG.adjlist[i].firstedge;
        // ���ͼ����Ϣ
        while (temp) {
            printf("[ %c ] -> ", temp->adjvex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
// ������ȱ������ڽӱ�洢��ͼALG
void DFSTraverseALG(ALGraph ALG)
{
    int i;
 
    // ��ʼ����־����
    for (i = 0; i < ALG.vexnum; i++) {
        visited[i] = 0;
    }
 
    printf("ͼ��������ȱ������У�");
    // �ӵ�һ���ڵ㿪ʼDFS����
    for (i = 0; i < ALG.vexnum; i++) {
        if (!visited[i]) {
            DFSALG(ALG, i);
        }
    }
}
// ���±�Ϊi�Ľڵ�Ϊ�������ͼALG��ʼDFS����
void DFSALG(ALGraph ALG, int i)
{
    EdgeNode* temp;
    int index;
 
    printf("%c, ", ALG.adjlist[i].vex);
    visited[i] = 1; // ��ǽڵ�i�ѱ�����
 
    temp = ALG.adjlist[i].firstedge;
    while (temp) {
        LocateVex(ALG, temp->adjvex, &index);
        // ����indexΪ�±�Ľڵ�δ������������������Ӹýڵ㿪ʼ������һ��DFS����
        if (!visited[index]) {
            DFSALG(ALG, index);
        }
        // ����indexΪ�±�Ľڵ㱻��������Ѱ�ҽڵ����һ���ڽӵ�
        temp = temp->next;
    }
}
void LocateVex(ALGraph ALG, VertexType vertex, int* index)
{
    int i;
 
    for (i = 0; i < ALG.vexnum; i++) {
        if (ALG.adjlist[i].vex == vertex) {
            *index = i; // ���ڵ�vertex���±긳��index
            return;
        }
    }
}
void BFSTraverseALG(ALGraph ALG)
{
    int i, index; // indexΪ��ǰ���ʽڵ������
    char ch;      // �ӽڵ�ch��ʼ��ͼ����BFS����
    EdgeNode* temp;
    CQueue* que = initCQueue();
 
    // ��ʼ����־����
    for (i = 0; i < ALG.vexnum; i++) {
        visited[i] = 0;
    }
 
    printf("�����뿪ʼ�ڵ㣺\n");
    scanf("%c", &ch);
    LocateVex(ALG, ch, &index); // ����ʼ�ڵ�ch���±긳��index
 
    printf("ͼ�Ĺ�����ȱ������У�");
    if (!visited[index]) {
        push(que, index); // ��ʼ�ڵ���ӣ����޸�visited����
        visited[index] = 1;
 
        // �����в���ʱ
        while (!isEmpty(que)) {
            pop(que, &index); // ����Ԫ�س��Ӳ�����
            printf("%c, ", ALG.adjlist[index].vex);
 
            temp = ALG.adjlist[index].firstedge;
            // ���ڵ�������ڽӵ����
            while (temp) {
                LocateVex(ALG, temp->adjvex, &index);
                // ���ڵ�δ������������Ӳ��޸�visited����
                if (!visited[index]) {
                    push(que, index);
                    visited[index] = 1;
                }
                temp = temp->next;
            }
        }
    }
}

// �����ն���
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
// ���
int push(CQueue* Q, dataType x)
{
    if (isFull(Q)) {
        // ���ﵽ����������������������������� 1.5 ��
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
// ����
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