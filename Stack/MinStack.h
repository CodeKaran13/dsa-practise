//
// Created by Karan Nandkar on 10/06/26.
//

#ifndef DSA_PRATISE_MINSTACK_H
#define DSA_PRATISE_MINSTACK_H

#include <stack>

class MinStack
{
private:
    std::stack<int> m_mainStack;
    std::stack<int> m_minStack;

public:
    void Push(int val);
    void Pop();
    int Top();
    int GetMin();
};


#endif //DSA_PRATISE_MINSTACK_H
