#ifndef TASK_25_1_SURGERY_H
#define TASK_25_1_SURGERY_H

#include <iostream>
#include <sstream>

struct Point
{
    int x;
    int y;

    explicit Point(const int& x = 0, const int& y = 0)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(const Point& p1) const
    {
        return (x == p1.x && y == p1.y);
    }

    void setPoint(const int& valueX, const int& valueY)
    {
        x = valueX;
        y = valueY;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    std::string getPointCoords() const
    {
        return (std::to_string(x) + " : " + std::to_string(y));
    }
};

void scalpel(const Point& start, const Point& finish)
{
    std::cout << "SCALPEL: cut is done between " << start.getPointCoords() << " and " << finish.getPointCoords() << "\n";
}

void hemostat(const Point& point)
{
    std::cout << "HEMOSTAT: is applied in " << point.getPointCoords() << "\n";
}

void tweezers(const Point& point)
{
    std::cout << "TWEEZERS: are applied in " << point.getPointCoords() << "\n";
}

void suture(const Point& start, const Point& finish)
{
    std::cout << "SUTURE: seam is made from " << start.getPointCoords() << " to " << finish.getPointCoords() << "\n";
}

/**
 * @function Process the user input for surgery.
 * @param input String to be processed.
 * @param [out] cmd link to String cmd.
 * @param [out] start link to Point.
 * @param [out] finish link to Point.
 */
void getCommand(std::string& input, std::string& cmd, Point& start, Point& finish)
{
    std::stringstream stream (input);
    std::string command;
    int startX = 0;
    int startY = 0;
    int endX = 0;
    int endY = 0;
    std::string buffer;


    stream >> command >>  startX >> startY >> endX >> endY;
    cmd = command;
    Point p1 (startX, startY);
    Point p2 (endX, endY);
    start = p1;
    finish = p2;

    if (command == "scalpel")
    {
        scalpel(p1, p2);
    }
    else if (command == "hemostat")
    {
        hemostat(p1);
    }
    else if (command == "tweezers")
    {
        tweezers(p1);
    }
    else if (command == "suture")
    {
        suture(p1, p2);
    }
}

#endif //TASK_25_1_SURGERY_H
