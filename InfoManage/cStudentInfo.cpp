#include "iostream"
#include<string.h>
using namespace std;


//------------------------------------------------------------------------------------------------------------------------------------
//定义学生信息类
class cStudentInfo  
{
private:
	char name[20];//姓名
	int age;//年龄
	int id;//学号
	int gender;//性别，1表示男，2表示女
	int birth_year;//出生年份
	int birth_month;//出生月份
	int birth_day;//出生日
	float grade_Chinese;//语文成绩
	float grade_Math;//数学成绩
	float grade_English;//英语成绩
public:
	int status;//标记该节点是否被检索到
	cStudentInfo();
	cStudentInfo(char *name,int age,int id,int gender,int birth_year,int birth_month,int birth_day,
		int grade_Chinese,int grade_Math,int grade_English);
	char* getName();
	int getAge();
	int getId();
	int getGender();
	int getBirth_year();
	int getBirth_month();
	int getBirth_day();
	float getgrade_Chinese();
	float getgrade_Math();
	float getgrade_English();
	virtual ~cStudentInfo();
};

//无参构造函数
cStudentInfo::cStudentInfo(){
	strcpy(name,"annoymous");
	//cout<<name<<endl;
	age=10;
	id=0;
	gender=1;
	birth_year=1996;
	birth_month=1;
	birth_day=1;
	grade_Chinese=60;
	grade_Math=60;
	grade_English=60;
}

 
cStudentInfo::cStudentInfo(char *name,int age,int id,int gender,int birth_year,int birth_month,int birth_day,
						 int grade_Chinese,int grade_Math,int grade_English){
	strcpy(this->name,name);
	this->age=age;
	this->id=id;
	this->gender=gender;
	this->birth_day=birth_day;
	this->birth_year=birth_year;
	this->birth_month=birth_month;
	this->grade_Chinese=grade_Chinese;
	this->grade_Math=grade_Math;
	this->grade_English=grade_English;
	this->status=0;
}

char* cStudentInfo::getName(){return name;}


int cStudentInfo::getId(){return id;}

int cStudentInfo::getAge(){return age;}

int cStudentInfo::getGender(){return gender;}

int cStudentInfo::getBirth_day(){return birth_day;}

int cStudentInfo::getBirth_month(){return birth_month;}

int cStudentInfo::getBirth_year(){return birth_year;}

float cStudentInfo::getgrade_Chinese(){return grade_Chinese;}

float cStudentInfo::getgrade_Math(){return grade_Math;}

float cStudentInfo::getgrade_English(){return grade_English;}

cStudentInfo::~cStudentInfo(){}


//------------------------------------------------------------------------------------------------------------------------------------
//链表节点类
class cLink  
{
	friend class cList;
private:
    cLink * next;//指向下一个结点的指针
	cStudentInfo sData;
public:
	cLink();
	cStudentInfo& getData();
	virtual ~cLink();
    cLink(char *name,int age,int id,int gender,int birth_year,int birth_month,int birth_day,
		int grade_Chinese,int grade_Math,int grade_English);//带参数的构造函数
	
};

cLink::cLink(char *name,int age,int id,int gender,int birth_year,int birth_month,int birth_day,
			 int grade_Chinese,int grade_Math,int grade_English):sData(name,age,id,gender,birth_year,birth_month,birth_day,
			 grade_Chinese,grade_Math,grade_English){
}

cLink::cLink(){}

cStudentInfo& cLink::getData(){return sData;}

cLink::~cLink(){}


//------------------------------------------------------------------------------------------------------------------------------------
//链表类
class cList  
{
public:
	cLink* first;
	cLink* last;
	int num;//统计链表中节点个数
public:
	cList();
	cList &Add(cLink& x);//向链表尾添加节点
	bool Delete(int id);//根据ID删除节点
	bool Delete(char *name);//根据姓名删除节点
	cLink &Search(char *name);//根据姓名找出节点
	cLink &Search(int id);//根据学号找到节点
	cLink* getMax();//找出总成绩最大值
	cLink* getMini();//找出总成绩最小值
	void sort();//排序输出所有节点信息
	int getnum();
	virtual ~cList();	
};

cList::cList(){
	//first=new cLink;
	//last=new cLink;
	first=last=NULL;
	num=0;
}

