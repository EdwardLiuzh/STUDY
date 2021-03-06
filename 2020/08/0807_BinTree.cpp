//  题目：实现二叉树的各种操作
//  测试数据：1 2 # 3 # # 4 5 # # 6 # #
#include <iostream>
#include <queue>
#include <stack>

template<class T>
struct Node {
    T data;
    Node *next;
};

template<class T>
struct BinTreeNode {
    T data;
    BinTreeNode *leftChild;
    BinTreeNode *rightChild;
};

template<class T>
class BinaryTree {
public:
    BinTreeNode<T> *CreateBinaryTree(); // 建立二叉树
    void NoRePreOrder(BinTreeNode<T> *root); // 非递归前序遍历二叉树
    void NoReInOrder(BinTreeNode<T> *root); // 非递归中序遍历二叉树
    void NoRePostOrder(BinTreeNode<T> *root); // 非递归后序遍历二叉树
    void RePreOrder(BinTreeNode<T> *p); // 递归前序遍历二叉树
    void ReInOrder(BinTreeNode<T> *p); // 递归中序遍历二叉树
    void RePostOrder(BinTreeNode<T> *p); // 递归后序遍历二叉树
    void LevelOrder(BinTreeNode<T> *root); // 层次遍历
    int LeafNumber(BinTreeNode<T> *p); // 求叶子数
    int NodeNumbers(BinTreeNode<T> *p); // 求二叉树结点数
    int getDepth(BinTreeNode<T> *p); // 获取二叉树的深度
    void ExchangeLeftAndRight(BinTreeNode<T> *parent); // 交换左右子树
    bool FindX(BinTreeNode<T> *root, T x); // 查找某个数
    bool isEmpty(BinTreeNode<T> *root); // 判断是否是空二叉树
    Node<T> *BuildLeafList(BinTreeNode<T> *root); // 生成叶子结点的链表
    void printLeafList(Node<T> *root); // 打印叶子结点链表
    BinTreeNode<T> *CopyBinaryTree(BinTreeNode<T> *p); // 复制二叉树
    bool isEqual(BinTreeNode<T>* p1, BinTreeNode<T>* p2); // 判断两棵二叉树是否等价
    void LinkToSequence(BinTreeNode<T>* p, T arr[], int i); // 将二叉链式存储结构转换为顺序存储结构
    void MakeEmpty(BinTreeNode<T>* p); // 清空二叉树
};

// 使用前序递归创建二叉树，可以使用中序或后序
template<class T>
BinTreeNode<T> *BinaryTree<T>::CreateBinaryTree() {
    BinTreeNode<T> *p;

    T num;
    std::cin >> num;
    if(num == '#')
        p = NULL;
    else {
        p = new BinTreeNode<T>();
        if(p == NULL) {
            std::cerr << "Space Error！\n";
            exit(1);
        }
        p->data = num;
        p->leftChild = CreateBinaryTree();
        p->rightChild = CreateBinaryTree();
    }
    return p;
}

// 非递归前序遍历二叉树：先访问父结点，再访问左孩子结点，最后访问右孩子结点。
// 思路：从根结点访问，不断访问左孩子结点，如果右孩子结点存在，则先
//      保存在栈中访问到空结点了，就从栈中取出结点，重复此步骤，
//      直到栈空。
template<class T>
void BinaryTree<T>::NoRePreOrder(BinTreeNode<T> *root) {
//    方法1:
//    std::stack<BinTreeNode<T> *> s;
//    BinTreeNode<T> *current;
//
//    if(p == NULL)
//        std::cout << "空二叉树\n";
//    else {
//        s.push(p);
//        while(!s.empty()) {
//            current = s.top(); // 取头结点
//            std::cout << current->data << " ";
//            s.pop();
//            if(current->rightChild != NULL)
//                s.push(current->rightChild);
//            if(current->leftChild != NULL)
//                s.push(current->leftChild);
//        }
//    }
    //    方法2:
    std::stack<BinTreeNode<T> *> s;
    BinTreeNode<T> *current;

    current = root;
    while(!s.empty() || current != NULL) {
        while(current != NULL) { // 当前指针非空
            std::cout << current->data << " ";
            s.push(current);
            current = current->leftChild;
        }
        if(!s.empty()) {
            current = s.top();
            s.pop();
            current = current->rightChild;
        }
    } // while
} // NoRePreOrder

