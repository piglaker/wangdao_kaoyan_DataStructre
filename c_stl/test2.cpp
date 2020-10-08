#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>


using namespace std;

int main()
{
    string s, s1;
    s = "HELLO";
    s1 = "HELLO";
    if(s.compare(s1) == 0)
        cout << s << " is equal to " << s1 << endl;
    else
        cout << s << " is not equal to " << s1 << endl;
    s.append(" WORLD!");
    cout << s << endl;
    printf("%s\n", s.c_str());
    if(s.compare(s1) == 0)
        cout << s << " is equal to " << s1 << endl;
    else
        cout << s << " is not equal to " << s1 << endl;
    
    stack <int> S;

	for(int i = 0;i< 5;i++){
		S.push(i);
	}	
	
	cout<<S.size()<<endl;

	cout<<S.top()<<endl;

	int tmp;

	for(int i = 0;i < 5;i++){
		S.pop();
		cout<<S.empty()<<endl;
		if(!S.empty()){
			tmp = S.top();
		}
		cout<<tmp<<endl;
	}

	int q[4] = {1,2,3,4};

	queue <int> Q;

	for(int i = 0 ;i < 4; i++){
		Q.push(q[i]);
	}

	cout<<Q.size()<<endl;

	while(!Q.empty()){
		cout<<Q.front()<<endl;
		Q.pop();
	}

	map <char, int> mp;

	mp.insert(pair<char,int>('a',2));   //key is 'c' and 2 is value.
    mp.insert(pair<char,int>('b',1));
    mp.insert(pair<char,int>('c',43));

    //inserts elements in range using insert() function in map 'mymap'.
    mp.insert(mp.begin(),mp.end());

    //declaring iterator for map
    map <char,int>::iterator it;

	it = mp.find('b');

	cout<<"Key and element's value of map are: ";
    cout<<it->first<<" and "<<it->second<<endl;

	mp['x'] = 1;

	mp['y'] = 2;

	cout<<mp.at('x')<<endl;

	mp.erase('x');

	mp.insert(pair<char, int>('a',3));

	cout<<mp.count('a')<<endl;

	vector <int> v;
    v.push_back(5);
    while(v.back() > 0)
        v.push_back(v.back() - 1);
    for(int i = 0;i < v.size();++i)
        cout << v.at(i) << ' ';
    cout << endl;
    while(!v.empty())
    {
        cout << v.back() << ' ';
        v.pop_back();
    }
    cout << endl;



    return 0;
}