//添加节点
cList& cList::Add(cLink& x){
	//如果first指针为空，说明是空链表
	if (first==NULL)
	{
		first=&x;
		last=&x;
		last->next=NULL;
		num++;
		cout<<first->getData().getName()<<endl;
	}
	else{
		last->next=&x;
		last=last->next;	
		if(num==1) first->next=last;
		last->next=NULL;
		cout<<last->getData().getName()<<endl;
		num++;
	}
	
	return (*this);
}

//按照学号找节点
cLink& cList::Search(int id){
	static cLink nlink;
	//first为空，说明链表为空
	if (first==NULL)
	{
		//添加处理后跳出
		cout<<"链表为空"<<endl;
		return nlink;
	}
	else{
		cLink* ptr=first;
		while (ptr!=NULL)
		{
			if (ptr->getData().getId()==id)
			{
				cout<<"HHHHH"<<endl;
				return *ptr;
			}
			ptr=ptr->next;
		}
		//未找到对应的值，处理后退出
		cout<<"没有相应的值"<<endl;
		return nlink;
	}
}

//按照姓名找出节点
cLink& cList::Search(char *name){
	static cLink nlink;
	//first为空，说明链表为空
	if (first==NULL)
	{
		//添加处理后跳出
		return nlink;
	}
	else{
		cout<<first->getData().getName()<<endl;
		cLink* ptr=first;
		while (ptr!=NULL)
		{
			if (!strcmp(ptr->getData().getName(),name))
			{
				cout<<"HHH"<<endl;
				return *ptr;
			}
			ptr=ptr->next;
		}
		//未找到对应的值，处理后退出，此处可以有throw
		cout<<"没有相应的值"<<endl;
		return nlink;
	}
}

//按照姓名删去节点
bool cList::Delete(char *name){
	cLink* ptr1;
	cLink* ptr2;
	ptr1=first;
	ptr2=first->next;
	//链表为空
	if(num==0){
		cout<<"链表为空"<<endl;
		return false;
	}	
	//与头节点匹配
	if(!strcmp(ptr1->sData.getName(),name)){
		cout<<"删去了头节点"<<endl;
		first=first->next;
		cout<<first->getData().getName()<<endl;
		cout<<last->getData().getName()<<endl;
		num--;
		return true;
	}
	while (ptr2!=NULL)
	{
		//找到name值匹配的节点并删除
		if(!strcmp(ptr2->getData().getName(),name)){
			//判断删去节点是否为尾节点
			if (ptr2==last)
			{
				last=ptr1;
				num--;
			}else{
				ptr1->next=ptr2->next;
				num--;
			}
			return true;
		}
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}	
	return false;
}

//按照学号删去节点
bool cList::Delete(int id){
	cLink* ptr1;
	cLink* ptr2;
	ptr1=first;
	ptr2=first->next;	
	//链表为空
	if(num==0){
		cout<<"链表为空"<<endl;
		return false;
	}
	
	//与头节点匹配
	if(ptr1->sData.getId()==id){
		first=first->next;
		num--;
		return true;
	}	
	while (ptr2!=NULL)
	{
		//找到name值匹配的节点并删除
		if(ptr2->getData().getId()==id){
			ptr1->next=ptr2->next;
			//判断删去节点是否为尾节点
			if (ptr2==last)
			{
				last=ptr1->next;
			}
			return true;
		}
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}	
	return false;
}

//找出总成绩最大的节点
cLink* cList::getMax(){
	if (num==0)
	{
		cout<<"表为空"<<endl;
		return NULL;
	}else{
		float grade;
		cLink* ptr=first;
		cout<<first->next->getData().getName();
		cLink* prt=ptr;
		grade=ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English();
		cout<<grade<<endl;
		while (ptr!=NULL)
		{
			if (ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English()>grade)
			{
				grade=ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English();
				cout<<grade<<endl;
				prt=ptr;
			}
			ptr=ptr->next;
		}
		return prt;
	}

}

//找出总成绩最小的节点
cLink* cList::getMini(){
	if (num==0)
	{
		cout<<"表为空"<<endl;
		return NULL;
	}else{
		float grade;
		cLink* ptr=first;
		cLink* prt=ptr;
		grade=ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English();
		while (ptr!=NULL)
		{
			if (ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English()<grade)
			{
				grade=ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English();
				prt=ptr;
			}
			ptr=ptr->next;
		}
		return prt;
	}
}

