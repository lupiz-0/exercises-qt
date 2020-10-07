#pragma once
#include <functional>


template <typename T>
class NotifierOfChange
{
public:
    NotifierOfChange(T& ty, std::function<void()> f_methodToCallIfChanged)
        : m_previousValue(ty), m_referenceToVariable(ty), methodToCallIfChanged(f_methodToCallIfChanged) {
    }
    ~NotifierOfChange() {
        if(m_previousValue != m_referenceToVariable)
            methodToCallIfChanged();
    }

private:
    T m_previousValue;
    T& m_referenceToVariable;
    std::function<void()> methodToCallIfChanged;
};

