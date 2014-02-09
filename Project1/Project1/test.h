template <typename T>
class Point2
{
public:
    Point2():x(), y(){}
    Point2(T a, T b):x(a), y(a){}
    T x;
    T y;
};

template <typename T>
T Add(T& a, T& b)
{
    return a + b;
}

template <typename X, typename Y>
struct Pair
{
    Pair(X a, Y b): x(a), y(b){}
    X x;
    Y y;
};