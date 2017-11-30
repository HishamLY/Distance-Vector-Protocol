#include <cstdio>

using namespace std;

class NDH {
private:
    int dist,nextHop;
public:
    NDH() {
        dist = -1;
        nextHop = -1;
    }

    NDH(int _dist, int _nextHop) {
        dist = _dist;
        nextHop = _nextHop;
    }

    NDH(const NDH& n) {
        dist = n.getDist();
        nextHop = n.getNextHop();
    }

    void copy(const NDH& n) {
        dist = n.getDist();
        nextHop = n.getNextHop();
    }

    void setValue(int _dist, int _nextHop) {
        dist = _dist;
        nextHop = _nextHop;
    }

    int getDist() const { return dist; }
    int getNextHop() const { return nextHop; }
};

class RoutingTable {
private:
    NDH* ndh;
    int n_node;
public:
    RoutingTable(int _n_node) {
        n_node = _n_node;
        ndh = new NDH[n_node+1];
    }
    ~RoutingTable() {
        delete[] ndh;
    }

    void setNodeValue(int node_id, NDH n) {
        ndh[node_id].copy(n);
    }

    NDH& getNDH(int node_id) {
        return ndh[node_id];
    }

    void print() {
        printf("Node\tDistance\tNextHop\n");
        for (int i=1; i <= n_node; i++) {
            printf("%d\t%d\t\t%d\n",i,ndh[i].getDist(),ndh[i].getNextHop());
        }
        printf("\n");
    }
    
    void printFormatted() {
        for (int i = 1; i <= n_node; i++) {
            printf("%d %d\n",ndh[i].getDist(),ndh[i].getNextHop());
        }
    }
};

class Matrix {
private:
    const int row,col;
    int ** m;
public:
    Matrix(int _row, int _col):row(_row),col(_col) {
        m = new int*[row+1];
        for (int i = 0; i <= row; i++)
            m[i] = new int[col+1];

        for (int i=1; i<=row; i++)
            for (int j=1; j<=col; j++)
                m[i][j] = (i==j) ? 1 : 0;
    }
    ~Matrix() {
        for (int i = 0; i <= row; i++)
            delete[] m[i];
        delete[] m;
    }
    int getValue(int i,int j) const { return m[i][j]; }
    int setValue(int i,int j,int v) { m[i][j] = v; }
};


// GLOBAL VARS
int n_node,n_edge;

// GLOBAL METHODS

// Inisiasi Routing Table O(N^2)
void initRoutingTable(RoutingTable* r, const Matrix& adj_matrix){  
    // inisiasi setiap routing table tiap node
    NDH n(0,0);
    for (int i = 1; i <= n_node; i++) {
        for (int j = 1; j <= n_node; j++) {
            if (adj_matrix.getValue(i,j) > 0) {
                if (i == j) n.setValue(0,j);
                else n.setValue(1,j);
                r[i].setNodeValue(j,n);
            }
        }
    }
}




void updateTable(RoutingTable* r,int node_src, int node_dest) {
    int cost = r[node_src].getNDH(node_dest).getDist();
    for (int i=1; i <= n_node; i++) {
        int dist = r[node_src].getNDH(i).getDist();
        if (dist == -1 || i == node_dest) continue; // Kalau dist ke node-i nya dari src unreachable, atau i == node_dest, gausa dibandingin

        int curr_cost = r[node_dest].getNDH(i).getDist();
        if (curr_cost == -1 || ((dist + cost) < curr_cost)) { // update kalo sebelumnya dist ke node-i unreachable atau yg sekarang lebih baik
            r[node_dest].getNDH(i).setValue(dist+cost, node_src);
        } else if ((dist + cost) == curr_cost && node_src < r[node_dest].getNDH(i).getNextHop()) { // update kalo indeksnya lebih kecil
            r[node_dest].getNDH(i).setValue(dist+cost, node_src);
        }
    }
   
}

int main() {
    
    // TODO : scan #node and #edge
    scanf("%d %d",&n_node,&n_edge);

    Matrix adj_matrix(n_node,n_node);

    // init routing table
    RoutingTable rt[n_node+1](n_node);


    // TODO : scan edges
    int a,b;
    for(int i = 0; i < n_edge; ++i) {
        scanf("%d %d",&a,&b);
        if (a == b) {
            adj_matrix.setValue(a,b,2);
        }
        else {
            adj_matrix.setValue(a,b,1);
            adj_matrix.setValue(b,a,1);
        }
    }


    initRoutingTable(rt,adj_matrix);
    

    int n_scenario;
    // TODO : scan #scenario
    scanf("%d",&n_scenario);

    // TODO : scan scenarios
    for (int i=0; i < n_scenario; ++i) {
        scanf("%d %d",&a,&b);
        updateTable(rt,a,b);
        
    }

    // TODO : print result as formatted
    for (int i=1; i<= n_node; i++) {
        rt[i].printFormatted();
    }

   return 0;
}