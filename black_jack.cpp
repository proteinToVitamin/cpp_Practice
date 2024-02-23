#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

class player{
    private:
        int score;
        int sign;
        
    public:
        player(){
            sign=1;
        }

        int getSign(){
            return sign;
        }
        int getScore(){
            return score;
        }
        void card(){
            if(sign==1){
                random_device rand;     // 非決定的な乱数生成器
                int dist;
                dist = rand()%13+1;
                cout << "You recieved " << dist << endl;
                score+=dist;
                if(score<22){
                    cout << "Your score is " << score<<" ."<<endl;
                }
                else{
                    cout << "GAME OVER."<<endl;
                    sign=-1;
                }
            }
        }
        void draw(){
            cout << "If you want more card : 1, otherwise : 0" << endl;
            cin >> sign;
        }
        void finish(){
            if(sign==0){
                cout<<"Your score is " << score<<"."<<endl;
            }
        }
};

class enemy{
    private:
        int score;
        int sign;
        
    public:
        enemy(){
            sign=1;
        }

        int getSign(){
            return sign;
        }
        int getScore(){
            return score;
        }
        void card(){
            if(sign==1){
                random_device rand;     // 非決定的な乱数生成器
                int dist;
                dist = rand()%13+1;
                cout << "I recieved " << dist << endl;
                score+=dist;
                if(score<22){
                    cout << "My score is " << score<<" ."<<endl;
                }
                else{
                    cout << "GAME OVER."<<endl;
                    sign=-1;
                }
            }
        }
        void draw(){
            if(score<18){
                sign=1;
                cout<<"I will draw!"<<endl;
            }
            else{
                sign=0;
                cout<<"I dont need!"<<endl;
            }
        }
        void finish(){
            if(sign==0){
                cout<<"My score is " << score<<"."<<endl;
            }
        }
};

class battle{
    int y_score;
    int y_sign;
    int i_score;
    int i_sign;
    int hoge;

    public:
        battle(){
            player you;
            enemy ene;
            y_sign=you.getSign();
            i_sign=ene.getSign();
            hoge=0;

            cout<<"Distribute first card!"<<endl;
            you.card();
            y_sign=you.getSign();

            ene.card();
            i_sign=ene.getSign();

            while(y_sign==1 || i_sign==1){
                you.draw();
                if(y_sign=1){
                    cout<<"Your turn!"<<endl;
                    you.card();
                    y_sign=you.getSign();
                }
                else{
                    you.finish();
                }
                
                ene.draw();
                if(i_sign=1){
                    
                    ene.card();
                    i_sign=ene.getSign();
                }
                else{
                    ene.finish();
                }
            }
            y_score=you.getScore();
            i_score=ene.getScore();
            if(y_score>21 && i_score>21){
                cout<<"Draw!"<<endl;
            }
            if(y_score<22 && i_score>21){
                cout<<"You win!"<<endl;
            }
            if(y_score>21 && i_score<22){
                cout<<"You Lose!"<<endl;
            }
            if(y_score<22 && i_score<22){
                if(y_score<i_score){
                    cout<<"You Lose!"<<endl;
                }
                if(y_score>i_score){
                    cout<<"You win!"<<endl;
                }
                if(y_score==i_score){
                    cout<<"Draw!"<<endl;
                }
            }
        }
};


int main(){
    battle firstGame;
};