//排序输出所有节点信息
/*根据找出最大的值的函数改写，将已经找出的大值标为已经找到的状态*/
void cList::sort(){
	cLink* ptr;
	cLink* prt;
	int grade;
	cLink* p=first;
	while(p!=NULL){
		p->getData().status=0;
		p=p->next;
	}
	for(int i=0;i<num;i++){
	if (num==0)
	{
		cout<<"表为空"<<endl;
	}else{		

		prt=getMini();
		ptr=first;
		grade=prt->getData().getgrade_Chinese()+prt->getData().getgrade_Math()+prt->getData().getgrade_English();
		while (ptr!=NULL)
		{
			if (ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English()>grade&&ptr->getData().status!=1)
			{
				grade=ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English();
				prt->getData().status=0;//将之前找到的最大值节点状态置0
				prt=ptr;
				prt->getData().status=1;//将新找到的最大值节点状态置1
			}
			ptr=ptr->next;
		}
		if(prt!=NULL){
		cStudentInfo* cstudent=&prt->getData();
		cout<<"第"<<i+1<<"位"<<endl;
		cout<<"姓名："<<cstudent->getName()<<endl;
		cout<<"学号："<<cstudent->getId()<<endl;
		cout<<"性别：";
		if (cstudent->getGender()==1)
			cout<<"男"<<endl;
		else
			cout<<"女"<<endl;
		cout<<"出生日期:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
		cout<<"语文："<<cstudent->getgrade_Chinese()<<endl;
		cout<<"数学："<<cstudent->getgrade_Math()<<endl;
		cout<<"英语："<<cstudent->getgrade_English()<<endl; 
		cout<<"总分："<<grade<<endl;
		cout<<endl<<endl;	
		}
	}
	}
}

int cList::getnum(){return num;}

cList::~cList(){}


//--------------------------------------------------------------------------------------------------------------------------------------
//添加函数 
void Add(cList& list){
	cout<<"-------添加信息-------"<<endl;
	cout<<"请输入相关信息,学号，年龄，性别(1表示男，2表示女)，出生年月日(以空格分隔，例如：1996 01 01)，语数外成绩（以空格分隔，例如：60 60 60）"<<endl;
	int id,age,gender,birth_year,birth_month,birth_day,grade_Chinese,grade_Math,grade_English;
	char *name=new char[20]; 
	cin>>name>>age>>id>>gender>>birth_year>>birth_month>>birth_day>>grade_Chinese>>grade_Math>>grade_English; 
	//建立学生节点 
	/*此处不能使用cLink studentLink,局部变量，空间被释放，指针指向的地址被回收
	  同时不能使用static cLink studentLink,全局变量，空间固定，所有的指针均指向一块相同的空间*/
	cLink* studentLink=new cLink(name,age,id,gender,birth_year,birth_month,birth_day,grade_Chinese,grade_Math,grade_English); 
	cout<<studentLink->getData().getName()<<endl;
	list.Add(*studentLink); 
	cout<<endl<<endl;
}
	
//按姓名查找
void Find_byName(cList& list){
	cout<<"-------按姓名查找-------"<<endl;
	cout<<"输入姓名"<<endl; 
	char* name=new char[20];
	cin>>name;
	cout<<list.first->getData().getName()<<endl;
	cStudentInfo* cstudent=&(list.Search(name).getData()); 
	if(cstudent->getId()==0){
		cout<<"找不到"<<name<<endl; 
	}else{
		cout<<"找到的信息如下:"<<endl;
		cout<<"姓名："<<cstudent->getName()<<endl;
		cout<<"学号："<<cstudent->getId()<<endl;
		cout<<"性别：";
		if (cstudent->getGender()==1)
			cout<<"男"<<endl;
		else
			cout<<"女"<<endl;
		cout<<"出生日期:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
		cout<<"语文："<<cstudent->getgrade_Chinese()<<endl;
		cout<<"数学："<<cstudent->getgrade_Math()<<endl;
		cout<<"英语："<<cstudent->getgrade_English()<<endl; 
	}
	cout<<endl<<endl;
}

