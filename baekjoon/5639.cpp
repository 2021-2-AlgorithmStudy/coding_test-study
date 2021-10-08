// #include <iostream>
// #include <stdlib.h>
// using namespace std;
// // int tree[1000001];
// struct NODE
// {
//     NODE *parent;
//     NODE *left;
//     NODE *right;
//     int num;
// };
// NODE *root;
// int n, prev_n = 1000001;

// NODE *find_lower_bound(NODE *node, int num)
// {
//     NODE *max_node;
//     NODE *cur = node;
//     while (cur->parent)
//     {
//         cur = cur->parent;
//         if (cur->num > max_node->num)
//             max_node = cur;
//         if (num < cur->num)
//         {
//             printf("find1: %d %d\n", num, cur->left->num);
//             return cur->left;
//         }
//     }
//     printf("find2: %d %d\n", num, max_node->num);
//     return max_node;
// }

// void postorder(NODE *node)
// {

//     if (node->left)
//         postorder(node->left);
//     if (node->right)
//         postorder(node->right);
//     printf("%d\n", node->num);
// }
// int main()
// {
//     int cur_idx = 0;
//     cin >> n;
//     root = (NODE *)malloc(sizeof(NODE));
//     root->parent = NULL;
//     root->left = NULL;
//     root->right = NULL;
//     root->num = n;
//     NODE *cur_node = root;
//     for (int i = 1; i < 9; i++)
//     // while (true)
//     {
//         NODE *new_node = (NODE *)malloc(sizeof(NODE));
//         cin >> n;
//         if (cin.eof() == true)
//             break;
//         if (prev_n < n)
//         {
//             cur_node = find_lower_bound(cur_node, n);
//             new_node->num = n;
//             new_node->parent = cur_node;
//             new_node->left = NULL;
//             new_node->right = NULL;
//             cur_node->right = new_node;
//             cur_node = new_node;
//         }
//         else
//         {
//             new_node->num = n;
//             new_node->parent = cur_node;
//             new_node->left = NULL;
//             new_node->right = NULL;
//             cur_node->left = new_node;
//             cur_node = new_node;
//         }
//         prev_n = n;
//     }
//     postorder(root);
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
int tree[1000001][2];
int n, max_node = 0, cur_root;
vector<int> root_list;
void make_node(int num)
{
    if (num < root_list.back())
        tree[root_list.back()][0] = num;
    else
    {
        max_node = 0;
        for (int i = root_list.size() - 1; i >= 0; i--)
        {
            if (num < root_list[i])
                break;
            if (root_list[i] > max_node)
                max_node = root_list[i];
        }
        tree[max_node][1] = num;
    }
    root_list.push_back(num);
}

void postorder(int num)
{
    if (tree[num][0])
        postorder(tree[num][0]);
    if (tree[num][1])
        postorder(tree[num][1]);
    printf("%d\n", num);
}
int main()
{
    int cur_idx = 0;
    cin >> n;
    root_list.push_back(n);
    while (true)
    {
        cin >> n;
        if (cin.eof() == true)
            break;
        make_node(n);
    }
    postorder(root_list[0]);
}