#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int startVertex, vertexes, edges;

int DFS(vector<vector<int> > _neighbours){
    vector<bool> isVisited(vertexes+1);
    for(int i = 1; i < vertexes+1; i++)
        isVisited[i] = false;
    stack<int> vertexesStack;
    vertexesStack.push(startVertex);
    while(vertexesStack.size() > 0){
        int currentVertex = vertexesStack.top();
        vertexesStack.pop();
        if(isVisited[currentVertex] == true){
            //cout << "Vertex " << currentVertex << " visited. It was true." << endl;
            break;
        }
        else {
            isVisited[currentVertex] = true;
            //cout << "Vertex " << currentVertex << " visited. It's now true." << endl;
            for(int i = 0; i < _neighbours[currentVertex].size(); i++){
                if(isVisited[_neighbours[currentVertex][i]] == false)
                    vertexesStack.push(_neighbours[currentVertex][i]);
            }
        }
    }

    bool isIntegral = true;
    for(int i = 1; i < vertexes+1; i++){
        if(isVisited[i] == false)
            isIntegral = false;
        //cout << "Vertex " << i << " is " << isVisited[i] << "." << endl;
    }

    if(isIntegral)
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;
}

int main(){
    int series; cin >> series;
    for(int i = 0; i < series; i++){
        cin >> vertexes >> edges;
        vector<vector<int> > neighbours(vertexes+1);

        for(int j = 0; j < edges; j++){
            int a, b; cin >> a >> b;
            neighbours[a].push_back(b);
            neighbours[b].push_back(a);
            startVertex = a;
        }
        DFS(neighbours);
    }
}
