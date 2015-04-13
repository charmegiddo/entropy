// http://en.wiktionary.org/wiki/entropy

#include <string>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

double log2( double number ) {
    return log( number ) / log( 2 ) ;
}
 
int main( int argc , char *argv[ ] ) {

    if(argc != 2){
        cout << "Ops!! Invalid parameters!!!" << endl; 
        cout << "Usage: " << argv[0] << " <strings>" << endl;
        return 0;
    }

    string data(argv[1]);
    int char_len;
    double sum = 0.0;
    map<char , int> freqs;
    char_len = data.length();

    // 出現頻度を加算
    for ( u_long i = 0; i < data.length(); i++ ){
        char c = argv[1][i];
        // Count
        freqs[c] ++;
    }

    // 計算
    for ( pair<char , int> p : freqs ) {
        // 出現確率に変換
        double percentage = (double)p.second / char_len;
        // 出現確率から情報量を計算
        double entropy = -percentage * log2(percentage);
        // 表示
        cout << "[" << p.first << "] = " << entropy << endl;
        // 平均情報量
        sum += entropy;
    }

    cout << "Entropy: " << sum << endl;

    return 0 ;
}