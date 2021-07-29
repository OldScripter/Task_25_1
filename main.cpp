#include <iostream>
#include "surgery.h"

int main() {
    //Storing start and finish points:
    Point startPoint = Point(0, 0);
    Point endPoint = Point(0, 0);

    //Temporary storing of current points and commands:
    Point point_1 = Point(0, 0);
    Point point_2 = Point(0, 0);
    std::string cmd;

    do
    {
        std::cout << "Please enter the command: ";
        std::string input;
        std::getline(std::cin, input);
        getCommand(input, cmd, point_1, point_2);
        if (cmd == "scalpel")
        {
            startPoint = point_1;
            endPoint = point_2;
        }
        else if (cmd == "suture")
        {
            if (point_1 == startPoint && point_2 == endPoint)
            {
                std::cout << "Surgery is finished.\n";
                break;
            }
        }
    } while (true);
    return 0;
}