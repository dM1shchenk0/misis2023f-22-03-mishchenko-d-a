#include "paper.h"
#include <iostream>
#include <cmath>
#define PI 3.141592f

Paper::Paper() {}

void Paper::addPoint(const Point& point) {
    if (std::isnan(point.x) || std::isnan(point.y) || std::isnan(point.z)) {
        std::cerr << "Ошибка: Некорректные координаты точки.\n";
        return;
    }
    points.push_back(point);
}

void Paper::setPaperSize(float width, float length) {
    points.clear();
    for (float x = 0; x < width; x += 0.1f) {
        for (float y = 0; y < length; y += 0.1f) {
            points.push_back({ x, y, 0.0f });
        }
    }
}

void Paper::bendAlongLine2Side(float lineY, float bendfactor) {
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].y != lineY) {
            points[i].z += bendfactor * abs(points[i].y - lineY);

        }
    }
}
void Paper::bendAlongLineLeftSide(float lineY, float bendfactor) {
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].y <= lineY) {
            points[i].z += bendfactor * abs(points[i].y - lineY);

        }
    }
}
void Paper::bendAlongLineRightSide(float lineY, float bendfactor) {
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].y >= lineY) {
            points[i].z += bendfactor * abs(points[i].y - lineY);

        }
    }
}
void Paper::transformToCylinder(float StartY, float EndY, float Radius) {
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].y >= StartY && points[i].y <= EndY) {
            float theta = points[i].y / EndY * PI;
            points[i].x = Radius * cos(theta);
            points[i].z = Radius * sin(theta);
        }
    }
}

std::vector<Point> Paper::getPaperPoints() const {
    return points;
}


