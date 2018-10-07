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
		cout << "未找到相关文件！" << endl;
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
	cout << "输入完成" << endl;
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
	cout << "1:创建顺序表" << endl;  
	cout << "2:从文件输入" << endl;  
	cout << "3:从屏幕输入" << endl;  
	cout << "4:查询（位置）" << endl;  
	cout << "5:查询（价格）" << endl;  
	cout << "6:插入" << endl;  
	cout << "7:删除" << endl;  
	cout << "8:输出" << endl;
	cout << "0:退出" << endl;  
	List L;
	BOOK e;
	int choose = -1, n, pos;
	while(choose != 0){
		cout << "请选择操作:" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			InitList(L);
			cout << "创建完毕!" << endl;
			break;
		case 2:
			BuildList(L);
			break;
		case 3:
			cout << "请输入需要读入的元素个数：" << endl;
			cin >> n;
			cout << "请输入书籍信息（空格隔开）:" <<  endl;
			ScanList(L, n);
			cout << "输入完毕!" << endl;
			break;
		case 4:
			cout << "请输入位置:" << endl;
			cin >> pos;
			if(GetElem(L, pos, e)) {
				cout << left << setw(15) << e.id << "\t" << left << setw(50)
						<< e.name << "\t" << left << setw(5) << e.price << endl
						<< endl;
			}	else
				cout << "查找失败" << endl;
			break;
		case 5:
			cout << "请输入价格:" << endl;
			cin >> pos;
			if(GetLocation(L, pos, e)){
				cout << left << setw(15) << e.id << "\t" << left << setw(50)
						<< e.name << "\t" << left << setw(5) << e.price << endl
						<< endl;
			}	else 
				cout << "查找失败" << endl;
			break;
		case 6:
			cout << "请输入位置:" << endl;
			cin >> pos;
			cout << "请输入书籍信息（空格隔开）:" << endl;
			cin >> e.id >> e.name >> e.price;
			if(InserElem(L, pos, e) ){
				cout << "插入成功！" << endl;
			}	else
				cout << "插入失败！" << endl;
			break;
		case 7:
			cout << "请输入位置：" << endl;
			cin >> pos;
			if(EraseElem(L, pos)){
				cout << "删除成功！" << endl;
			}	else
				cout << "删除失败！" << endl;
			break;
		case 8:
			if(GetList(L)){
				cout << "输出完毕" << endl;
			}	else
				cout << "输出失败" << endl;
			break;
		}
	}
	return 0;
}
