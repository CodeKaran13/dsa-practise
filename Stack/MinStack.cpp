//
// Created by Karan Nandkar on 10/06/26.
//

#include "MinStack.h"


void MinStack::Push(int val)
{
    m_mainStack.push(val);
    if (m_minStack.empty() || val <= m_minStack.top())
        m_minStack.push(val);
}

void MinStack::Pop()
{
    if (m_mainStack.top() == m_minStack.top())
        m_minStack.pop();

    m_mainStack.pop();
}

int MinStack::Top()
{
    return m_mainStack.top();
}

int MinStack::GetMin()
{
    return m_minStack.top();
}
