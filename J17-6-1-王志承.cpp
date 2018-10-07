#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
struct BOOK {
	string id;
	string name;
	double price;
};
string head_1, head_2, head_3;
typedef struct {
	int length;
	int maxs = MAXSIZE;
	BOOK *start;
} List;

void InitList(List &L) {
	L.start = new BOOK[MAXSIZE];
	L.length = 0;
}

void BuildList(List &L) {
	BOOK e;
	fstream file;
	file.open("book.txt");
	if(!file) {
		cout << "δ�ҵ�����ļ���" << endl;
		return;
	}
	file >> head_1 >> head_2 >> head_3;
	while(!file.eof()) {
		if(L.length == L.maxs - 1){
			cout << "overflow!" << endl;
			return;
		}
		++L.length;
		file >> L.start[L.length].id >> L.start[L.length].name >> L.start[L.length].price;	
	}
	file.close();
	cout << "�������" << endl;
}

void ScanList(List &L, int n) {
	BOOK e;
	while(n--) {
		if(L.length == L.maxs - 1){
			cout << "overflow!" << endl;
			return;
		}
		++L.length;
		cin >> e.id >> e.name >> e.price;
		L.start[L.length] = e;
	}
}

int InserElem(List &L, int pos, BOOK e) {
	if(pos > L.length)
		return 0;
	for(int i=L.length; i>=pos; --i) {
		L.start[i+1] = L.start[i];
	}
	L.start[pos] = e;
	++L.length;
	return 1;
}

int EraseElem(List &L, int pos) {
	if(pos > L.length)
		return 0;
	for(int i=pos;i<L.length;++i) {
		L.start[i] = L.start[i+1];
	}
	--L.length;
	return 1;
}

int GetLocation(List &L, int p, BOOK &e) {
	int now = 1;
	while(now <= L.length && L.start[now].price != p)
		++now;
	if(now > L.length || L.start[now].price != p)
		return 0;
	e = L.start[now];
	return 1;
}
int GetElem(List &L, int pos, BOOK &e) {
	if(pos > L.length)
		return 0;
	e = L.start[pos];
	return 1;
}

int GetList(List &L) {
	int now = 1;
	BOOK e;
	if(L.length == 0)
		return 0;
	while(now <= L.length) {
		e = L.start[now];
		cout << left << setw(15) << e.id << "\t" << left << setw(50)
				<< e.name << "\t" << left << setw(5) << e.price << endl;
		++now;
	}
	return 1;
}

int main(int argc, char const *argv[])
{  
	cout << "1:����˳���" << endl;  
	cout << "2:���ļ�����" << endl;  
	cout << "3:����Ļ����" << endl;  
	cout << "4:��ѯ��λ�ã�" << endl;  
	cout << "5:��ѯ���۸�" << endl;  
	cout << "6:����" << endl;  
	cout << "7:ɾ��" << endl;  
	cout << "8:���" << endl;
	cout << "0:�˳�" << endl;  
	List L;
	BOOK e;
	int choose = -1, n, pos;
	while(choose != 0){
		cout << "��ѡ�����:" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			InitList(L);
			cout << "�������!" << endl;
			break;
		case 2:
			BuildList(L);
			break;
		case 3:
			cout << "��������Ҫ�����Ԫ�ظ�����" << endl;
			cin >> n;
			cout << "�������鼮��Ϣ���ո������:" <<  endl;
			ScanList(L, n);
			cout << "�������!" << endl;
			break;
		case 4:
			cout << "������λ��:" << endl;
			cin >> pos;
			if(GetElem(L, pos, e)) {
				cout << left << setw(15) << e.id << "\t" << left << setw(50)
						<< e.name << "\t" << left << setw(5) << e.price << endl
						<< endl;
			}	else
				cout << "����ʧ��" << endl;
			break;
		case 5:
			cout << "������۸�:" << endl;
			cin >> pos;
			if(GetLocation(L, pos, e)){
				cout << left << setw(15) << e.id << "\t" << left << setw(50)
						<< e.name << "\t" << left << setw(5) << e.price << endl
						<< endl;
			}	else 
				cout << "����ʧ��" << endl;
			break;
		case 6:
			cout << "������λ��:" << endl;
			cin >> pos;
			cout << "�������鼮��Ϣ���ո������:" << endl;
			cin >> e.id >> e.name >> e.price;
			if(InserElem(L, pos, e) ){
				cout << "����ɹ���" << endl;
			}	else
				cout << "����ʧ�ܣ�" << endl;
			break;
		case 7:
			cout << "������λ�ã�" << endl;
			cin >> pos;
			if(EraseElem(L, pos)){
				cout << "ɾ���ɹ���" << endl;
			}	else
				cout << "ɾ��ʧ�ܣ�" << endl;
			break;
		case 8:
			if(GetList(L)){
				cout << "������" << endl;
			}	else
				cout << "���ʧ��" << endl;
			break;
		}
	}
	return 0;
}
