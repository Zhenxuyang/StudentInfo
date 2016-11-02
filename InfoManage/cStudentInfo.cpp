#include "iostream"
#include<string.h>
using namespace std;


//------------------------------------------------------------------------------------------------------------------------------------
//����ѧ����Ϣ��
class cStudentInfo  
{
private:
	char name[20];//����
	int age;//����
	int id;//ѧ��
	int gender;//�Ա�1��ʾ�У�2��ʾŮ
	int birth_year;//�������
	int birth_month;//�����·�
	int birth_day;//������
	float grade_Chinese;//���ĳɼ�
	float grade_Math;//��ѧ�ɼ�
	float grade_English;//Ӣ��ɼ�
public:
	int status;//��Ǹýڵ��Ƿ񱻼�����
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

//�޲ι��캯��
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
//����ڵ���
class cLink  
{
	friend class cList;
private:
    cLink * next;//ָ����һ������ָ��
	cStudentInfo sData;
public:
	cLink();
	cStudentInfo& getData();
	virtual ~cLink();
    cLink(char *name,int age,int id,int gender,int birth_year,int birth_month,int birth_day,
		int grade_Chinese,int grade_Math,int grade_English);//�������Ĺ��캯��
	
};

cLink::cLink(char *name,int age,int id,int gender,int birth_year,int birth_month,int birth_day,
			 int grade_Chinese,int grade_Math,int grade_English):sData(name,age,id,gender,birth_year,birth_month,birth_day,
			 grade_Chinese,grade_Math,grade_English){
}

cLink::cLink(){}

cStudentInfo& cLink::getData(){return sData;}

cLink::~cLink(){}


//------------------------------------------------------------------------------------------------------------------------------------
//������
class cList  
{
public:
	cLink* first;
	cLink* last;
	int num;//ͳ�������нڵ����
public:
	cList();
	cList &Add(cLink& x);//������β��ӽڵ�
	bool Delete(int id);//����IDɾ���ڵ�
	bool Delete(char *name);//��������ɾ���ڵ�
	cLink &Search(char *name);//���������ҳ��ڵ�
	cLink &Search(int id);//����ѧ���ҵ��ڵ�
	cLink* getMax();//�ҳ��ܳɼ����ֵ
	cLink* getMini();//�ҳ��ܳɼ���Сֵ
	void sort();//����������нڵ���Ϣ
	int getnum();
	virtual ~cList();	
};

cList::cList(){
	//first=new cLink;
	//last=new cLink;
	first=last=NULL;
	num=0;
}

//��ӽڵ�
cList& cList::Add(cLink& x){
	//���firstָ��Ϊ�գ�˵���ǿ�����
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

//����ѧ���ҽڵ�
cLink& cList::Search(int id){
	static cLink nlink;
	//firstΪ�գ�˵������Ϊ��
	if (first==NULL)
	{
		//��Ӵ��������
		cout<<"����Ϊ��"<<endl;
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
		//δ�ҵ���Ӧ��ֵ��������˳�
		cout<<"û����Ӧ��ֵ"<<endl;
		return nlink;
	}
}

//���������ҳ��ڵ�
cLink& cList::Search(char *name){
	static cLink nlink;
	//firstΪ�գ�˵������Ϊ��
	if (first==NULL)
	{
		//��Ӵ��������
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
		//δ�ҵ���Ӧ��ֵ��������˳����˴�������throw
		cout<<"û����Ӧ��ֵ"<<endl;
		return nlink;
	}
}

//��������ɾȥ�ڵ�
bool cList::Delete(char *name){
	cLink* ptr1;
	cLink* ptr2;
	ptr1=first;
	ptr2=first->next;
	//����Ϊ��
	if(num==0){
		cout<<"����Ϊ��"<<endl;
		return false;
	}	
	//��ͷ�ڵ�ƥ��
	if(!strcmp(ptr1->sData.getName(),name)){
		cout<<"ɾȥ��ͷ�ڵ�"<<endl;
		first=first->next;
		cout<<first->getData().getName()<<endl;
		cout<<last->getData().getName()<<endl;
		num--;
		return true;
	}
	while (ptr2!=NULL)
	{
		//�ҵ�nameֵƥ��Ľڵ㲢ɾ��
		if(!strcmp(ptr2->getData().getName(),name)){
			//�ж�ɾȥ�ڵ��Ƿ�Ϊβ�ڵ�
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

//����ѧ��ɾȥ�ڵ�
bool cList::Delete(int id){
	cLink* ptr1;
	cLink* ptr2;
	ptr1=first;
	ptr2=first->next;	
	//����Ϊ��
	if(num==0){
		cout<<"����Ϊ��"<<endl;
		return false;
	}
	
	//��ͷ�ڵ�ƥ��
	if(ptr1->sData.getId()==id){
		first=first->next;
		num--;
		return true;
	}	
	while (ptr2!=NULL)
	{
		//�ҵ�nameֵƥ��Ľڵ㲢ɾ��
		if(ptr2->getData().getId()==id){
			ptr1->next=ptr2->next;
			//�ж�ɾȥ�ڵ��Ƿ�Ϊβ�ڵ�
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

//�ҳ��ܳɼ����Ľڵ�
cLink* cList::getMax(){
	if (num==0)
	{
		cout<<"��Ϊ��"<<endl;
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

//�ҳ��ܳɼ���С�Ľڵ�
cLink* cList::getMini(){
	if (num==0)
	{
		cout<<"��Ϊ��"<<endl;
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

//����������нڵ���Ϣ
/*�����ҳ�����ֵ�ĺ�����д�����Ѿ��ҳ��Ĵ�ֵ��Ϊ�Ѿ��ҵ���״̬*/
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
		cout<<"��Ϊ��"<<endl;
	}else{		

		prt=getMini();
		ptr=first;
		grade=prt->getData().getgrade_Chinese()+prt->getData().getgrade_Math()+prt->getData().getgrade_English();
		while (ptr!=NULL)
		{
			if (ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English()>grade&&ptr->getData().status!=1)
			{
				grade=ptr->getData().getgrade_Chinese()+ptr->getData().getgrade_Math()+ptr->getData().getgrade_English();
				prt->getData().status=0;//��֮ǰ�ҵ������ֵ�ڵ�״̬��0
				prt=ptr;
				prt->getData().status=1;//�����ҵ������ֵ�ڵ�״̬��1
			}
			ptr=ptr->next;
		}
		if(prt!=NULL){
		cStudentInfo* cstudent=&prt->getData();
		cout<<"��"<<i+1<<"λ"<<endl;
		cout<<"������"<<cstudent->getName()<<endl;
		cout<<"ѧ�ţ�"<<cstudent->getId()<<endl;
		cout<<"�Ա�";
		if (cstudent->getGender()==1)
			cout<<"��"<<endl;
		else
			cout<<"Ů"<<endl;
		cout<<"��������:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
		cout<<"���ģ�"<<cstudent->getgrade_Chinese()<<endl;
		cout<<"��ѧ��"<<cstudent->getgrade_Math()<<endl;
		cout<<"Ӣ�"<<cstudent->getgrade_English()<<endl; 
		cout<<"�ܷ֣�"<<grade<<endl;
		cout<<endl<<endl;	
		}
	}
	}
}

int cList::getnum(){return num;}

cList::~cList(){}


//--------------------------------------------------------------------------------------------------------------------------------------
//��Ӻ��� 
void Add(cList& list){
	cout<<"-------�����Ϣ-------"<<endl;
	cout<<"�����������Ϣ,ѧ�ţ����䣬�Ա�(1��ʾ�У�2��ʾŮ)������������(�Կո�ָ������磺1996 01 01)��������ɼ����Կո�ָ������磺60 60 60��"<<endl;
	int id,age,gender,birth_year,birth_month,birth_day,grade_Chinese,grade_Math,grade_English;
	char *name=new char[20]; 
	cin>>name>>age>>id>>gender>>birth_year>>birth_month>>birth_day>>grade_Chinese>>grade_Math>>grade_English; 
	//����ѧ���ڵ� 
	/*�˴�����ʹ��cLink studentLink,�ֲ��������ռ䱻�ͷţ�ָ��ָ��ĵ�ַ������
	  ͬʱ����ʹ��static cLink studentLink,ȫ�ֱ������ռ�̶������е�ָ���ָ��һ����ͬ�Ŀռ�*/
	cLink* studentLink=new cLink(name,age,id,gender,birth_year,birth_month,birth_day,grade_Chinese,grade_Math,grade_English); 
	cout<<studentLink->getData().getName()<<endl;
	list.Add(*studentLink); 
	cout<<endl<<endl;
}
	
//����������
void Find_byName(cList& list){
	cout<<"-------����������-------"<<endl;
	cout<<"��������"<<endl; 
	char* name=new char[20];
	cin>>name;
	cout<<list.first->getData().getName()<<endl;
	cStudentInfo* cstudent=&(list.Search(name).getData()); 
	if(cstudent->getId()==0){
		cout<<"�Ҳ���"<<name<<endl; 
	}else{
		cout<<"�ҵ�����Ϣ����:"<<endl;
		cout<<"������"<<cstudent->getName()<<endl;
		cout<<"ѧ�ţ�"<<cstudent->getId()<<endl;
		cout<<"�Ա�";
		if (cstudent->getGender()==1)
			cout<<"��"<<endl;
		else
			cout<<"Ů"<<endl;
		cout<<"��������:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
		cout<<"���ģ�"<<cstudent->getgrade_Chinese()<<endl;
		cout<<"��ѧ��"<<cstudent->getgrade_Math()<<endl;
		cout<<"Ӣ�"<<cstudent->getgrade_English()<<endl; 
	}
	cout<<endl<<endl;
}

//��ѧ�Ų��� 
void Find_byId(cList& list){
	cout<<"-------��ѧ�Ų���-------"<<endl;
	cout<<"����ѧ��"<<endl; 
	int Id;
	cin>>Id; 
	cStudentInfo* cstudent=&(list.Search(Id).getData()); 
	if(cstudent->getId()==0){
		cout<<"�Ҳ���"<<Id<<endl; 
	}else{
		cout<<"�ҵ�����Ϣ����:"<<endl;
		cout<<"������"<<cstudent->getName()<<endl;
		cout<<"ѧ�ţ�"<<cstudent->getId()<<endl;
		cout<<"�Ա�";
		if (cstudent->getGender()==1)
			cout<<"��"<<endl;
		else
			cout<<"Ů"<<endl;
		cout<<"��������:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
		cout<<"���ģ�"<<cstudent->getgrade_Chinese()<<endl;
		cout<<"��ѧ��"<<cstudent->getgrade_Math()<<endl;
		cout<<"Ӣ�"<<cstudent->getgrade_English()<<endl; 
	}
	cout<<endl<<endl;
}

//������ɾ��
void Delete_byName(cList &list){
	cout<<"-------������ɾ��-------"<<endl;
	cout<<"��������"<<endl; 
	char* name=new char[20];
	cin>>name;
	list.Delete(name);
} 

//��ѧ��ɾ�� 
void Delete_byId(cList &list){
	cout<<"-------��ѧ��ɾ��-------"<<endl;
	cout<<"����ѧ��"<<endl;
	int Id;
	cin>>Id;
	list.Delete(Id); 
	cout<<endl<<endl;
}

//�õ����ֵ 
void getMax(cList &list){
	cout<<"-------�ҵ����ֵ-------"<<endl;
	cout<<list.first->getData().getName();
	cStudentInfo* cstudent=&(list.getMax()->getData()); 
	cout<<"�ҵ�����Ϣ����:"<<endl;
	cout<<"������"<<cstudent->getName()<<endl;
	cout<<"ѧ�ţ�"<<cstudent->getId()<<endl;
	cout<<"�Ա�";
	if (cstudent->getGender()==1)
		cout<<"��"<<endl;
	else
		cout<<"Ů"<<endl;
	cout<<"��������:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
	cout<<"���ģ�"<<cstudent->getgrade_Chinese()<<endl;
	cout<<"��ѧ��"<<cstudent->getgrade_Math()<<endl;
	cout<<"Ӣ�"<<cstudent->getgrade_English()<<endl; 
	cout<<endl<<endl;
} 

//�õ���Сֵ 
void getMini(cList &list){
	cout<<"-------����Сֵ-------"<<endl;
	cStudentInfo* cstudent=&(list.getMini()->getData()); 
	cout<<"�ҵ�����Ϣ����:"<<endl;
	cout<<"������"<<cstudent->getName()<<endl;
	cout<<"ѧ�ţ�"<<cstudent->getId()<<endl;
	cout<<"�Ա�";
	if (cstudent->getGender()==1)
		cout<<"��"<<endl;
	else
		cout<<"Ů"<<endl;
	cout<<"��������:"<<cstudent->getBirth_year()<<"-"<<cstudent->getBirth_month()<<"-"<<cstudent->getBirth_day()<<endl;
	cout<<"���ģ�"<<cstudent->getgrade_Chinese()<<endl;
	cout<<"��ѧ��"<<cstudent->getgrade_Math()<<endl;
	cout<<"Ӣ�"<<cstudent->getgrade_English()<<endl; 
	cout<<endl<<endl;
} 

//����������нڵ���Ϣ
void SortOutput(cList& list){
	cout<<"-------�����������Ϣ-------"<<endl;
	list.sort();
}

//�����ܵ�ѡ��
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
		default: cout<<"��������"<<endl; 
	}
}

//�˵������
void menu_main(){
	freopen("input.txt","r",stdin);
	cList InfoList;
	char c;
	cout<<"�򵥵�ѧ����Ϣ����ϵͳ"<<endl;
	cout<<"1.���"<<endl<<endl;
	cout<<"2.����������"<<endl<<endl;
	cout<<"3.��ѧ�Ų���"<<endl<<endl;
	cout<<"4.������ɾ��"<<endl<<endl;
	cout<<"5.��ѧ��ɾ��"<<endl<<endl;
	cout<<"6.�ҳ����ֵ"<<endl<<endl;
	cout<<"7.�ҳ���Сֵ"<<endl<<endl;
	cout<<"8.�������"<<endl<<endl;
	cout<<"9.�˳�"<<endl<<endl; 
	cout<<"����1~8���в���"<<endl;
	while (cin>>c&&c!=9)
	{
		Select(c,InfoList);
		cout<<"��ǰѧ������Ϊ"<<InfoList.num<<endl;
		cout<<"����1~9���в���"<<endl;
	}
}

int main(){
	menu_main();
	return 0;
}
