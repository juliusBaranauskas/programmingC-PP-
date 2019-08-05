#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int N = 9;
const int ROW = 3;
const int COL = 3;
const int BLK = 3;  

const char D[] = "sudoku.txt";


void initTag ( bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]);
void fillTags (int problemMatrix[N][N], bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]);
void assignTag (int i, int j, int n, bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]);
bool checkValid (int i, int j, int c, bool tagRow[N][N], bool tagCol[N][N], bool tagBlk[N][N]);
void solveLogical (int problemMatrix[N][N], bool tagRow[N][N], bool tagCol[N][N], bool tagBlk[N][N]);
void resetTag (int i, int j, int n, bool tagRow[N][N], bool tagCol[N][N], bool tagBlk[N][N]);
bool solveBacktrack (int i, int j, int proMat [N][N], bool tagRow[N][N], bool tagCol[N][N], bool tagBlk[N][N]);
bool solvePuzzle(int problemMatrix[N][N], bool tagRow[N][N], bool tagCol[N][N], bool tagBlk[N][N]);
void printPuzzle (int problemMatrix[N][N]);

int main()
{

    int problemMatrix[N][N];

    bool tagRow[N][N];
    bool tagCol[N][N];
    bool tagBlk[N][N];
    ifstream fd(D);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            fd >> problemMatrix[i][j];
        }
    }
    fd.close();

    initTag(tagRow, tagCol, tagBlk);

    fillTags(problemMatrix, tagRow, tagCol, tagBlk);
    if (solvePuzzle (problemMatrix, tagRow, tagCol, tagBlk)) {
       printPuzzle(problemMatrix);
    }
    else
        cout << "Puzzle cannot be solved." << endl;
    cout << endl;

    return 0;
}

 void initTag ( bool tagRow[N][N], bool tagCol[N][N], bool tagBlk[N][N]) {
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            tagRow[j][k] = false;                                           //pradzioje suzymim kad tuscia
            tagCol[j][k] = false;
            tagBlk[j][k] = false;
        }
    }
}

void fillTags (int problemMatrix[N][N], bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]) {         //is nuskaitytos sudoku matricos sudeda atitinkamus tagus
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            assignTag (i, j, problemMatrix[i][j], tagRow, tagCol, tagBlk);
}

void assignTag (int i, int j, int n, bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]) {            //kai patikrina su checkValid, uzdeda atitinkama taga
    if (n == 0)
        return;
    n--;                                                          //KODEL CIA ATIMAM?????????????????????

    tagRow[i][n] = true;
    tagCol[n][j] = true;
    tagBlk[(i/BLK)*BLK+j/BLK][n] = true;                        //bloko numeris nuo 0 iki 8
}

bool checkValid (int i, int j, int c, bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]) {

    c--;                                                      //KODEL MAZINA?????????? CIA GI ESMINIS SKAICIUS???????????????????

    if (tagRow[i][c] == true)                                 //jei true - jau uzpildytas langelis
        return false;
    if (tagCol[c][j] == true)                               //jei tinka eiluteje, langelyje ir bloke grazinam true
        return false;
    if (tagBlk[(i/BLK)*BLK+j/BLK][c] == true)
        return false;
    return true;
}

void resetTag (int i, int j, int n, bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]) {
        if (n == 0)
            return;
        n--;                                                //IR VEL ATIMTIS IS ORO?????????????????

        tagRow[i][n] = false;
        tagCol[n][j] = false;
        tagBlk[(i/BLK)*BLK+j/BLK][n] = false;
}

bool solvePuzzle(int problemMatrix[N][N],  bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]) {

    solveLogical (problemMatrix, tagRow, tagCol, tagBlk);
    return solveBacktrack (0, 0, problemMatrix, tagRow, tagCol, tagBlk);
}

