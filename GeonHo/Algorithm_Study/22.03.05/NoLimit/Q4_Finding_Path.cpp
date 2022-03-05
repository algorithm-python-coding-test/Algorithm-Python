//0.01ms ~ 24.63ms

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//����� ��ġ�� ��ȣ�� ������ �迭
vector<pair<vector<int>, int>> _nodeinfo;
//��ȯ�� ������ ������ �迭
vector<vector<int>> _answer = { {}, {} };
//_nodeinfo�� ������ �� ���. x�� ���� �������� ����
bool comp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
    return a.first[0] < b.first[0];
}

struct treeNode {
    int num = 0;
    treeNode* left = nullptr;
    treeNode* right = nullptr;
};
//left��° ������ right��° ��� �� y���� �ִ��� ��带 ��ȯ
treeNode* binarySearch(int left, int right) {
    if (right < left) return nullptr;
    int ypos = -1;
    int num = 0;
    int idx = 0;
    for (int i = left; i <= right; i++) {
        if (_nodeinfo[i].first[1] > ypos) {
            ypos = _nodeinfo[i].first[1];
            num = _nodeinfo[i].second;
            idx = i;
        }
    }
    treeNode* tree = new treeNode();
    tree->num = num;
    tree->left = binarySearch(left, idx - 1);
    tree->right = binarySearch(idx + 1, right);
    return tree;
}
//������ȸ �Լ�
void preorder(treeNode* node) {
    _answer[0].push_back(node->num);
    if (node->left != nullptr) preorder(node->left);
    if (node->right != nullptr) preorder(node->right);
}
//������ȸ �Լ�
void postorder(treeNode* node) {
    if (node->left != nullptr) postorder(node->left);
    if (node->right != nullptr) postorder(node->right);
    _answer[1].push_back(node->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    //����� ��ġ�� ��ȣ�� _nodeinfo�� ����
    for (int i = 0; i < nodeinfo.size(); i++) {
        _nodeinfo.push_back({ nodeinfo[i], i + 1 });
    }
    //��带 x�� ���� �������� ����
    sort(_nodeinfo.begin(), _nodeinfo.end(), comp);
    int left = 0, right = nodeinfo.size() - 1;
    //����Ʈ���� ����
    treeNode* root = binarySearch(left, right);

    preorder(root);
    postorder(root);

    return _answer;
}