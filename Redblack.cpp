template<class x,class y>
class redBlack
{
public:
    x key;
    y value;
    redBlack *left;
    redBlack *right;
    std::string color;
    redBlack(x a,y b,std::string c="red")
    {
        key=a;
        value=b;
        left=nullptr;
        right=nullptr;
        color=c;
    }
    static redBlack *root;
    static void insert(x a,y b);
    static y get(x a);
    static void iterator();
};
template<class x,class y>redBlack<x,y>* redBlack<x,y>::root=nullptr;
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
template<class x,class y>redBlack<x,y>* left(redBlack<x,y> *node)
{
    if(node==nullptr)
        return nullptr;
    redBlack<x,y> *temp=node;
    node=node->right;
    temp->right=node->left;
    node->left=temp;
    node->color=temp->color;
    node->left->color="red";
    return node;
}
template<class x,class y>redBlack<x,y>* right(redBlack<x,y> *node)
{
    if(node==nullptr)
        return nullptr;
    redBlack<x,y> *temp=node;
    node=node->left;
    temp->left=node->right;
    node->right=temp;
    node->color=temp->color;
    node->right->color="red";
    return node;
}
template<class x,class y>bool isRed(redBlack<x,y> *node)
{
    if(node==nullptr)
        return false;
    else if(node->color=="red")
        return true;
        else
            return false;
}
template<class x,class y>redBlack<x,y>* insert(redBlack<x,y> *node,x a,y b)
{
    if(node==nullptr)
    {
        return new redBlack<x,y>(a,b);
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
    using::isRed;
    if(isRed(node->right)&&!isRed(node->left))//this whole thing is a doubt
        node=left<x,y>(node);
    if(isRed(node->left)&&isRed(node->left->left))
        node=right<x,y>(node);
    if(isRed(node->right)&&isRed(node->left))
        flipcolor<x,y>(node);
    return node;
}
template<class x,class y>void redBlack<x,y>::insert(x a,y b)
{
    using::insert;
    root=insert(redBlack<x,y>::root,a,b);
}
template<class x,class y>y get(redBlack<x,y> *node,x a)
{
    if(node==nullptr)
        return NULL;
    else if(a>node->key)
        return get(node->right,a);
    else if(a<node->key)
        return get(node->left,a);
    else if(a==node->key)
        return node->value;
}
template<class x,class y>y redBlack<x,y>::get(x a)
{
    using::get;
    return get(redBlack<x,y>::root,a);
}
template<class x,class y>void iterator(redBlack<x,y> *node)
{
    if(node==nullptr)
        return;
    iterator(node->left);
    std::cout<<node->key<<" "<<node->value<<" "<<node->color<<std::endl;
    iterator(node->right);
}
template<class x,class y>void redBlack<x,y>::iterator()
{
    using::iterator;
    iterator(redBlack<x,y>::root);
}

