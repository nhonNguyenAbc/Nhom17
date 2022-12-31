#include"graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>
struct Data
{
	char info[10];
}; typedef Data DATA;
DATA dt[10];
DATA ad[10];
DATA po[10];

char s1[] = "1", s2[] = "2", s3[] = "3", s4[] = "4", s5[] = "5", s6[] = "6";
char c1[] = "0";
int cl[8] = { 2,2,2,2,2,2,2,2 };
int cl1[7] = { 2,2,2,2,2,2,2 };
char p1[] = "NULL";
char c0[] = "";

void Rectangle(int x1, int y1, int x2, int y2, int color)
{
	setcolor(color);
	line(x1, y1, x1, y2);
	line(x1, y1, x2, y1);
	line(x2, y2, x2, y1);
	line(x2, y2, x1, y2);
}
void Queue(int x1, int y1, int x2, int y2)
{
	line(x1, y1, x2, y1);
	line(x2, y2, x1, y2);
}
void DRectangle(int x1, int y1, int x2, int y2, int color)
{
	setcolor(color);
	line(x1, y1, x1, y2);
	line(x1, y1, x2, y1);
	line(x2, y2, x2, y1);
	line(x2, y2, x1, y2);
	line(x1, (y1 + y2) / 2, x2, (y1 + y2) / 2);
}
void Pointer(int x1, int y1, int y2)
{
	line(x1, y1, x1, y2);
	line(x1 - 10, y2 - 10, x1, y2);
	line(x1 + 10, y2 - 10, x1, y2);
}
void Node()
{
	for (int i = 1; i < 7; i++)
	{
		Rectangle(500 + 100 * i, 200, 570 + 100 * i, 270, cl[i]);
		drawText(520 + 100 * i, 220, dt[i].info);
	}


}
void Count()
{
	for (int i = 1; i < 7; i++)
	{
		DRectangle(500 + 100 * i, 300, 570 + 100 * i, 400, cl[i]);
		Pointer(535 + 100 * i, 400, 500);
		drawText(520 + 100 * i, 310, ad[i].info);
	}
}

