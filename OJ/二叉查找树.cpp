#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class BinaryTree {
public:
    class Node { //����࣬�ڲ�class
	public:
    	T data;           	//���������
    	Node*  left; 	//�����������ָ��
		Node*  right; 	//�����������ָ��
		Node(const T &d): data(d), left(NULL), right(NULL) {}
		Node(const T &d, const Node *l, const Node *r): data(d), left(l), right(r) {}
	};
	
protected:
    Node* root;        				//�����������ָ��
	int getNodeNumber(Node *r) {	// �����ﲹ�����
		if(r==NULL)	return 0;
		else 		return getNodeNumber(r->left)+getNodeNumber(r->right)+1;
	}
	int getNodeNumber(Node *r, int k) {		// �����ﲹ�����
		int t=k;
		if(t<1||root==NULL)	return 0;
		if(t==1)	return 1;
		int ln=getNodeNumber(r->left,t-1);
		int rn=getNodeNumber(r->right,t-1);
		return ln+rn;
	}
	int getHeight(Node *r) {				// �����ﲹ�����
		if(r==NULL)	return 0;
		int ld,rd;
		ld=getHeight(r->left);	
		rd=getHeight(r->right);
		if(ld>rd)	return ld+1;
		else		return rd+1;
	}
	bool isBst(const Node *r) const {		// �����ﲹ�����
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
    BinaryTree() { root = NULL; } 		//���캯��
    BinaryTree(Node* r) { root = r; }
    //~BinaryTree() { DeleteBinaryTree(root); };    	//��������
    bool isEmpty() const { return root==NULL; };  	//�Ƿ�Ϊ����
    static bool isLeaf(const Node *nd) {
        // �����ﲹ�����
    }
    bool isBst() const { return isBst(root); }
    static void visit(const T& v) { cout << v << " "; } //����
    const Node* Root() const { return root; };   	//���ظ����
	int getNodeNumber() { return getNodeNumber(root); };
	int getNodeNumber(int k) { return getNodeNumber(root, k); }
	int getHeight() { return getHeight(root); }
	//��dataΪ����ltreeΪ��������rtreeΪ�������������� 
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
    visit(r->data);		//���ʸ����
    preorder(r->left);
    preorder(r->right);
}

template <class T>
void BinaryTree<T>::postorder(const BinaryTree<T>::Node* r) {
    if (r == NULL) 
       return;
    postorder(r->left);
    postorder(r->right);
    visit(r->data);		//���ʸ����
}

template <class T>
void BinaryTree<T>::inorder(const BinaryTree<T>::Node* r) {
    if (r == NULL) 
       return;
    inorder(r->left);
    visit(r->data);		//���ʸ����
    inorder(r->right);
}

template <typename T>
void BinaryTree<T>::CreateTree( BinaryTree<T>::Node * &r) {
    char ch;
    cin >> ch;
    if (ch == '#')
        r = NULL;
    else {	  //����ǿշ���
        r = new BinaryTree<T>::Node(ch);		//���ɽ��
        CreateTree(r->left);			//����������
        CreateTree(r->right);			//����������
    }
}


template <typename T>
class BSTree: public BinaryTree<T> {
    typedef  typename BinaryTree<T>::Node BTNode;
public:
    BSTree(){};
    BSTree(BTNode *r): BinaryTree<T>(r) {}; // �̳�BinaryTree�Ĺ��캯��
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
typename BinaryTree<T>::Node* BSTree<T>::Search(BTNode* r, const T& k) const {	// �����ﲹ����룬��BTNode����
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
typename BinaryTree<T>::Node * BSTree<T>::parent(const BTNode *me) {			// �����ﲹ����룬��BTNode����
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
    BSTree<char> bst(r); //�����Ӷ�Ӧ�Ĺ��캯��
    char ch1, ch2;
    cin >> ch1 >> ch2; //���������ַ�
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

