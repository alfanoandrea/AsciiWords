#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <windows.h>

const int dim = 5;


class Color {
public:
	static std::string violet;
	static std::string red;
	static std::string cyan;
	static std::string green;
	static std::string yellow;
	static std::string reset;
};

std::string Color::violet = "\033[35m";
std::string Color::red = "\u001b[31m";
std::string Color::cyan = "\u001b[36m";
std::string Color::green = "\u001b[32m";
std::string Color::yellow = "\u001b[33m";
std::string Color::reset = "\u001b[0m";


struct lettere {
	std::string word[dim];
};


void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


COORD getMaxConsoleCoords() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwMaximumWindowSize;
}


std::string getFrase() {
	std::string fr;
	std::cout << "Inserisci la frase da stampare: ";
	std::getline(std::cin, fr);
	std::cout << "\n\n";
	return fr;
}


int getCarattere(char carattere) {
	for (int i = 48, par = 27; i <= 57; i++) {
		if (i == carattere)
			return par;
		par++;
	}
	carattere = std::toupper(carattere);
	for (int i = 64, par = 0; i <= 90; i++) {
		if (i == carattere)
			return par;
		par++;
	}
	return 0;
}

void selColor() {
	int sel = rand() % 5 + 1;
	if (sel == 1)
		std::cout << Color::cyan;
	else if (sel == 2)
		std::cout << Color::violet;
	else if (sel == 3)
		std::cout << Color::green;
	else if (sel == 4)
		std::cout << Color::red;
	else if (sel == 5)
		std::cout << Color::yellow;
}


void printChar(std::string fr, std::vector<lettere> &alfabeto) {
	COORD maxCoords = getMaxConsoleCoords();
	int x = 0, y = 3, maggiore;
	selColor();
	for (int i = 0; i < fr.length(); i++) {
		if (x >= maxCoords.X - 2) {
			x = 0;
			y += dim + 2;
		}
		maggiore = 0;
		
		for (int j = 0; j < dim; j++) {
			gotoxy(x, j + y);
			if (alfabeto[getCarattere(fr[i])].word[j].length() > maggiore)
				maggiore = alfabeto[getCarattere(fr[i])].word[j].length();
			std::cout << alfabeto[getCarattere(fr[i])].word[j] << '\n';
		}
		x += maggiore + 2;
	}
	std::cout << Color::reset;
}


std::vector<lettere> loadAlfabeto();


int main() {
	srand(time(NULL));
	std::vector<lettere> alfabeto = loadAlfabeto();
	std::string frase = getFrase();
	printChar(frase, alfabeto);
	return 0;
}