void Top()
{

	for (int i = 1; i < 7; i++)
	{
		Rectangle(500 + 100 * i, 500, 570 + 100 * i, 570, cl1[i]);
		drawText(510 + 100 * i, 520, po[i].info);
	}
}
void SUC()
{
	Pointer(635, 570, 670);
	Pointer(635, 740, 840);
	Pointer(735, 570, 670);
	Pointer(735, 740, 840);
	Pointer(835, 570, 670);
	Pointer(1035, 570, 670);
	Pointer(1135, 570, 670);

	drawText(610, 860, "NULL");
	drawText(710, 860, "NULL");
	drawText(810, 690, "NULL");
	drawText(1010, 690, "NULL");
	drawText(1110, 690, "NULL");
}
void Feat()
{
	drawText(500, 230, "NODE");
	drawText(500, 330, "COUNT");
	drawText(500, 530, "SUC");
}
int main()
{

	strcpy_s(dt[1].info, s1);	strcpy_s(ad[1].info, c1);	strcpy_s(po[1].info, p1);
	strcpy_s(dt[2].info, s2);	strcpy_s(ad[2].info, c1);	strcpy_s(po[2].info, p1);
	strcpy_s(dt[3].info, s3);	strcpy_s(ad[3].info, c1);	strcpy_s(po[3].info, p1);
	strcpy_s(dt[4].info, s4);	strcpy_s(ad[4].info, c1);	strcpy_s(po[4].info, p1);
	strcpy_s(dt[5].info, s5);	strcpy_s(ad[5].info, c1);	strcpy_s(po[5].info, p1);
	strcpy_s(dt[6].info, s6);	strcpy_s(ad[6].info, c1);	strcpy_s(po[6].info, p1);

	int n = 0;
	initgraph();
	char c[] = "Press any key";
	outtextxy(0, 0, c);
	_getch();

	while (n < 200)
	{
		system("cls");
		if ( n<=5)
		{
			Feat();
			cl[2] = 3; cl1[1] = 3;
			strcpy_s(po[1].info, c0);
			strcpy_s(ad[2].info, s1);
			Node(); Count(); Top();
			Pointer(635, 570, 670);
			Rectangle(600, 670, 670, 740, cl[7]);
			drawText(620, 520, "2");
			drawText(610, 690, "NULL");
		}
		if (n >= 5 && n < 10)
		{
			Feat();
			cl[2] = 2; cl[5] = 3;
			cl1[1] = 3;
			strcpy_s(ad[5].info, s1);
			Node(); Count(); Top();
			Pointer(635, 570, 670);
			Pointer(635, 740, 840);
			Rectangle(600, 670, 670, 740, cl[7]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl[7]);
			drawText(620, 690, "2");
			drawText(610, 860, "NULL");
		}

		if (n >= 10 && n < 17)
		{
			Feat();
			cl1[1] = 2; cl1[2] = 3;
			cl[3] = 3; cl[5] = 2;
			strcpy_s(po[2].info, c0);
			strcpy_s(ad[3].info, s1);
			Node(); Count(); Top();

			Pointer(635, 570, 670);
			Pointer(635, 740, 840);
			Pointer(735, 570, 670);

			Rectangle(600, 670, 670, 740, cl[7]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl[7]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "3");
			drawText(610, 860, "NULL");
			drawText(710, 690, "NULL");
		}
		if (n >= 17 && n < 24)
		{
			Feat();
			cl1[2] = 3;
			cl[3] = 2; cl[6] = 3;
			strcpy_s(ad[6].info, s1);
			Node(); Count(); Top();
			Pointer(635, 570, 670);
			Pointer(635, 740, 840);
			Pointer(735, 570, 670);
			Pointer(735, 740, 840);

			Rectangle(600, 670, 670, 740, cl[7]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl[7]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			drawText(610, 860, "NULL");
			drawText(710, 860, "NULL");

		}

		if (n >= 24 && n < 31)
		{
			Feat();
			cl1[2] = 2; cl1[3] = 3;
			cl[4] = 3; cl[6] = 2;
			strcpy_s(po[3].info, c0);
			strcpy_s(ad[4].info, s1);
			Node(); Count(); Top();
			Pointer(635, 570, 670);
			Pointer(635, 740, 840);
			Pointer(735, 570, 670);
			Pointer(735, 740, 840);
			Pointer(835, 570, 670);

			Rectangle(600, 670, 670, 740, cl[7]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl[7]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			drawText(610, 860, "NULL");
			drawText(710, 860, "NULL");
			drawText(810, 690, "NULL");
		}

		if (n >= 31 && n < 38)
		{
			Feat();
			cl1[5] = 3; cl1[3] = 2;
			cl[4] = 2; cl[6] = 3;
			strcpy_s(po[5].info, c0);
			strcpy_s(ad[6].info, s2);
			Node(); Count(); Top();
			Pointer(635, 570, 670);
			Pointer(635, 740, 840);
			Pointer(735, 570, 670);
			Pointer(735, 740, 840);
			Pointer(835, 570, 670);
			Pointer(1035, 570, 670);

			Rectangle(600, 670, 670, 740, cl[7]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl[7]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			drawText(610, 860, "NULL");
			drawText(710, 860, "NULL");
			drawText(810, 690, "NULL");
			drawText(1010, 690, "NULL");
		}

		if (n >=38  && n < 45)
		{
			Feat();
			cl1[5] = 2; cl1[6] = 3;
			cl[4] = 3; cl[6] = 2;
			strcpy_s(po[6].info, c0);
			strcpy_s(ad[4].info, s2);
			Node(); Count(); Top();
			Pointer(635, 570, 670);
			Pointer(635, 740, 840);
			Pointer(735, 570, 670);
			Pointer(735, 740, 840);
			Pointer(835, 570, 670);
			Pointer(1035, 570, 670);
			Pointer(1135, 570, 670);

			Rectangle(600, 670, 670, 740, cl[7]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl[7]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			drawText(610, 860, "NULL");
			drawText(710, 860, "NULL");
			drawText(810, 690, "NULL");
			drawText(1010, 690, "NULL");
			drawText(1110, 690, "NULL");
		}
		if (n >= 45 && n < 52)
		{
			Feat();
			cl[1] = 3; cl[4] = 2; 
			cl1[6] = 2;
			Node(); Count(); Top();
			Rectangle(600, 670, 670, 740, cl[7]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl[7]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			SUC();
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
		}
		if (n >= 52 && n < 60)
		{
			Feat();
			cl1[1] = 3;
			cl[5] = 3;
			strcpy_s(ad[5].info, c1);
			strcpy_s(po[6].info, c0);
			strcpy_s(ad[4].info, s2);
			Node(); Count(); Top();
			Rectangle(600, 670, 670, 740, cl[7]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl[7]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			SUC();
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			drawText(1320, 830, "1");

		}
		if (n >= 60 && n <68)
		{
			Feat();
			cl1[1] = 3;
			cl[5] = 2;
			strcpy_s(ad[5].info, c1);
			strcpy_s(po[6].info, c0);
			strcpy_s(ad[4].info, s2);
			Node(); Count(); Top();
			SUC();
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl[7]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			drawText(1320, 830, "1");
			drawText(1400, 830, "5");
		}
		if (n >= 68 && n < 75)
		{
			Feat();
			cl1[1] = 3;
			cl[5] = 2; cl[2] = 3;
			strcpy_s(ad[2].info, c1);
			strcpy_s(po[6].info, c0);
			strcpy_s(ad[4].info, s2);
			Node(); Count(); Top();
			SUC();
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			rectangle(1460, 800, 1530, 900);
			drawText(1320, 830, "1");
			drawText(1400, 830, "5");
			drawText(1480, 830, "2");
		}
		if (n >= 75 && n < 82)
		{
			
			system("cls");
			Feat();
			cl1[1] = 4;
			cl[1] = 4; cl[2] = 2;
			Node(); Count(); Top();
			SUC();
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "5");
			drawText(1400, 830, "2");
			drawText(820, 830, "1");
		}
		if (n >= 82 && n < 90)
		{
			Feat();
			strcpy_s(ad[6].info, s1);
			cl1[1] = 4; cl1[5] = 3;
			cl[1] = 4; cl[5] = 3;
			Node(); Count(); Top();
			SUC();
		
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "5");
			drawText(1400, 830, "2");
			drawText(820, 830, "1");
		}
		if (n >= 90 && n < 98)
		{

			system("cls");
			Feat();
			cl1[5] = 3;
			cl[5] = 3;
			Node(); Count(); Top();
			SUC();

			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[5]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "2");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
		}
		if (n >= 98 && n < 105)
		{
			
			Feat();
			cl1[5] = 4; cl1[2] = 3;
			cl[5] = 4; cl[2] = 3;
			Node(); Count(); Top();
			SUC();

			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[5]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "2");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
		}
		if (n >= 105 && n < 112)
		{
			Feat();
			strcpy_s(ad[6].info, c1);
			cl1[2] = 3;
			cl[6] = 3; cl[2] = 3;
			Node(); Count(); Top();
			SUC();

			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[7]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[5]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "2");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
		}
		if (n >= 112 && n < 120)
		{
			Feat();
			strcpy_s(ad[3].info, c1);
			cl[3] = 3;
			cl[6] = 2; cl[2] = 3;
			Node(); Count(); Top();
			SUC();

			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[3]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[5]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "2");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
			drawText(1400, 830, "6");
		}
		if (n >= 120 && n < 128)
		{
			Feat();
			cl[3] = 3;
			cl[6] = 2; cl[2] = 3;
			Node(); Count(); Top();
			SUC();

			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[3]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[7]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[5]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			rectangle(1460, 800, 1530, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "2");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
			drawText(1400, 830, "6");
			drawText(1480, 830, "3");
		}
		if (n >= 128 && n < 135)
		{
			system("cls");
			Feat();
			cl[3] = 2;
			cl[6] = 2; cl[2] = 3;
			Node(); Count(); Top();
			SUC();
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[2]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[2]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[5]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			rectangle(1000, 800, 1070, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "6");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
			drawText(1400, 830, "3");
			drawText(1020, 830, "2");
		}
		if (n >= 135 && n < 143)
		{
			Feat();
			cl1[2] = 4;
			 cl[2] = 4;
			Node(); Count(); Top();
			SUC();
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[2]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[2]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[5]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[7]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			rectangle(1000, 800, 1070, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "6");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
			drawText(1400, 830, "3");
			drawText(1020, 830, "2");
		}
		if (n >= 143 && n < 150)
		{
			Feat();
			strcpy_s(ad[4].info, s1);
			cl1[6] = 3;
			cl[6] = 3;
			Node(); Count(); Top();
			SUC();
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[2]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[2]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[6]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			rectangle(1000, 800, 1070, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "6");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
			drawText(1400, 830, "3");
			drawText(1020, 830, "2");

		}
		if (n >= 150 && n < 158)
		{
			system("cls");
			Feat();
			cl1[6] = 4;
			cl[6] = 4;
			Node(); Count(); Top();
			SUC();
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[2]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[2]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[7]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[6]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1100, 800, 1170, 900);
			rectangle(1000, 800, 1070, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "2");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
			drawText(1120, 830, "6");
			drawText(1020, 830, "2");
		}
		if (n >= 158 && n < 164)
		{
			Feat();
			strcpy_s(ad[4].info, c1);
			cl1[3] = 3;
			cl[3] = 3;
			Node(); Count(); Top();
			SUC();
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[2]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[2]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[3]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[7]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[6]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1380, 800, 1450, 900);
			rectangle(1100, 800, 1170, 900);
			rectangle(1000, 800, 1070, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1320, 830, "2");
			drawText(1400, 830, "4");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
			drawText(1120, 830, "6");
			drawText(1020, 830, "2");
		}
		if (n >= 164 && n < 172)
		{
			system("cls");
			Feat();
			cl1[3] = 4;
			cl[3] = 4;
			cl1[4] = 4;
			cl[4] = 4;
			Node(); Count(); Top();
			SUC();
			Rectangle(600, 670, 670, 740, cl1[1]);
			drawText(620, 520, "5");
			Rectangle(600, 840, 670, 910, cl1[1]);
			drawText(620, 690, "2");
			Rectangle(700, 670, 770, 740, cl[2]);
			drawText(720, 520, "6");
			Rectangle(700, 840, 770, 910, cl[2]);
			drawText(720, 690, "3");
			Rectangle(800, 670, 870, 740, cl[3]);
			drawText(820, 520, "4");
			Rectangle(1000, 670, 1070, 740, cl[4]);
			drawText(1020, 520, "6");
			Rectangle(1100, 670, 1170, 740, cl[6]);
			drawText(1120, 520, "4");
			Queue(1300, 800, 1800, 900);
			rectangle(1300, 800, 1370, 900);
			rectangle(1200, 800, 1270, 900);
			rectangle(1100, 800, 1170, 900);
			rectangle(1000, 800, 1070, 900);
			rectangle(900, 800, 970, 900);
			rectangle(800, 800, 870, 900);
			drawText(1220, 830, "2");
			drawText(1320, 830, "4");
			drawText(920, 830, "5");
			drawText(820, 830, "1");
			drawText(1120, 830, "6");
			drawText(1020, 830, "2");
			_getch();
			
		}
		Sleep(10);
		n++;

	}

}