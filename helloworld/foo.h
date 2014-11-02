template <typename hello> class foo
{
    public:
        foo();
        foo(hello mystuff);
        hello myvar;
};

template <typename hello> foo<hello>::foo()
{
}

template <typename hello> foo<hello>::foo(hello mystuff)
{
    myvar = mystuff;
}