// 非递归中序遍历二叉树：先访问左孩子结点，再访问父结点，最后访问右孩子结点。
// 思路：（1）将二叉树的根结点作为当前结点
//      （2）若当前结点非空，则该结点进栈并将其左孩子结点作为当前结点
//          重复步骤（2），直到当前结点为空为止
//      （3）若栈非空，则将栈顶点出栈并作为当前结点，接着访问当前结点，
//          再将当前结点的右孩子结点作为当前结点
template<class T>
void BinaryTree<T>::NoReInOrder(BinTreeNode<T> *root){
    std::stack<BinTreeNode<T> *> s;
    BinTreeNode<T> *current;

    current = root;
    while(!s.empty() || current != NULL) {
        while(current != NULL) { // 当前结点非空
            s.push(current);
            current = current->leftChild;
        }
        if(!s.empty()) {
            current = s.top();
            s.pop();
            std::cout << current->data << " ";
            current = current->rightChild;
        }
    }
}

// 非递归后序遍历二叉树:先访问左结点，再访问右结点，最后访问根结点。
// 思路：(1)如果当前结点非空，设置标志flag = 0,
//         把根结点和标志flag分别进栈s1和s2；
//      (2)把左孩子结点作为当前结点，如果当前结点非空，则进栈s1，并把标志
//         flag=0存到标志栈s2中,重复步骤（2);
//      (3)直到当前结点为空，则取出s1,s2的栈顶点，判断s2的flag是否为1，
//         如果为1,说明是第二次出栈，则输出该结点；否则，把该结点存到栈s1
//         中， 并将flag设置为1，存储到s2中，同时，把右孩子结点作为当前
//         结点。重复（1）（2）（3）步骤，直到栈为空或当前结点为空
template<class T>
void BinaryTree<T>::NoRePostOrder(BinTreeNode<T> *root){
    std::stack<BinTreeNode<T> *> s1;
    std::stack<int> s2;
    BinTreeNode<T> *current;
    int flag;

    current = root;
    while(!s1.empty() || current != NULL) {
        while(current != NULL) { // 当前结点非空
            s1.push(current); // 当前结点和第一次进栈标志进栈
            s2.push(0);
            current = current->leftChild; // 以当前结点的左孩子作为当前结点
        }
        if(!s1.empty()) { // 栈非空
            current = s1.top(); // s1,s2栈顶顶点出栈
            s1.pop();
            flag = s2.top();
            s2.pop();
            if(flag == 1) { // 如果该结点是第二次出栈
                std::cout << current->data << " "; // 访问结点
                current = NULL;
            } else {
                s1.push(current); // 结点第二次进栈
                s2.push(1);
                current = current->rightChild; // 以当前结点的右孩子作为当前结点
            } // else
        } // if
    } // while
} // NoRePostOrder

// 递归前序遍历二叉树
template<class T>
void BinaryTree<T>::RePreOrder(BinTreeNode<T> *p) {
    if(p != NULL) { // 二叉树非空
        std::cout << p->data << " "; // 对结点进行访问
        RePreOrder(p->leftChild); // 对左子树进行遍历
        RePreOrder(p->rightChild); // 对右子树进行遍历
    }
}

// 递归中序遍历二叉树
template<class T>
void BinaryTree<T>::ReInOrder(BinTreeNode<T> *p) {
    if(p != NULL) { // 二叉树非空
        RePreOrder(p->leftChild); // 对左子树进行遍历
        std::cout << p->data << " "; // 对结点进行访问
        RePreOrder(p->rightChild); // 对右子树进行遍历
    }
}

