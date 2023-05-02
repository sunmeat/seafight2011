#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int pole[10][10], mypole[10][10], x, y, ud[2], hod[1], i, j, m, k;
//pole - поле соперника
//mypole - моё поле
//x y - координаты
//ud[2] - удар
//hod[1]- ход
//i j m k - 
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //дескриптор окна
int ui; //для менюшки
char s1[256]; //для русской кодировки

void GotoXY(int X, int Y) { // координаты для курсора
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

void SetColor(int text, int background) { //задание цвета тексту
	SetConsoleTextAttribute(hStdOut, background * 16 + text);
}

char* Rus(const char* s2) {   //смена кодировки для текста
	AnsiToOem(s2, s1);
	return s1;
}

void GAMEOVER(int chislomy, int chislocomp) { //результаты
	SetColor(0, 0);
	system("cls");
	if (chislocomp == 20) {
		GotoXY(33, 14);
		SetColor(0, 12);
		cout << Rus("Вы проиграли");
		_getch();
	}
	if (chislomy == 20) {
		GotoXY(33, 14);
		SetColor(0, 12);
		cout << Rus("Вы выиграли!");
		_getch();
	}
}

void DRAWRAM() { // прорисовка рамки
	SetColor(15, 0); // с кодами символов белая рамка, нумерация и республика
	cout << "\xC9\xCD\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "1\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "2\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "3\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "4\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "5\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "6\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "7\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "8\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "9\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "10\n";
	cout << "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n";
	cout << Rus("  Р Е С П У Б Л И К А\n");

	GotoXY(40, 0); cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n";
	GotoXY(40, 1); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "1\n";
	GotoXY(40, 2); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 3); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "2\n";
	GotoXY(40, 4); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 5); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "3\n";
	GotoXY(40, 6); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 7); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "4\n";
	GotoXY(40, 8); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 9); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "5\n";
	GotoXY(40, 10); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 11); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "6\n";
	GotoXY(40, 12); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 13); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "7\n";
	GotoXY(40, 14); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 15); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "8\n";
	GotoXY(40, 16); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 17); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "9\n";
	GotoXY(40, 18); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 19); cout << "\xba"; cout << "\t\t     "; cout << "\xba" << "10\n";
	GotoXY(40, 20); cout << "\xba"; cout << "\t\t     "; cout << "\xba\n";
	GotoXY(40, 21); cout << "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n";
	GotoXY(40, 22); cout << Rus("  Р Е С П У Б Л И К А\n");
}

int sheeps(int pole[10][10]) { // рандомная растановка короблей, заполнение массива кораблями
	int i, j, f, k, rand_chislo, rand_chislo1, ts; // ts - направление
	// i,j,f,k - типа счётчики, служебные переменные для работы))
	srand(time(NULL));
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			pole[i][j] = 0; //изначально пустое поле
	//ставим 4палубы
	do {
		f = 0; //"флажок" есть ошибки или нет
		rand_chislo = 0 + rand() % 10;
		rand_chislo1 = 0 + rand() % 10;
		ts = 1 + rand() % 4; // возможные положения
		//проверки на стены
		if (ts == 1) {
			for (i = 0; i < 3; i++)
				if (rand_chislo == i) f = 1;
		}
		if (ts == 2) {
			for (i = 7; i < 10; i++)
				if (rand_chislo == i) f = 1;
		}
		if (ts == 3) {
			for (i = 0; i < 3; i++)
				if (rand_chislo1 == i) f = 1;
		}
		if (ts == 4) {
			for (i = 7; i < 10; i++)
				if (rand_chislo1 == i) f = 1;
		}
	} while (f == 1);
	switch (ts) { // выставление корабля
	case 1:
		pole[rand_chislo][rand_chislo1] = 1;
		pole[rand_chislo - 1][rand_chislo1] = 1;
		pole[rand_chislo - 2][rand_chislo1] = 1;
		pole[rand_chislo - 3][rand_chislo1] = 1;
		break;
	case 2:
		pole[rand_chislo][rand_chislo1] = 1;
		pole[rand_chislo + 1][rand_chislo1] = 1;
		pole[rand_chislo + 2][rand_chislo1] = 1;
		pole[rand_chislo + 3][rand_chislo1] = 1;
		break;
	case 3:
		pole[rand_chislo][rand_chislo1] = 1;
		pole[rand_chislo][rand_chislo1 - 1] = 1;
		pole[rand_chislo][rand_chislo1 - 2] = 1;
		pole[rand_chislo][rand_chislo1 - 3] = 1;
		break;
	case 4:
		pole[rand_chislo][rand_chislo1] = 1;
		pole[rand_chislo][rand_chislo1 + 1] = 1;
		pole[rand_chislo][rand_chislo1 + 2] = 1;
		pole[rand_chislo][rand_chislo1 + 3] = 1;
		break;
	}
	//выставление 2 палубы в колве 3 шт
	for (k = 0; k < 3; k++) {
		do {
			f = 0;
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;
			ts = 1 + rand() % 4;
			if (ts == 1) {
				if (rand_chislo != 0) {
					for (i = rand_chislo - 2; i < rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else f = 1;
			}
			if (ts == 2) {
				if (rand_chislo != 9) {
					for (i = rand_chislo - 1; i <= rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else f = 1;
			}
			if (ts == 3) {
				if (rand_chislo1 != 0) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 2; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else f = 1;
			}
			if (ts == 4) {
				if (rand_chislo1 != 9) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 2; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else f = 1;
			}
		} while (f == 1);
		switch (ts) {
		case 1:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo - 1][rand_chislo1] = 1;
			break;
		case 2:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo + 1][rand_chislo1] = 1;
			break;
		case 3:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 - 1] = 1;
			break;
		case 4:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 + 1] = 1;
			break;
		}
	}
	//3палубы 2корабля
	for (k = 0; k < 2; k++) {
		do {
			f = 0;
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;
			ts = 1 + rand() % 4;

			if (ts == 1) {
				if (rand_chislo != 0 && rand_chislo != 1) {
					for (i = rand_chislo - 3; i < rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else f = 1;
			}
			if (ts == 2) {
				if (rand_chislo != 9 && rand_chislo != 8) {
					for (i = rand_chislo - 1; i <= rand_chislo + 3; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else f = 1;
			}
			if (ts == 3) {
				if (rand_chislo1 != 0 && rand_chislo1 != 1) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 3; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else f = 1;
			}
			if (ts == 4) {
				if (rand_chislo1 != 9 && rand_chislo1 != 8) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 3; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else f = 1;
			}
		} while (f == 1);
		switch (ts) {
		case 1:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo - 1][rand_chislo1] = 1;
			pole[rand_chislo - 2][rand_chislo1] = 1;
			break;
		case 2:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo + 1][rand_chislo1] = 1;
			pole[rand_chislo + 2][rand_chislo1] = 1;
			break;
		case 3:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 - 1] = 1;
			pole[rand_chislo][rand_chislo1 - 2] = 1;
			break;
		case 4:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 + 1] = 1;
			pole[rand_chislo][rand_chislo1 + 2] = 1;
			break;
		}
	}
	// 1палуба 4 штуки
	for (i = 0; i < 4; i++) {
		do {
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;
		} while (pole[rand_chislo][rand_chislo1] != 0 || pole[rand_chislo + 1][rand_chislo1] != 0 || pole[rand_chislo - 1][rand_chislo1] != 0 || pole[rand_chislo][rand_chislo1 + 1] != 0 || pole[rand_chislo][rand_chislo1 - 1] != 0 || pole[rand_chislo + 1][rand_chislo1 + 1] != 0 || pole[rand_chislo - 1][rand_chislo1 - 1] != 0 || pole[rand_chislo + 1][rand_chislo1 - 1] != 0 || pole[rand_chislo - 1][rand_chislo1 + 1] != 0);
		pole[rand_chislo][rand_chislo1] = 1;
	}
	return pole[10][10];
}

