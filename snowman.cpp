#include <iostream>
#include <array>
#include "snowman.hpp"

using namespace std;

//number of the part body in the string number
constexpr int len_legal = 8;
constexpr int base_num = 7;
constexpr int torso_num = 6;
constexpr int right_arm_num = 5;
constexpr int left_arm_num = 4;
constexpr int right_eye_num = 3;
constexpr int left_eye_num = 2;
constexpr int nose_num = 1;
constexpr int hat_num = 0;

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

    // set the body of the snowman
    array<string, len_legal> set_body()
    {
        array<string, len_legal> ans;
        ans[hat_num] = hat(str.at(hat_num));
        ans[nose_num] = nose(str.at(nose_num));
        ans[left_eye_num] = left_and_right_eye(str.at(left_eye_num));
        ans[right_eye_num] = left_and_right_eye(str.at(right_eye_num));
        ans[left_arm_num] = left_arm(str.at(left_arm_num));
        ans[right_arm_num] = right_arm(str.at(right_arm_num));
        ans[torso_num] = torso(str.at(torso_num));
        ans[base_num] = base(str.at(base_num));
        return ans;
    }

    string snowman(int num)
    {
        str = to_string(num);
        int str_size = str.size();

        string ans;

        // if the number bigger or smaller then 8
        if (str_size > len_legal || str_size < len_legal)
        {
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }

        array<string, len_legal> body = set_body();
        ans = string(" ") + body[hat_num] + "\n";
        string part_1;
        string part_2;
        // while the left arm is up
        if (str.at(left_arm_num) == '2')
        {
            part_1 = body[left_arm_num] + "(" + body[left_eye_num] + body[nose_num] + body[right_eye_num] + ")";
            part_2 = string(" ") + "(" + body[torso_num] + ")";
        }
        // while the left arm is down
        else
        {
            part_1 = string(" ") + "(" + body[left_eye_num] + body[nose_num] + body[right_eye_num] + ")";
            part_2 = body[left_arm_num] + "(" + body[torso_num] + ")";
        }
        // while the right arm is up
        if (str.at(right_arm_num) == '2')
        {
            part_1 = part_1 + body[right_arm_num];
        }
        // while the right arm is down
        else
        {
            part_2 = part_2 + body[right_arm_num];
        }
        ans = ans + part_1 + "\n" + part_2 + "\n";
        ans = ans + " (" + body[base_num] + ")";

        return ans;
    }

}