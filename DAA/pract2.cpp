#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

class HuffmanTreeNode {
    public:
        char data;
        int freq;
        HuffmanTreeNode* left;
        HuffmanTreeNode* right;

    HuffmanTreeNode(char data, int freq) {
        this->data = data;
        this->freq = freq;

        this->left = this->right = nullptr;
    }
};

class Compare{
    public: 
    bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b){
        return a->freq > b->freq;
    }
};

HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare>& pq) {
    while(pq.size() != 1) {
        HuffmanTreeNode* left = pq.top();
        pq.pop();
        HuffmanTreeNode* right = pq.top();
        pq.pop();

        HuffmanTreeNode* newNode = new HuffmanTreeNode('?', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }
    cout<<pq.top()->freq<<endl;
    return pq.top();
}


void printCodes(HuffmanTreeNode* root, vector<int> arr, int top) {
    // cout<<root->data<<'*'<<endl;
    if(root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    if(root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    if(!root->left && !root->right) {
        cout<<root->data<<' ';
        for(int i=0; i<top; i++) {
            cout<<arr[i];
        }
        cout<<endl;
    }
}

void encode(vector<char>& data, vector<int>& freq) {
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;
    int n = data.size();
    for(int i=0; i<n; i++) {
        HuffmanTreeNode* nNode = new HuffmanTreeNode(data[i], freq[i]);
        pq.push(nNode);
    }

    HuffmanTreeNode* root = generateTree(pq);

    vector<int> arr(100);
    int top = 0;
    printCodes(root, arr, top);
}


int main(){
    int n;
    cin >> n;
    vector<char> data;
    vector<int> freq;
    char x;
    for (int i = 0; i < n;i++){
        cin >> x;
        data.push_back(x);
    }
    int y;
    for (int i = 0; i < n; i++)
    {
        cin >> y;
        freq.push_back(y);
    }
    encode(data, freq);
    return 0;
}