// 递归后序遍历二叉树
template<class T>
void BinaryTree<T>::RePostOrder(BinTreeNode<T> *p) {
    if(p != NULL) { // 二叉树非空
        RePreOrder(p->leftChild); // 对左子树进行遍历
        RePreOrder(p->rightChild); // 对右子树进行遍历
        std::cout << p->data << " "; // 对结点进行访问
    }
}

// 层次遍历
template<class T>
void BinaryTree<T>::LevelOrder(BinTreeNode<T> *root) {
    std::queue<BinTreeNode<T> *> q;
    BinTreeNode<T> *current;

    current = root;
    if(current != NULL)
        q.push(current);
    while(!q.empty()) {
        current = q.front(); // 取队列头结点
        q.pop();
        std::cout << current->data << " ";
        if(current->leftChild != NULL)
            q.push(current->leftChild);
        if(current->rightChild != NULL)
            q.push(current->rightChild);
    } // while
} // LevelOrder

// 求叶子数
template<class T>
int BinaryTree<T>::LeafNumber(BinTreeNode<T> *p){ // 求叶子数
    if(p == NULL)
        return 0;
    else { // 二叉树非空
        if(p->leftChild == NULL && p->rightChild == NULL)
            return 1;
        else
            return LeafNumber(p->leftChild) + LeafNumber(p->rightChild);
    }
}


// 求二叉树结点数
// 思路：（1）如果当前结点为空，则返回0
//      （2）如果不空，就返回1+左孩子树的结点树+右孩子树的结点数
//          （使用递归）
template<class T>
int BinaryTree<T>::NodeNumbers(BinTreeNode<T> *p) {
    if(p == NULL)
        return 0;
    return 1 + NodeNumbers(p->leftChild) + NodeNumbers(p->rightChild);
}

// 获取二叉树的深度
template<class T>
int BinaryTree<T>::getDepth(BinTreeNode<T> *p) {
    int depth1, depth2;

    if(p == NULL)
        return 0;
    depth1 = getDepth(p->leftChild); // 求左孩子树的高度
    depth2 = getDepth(p->rightChild); // 求右孩子树的高度
    if(depth1 > depth2)
        return (1+depth1);
    return (1+depth2); // else可省略写
}

// 交换左右孩子树
template<class T>
void BinaryTree<T>::ExchangeLeftAndRight(BinTreeNode<T> *parent) {
    BinTreeNode<T> *current;

    if(parent != NULL) {
        current = parent->leftChild;
        parent->leftChild = parent->rightChild;
        parent->rightChild = current;
        ExchangeLeftAndRight(parent->leftChild);
        ExchangeLeftAndRight(parent->rightChild);
    }
}

// 查找某个数:前序遍历各个结点,找x
template<class T>
bool BinaryTree<T>::FindX(BinTreeNode<T> *root, T x) {
    BinTreeNode<T> *current;
    std::stack<BinTreeNode<T> *> s;

    if(root == NULL)
        return false;
    current = root;
    while(!s.empty() || current != NULL) {
        while(current != NULL && current->data != x) {
            s.push(current);
            current = current->leftChild;
        }
        if(current != NULL && current->data == x)
            return true;
        if(!s.empty()) {
            current = s.top();
            s.pop();
            if(current->rightChild != NULL)
                current = current->rightChild;
            else
                current = NULL;
        }
    }
    return false;
}

// 判断是否是空二叉树
template<class T>
bool BinaryTree<T>::isEmpty(BinTreeNode<T> *root) {
    if(root == NULL)
        return true;
    return false;
}

