#include "iostream"
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
	cout<<name<<endl;
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
			 grade_Chinese,grade_Math,grade_English){}

cLink::cLink(){}

cStudentInfo& cLink::getData(){
	return sData;
}

cLink::~cLink(){}


//------------------------------------------------------------------------------------------------------------------------------------
//链表类
class cList  
{
private:
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
	}
	else{
		last->next=&x;
		last=last->next;
		last->next=NULL;
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
		cout<<"链表为空"<<endl;
		return nlink;
	}
	else{
		cLink* ptr=first;
		while (ptr!=NULL)
		{
			if (ptr->getData().getName()==name)
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
	if(ptr1->sData.getName()==name){
		first=first->next;
		num--;
		return true;
	}

	while (ptr2!=NULL)
	{
		//找到name值匹配的节点并删除
		if(ptr2->getData().getName()==name){
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
		cLink* prt=ptr;
		grade=ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English();
		while (ptr!=NULL)
		{
			if (ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English()>grade)
			{
				grade=ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English();
				prt=ptr;
			}
			ptr=ptr->next;
		}
		return prt;
	}

}

int cList::getnum(){return num;}

cList::~cList(){}

//--------------------------------------------------------------------------------------------------------------------------------------
//添加
bool Add(){ return true;}

/*//查找
boolean Find(){return true;}

//删除
boolean Delete(){return true;}

//功能的选择
void select(int key){
	switch(key){
		case 1: Add();
		case 2: Find();
		case 3: Delete();
		case 4: exit(0);
	}
}*/

//菜单的设计
void menu_main(){
	cout<<"\n\n\n\n\t\t\t\t\t\t"<<"简单的学生信息管理系统"<<"\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t"<<"1.添加"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t"<<"2.查找"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t"<<"3.删除"<<endl<<endl;
	cout<<"输入1~3进行操作"<<endl;
	//select((int)getchar());
}




int main(){
	menu_main();

	return 0;
}