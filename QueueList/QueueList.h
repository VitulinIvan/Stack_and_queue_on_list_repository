#pragma once

#include "List.h"

template <class T>
class TQueueList
{
protected:
    TList<T> list;
public:
    TQueueList();
    TQueueList(const TQueueList<T>& q);
    ~TQueueList();
    TQueueList<T>& operator=(const TQueueList<T>& q);
    void Push(T n);
    void Pop();
    T Get();
    bool IsEmpty();
    bool IsFull();
    int Length();
    template <class T1>
    friend ostream& operator<<(ostream& ostr, const TQueueList<T1>& Q);
    template <class T1>
    friend istream& operator>>(istream& istr, TQueueList<T1>& Q);
    template <class T1>
    friend ofstream& operator<<(ofstream& ofstr, TQueueList<T1>& Q);
    T GetMaxElement();//Доп. задание 1
    T GetMinElement(); //Доп. задание 3
    void WriteToFile(string filename);// Доп. задание 2
};

template<class T>
inline TQueueList<T>::TQueueList()
{
}

template<class T>
inline TQueueList<T>::TQueueList(const TQueueList<T>& q)
{
    this->list = q.list;
}

template<class T>
inline TQueueList<T>::~TQueueList()
{
}

template<class T>
inline TQueueList<T>& TQueueList<T>::operator=(const TQueueList<T>& q)
{
    if (this == &q)
        return *this;
    this->list = q.list;
    return *this;
}

template<class T>
inline void TQueueList<T>::Push(T n)
{
    list.InsLast(n);
}

template<class T>
inline void TQueueList<T>::Pop()
{
    list.DelFirst();
}

template<class T>
inline T TQueueList<T>::Get()
{
    if (list.IsEmpty())
        throw - 1;
    return list.GetFirst()->GetData();
}

template<class T>
inline bool TQueueList<T>::IsEmpty()
{
    return list.IsEmpty();
}

template<class T>
inline bool TQueueList<T>::IsFull()
{
    return list.IsFull();
}

template<class T>
inline int TQueueList<T>::Length()
{
    return list.GetCount();
}

template <class T1>
ostream& operator<<(ostream& ostr, const TQueueList<T1>& Q)
{
    return ostr << Q.list;
}

template <class T1>
istream& operator>>(istream& istr, TQueueList<T1>& Q)
{
    return istr >> Q.list;
}

template<class T1>
inline ofstream& operator<<(ofstream& ofstr, TQueueList<T1>& Q)
{
    return ofstr << Q.list;
}

template<class T>
inline T TQueueList<T>::GetMaxElement() //Доп. задание 1
{
    if (IsEmpty())
        throw - 1;
    TListIterator<T> iter = list.begin();
    int res = *iter;
    ++iter;
    for (; !iter.IsEmpty(); ++iter)
        if (*iter > res)
            res = *iter;;
    return res;
}

template<class T>
inline T TQueueList<T>::GetMinElement() //Допю задание 3
{
    if (IsEmpty())
        throw - 1;
    TListIterator<T> iter = list.begin();
    int res = *iter;
    ++iter;
    for (; !iter.IsEmpty(); ++iter)
        if (*iter < res)
            res = *iter;;
    return res;
}

template<class T>
inline void TQueueList<T>::WriteToFile(string filename)// Доп. задание 2
{
    ofstream fout(filename.c_str());
    fout << *this;
    fout.close();
}