//按学号查找 
void Find_byId(cList& list){
	cout<<"-------按学号查找-------"<<endl;
	cout<<"输入学号"<<endl; 
	int Id;
	cin>>Id; 
	cStudentInfo* cstudent=&(list.Search(Id).getData()); 
	if(cstudent->getId()==0){
		cout<<"找不到"<<Id<<endl; 
	}else{
		cout<<"找到的信息如下:"<<endl;
		cout<<"姓名："<<cstudent->getName()<<endl;
		cout<<"学号："<<cstudent->getId()<<endl;
		cout<<"性别：";
		if (cstudent->getGender()==1)
			cout<<"男"<<endl;
		else
			cout<<"女"<<endl;
		cout<<"出生日期:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
		cout<<"语文："<<cstudent->getgrade_Chinese()<<endl;
		cout<<"数学："<<cstudent->getgrade_Math()<<endl;
		cout<<"英语："<<cstudent->getgrade_English()<<endl; 
	}
	cout<<endl<<endl;
}

//按姓名删除
void Delete_byName(cList &list){
	cout<<"-------按姓名删除-------"<<endl;
	cout<<"输入姓名"<<endl; 
	char* name=new char[20];
	cin>>name;
	list.Delete(name);
} 

//按学号删除 
void Delete_byId(cList &list){
	cout<<"-------按学号删除-------"<<endl;
	cout<<"输入学号"<<endl;
	int Id;
	cin>>Id;
	list.Delete(Id); 
	cout<<endl<<endl;
}

//得到最大值 
void getMax(cList &list){
	cout<<"-------找到最大值-------"<<endl;
	cout<<list.first->getData().getName();
	cStudentInfo* cstudent=&(list.getMax()->getData()); 
	cout<<"找到的信息如下:"<<endl;
	cout<<"姓名："<<cstudent->getName()<<endl;
	cout<<"学号："<<cstudent->getId()<<endl;
	cout<<"性别：";
	if (cstudent->getGender()==1)
		cout<<"男"<<endl;
	else
		cout<<"女"<<endl;
	cout<<"出生日期:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
	cout<<"语文："<<cstudent->getgrade_Chinese()<<endl;
	cout<<"数学："<<cstudent->getgrade_Math()<<endl;
	cout<<"英语："<<cstudent->getgrade_English()<<endl; 
	cout<<endl<<endl;
} 

//得到最小值 
void getMini(cList &list){
	cout<<"-------找最小值-------"<<endl;
	cStudentInfo* cstudent=&(list.getMini()->getData()); 
	cout<<"找到的信息如下:"<<endl;
	cout<<"姓名："<<cstudent->getName()<<endl;
	cout<<"学号："<<cstudent->getId()<<endl;
	cout<<"性别：";
	if (cstudent->getGender()==1)
		cout<<"男"<<endl;
	else
		cout<<"女"<<endl;
	cout<<"出生日期:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
	cout<<"语文："<<cstudent->getgrade_Chinese()<<endl;
	cout<<"数学："<<cstudent->getgrade_Math()<<endl;
	cout<<"英语："<<cstudent->getgrade_English()<<endl; 
	cout<<endl<<endl;
} 

//排序输出所有节点信息
void SortOutput(cList& list){
	cout<<"-------按降序输出信息-------"<<endl;
	list.sort();
}

//主功能的选择
void Select(int key,cList &list){
	switch(key){
		case '1': Add(list); break;
		case '2': Find_byName(list); break;
		case '3': Find_byId(list); break;
		case '4': Delete_byName(list); break;
		case '5': Delete_byId(list); break;
		case '6': getMax(list); break;
		case '7': getMini(list); break;
		case '8': SortOutput(list);break;
		case '9': exit(0);
		default: cout<<"输入有误"<<endl; 
	}
}

//菜单的设计
void menu_main(){
	freopen("input.txt","r",stdin);
	cList InfoList;
	char c;
	cout<<"简单的学生信息管理系统"<<endl;
	cout<<"1.添加"<<endl<<endl;
	cout<<"2.按姓名查找"<<endl<<endl;
	cout<<"3.按学号查找"<<endl<<endl;
	cout<<"4.按姓名删除"<<endl<<endl;
	cout<<"5.按学号删除"<<endl<<endl;
	cout<<"6.找出最大值"<<endl<<endl;
	cout<<"7.找出最小值"<<endl<<endl;
	cout<<"8.按序输出"<<endl<<endl;
	cout<<"9.退出"<<endl<<endl; 
	cout<<"输入1~8进行操作"<<endl;
	while (cin>>c&&c!=9)
	{
		Select(c,InfoList);
		cout<<"当前学生总数为"<<InfoList.num<<endl;
		cout<<"输入1~9进行操作"<<endl;
	}
}

int main(){
	menu_main();
	return 0;
}
