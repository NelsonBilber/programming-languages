
template <>
struct Tuple<>
{
    Tuple(){}
};

template <typename T1>
struct Tuple<T1>: Tuple <> // 1 - Tuple
{
    T1 x;
    
    using Base = Tuple <>;
    Base* base()
    {
        return static_cast<Base *>(this);
    }
    
    const Base* base() const
    {
        return static_cast<const Base *>(this);
    }
    
    Tuple(const T1& t1):
    Base{},
    x{t1}
    {}
};