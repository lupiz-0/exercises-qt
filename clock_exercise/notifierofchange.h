#pragma once

template <typename T>
class NotifierOfChange
{
public:
    NotifierOfChange(T ty): m_previousValue(ty) {
    }

    bool isChanged(T ty){
        if(ty != m_previousValue)
            return true;
        else
            return  false;
    }

private:
    T m_previousValue;
};