void solveLogical (int problemMatrix[N][N],  bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]) {

        int i, j, k, l = 0, row = 0, col = 0, cnt = 0;
        bool flagNotSingle = false;
        bool flagValueSet = false;              // jei while cikle priskiriam kazkoki skaiciu

        while (true) {

            flagValueSet = false;               // jei nebuvo jokio priskyrimo
            for (k = 0; k < N; k++) {           // TIKRINAM VISUS 9 BLOKUS
            //    for (l = 1; l < (N+1); l++) {
              for (l = 1; l <=N; l++){
                    cnt = 0;
                    flagNotSingle = false;      // tarkime, kad nera "vienintelio skaiciaus" langelio
                    for (i = (k/COL)*COL; i < ((k/COL)*COL + COL); i++) {
                        for (j = (k%COL)*ROW; j < ((k%COL)*ROW + ROW); j++) {
                            if (problemMatrix [i][j] > 0) //praleidziam jau uzpildytus
                                continue;
                            if (checkValid (i, j, l, tagRow, tagCol, tagBlk)) { // jei randam tuscia, paziurim ar tinka dabartinis skaicius
                                row = i;
                                col = j;
                                cnt ++;
                            }
                            if (cnt > 1) {
                                flagNotSingle = true;   // jei buvo galima irasyti daugiau nei vieninteli skaiciu
                                break;
                            }
                        }
                        if (flagNotSingle)
                            break;
                    }

                    if (cnt == 1) {                     // jei buvo rastas langelis tik su viena legalia reiksme, ja irasom
                        problemMatrix [row][col] = l;
                        assignTag (row, col, l, tagRow, tagCol, tagBlk);
                        flagValueSet = true;
                    }
                }
            }

            for (i = 0; i < N; i++) {           //TIKRINAM STULPELIUS
           // for (l = 1; l < N; l++){                                        //GAL KLAIDA? KODEL NE l <=N ?
             for (l = 1; l <= N; l++) {
                    cnt = 0;
                    for (j = 0; j < N; j++) {
                        if (problemMatrix [i][j] > 0)
                            continue;
                        if (checkValid (i, j, l, tagRow, tagCol, tagBlk)) { //jei randa tuscia.
                            row = i;
                            col = j;
                            cnt++;
                        }
                        if (cnt > 1) {
                            flagNotSingle = true;
                            break;
                        }
                    }
                    if (cnt == 1) {
                        problemMatrix [row][col] = l;
                        assignTag (row, col, l, tagRow, tagCol, tagBlk);
                        flagValueSet = true;
                    }
                }
            }

            for (i = 0; i < N; i++) { // TIKRINAM VISAS EILES
               // for (l = 1; l < N; l++) {
                for (l = 1; l <= N; l++) {
                    cnt = 0;
                    for (j = 0; j < N; j++) {
                        if (problemMatrix [j][i] > 0)
                            continue;
                        if (checkValid (j, i, l, tagRow, tagCol, tagBlk)) { // jei randa tuscia - tikrina, ar tinka dabartinis skaicius
                            row = j;
                            col = i;
                            cnt++;
                        }
                        if (cnt > 1) {
                            flagNotSingle = true;
                            break;
                        }
                    }
                    if (cnt == 1) {
                        problemMatrix [row][col] = l;
                        assignTag (row, col, l, tagRow, tagCol, tagBlk);
                        flagValueSet = true;
                    }
                }
            }

            if(!flagValueSet) // If assignment was not made during an iteration, break out of logical solve.
                break;
        }
}


 bool solveBacktrack (int i, int j, int proMat [N][N], bool tagRow[N][N],  bool tagCol[N][N],  bool tagBlk[N][N]) {
        if (i == N) {                                       // nuo pirmos iki paskutines eiles
            i = 0;
            if (++j == N)                                   // kai baigiasi eiles pradeda nuo pradziu bet sekanti tulpeli
                return true;                                // kai pasiekia paskutini langeli - sudoku issprestas
        }

        if (proMat[i][j] > 0)                               // praleisti jau uzpildytus
            return solveBacktrack (i + 1, j, proMat, tagRow, tagCol, tagBlk);       // eina prie sekancios dabartinio stulpelio eiles

        for (int val = 1; val <= N; val++) {                                        // tuscias langelis, tikrina nuo 1 iki 9.
            if (checkValid(i, j, val, tagRow, tagCol, tagBlk)) {
                proMat[i][j] = val;
                assignTag (i, j, val, tagRow, tagCol, tagBlk);
                if (solveBacktrack (i+1, j, proMat, tagRow, tagCol, tagBlk))
                    return true;                                                // jei true - sudoku issprestas
                else                                                            // jei ne - resetinti tagus ir backtrackinti
                    resetTag (i, j, proMat[i][j], tagRow, tagCol, tagBlk);
            }
        }

        resetTag (i, j, proMat[i][j], tagRow, tagCol, tagBlk);                   // backtrackinti
        proMat[i][j] = 0;
        return false;
}

void printPuzzle (int problemMatrix[N][N]) {
    /*cout << "-------------------------------------------------------" << endl;
    for (int row = 0; row < N; row++) {
            cout << "| ";
            for (int col = 0; col < N; col++) {
                cout << " *" << problemMatrix[row][col] << "* ";
                if (!((col+1) % BLK))
                    cout << " | ";
            }
            if (!((row+1) % BLK))
                cout << endl << "-------------------------------------------------------" << endl;
            else
                cout << endl;
        }*/

        //bent isvedima naudosiu savo (kai bus ka isvesti :/ )
        for (int row = 0; row < N; row++) {
       for (int col = 0; col < N; col++){
            cout << setw(2) << problemMatrix[row][col];
            if ((col + 1)%3 == 0 && (col != N-1))
            cout << "|";
        }
            cout << "\n";

        if ((row + 1)%3 == 0 && (row != N-1))
            cout << "------+------+-------" << endl;
    }
}