/*
USER: zobayer
TASK: JUNL
ALGO: ad-hoc
*/

#include <string>
#include <list>
#include <iostream>
using namespace std;

class Island {
	int shift;
	list< string > st;

	void addleft(int size) {
		string mask = "";
		list< string >::iterator it;
		for(int i = 0; i < size; i++) mask += '-';
		for(it = st.begin(); it != st.end(); it++) *it = *it + mask;
	}

	void addright(int size) {
		string mask = "";
		list< string >::iterator it;
		for(int i = 0; i < size; i++) mask += '-';
		for(it = st.begin(); it != st.end(); it++) *it = mask + *it;
		shift -= size;
	}

public:	
	void init() {
		st.clear();
		shift = 0;
	}

	void put(int pos) {
		list< string >::iterator i, prev;
		bool done = false;
		if(st.empty()) {
			st.push_front("O");
			shift = pos;
			return;
		}
		pos = pos - shift;
		prev = st.end();
		for(i = st.begin(); i != st.end(); i++) {
			if(pos >= (int)i->size()) {
				if(prev != st.end()) (*prev)[pos] = '-';
				addleft(pos - i->size() + 1);
				(*i)[pos] = 'O';
				done = true;
			}
			else if(pos < 0) {
				if(prev != st.end()) (*prev)[pos] = '-';
				addright(-pos);
				(*i)[pos = 0] = 'O';
				done = true;
			}
			else {
				if((*i)[pos] != '-') {
					if(pos + 1 >= (int)i->size()) {
						if(prev != st.end()) (*prev)[pos] = '-';
						addleft(1);
						(*i)[++pos] = 'O';
						done = true;
					}
					else if(pos + 1 < (int)i->size() && (*i)[pos + 1] == '-') {
						if(prev != st.end()) (*prev)[pos] = '-';
						(*i)[++pos] = 'O';
						done = true;
					}
					else if(pos - 1 < 0) {
						if(prev != st.end()) (*prev)[pos] = '-';
						addright(1);
						(*i)[pos = 0] = 'O';
						done = true;
					}
					else if(pos - 1 >= 0 && (*i)[pos - 1] == '-') {
						if(prev != st.end()) (*prev)[pos] = '-';
						(*i)[--pos] = 'O';
						done = true;
					}
					else break;
				}
				else {
					if(prev != st.end()) (*prev)[pos] = '-';
					(*i)[pos] = 'O';
					done = true;
				}
			}
			prev = i;
		}
		if(!done) {
			string tmp = "";
			for(size_t i = 0; i < st.begin()->size(); i++) tmp += '-';
			tmp[pos] = 'O';
			st.push_front(tmp);
		}
	}

	void print() {
		list< string >::iterator it;
		for(it = st.begin(); it != st.end(); it++) cout << *it << endl;
	}
};

int main() {
	int test, n, pos;
	Island island;
	ios::sync_with_stdio(false);
	cin >> test;
	while(test--) {
		island.init();
		cin >> n;
		while(n--) {
			cin >> pos;
			island.put(pos);
		}
		island.print();
	}
	return 0;
}