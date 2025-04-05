#include <iostream>
using namespace std;

struct node {
    float info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void LNR(TREE t, FILE* fp);
void NLR(TREE t, FILE* fp);
void LRN(TREE t, FILE* fp);

int Xuat(const char* filename, TREE t, void (*Traversal)(TREE, FILE*)) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL)
        return 0;
    Traversal(t, fp);
    fclose(fp);
    return 1;
}
//câu 008
void LNR(TREE t, FILE* fp) {
    if (t == NULL)
        return;
    LNR(t->pLeft, fp);
    fwrite(&t->info, sizeof(float), 1, fp);
    LNR(t->pRight, fp);
}
//câu 009
void NLR(TREE t,FILE*fp)
{
    if(t==NULL)
        return;
    fwrite(&t->info,sizeof(float),1,fp);
    NLR(t->pLeft,fp);
    NLR(t->pRight,fp);
}
//câu 010
void LRN(TREE t,FILE*fp)
{
    if(t==NULL)
        return;
    LRN(t->pLeft,fp);
    LRN(t->pRight,fp);
    fwrite(&t->info,sizeof(float),1,fp);
}

NODE* CreateNode(float x) {
    NODE* p = new NODE;
    if (p != NULL) {
        p->info = x;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}

void Insert(TREE& t, float x) {
    if (t == NULL) {
        t = CreateNode(x);
    }
    else {
        if (x < t->info)
            Insert(t->pLeft, x);
        else
            Insert(t->pRight, x);
    }
}

void DocFile(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        cout << "Khong the mo file: " << filename << endl;
        return;
    }

    float value;
    cout << "Noi dung file " << filename << ": ";
    while (fread(&value, sizeof(float), 1, fp)) {
        cout << value << " ";
    }
    cout << endl;

    fclose(fp);
}
int main() {
    TREE root = NULL;

    Insert(root, 10.5);
    Insert(root, 5.2);
    Insert(root, 15.8);
    Insert(root, 2.1);
    Insert(root, 7.4);

    if (Xuat("data_lnr.out", root, LNR)) {
        cout << "Ghi file data_lnr.out thanh cong!" << endl;
    } else {
        cout << "Loi mo file data_lnr.out!" << endl;
    }

    if (Xuat("data_nlr.out", root, NLR)) {
        cout << "Ghi file data_nlr.out thanh cong!" << endl;
    } else {
        cout << "Loi mo file data_nlr.out!" << endl;
    }

    if (Xuat("data_lrn.out", root, LRN)) {
        cout << "Ghi file data_lrn.out thanh cong!" << endl;
    } else {
        cout << "Loi mo file data_lrn.out!" << endl;
    }

    DocFile("data_lnr.out");
    DocFile("data_nlr.out");
    DocFile("data_lrn.out");
    return 0;
}
