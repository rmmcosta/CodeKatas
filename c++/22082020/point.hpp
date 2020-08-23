class Point
{
private:
    double x, y;

public:
    Point(double x, double y) : x(x), y(y) {}
    double getDistance(const Point &) const;
};