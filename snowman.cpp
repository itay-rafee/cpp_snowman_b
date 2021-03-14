#include <iostream>
#include <array>
#include "snowman.hpp"

using namespace std;
constexpr int LEN_LEGAL = 8;
constexpr int BASE = 7;
constexpr int TORSO = 6;
constexpr int RIGHT_ARM = 5;
constexpr int LEFT_ARM = 4;
constexpr int RIGHT_EYE = 3;
constexpr int LEFT_EYE = 2;
constexpr int NOSE = 1;
constexpr int HAT = 0;

namespace ariel
{
    string str;

    string hat(char tav)
    {
        switch (tav)
        {
        case '1': // Straw Hat
            return "_===_";

        case '2': // Mexican Hat
            return " ___\n .....";

        case '3': // Fez
            return "  _  \n  /_\\ ";

        case '4': // Russian Hat
            return " ___ \n (_*_)";

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
    }

    string nose(char tav)
    {
        switch (tav)
        {
        case '1': // Normal
            return ",";

        case '2': // Dot
            return ".";

        case '3': // Line
            return "_";

        case '4': // None
            return " ";

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
    }

    string left_and_right_eye(char tav)
    {
        switch (tav)
        {
        case '1': // Dot
            return ".";

        case '2': // Bigger Dot
            return "o";

        case '3': // Biggest Dot
            return "O";

        case '4': // Closed
            return "-";

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
    }

    string left_arm(char tav)
    {
        switch (tav)
        {
        case '1': // Normal Arm
            return "<";

        case '2': // Upwards Arm
            return "\\";

        case '3': // Downwards Arm
            return "/";

        case '4': // None
            return " ";

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
    }

    string right_arm(char tav)
    {
        switch (tav)
        {
        case '1': // Normal Arm
            return ">";

        case '2': // Upwards Arm
            return "/";

        case '3': // Downwards Arm
            return "\\";

        case '4': // None
            return "";

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
    }

    string torso(char tav)
    {
        switch (tav)
        {
        case '1': // Buttons
            return " : ";

        case '2': // Vest
            return "] [";

        case '3': // Inward Arms
            return "> <";

        case '4': // None
            return "   ";

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
    }

    string base(char tav)
    {
        switch (tav)
        {
        case '1': // Buttons
            return " : ";

        case '2': // Feet
            return "\" \"";

        case '3': // Flat
            return "___";

        case '4': // None
            return "   ";

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
    }

    array<string, LEN_LEGAL> set_body()
    {
        array<string, LEN_LEGAL> ans;
        ans[HAT] = hat(str.at(HAT));
        ans[NOSE] = nose(str.at(NOSE));
        ans[LEFT_EYE] = left_and_right_eye(str.at(LEFT_EYE));
        ans[RIGHT_EYE] = left_and_right_eye(str.at(RIGHT_EYE));
        ans[LEFT_ARM] = left_arm(str.at(LEFT_ARM));
        ans[RIGHT_ARM] = right_arm(str.at(RIGHT_ARM));
        ans[TORSO] = torso(str.at(TORSO));
        ans[BASE] = base(str.at(BASE));
        return ans;
    }

    string snowman(int num)
    {
        str = to_string(num);
        int str_size = str.size();

        string ans;

        if (str_size > LEN_LEGAL || str_size < LEN_LEGAL)
        {
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
        array<string, LEN_LEGAL> body = set_body();
        ans = string(" ") + body[HAT] + "\n";
        string part_1;
        string part_2;
        if (str.at(LEFT_ARM) == '2')
        {
            part_1 = body[LEFT_ARM] + "(" + body[LEFT_EYE] + body[NOSE] + body[RIGHT_EYE] + ")";
            part_2 = string(" ") + "(" + body[TORSO] + ")";
        }
        else
        {
            part_1 = string(" ") + "(" + body[LEFT_EYE] + body[NOSE] + body[RIGHT_EYE] + ")";
            part_2 = body[LEFT_ARM] + "(" + body[TORSO] + ")";
        }
        if (str.at(RIGHT_ARM) == '2')
        {
            part_1 = part_1 + body[RIGHT_ARM];
        }
        else
        {
            part_2 = part_2 + body[RIGHT_ARM];
        }
        ans = ans + part_1 + "\n" + part_2 + "\n";
        ans = ans + " (" + body[BASE] + ")";

        return ans;
    }

}