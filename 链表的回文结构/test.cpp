#define  _CRT_SECURE_NO_WARNINGS
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		list<int> l;
		ListNode* cur = A;
		while (cur != nullptr){
			l.push_front(cur->val);
			cur = cur->next;
		}
		cur = A;
		for (auto& e : l){
			if (e != cur->val)
				return false;
			cur = cur->next;
		}
		return true;
	}
};