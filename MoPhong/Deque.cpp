#include"graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>



// Khai bao cau truc cua mot node trong deque
struct node
{
    int data;//deque dang chua cac so nguyen
    struct node* pNext; //con tro lien ket giua cac node voi nhau
};
typedef struct node NODE;


//khai bao cau truc cua deque
struct deque
{
    NODE* pHead;// dung con tro dau va cuoi de quan ly deque
    NODE* pTail;
};
typedef struct deque DEQUE;


//ham khoi tao deque
void khoiTaoDeque(DEQUE& q)
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

//ham IsEmpty( kiem tra deque co rong hay khong)
bool IsEmpty(DEQUE q)
{
    //neu danh sach rong
    if (q.pHead == NULL)
        return true;
    return false;//danh sach co phan tu
}

void Pushfront(DEQUE& q, NODE* p)
{
    if (q.pHead == NULL)// danh sách rỗng
    {
        q.pHead = q.pTail = p;
    }
    else
    {
        p->pNext = q.pHead;//cho node p trỏ đến node đầu tiên
        q.pHead = p;//cập nhập lại node đầu bằng p		
    }
}

void Pushback(DEQUE& q, NODE* p)
{
    if (q.pHead == NULL)
    {
        q.pHead = q.pTail = p;
    }
    else
    {
        q.pTail->pNext = p;
        q.pTail = p;
    }
}

void Popfront(DEQUE& q)
{
    //nếu danh sách rỗng
    if (q.pHead == NULL)
    {
        return;
    }
    NODE* p = q.pHead;//node p là node sẽ xóa
    q.pHead = q.pHead->pNext;//cập nhập lại pHead là phần tử kế tiếp
    delete p;
}


void Popback(DEQUE& q)
{
    //nếu deque rỗng
    if (q.pHead == NULL)
        return;
    //trường hợp deque có một phần tử
    if (q.pHead->pNext == NULL)
    {
        Popfront(q);
        return;
    }
    //duyệt từ đầu deque đến phần tử kế cuối
    for (NODE* k = q.pHead; k != NULL; k = k->pNext)
    {
        //phát hiện phần tử kế cuối
        if (k->pNext == q.pTail)
        {
            delete q.pTail;// xóa đi phần tử cuối
            k->pNext = NULL;// cho con trỏ của node kế cuối trỏ đến vùng nhớ NULL
            q.pTail = k;// cập nhập lại l.pTail.
            break;
        }
    }

}


//ham xuat deque
void xuat(DEQUE q)
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

void ToFront(DEQUE& q1, DEQUE& q) {
    node* temp = new node();
    temp = q.pHead;
    while (temp != NULL) {
        int x = temp->data;
        NODE* p = khoiTaoNode(x);
        Pushfront(q1, p);
        temp = temp->pNext;
    }

}



// mo phong


