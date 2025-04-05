#include <iostream>
using namespace std;

// Cấu trúc một nút trong cây BST
struct BST_NODE {
    int Key; // Khóa của nút
    int So_lan; // Số lần xuất hiện
    struct BST_NODE* Left, * Right;
};

// Cấu trúc cây BST
struct BST_TREE {
    struct BST_NODE* pRoot; // Nút gốc của cây
};

// Hàm khởi tạo cây rỗng
void Init(BST_TREE& t) {
    t.pRoot = NULL;
}

// Hàm tạo một nút mới
BST_NODE* CreateNode(int x) {
    BST_NODE* p = new BST_NODE;
    if (p != NULL) {
        p->Key = x;
        p->So_lan = 1; // Mặc định số lần xuất hiện là 1
        p->Left = NULL;
        p->Right = NULL;
    }
    return p;
}

// Hàm thêm phần tử vào cây BST
void Insert(BST_TREE& t, int x) {
    BST_NODE* p = t.pRoot;
    BST_NODE* parent = NULL;

    // Tìm vị trí thích hợp để chèn
    while (p != NULL) {
        parent = p;
        if (x == p->Key) { 
            p->So_lan++; // Nếu nút đã tồn tại, tăng số lần xuất hiện
            return;
        }
        else if (x < p->Key)
            p = p->Left;
        else
            p = p->Right;
    }

    // Tạo nút mới
    BST_NODE* newNode = CreateNode(x);
    if (parent == NULL) 
        t.pRoot = newNode; // Nếu cây rỗng, gán làm gốc
    else if (x < parent->Key)
        parent->Left = newNode;
    else
        parent->Right = newNode;
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây con phải
BST_NODE* MinValueNode(BST_NODE* root) {
    BST_NODE* current = root;
    while (current && current->Left != NULL)
        current = current->Left;
    return current;
}

// Hàm xóa phần tử khỏi cây BST
BST_NODE* DeleteNode(BST_NODE* root, int x) {
    if (root == NULL)
        return root;

    if (x < root->Key)
        root->Left = DeleteNode(root->Left, x);
    else if (x > root->Key)
        root->Right = DeleteNode(root->Right, x);
    else { // Tìm thấy nút cần xóa
        if (root->So_lan > 1) { 
            root->So_lan--; // Giảm số lần xuất hiện thay vì xóa
            return root;
        }

        // Nếu chỉ có một con hoặc không có con
        if (root->Left == NULL) {
            BST_NODE* temp = root->Right;
            delete root;
            return temp;
        }
        else if (root->Right == NULL) {
            BST_NODE* temp = root->Left;
            delete root;
            return temp;
        }

        // Nếu có cả hai con: Tìm giá trị nhỏ nhất bên phải
        BST_NODE* temp = MinValueNode(root->Right);
        root->Key = temp->Key;
        root->So_lan = temp->So_lan;
        root->Right = DeleteNode(root->Right, temp->Key);
    }
    return root;
}

// Hàm gọi xóa nút từ cây BST
void XoaGiaTri(BST_TREE& t, int X) {
    t.pRoot = DeleteNode(t.pRoot, X);
}

// Hàm duyệt cây theo thứ tự NLR
void NLR(BST_NODE* root) {
    if (root == NULL)
        return;
    cout << root->Key << "(" << root->So_lan << ") ";
    NLR(root->Left);
    NLR(root->Right);
}

// Hàm gọi duyệt cây BST
void LietKe(BST_TREE t) {
    NLR(t.pRoot);
    cout << endl;
}

// Chương trình chính
int main() {
    BST_TREE t;
    Init(t);

    // Thêm dữ liệu vào cây
    Insert(t, 10);
    Insert(t, 5);
    Insert(t, 15);
    Insert(t, 5);  // Thêm giá trị trùng lặp
    Insert(t, 20);
    Insert(t, 3);
    Insert(t, 7);

    // Hiển thị cây trước khi xóa
    cout << "Cay BST sau khi them: ";
    LietKe(t);

    // Xóa phần tử (giảm số lần xuất hiện nếu có)
    XoaGiaTri(t, 5);
    cout << "Cay BST sau khi xoa 1 lan gia tri 5: ";
    LietKe(t);

    // Xóa hẳn phần tử 5
    XoaGiaTri(t, 5);
    cout << "Cay BST sau khi xoa hoan toan 5: ";
    LietKe(t);

    return 0;
}
