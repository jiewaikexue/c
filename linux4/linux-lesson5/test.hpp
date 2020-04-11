#pragma once
#include <cstdio>
#include <iostream>
#include <string.h>

struct UserInfo
{
    UserInfo()
    {
        memset(Name_, '\0', sizeof(Name_));
        memset(Age_, '\0', sizeof(Age_));
    }
    char Name_[20];
    char Age_[10];
};

void func(int a, int b)
{
    int aa = 10;
    int bb = 20;
    int cc = aa + bb;
    printf("a + b = %d\n", a + b);
}

void TestUserInfo()
{
    UserInfo* ui = new UserInfo();
    //strncpy()
    strcpy(ui->Name_, "zhangsan");
    strcpy(ui->Age_, "18");

    printf("name:%s   age:%s\n", ui->Name_, ui->Age_);
    delete ui;
}
