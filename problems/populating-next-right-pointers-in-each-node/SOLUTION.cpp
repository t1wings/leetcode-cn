#define NODE_DEFINE_LEETCODE_116_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE
#include "../../test/Common/Node.cpp"

/*
// Definition for a Node.
class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};
*/

//////////////////////////////////////////////////////////////////////////
Node* connect(Node* root)
{
	if (root == nullptr) return {};

	if (root->left != nullptr && root->right != nullptr) root->left->next = root->right;
	if (root->next != nullptr && root->next->left != nullptr) root->right->next = root->next->left;

	connect(root->left);
	connect(root->right);
	return root;
}

//////////////////////////////////////////////////////////////////////////
//Node* _solution_run(Node* root)
//{
//	return connect(root);
//}


#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
	Node* root = StringToNode(tc.get<string>());
	Node* ret = connect(root);
	string ans = NodeToString(ret);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

