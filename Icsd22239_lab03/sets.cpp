
    T getData() const
    {
        return data;
    }

    void setData(T val)
    {
        data = val;
    }

    Node<T> *getLeft() const
    {
        return Left;
    }

    void setLeft(Node<T> *node)
    {
        Left = node;
    }

    Node<T> *getRight() const
    {
        return Right;
    }

    void setRight(Node<T> *node)
    {
        Right = node;
    }