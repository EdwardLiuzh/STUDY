#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class BinaryTree {
public:
    class Node { //结点类，内部class
	public:
    	T data;           	//结点数据域
    	Node*  left; 	//结点左子树的指针
		Node*  right; 	//结点右子树的指针
		Node(const T &d): data(d), left(NULL), right(NULL) {}
		Node(const T &d, const Node *l, const Node *r): data(d), left(l), right(r) {}
	};
	
protected:
    Node* root;        				//二叉树根结点指针
	int getNodeNumber(Node *r) {	// 在这里补充代码
		if(r==NULL)	return 0;
		else 		return getNodeNumber(r->left)+getNodeNumber(r->right)+1;
	}
	int getNodeNumber(Node *r, int k) {		// 在这里补充代码
		int t=k;
		if(t<1||root==NULL)	return 0;
		if(t==1)	return 1;
		int ln=getNodeNumber(r->left,t-1);
		int rn=getNodeNumber(r->right,t-1);
		return ln+rn;
	}
	int getHeight(Node *r) {				// 在这里补充代码
		if(r==NULL)	return 0;
		int ld,rd;
		ld=getHeight(r->left);	
		rd=getHeight(r->right);
		if(ld>rd)	return ld+1;
		else		return rd+1;
	}
	bool isBst(const Node *r) const {		// 在这里补充代码
	    if(root==NULL)	return true;
	    if(r->left)
			if(r->left->data>=r->data)
				return false;
		if(r->right)
			if(r->right->data<=r->data)
				return false;
	    return isBst(r->left)&&isBst(r->right);
	}
	
public:
    BinaryTree() { root = NULL; } 		//构造函数
    BinaryTree(Node* r) { root = r; }
    //~BinaryTree() { DeleteBinaryTree(root); };    	//析构函数
    bool isEmpty() const { return root==NULL; };  	//是否为空树
    static bool isLeaf(const Node *nd) {
        // 在这里补充代码
    }
    bool isBst() const { return isBst(root); }
    static void visit(const T& v) { cout << v << " "; } //访问
    const Node* Root() const { return root; };   	//返回根结点
	int getNodeNumber() { return getNodeNumber(root); };
	int getNodeNumber(int k) { return getNodeNumber(root, k); }
	int getHeight() { return getHeight(root); }
	//以data为根，ltree为左子树，rtree为右子树，构造树 
    static BinaryTree & CreateTree(const T& data, Node* ltree, Node* rtree) {
		Node *r = new Node(data);
		r->left = ltree;
		r->right = rtree;
		return *new BinaryTree(r); 
	}		
	static void CreateTree( Node * &r) ;
	static void CreateTree( Node * &r, const string &preorder, const string &inorder) ;
	static void preorder(const Node* root);
	static void inorder(const Node* root);
	static void postorder(const Node* root);
};

template <class T>
void BinaryTree<T>::preorder(const BinaryTree<T>::Node* r) {
    if (r == NULL) 
       return;
    visit(r->data);		//访问根结点
    preorder(r->left);
    preorder(r->right);
}

template <class T>
void BinaryTree<T>::postorder(const BinaryTree<T>::Node* r) {
    if (r == NULL) 
       return;
    postorder(r->left);
    postorder(r->right);
    visit(r->data);		//访问根结点
}

template <class T>
void BinaryTree<T>::inorder(const BinaryTree<T>::Node* r) {
    if (r == NULL) 
       return;
    inorder(r->left);
    visit(r->data);		//访问根结点
    inorder(r->right);
}

template <typename T>
void BinaryTree<T>::CreateTree( BinaryTree<T>::Node * &r) {
    char ch;
    cin >> ch;
    if (ch == '#')
        r = NULL;
    else {	  //读入非空符号
        r = new BinaryTree<T>::Node(ch);		//生成结点
        CreateTree(r->left);			//构造左子树
        CreateTree(r->right);			//构造右子树
    }
}


template <typename T>
class BSTree: public BinaryTree<T> {
    typedef  typename BinaryTree<T>::Node BTNode;
public:
    BSTree(){};
    BSTree(BTNode *r): BinaryTree<T>(r) {}; // 继承BinaryTree的构造函数
    ~BSTree(){};

    BTNode* Search(BTNode* subroot, const T  & k) const;
    BTNode *search(const T &k) const {return Search(this->root, k); }
    BTNode *parent(const BTNode *me);
    void Insert(BTNode *&root, const T& k);
    bool Delete(BTNode *&root, const T& k);
    void insert(const T &k) { Insert(this->root, k); }
    bool remove(const T &k) { return Delete(this->root, k); }
    void postorder() { return BinaryTree<T>::postorder(this->root); }
};

template <typename T>
typename BinaryTree<T>::Node* BSTree<T>::Search(BTNode* r, const T& k) const {	// 在这里补充代码，用BTNode类型
    BTNode *res=NULL;
	if(k==r->data)
		res=r;
    else if(k<r->data)
    	res=Search(r->left,k);
    else if(k>r->data)
    	res=Search(r->right,k);
    if(res==NULL)
    //	cout<<"Cant't find "<<endl;
    return res;
}

template <class T>
typename BinaryTree<T>::Node * BSTree<T>::parent(const BTNode *me) {			// 在这里补充代码，用BTNode类型
	BTNode *r=this->root;		
	if(r!=NULL)
    	while(BinaryTree<T>::getNodeNumber(r)>1){
			if(r->data==me->data)
				return r;
			else if(r->data<me->data)
				r=r->left;
			else if(r->data>me->data)
				r=r->right;
		}
    else{
    //	cout<<"No parent node"<<endl;
    	return NULL;
	}
}

int main() {
  BinaryTree<char>::Node *r ;
  BinaryTree<char>::CreateTree(r);
  BinaryTree<char> bt(r);
  cout << bt.isBst() << endl;
  if (bt.isBst()) {
    BSTree<char> bst(r); //请增加对应的构造函数
    char ch1, ch2;
    cin >> ch1 >> ch2; //输入两个字符
    BinaryTree<char>::Node *me = bst.search(ch1);
    BinaryTree<char>::Node *pn = bst.parent(me);
    BinaryTree<char>::postorder(pn);
    me = bst.search(ch2);
    pn = bst.parent(me);
    BinaryTree<char>::postorder(pn);
  }
  bt.postorder(bt.Root());

  return 0;
}

