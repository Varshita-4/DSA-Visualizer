#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// ======================= SORTING MODULE =======================
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        cout << "Pass " << i+1 << ": ";
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
        for(int x : arr) cout << x << " ";
        cout << endl;
    }
}

void insertionSort(vector<int> arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while(j >= 0 && arr[j] > key)
            arr[j+1] = arr[j--];
        arr[j+1] = key;
        cout << "Step " << i << ": ";
        for(int x : arr) cout << x << " ";
        cout << endl;
    }
}

// ======================= STACK MODULE =======================
void stackOperations() {
    stack<int> st;
    int choice, val;
    while (true) {
        cout << "\n--- Stack Operations ---\n1. Push\n2. Pop\n3. Display\n0. Back\nChoose: ";
        cin >> choice;
        if(choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            st.push(val);
        } else if(choice == 2) {
            if(st.empty()) cout << "Stack is empty.\n";
            else { cout << "Popped: " << st.top() << endl; st.pop(); }
        } else if(choice == 3) {
            stack<int> temp = st;
            cout << "Stack (Top to Bottom): ";
            while(!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        } else break;
    }
}

// ======================= QUEUE MODULE =======================
void queueOperations() {
    queue<int> q;
    int choice, val;
    while (true) {
        cout << "\n--- Queue Operations ---\n1. Enqueue\n2. Dequeue\n3. Display\n0. Back\nChoose: ";
        cin >> choice;
        if(choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            q.push(val);
        } else if(choice == 2) {
            if(q.empty()) cout << "Queue is empty.\n";
            else { cout << "Dequeued: " << q.front() << endl; q.pop(); }
        } else if(choice == 3) {
            queue<int> temp = q;
            cout << "Queue (Front to Rear): ";
            while(!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        } else break;
    }
}

// ======================= GRAPH MODULE =======================
void bfs(vector<vector<int>>& adj, int start, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while(!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for(int neighbor : adj[node]) {
        if(!visited[neighbor])
            dfsUtil(neighbor, adj, visited);
    }
}

void graphTraversal() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):\n";
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // if undirected
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    bfs(adj, start, V);
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    dfsUtil(start, adj, visited);
    cout << endl;
}

// ======================= TREE MODULE =======================
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(NULL), right(NULL) {}
};

Node* buildTree() {
    int val;
    cout << "Enter node value (-1 for NULL): ";
    cin >> val;
    if(val == -1) return NULL;

    Node* root = new Node(val);
    cout << "Left child of " << val << ":\n";
    root->left = buildTree();
    cout << "Right child of " << val << ":\n";
    root->right = buildTree();
    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void treeTraversal() {
    Node* root = buildTree();
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;
}

// ======================= MAIN MENU =======================
int main() {
    int choice;
    while(true) {
        cout << "\n===== DSA VISUALIZER =====\n";
        cout << "1. Sorting Algorithms\n";
        cout << "2. Stack Operations\n";
        cout << "3. Queue Operations\n";
        cout << "4. Graph Traversal (BFS/DFS)\n";
        cout << "5. Binary Tree Traversals\n";
        cout << "0. Exit\nChoose an option: ";
        cin >> choice;

        if(choice == 1) {
            vector<int> arr;
            int n, val;
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements: ";
            for(int i = 0; i < n; i++) {
                cin >> val;
                arr.push_back(val);
            }
            cout << "\n1. Bubble Sort\n2. Insertion Sort\nChoose: ";
            int sortType;
            cin >> sortType;
            if(sortType == 1) bubbleSort(arr);
            else insertionSort(arr);
        }
        else if(choice == 2) stackOperations();
        else if(choice == 3) queueOperations();
        else if(choice == 4) graphTraversal();
        else if(choice == 5) treeTraversal();
        else if(choice == 0) break;
        else cout << "Invalid option. Try again.\n";
    }
    return 0;
}
