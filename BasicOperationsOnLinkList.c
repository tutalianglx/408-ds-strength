typedef struct node{
    int data;
    struct node* next;
}Node, * LinkList;

/*
    默认都带头结点
*/

//计算单链表长度
int getListLength(LinkList L){
    int count = 0;//计数器
    Node* p = L->next;
    while(p != NULL){//从头开始遍历对结点计数
        count++;
        p = p->next;
    }
    return count;
}

//返回链表的第k个结点
Node* getKthNode(LinkList L,int k){
    int count = 0;//计数器
    Node* p = L->next;
    while(p != NULL){
        count++;
        if(count == k)
            return p;
        p = p->next;
    }
    return NULL;
}

//按关键字查找+删除结点
void deleteNode(LinkList L,int k){
    Node* pre = L;//pre指针指向p结点的前面结点
    Node* p = L->next;//p指针指向要删除的结点
    while(p != NULL){
        if(p->data == k){
            pre->next = p->next;
            Node* temp = p;
            p = p->next;
            free(temp);
        }else{
            pre = p;
            p = p->next;
        }
    }
}

//在一个关键字递增的单链表中插入一个结点
void insertNode(LinkList L,int k){
    //先找到要插入的位置
    Node* pre = L;
    Node* p = L->next;
    while(p != NULL){
        if(p != NULL){
            if(p->data > k)
                break;
            else{
                pre = p;
                p = p->next;
            }
        }
    }
    //插入到p结点的前面
    Node* newNode = (Node *)malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = k;
        newNode->next = p;
        pre->next = newNode;
    }else
        return;
}

//头插法-原地逆置链表
void ListReserve(LinkList L){
    //新建立一个【辅助头结点】
    LinkList newL = (Node*) malloc(sizeof(Node));
    newL->next = NULL;
    //按顺序拆下原链表的每个结点,头插到辅助头结点的后面
    while(L->next != NULL){
        Node* p = L->next;
        L->next = p->next;
        p->next = newL->next;
        newL->next = p;
    }
    //最后释放辅助头结点
    L->next = newL->next;
    free(newL);
}

//尾插法-保持原序
void insertEndNode(LinkList L,int k){
    //先找到尾结点
    Node* p = L;
    while(p->next != NULL){
        p = p->next;
    }
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = NULL;
    p->next = newNode;
}
