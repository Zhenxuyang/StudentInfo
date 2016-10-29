#include "iostream"
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
			 grade_Chinese,grade_Math,grade_English){}

cLink::cLink(){}

cStudentInfo& cLink::getData(){
	return sData;
}

cLink::~cLink(){}


//------------------------------------------------------------------------------------------------------------------------------------
//������
class cList  
{
private:
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
	}
	else{
		last->next=&x;
		last=last->next;
		last->next=NULL;
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
		cout<<"����Ϊ��"<<endl;
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
	if(ptr1->sData.getName()==name){
		first=first->next;
		num--;
		return true;
	}

	while (ptr2!=NULL)
	{
		//�ҵ�nameֵƥ��Ľڵ㲢ɾ��
		if(ptr2->getData().getName()==name){
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
//���
bool Add(){ return true;}

/*//����
boolean Find(){return true;}

//ɾ��
boolean Delete(){return true;}

//���ܵ�ѡ��
void select(int key){
	switch(key){
		case 1: Add();
		case 2: Find();
		case 3: Delete();
		case 4: exit(0);
	}
}*/

//�˵������
void menu_main(){
	cout<<"\n\n\n\n\t\t\t\t\t\t"<<"�򵥵�ѧ����Ϣ����ϵͳ"<<"\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t"<<"1.���"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t"<<"2.����"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t"<<"3.ɾ��"<<endl<<endl;
	cout<<"����1~3���в���"<<endl;
	//select((int)getchar());
}




int main(){
	menu_main();

	return 0;
}