void Deque(int color)
{
    for (int i = 0; i < 1; i++)
    {
        setcolor(color);
        line(600, 350 + i, 1100, 350 + i);
        line(600, 550 + i, 1100, 550 + i);
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


int clst = 3; // color Deque
int clr[7] = { 16,16,16,16,16,16,16 }; // color rectangle
int sx[7] = { 0,0,0,0,0,0,0 };//speed x
int sy[7] = { 0,0,0,0,0,0,0 }; //speed y

// Du lieu truyen cho phan mo phong
struct Input
{
    char value[100];
}ip[9];

void Mophong() {
    Rectangle(500 + sx[6], 160 + sy[6], 600 + sx[6], 340 + sy[6], clr[6]);
    drawText(538 + sx[6], 240 + sy[6], ip[6].value);
    Rectangle(500 + sx[5], 160 + sy[5], 600 + sx[5], 340 + sy[5], clr[5]);
    drawText(538 + sx[5], 240 + sy[5], ip[5].value);
    Rectangle(500 + sx[4], 160 + sy[4], 600 + sx[4], 340 + sy[4], clr[4]);
    drawText(538 + sx[4], 240 + sy[4], ip[4].value);
    Rectangle(500 + sx[3], 160 + sy[3], 600 + sx[3], 340 + sy[3], clr[3]);
    drawText(538 + sx[3], 240 + sy[3], ip[3].value);
    Rectangle(500 + sx[2], 160 + sy[2], 600 + sx[2], 340 + sy[2], clr[2]);
    drawText(538 + sx[2], 240 + sy[2], ip[2].value);
    Rectangle(500 + sx[1], 160 + sy[1], 600 + sx[1], 340 + sy[1], clr[1]);
    drawText(538 + sx[1], 240 + sy[1], ip[1].value);
    Deque(clst);
}

// Them vao dang truoc
void Push_FrontMP(int vitri, int& sx, int& sy) {
    int n = 0;
    while (n < 33) { 
        system("cls");
        //down
        if (n >= 0 && n < 8)
        {
            Mophong();
            sy += 25;
        }
        // right
        if (n >= 8 && n < 8+vitri)
        {
            Mophong();
            sx += 25;
        }
        n++;
    }
}

//Them vao dang sau
void Push_BackMP(int& sx, int& sy) {
    int n = 0;
    while (n < 41) { 
        system("cls");
        // Right
        if (n >= 0 && n < 24)
        {
            Mophong();
            sx += 25;
        }
        // Down
        if (n >= 24 && n < 32)
        {
            Mophong();
            sy += 25;
        }
        // Left
        if (n >= 32 && n < 36)
        {
            Mophong();
            sx -= 25;
        }
        n++;
    }
}

// xoa tu dang truoc
void Pop_FRONTMP(int& sx, int& sy) {
    int n = 0;
    while (n < 45) {
        system("cls");
        // left
        if (n >= 0 && n < 20)
        {
            Mophong();
            sx -= 25;
        }
        // down
        if (n >= 20 && n < 45)
        {
            Mophong();
            sy += 30;
        }
        n++;
    }
}

// xoa tu dang sau
void Pop_BACKMP(int& sx, int& sy) {
    int n = 0;
    while (n < 29) {
        system("cls");
        // right
        if (n >= 0 && n < 4)
        {
            Mophong();
            sx += 25;
        }
        // down
        if (n >= 4 && n < 29)
        {
            Mophong();
            sy += 30;
        }
        n++;
    }
}

// di chuyen sang trai 1 don vi
void MoveLeft(int& sx) {
    int n = 0;
    while (n < 4) {
        system("cls");
        // left
        if (n >= 0 && n < 4)
        {
            Mophong();
            sx -= 25;
        }
        n++;
    }
}

// di chuyen sang phai 1 don vi
void MoveRight(int& sx) {
    int n = 0;
    while (n < 4) {
        system("cls");
        // right
        if (n >= 0 && n < 4)
        {
            Mophong();
            sx += 25;
        }
        n++;
    }
}

// dem xem trong DEQUE co bao nhieu phan tu
int NumberElement(DEQUE q)
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
    DEQUE q;
    khoiTaoDeque(q);
    initgraph();
    char c1[] = "Press any key to view the Deque";
    outtextxy(0, 0, c1);
    _getch();// du man hinh do hoa

    int A[6] = {0, 20, 16, 12, 8 , 4 }; // mang vi tri cua deque
    system("cls");
    int chon; // lua chon menu
    int count = 1; // bien nay dem xem bao nhieu phan tu da vao deque


    while (true)
    {
        system("cls");
        Mophong();
        cout << "1.Them Vao Truoc" << endl;
        cout << "2.Them Vao Sau" << endl;
        cout << "3.Xoa Phan Tu Truoc" << endl;
        cout << "4.Xoa Phan Tu Sau" << endl;
        cout << "0.Exit" << endl;
        cin >> chon;

        if (chon == 1)
        {
            if (count < 7)
            {
                if (NumberElement(q) < 5) {
                    cout << "Nhap Phan tu can them:" << endl;
                    cin >> ip[count].value; // Nhap gia tri can truyen vao
                    NODE* p = khoiTaoNode(count);
                    Pushfront(q, p);
                    clr[count] = 15;
                    Push_FrontMP(A[NumberElement(q)], sx[count], sy[count]);
                    count++;
                }
                else {
                    cout << "DEQUE IS FULL!!!\n";
                    Sleep(1500);
                }
            }
            else
            {
                cout << "HET PHAN TU!!!!KHONG THE THEM!!!!!!!" << endl;
                Sleep(1500);
            }
        }
        if (chon == 2)
        {
            if (count < 7)
            {
                if (NumberElement(q) < 5) {
                    cout << "Nhap Phan tu can them:" << endl;
                    cin >> ip[count].value; // Nhap gia tri can truyen vao
                    node* temp = new node();
                    for (temp = q.pHead; temp != NULL; temp = temp->pNext) {
                        MoveLeft(sx[temp->data]);
                    } // Dich nhung phan tu trong DEQUE sang trai sau do them vao dang sau
                    NODE* p = khoiTaoNode(count);
                    clr[count] = 15;
                    Push_BackMP(sx[count], sy[count]);
                    Pushback(q, p);
                    count++;
                }
                else {
                    cout << "DEQUE IS FULL!!!\n";
                    Sleep(1500);
                }
            }
            else
            {
                cout << "HET PHAN TU!!!!KHONG THE THEM!!!!!!!" << endl;
                Sleep(1500);
            }
        }
        if (chon == 3) {
            if(IsEmpty(q)!=1){ // Kiem tra xem DEQUE co rong khong
                int frontDeque = q.pHead->data; // lay phan tu dau tien dang truoc
                Pop_FRONTMP(sx[frontDeque], sy[frontDeque]);
                Popfront(q);
            }
            else {
                cout << "QUEUE RONG!!!!!KHONG THE POP!!!\n";
                Sleep(1500);
            }
        }
        if (chon == 4) {
            if (IsEmpty(q) != 1) {
                DEQUE q1;
                khoiTaoDeque(q1);
                int backDeque = q.pTail->data;
                Pop_BACKMP(sx[backDeque], sy[backDeque]);
                Popback(q);
                ToFront(q1, q);
                node* temp = new node();
                for (temp = q1.pHead; temp != NULL; temp = temp->pNext) {
                    MoveRight(sx[temp->data]);
                }
            }
            else {
                cout << "DEQUE RONG!!!!!KHONG THE POP!!!\n";
                Sleep(1500);
            }
        }
        if (chon == 0) {
            exit(0);
        }
    }
    return 0;
}