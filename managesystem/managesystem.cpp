#include<iostream>
using namespace std;
int stuCount;
struct Student{
	char name[20];
	long num;
	int choose;
	int grade;
}student[300];

void list();
void ChooseSubject();
void DropSubject();
void InputGrade();
int find(long);

int main(){
	int action;
	RETURN:
	cout<<"1 �鿴ѧ������"<<endl;
	cout<<"2 ѡ��(���ѧ��)"<<endl;
	cout<<"3 ��ѡ��ɾ��ѧ����"<<endl;
	cout<<"4 ����ɼ�"<<endl;
	cout<<"5 �˳�����"<<endl;
	cout<<"***********������Ҫ�����Ĳ������***********"<<endl<<endl;

	cin>>action;
	do{
		switch (action)
		{
		case 1:
			list();
			break;
		case 2:
			ChooseSubject();
			break;
		case 3:
			DropSubject();
			break;
		case 4:
			InputGrade();
			break;
		case 5:
			return 0;
		default:
			cout<<"ERROR!"<<endl;
			break;
		}
		goto RETURN;
	}while (1);

}

void list(){
	cout<<"ѧ������\t"<<"ѧ�� \t\t"<<"�Ƿ�ѡ��(1����ѡ�Σ�0����ûѡ)    \t"<<"ѧ���ɼ�"<<endl;
	for (int i = 0; i < stuCount; i++)
	{
		cout<<student[i].name<<"  \t";
		cout<<student[i].num<<"\t\t";
		cout<<student[i].choose<<"\t\t\t\t";
		cout<<student[i].grade<<endl;
	}
		cout<<"********************************"<<endl<<endl;
}

void ChooseSubject(){
	struct Student studenttemp;
	studenttemp.choose=0;
	studenttemp.grade=0;
	cout<<"������ѧ������"<<endl;
	cin>>studenttemp.name;
	cout<<"������ѧ��ѧ��(ѧ�ű���С��10λ��)"<<endl;
	cin>>studenttemp.num;
	cout<<"������ѧ���Ƿ�ѡ��(1����ѡ�Σ�0����ûѡ)"<<endl;
	cin>>studenttemp.choose;
	int i=0;
	i=find(studenttemp.num);
	if (i==stuCount)
	{
		strcpy(student[i].name,studenttemp.name);
		student[i].num=studenttemp.num;
		student[i].choose=studenttemp.choose;
		stuCount++;
	}
	else
	{
		cout<<"ERROE!"<<endl;
		}
}

void DropSubject(){
	int i,j,l;
	cout<<"������ѧ��ѧ��"<<endl;
	cin>>j;
	i=find(j);
	if(i>=stuCount)
		cout<<"�������ѧ������"<<endl;
	else
		{
	cout<<"��˶�ѧ����Ϣ"<<endl;
	cout<<student[i].name<<endl;
	cout<<student[i].num<<endl;
	cout<<student[i].choose<<endl;
	cout<<student[i].grade<<endl;
	cout<<"ȷ����ѡ������1������������0"<<endl;
	cin>>l;
		if(l==1){
			student[i].choose=0;
			student[i].grade=0;
			}
		}
}

void InputGrade(){
	int i,j,l,n;
	n=1;
	do
	{
		cout<<"������ѧ��ѧ��"<<endl;
		cin>>j;
		i=find(j);
		if(i>=stuCount)
			cout<<"�������ѧ������"<<endl<<endl;
		else
		{
			cout<<"��˶�ѧ����Ϣ"<<endl;
			cout<<student[i].name<<endl;
			cout<<student[i].num<<endl;
			cout<<student[i].choose<<endl;
			cout<<student[i].grade<<endl;
			cout<<"ȷ����ӳɼ�������1������������0"<<endl;
			cin>>l;
		if(l==1){
			int n;
			cout<<"������ɼ�"<<endl;
			cin>>n;
			student[i].grade=n;
			}
		}
		cout<<"�Ƿ������ӳɼ��� ��������1������������0"<<endl;
		cin>>n;
	}while(n);
}

int find(long b){
	int m;
	for (m = 0; m < stuCount; m++)
	{
		if(student[m].num==b)
			break;
	}
	return m;
}