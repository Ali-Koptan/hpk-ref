template<class T>
class SegmentTree
{
private:
    class Node
    {
    public:
        long long int Start, End;
        T val, lazy;
        Node *right, *left;
        Node(long long int Start, long long int End)
        {
            this->Start = Start;
            this->End = End;
            right = left = nullptr;
            val = 0;
            //default lazy value here...
            lazy = 0;
        }
    }*root;
    long long int _size;
    void ensureChildren(Node* n)
    {
        if(n->Start == n->End)
        {
            cleanUp(n);
        }
        else
        {
            long long int mid = (n->Start + n->End) / 2;
            if(n->left == nullptr || n->right == nullptr)
            {
                n->left = new Node(n->Start, mid);
                n->right = new Node(mid + 1, n->End);
            }
            else
            {
                n->left->Start = n->Start;
                n->left->End = mid;
                n->right->Start = mid + 1;
                n->right->End = n->End;
            }
        }
    }
    void checkLazy(Node* n)
    {
        ensureChildren(n);
        //Lazy check here...
        if(n->lazy != 0)
        {
            //Lazy Update here...
            n->val += n->lazy * (n->End - n->Start + 1);
            if(n->Start != n->End)
            {
                n->left->lazy += n->lazy;
                n->right->lazy += n->lazy;
            }
            n->lazy = 0;
        }
    }
    void build(Node* n, T* arr)
    {
        ensureChildren(n);
        if(n->Start == n->End)
        {
            n->val = arr[n->Start];
        }
        else
        {
            build(n->left, arr);
            build(n->right, arr);
            //insert build code here...
            n->val = n->left->val + n->right->val;
        }
    }
    void update(Node* n, long long int TStart, long long int TEnd, const T& val)
    {
        checkLazy(n);
        if(n->Start > TEnd || n->End < TStart)
        {
            return;
        }
        if(n->Start >= TStart && n->End <= TEnd)
        {
            //insert complete update code here...
            n->val += val * (n->End - n->Start + 1);
            if(n->Start != n->End)
            {
                n->left->lazy += val;
                n->right->lazy += val;
            }
        }
        else
        {
            update(n->left, TStart, TEnd, val);
            update(n->right, TStart, TEnd, val);
            //insert combined update code here
            n->val = n->right->val + n->left->val;
        }
    }
    T query(Node* n, long long int TStart, long long int TEnd)
    {
        checkLazy(n);
        if(n->Start > TEnd || n->End < TStart)
        {
            //insert out of range query code here...
            return 0;
        }
        if(n->Start >= TStart && n->End <= TEnd)
        {
            //insert complete query code here...
            return n->val;
        }
        else
        {
            T lhs = query(n->left, TStart, TEnd);
            T rhs = query(n->right, TStart, TEnd);
            //insert combined query code here...
            return lhs + rhs;
        }
    }
    void cleanUp(Node* n)
    {
        if(n == nullptr)
        {
            return;
        }
        delete n->left, n->right;
        n->left = n->right = nullptr;
    }
public:
    SegmentTree(long long int n, const T& initialVal)
    {
        _size = n;
        root = new Node(0, _size - 1);
        update(root, 0, _size - 1, initialVal);
    }
    SegmentTree(T* arr, int Size)
    {
        _size = Size;
        root = new Node(0, _size - 1);
        build(root, arr);
    }
    void Build(T* arr, int Size)
    {
        _size = Size;
        root->Start = 0;
        root->End = _size - 1;
        build(root, arr);
    }
    void Build(long long int Size, const T& initialVal)
    {
        cleanUp(root);
        _size = Size;
        root->Start = 0;
        root->End = _size - 1;
        update(root, 0, _size - 1, initialVal);
    }
    void Update(int Start, int End, const T& val)
    {
        update(root, Start, End, val);
    }
    T Query(int Start, int End)
    {
        return query(root, Start, End);
    }
    ~SegmentTree()
    {
        cleanUp(root);
        delete root;
    }
};
