#pragma once

template <typename typ>
class NotifierOfChange
{
public:
    NotifierOfChange(typ ty): m_previousValue(ty) {
    }

    bool isChanged(typ ty){
        if(ty != m_previousValue)
            return true;
        else
            return  false;
    }

private:
    typ m_previousValue;
};

