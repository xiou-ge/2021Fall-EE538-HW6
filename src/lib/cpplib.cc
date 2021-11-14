#include "cpplib.h"
#include "limits"

// Question 3

// Question 5
void CPPLib::mergeArray(std::vector<int>& input1, int m, std::vector<int>& input2, int n){

}

// Question 6
MyString::MyString() {

}

MyString::~MyString() {

}

MyString::MyString(const MyString& rhs) {

}

void MyString::push_back(char ch) {

}

void MyString::pop_back() {

}

int MyString::size() {

}

char* MyString::data() {

}

bool MyString::empty() {

}

// Question 5
bool CPPLib::CheckValidExpression(const std::string& a){
    
}

// Question 8

bool SinglyLinkedList::empty() { return head_ == nullptr; }

int SinglyLinkedList::size() {
  int s = 0;
  if (empty()) {
    return s;
  }
  ListNode *p = head_;
  ListNode *p_prev;
  while (p != nullptr) {
    s++;
    p_prev = p;
    p = p->next;
  }

  return s;
}

ListNode *SinglyLinkedList::GetBackPointer() {
  if (empty()) {
    return head_;
  }
  ListNode *p = head_;
  while (p->next != nullptr) {
    p = p->next;
  }
  return p;
}

ListNode *SinglyLinkedList::GetIthPointer(int i) {
  if (empty()) {
    return head_;
  }

  ListNode *p = head_;
  ListNode *p_prev = head_;
  int max_size = size();
  int count = 0;
  while (p != nullptr && count < max_size && count <= i) {
    p_prev = p;
    p = p->next;  // Dangerous!! If p is null, then p->next = crash!!
    count++;
  }

  if (i < max_size) {
    return p_prev;
  } else {
    return nullptr;
  }
}

void SinglyLinkedList::push_back(int i) {
  // If list empty, create a new node and point head_ to it
  if (empty()) {
    head_ = new ListNode(i);
    return;
  }
  // If not empty, go to the end, create a new node and point the last item to
  // it
  auto back_ptr = GetBackPointer();
  auto newNode = new ListNode(i);
  back_ptr->next = newNode;
}

void SinglyLinkedList::pop_back() {}
int SinglyLinkedList::back() { return 0; }
void SinglyLinkedList::print() {
  std::cout << "{";
  if (!empty()) {
    ListNode *p = head_;
    ListNode *p_prev;
    while (p != nullptr) {
      p_prev = p;
      std::cout << p->val;
      p = p->next;
      if (p) {
        std::cout << ", ";
      }
    }
    std::cout << "}" << std::endl;
  }
}
