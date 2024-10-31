#include <stdio.h>
#include <stdlib.h>
 
typedef struct queueNode
{
    void *data;
    struct queueNode *next;
} queueNode;
 
typedef queueNode *queue;
 
typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
 
TreeNode* createTreeNode(int value)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) exit(EXIT_FAILURE);
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
// Функция для создания новой очереди
queue createQueue() {
    return NULL;
}
 
// Функция добавления узла к очереди
void enqueue(queue *q, TreeNode *node)
{
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    if (newNode == NULL) return;
    newNode->data = (void *)node;
    newNode->next = NULL;
    if (*q == NULL) *q = newNode; // ксли очередь пустая, добавляем новый узел
    else 
    {
        queueNode *temp = *q;
        while (temp->next != NULL) temp = temp->next; // аайти последний узел
        temp->next = newNode; // вобавляем новый узел в конец очереди
    }
}
 
// функция удаления узла из очереди
TreeNode* dequeue(queue *q)
{
    if (*q == NULL) return NULL; // если очередь пустая, возвращаем NULL
    queueNode *temp = *q; // сохраняем первый узел очереди
    TreeNode *treeNode = (TreeNode *)temp->data; // илекаем данные
    *q = (*q)->next; // свигаем указатель очереди
    free(temp); // сивобождаем память
    return treeNode; // впзвращаем данные
}
 
// функция для подсчета узлов на N-ом уровне
int countNodesAtLevel(TreeNode *root, int N)
{
    if (root == NULL) return 0;
    queue q = NULL;
    enqueue(&q, root); // Добавляем корень в очередь
    int currentLevel = 0;
    int count = 0;
    while (q != NULL) 
    {
        int nodesAtCurrentLevel = 0;
        int nodesInQueue = 0;
        // определяем количество узлов на текущем уровне, сначала считываем количество узлов в очереди для текущего уровня
        queueNode *temp = q;
        while (temp != NULL)
        {
            nodesInQueue++;
            temp = temp->next; // Считываем количество узлов
        }
        // Обрабатываем все узлы на текущем уровне
        for (int i = 0; i < nodesInQueue; i++) 
        {
            TreeNode *currentNode = dequeue(&q); // извлекаем узел из очереди
            // ксли текущий уровень равен N, то увеличиваем счетчик
            if (currentLevel == N) count++; 
            // лобавляем дочерние узлы в очередь
            if (currentNode->left != NULL) enqueue(&q, currentNode->left);
            if (currentNode->right != NULL) enqueue(&q, currentNode->right);
        }
        // Если мы уже достигли нужного уровня, выходим из цикла
        if (currentLevel == N) break;
        currentLevel++; // увеличиваем уровень
    }
    return count; // и возвращаем количество узлов на N-ом уровне
}
 
int main(void)
{
    TreeNode *root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->left->left->left = createTreeNode(4);
    root->left->right->right = createTreeNode(5);
    root->left->left->right = createTreeNode(4);
    root->left->right->left = createTreeNode(5);
    int level = 3;
    int nodeCount = countNodesAtLevel(root, level);
 
    printf("Number of nodes at the level %d: %d\n", level, nodeCount);
 
 
    return 0;
}
 
