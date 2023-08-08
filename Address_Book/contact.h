#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_NUM 3
#define INCREMENT_NUM 2


//每个人包含的信息
typedef struct Person
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Person;



typedef struct Contact {
	int count;          //当前通讯录中实际联系人的数量
	int capacity;       //当前通讯录可存储联系人的容量
	Person* person;    //联系人的信息
}Contact;



//初始化通讯录
void init_Contact(Contact* pc);
//添加联系人
void add_Contact(Contact* pc);
//显示通讯录
void print_Contact(const Contact* pc);
//删除通讯录中指定联系人
void del_Contact(Contact* pc);
//查找通讯录中指定联系人
void Search_Contact(const Contact* pc);
//修改通讯录中指定联系人信息
void Modify_Contact(Contact* pc);
//对通讯录进行排序
void Sort_Contact(Contact* pc);
//销毁通讯录
void Destroy_Contact(Contact* pc);
//保存通讯录的信息到文件
void Save_Contact(Contact* pc);
//加载文件的信息到通讯录
void Load_Contact(Contact* pc);
