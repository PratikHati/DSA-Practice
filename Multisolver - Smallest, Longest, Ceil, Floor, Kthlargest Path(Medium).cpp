#include<bits/stdc++.h>

using namespace std;

class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};


struct myComp {
  bool operator()(
    pair<int, string>& a,
    pair<int, string>& b)
  {
    return a.first > b.first;
  }
};
string spath;
int spathwt = INT_MAX;
string lpath;
int lpathwt = INT_MIN;
string cpath;
int cpathwt = INT_MAX;
string fpath;
int fpathwt = INT_MIN;

priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;

void multisolver(vector<Edge> graph[], int src, int dest, vector<bool> visited, int criteria, int k, string psf, int wsf) {
  //write your code here
  if(src == dest){
    if(spathwt > wsf){    //smallest
      spathwt = wsf;
      spath = psf;
    }

    if(lpathwt < wsf){    //largest
      
      lpathwt = wsf;
      lpath = psf;
    }

    if(wsf < criteria){   //floor
      if(wsf > fpathwt){
        fpathwt = wsf;
        fpath = psf;
      }
    
    }
    if(wsf > criteria){   //ceil
      if(wsf < cpathwt){
        cpathwt = wsf;
        cpath = psf;
      }
      
    }

    if(pq.size() <k){
      pq.push(make_pair(wsf,psf));
    }
    else{
      if(pq.top().first < wsf){
        pq.pop();
        pq.push(make_pair(wsf,psf));
      }
    }
    
    
    return;
  }


  int size= graph[src].size();
  visited[src] = true;

  for(int i=0;i<size;i++){

    int index = graph[src][i].nbr;
    int val = graph[src][i].wt;

    if(visited[index] == false){
      
      char temp = index+48;
      
      psf.push_back(temp);
      
      multisolver(graph,index,dest,visited,criteria,k,psf,wsf+val);
      
      psf.pop_back();
      
    }
  }

  visited[src] = false;
  return;
}

int main() {

  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }

  int src;
  cin >> src;
  int dest;
  cin >> dest;

  int criteria;
  cin >> criteria;
  int k;
  cin >> k;

  vector<bool> visited(vtces, false);
  multisolver(graph, src, dest, visited, criteria, k, src + "0", 0);

  cout << "Smallest Path = " << spath << "@" << spathwt << endl;
  cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
  cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
  cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt << endl;
  cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;

  return 0;
}