#include<iostream>
#include<stack>
template<class T>
struct BinTreeNode{
    T data;
    struct BinTreeNode* lchild;
    struct BinTreeNode* rchild;
};

template<class T>
class BinTree{
    BinTreeNode<T> *root;
    public:
        BinTreeNode<T>* CreatBinTree();
        void PreOrder(BinTreeNode<T> *root);
};

template<class T>
BinTreeNode<T>* BinTree<T>::CreatBinTree(){
    BinTreeNode<T> *p;
    T num;
    std::cin>>num;
    if(num=='#')
        p=NULL;
    else{
        p=new BinTreeNode<T>;
        if(p==NULL){
            std::cerr<<"申请空间失败！"<<std::endl;
            exit(1);
        }
        p->data=num;
        p->lchild=CreatBinTree();
        p->rchild=CreatBinTree();
    }
    return p;
}

template<class T>
void PreOrder(BinTreeNode<T>* root){
    if(root==NULL)
        std::cout<<"空二叉树"<<std::endl;
    else{
        std::stack<BinTreeNode<T>* >s;
        BinTreeNode<T>* current=root;
        s.push(current);
        while(!s.empty()){
            std::cout<<current->data<<" ";
            s.pop();
            if(current->lchild!=NULL)
                s.push(current->lchild);
            if(current->rchild!=NULL)
                s.push(current->rchild);
        }
    }
}

int main(){
    BinTree<char>bt;
    BinTreeNode<char>* root;
    root=bt.CreatBinTree();
    PreOrder(root);
    return 0;
}
