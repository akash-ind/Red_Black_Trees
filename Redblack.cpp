template<class x,class y>
class redBlack
{
    x key;
    y value;
    redBlack *left;
    redBlack *right;
    string color;
public:
    redBlack(x a,y b,string c="black")
    {
        key=a;
        value=b;
        left=nullptr;
        right=nullptr;
        color=c;
    }
    static redBlack *root;
    static void insert();
    static y get();
    static y floor();
};
template<class x,class y>redBlack<x,y> redblack<x,y>::root=nullptr;
template<class x,class y>void redblack<x,y>::insert(x a,y b)
{
    root=insert(redBlack<x,y>::root,a,b);
}
template<class x,class y>void flipcolor(redBlack<x,y> *node)
{
    if(node==nullptr)
    {
        return;
    }
    node->left->color="black";
    node->right->color="black";
    node->color="red";
    return;
}
template<class x,class y>void left(redBlack<x,y> *node)
{
    if(node==nullptr)
        return;
    redBlack<x,y> *temp=node;
    node=node->right;
    temp->right=node->left;
    node->left=temp;
    node->left->color="red";
}
template<class x,class y>void right(redBlack<x,y> *node)
{
    if(node==nullptr)
        return;
    redBlack<x,y> *temp=node;
    node=node->left;
    temp->left=node->right;
    node->right=temp;
    node->right->color="red";
}
template<class x,class y>bool isRed(redBlack<x,y> *node)
{
    if(node->color=="red")
        return true;
    else
        return false;
}
template<class x,class y>redblack<x,y>* insert(redBlack<x,y> *node,x a,x b)
{
    if(node==nullptr)
    {
        return new redBlack<x,y> ob(a,b);
    }
    if(a<node->key)
    {
        node->left=insert(node->left,a,b);
    }
    else if(a>node->key)
    {
        node->right=insert(node->right,a,b);
    }
    else if(a==node->key)
    {
        node->value=b;
    }
    if(isRed(node->right->color)&&!isRed(node->left->color))
        left(node);
    if(isRed(node->right->color)&&isRed(node->left->color))
        flipcolor(node);

    return node;
}
