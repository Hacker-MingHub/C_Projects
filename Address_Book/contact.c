#include "contact.h"


static int FindByName(Contact* pc, char* name) {
	for (int i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->person[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


static int CompareByName(const void* e1, const void* e2) {
	return strcmp(((Person*)e1)->name, ((Person*)e2)->name);
}



void init_Contact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	pc->capacity = DEFAULT_NUM;
	Person* ptr = (Person*)malloc(DEFAULT_NUM * sizeof(Person));
	if (ptr == NULL)
	{
		perror("初始化失败");
		return;
	}
	pc->person = ptr;
	Load_Contact(pc);
}



void add_Contact(Contact* pc) {
	assert(pc);
	if (pc->count == pc->capacity)
	{
		Person* ptr = (Person*)realloc(pc->person, (pc->capacity + INCREMENT_NUM) * sizeof(Person));
		if (ptr == NULL)
		{
			perror("初始化失败");
			return;
		}
		pc->person = ptr;
		pc->capacity += INCREMENT_NUM;
		printf("容量增加成功\n");
	}

	//获取所添加的信息
	printf("请输入名字:>");
	scanf("%s", pc->person[pc->count].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->person[pc->count].age));
	printf("请输入性别:>");
	scanf("%s", pc->person[pc->count].sex);
	printf("请输入电话:>");
	scanf("%s", pc->person[pc->count].tele);
	printf("请输入地址:>");
	scanf("%s", pc->person[pc->count].addr);

	pc->count++;
	printf("添加成功\n");
}


void print_Contact(const Contact* pc) {
	assert(pc);
	printf("%-3s\t%-25s\t%-5s\t%-5s\t%-11s\t%-30s\n", " ", "Name", "Age", "Sex", "Tele", "Address");
	for (int i = 0; i < pc->count; i++)
	{
		printf("%-3d\t%-25s\t%-5d\t%-5s\t%-11s\t%-30s\n", i + 1,
			pc->person[i].name,
			pc->person[i].age,
			pc->person[i].sex,
			pc->person[i].tele,
			pc->person[i].addr);
	}
}


void del_Contact(Contact* pc) {
	assert(pc);
	char name[MAX_NAME];

	if (pc->count == 0)
	{
		printf("通讯录为空，没有联系人可以删除\n");
		return;
	}

	printf("请输入要删除联系人的名字:>");
	scanf("%s", name);

	//查找指定名字联系人所在位置
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要删除的联系人不存在\n");
		return;
	}

	//删除该联系人
	for (int i = ret; i < pc->count - 1; i++)
	{
		pc->person[i] = pc->person[i + 1];
	}
	pc->count--;
	printf("该联系人已删除\n");
}


void Search_Contact(const Contact* pc) {
	assert(pc);
	char name[MAX_NAME];

	if (pc->count == 0)
	{
		printf("通讯录为空，没有联系人可以查找\n");
		return;
	}

	printf("请输入要查找联系人的名字:>");
	scanf("%s", name);

	//查找指定名字联系人所在位置
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要查找的联系人不存在\n");
		return;
	}

	//打印查找到的联系人信息
	printf("%-3s\t%-10s\t%-5s\t%-5s\t%-11s\t%-30s\n", " ", "名字", "年龄", "性别", "电话", "地址");
	printf("%-3d\t%-10s\t%-5d\t%-5s\t%-11s\t%-30s\n", ret + 1,
		pc->person[ret].name,
		pc->person[ret].age,
		pc->person[ret].sex,
		pc->person[ret].tele,
		pc->person[ret].addr);
}


void Modify_Contact(Contact* pc) {
	assert(pc);
	char name[MAX_NAME];

	if (pc->count == 0)
	{
		printf("通讯录为空，没有联系人可以修改\n");
		return;
	}

	printf("请输入要修改联系人的名字:>");
	scanf("%s", name);

	//查找指定名字联系人所在位置
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要修改的联系人不存在\n");
		return;
	}
	printf("要修改的联系人已查找到，接下来开始修改\n");

	//修改联系人信息
	printf("请输入名字:>");
	scanf("%s", pc->person[ret].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->person[ret].age));
	printf("请输入性别:>");
	scanf("%s", pc->person[ret].sex);
	printf("请输入电话:>");
	scanf("%s", pc->person[ret].tele);
	printf("请输入地址:>");
	scanf("%s", pc->person[ret].addr);

	printf("修改成功\n");
}


void Sort_Contact(Contact* pc) {
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，不需要排序\n");
		return;
	}

	qsort(pc->person, pc->count, sizeof(Person), CompareByName);
	printf("排序完成\n");
}


void Destroy_Contact(Contact* pc) {
	assert(pc);
	free(pc->person);
	pc->person = NULL;
}


void Save_Contact(Contact* pc) {
	assert(pc);
	FILE* fp = fopen("contact.txt", "wb");
	if (fp == NULL)
	{
		perror("打开文件失败");
	}
	else
	{
		//fprintf(fp, "%-3s\t%-15s\t%-5s\t%-5s\t%-11s\t%-30s\n", " ", "名字", "年龄", "性别", "电话", "地址");
		for (int i = 0; i < pc->count; i++)
		{
			fwrite(pc->person + i, sizeof(Person), 1, fp);
		}
		fclose(fp);
		fp = NULL;
	}
}




void Load_Contact(Contact* pc) {
	assert(pc);
	FILE* fp = fopen("contact.txt", "rb");
	if (fp == NULL)
	{
		perror("打开文件失败");
		return;
	}
	else
	{
		Person tmp;
		while (fread(&tmp, sizeof(Person), 1, fp))
		{
			int i = 0;
			if (pc->count == pc->capacity)
			{
				Person* ptr = (Person*)realloc(pc->person, (pc->capacity + INCREMENT_NUM) * sizeof(Person));
				if (ptr == NULL)
				{
					perror("初始化失败");
					return;
				}
				pc->person = ptr;
				pc->capacity += INCREMENT_NUM;
				printf("容量增加成功\n");
			}
			pc->person[pc->count] = tmp;
			pc->count++;
		}
		fclose(fp);
		fp = NULL;
	}
}