std::vector<lettere> loadAlfabeto() {
	std::vector<lettere> alfabeto(37);
	//////////////////////////////
	alfabeto[0].word[0] = "  ";
	alfabeto[0].word[1] = "  ";
	alfabeto[0].word[2] = "  ";  // spazio
	alfabeto[0].word[3] = "  ";
	alfabeto[0].word[4] = "  ";
	//////////////////////////////
	alfabeto[1].word[0] = " AAA ";
	alfabeto[1].word[1] = "A   A";
	alfabeto[1].word[2] = "AAAAA";  // A
	alfabeto[1].word[3] = "A   A";
	alfabeto[1].word[4] = "A   A";
	//////////////////////////////
	alfabeto[2].word[0] = "BBBB ";
	alfabeto[2].word[1] = "B   B";
	alfabeto[2].word[2] = "BBBB ";  // B
	alfabeto[2].word[3] = "B   B";
	alfabeto[2].word[4] = "BBBBB";
	//////////////////////////////
	alfabeto[3].word[0] = " CCCC";
	alfabeto[3].word[1] = "C    ";
	alfabeto[3].word[2] = "C    ";  // C
	alfabeto[3].word[3] = "C    ";
	alfabeto[3].word[4] = " CCCC";
	/////////////////////////////
	alfabeto[4].word[0] = "DDDD ";
	alfabeto[4].word[1] = "D   D";
	alfabeto[4].word[2] = "D   D";  // D
	alfabeto[4].word[3] = "D   D";
	alfabeto[4].word[4] = "DDDD ";
	//////////////////////////////
	alfabeto[5].word[0] = "EEEEE";
	alfabeto[5].word[1] = "E    ";
	alfabeto[5].word[2] = "EEEE ";  // E
	alfabeto[5].word[3] = "E    ";
	alfabeto[5].word[4] = "EEEEE";
	/////////////////////////////
	alfabeto[6].word[0] = "FFFFF";
	alfabeto[6].word[1] = "F    ";
	alfabeto[6].word[2] = "FFFF ";  // F
	alfabeto[6].word[3] = "F    ";
	alfabeto[6].word[4] = "F    ";
	/////////////////////////////
	alfabeto[7].word[0] = " GGGG";
	alfabeto[7].word[1] = "G    ";
	alfabeto[7].word[2] = "G  GG";  // G
	alfabeto[7].word[3] = "G   G";
	alfabeto[7].word[4] = " GGGG";
	/////////////////////////////
	alfabeto[8].word[0] = "H   H";
	alfabeto[8].word[1] = "H   H";
	alfabeto[8].word[2] = "HHHHH";  // H
	alfabeto[8].word[3] = "H   H";
	alfabeto[8].word[4] = "H   H";
	/////////////////////////////
	alfabeto[9].word[0] = "II";
	alfabeto[9].word[1] = "II";
	alfabeto[9].word[2] = "II";    // I
	alfabeto[9].word[3] = "II";
	alfabeto[9].word[4] = "II";
	//////////////////////////////
	alfabeto[10].word[0] = "   JJ";
	alfabeto[10].word[1] = "    J";
	alfabeto[10].word[2] = "    J";  // J
	alfabeto[10].word[3] = "J   J";
	alfabeto[10].word[4] = " JJJ ";
	//////////////////////////////
	alfabeto[11].word[0] = "K   K";
	alfabeto[11].word[1] = "K KK ";
	alfabeto[11].word[2] = "KK   ";  // K
	alfabeto[11].word[3] = "K KK ";
	alfabeto[11].word[4] = "K   K";
	//////////////////////////////
	alfabeto[12].word[0] = "L    ";
	alfabeto[12].word[1] = "L    ";
	alfabeto[12].word[2] = "L    ";  // L
	alfabeto[12].word[3] = "L    ";
	alfabeto[12].word[4] = "LLLLL";
	//////////////////////////////
	alfabeto[13].word[0] = "MM   MM";
	alfabeto[13].word[1] = "M M M M";
	alfabeto[13].word[2] = "M  M  M";  // M
	alfabeto[13].word[3] = "M     M";
	alfabeto[13].word[4] = "M     M";
	//////////////////////////////
	alfabeto[14].word[0] = "N   N";
	alfabeto[14].word[1] = "NN  N";
	alfabeto[14].word[2] = "N N N";  // N
	alfabeto[14].word[3] = "N  NN";
	alfabeto[14].word[4] = "N   N";
	//////////////////////////////
	alfabeto[15].word[0] = " OOO ";
	alfabeto[15].word[1] = "O   O";
	alfabeto[15].word[2] = "O   O";  // O
	alfabeto[15].word[3] = "O   O";
	alfabeto[15].word[4] = " OOO ";
	//////////////////////////////
	alfabeto[16].word[0] = "PPPP ";
	alfabeto[16].word[1] = "P   P";
	alfabeto[16].word[2] = "PPPP ";  // P
	alfabeto[16].word[3] = "P    ";
	alfabeto[16].word[4] = "P    ";
	//////////////////////////////
	alfabeto[17].word[0] = " QQQ ";
	alfabeto[17].word[1] = "Q   Q";
	alfabeto[17].word[2] = "Q Q Q";  // Q
	alfabeto[17].word[3] = " QQQ ";
	alfabeto[17].word[4] = "    Q";
	//////////////////////////////
	alfabeto[18].word[0] = "RRRR ";
	alfabeto[18].word[1] = "R   R";
	alfabeto[18].word[2] = "RRRR ";  // R
	alfabeto[18].word[3] = "R  R ";
	alfabeto[18].word[4] = "R   R";
	//////////////////////////////
	alfabeto[19].word[0] = " SSS";
	alfabeto[19].word[1] = "S   ";
	alfabeto[19].word[2] = " SS ";  // S
	alfabeto[19].word[3] = "   S";
	alfabeto[19].word[4] = "SSS ";
	//////////////////////////////
	alfabeto[20].word[0] = "TTTTTT";
	alfabeto[20].word[1] = "  TT  ";
	alfabeto[20].word[2] = "  TT  ";  // T
	alfabeto[20].word[3] = "  TT  ";
	alfabeto[20].word[4] = "  TT  ";
	//////////////////////////////
	alfabeto[21].word[0] = "U   U";
	alfabeto[21].word[1] = "U   U";
	alfabeto[21].word[2] = "U   U";  // U
	alfabeto[21].word[3] = "U   U";
	alfabeto[21].word[4] = " UUU ";
	//////////////////////////////
	alfabeto[22].word[0] = "V   V";
	alfabeto[22].word[1] = "V   V";
	alfabeto[22].word[2] = "V   V";  // V
	alfabeto[22].word[3] = " V V ";
	alfabeto[22].word[4] = "  V  ";
	//////////////////////////////
	alfabeto[23].word[0] = "W     W";
	alfabeto[23].word[1] = "W     W";
	alfabeto[23].word[2] = "W  W  W";  // W
	alfabeto[23].word[3] = "W W W W";
	alfabeto[23].word[4] = "WW   WW";
	//////////////////////////////
	alfabeto[24].word[0] = "X   X";
	alfabeto[24].word[1] = " X X ";
	alfabeto[24].word[2] = "  X  ";  // X
	alfabeto[24].word[3] = " X X ";
	alfabeto[24].word[4] = "X   X";
	//////////////////////////////
	alfabeto[25].word[0] = "Y   Y";
	alfabeto[25].word[1] = " Y Y ";
	alfabeto[25].word[2] = "  Y  ";  // Y
	alfabeto[25].word[3] = "  Y  ";
	alfabeto[25].word[4] = "  Y  ";
	//////////////////////////////
	alfabeto[26].word[0] = "ZZZZZ";
	alfabeto[26].word[1] = "   Z ";
	alfabeto[26].word[2] = "  Z  ";  // Z
	alfabeto[26].word[3] = " Z   ";
	alfabeto[26].word[4] = "ZZZZZ";
	//////////////////////////////
	alfabeto[27].word[0] = " 000 ";
	alfabeto[27].word[1] = "0  00";
	alfabeto[27].word[2] = "0 0 0";  // 0
	alfabeto[27].word[3] = "00  0";
	alfabeto[27].word[4] = " 000 ";
	//////////////////////////////
	alfabeto[28].word[0] = "  11 ";
	alfabeto[28].word[1] = "1111 ";
	alfabeto[28].word[2] = "  11 ";  // 1
	alfabeto[28].word[3] = "  11 ";
	alfabeto[28].word[4] = "11111";
	//////////////////////////////
	alfabeto[29].word[0] = " 222 ";
	alfabeto[29].word[1] = "2   2";
	alfabeto[29].word[2] = "  22 ";  // 2
	alfabeto[29].word[3] = " 22  ";
	alfabeto[29].word[4] = "22222";
	//////////////////////////////
	alfabeto[30].word[0] = "3333 ";
	alfabeto[30].word[1] = "    3";
	alfabeto[30].word[2] = " 333 ";  // 3
	alfabeto[30].word[3] = "    3";
	alfabeto[30].word[4] = "3333 ";
	//////////////////////////////
	alfabeto[31].word[0] = "  4  ";
	alfabeto[31].word[1] = " 4   ";
	alfabeto[31].word[2] = "4  4 ";  // 4
	alfabeto[31].word[3] = "44444";
	alfabeto[31].word[4] = "   4 ";
	//////////////////////////////
	alfabeto[32].word[0] = "55555";
	alfabeto[32].word[1] = "5    ";
	alfabeto[32].word[2] = "5555 ";  // 5
	alfabeto[32].word[3] = "    5";
	alfabeto[32].word[4] = "5555 ";
	//////////////////////////////
	alfabeto[33].word[0] = " 6666";
	alfabeto[33].word[1] = "6    ";
	alfabeto[33].word[2] = "6666 ";  // 6
	alfabeto[33].word[3] = "6   6";
	alfabeto[33].word[4] = " 666 ";
	//////////////////////////////
	alfabeto[34].word[0] = "77777";
	alfabeto[34].word[1] = "   7 ";
	alfabeto[34].word[2] = " 777 ";  // 7
	alfabeto[34].word[3] = " 7   ";
	alfabeto[34].word[4] = "7    ";
	//////////////////////////////
	alfabeto[35].word[0] = " 888 ";
	alfabeto[35].word[1] = "8   8";
	alfabeto[35].word[2] = " 888 ";  // 8
	alfabeto[35].word[3] = "8   8";
	alfabeto[35].word[4] = " 888 ";
	//////////////////////////////
	alfabeto[36].word[0] = " 999 ";
	alfabeto[36].word[1] = "9   9";
	alfabeto[36].word[2] = " 9999";  // 9
	alfabeto[36].word[3] = "    9";
	alfabeto[36].word[4] = "9999 ";
	//////////////////////////////
	return alfabeto;
}
