#include <iostream>
using namespace std;

 
struct Node
{
    int key;
    struct Node *left, *right;
};
 
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

void sorted(Node *root, int array[], int &i)
{
    if (root != NULL)
    {
        sorted(root->left, array, i);
        array[i++] = root->key;
        sorted(root->right, array, i);
    }
}
 

Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    return node;
}
 
void sort(int array[], int n)
{
    struct Node *root = NULL;
 
    root = insert(root, array[0]);
    for (int i=1; i<n; i++)
        root = insert(root, array[i]);
 
    
    int i = 0;
    sorted(root, array, i);
}
 
int main()
{
    
    int n;
    cout<<"Number of elements: ";
    cin>>n;
    int array[n];
    
    for(int j=0;j<n;j++)
    {
    	cout<<j+1<<" th number elements: ";
    	cin>>array[j];
	}

    sort(array, n);
 
        for (int i=0; i<n; i++)
        {
       cout << array[i] << " ";
       }
    return 0;
}










