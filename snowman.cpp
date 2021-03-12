#include <cstring>
#include "snowman.hpp"

using namespace std;

namespace ariel
{
    string str;

    string hat(char tav)
    {
        switch (tav)
        {
        case '1': // Straw Hat
            return "_===_";
            break;

        case '2': // Mexican Hat
            return " ___\n.....";
            break;

        case '3': // Fez
            return "  _  \n /_\\ ";
            break;

        case '4': // Russian Hat
            return " ___ \n(_*_)";
            break;

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
            break;
        }
    }

    string nose(char tav)
    {
        switch (tav)
        {
        case '1': // Normal
            return ",";
            break;

        case '2': // Dot
            return ".";
            break;

        case '3': // Line
            return "_";
            break;

        case '4': // None
            return "";
            break;

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
            break;
        }
    }

    string left_and_right_eye(char tav)
    {
        switch (tav)
        {
        case '1': // Dot
            return ".";
            break;

        case '2': // Bigger Dot
            return "o";
            break;

        case '3': // Biggest Dot
            return "O";
            break;

        case '4': // Closed
            return "-";
            break;

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
            break;
        }
    }

    string left_arm(char tav)
    {
        switch (tav)
        {
        case '1': // Normal Arm
            return "<";
            break;

        case '2': // Upwards Arm
            return "\\";
            break;

        case '3': // Downwards Arm
            return "/";
            break;

        case '4': // None
            return "";
            break;

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
            break;
        }
    }

    string right_arm(char tav)
    {
        switch (tav)
        {
        case '1': // Normal Arm
            return ">";
            break;

        case '2': // Upwards Arm
            return "/";
            break;

        case '3': // Downwards Arm
            return "\\";
            break;

        case '4': // None
            return "";
            break;

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
            break;
        }
    }

    string torso(char tav)
    {
        switch (tav)
        {
        case '1': // Buttons
            return " : ";
            break;

        case '2': // Vest
            return "] [";
            break;

        case '3': // Inward Arms
            return "> <";
            break;

        case '4': // None
            return "   ";
            break;

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
            break;
        }
    }

    string base(char tav)
    {
        switch (tav)
        {
        case '1': // Buttons
            return " : ";
            break;

        case '2': // Feet
            return "\" \"";
            break;

        case '3': // Flat
            return "___";
            break;

        case '4': // None
            return "   ";
            break;

        default:
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
            break;
        }
    }

    string *set_body()
    {
        string *ans = new string[8];
        ans[0] = hat(str.at(0));
        ans[1] = nose(str.at(1));
        ans[2] = left_and_right_eye(str.at(2));
        ans[3] = left_and_right_eye(str.at(3));
        ans[4] = left_arm(str.at(4));
        ans[5] = right_arm(str.at(5));
        ans[6] = torso(str.at(6));
        ans[7] = base(str.at(7)) return ans;
    }

    string snowman(int num)
    {
        str = to_string(num);
        int str_size = str.size();
        const int right_size = 8;

        string ans;

        if (str_size > right_size || str_size < right_size)
        {
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
        string *body = set_body();
        ans = body[0] + "\n";
        string part_1;
        string part_2;
        if (str.at(4) == '2')
        {
            part_1 = body[4] + "(" + body[3] + body[2] + body[4] + ")";
            part_2 = " " + "(" + body[6] + ")";
        }
        else
        {
            part_1 = " " + "(" + body[3] + body[2] + body[4] + ")";
            part_2 = body[4] + "(" + body[6] + ")";
        }
        if (str.at(5) == '2')
        {
            part_1 = part_1 + body[5];
        }
        else
        {
            part_2 = part_2 + body[5];
        }
        ans = ans + part_1 + "\n" + part_2 + "\n";
        ans = ans + "(" + body[7] + ")";

        return ans;
    }

}