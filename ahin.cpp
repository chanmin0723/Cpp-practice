#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>



using namespace  std;

//최저 비용 탐색
void find(int s,int a,int value,vector <pair<int,int>> bus[],vector <int> pass,vector<int> passes[], int taked[],int &value_max){
    if((s==a)&&(value_max>value)){
        value_max = value;
        int i=0;
        while(!pass.empty()){
            passes[value_max].push_back(pass.back());
            pass.pop_back();
        }
        return; 
    }
    if((taked[s] == 1) || (s==a)){ //지나간 노드
        return;
    }
    taked[s] =1;
    int taked_tem[100001];
    copy(taked,taked+100001,taked_tem);
    vector <pair<int,int>> bus_tem;vector <int> pass_tem;
    bus_tem.resize(bus[s].size()); 
    copy(bus[s].begin(),bus[s].end(),bus_tem.begin());
    while (!bus_tem.empty()){
        pass_tem.clear();pass_tem.assign(pass.begin(), pass.end());
        int value_tem = value;
        pair <int,int> k = bus_tem.back();
        value_tem += k.second;
        bus_tem.pop_back();
        pass_tem.push_back(k.first);
        find(k.first,a,value_tem, bus, pass_tem, passes,taked,value_max);
    }
}

int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    vector <pair<int,int>> bus[100001];
    vector <int> pass;
    vector <int> passes[100001];
    for(int i=0;i<b;i++){ //버스 노선도 연결하기
        int p,q,r;
        scanf("%d %d %d",&p,&q,&r);
        bus[p].push_back(make_pair(q,r));
    }
    int st,ar;
    cin >>st>>ar;
    int value = 0;
    int value_max = 100001;
    pass.push_back(st);
    int taked[1001] = {0,};
    find(st,ar,value, bus, pass, passes, taked,value_max);
    cout << value_max <<"\n";
    cout << passes[value_max].size() << "\n";
    int size = passes[value_max].size();
    for(int j=0;j<size;j++){
        cout << passes[value_max].back() << " ";
        passes[value_max].pop_back();
    }
} 