int ras(int mypole[10][10]) { //расстановка вручную
	system("cls");
	int i, j, x, y, u, f, e, w, nap, ui;
	DRAWRAM();
	for (i = 0, x = 1; i < 10, x < 21; i++, x = x + 2) { // отрисовка поля, 1 ячейка занимает 4 клетки
		for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
			//по цветам)) голубенький и синий))
			GotoXY(x, y);
			if ((j + i) % 2 != 0) {
				SetColor(0, 1);
				cout << "  ";
			}
			else {
				SetColor(0, 9);
				cout << "  ";
			}

			GotoXY(x, y + 1);
			if ((j + i) % 2 != 0) {
				SetColor(0, 1);
				cout << "  ";
			}
			else {
				SetColor(0, 9);
				cout << "  ";
			}
		}
	}
	//поле изначально пустое
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			mypole[i][j] = 0;
	}

	GotoXY(25, 7); SetColor(15, 0); cout << Rus("поворот-space");
	GotoXY(25, 8); SetColor(15, 0); cout << Rus("принять-enter");
	GotoXY(26, 9); SetColor(15, 0); cout << Rus("в меню-Esc");

	ui = 0; //менюшка
	for (u = 1; u < 5; u++) {
		if (ui == 0) //
			for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2) {
				for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
					GotoXY(x, y);
					if (mypole[i][j] == 1) {
						SetColor(0, 12);
						cout << "  ";
					}
					else {
						if ((j + i) % 2 != 0) {
							SetColor(0, 1);
							cout << "  ";
						}
						else {
							SetColor(0, 9);
							cout << "  ";
						}
					}

					GotoXY(x, y + 1);
					if (mypole[i][j] == 1) {
						SetColor(0, 12);
						cout << "  ";
					}
					else {
						if ((j + i) % 2 != 0) {
							SetColor(0, 1);
							cout << "  ";
						}
						else {
							SetColor(0, 9);
							cout << "  ";
						}
					}
				}
			}
		switch (u) {
		case 1: {
			x = 41;
			y = nap = 1;
			i = j = 0;
			for (e = x; e < x + 8; e = e + 2) {
				GotoXY(e, y);
				SetColor(0, 14);
				cout << "  ";

				GotoXY(e, y + 1);
				SetColor(0, 14);
				cout << "  ";
			}

			do {
				f = 0;
				int code = _getch();
				if (code == 224) {
					code = _getch();
					switch (code) {
					case 72: {
						if (y != 1) {
							if (nap == 1) {
								for (e = x; e < x + 8; e = e + 2) {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}

									GotoXY(e, y + 1);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}
								}
								y = y - 2;
								for (e = x; e < x + 8; e = e + 2) {
									GotoXY(e, y);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(e, y + 1);
									SetColor(0, 14);
									cout << "  ";
								}
							}
							else {
								if (y != 33) {
									for (e = y; e < y + 8; e = e + 2) {
										i = (x - 40) / 2;
										j = e / 2;

										GotoXY(x, e);
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}

										GotoXY(x, e + 1);
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}
									y = y - 2;
									for (e = y; e < y + 8; e = e + 2) {
										GotoXY(x, e);
										SetColor(0, 14);
										cout << "  ";

										GotoXY(x, e + 1);
										SetColor(0, 14);
										cout << "  ";
									}
								}
							}

						}
						break;
					}

					case 77: {
						if (nap == 1) {
							if (x != 53) {
								for (e = x; e < x + 8; e = e + 2) {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}

									GotoXY(e, y + 1);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}
								}
								x = x + 2;
								for (e = x; e < x + 8; e = e + 2) {
									GotoXY(e, y);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(e, y + 1);
									SetColor(0, 14);
									cout << "  ";
								}
							}
						}
						else {
							if (x != 59) {
								for (e = y; e < y + 8; e = e + 2) {
									i = (x - 40) / 2;
									j = e / 2;
									GotoXY(x, e);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}

									GotoXY(x, e + 1);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}
								}
								x = x + 2;
								for (e = y; e < y + 8; e = e + 2) {
									GotoXY(x, e);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(x, e + 1);
									SetColor(0, 14);
									cout << "  ";
								}
							}
						}
						break;
					}

					case 80: {
						if (nap == 1) {
							if (y != 19) {
								for (e = x; e < x + 8; e = e + 2) {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}

									GotoXY(e, y + 1);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}
								}
								y = y + 2;
								for (e = x; e < x + 8; e = e + 2) {
									GotoXY(e, y);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(e, y + 1);
									SetColor(0, 14);
									cout << "  ";
								}
							}
						}
						else {
							if (y != 13) {
								for (e = y; e < y + 8; e = e + 2) {
									i = (x - 40) / 2;
									j = e / 2;
									GotoXY(x, e);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}

									GotoXY(x, e + 1);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}
								}
								y = y + 2;
								for (e = y; e < y + 8; e = e + 2) {
									GotoXY(x, e);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(x, e + 1);
									SetColor(0, 14);
									cout << "  ";
								}
							}
						}
						break;
					}

					case 75: {
						if (nap == 1) {
							if (x != 41) {
								for (e = x; e < x + 8; e = e + 2) {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}

									GotoXY(e, y + 1);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}
								}
								x = x - 2;
								for (e = x; e < x + 8; e = e + 2) {
									GotoXY(e, y);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(e, y + 1);
									SetColor(0, 14);
									cout << "  ";
								}
							}
						}
						else {
							if (x != 41) {
								for (e = y; e < y + 8; e = e + 2) {
									i = (x - 40) / 2;
									j = e / 2;
									GotoXY(x, e);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}

									GotoXY(x, e + 1);
									if ((i + j) % 2 != 0) {
										SetColor(0, 1);
										cout << "  ";
									}
									else {
										SetColor(0, 9);
										cout << "  ";
									}
								}
								x = x - 2;
								for (e = y; e < y + 8; e = e + 2) {
									GotoXY(x, e);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(x, e + 1);
									SetColor(0, 14);
									cout << "  ";
								}
							}
						}
						break;
					}
					}
				}

				else {
					switch (code) {
					case 32: {
						if (nap == 1 && y < 15 || nap == -1 && x < 55) {
							nap = nap * (-1);
							if (nap == 1) {
								for (e = y; e < y + 8; e = e + 2) {
									i = (x - 40) / 2;
									j = e / 2;
									GotoXY(x, e);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									GotoXY(x, e + 1);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}
								}

								for (e = x; e < x + 8; e = e + 2) {
									GotoXY(e, y);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(e, y + 1);
									SetColor(0, 14);
									cout << "  ";
								}

							}
							else {
								for (e = x; e < x + 8; e = e + 2) {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									GotoXY(e, y + 1);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}
								}

								for (e = y; e < y + 8; e = e + 2) {
									GotoXY(x, e);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(x, e + 1);
									SetColor(0, 14);
									cout << "  ";
								}
							}
						}
						break;
					}

					case 13: {
						if (nap == 1) {
							for (e = x; e < x + 8; e = e + 2) {
								i = (e - 40) / 2;
								j = y / 2;
								mypole[i][j] = 1;
							}

						}
						else {
							for (e = y; e < y + 8; e = e + 2) {
								i = (x - 40) / 2;
								j = e / 2;
								mypole[i][j] = 1;
							}
						}
						f = 1;
						break;
					}
					case 27: {
						f = 1;
						ui = 1;
						break;
					}
					}
				}
			} while (f != 1);
			break;
		}

		case 2: {
			for (w = 0; w < 2; w++)
				if (ui == 0) {
					for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
						for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
							GotoXY(x, y);
							if (mypole[i][j] == 1) {
								SetColor(0, 12);
								cout << "  ";
							}
							else {
								if ((j + i) % 2 != 0) {
									SetColor(0, 1);
									cout << "  ";
								}
								else {
									SetColor(0, 9);
									cout << "  ";
								}
							}

							GotoXY(x, y + 1);
							if (mypole[i][j] == 1) {
								SetColor(0, 12);
								cout << "  ";
							}
							else {
								if ((j + i) % 2 != 0) {
									SetColor(0, 1);
									cout << "  ";
								}
								else {
									SetColor(0, 9);
									cout << "  ";
								}
							}
						}
					x = 41;
					y = nap = 1;
					i = j = 0;
					for (e = x; e < x + 6; e = e + 2) {
						GotoXY(e, y);
						SetColor(0, 14);
						cout << "  ";

						GotoXY(e, y + 1);
						SetColor(0, 14);
						cout << "  ";
					}
					do {
						f = 0;
						int code = _getch();
						if (code == 224) {
							code = _getch();
							switch (code) {
							case 72: {
								if (y != 1) {
									if (nap == 1) {
										for (e = x; e < x + 6; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										y = y - 2;
										for (e = x; e < x + 6; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
									else {
										if (y != 33) {
											for (e = y; e < y + 6; e = e + 2) {
												i = (x - 40) / 2;
												j = e / 2;
												GotoXY(x, e);
												if (mypole[i][j] == 1) {
													SetColor(0, 12);
													cout << "  ";
												}
												else {
													if ((i + j) % 2 != 0) {
														SetColor(0, 1);
														cout << "  ";
													}
													else {
														SetColor(0, 9);
														cout << "  ";
													}
												}

												GotoXY(x, e + 1);
												if (mypole[i][j] == 1) {
													SetColor(0, 12);
													cout << "  ";
												}
												else {
													if ((i + j) % 2 != 0) {
														SetColor(0, 1);
														cout << "  ";
													}
													else {
														SetColor(0, 9);
														cout << "  ";
													}
												}
											}
											y = y - 2;
											for (e = y; e < y + 6; e = e + 2) {
												GotoXY(x, e);
												SetColor(0, 14);
												cout << "  ";

												GotoXY(x, e + 1);
												SetColor(0, 14);
												cout << "  ";
											}
										}
									}
								}
								break;
							}

							case 77: {
								if (nap == 1) {
									if (x != 55) {
										for (e = x; e < x + 6; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										x = x + 2;
										for (e = x; e < x + 6; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								else {
									if (x != 59) {
										for (e = y; e < y + 6; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(x, e + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										x = x + 2;
										for (e = y; e < y + 6; e = e + 2) {
											GotoXY(x, e);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(x, e + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								break;
							}

							case 80: {
								if (nap == 1) {
									if (y != 19) {
										for (e = x; e < x + 6; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										y = y + 2;
										for (e = x; e < x + 6; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								else {
									if (y != 15) {
										for (e = y; e < y + 6; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(x, e + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										y = y + 2;
										for (e = y; e < y + 6; e = e + 2) {
											GotoXY(x, e);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(x, e + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								break;
							}

							case 75: {
								if (nap == 1) {
									if (x != 41) {
										for (e = x; e < x + 6; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										x = x - 2;
										for (e = x; e < x + 6; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								else {
									if (x != 41) {
										for (e = y; e < y + 6; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(x, e + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										x = x - 2;
										for (e = y; e < y + 6; e = e + 2) {
											GotoXY(x, e);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(x, e + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								break;
							}
							}
						}
						else {
							switch (code) {
							case 32: {
								if (nap == 1 && y < 17 || nap == -1 && x < 57) {
									nap = nap * (-1);
									if (nap == 1) {
										for (e = y; e < y + 6; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(x, e + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}

										for (e = x; e < x + 6; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
									else {
										for (e = x; e < x + 6; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}

										for (e = y; e < y + 6; e = e + 2) {
											GotoXY(x, e);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(x, e + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								break;
							}

							case 13: {
								int pr = f = 0;
								if (nap == 1) {
									for (e = x - 2; e <= x + 6; e = e + 2)
										for (int a = y - 2; a <= y + 2; a = a + 2) {
											i = (e - 40) / 2;
											j = a / 2;
											if (i < 10 && j < 10 && mypole[i][j] == 1)
												pr = 1;
										}
									if (pr == 0)
										for (e = x; e < x + 6; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											mypole[i][j] = 1;
											f = 1;
										}
								}
								else {
									for (e = y - 2; e <= y + 6; e = e + 2)
										for (int a = x - 2; a <= x + 2; a = a + 2) {
											i = (a - 40) / 2;
											j = e / 2;
											if (i < 10 && j < 10 && mypole[i][j] == 1)
												pr = 1;
										}
									if (pr == 0)
										for (e = y; e < y + 6; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											mypole[i][j] = 1;
											f = 1;
										}
								}
								break;
							}

							case 27: {
								f = 1;
								ui = 1;
								break;
							}
							}
						}
					} while (f != 1);
				}
			break;
		}

		case 3: {
			for (w = 0; w < 3; w++)
				if (ui == 0) {
					for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
						for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
							GotoXY(x, y);
							if (mypole[i][j] == 1) {
								SetColor(0, 12);
								cout << "  ";
							}
							else {
								if ((j + i) % 2 != 0) {
									SetColor(0, 1);
									cout << "  ";
								}
								else {
									SetColor(0, 9);
									cout << "  ";
								}
							}

							GotoXY(x, y + 1);
							if (mypole[i][j] == 1) {
								SetColor(0, 12);
								cout << "  ";
							}
							else {
								if ((j + i) % 2 != 0) {
									SetColor(0, 1);
									cout << "  ";
								}
								else {
									SetColor(0, 9);
									cout << "  ";
								}
							}
						}
					x = 41;
					y = nap = 1;
					i = j = 0;
					for (e = x; e < x + 4; e = e + 2) {
						GotoXY(e, y);
						SetColor(0, 14);
						cout << "  ";

						GotoXY(e, y + 1);
						SetColor(0, 14);
						cout << "  ";
					}
					do {
						f = 0;
						int code = _getch();
						if (code == 224) {
							code = _getch();
							switch (code) {
							case 72: {
								if (y != 1) {
									if (nap == 1) {
										for (e = x; e < x + 4; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										y = y - 2;
										for (e = x; e < x + 4; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
									else {
										if (y != 33) {
											for (e = y; e < y + 4; e = e + 2) {
												i = (x - 40) / 2;
												j = e / 2;
												GotoXY(x, e);
												if (mypole[i][j] == 1) {
													SetColor(0, 12);
													cout << "  ";
												}
												else {
													if ((i + j) % 2 != 0) {
														SetColor(0, 1);
														cout << "  ";
													}
													else {
														SetColor(0, 9);
														cout << "  ";
													}
												}

												GotoXY(x, e + 1);
												if (mypole[i][j] == 1) {
													SetColor(0, 12);
													cout << "  ";
												}
												else {
													if ((i + j) % 2 != 0) {
														SetColor(0, 1);
														cout << "  ";
													}
													else {
														SetColor(0, 9);
														cout << "  ";
													}
												}
											}
											y = y - 2;
											for (e = y; e < y + 4; e = e + 2) {
												GotoXY(x, e);
												SetColor(0, 14);
												cout << "  ";

												GotoXY(x, e + 1);
												SetColor(0, 14);
												cout << "  ";
											}
										}
									}
								}
								break;
							}

							case 77: {
								if (nap == 1) {
									if (x != 57) {
										for (e = x; e < x + 4; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										x = x + 2;
										for (e = x; e < x + 4; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								else {
									if (x != 59) {
										for (e = y; e < y + 4; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(x, e + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										x = x + 2;
										for (e = y; e < y + 4; e = e + 2) {
											GotoXY(x, e);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(x, e + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								break;
							}

							case 80: {
								if (nap == 1) {
									if (y != 19) {
										for (e = x; e < x + 4; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										y = y + 2;
										for (e = x; e < x + 4; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								else {
									if (y != 17) {
										for (e = y; e < y + 4; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(x, e + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										y = y + 2;
										for (e = y; e < y + 4; e = e + 2) {
											GotoXY(x, e);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(x, e + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								break;
							}

							case 75: {
								if (nap == 1) {
									if (x != 41) {
										for (e = x; e < x + 4; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										x = x - 2;
										for (e = x; e < x + 4; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								else {
									if (x != 41) {
										for (e = y; e < y + 4; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(x, e + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}
										x = x - 2;
										for (e = y; e < y + 4; e = e + 2) {
											GotoXY(x, e);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(x, e + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								break;
							}
							}
						}
						else {
							switch (code) {
							case 32: {
								if (nap == 1 && y < 19 || nap == -1 && x < 59) {
									nap = nap * (-1);
									if (nap == 1) {
										for (e = y; e < y + 4; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(x, e + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}

										for (e = x; e < x + 4; e = e + 2) {
											GotoXY(e, y);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(e, y + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
									else {
										for (e = x; e < x + 4; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											GotoXY(e, y);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}

											GotoXY(e, y + 1);
											if (mypole[i][j] == 1) {
												SetColor(0, 12);
												cout << "  ";
											}
											else {
												if ((i + j) % 2 != 0) {
													SetColor(0, 1);
													cout << "  ";
												}
												else {
													SetColor(0, 9);
													cout << "  ";
												}
											}
										}

										for (e = y; e < y + 4; e = e + 2) {
											GotoXY(x, e);
											SetColor(0, 14);
											cout << "  ";

											GotoXY(x, e + 1);
											SetColor(0, 14);
											cout << "  ";
										}
									}
								}
								break;
							}

							case 13: {
								int pr = f = 0;
								if (nap == 1) {
									for (e = x - 2; e <= x + 4; e = e + 2)
										for (int a = y - 2; a <= y + 2; a = a + 2) {
											i = (e - 40) / 2;
											j = a / 2;
											if (i < 10 && j < 10 && mypole[i][j] == 1)
												pr = 1;
										}
									if (pr == 0)
										for (e = x; e < x + 4; e = e + 2) {
											i = (e - 40) / 2;
											j = y / 2;
											mypole[i][j] = 1;
											f = 1;
										}
								}
								else {
									for (e = y - 2; e <= y + 4; e = e + 2)
										for (int a = x - 2; a <= x + 2; a = a + 2) {
											i = (a - 40) / 2;
											j = e / 2;
											if (i < 10 && j < 10 && mypole[i][j] == 1)
												pr = 1;
										}
									if (pr == 0)
										for (e = y; e < y + 4; e = e + 2) {
											i = (x - 40) / 2;
											j = e / 2;
											mypole[i][j] = 1;
											f = 1;
										}
								}
								break;
							}
							case 27: {
								f = 1;
								ui = 1;
								break;
							}
							}
						}
					} while (f != 1);
				}
			break;
		}

		case 4: {
			for (w = 0; w < 4; w++)
				if (ui == 0) {
					for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
						for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
							GotoXY(x, y);
							if (mypole[i][j] == 1) {
								SetColor(0, 12);
								cout << "  ";
							}
							else {
								if ((j + i) % 2 != 0) {
									SetColor(0, 1);
									cout << "  ";
								}
								else {
									SetColor(0, 9);
									cout << "  ";
								}
							}

							GotoXY(x, y + 1);
							if (mypole[i][j] == 1) {
								SetColor(0, 12);
								cout << "  ";
							}
							else {
								if ((j + i) % 2 != 0) {
									SetColor(0, 1);
									cout << "  ";
								}
								else {
									SetColor(0, 9);
									cout << "  ";
								}
							}
						}
					x = 41;
					y = 1;
					i = j = 0;
					e = x;
					GotoXY(e, y);
					SetColor(0, 14);
					cout << "  ";

					GotoXY(e, y + 1);
					SetColor(0, 14);
					cout << "  ";
					do {
						f = 0;
						int code = _getch();
						if (code == 224) {
							code = _getch();
							switch (code) {
							case 72: {
								if (y != 1) {
									e = x;

									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									GotoXY(e, y + 1);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									y = y - 2;
									e = x;

									GotoXY(e, y); SetColor(0, 14); cout << "  ";

									GotoXY(e, y + 1); SetColor(0, 14); cout << "  ";
								}
								break;
							}

							case 77: {
								if (x != 59) {
									e = x;

									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									GotoXY(e, y + 1);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									x = x + 2;
									e = x;

									GotoXY(e, y);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(e, y + 1);
									SetColor(0, 14);
									cout << "  ";
								}
								break;
							}

							case 80: {
								if (y != 19) {
									e = x;

									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									GotoXY(e, y + 1);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									y = y + 2;
									e = x;

									GotoXY(e, y);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(e, y + 1);
									SetColor(0, 14);
									cout << "  ";
								}
								break;
							}

							case 75: {
								if (x != 41) {
									e = x;

									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									GotoXY(e, y + 1);
									if (mypole[i][j] == 1) {
										SetColor(0, 12);
										cout << "  ";
									}
									else {
										if ((i + j) % 2 != 0) {
											SetColor(0, 1);
											cout << "  ";
										}
										else {
											SetColor(0, 9);
											cout << "  ";
										}
									}

									x = x - 2;
									e = x;

									GotoXY(e, y);
									SetColor(0, 14);
									cout << "  ";

									GotoXY(e, y + 1);
									SetColor(0, 14);
									cout << "  ";
								}
								break;
							}
							}
						}

						else {
							switch (code) {
							case 13: {
								int pr = f = 0;
								for (e = x - 2; e <= x + 2; e = e + 2)
									for (int a = y - 2; a <= y + 2; a = a + 2) {
										i = (e - 40) / 2;
										j = a / 2;
										if (i < 10 && j < 10 && mypole[i][j] == 1)
											pr = 1;
									}
								if (pr == 0)
									for (e = x; e < x + 2; e = e + 2) {
										i = (e - 40) / 2;
										j = y / 2;
										mypole[i][j] = 1;
										f = 1;
									}
								break;
							}

							case 27: {
								f = 1;
								ui = 1;
								break;
							}
								   break;
							}
						}
					} while (f != 1);
				}
			break;
		}
			  break;
		}
	}
	return ui;
}

int comp(int mypole[10][10], int udar, int ud[2], int hod[1]) {
	int i, j, f, per, n, m, x, y, k, h, pri, prj;
	GotoXY(24, 14);
	SetColor(15, 0);
	cout << Rus("  Ходит комп ");
	do {
		f = 1;
		per = 0;
		k = 0;
		GotoXY(28, 16);
		SetColor(15, 0);
		cout << Rus("      ");
		Sleep(1000);

		h = 0;
		if (hod[0] == 5) {
			for (n = ud[0] - 1; n <= ud[0] + 1 && n < 10; n++)
				for (m = ud[1] - 1; m <= ud[1] + 1 && m < 10; m++)
					if (mypole[n][m] == 1) {
						h = 1;
					}
			if (h == 0) {
				mypole[ud[0]][ud[1]] = 5;
				for (n = ud[0] - 1; n <= ud[0] + 1 && n < 10; n++)
					for (m = ud[1] - 1; m <= ud[1] + 1 && m < 10; m++)
						if (mypole[n][m] == 0) {
							mypole[n][m] = 3;
						}
			}
			if (h == 1) {
				per = 1;
				do {
					pri = rand() % 4 + 1;
					prj = 0;
					switch (pri) {
					case 1: {
						if (mypole[ud[0] - 1][ud[1]] == 0 && ud[0] != 0) {
							mypole[ud[0] - 1][ud[1]] = 3;
							GotoXY(28, 16);
							SetColor(15, 0);
							Sleep(1000);
							cout << Rus("Мимо!");
							prj = 1;
							per = 1;
							f = 1;
						}
						if (mypole[ud[0] - 1][ud[1]] == 1 && ud[0] != 0) {
							mypole[ud[0] - 1][ud[1]] = 4;
							GotoXY(28, 16);
							SetColor(15, 0);
							cout << Rus("Попал!");
							udar++;
							Sleep(1000);
							cout << "\x07";
							f = 0;
							prj = 1;
							per = 1;
							hod[0] = 1;
						}
						break;
					}

					case 2: {
						if (mypole[ud[0] + 1][ud[1]] == 0 && ud[0] != 9) {
							mypole[ud[0] + 1][ud[1]] = 3;
							GotoXY(28, 16);
							SetColor(15, 0);
							Sleep(1000);
							cout << Rus("Мимо!");
							prj = 1;
							per = 1;
							f = 1;
						}
						if (mypole[ud[0] + 1][ud[1]] == 1 && ud[0] != 9) {
							mypole[ud[0] + 1][ud[1]] = 4;
							GotoXY(28, 16); SetColor(15, 0);
							cout << Rus("Попал!");
							udar++;
							Sleep(1000);
							cout << "\x07";
							f = 0;
							prj = 1;
							per = 1;
							hod[0] = 1;
						}
						break;
					}

					case 3: {
						if (mypole[ud[0]][ud[1] - 1] == 0 && ud[1] != 0) {
							mypole[ud[0]][ud[1] - 1] = 3;
							GotoXY(28, 16);
							SetColor(15, 0);
							Sleep(1000);
							cout << Rus("Мимо!");
							prj = 1;
							per = 1;
							f = 1;
						}
						if (mypole[ud[0]][ud[1] - 1] == 1 && ud[1] != 0) {
							mypole[ud[0]][ud[1] - 1] = 4;
							GotoXY(28, 16);
							SetColor(15, 0);
							cout << Rus("Попал!");
							udar++; Sleep(1000);
							cout << "\x07";
							f = 0;
							prj = 1;
							per = 1;
							hod[0] = 1;
						}
						break;
					}

					case 4: {
						if (mypole[ud[0]][ud[1] + 1] == 0 && ud[1] != 9) {
							mypole[ud[0]][ud[1] + 1] = 3;
							GotoXY(28, 16);
							SetColor(15, 0);
							Sleep(1000);
							cout << Rus("Мимо!");
							prj = 1;
							per = 1;
							f = 1;
						}
						if (mypole[ud[0]][ud[1] + 1] == 1 && ud[1] != 9) {
							mypole[ud[0]][ud[1] + 1] = 4;
							GotoXY(28, 16);
							SetColor(15, 0);
							cout << Rus("Попал!");
							udar++;
							Sleep(1000);
							cout << "\x07";
							f = 0;
							prj = 1;
							per = 1;
							hod[0] = 1;
						}
						break;
					}
					}
				} while (prj == 0);
			}
		}

		if (hod[0] == 1) {
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++) {
					h = 0;
					if (mypole[i][j] == 4 || mypole[i][j] == 5) {
						mypole[i][j] = 5;
						if (i > 0) {
							if (mypole[i - 1][j] == 1) {
								h = 1;
								mypole[i - 1][j] = 5;
								GotoXY(28, 16);
								SetColor(15, 0);
								cout << Rus("Попал!");
								Sleep(1000);
								cout << "\x07";
								for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
									for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
										GotoXY(x, y);
										switch (mypole[i][j]) {
										case 0:
											if ((j + i) % 2 != 0) {
												SetColor(0, 1);
												cout << "  ";
											}
											else {
												SetColor(0, 9);
												cout << "  ";
											}
											break;
										case 1:
											SetColor(0, 12);
											cout << "  ";
											break;
										case 2:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 3:
											SetColor(0, 11);
											cout << "  ";
											break;
										case 4:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 5:
											SetColor(0, 7);
											cout << "  ";
											break;
										}

										GotoXY(x, y + 1);
										switch (mypole[i][j]) {
										case 0:
											if ((j + i) % 2 != 0) {
												SetColor(0, 1);
												cout << "  ";
											}
											else {
												SetColor(0, 9);
												cout << "  ";
											}
											break;
										case 1:
											SetColor(0, 12);
											cout << "  ";
											break;
										case 2:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 3:
											SetColor(0, 11);
											cout << "  ";
											break;
										case 4:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 5:
											SetColor(0, 7);
											cout << "  ";
											break;
										}
									}
							}
						}
						if (i < 9) {
							if (mypole[i + 1][j] == 1) {
								h = 1;
								mypole[i + 1][j] = 5;
								GotoXY(28, 16);
								SetColor(15, 0);
								cout << Rus("Попал!");
								Sleep(1000);
								cout << "\x07";
								for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
									for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
										GotoXY(x, y);
										switch (mypole[i][j]) {
										case 0:
											if ((j + i) % 2 != 0) {
												SetColor(0, 1);
												cout << "  ";
											}
											else {
												SetColor(0, 9);
												cout << "  ";
											}
											break;
										case 1:
											SetColor(0, 12);
											cout << "  ";
											break;
										case 2:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 3:
											SetColor(0, 11);
											cout << "  ";
											break;
										case 4:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 5:
											SetColor(0, 7);
											cout << "  ";
											break;
										}

										GotoXY(x, y + 1);
										switch (mypole[i][j]) {
										case 0:
											if ((j + i) % 2 != 0) {
												SetColor(0, 1);
												cout << "  ";
											}
											else {
												SetColor(0, 9);
												cout << "  ";
											}
											break;
										case 1:
											SetColor(0, 12);
											cout << "  ";
											break;
										case 2:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 3:
											SetColor(0, 11);
											cout << "  ";
											break;
										case 4:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 5:
											SetColor(0, 7);
											cout << "  ";
											break;
										}
									}
							}
						}

						if (j > 0) {
							if (mypole[i][j - 1] == 1) {
								h = 1;
								mypole[i][j - 1] = 5;
								GotoXY(28, 16);
								SetColor(15, 0);
								cout << Rus("Попал!");
								Sleep(1000);
								cout << "\x07";
								for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
									for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
										GotoXY(x, y);
										switch (mypole[i][j]) {
										case 0:
											if ((j + i) % 2 != 0) {
												SetColor(0, 1);
												cout << "  ";
											}
											else {
												SetColor(0, 9);
												cout << "  ";
											}
											break;
										case 1:
											SetColor(0, 12);
											cout << "  ";
											break;
										case 2:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 3:
											SetColor(0, 11);
											cout << "  ";
											break;
										case 4:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 5:
											SetColor(0, 7);
											cout << "  ";
											break;
										}

										GotoXY(x, y + 1);
										switch (mypole[i][j]) {
										case 0:
											if ((j + i) % 2 != 0) {
												SetColor(0, 1);
												cout << "  ";
											}
											else {
												SetColor(0, 9);
												cout << "  ";
											}
											break;
										case 1:
											SetColor(0, 12);
											cout << "  ";
											break;
										case 2:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 3:
											SetColor(0, 11);
											cout << "  ";
											break;
										case 4:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 5:
											SetColor(0, 7);
											cout << "  ";
											break;
										}
									}
							}
						}
						if (j < 9) {
							if (mypole[i][j + 1] == 1) {
								h = 1;
								mypole[i][j + 1] = 5;
								GotoXY(28, 16);
								SetColor(15, 0);
								cout << Rus("Попал!");
								Sleep(1000);
								cout << "\x07";
								for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
									for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
										GotoXY(x, y);
										switch (mypole[i][j]) {
										case 0:
											if ((j + i) % 2 != 0) {
												SetColor(0, 1);
												cout << "  ";
											}
											else {
												SetColor(0, 9);
												cout << "  ";
											}
											break;
										case 1:
											SetColor(0, 12);
											cout << "  ";
											break;
										case 2:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 3:
											SetColor(0, 11);
											cout << "  ";
											break;
										case 4:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 5:
											SetColor(0, 7);
											cout << "  ";
											break;
										}

										GotoXY(x, y + 1);
										switch (mypole[i][j]) {
										case 0:
											if ((j + i) % 2 != 0) {
												SetColor(0, 1);
												cout << "  ";
											}
											else {
												SetColor(0, 9);
												cout << "  ";
											}
											break;
										case 1:
											SetColor(0, 12);
											cout << "  ";
											break;
										case 2:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 3:
											SetColor(0, 11);
											cout << "  ";
											break;
										case 4:
											SetColor(0, 7);
											cout << "  ";
											break;
										case 5:
											SetColor(0, 7);
											cout << "  ";
											break;
										}
									}
							}
						}
					}
				}

			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++) {
					h = 0;
					if (mypole[i][j] == 5) {
						if (i > 0) {
							if (mypole[i - 1][j] == 0) {
								h = 1;
								mypole[i - 1][j] = 3;
							}
						}

						if (i < 9) {
							if (mypole[i + 1][j] == 0) {
								h = 1;
								mypole[i + 1][j] = 3;
							}
						}

						if (j > 0) {
							if (mypole[i][j - 1] == 0) {
								h = 1;
								mypole[i][j - 1] = 3;
							}
						}

						if (j < 9) {
							if (mypole[i][j + 1] == 0) {
								h = 1;
								mypole[i][j + 1] = 3;
							}
						}

						if (i > 0 && j > 0) {
							if (mypole[i - 1][j - 1] == 0) {
								h = 1;
								mypole[i - 1][j - 1] = 3;
							}
						}

						if (i > 0 && j < 9) {
							if (mypole[i - 1][j + 1] == 0) {
								h = 1;
								mypole[i - 1][j + 1] = 3;
							}
						}

						if (i < 9 && j < 9) {
							if (mypole[i + 1][j + 1] == 0) {
								h = 1;
								mypole[i + 1][j + 1] = 3;
							}
						}

						if (i < 9 && j>0) {
							if (mypole[i + 1][j - 1] == 0) {
								h = 1;
								mypole[i + 1][j - 1] = 3;
							}
						}
					}
				}

		}

		udar = 0;
		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++)
				if (mypole[i][j] == 4 || mypole[i][j] == 5)
					udar++;
		if (udar == 20) {
			f = 1;
			per = 1;
		}
		for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
			for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
				GotoXY(x, y);
				switch (mypole[i][j]) {
				case 0:
					if ((j + i) % 2 != 0) {
						SetColor(0, 1);
						cout << "  ";
					}
					else {
						SetColor(0, 9);
						cout << "  ";
					}
					break;
				case 1:
					SetColor(0, 12);
					cout << "  ";
					break;
				case 2:
					SetColor(0, 7);
					cout << "  ";
					break;
				case 3:
					SetColor(0, 11);
					cout << "  ";
					break;
				case 4:
					SetColor(0, 7);
					cout << "  ";
					break;
				case 5:
					SetColor(0, 7);
					cout << "  ";
					break;
				}

				GotoXY(x, y + 1);
				switch (mypole[i][j]) {
				case 0:
					if ((j + i) % 2 != 0) {
						SetColor(0, 1);
						cout << "  ";
					}
					else {
						SetColor(0, 9);
						cout << "  ";
					}
					break;
				case 1:
					SetColor(0, 12);
					cout << "  ";
					break;
				case 2:
					SetColor(0, 7);
					cout << "  ";
					break;
				case 3:
					SetColor(0, 11);
					cout << "  ";
					break;
				case 4:
					SetColor(0, 7);
					cout << "  ";
					break;
				case 5:
					SetColor(0, 7);
					cout << "  ";
					break;
				}
			}

		if (per == 0) {
			do {
				i = rand() % 10;
				j = rand() % 10;
			} while (mypole[i][j] > 1);

			if (mypole[i][j] == 1) {
				mypole[i][j] = 4;
				ud[0] = i;
				ud[1] = j;
				GotoXY(28, 16);
				SetColor(15, 0);
				cout << Rus("Попал!");
				hod[0] = 5;
				Sleep(1000);
				cout << "\x07";
				f = 0;
			}

			if (mypole[i][j] == 0) {
				mypole[i][j] = 3;
				f = 1;
				GotoXY(28, 16);
				SetColor(15, 0);
				cout << Rus("Мимо!");
				Sleep(1000);
			}
		}

		Sleep(1000);
		for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
			for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
				GotoXY(x, y);
				switch (mypole[i][j]) {
				case 0:
					if ((j + i) % 2 != 0) {
						SetColor(0, 1);
						cout << "  ";
					}
					else {
						SetColor(0, 9);
						cout << "  ";
					}
					break;
				case 1:
					SetColor(0, 12);
					cout << "  ";
					break;
				case 2:
					SetColor(0, 7);
					cout << "  ";
					break;
				case 3:
					SetColor(0, 11);
					cout << "  ";
					break;
				case 4:
					SetColor(0, 7);
					cout << "  ";
					break;
				case 5:
					SetColor(0, 7);
					cout << "  ";
					break;
				}

				GotoXY(x, y + 1);
				switch (mypole[i][j]) {
				case 0:
					if ((j + i) % 2 != 0) {
						SetColor(0, 1);
						cout << "  ";
					}
					else {
						SetColor(0, 9);
						cout << "  ";
					}
					break;
				case 1:
					SetColor(0, 12);
					cout << "  ";
					break;
				case 2:
					SetColor(0, 7);
					cout << "  ";
					break;
				case 3:
					SetColor(0, 11);
					cout << "  ";
					break;
				case 4:
					SetColor(0, 7);
					cout << "  ";
					break;
				case 5:
					SetColor(0, 7);
					cout << "  ";
					break;
				}
			}
		GotoXY(24, 5); SetColor(12, 0); cout << Rus("Комп сбил-") << udar << "/" << 20;
	} while (f == 0);

	return udar;
}

int player(int pole[10][10], int udar) {
	GotoXY(27, 16);
	SetColor(0, 0);
	cout << Rus("        ");
	int i, j, x, y, f, e, k = 0, pop, iper, jper, vih, end;
	for (i = 0, x = 1; i < 10, x < 21; i++, x = x + 2)
		for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
			GotoXY(x, y);
			if (pole[i][j] == 3) {
				SetColor(0, 11);
				cout << "  ";
			}
			else {
				if (pole[i][j] == 2) {
					SetColor(0, 12);
					cout << "  ";
				}
				else {
					if ((j + i) % 2 != 0) {
						SetColor(0, 1);
						cout << "  ";
					}
					else {
						SetColor(0, 9);
						cout << "  ";
					}
				}
			}

			GotoXY(x, y + 1);
			if (pole[i][j] == 3) {
				SetColor(0, 11);
				cout << "  ";
			}
			else {
				if (pole[i][j] == 2) {
					SetColor(0, 12);
					cout << "  ";
				}
				else {
					if ((j + i) % 2 != 0) {
						SetColor(0, 1);
						cout << "  ";
					}
					else {
						SetColor(0, 9);
						cout << "  ";
					}
				}
			}
		}
	x = 1; y = 1;
	i = j = 0;
	e = x;

	GotoXY(e, y);
	SetColor(0, 14);
	cout << "  ";

	GotoXY(e, y + 1);
	SetColor(0, 14);
	cout << "  ";

	do {
		f = 0;
		pop = 0;
		GotoXY(24, 14);
		SetColor(15, 0);
		cout << Rus("  Ходит игрок ");
		int code = _getch();
		if (code == 224) {
			GotoXY(27, 16);
			SetColor(0, 0);
			cout << Rus("        ");
			code = _getch();
			switch (code) {
			case 72: {
				if (y != 1) {
					e = x;

					i = e / 2;
					j = y / 2;
					GotoXY(e, y);
					if (pole[i][j] == 3) {
						SetColor(0, 11);
						cout << "  ";
					}
					else {
						if (pole[i][j] == 2) {
							SetColor(0, 12);
							cout << "  ";
						}
						else {
							if ((i + j) % 2 != 0) {
								SetColor(0, 1);
								cout << "  ";
							}
							else {
								SetColor(0, 9);
								cout << "  ";
							}
						}
					}

					GotoXY(e, y + 1);
					if (pole[i][j] == 3) {
						SetColor(0, 11);
						cout << "  ";
					}
					else {
						if (pole[i][j] == 2) {
							SetColor(0, 12);
							cout << "  ";
						}
						else {
							if ((i + j) % 2 != 0) {
								SetColor(0, 1);
								cout << "  ";
							}
							else {
								SetColor(0, 9);
								cout << "  ";
							}
						}
					}

					y = y - 2;
					e = x;
					GotoXY(e, y);
					SetColor(0, 14);
					cout << "  ";

					GotoXY(e, y + 1);
					SetColor(0, 14);
					cout << "  ";
				}
				break;
			}

			case 77: {
				if (x != 19) {
					e = x;
					i = e / 2;
					j = y / 2;
					GotoXY(e, y);
					if (pole[i][j] == 3) {
						SetColor(0, 11);
						cout << "  ";
					}
					else {
						if (pole[i][j] == 2) {
							SetColor(0, 12);
							cout << "  ";
						}
						else {
							if ((i + j) % 2 != 0) {
								SetColor(0, 1);
								cout << "  ";
							}
							else {
								SetColor(0, 9);
								cout << "  ";
							}
						}
					}

					GotoXY(e, y + 1);
					if (pole[i][j] == 3) {
						SetColor(0, 11);
						cout << "  ";
					}
					else {
						if (pole[i][j] == 2) {
							SetColor(0, 12);
							cout << "  ";
						}
						else {
							if ((i + j) % 2 != 0) {
								SetColor(0, 1);
								cout << "  ";
							}
							else {
								SetColor(0, 9);
								cout << "  ";
							}
						}
					}

					x = x + 2;
					e = x;

					GotoXY(e, y);
					SetColor(0, 14);
					cout << "  ";

					GotoXY(e, y + 1);
					SetColor(0, 14);
					cout << "  ";
				}
				break;
			}

			case 80: {
				if (y != 19) {
					e = x;
					i = e / 2;
					j = y / 2;
					GotoXY(e, y);
					if (pole[i][j] == 3) {
						SetColor(0, 11);
						cout << "  ";
					}
					else {
						if (pole[i][j] == 2) {
							SetColor(0, 12);
							cout << "  ";
						}
						else {
							if ((i + j) % 2 != 0) {
								SetColor(0, 1);
								cout << "  ";
							}
							else {
								SetColor(0, 9);
								cout << "  ";
							}
						}
					}

					GotoXY(e, y + 1);
					if (pole[i][j] == 3) {
						SetColor(0, 11);
						cout << "  ";
					}
					else {
						if (pole[i][j] == 2) {
							SetColor(0, 12);
							cout << "  ";
						}
						else {
							if ((i + j) % 2 != 0) {
								SetColor(0, 1);
								cout << "  ";
							}
							else {
								SetColor(0, 9);
								cout << "  ";
							}
						}
					}

					y = y + 2;
					e = x;
					GotoXY(e, y);
					SetColor(0, 14);
					cout << "  ";

					GotoXY(e, y + 1);
					SetColor(0, 14);
					cout << "  ";
				}
				break;
			}

			case 75: {
				if (x != 1) {
					e = x;
					i = e / 2;
					j = y / 2;
					GotoXY(e, y);
					if (pole[i][j] == 3) {
						SetColor(0, 11);
						cout << "  ";
					}
					else {
						if (pole[i][j] == 2) {
							SetColor(0, 12);
							cout << "  ";
						}
						else {
							if ((i + j) % 2 != 0) {
								SetColor(0, 1);
								cout << "  ";
							}
							else {
								SetColor(0, 9);
								cout << "  ";
							}
						}
					}

					GotoXY(e, y + 1);
					if (pole[i][j] == 3) {
						SetColor(0, 11);
						cout << "  ";
					}
					else {
						if (pole[i][j] == 2) {
							SetColor(0, 12);
							cout << "  ";
						}
						else {
							if ((i + j) % 2 != 0) {
								SetColor(0, 1);
								cout << "  ";
							}
							else {
								SetColor(0, 9);
								cout << "  ";
							}
						}
					}

					x = x - 2;
					e = x;
					GotoXY(e, y);
					SetColor(0, 14);
					cout << "  ";

					GotoXY(e, y + 1);
					SetColor(0, 14);
					cout << "  ";
				}
				break;
			}
			}
		}
		else {
			switch (code) {
			case 13: {
				int pr = f = 0;
				pop = 0;
				e = x;
				int a = y;
				i = e / 2;
				j = a / 2;
				if (i < 10 && j < 10 && pole[i][j] == 2 || pole[i][j] == 3)
					pr = 1;
				if (pr == 0) {
					e = x;
					i = e / 2;
					j = y / 2;
					if (pole[i][j] == 0) {
						pole[i][j] = 3;
						f = 1;
						GotoXY(28, 16);
						SetColor(15, 0);
						cout << Rus("Мимо!");
					}
					else {
						pole[i][j] = 2;
						cout << "\x07";
						GotoXY(27, 16);
						SetColor(15, 0);
						cout << Rus("Попал!");
						pop = 1;
						udar++;
					}
				}
				break;
			}

			case 27: {
				f = 1;
				GotoXY(24, 14);
				SetColor(15, 0);
				cout << Rus("    Выйти?    ");

				GotoXY(24, 16);
				SetColor(15, 0);
				cout << "[";
				SetColor(0, 2);
				cout << Rus("да");
				SetColor(15, 0);
				cout << "]  ";

				GotoXY(31, 16);
				SetColor(15, 0);
				cout << "  [";
				cout << Rus("нет");
				SetColor(15, 0);
				cout << "]";
				do {
					k = 0;
					vih = 0;
					int code = _getch();
					if (code == 224) {
						code = _getch();
						switch (code) {
						case 75: {
							f = f * (-1);
							if (f == 1) {
								GotoXY(24, 16);
								SetColor(15, 0);
								cout << "[";
								SetColor(0, 2);
								cout << Rus("да");
								SetColor(15, 0);
								cout << "]  ";

								GotoXY(31, 16);
								SetColor(15, 0);
								cout << "  [";
								cout << Rus("нет");
								SetColor(15, 0);
								cout << "]";
							}
							else {
								GotoXY(24, 16);
								SetColor(15, 0);
								cout << "[";
								cout << Rus("да");
								cout << "]  ";

								GotoXY(31, 16);
								SetColor(15, 0);
								cout << "  [";
								SetColor(0, 2);
								cout << Rus("нет");
								SetColor(15, 0);
								cout << "]";
							}
							break;
						}

						case 77: {
							f = f * (-1);
							if (f == 1) {
								GotoXY(24, 16);
								SetColor(15, 0);
								cout << "[";
								SetColor(0, 2);
								cout << Rus("да");
								SetColor(15, 0);
								cout << "]  ";

								GotoXY(31, 16);
								SetColor(15, 0);
								cout << "  [";
								cout << Rus("нет");
								SetColor(15, 0);
								cout << "]";
							}
							else {
								GotoXY(24, 16);
								SetColor(15, 0);
								cout << "[";
								cout << Rus("да");
								cout << "]  ";

								GotoXY(31, 16);
								SetColor(15, 0);
								cout << "  [";
								SetColor(0, 2);
								cout << Rus("нет");
								SetColor(15, 0);
								cout << "]";
							}
							break;
						}
						}
					}
					else {
						switch (code) {
						case 13: {
							GotoXY(24, 14);
							SetColor(0, 0);
							cout << "              ";

							GotoXY(24, 16);
							cout << "              ";
							if (f == 1)
								k = 1;
							vih = 1;
							break;
						}
						}
					}
				} while (vih == 0);
				break;
			}
			}
			int mas[20][2], sh = 0, a, b;
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++) {
					if (pole[i][j] == 1) {
						if (i > 0 && pole[i - 1][j] == 2) {
							mas[sh][0] = i - 1;
							mas[sh][1] = j;
							sh++;
							if (i > 1 && pole[i - 2][j] == 2) {
								mas[sh][0] = i - 2;
								mas[sh][1] = j;
								sh++;
								if (i > 2 && pole[i - 3][j] == 2) {
									mas[sh][0] = i - 3;
									mas[sh][1] = j;
									sh++;
								}
							}
						}

						if (i < 9 && pole[i + 1][j] == 2) {
							mas[sh][0] = i + 1;
							mas[sh][1] = j;
							sh++;
							if (i < 8 && pole[i + 2][j] == 2) {
								mas[sh][0] = i + 2;
								mas[sh][1] = j;
								sh++;
								if (i < 7 && pole[i + 3][j] == 2) {
									mas[sh][0] = i + 3;
									mas[sh][1] = j;
									sh++;
								}
							}
						}

						if (j > 0 && pole[i][j - 1] == 2) {
							mas[sh][0] = i;
							mas[sh][1] = j - 1;
							sh++;
							if (j > 1 && pole[i][j - 2] == 2) {
								mas[sh][0] = i;
								mas[sh][1] = j - 2;
								sh++;
								if (j > 2 && pole[i][j - 3] == 2) {
									mas[sh][0] = i;
									mas[sh][1] = j - 3;
									sh++;
								}
							}
						}

						if (j < 9 && pole[i][j + 1] == 2) {
							mas[sh][0] = i;
							mas[sh][1] = j + 1;
							sh++;
							if (i < 8 && pole[i][j + 2] == 2) {
								mas[sh][0] = i;
								mas[sh][1] = j + 2;
								sh++;
								if (i < 7 && pole[i][j + 3] == 2) {
									mas[sh][0] = i;
									mas[sh][1] = j + 3;
									sh++;
								}
							}
						}
					}
				}

			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++) {
					b = 0;
					if (pole[i][j] == 2) {
						for (a = 0; a < sh; a++)
							if (i == mas[a][0] && j == mas[a][1])
								b = 1;
						if (b == 0) {
							if (i > 0 && pole[i - 1][j] == 0)	pole[i - 1][j] = 3;
							if (i < 9 && pole[i + 1][j] == 0)	pole[i + 1][j] = 3;
							if (j > 0 && pole[i][j - 1] == 0)	pole[i][j - 1] = 3;
							if (j < 9 && pole[i][j + 1] == 0)	pole[i][j + 1] = 3;
							if (i > 0 && j > 0 && pole[i - 1][j - 1] == 0)	pole[i - 1][j - 1] = 3;
							if (i > 0 && j < 9 && pole[i - 1][j + 1] == 0)	pole[i - 1][j + 1] = 3;
							if (i < 9 && j < 9 && pole[i + 1][j + 1] == 0)	pole[i + 1][j + 1] = 3;
							if (i < 9 && j>0 && pole[i + 1][j - 1] == 0)	pole[i + 1][j - 1] = 3;
						}
					}
				}

			iper = x; jper = y;
			GotoXY(e, y);
			SetColor(0, 14);
			cout << "  ";

			GotoXY(e, y + 1);
			SetColor(0, 14);
			cout << "  ";
			for (i = 0, x = 1; i < 10, x < 21; i++, x = x + 2)
				for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
					GotoXY(x, y);
					switch (pole[i][j]) {
					case 0:
						if ((j + i) % 2 != 0) {
							SetColor(0, 1);
							cout << "  ";
						}
						else {
							SetColor(0, 9);
							cout << "  ";
						}
						break;
					case 1:
						if ((j + i) % 2 != 0) {
							SetColor(0, 1);
							cout << "  ";
						}
						else {
							SetColor(0, 9);
							cout << "  ";
						}
						break;
					case 2:
						SetColor(0, 12);
						cout << "  ";
						break;
					case 3:
						SetColor(0, 11);
						cout << "  ";
						break;
					}
					GotoXY(x, y + 1);
					switch (pole[i][j]) {
					case 0:
						if ((j + i) % 2 != 0) {
							SetColor(0, 1);
							cout << "  ";
						}
						else {
							SetColor(0, 9);
							cout << "  ";
						}
						break;
					case 1:
						if ((j + i) % 2 != 0) {
							SetColor(0, 1);
							cout << "  ";
						}
						else {
							SetColor(0, 9);
							cout << "  ";
						}
						break;
					case 2:
						SetColor(0, 12);
						cout << "  ";
						break;
					case 3:
						SetColor(0, 11);
						cout << "  ";
						break;
					}
				}
			x = iper; y = jper;
			udar = 0;
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++)
					if (pole[i][j] == 2 || pole[i][j] == 2)
						udar++;
			end = 0;
			if (udar == 20) {
				f = 1;
				pop = 0;
			}
			if (k == 1) {
				udar = -1;
				f = 1;
			}
		}
		GotoXY(24, 4);
		SetColor(12, 0);
		cout << Rus("Игрок сбил-") << udar << "/" << 20;
	} while ((f != 1 || pop != 0));

	return udar;
}

void DRAWSHIP() {
	SetColor(9, 0);
	GotoXY(15, 25); cout << "	  ^v^";
	GotoXY(15, 26); cout << "             $…   ^v^";
	GotoXY(15, 26); cout << "        ^v^     $$";
	GotoXY(15, 27); cout << "             $ $$";
	GotoXY(15, 28); cout << "             $$$ …     ^v^";
	GotoXY(15, 29); cout << "     ^v^       $$ §§§.";
	GotoXY(15, 30); cout << "           $$$ §§§§§";
	GotoXY(15, 31); cout << "           $ $ §§§§§§ ………      ^v^";
	GotoXY(15, 32); cout << "          $$ $  §§§§§§";
	GotoXY(15, 33); cout << "         $$$ $  §§§§§§§";
	GotoXY(15, 34); cout << "        $$$$ $  §§§§§§§§";
	GotoXY(15, 35); cout << "       $$$$$ $  §§§§§§§§";
	GotoXY(15, 36); cout << "     $$$$$$$ $  §§§§§§§§§";
	GotoXY(15, 37); cout << "    $$$$$$$$ $ §§§§§§§§§§§";
	GotoXY(15, 38); cout << " $ $$$$$$$$$ $ §§§§§§§§§§§";
	GotoXY(15, 39); cout << " $$ $        $$$     $$$$$   $$";
	GotoXY(15, 40); cout << "  $$$$$$$$$$$$$$$$$$$$$$$ $$$$.";
	GotoXY(15, 41); cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$";
	GotoXY(15, 42); cout << " ..-+*°* -..  ~~~*°*~~~  ..- *°* -..";
	GotoXY(15, 43); cout << "~~~  ..- *°* -..~~~~  ..- *°* -.. ";
	GotoXY(15, 44); cout << " ..- *~~°* -..  ..- *~~~~°* -.. * -...- *°";
	GotoXY(15, 45); cout << " .~*°*~~~~  ..- *~~~~°* -.. *.- *°* -..";
}

void GAME(int f) {
	int chislocomp = 0, chislomy = 0;
	SetColor(15, 0);
	system("cls");
	DRAWRAM(); // отрисовка рамки
	DRAWSHIP(); //отрисовка кораблей
	//раскраска поля компьютера, как шахматной доски в синий и голубой
	for (i = 0, x = 1; i < 10, x < 21; i++, x = x + 2) {
		for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
			GotoXY(x, y);
			if ((j + i) % 2 != 0) {
				SetColor(0, 1);
				cout << "  ";
			}
			else {
				SetColor(0, 9);
				cout << "  ";
			}
			GotoXY(x, y + 1);
			if ((j + i) % 2 != 0) {
				SetColor(0, 1);
				cout << "  ";
			}
			else {
				SetColor(0, 9);
				cout << "  ";
			}
		}
	}
	// раскраска нашего поля как шахмотной доски
	for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2) {
		for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2) {
			GotoXY(x, y);
			if (mypole[i][j] == 1) {
				SetColor(0, 12);
				cout << "  ";
			}
			else {
				if ((j + i) % 2 != 0) {
					SetColor(0, 1);
					cout << "  ";
				}
				else {
					SetColor(0, 9);
					cout << "  ";
				}
			}
			// переход на следующую строку
			GotoXY(x, y + 1);
			if (mypole[i][j] == 1) {
				SetColor(0, 12);
				cout << "  ";
			}
			else {
				if ((j + i) % 2 != 0) {
					SetColor(0, 1);
					cout << "  ";
				}
				else {
					SetColor(0, 9);
					cout << "  ";
				}
			}
		}
	}
	//
	GotoXY(24, 4); SetColor(12, 0); cout << Rus("Игрок сбил-0/20");
	GotoXY(24, 5); SetColor(12, 0); cout << Rus("Комп сбил-0/20");
	GotoXY(25, 8); SetColor(15, 0); cout << Rus("Выстрел-[Enter]");
	GotoXY(26, 9); SetColor(15, 0); cout << Rus("В меню-[Esc]");
	ud[0] = -3; ud[1] = -3;

	while (chislocomp < 20 && chislomy < 20) {
		if (chislomy == -1)
			break;
		if (chislocomp != 20 && chislomy != 20) {
			if (f == 1) {
				chislocomp = comp(mypole, chislocomp, ud, hod);
				f = f * (-1);
			}
			else {
				chislomy = player(pole, chislomy);
				f = f * (-1);
			}
		}
	}
	GAMEOVER(chislomy, chislocomp);
}

void HEAD() {
	SetColor(9, 0);
	GotoXY(5, 2); cout << "$$     $$                                     $$    $$$$$$          $$";
	GotoXY(5, 3); cout << "$$ $ $ $$ $$$$$$ $$$$$    $$$ $$  $$ $$$$$$ $$  $$  $$     $$$$$$ $$  $$";
	GotoXY(5, 4); cout << "$$  $  $$ $$  $$ $$  $$ $$    $$  $$ $$  $$ $$  $$  $$$$$  $$  $$ $$  $$";
	GotoXY(5, 5); cout << "$$     $$ $$  $$ $$$$$  $$    $$ $$  $$  $$ $$ $$$  $$  $$ $$  $$ $$ $$$";
	GotoXY(5, 6); cout << "$$     $$ $$  $$ $$     $$    $$  $$ $$  $$ $$$ $$  $$  $$ $$  $$ $$$ $$";
	GotoXY(5, 7); cout << "$$     $$ $$$$$$ $$      $$$$ $$  $$ $$$$$$ $$  $$  $$$$$  $$$$$$ $$  $$";
}


void menu() {  // менюшка
	int f = 1, k, code;
	SetColor(0, 0);
	system("cls");
	HEAD();
	DRAWSHIP();
	GotoXY(27, 12);
	SetColor(14, 0); //подсвеченная жёлтым новая игра
	cout << Rus("-->Новая игра<--");

	GotoXY(30, 13);
	SetColor(15, 0); //белый выход
	cout << Rus("   Выход   ");
	do {
		k = 0;
		code = _getch();
		if (code == 224 || code == 0)
			code = _getch();
		if (code == 80) { //код вниз, переход на пункт выход
			f = f * (-1);
			if (f == 1) {
				GotoXY(27, 12); SetColor(14, 0); cout << Rus("-->Новая игра<--");
				GotoXY(30, 13); SetColor(15, 0); cout << Rus("   Выход   ");
			}
			else {
				GotoXY(27, 12); SetColor(15, 0); cout << Rus("   Новая игра   ");
				GotoXY(30, 13); SetColor(14, 0); cout << Rus("-->Выход<--");
			}
		}
		else if (code == 72) { //код вверх, обратно на Новую игру
			f = f * (-1);
			if (f == 1) {
				GotoXY(27, 12); SetColor(14, 0); cout << Rus("-->Новая игра<--");
				GotoXY(30, 13); SetColor(15, 0); cout << Rus("   Выход   ");
			}
			else {
				GotoXY(27, 12); SetColor(15, 0);	cout << Rus("   Новая игра   ");
				GotoXY(30, 13); SetColor(14, 0);  cout << Rus("-->Выход<--");
			}
		}
		else if (code == 13) k = 1; //enter
	} while (k == 0);
	if (f != 1) system("taskkill -im cmd.exe");

	SetColor(0, 0);
	system("cls");
	HEAD();
	DRAWSHIP();
	f = 1;
	GotoXY(30, 10); SetColor(15, 0); cout << Rus("Расставить корабли");
	GotoXY(27, 13); SetColor(14, 0); cout << Rus("-->автоматически<--");
	GotoXY(30, 14); SetColor(15, 0); cout << Rus("   вручную   ");
	do { //переход между пунктами меню
		k = 0;
		code = _getch();
		if (code == 0 || code == 224)
			code = _getch();
		if (code == 80) {
			f = f * (-1); // 
			if (f == 1) {
				GotoXY(27, 13); SetColor(14, 0); cout << Rus("-->автоматически<--");
				GotoXY(30, 14); SetColor(15, 0); cout << Rus("   вручную   ");
			}
			else {
				GotoXY(27, 13); SetColor(15, 0); cout << Rus("   автоматически   ");
				GotoXY(30, 14); SetColor(14, 0); cout << Rus("-->вручную<--");
			}
		}
		else if (code == 72) {
			f = f * (-1);
			if (f == 1) {
				GotoXY(27, 13); SetColor(14, 0); cout << Rus("-->автоматически<--");
				GotoXY(30, 14); SetColor(15, 0); cout << Rus("   вручную   ");
			}
			else {
				GotoXY(27, 13); SetColor(15, 0); cout << Rus("   автоматически   ");
				GotoXY(30, 14); SetColor(14, 0); cout << Rus("-->вручную<--");
			}
		}
		else if (code == 13)  k = 1;
	} while (k == 0);
	if (f == 1) { //расставляются автоматически на моём моле
		sheeps(mypole);
		ui = 0;
	}
	else {
		SetColor(0, 0); // расстановка вручную..
		ui = ras(mypole);
	}
	if (ui == 0) { //расстановка кораблей, типа прогресс-бар
		SetColor(0, 0);
		system("cls");
		GotoXY(30, 10); SetColor(15, 0); cout << Rus("Расстановка кораблей");
		for (i = 1; i <= 100; i++) {
			GotoXY(62, 15);
			SetColor(15, 0);
			cout << i << "%";
			if (i % 2 == 0) {
				GotoXY(10 + (i / 2), 15);
				SetColor(0, 15);
				cout << " ";
			}
			Sleep(20);
		}
		sheeps(pole);
		SetColor(0, 0);
		system("cls");
		f = 1;
		GotoXY(30, 10); SetColor(15, 0); cout << Rus("Кто ходит первым?");
		GotoXY(27, 13); SetColor(14, 0); cout << Rus("-->компьютер<--");
		GotoXY(30, 14); SetColor(15, 0); cout << Rus("   игрок   ");
		do {
			k = 0;
			code = _getch();
			if (code == 0 || code == 224)
				code = _getch();
			if (code == 80) {
				f = f * (-1);
				if (f == 1) {
					GotoXY(27, 13); SetColor(14, 0); cout << Rus("-->компьютер<--");
					GotoXY(30, 14); SetColor(15, 0); cout << Rus("   игрок   ");
				}
				else {
					GotoXY(27, 13); SetColor(15, 0); cout << Rus("   компьютер   ");
					GotoXY(30, 14); SetColor(14, 0); cout << Rus("-->игрок<--");
				}
			}
			else if (code == 72) {
				f = f * (-1);
				if (f == 1) {
					GotoXY(27, 13); SetColor(14, 0); cout << Rus("-->компьютер<--");
					GotoXY(30, 14); SetColor(15, 0); cout << Rus("   игрок   ");
				}
				else {
					GotoXY(27, 13); SetColor(15, 0); cout << Rus("   компьютер   ");
					GotoXY(30, 14); SetColor(14, 0); cout << Rus("-->игрок<--");
				}
			}
			else if (code == 13) k = 1;
		} while (k == 0);
		GAME(f);
	}

}

void main() {
	system("title Морской бой");
	srand(time(NULL));
	while (1) {
		menu();
	}
}