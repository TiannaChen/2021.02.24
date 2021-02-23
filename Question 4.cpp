
#include <bits/stdc++.h>
using namespace std;
int main() {
    int row = 10, column = 20;
    int arr[row][column];
    ifstream input;  //input
    input.open("input_question_4.txt");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) input >> arr[i][j];
    }
    input.close();
    int now = 0;
    int flag[row][column];
    memset(flag, 0, sizeof(flag));   //initializes the array
    for (int i = 0; i < row; i++) {     //connectivity is judged from each vertex
        for (int j = 0; j < column; j++) {
            if (flag[i][j] == 1) continue;
            if (arr[i][j] == 0) continue;
            now++;
            //DFS
            stack<int>stax;
            stack<int>stay;
            stax.push(i);
            stay.push(j);
            arr[i][j] = now;
            flag[i][j] = 1;
            while (!stax.empty()) {
                int x = stax.top();
                int y = stay.top();
                stax.pop();
                stay.pop();
                //choose 4-connectivity
                if (x - 1 >= 0 && flag[x - 1][y] == 0 && arr[x - 1][y] != 0) {  //ио
                    stax.push(x - 1);
                    stay.push(y);
                    arr[x - 1][y] = now;
                    flag[x - 1][y] = 1;
                }
                if (x + 1 < row && flag[x + 1][y] == 0 && arr[x + 1][y] != 0) {  //об
                    stax.push(x + 1);
                    stay.push(y);
                    arr[x + 1][y] = now;
                    flag[x + 1][y] = 1;
                }
                if (y - 1 >= 0 && flag[x][y - 1] == 0 && arr[x][y - 1] != 0) {  //вС
                    stax.push(x);
                    stay.push(y - 1);
                    arr[x][y - 1] = now;
                    flag[x][y - 1] = 1;
                }
                if (y + 1 < column && flag[x][y + 1] == 0 && arr[x][y + 1] != 0) {  //ср
                    stax.push(x);
                    stay.push(y + 1);
                    arr[x][y + 1] = now;
                    flag[x][y + 1] = 1;
                }
            }



        }
    }

    ofstream output;  //output
    output.open("output_question_4.txt");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            output << arr[i][j] << " ";
        }
        output << endl;
    }
    output.close();
}