#include<bits/stdc++.h>
using namespace std; 
const int N=1e5+10;
int n,cnt=1,a[N];//cnt�����Ľڵ����� 
struct node{
	int lc=0,rc=0,val=0,w=0;//lc,rc����������,val�ǵ�ǰ�ڵ��ֵ,w�ǵ�ǰ�ڵ��м��� 
}t[N];
void insert(int o,int v){//���o����һ��v 
	if(!t[o].val){//������ڵ��ǿյ� 
		t[o].val=v;
		t[o].w++; 
		return ;
	}
	if(t[o].val==v){//������ڵ�պõ��� 
	    t[o].w++;
	    return ;
	}
    if(t[o].val>v){//������������ 
    	if(!t[o].lc){
    		cnt++;
    	    t[o].lc=cnt;
		}
    	insert(t[o].lc,v);
    	return ;
	}
	if(t[o].val<v){//������������ 
		if(!t[o].rc){
			cnt++;
		    t[o].rc=cnt;
		}
		insert(t[o].rc,v);
	}
	return ; 
}
void dfs(int o){//������ö��������� 
	if(!t[o].val) return ;
	if(t[o].lc) dfs(t[o].lc);//�������
	cout<<t[o].val<<" ";//������ڵ� 
	if(t[o].rc) dfs(t[o].rc);//���ұ��� 
	return ; 
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		insert(1,a[i]);
	}
	dfs(1);
	return 0;
}

