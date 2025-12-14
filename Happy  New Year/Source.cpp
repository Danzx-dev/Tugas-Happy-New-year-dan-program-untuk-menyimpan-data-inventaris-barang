#include <iostream>
#include <string>
#include <vector>
#include <windows.h> 
#include <conio.h>   

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


const char BLOCK_CHAR = (char)178;

const std::vector<std::string> MAP_2 = {
    "11111",
    "00001",
    "11111",
    "10000",
    "11111"
};

const std::vector<std::string> MAP_0 = {
    "11111",
    "10001",
    "10001",
    "10001",
    "11111"
};

const std::vector<std::string> MAP_6 = {
    "11111",
    "10000",
    "11111",
    "10001",
    "11111"
};


void display_digit(const std::vector<std::string>& digit_map, int start_x, int start_y) {
    for (size_t i = 0; i < digit_map.size(); ++i) {
        gotoxy(start_x, start_y + i);
        for (char c : digit_map[i]) {
            if (c == '0') {
                std::cout << ' '; 
            }
            else {
                std::cout << BLOCK_CHAR; 
            }
        }
    }
}


void display_animated_text(const std::string& text, int x, int y, int delay_ms) {
    gotoxy(x, y);
    for (char c : text) {
        std::cout << c;
        Sleep(delay_ms);
    }
}

int main() {
   
    SetConsoleTitle(L"Happy New Year 2026");

   
    system("cls");

   
    const int TEXT_X = 1;
    const int TEXT_Y = 1;

   
    display_animated_text("Happy New Year", TEXT_X, TEXT_Y, 250); 

    
    Sleep(500);

    
    const int DIGIT_START_X = 2;
    const int DIGIT_START_Y = 3;
    const int DIGIT_WIDTH = 6; 

    
    display_digit(MAP_2, DIGIT_START_X, DIGIT_START_Y);
    display_digit(MAP_0, DIGIT_START_X + DIGIT_WIDTH, DIGIT_START_Y);
    display_digit(MAP_2, DIGIT_START_X + 2 * DIGIT_WIDTH, DIGIT_START_Y);
    display_digit(MAP_6, DIGIT_START_X + 3 * DIGIT_WIDTH, DIGIT_START_Y);

    
    Sleep(500);

    
    const int PROMPT_Y = DIGIT_START_Y + 7; 
    display_animated_text("Press any key to continue . . .", TEXT_X, PROMPT_Y, 100);


    _getch();

    system("cls");

    return 0;
}