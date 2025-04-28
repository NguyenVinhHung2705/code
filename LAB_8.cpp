#include "iostream"
#include "stack"
#include "queue"
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

void insert(TreeNode*& root,int x)
{
    if(!root)
    {   
        root = new TreeNode(x);
        return;
    } 
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();
        if(!current->left)
        {
            current->left = new TreeNode(x);
            return;
        } 
        else
        {
            q.push(current->left);
        }
        if(!current->right)
        {
            current->right = new TreeNode(x);
            return;
        } 
        else
        {
            q.push(current->right);
        }
    }
}

/*
    Duyệt cây sử dụng đệ quy
*/

// void preOrder(TreeNode* root)
// {
//     if(!root) return;
//     cout << root->val << " ";
//     preOrder(root->left);
// }

// void inOrder(TreeNode* root)
// {
//     if(!root) return;
//     inOrder(root->left);
//     cout << root->val << " ";
//     inOrder(root->right);
// }

// void postOrder(TreeNode* root)
// {
//     if(!root) return;
//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->val << " ";
// }

/*
    Duyệt cây không sử dụng đệ quy
*/

// void preOrder(TreeNode* root)
// {
//     if (!root) return;
//     stack<TreeNode*> st;
//     TreeNode* current = root;
//     while(current || !st.empty())
//     {
//         while(current)
//         {
//             st.push(current);
//             cout << current->val << " ";
//             current = current->left;
//         }
//         current = st.top();
//         st.pop();
//     }
// }

int inMepTrai(TreeNode* root)
{
    if(!root) return 0;
    return root->val + inMepTrai(root->left);
}

void inOrder(TreeNode* root)
{
    if (!root) return;
    stack<TreeNode*> st;
    TreeNode* current = root;
    while(current || !st.empty())
    {
        while(current)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->val << " ";
        current = current->right;
    }

}

void postOrder(TreeNode* root) 
{
    if (!root) return;

    stack<TreeNode*> st;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;

    while (current || !st.empty()) 
    {
        while (current) 
        {
            st.push(current);
            current = current->left;
        }

        TreeNode* peekNode = st.top();
        if (peekNode->right && lastVisited != peekNode->right) 
        {
            current = peekNode->right;
        } 
        else 
        {
            cout << peekNode->val << " ";
            lastVisited = peekNode;
            st.pop();
        }
    }
}

int countLeaves(TreeNode* root) 
{
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int height(TreeNode* root) 
{
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void findValueBetween(TreeNode* root,int x, int y, int& answer)
{
    if(!root || answer != -1) return;
    if(root->val > x && root->val < y)
    {
        answer = root->val;
        return;
    }

    findValueBetween(root->left, x, y, answer);
    findValueBetween(root->right, x, y, answer);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    #endif
	TreeNode* root = nullptr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(root, x);
    }
    cout << inMepTrai(root);
}