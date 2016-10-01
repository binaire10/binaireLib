#include "../include/MySystem/Console.h"
#include "../include/SystemFunction.h"
#include "iostream"

using namespace binaire;
using namespace System;
using namespace std;

Console::Console() noexcept : m_Mutex(CreatMutex())
{}

void Console::write(const string &data)
{
    m_Mutex->lock();
    cout << data << endl;
    m_Mutex->release();
}

void Console::write(const char *const &data, const unsigned &size)
{
    m_Mutex->lock();
    cout.write(data, size);
    cout << endl;
    m_Mutex->release();
}


void Console::read(string &data)
{
    m_Mutex->lock();
    cin >> data;
    m_Mutex->release();
}
/*
size_t Console::read(char *&data, const unsigned &size)
{
    m_Mutex->lock();
    cin.read(data, size);
    m_Mutex->release();
    return cin.gcount();
}*/

void Console::move(unsigned long long, bool)
{
}

void Console::moveTo(unsigned long long)
{
}
