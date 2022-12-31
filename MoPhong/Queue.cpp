#include"graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>



// Khai bao cau truc cua mot node trong queue
struct node
{
    int data;//queue dang chua cac so nguyen
    struct node* pNext; //con tro lien ket giua cac node voi nhau
};
typedef struct node NODE;

//khai bao cau truc cua queue
struct queue
{
    NODE* pHead;// dung con tro dau va cuoi de quan ly queue
    NODE* pTail;
};
typedef struct queue QUEUE;

//ham khoi tao stack
void khoiTaoQueue(QUEUE& q)
{
    q.pHead = NULL;
    q.pTail = NULL;
}

//ham khoi tao mot cai node
NODE* khoiTaoNode(int x)
{
    NODE* p = new NODE();
    if (p == NULL)
    {
        cout << "\nKhong du du lieu de cap phat !!!";
        return NULL;
    }
    p->data = x;//them gia tri cua bien x vao trong data
    p->pNext = NULL;
    return p;
}

//ham IsEmpty( kiem tra queue co rong hay khong)
bool IsEmpty(QUEUE q)
{
    //neu danh sach rong
    if (q.pHead == NULL)
        return true;
    return false;//danh sach co phan tu
}

//them 1 phan tu vao cuoi queue
bool Enqueue(QUEUE& q, NODE* p)
{
    //neu stack rong
    if (IsEmpty(q) == true)
    {
        q.pHead = q.pTail = p;//node p gio la node dau va node cuoi cua queue
    }
    else //danh sach da co phan tu
    {
        q.pTail->pNext = p;//lien ket con tro cuoi cua danh sach voi phan tu p can them vao
        q.pTail = p;//cap nhap lai con tro cuoi la node p
    }
    return true;
}

//lay phan tu dau queue va huy no di
void Dequeue(QUEUE& q)//x chinh la gia tri can lay trong node
{
    //neu danh sach rong
        NODE* p = q.pHead;              //node p la node de chung ta xoa
        q.pHead = q.pHead->pNext;      //cap nhap lai node dau cua queue
        delete p;                   //xoa node dau queue vua lay
}

//xem thong tin phan tu dau queue va giu nguyen gia tri cua queue
int Top(QUEUE& q)//x la bien de lay gia tri can xem
{
    if (IsEmpty(q))
        return -1;
    int x = q.pHead->data;//lay gia tri phan tu dau queue ra de xem
    return x;
}

//ham xuat queue
void xuat(QUEUE q)
{
    if (IsEmpty(q) == true)
    {
        cout << "Danh sach rong";
    }
    else
    {
        int x;
        node* temp = new node();
        temp = q.pHead;
        while (temp != NULL) {
            x = temp->data;
            temp = temp->pNext;
            cout << x << " ";
        }
    }
}





// Mo phong

int clst = 0; // color stack
int clr[8] = {16,16,16,16,16,16,16,16}; // color rectangle
int sx[8] = { 0,0,0,0,0,0,0,0 };//speed x
int sy[8] = { 0,0,0,0,0,0,0,0 }; //speed y

// Du lieu truyen cho phan mo phong
struct Input
{
    char value[100];
}ip[9];

void Queue(int color)
{
    drawText(1220, 320, "FRONT");
    drawText(645, 320, "BACK");
    for (int i = 0; i < 1; i++)
    {
        setcolor(color);
        line(650, 350 + i, 1275, 350 + i);
        line(650, 550 + i, 1275, 550 + i);
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
    Rectangle(500 + sx[6], 360 + sy[6], 625 + sx[6], 540 + sy[6], clr[6]);
    drawText(555 + sx[6], 440 + sy[6], ip[6].value);
    Rectangle(500 + sx[5], 360 + sy[5], 625 + sx[5], 540 + sy[5], clr[5]);
    drawText(555 + sx[5], 440 + sy[5], ip[5].value);
    Rectangle(500 + sx[4], 360 + sy[4], 625 + sx[4], 540 + sy[4], clr[4]);
    drawText(555 + sx[4], 440 + sy[4], ip[4].value);
    Rectangle(500 + sx[3], 360 + sy[3], 625 + sx[3], 540 + sy[3], clr[3]);
    drawText(555 + sx[3], 440 + sy[3], ip[3].value);
    Rectangle(500 + sx[2], 360 + sy[2], 625 + sx[2], 540 + sy[2], clr[2]);
    drawText(555 + sx[2], 440 + sy[2], ip[2].value);
    Rectangle(500 + sx[1], 360 + sy[1], 625 + sx[1], 540 + sy[1], clr[1]);
    drawText(555 + sx[1], 440 + sy[1], ip[1].value);
    Queue(clst);
}

// Ham push 
void PushMP(int vitri, int& sx, int& sy) {
    int n = 0;
    while (n < 26) { 
        system("cls");
        // push -> right
        if (n >= 0 && n < vitri)
        {
            Mophong();
            sx += 25;
        }
        n++;
    }
}

// Ham pop
void PopMP(int& sx, int& sy) {
    int n = 0;
    while (n < 30) { 
        system("cls");
        // push -> right
        if (n >= 0 && n < 5)
        {
            Mophong();
            sx += 25;
        }
        if (n >= 5 && n < 30)
        {
            Mophong();
            sy += 30;
        }
        n++;
    }
}

// Ham nay la dich sang phai 1 don vi. Dung khi pop ra day cac phan tu con lai sang phai
void MoveRight( int& sx) {
    int n = 0;
    while (n < 5) { 
        system("cls");
        // push -> right
        if (n >= 0 && n < 5)
        {
            Mophong();
            sx += 25;
        }
        n++;
    }
}

// Dem so luong phan trong QUEUE
int NumberElement(QUEUE q)
{
    node* temp = new node();
    int dem = 0;
    for (temp = q.pHead; temp != NULL; temp = temp->pNext) {
        dem++;
    }
    return dem;
}

int main()
{
    QUEUE q;
    khoiTaoQueue(q);
    initgraph();
    char c[] = "Press any key to view the Queue";
    outtextxy(0, 0, c);
    _getch();// du man hinh do hoa

    int A[6] = { 0, 26, 21, 16, 11,6}; // mang vi tri cua queue
    system("cls");
    int chon; // lua chon menu
    int count = 1; // bien nay dem xem bao nhieu phan tu da vao QUEUE
    clst = 3;

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
                if (NumberElement(q) < 5) { // QUEUE co toi da 5 phan tu
                    cout << "Nhap Phan tu can them:" << endl;
                    cin >> ip[count].value; // Nhap gia tri can truyen vao
                    NODE* p = khoiTaoNode(count);
                    Enqueue(q,p); // Them phan tu vao trong QUEUE q;
                    clr[count] = 15;
                    PushMP(A[NumberElement(q)], sx[count], sy[count]);
                    count++;
                }
                else {
                    cout << "QUEUE IS FULL!!!\n";
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
            int topQueue = Top(q); // lay top cua QUEUE q
            if (topQueue != -1) {
                PopMP(sx[topQueue], sy[topQueue]); 
                Dequeue(q); // phan tu top ra khoi QUEUE Q
                node* temp = new node(); // Duyet cac phan con lai trong QUEUE q roi dich sang ben phai
                for (temp = q.pHead; temp != NULL; temp = temp->pNext) {
                    MoveRight(sx[temp->data]);
                }
            }

            else {
                cout << "QUEUE RONG!!!!!KHONG THE POP!!!\n";
                Sleep(1500);
            }
        }
        if (chon == 0) {
            exit(0);
        }
    }
}

