#ifndef PAPER_H
#define PAPER_H

#include <vector>

struct Point {
    float x, y, z;
};

class Paper {
private:
    std::vector<Point> points;

public:
    Paper();
    void addPoint(const Point& point);
    void setPaperSize(float width, float length);
    void bendAlongLineRightSide(float lineY, float bendfactor);
    void bendAlongLineLeftSide(float lineY, float bendfactor);
    void bendAlongLine2Side(float lineY, float bendfactor);
    void transformToCylinder(float StartY, float EndY, float Radius);
    std::vector<Point> getPaperPoints() const;
};

#endif 
