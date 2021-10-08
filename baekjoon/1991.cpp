#include <cstdio>
using namespace std;
int tree[27][2];
int n;
void preorder(int node)
{
    printf("%c", node + 'A');
    if (tree[node][0] != -1)
        preorder(tree[node][0]);
    if (tree[node][1] != -1)
        preorder(tree[node][1]);
}

void inorder(int node)
{
    if (tree[node][0] != -1)
        inorder(tree[node][0]);
    printf("%c", node + 'A');
    if (tree[node][1] != -1)
        inorder(tree[node][1]);
}

void postorder(int node)
{
    if (tree[node][0] != -1)
        postorder(tree[node][0]);
    if (tree[node][1] != -1)
        postorder(tree[node][1]);
    printf("%c", node + 'A');
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char c1, c2, c3;
        scanf(" %c %c %c1", &c1, &c2, &c3);

        tree[c1 - 65][0] = c2 == '.' ? -1 : c2 - 65;
        tree[c1 - 65][1] = c3 == '.' ? -1 : c3 - 65;
    }
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    printf("\n");
    return 0;
}