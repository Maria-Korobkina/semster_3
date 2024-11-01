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
 
queue createQueue() {
    return NULL;
}
 
void enqueue(queue *q, TreeNode *node)
{
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    if (newNode == NULL) return;
    newNode->data = (void *)node;
    newNode->next = NULL;
    if (*q == NULL) *q = newNode;
    else 
    {
        queueNode *temp = *q;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}
 
TreeNode* dequeue(queue *q)
{
    if (*q == NULL) return NULL;
    queueNode *temp = *q;
    TreeNode *treeNode = (TreeNode *)temp->data;
    *q = (*q)->next;
    free(temp);
    return treeNode;
}
 
int countNodesAtLevel(TreeNode *root, int N)
{
    if (root == NULL) return 0;
    queue q = NULL;
    enqueue(&q, root);
    int currentLevel = 0;
    int count = 0;
    while (q != NULL) 
    {
        int nodesAtCurrentLevel = 0;
        int nodesInQueue = 0;
        queueNode *temp = q;
        while (temp != NULL)
        {
            nodesInQueue++;
            temp = temp->next;
        }
        for (int i = 0; i < nodesInQueue; i++) 
        {
            TreeNode *currentNode = dequeue(&q); 
            if (currentLevel == N) count++; 
            if (currentNode->left != NULL) enqueue(&q, currentNode->left);
            if (currentNode->right != NULL) enqueue(&q, currentNode->right);
        }
        if (currentLevel == N) break;
        currentLevel++;
    }
    return count;
}
 
int main()
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
 
