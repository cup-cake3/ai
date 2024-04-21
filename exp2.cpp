#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    vector<vector<char>> data;
    int level;
    int fval;

    node(vector<vector<char>> data, int level, int fval) : data(data), level(level), fval(fval) {}

    vector<node> generateChild()
    {
        int x, y;
        tie(x, y) = find(data, '_');
        vector<vector<int>> valList = {{x, y - 1}, {x, y + 1}, {x - 1, y}, {x + 1, y}};
        vector<node> children;
        for (auto i : valList)
        {
            auto child = shuffle(data, x, y, i[0], i[1]);
            if (!child.empty())
            {
                children.emplace_back(child, level + 1, 0);
            }
        }
        return children;
    }

    vector<vector<char>> shuffle(vector<vector<char>> &puz, int x1, int y1, int x2, int y2)
    {
        if ((x2 >= 0 && x2 < puz.size()) && (y2 >= 0 && y2 < puz.size()))
        {
            auto temp_puz = copy(puz);
            swap(temp_puz[x1][y1], temp_puz[x2][y2]);
            return temp_puz;
        }
        else
        {
            return {};
        }
    }

    vector<vector<char>> copy(vector<vector<char>> &root)
    {
        vector<vector<char>> temp;
        for (auto i : root)
        {
            temp.emplace_back(i);
        }
        return temp;
    }

    pair<int, int> find(vector<vector<char>> &data, char x)
    {
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = 0; j < data.size(); j++)
            {
                if (data[i][j] == x)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

class puzzle
{
public:
    int n;
    vector<node> open;
    vector<node> closed;

    puzzle(int size) : n(size) {}

    vector<vector<char>> accept()
    {
        vector<vector<char>> puz;
        for (int i = 0; i < n; i++)
        {
            vector<char> temp;
            for (int j = 0; j < n; j++)
            {
                char tile;
                cin >> tile;
                temp.push_back(tile);
            }
            puz.push_back(temp);
        }
        return puz;
    }

    int f(node &start, vector<vector<char>> &goal)
    {
        return h(start.data, goal) + start.level;
    }

    int h(vector<vector<char>> &start, vector<vector<char>> &goal)
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (start[i][j] != goal[i][j] && start[i][j] != '_')
                {
                    temp++;
                }
            }
        }
        return temp;
    }

    void process()
    {
        cout << "enter start" << endl;
        auto start = accept();
        cout << "ender goal" << endl;
        auto goal = accept();

        node startNode(start, 0, 0);
        startNode.fval = f(startNode, goal);
        open.push_back(startNode);

        while (true)
        {
            auto cur = open[0];
            cout << "****************************************************" << endl;
            for (auto row : cur.data)
            {
                for (auto i : row)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            if (h(cur.data, goal) == 0)
            {
                break;
            }
            for (auto i : cur.generateChild())
            {
                i.fval = f(i, goal);
                open.push_back(i);
            }
            closed.push_back(cur);
            open.erase(open.begin());
            sort(open.begin(), open.end(), [](const node &a, const node &b)
                 { return a.fval < b.fval; });
        }
    }
};

int main()
{
    puzzle puz(3);
    puz.process();
    return 0;
}
// class puzzle{
//     public:
//     int n;
//     vector<node>open;
//     vector<node>closed;
//     puzzle(int n):n(n){};

//     vector<vector<char>>accept(){
//         vector<vector<char>>puz;
//         for(int i=0;i<n;i++){
//             vector<char>temp;
//             for(int i=0;i<n;i++){
//                 char tile;
//                 cin>>tile;
//                 temp.push_back(tile);
//             }
//             puz.push_back(temp);
//         }
//         return puz;
//     }

//     int f(node& start,vector<vector<char>> &goal){
//         return h(start.data,goal)+start.level;
//     }

//     int h(vector<vector<char>>&start,vector<vector<char>>&goal){
//         int temp=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(start[i][j]!=goal[i][j] && start[i][j]!='_'){
//                     temp++;
//                 }
//             }
//         }
//         return temp;
//     }
// };