//NODE H CLASS
#ifndef guard
#define guard
class node {
 public:
    node(int);//constructor
    ~node();//destructor
    void setLeft(node*);
    void setRight(node*);
    node* getLeft();
    node* getRight();
    void setHead(node*);
    void setData(int);
    int getData();
    node* left;
    node* right;
    node* head;
    int data;
};

#endif
