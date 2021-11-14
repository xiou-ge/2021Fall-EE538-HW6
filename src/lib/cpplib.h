#ifndef TEMPLATE_CPPLIB_H
#define TEMPLATE_CPPLIB_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

class CPPLib {
 public:
  //q3

  //q5
  void mergeArray(std::vector<int>& input1, int m, std::vector<int>& input2, int n);
  //q8
  bool CheckValidExpression(const std::string& a);
};


// q6
class MyString
{
private:
    char* data_;
    int size_;
public:
    MyString();
    ~MyString();
    MyString(const MyString&);
    void push_back(char);
    void pop_back();
    int size();
    char* data();
    bool empty();
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};



class SinglyLinkedList {
public:
  SinglyLinkedList() { head_ = nullptr; }
  bool empty();
  int size();
  void push_back(int i);
  void pop_back();
  int back();
  ListNode *GetBackPointer();
  ListNode *GetIthPointer(int i);
  void print();

  ListNode *head_;
};


#endif