// 生成叶子结点的链表
template<class T>
Node<T> *BinaryTree<T>::BuildLeafList(BinTreeNode<T> *root) {
    std::stack<BinTreeNode<T> *> s;
    BinTreeNode<T> *p;
    Node<T> *newNode;
    Node<T> *head = NULL, *current = NULL; // 头结点

    if(root == NULL) // 空二叉树
        return NULL;
    // p不空,一直往左结点找，直到遇到结点的左孩子结点为空
    p = root;
    while(!s.empty() || p != NULL) {
        while(p != NULL) {
            s.push(p);
            p = p->leftChild;
        }
        if(!s.empty()) {
            p = s.top();
            s.pop();
            if(p->rightChild == NULL) {
                // 如果左结点，右结点为空，则为叶子结点
                newNode = new Node<T>();
                if(newNode == NULL) {
                    std::cerr << "Space ERROR!\n";
                    exit(1);
                }
                newNode->next = NULL;
                newNode->data = p->data;
                if(head == NULL)
                    head = newNode;
                else
                    current->next = newNode;
                current = newNode;
                p = NULL; // 注意要把p置空，否则最后退不出循环。
            } else
                p = p->rightChild;
        }
    }
    return head;
}

// 打印叶子结点链表
template<class T>
void BinaryTree<T>::printLeafList(Node<T> *root) {
    Node<T> *current;

    current = root;
    while(current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

// 复制二叉树
template<class T>
BinTreeNode<T> *BinaryTree<T>::CopyBinaryTree(BinTreeNode<T> *p) {
    BinTreeNode<T> *current;

    if(p == NULL)
        return NULL;
    current = new BinTreeNode<T>();
    if(current == NULL) {
        std::cerr << "Space ERROR！\n";
        exit(1);
    }
    current->data = p->data;
    current->leftChild = CopyBinaryTree(p->leftChild); // 复制左子树
    current->rightChild = CopyBinaryTree(p->rightChild); // 复制右子树
    return current;
}

// 判断两棵二叉树是否等价
template<class T>
bool BinaryTree<T>::isEqual(BinTreeNode<T>* p1, BinTreeNode<T>* p2) {
    bool isFlag;

    isFlag = false; // 假设不等价
    if(p1 == NULL && p2 == NULL) // 两者都为空
        isFlag = true;
    else if(p1 != NULL && p2 != NULL && (p1->data == p2->data)) { // 两个都不为空，并且值相同
        if(isEqual(p1->leftChild, p2->leftChild)) { // 左子树等价，然后再判断右子树
            if(isEqual(p1->rightChild, p2->rightChild)) // 右子树等价
                isFlag = true; // 左右子树都等价
        } // if
    } // eles if
    return isFlag;
}  // isEquit

// 将二叉链式存储结构转换为顺序存储结构
template<class T>
void BinaryTree<T>::LinkToSequence(BinTreeNode<T>* p, T arr[], int i) {
    if(p != NULL) {
        arr[i] = p->data;
        LinkToSequence(p->leftChild, arr, 2 * i + 1);
        LinkToSequence(p->rightChild, arr, 2 * i + 2);
    }
}

// 清空二叉树
template<class T>
void  BinaryTree<T>::MakeEmpty(BinTreeNode<T>* p) {
    if(p != NULL) {
        MakeEmpty(p->leftChild);
        MakeEmpty(p->rightChild);
        delete p;
        p = NULL;
    }
}

int main(int argc, const char * argv[]) {
    int choice, finished;
    BinaryTree<char> bt;
    BinTreeNode<char> *root, *root1, *root3, *root4;
    Node<char> *head; // 指针叶子链表
    char ch, arr[100];

    finished = 1;
    root = NULL;
    for(int i = 0; i < 100; i++)
        arr[i] = '#';
    while(finished) {
        std::cout << "\n*********Menu*********\n";
        std::cout << "1:Creat\n";
        std::cout << "2:NoRe Pre Order\n";
        std::cout << "3:NoRe In Order\n";
        std::cout << "4:NoRe Re Post Order\n";
        std::cout << "5:Re Pre Order\n";
        std::cout << "6:Re In Order\n";
        std::cout << "7:Re Post Order\n";
        std::cout << "8:Level Order\n";
        std::cout << "9:Leaf Number\n";
        std::cout << "10:Node Numbers\n";
        std::cout << "11:get Depth\n";
        std::cout << "12:Exchange Left And Right\n";
        std::cout << "13:Find X\n";
        std::cout << "14:Determine Empty\n";
        std::cout << "15:Build Leaf List\n";
        std::cout << "16:Copy BinaryTree\n";
        std::cout << "17:Equal\n";
        std::cout << "18:Link To Sequence\n";
        std::cout << "19:Make Empty\n";
        std::cout << "20:Exit\n";
        std::cout << "Make Choice(1-20):\n";
        std::cin >> choice;
        switch(choice) {
            case 1:
                std::cout << "Input data：\n";
                root = bt.CreateBinaryTree();
                break;
            case 2:
                std::cout << "NoRe Pre Order：\n";
                bt.NoRePreOrder(root);
                break;
            case 3:
                std::cout << "NoRe In Order：\n";
                bt.NoReInOrder(root);
                break;
            case 4:
                std::cout << "NoRe Post Order：\n";
                bt.NoRePostOrder(root);
                break;
            case 5:
                std::cout << "Re Pre Order：\n";
                bt.RePreOrder(root);
                break;
            case 6:
                std::cout << "Re In Order：\n";
                bt.ReInOrder(root);
                break;
            case 7:
                std::cout << "Re Post Order：\n";
                bt.RePostOrder(root);
                break;
            case 8:
                std::cout << "Level Order：\n";
                bt.LevelOrder(root);
                break;
            case 9:
                std::cout << "LeafNumber：\n";
                std::cout << bt.LeafNumber(root) << std::endl;
                break;
            case 10:
                std::cout << "NodeNumbers：\n";
                std::cout << bt.NodeNumbers(root) << std::endl;
                break;
            case 11:
                std::cout << "getDepth：\n";
                std::cout << bt.getDepth(root) << std::endl;
                break;
            case 12:
                bt.ExchangeLeftAndRight(root); // 交换左右子树
                break;
            case 13:
                std::cout << "find what?";
                std::cin >> ch;
                if(bt.FindX(root, ch))
                    std::cout << "Find!" << ch << "\n";
                else
                    std::cout << "NO DATA" << ch << "\n";
                break;
            case 14:
                if(bt.isEmpty(root))
                    std::cout << "EMPTY!" << "\n";
                else
                    std::cout << "UNEMPTY" << "\n";
                break;
            case 15:
                head = bt.BuildLeafList(root);
                std::cout << "Make Leaf List：\n";
                bt.printLeafList(head);
                break;
            case 16:
                root1 = bt.CopyBinaryTree(root);
                std::cout << "原二叉树前序遍历：" << "\n";
                bt.RePreOrder(root);
                std::cout << std::endl;
                std::cout << "复制的二叉树前序遍历：" << "\n";
                bt.RePreOrder(root1);
                std::cout << std::endl;
                break;
            case 17:
                std::cout << "请输入第一棵二叉树的数据，建立二叉树：" << "\n";
                root3 = bt.CreateBinaryTree(); // 建立第一棵二叉树
                std::cout << "请输入第二棵二叉树的数据，建立二叉树：" << "\n";
                root4 = bt.CreateBinaryTree(); // 建立第二棵二叉树
                if(bt.isEqual(root3, root4))
                    std::cout << "这两棵二叉树等价。";
                else
                    std::cout << "这两棵二叉树不等价。\n";
                break;
            case 18:
                bt.LinkToSequence(root, arr, 0);
                for(int i = 0; i < 100; i++)
                    if(arr[i] != '#')
                        std::cout << i << " " << arr[i] << std::endl;
                break;
            case 19:
                bt.MakeEmpty(root);
                break;
            case 20:
                finished = 0;
                break;
            default:
                std::cout << "输入错误，请重新输入！" << std::endl;
                break;
        }
    }
    return 0;
}
