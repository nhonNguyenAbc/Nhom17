#include"graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

// Tao stack

// Khai bao cau truc cua mot node trong stack
struct node
{
    int data;//stack dang chua cac so nguyen
    struct node* pNext; //con tro lien ket giua cac node voi nhau
};
typedef struct node NODE;


//khai bao cau truc cua stack
struct stack
{
    NODE* pTop; // dung con tro dau de quan ly stack
};
typedef struct stack STACK;


//ham khoi tao stack
void initStack(STACK& s)
{
    s.pTop = NULL;
}

//ham khoi tao mot cai node
NODE* initNode(int x)
{
    NODE* p = new NODE();
    if (p == NULL)
    {
        cout << "Khong du du lieu de cap phat !!!";
        return NULL;
    }
    p->data = x;//them gia tri cua bien x vao trong data
    p->pNext = NULL;
    return p;
}

//ham IsEmpty( kiem tra stack co rong hay khong)
bool IsEmpty(STACK s)
{
    return(s.pTop == NULL);
}


//them 1 phan tu vao dau satck
bool Push(STACK& s, int data)
{
    NODE* p = initNode(data);
    if (p == NULL)
        return false;
    //neu stack rong
    if (IsEmpty(s))
    {
        s.pTop = p;//node p gio la node dau cua stack
    }
    else //danh sach da co phan tu
    {
        p->pNext = s.pTop;//cho con tro cua node p tro den dau danh sach <=> tao lien ket
        s.pTop = p;//cap nhap lai node dau cua stack
    }
    return true;
}

//lay phan tu dau stack va huy no di
void Pop(STACK& s)//x chinh la gia tri can lay trong node
{
    //neu danh sach rong
    if (IsEmpty(s))
    {
        cout << "Danh sach rong";
    }
    else
    {
        NODE* p = s.pTop;              //node p la node de chung ta xoa
        s.pTop = s.pTop->pNext;      //cap nhap lai node dau cua stack
        delete p;                   //xoa node dau stack vua lay
    }

}

//xem thong tin phan tu dau stack va giu nguyen gia tri cua stack
int getTop(STACK s)//x la bien de lay gia tri can xem
{
    int x;
    if (IsEmpty(s))
        return -1;
    else
        x = s.pTop->data;//lay gia tri phan tu dau stack ra de xem
    return x;
}
//ham xuat stack
void xuat(STACK s)
{
    if (IsEmpty(s) == true)
    {
        cout << "Danh sach rong";
    }
    else
    {
        int x;
        node* temp = new node();
        temp = s.pTop;
        while (temp != NULL) {
            x = temp->data;
            temp = temp->pNext;
            cout << x << " ";
        }
    }
}




//Mo phong

int clst = 3; // color stack
int clr[7] = { 2,16,16,16,16,16,16 }; // color rectangle
int sx[7] = { 0,0,0,0,0,0,0 };//speed x
int sy[7] = { 0,0,0,0,0,0,0 }; //speed y

// Du lieu truyen cho phan mo phong
struct Input
{
    char value[100];
}ip[9];


void Stack(int color)
{
    for (int i = 0; i < 3; i++)
    {
        setcolor(color);
        line(650 + i, 400, 650 + i, 800);
        line(895 + i, 400, 895 + i, 800);
        line(895, 800 + i, 650, 800 + i);
    }
}
void Rectangle(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);
    line(x1, y1, x1, y2);
    line(x1, y1, x2, y1);
    line(x2, y2, x2, y1);
    line(x2, y2, x1, y2);
}

void Mophong() {
    Rectangle(400 + sx[6], 300 + sy[6], 600 + sx[6], 370 + sy[6], clr[6]);
    drawText(490 + sx[6], 315 + sy[6], ip[6].value);
    Rectangle(400 + sx[5], 300 + sy[5], 600 + sx[5], 370 + sy[5], clr[5]);
    drawText(490 + sx[5], 315 + sy[5], ip[5].value);
    Rectangle(400 + sx[4], 300 + sy[4], 600 + sx[4], 370 + sy[4], clr[4]);
    drawText(490 + sx[4], 315 + sy[4], ip[4].value);
    Rectangle(400 + sx[3], 300 + sy[3], 600 + sx[3], 370 + sy[3], clr[3]);
    drawText(490 + sx[3], 315 + sy[3], ip[3].value);
    Rectangle(400 + sx[2], 300 + sy[2], 600 + sx[2], 370 + sy[2], clr[2]);
    drawText(490 + sx[2], 315 + sy[2], ip[2].value);
    Rectangle(400 + sx[1], 300 + sy[1], 600 + sx[1], 370 + sy[1], clr[1]);
    drawText(490 + sx[1], 315 + sy[1], ip[1].value);
    Stack(clst);
}

// Ham push 
void PushMP(int vitri, int &sx, int &sy) {

    int n = 0;
    while (n < 27) { 
        system("cls");
        // push -> right
        if (n >= 0 && n < 11)
        {
            Mophong();
            sx += 25;
        }
        // push -> down
        if (n >= 11 && n < 11 + vitri)
        {
            Mophong();
            sy += 25;
        }
        n++;
    }
}

// Ham pop ra stack
void PopMP(int vitri,int &sx, int &sy) {
    int n = 0;
    while (n < 76) {
        system("cls");
        // pop -> up
        if (n >= 0 && n < vitri)
        {
            Mophong();
            sy -= 25;
        }
        // pop -> right
        if (n >= vitri && n < 30)
        {
            Mophong();
            sx += 25;
        }
        // pop -> down
        if (n >= 30 && n < 75)
        {
            Mophong();
            sy += 25;
        }
        n++;
    }
}

// Kiem tra trong STACK co bao nhieu phan tu
int NumberElement(STACK s)
{
    node* temp = new node();
    int dem = 0;
    for (temp = s.pTop; temp != NULL; temp = temp->pNext) {
        dem++;
    }
    return dem;
}    

int main() {
    STACK s;
    initStack(s);
    initgraph();;
    char c[] = "Press any key to view the Stack";
    outtextxy(0, 0, c);
    _getch();

    int A[5] = { 0,16, 12, 8, 4}; // mang toa do cua stack
    system("cls");
    int chon; // lua chon menu
    int count = 1; // bien nay dem xem bao nhieu phan tu da vao stack
    while (true)
    {
        system("cls");
        Mophong();
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "0.Exit" << endl;
        cin >> chon;
        if (chon == 1)
        {
            if (count < 7)
            {
                if (NumberElement(s) < 4) { // STACK co 4 phan tu
                    cout << "Nhap Phan tu can them:" << endl;
                    cin >> ip[count].value; // Nhap du lieu 
                    Push(s, count); // Them phan tu vua nhap vao STACK s;
                    clr[count] = 15; // doi mau de hien phan tu ra
                    PushMP(A[NumberElement(s)], sx[count], sy[count]);
                    count++;
                }
                else {
                    cout << "STACK IS FULL!!!\n";
                    Sleep(1500);
                }
            }
            else
            {
                cout << "HET PHAN TU!!!!KHONG THE PUSH!!!!!!!" << endl;
                Sleep(1500);
            }
        }
        if (chon == 2) {
            int topStack = getTop(s); // Lay phan tu dau STACK
            if (topStack != -1) { // Ham getTop() tra ve gia tri -1 la STACK rong;
                PopMP(A[NumberElement(s)],sx[topStack], sy[topStack]);
                Pop(s);
            }
            else {
                cout << "STACK RONG!!!!!KHONG THE POP!!!\n";
                Sleep(1500);
            }
        }
        if (chon == 0) {
            exit(0);
        }
    }
    return 0;
}